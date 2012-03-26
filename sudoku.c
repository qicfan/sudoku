//
//  sudoku.c
//  sudoku
//
//  Created by 齐 晓鹏 on 12-3-25.
//  Copyright (c) 2012年 Yushuo. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "common.h";
#include "sudoku.h";

int validate_pit(int x, int y, int z) {
	int i,j;
	// 判断当前行是否有重复值
	for (j=0;j<9;j++) {
		if (SUDOKU[y][j] == z) {
			// 有重复值，返回0
			return 0;
		}
	}
	// 判断当前列是否有重复值
	for (j=0;j<9;j++) {
		if (SUDOKU[j][x] == z) {
			return 0;
		}
	}
	// 判断九宫格是否有重复值
	int xmin = (int)x/3 * 3;
	int ymin = (int)y/3 * 3;
	int xmax = xmin + 2;
	int ymax = ymin + 2;
	for (i=ymin; i<=ymax; i++) {
		for (j=xmin; j<= xmax; j++) {
			if (SUDOKU[i][j] == z) {
				return 0;
			}
		}
	}
	return 1;
}

void create_pit(int x, int y) {
	int z;
	z = randoms();

	if (validate_pit(x,y,z) == 1) {
		SUDOKU[y][x] = z;
		return;
	}
	return create_pit(x, y);

}

void create_random_pit() {
	int x,y;
	srand((int)time(0));
	// 给1-9行随机位置赋予种子
	// 种子随机给予
	for (y=0;y<9;y++) {
		x = randoms();
		create_pit(x, y);
	}
	return;
}

void fill_pit(int x, int y) {

	// 取这个坐标的可能解(取y轴已有值的数组、取X轴已有值的数组、取九宫格已有值的数组，对三个数组合并去重，然后和[1,2,3,4,5,6,7,8,9]取差集)

	// 循环可能解数组，找到正确的解
	return;
}

void hash_sudoku(level) {
	return;
}

void init_sudoku() {
	int x,y;
	for (y=0; y<9; y++) {
		for (x=0; x<9; x++) {
			SUDOKU[y][x] = 0;
		}
	}
	return;
}

void generate_sudoku(int level) {
	int x,y;
	// 初始化数独种子（给每一行随机生成一个数字）
	init_sudoku();
	create_random_pit();
	// 循环给每一个格子填充数字（求解）
	for (int y=0; y<9; y++) {
		for (int x=0; x<9; x++) {
			fill_pit(x, y);
		}
	}
	// 给数独挖坑
	hash_sudoku(level);
	return;
}

int main() {
	int x, y;
	printf("Hello sudoku!\n");
	generate_sudoku(1);
	for (y=0; y<9; y++) {
		printf("| ");
		for (x=0; x<9; x++) {
			printf("%d | ", SUDOKU[y][x]);
		}
		printf("\n");
	}
    return 0;
}
