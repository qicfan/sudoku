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

// 定义一个简单的树
typedef struct tree_struct {
	// 该节点的值
	int data;
	// 子节点的数量
	int child_count;
	// 该节点的x轴
	int x;
	// 该节点的y轴
	int y;
	// 该节点在父级子节点中的位置
	int position;
	// 该节点的父节点
	struct tree_struct *parent;
	// 该节点的子节点数组
	struct tree_struct *childs;
} tree_node;

// 生成一个节点
tree_node *create_node(int data, int x, int y);
// 给某一个节点添加一个子节点
void append_child(tree_node *node, tree_node *child);
// 销毁一个节点
int free_node(tree_node *node);


#endif
