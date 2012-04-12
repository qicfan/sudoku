//
//  common.c
//  sudoku
//
//  Created by 齐 晓鹏 on 12-3-25.
//  Copyright (c) 2012年 Yushuo. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "common.h";

/**
 生成1-9的随机数
 */
int randoms() {
	int r;
	r = rand() % 9;
	if (r == 0) {
		return 1;
	}
	return r;
}

tree_node * create_node(int data, int x, int y) {
	tree_node * new_node = (tree_node *)malloc(sizeof(tree_node));
	if (new_node == NULL) {
		printf("malloc failed\n");
		exit(0);
	}
	new_node->data = data;
	new_node->x = x;
	new_node->y = y;
	new_node->child_count = 1;
	new_node->childs = NULL;
	new_node->parent = NULL;
	new_node->position = 0;
	return new_node;
}

void append_child(tree_node *node, tree_node *child) {
	tree_node *tmp_node = (tree_node *)calloc(node->child_count + 1, sizeof(tree_node *));
	if (tmp_node == NULL) {
		printf("malloc failed\n");
		exit(0);
	}
	memcpy(tmp_node, node->childs, sizeof(node->childs));
	tmp_node[node->child_count] = *child;
	free(node->childs);
	node->childs = tmp_node;
	child->position = node->child_count;
	node->child_count ++;
	child->parent = node;
	return;
}

int delete_node(tree_node *node) {
	int i = 0;
	if (node->child_count != 0) {
		// 如果还有子节点则不能删除
		return 1;
	}
	if (node == NULL) {
		return 1;
	}
	free(node->childs);
	node->childs = NULL;
	free(node);
	node = NULL;
	return 0;
}
