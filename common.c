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
#include "common.h";

/**
 生成1-9的随机数
 */
int randoms() {
	int r;
	r = rand()%9;
	if (r == 0) {
		return 1;
	}
	return r;
}

// 生成指定长度的数组
array *create_array(int size) {
	int i = 0;
	array *data = (array *)malloc(sizeof(array));
	if (data == NULL) {
		printf("create array malloc failed!");
		exit(0);
	}
	data->items = (int *)malloc(size * sizeof(int));
	if (data->items == NULL) {
		printf("items malloc failed!");
		exit(0);
	}
	for (i=0;i<size;i++) {
		data->items[i] = i + 1;
	}
	data->size = size;
	return data;
}

// 销毁一个数组
void destroy_array(array *data) {
	free(data->items);
	free(data);
	return;
}

