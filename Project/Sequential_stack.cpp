#define _CRT_SECURE_NO_WARNINGS 1
#include "Sequential_stack.h"

SqStack S;					//����һ��ջ
int e;

Status InitStack(SqStack& S)			//����һ����ջS
{
	S.base = new SElemType[MAXSIZE];
	if (!S.base)	exit(OVERFLOW);
	S.top = S.base;
	S.Stacksize = MAXSIZE;
	return 1;
}

Status Push(SqStack& S, SElemType e)	//����Ԫ��eΪ�µ�ջ��Ԫ��
{
	if (S.top - S.base == S.Stacksize)	return 0;
	*S.top++ = e;
	return 1;
}

Status Pop(SqStack& S, SElemType& e)	//ɾ��S��ջ��Ԫ�أ���e������ֵ
{
	if (S.top == S.base)	return 0;
	e = *--S.top;
	return	1;
}

SElemType GetTop(SqStack S)				//����S��ջ��Ԫ�أ����޸�ջ��ָ��
{
	if (S.top != S.base)
		return *(S.top - 1);
}

SElemType StackEmpty(SqStack S)			//�ж��Ƿ�Ϊ��ջ
{
	if (S.base == S.top)
		return 1;
	else
		return 0;
}
