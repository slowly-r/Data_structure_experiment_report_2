#define _CRT_SECURE_NO_WARNINGS 1
#include "Sequential_stack.h"

SqStack S1;					//定义一个栈
char flag;					//标志位：1表匹配正确，0表匹配错误
int x;
char ch;					//定义输入的字符

//检验表达式中所含括号是否正确匹配，如果正确匹配，返回1，否者返回0
//输入字符表达式以#结尾
Status Matching()
{
	InitStack(S1);				//初始化空栈
	flag = 1;					//标记匹配结果以控制循环及返回结果
	cin >> ch;					//读入第一个字符
	while (ch != '#' && flag)	//假设表达式以"#"结尾
	{
		switch (ch)
		{
			case '[':			//若是左括号，则将其压入栈
				Push(S1, ch);
				break;

			case '(':			//若是左括号，则将其压入栈
				Push(S1, ch);
				break;

			case ')':			//若是")"，则根据当前栈顶元素的值分情况考虑
				if (!StackEmpty(S1) && GetTop(S1) == '(')
					Pop(S1, x);	//若栈非空且栈顶元素是"("，则正确匹配
				else  flag = 0;	//若栈空或栈顶元素不是"("，则错误匹配
				break;

			case ']':			//若是"]"，则根据当前栈顶元素的值分情况考虑
				if (!StackEmpty(S1) && GetTop(S1) == '[')
					Pop(S1, x);	//若栈非空且栈顶元素是"["，则正确匹配
				else flag = 0;	//若栈空或栈顶元素不是"["，则错误匹配
				break;


			default:
				break;
		}
		cin >> ch;				//继续读入下一个字符
	}
	if (StackEmpty(S1) && flag)	return	1;	//匹配成功
	else  return 0;							//匹配失败
}

int main(void)
{
	if (Matching())
		cout << "匹配结果：正确" << endl;				//输出匹配结果
	else
		cout << "匹配结果：错误" << endl;				//输出匹配结果
}
