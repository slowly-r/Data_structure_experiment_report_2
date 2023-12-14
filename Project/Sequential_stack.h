#pragma once
#include <iostream>
#include <stdio.h>
#include <cmath>
#include <cstdlib>

using namespace std;		//引入std命名空间中的所有成员到当前的命名空间中

#define SElemType int		//宏定义特殊的返回类型为int
#define Status int

#define MAXSIZE 100			//顺序栈存储空间的初始分配量
typedef struct
{
	SElemType* base;		//栈底指针
	SElemType* top;			//栈顶指针
	int Stacksize;			//栈可用的最大容量
}SqStack;

Status InitStack(SqStack& S);			//构建一个空栈S
Status Push(SqStack& S, SElemType e);	//插入元素e为新的栈顶元素
Status Pop(SqStack& S, SElemType& e);	//删除S的栈顶元素，用e返回其值
SElemType GetTop(SqStack S);			//返回S的栈顶元素，不修改栈顶
SElemType StackEmpty(SqStack S);		//判断是否为空栈

