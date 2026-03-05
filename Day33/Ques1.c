/*
Problem: Convert an infix expression to postfix notation using stack.

Input:
- Single line: infix expression (operands are single characters)

Output:
- Print the postfix expression

Example:
Input:
A+B*C

Output:
ABC*+

Explanation:
Operator precedence: * > +
Use stack to handle operator precedence and associativity
*/

#include <stdio.h>
#include <ctype.h>

char stack[100];
int top=-1;

void push(char c)
{
    stack[++top]=c;
}

char pop()
{
    return stack[top--];
}

int precedence(char c)
{
    if(c=='+'||c=='-') return 1;
    if(c=='*'||c=='/') return 2;
    if(c=='^') return 3;
    return 0;
}

int main()
{
    char infix[100], postfix[100];
    int i=0,k=0;

    scanf("%s",infix);

    while(infix[i]!='\0')
    {
        if(isalnum(infix[i]))
        {
            postfix[k++]=infix[i];
        }
        else if(infix[i]=='(')
        {
            push(infix[i]);
        }
        else if(infix[i]==')')
        {
            while(stack[top]!='(')
                postfix[k++]=pop();
            pop();
        }
        else
        {
            while(top!=-1 && precedence(stack[top])>=precedence(infix[i]))
                postfix[k++]=pop();
            push(infix[i]);
        }
        i++;
    }

    while(top!=-1)
        postfix[k++]=pop();

    postfix[k]='\0';

    printf("%s",postfix);

    return 0;
}