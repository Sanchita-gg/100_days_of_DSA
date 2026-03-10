/*
Problem: Deque (Double-Ended Queue)

A Deque is a linear data structure that allows insertion and deletion of elements from both the front and the rear. It provides more flexibility than a standard queue or stack.

Common Operations:
1. push_front(value): Insert an element at the front of the deque.
2. push_back(value): Insert an element at the rear of the deque.
3. pop_front(): Remove an element from the front of the deque.
4. pop_back(): Remove an element from the rear of the deque.
5. front(): Return the front element of the deque.
6. back(): Return the rear element of the deque.
7. empty(): Check whether the deque is empty.
8. size(): Return the number of elements in the deque.

Additional Operations:
- clear(): Remove all elements from the deque.
- erase(): Remove one or more elements from the deque.
- swap(): Swap contents of two deques.
- emplace_front(): Insert an element at the front without copying.
- emplace_back(): Insert an element at the rear without copying.
- resize(): Change the size of the deque.
- assign(): Replace elements with new values.
- reverse(): Reverse the order of elements.
- sort(): Sort the elements in ascending order.

Time Complexity:
- push_front, push_back, pop_front, pop_back, front, back, empty, size: O(1)
- clear, erase, resize, assign, reverse: O(n)
- sort: O(n log n)

Input:
- Sequence of deque operations with values (if applicable)

Output:
- Results of operations such as front, back, size, or the final state of the deque after all operation
*/

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* prev;
    struct node* next;
};

struct node* front=NULL;
struct node* rear=NULL;
int count=0;

void push_front(int x){
    struct node* temp=malloc(sizeof(struct node));
    temp->data=x;
    temp->prev=NULL;
    temp->next=front;
    if(front!=NULL) front->prev=temp;
    front=temp;
    if(rear==NULL) rear=temp;
    count++;
}

void push_back(int x){
    struct node* temp=malloc(sizeof(struct node));
    temp->data=x;
    temp->next=NULL;
    temp->prev=rear;
    if(rear!=NULL) rear->next=temp;
    rear=temp;
    if(front==NULL) front=temp;
    count++;
}

void pop_front(){
    if(front==NULL) return;
    struct node* temp=front;
    front=front->next;
    if(front!=NULL) front->prev=NULL;
    else rear=NULL;
    free(temp);
    count--;
}

void pop_back(){
    if(rear==NULL) return;
    struct node* temp=rear;
    rear=rear->prev;
    if(rear!=NULL) rear->next=NULL;
    else front=NULL;
    free(temp);
    count--;
}

int get_front(){
    if(front==NULL) return -1;
    return front->data;
}

int get_back(){
    if(rear==NULL) return -1;
    return rear->data;
}

int empty(){
    return front==NULL;
}

int size(){
    return count;
}

void display(){
    struct node* temp=front;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

int main(){
    int n,x;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int op;
        scanf("%d",&op);
        if(op==1){
            scanf("%d",&x);
            push_front(x);
        }
        else if(op==2){
            scanf("%d",&x);
            push_back(x);
        }
        else if(op==3){
            pop_front();
        }
        else if(op==4){
            pop_back();
        }
        else if(op==5){
            printf("%d\n",get_front());
        }
        else if(op==6){
            printf("%d\n",get_back());
        }
        else if(op==7){
            printf("%d\n",empty());
        }
        else if(op==8){
            printf("%d\n",size());
        }
    }
    display();
}