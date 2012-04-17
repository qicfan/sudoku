dnl $Id$
dnl config.m4 for extension sudoku

dnl Comments in this file start with the string 'dnl'.
dnl Remove where necessary. This file will not work
dnl without editing.

dnl If your extension references something external, use with:

PHP_ARG_WITH(sudoku, for sudoku support,
[  --with-sudoku             Include sudoku support])

dnl Otherwise use enable:

dnl PHP_ARG_ENABLE(sudoku, whether to enable sudoku support,
dnl Make sure that the comment is aligned:
dnl [  --enable-sudoku           Enable sudoku support])
dnl if test -z "%PHP_DEBUG"; then
dnl   AC_ARG_ENABLE(debug,
dnl   [  --enable-debug
dnl      PHP_DEBUG=$enableval
dnl   ], [  PHP_DEBUG=no
dnl   ])
dnl fi
if test "$PHP_SUDOKU" != "no"; then
  dnl Write more examples of tests here...

  dnl # --with-sudoku -> check with-path
  dnl SEARCH_PATH="/usr/local /usr"     # you might want to change this
  dnl SEARCH_FOR="/include/sudoku.h"  # you most likely want to change this
  dnl if test -r $PHP_SUDOKU/$SEARCH_FOR; then # path given as parameter
  dnl   SUDOKU_DIR=$PHP_SUDOKU
  dnl else # search default path list
  dnl   AC_MSG_CHECKING([for sudoku files in default path])
  dnl   for i in $SEARCH_PATH ; do
  dnl     if test -r $i/$SEARCH_FOR; then
  dnl       SUDOKU_DIR=$i
  dnl       AC_MSG_RESULT(found in $i)
  dnl     fi
  dnl   done
  dnl fi
  dnl
  dnl if test -z "$SUDOKU_DIR"; then
  dnl   AC_MSG_RESULT([not found])
  dnl   AC_MSG_ERROR([Please reinstall the sudoku distribution])
  dnl fi

  dnl # --with-sudoku -> add include path
  dnl PHP_ADD_INCLUDE($SUDOKU_DIR/include)

  dnl # --with-sudoku -> check for lib and symbol presence
  dnl LIBNAME=sudoku # you may want to change this
  dnl LIBSYMBOL=sudoku # you most likely want to change this 

  dnl PHP_CHECK_LIBRARY($LIBNAME,$LIBSYMBOL,
  dnl [
  dnl   PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, $SUDOKU_DIR/lib, SUDOKU_SHARED_LIBADD)
  dnl   AC_DEFINE(HAVE_SUDOKULIB,1,[ ])
  dnl ],[
  dnl   AC_MSG_ERROR([wrong sudoku lib version or lib not found])
  dnl ],[
  dnl   -L$SUDOKU_DIR/lib -lm
  dnl ])
  dnl
  dnl PHP_SUBST(SUDOKU_SHARED_LIBADD)

  PHP_NEW_EXTENSION(sudoku, sudoku.c lsudoku.c common.c, $ext_shared)
fi
