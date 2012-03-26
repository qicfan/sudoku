//
//  sudoku.h
//  sudoku
//
//  Created by 齐 晓鹏 on 12-3-25.
//  Copyright (c) 2012年 Yushuo. All rights reserved.
//

#ifndef sudoku_sudoku_h
#define sudoku_sudoku_h
// 数独的解
int SUDOKU[9][9];
// 挖好坑要显示的数独
int DIS_SUDOKU[9][9];
// 初始化数独数据，将每一个格子都设置为0
void init_sudoku();
// 生成数独，根据level来生成指定难度的数独
void generate_sudoku(int level);
// 对每一行随机填一个数字
void create_random_pit();
// 对每一行随机填数字的时候，如果这个数字不满足规则，则递归直到满足规则为止
void create_pit(int x, int y);
// 验证该坐标填这个数字是否符合规则，如果符合规则，返回1；否则的话返回0
int validate_pit(int x, int y, int z);
// 给该坐标填写一个数，进行深度优先搜索，直到找到有解的数字
void fill_pit(int x, int y);
// 按照level难度给数独的解挖坑，每个九宫格挖随机数量的坑（填0）
void hash_sudoku(int level);

#endif
