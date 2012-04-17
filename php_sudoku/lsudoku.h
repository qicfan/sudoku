//
//  sudoku.h
//  sudoku
//
//  Created by 齐 晓鹏 on 12-3-25.
//  Copyright (c) 2012年 Yushuo. All rights reserved.
//

#ifndef lsudoku_h
#define lsudoku_h
void init_sudoku();
void generate_sudoku();
void create_random_pit();
void create_pit(int x, int y);
int validate_pit(int x, int y, int z);
int fill_pit();
void hash_sudoku();

#endif
