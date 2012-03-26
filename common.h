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
// 数组结构，items用来存放数据，count用来存放数组元素个数
typedef struct array_struct {
	int *items;
	int size;
} array;
// 生成并且初始化数组
array *create_array(int size);
// 销毁数组，释放内存空间
void destroy_array(array *data);

#endif
