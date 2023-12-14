#define _CRT_SECURE_NO_WARNINGS 1
#include "Sequential_stack.h"

SqStack S1;					//����һ��ջ
char flag;					//��־λ��1��ƥ����ȷ��0��ƥ�����
int x;
char ch;					//����������ַ�

//������ʽ�����������Ƿ���ȷƥ�䣬�����ȷƥ�䣬����1�����߷���0
//�����ַ����ʽ��#��β
Status Matching()
{
	InitStack(S1);				//��ʼ����ջ
	flag = 1;					//���ƥ�����Կ���ѭ�������ؽ��
	cin >> ch;					//�����һ���ַ�
	while (ch != '#' && flag)	//������ʽ��"#"��β
	{
		switch (ch)
		{
			case '[':			//���������ţ�����ѹ��ջ
				Push(S1, ch);
				break;

			case '(':			//���������ţ�����ѹ��ջ
				Push(S1, ch);
				break;

			case ')':			//����")"������ݵ�ǰջ��Ԫ�ص�ֵ���������
				if (!StackEmpty(S1) && GetTop(S1) == '(')
					Pop(S1, x);	//��ջ�ǿ���ջ��Ԫ����"("������ȷƥ��
				else  flag = 0;	//��ջ�ջ�ջ��Ԫ�ز���"("�������ƥ��
				break;

			case ']':			//����"]"������ݵ�ǰջ��Ԫ�ص�ֵ���������
				if (!StackEmpty(S1) && GetTop(S1) == '[')
					Pop(S1, x);	//��ջ�ǿ���ջ��Ԫ����"["������ȷƥ��
				else flag = 0;	//��ջ�ջ�ջ��Ԫ�ز���"["�������ƥ��
				break;


			default:
				break;
		}
		cin >> ch;				//����������һ���ַ�
	}
	if (StackEmpty(S1) && flag)	return	1;	//ƥ��ɹ�
	else  return 0;							//ƥ��ʧ��
}

int main(void)
{
	if (Matching())
		cout << "ƥ��������ȷ" << endl;				//���ƥ����
	else
		cout << "ƥ����������" << endl;				//���ƥ����
}
