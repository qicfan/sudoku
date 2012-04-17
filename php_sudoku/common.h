//
//  common.h
//  sudoku
//
//  Created by 齐 晓鹏 on 12-3-25.
//  Copyright (c) 2012年 Yushuo. All rights reserved.
//

#ifndef sudoku_common_h
#define sudoku_common_h
int randoms();

typedef struct tree_struct {
	int data;
	int child_count;
	int x;
	int y;
	int position;
	struct tree_struct *parent;
	struct tree_struct *childs[9];
} tree_node;

tree_node *create_node(int data, int x, int y);
void append_child(tree_node *node, tree_node *child);
int delete_node(tree_node *node);


#endif
