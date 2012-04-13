//
//  common.c
//  sudoku
//
//  Created by �� ���� on 12-3-25.
//  Copyright (c) 2012�� Yushuo. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "common.h"

/**
 ����1-9�������
 */
int randoms() {
	int r;
	r = rand() % 9;
	if (r == 0) {
		return 1;
	}
	return r;
}

tree_node * create_node(int data, int x, int y) {	int i;
	tree_node * new_node = (tree_node *)malloc(sizeof(tree_node));
	if (new_node == NULL) {
		printf("malloc failed\n");
		exit(0);
	}
	new_node->data = data;
	new_node->x = x;
	new_node->y = y;
	new_node->child_count = 0;	for (i=0; i<9; i++) {		new_node->childs[i] = NULL;	}
	new_node->parent = NULL;
	new_node->position = 0;
	return new_node;
}

void append_child(tree_node *node, tree_node *child) {
	node->childs[node->child_count] = child;
	child->position = node->child_count;
	node->child_count ++;
	child->parent = node;
	return;
}

int delete_node(tree_node *node) {
	if (node == NULL) {
		return 1;
	}
	if (node->child_count > 0) {
		// ��������ӽڵ�����ɾ��
		int j;
		for (j=0;j<node->child_count;j++) {
			delete_node(node->childs[j]);
		}
	}	if (node->parent != NULL) {
		tree_node *tmp;
		int end = node->parent->child_count - 1;
		// �����һλ����λ��
		if (node->position == end || node->parent->child_count == 1) {
			node->parent->childs[node->position] = NULL;
		} else {
			tmp = node->parent->childs[end];
			tmp->position = node->position;
			node->parent->childs[end] = NULL;
			node->parent->childs[node->position] = tmp;
		}		node->parent->child_count --;	}
	free(node);
	node = NULL;
	return 0;
}
