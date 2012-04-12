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

void get_better(tree_node *current_node, int x, int y) {
	tree_node *node = create_node(0);
	return;
}

// 1、从0,0开始取该坐标的最优解，
// 2、最优解加入树中
// 3、按顺序取每一个子节点，验证该节点值，如果符合规则，就进入深度搜索；否则删除该节点，进入下一个兄弟节点，重复3
// 4、取该节点坐标的下一个坐标，重复1-3
int fill_pit() {
	int x, y, z, c=0;
	tree_node *current_node = create_node(0, 0, 0);
	for (y=0; y<9; y++) {
		for (x=0; x<9; x++) {
			if (c == 0) {
				// 该坐标没有合适的，回到父级
				tree_node *tmp_node = current_node->parent;
				if (tmp_node == NULL || tmp_node->data == 0) {
					return 1;
				}
				// 删除当前
				tmp_node->childs[current_node->position] = NULL;
				free_node(current_node);
				current_node = tmp_node;
				x = current_node->x;
				y = current_node->y;
				SUDOKU[y][x] = 0;
			} else {
				// 树的当前节点
				get_better(current_node, x, y);
			}
			for (z=0; z<current_node->child_count; z++) {
				if (current_node->childs[z] == NULL || !validate_pit(x, y, current_node->childs[z]->data)) {
					// 不符合规则，进入下一个兄弟节点
					// 删除该节点
					free_node(current_node->childs[z]);
					current_node->childs[z] = NULL;
					current_node->child_count --;
					continue;
				}
				// 符合规则，进入下一个坐标
				SUDOKU[y][x] = current_node->childs[z]->data;
				c = 1;
				break;
			}
		}
	}
	return 0;
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
	int x,y,z=0;
	// 初始化数独种子（给每一行随机生成一个数字）
	init_sudoku();
	create_random_pit();
	// 循环给每一个格子填充数字（求解）
	while (1) {
		if (x > 81) {
			break;
		}
		x ++;
		z = fill_pit();
		if (z == 0) {
			break;
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
