/*
Problem: Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.

Input:
- Postfix expression with operands and operators

Output:
- Print the integer result

Example:
Input:
2 3 1 * + 9 -

Output:
-4
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct node{
    int data;
    struct node* next;
};

struct node* top=NULL;

void push(int x){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=x;
    temp->next=top;
    top=temp;
}

int pop(){
    struct node* temp=top;
    int x=temp->data;
    top=top->next;
    free(temp);
    return x;
}

int main(){
    char s[100];
    fgets(s,100,stdin);
    char *t=strtok(s," ");
    while(t!=NULL){
        if(isdigit(t[0]) || (t[0]=='-' && isdigit(t[1]))){
            push(atoi(t));
        }else{
            int b=pop();
            int a=pop();
            if(t[0]=='+') push(a+b);
            else if(t[0]=='-') push(a-b);
            else if(t[0]=='*') push(a*b);
            else if(t[0]=='/') push(a/b);
        }
        t=strtok(NULL," ");
    }
    printf("%d",pop());
    return 0;
}