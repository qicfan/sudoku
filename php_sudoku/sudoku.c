/*
  +----------------------------------------------------------------------+
  | PHP Version 5                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2011 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author:                                                              |
  +----------------------------------------------------------------------+
*/

/* $Id: header 310447 2011-04-23 21:14:10Z bjori $ */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "php_sudoku.h"
#include "lsudoku.h"

/* If you declare any globals in php_sudoku.h uncomment this:
ZEND_DECLARE_MODULE_GLOBALS(sudoku)
*/

/* True global resources - no need for thread safety here */
extern int SUDOKU[9][9];
extern int DIS_SUDOKU[9][9];
static int le_sudoku;

/* {{{ sudoku_functions[]
 *
 * Every user visible function must have an entry in sudoku_functions[].
 */
const zend_function_entry sudoku_functions[] = {
	PHP_FE(lgenerate_sudoku, NULL)
	PHP_FE(get_sudoku, NULL)
	PHP_FE_END	/* Must be the last line in sudoku_functions[] */
};
/* }}} */

/* {{{ sudoku_module_entry
 */
zend_module_entry sudoku_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
	STANDARD_MODULE_HEADER,
#endif
	"sudoku",
	sudoku_functions,
	PHP_MINIT(sudoku),
	PHP_MSHUTDOWN(sudoku),
	PHP_RINIT(sudoku),		/* Replace with NULL if there's nothing to do at request start */
	PHP_RSHUTDOWN(sudoku),	/* Replace with NULL if there's nothing to do at request end */
	PHP_MINFO(sudoku),
#if ZEND_MODULE_API_NO >= 20010901
	"0.1", /* Replace with version number for your extension */
#endif
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_SUDOKU
ZEND_GET_MODULE(sudoku)
#endif

/* {{{ PHP_MINIT_FUNCTION
 */
PHP_MINIT_FUNCTION(sudoku)
{
	/* If you have INI entries, uncomment these lines 
	REGISTER_INI_ENTRIES();
	*/
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MSHUTDOWN_FUNCTION
 */
PHP_MSHUTDOWN_FUNCTION(sudoku)
{
	/* uncomment this line if you have INI entries
	UNREGISTER_INI_ENTRIES();
	*/
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request start */
/* {{{ PHP_RINIT_FUNCTION
 */
PHP_RINIT_FUNCTION(sudoku)
{
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request end */
/* {{{ PHP_RSHUTDOWN_FUNCTION
 */
PHP_RSHUTDOWN_FUNCTION(sudoku)
{
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(sudoku)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "sudoku support", "enabled");
	php_info_print_table_end();

	/* Remove comments if you have entries in php.ini
	DISPLAY_INI_ENTRIES();
	*/
}
/* }}} */

PHP_FUNCTION(lgenerate_sudoku)
{
	int x,y;
	zval *ret = NULL;
	MAKE_STD_ZVAL(ret);
	generate_sudoku();
	array_init(ret);
	for (y=0;y<9;y++) {
		zval *arr = NULL;
		MAKE_STD_ZVAL(arr);
		array_init(arr);
		for (x=0;x<9;x++) {
			add_index_long(arr, x, DIS_SUDOKU[y][x]);
		}
		add_index_zval(ret, y, arr);
	}
	RETURN_ZVAL(ret, 0, 0);
}

PHP_FUNCTION(get_sudoku)
{
	int x,y;
	zval *ret = NULL;
	MAKE_STD_ZVAL(ret);
	array_init(ret);
	for (y=0;y<9;y++) {
		zval *arr = NULL;
		MAKE_STD_ZVAL(arr);
		array_init(arr);
		for (x=0;x<9;x++) {
			add_index_long(arr, x, SUDOKU[y][x]);
		}
		add_index_zval(ret, y, arr);
	}
	RETURN_ZVAL(ret, 0, 0);
}
