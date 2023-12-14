#pragma once
#include <iostream>
#include <stdio.h>
#include <cmath>
#include <cstdlib>

using namespace std;		//����std�����ռ��е����г�Ա����ǰ�������ռ���

#define SElemType int		//�궨������ķ�������Ϊint
#define Status int

#define MAXSIZE 100			//˳��ջ�洢�ռ�ĳ�ʼ������
typedef struct
{
	SElemType* base;		//ջ��ָ��
	SElemType* top;			//ջ��ָ��
	int Stacksize;			//ջ���õ��������
}SqStack;

Status InitStack(SqStack& S);			//����һ����ջS
Status Push(SqStack& S, SElemType e);	//����Ԫ��eΪ�µ�ջ��Ԫ��
Status Pop(SqStack& S, SElemType& e);	//ɾ��S��ջ��Ԫ�أ���e������ֵ
SElemType GetTop(SqStack S);			//����S��ջ��Ԫ�أ����޸�ջ��
SElemType StackEmpty(SqStack S);		//�ж��Ƿ�Ϊ��ջ

