#define _CRT_SECURE_NO_WARNINGS 1
#include "Sequential_stack.h"

SqStack S;					//定义一个栈
int e;

Status InitStack(SqStack& S)			//构建一个空栈S
{
	S.base = new SElemType[MAXSIZE];
	if (!S.base)	exit(OVERFLOW);
	S.top = S.base;
	S.Stacksize = MAXSIZE;
	return 1;
}

Status Push(SqStack& S, SElemType e)	//插入元素e为新的栈顶元素
{
	if (S.top - S.base == S.Stacksize)	return 0;
	*S.top++ = e;
	return 1;
}

Status Pop(SqStack& S, SElemType& e)	//删除S的栈顶元素，用e返回其值
{
	if (S.top == S.base)	return 0;
	e = *--S.top;
	return	1;
}

SElemType GetTop(SqStack S)				//返回S的栈顶元素，不修改栈顶指针
{
	if (S.top != S.base)
		return *(S.top - 1);
}

SElemType StackEmpty(SqStack S)			//判断是否为空栈
{
	if (S.base == S.top)
		return 1;
	else
		return 0;
}
