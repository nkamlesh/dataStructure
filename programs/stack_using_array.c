/*
Name:
Roll no:
Branch:
Title: Program on implementation of stack using array
*/
#include <stdio.h>
#include <stdio.h>
#define SIZE 3 //size of stack can be changed from here
//creating structure for accessing stack array and its top pointer under same group
struct stack{
int a[SIZE];
int top;
}s;

//check top value, return 1 if empty
int is_empty() {
	if(s.top == -1)
		return 1;
	return 0;
}
//check stack is full return 1, otherwise 0
int is_full() {
	if(s.top == SIZE-1)
		return 1;
	return 0;
}

//add a element to the top stack
void push(int x) {
		s.top=s.top+1;
		s.a[s.top] = x;
}

//remove a element from top of stack
int pop() {
    int temp;
	temp=s.a[s.top];
	s.top=s.top-1;
	return temp;
}

// provide a view to top element of stack
int peek(){
   return s.a[s.top];
}

int main() { 
int choice,item;
//intialize stack at start
s.top=-1;
//user driven menu
do{
	printf("\n 1. Push 2. Pop 3. Peek 4.exit \n Enter your choice:");
	scanf("%d",&choice);
	switch(choice){
		case 1:
			if(is_full()){
				printf("\n Stack is full");
			}
			else{
				printf("\n Enter the item to be pushed:");
				scanf("%d",&item);
				push(item);
			}
			break;
		case 2:
			if(is_empty()){
				printf("\n Stack Underflow");
			}
			else{
				item=pop();
				printf("\n item popped from top of stack:%d",item);
			}
			break;
		case 3:
			if(is_empty()){
				printf("\n Stack Underflow");
			}
			else{
				item=peek();
				printf("\n item at top of stack:%d",item);
			}
		case 4:
			break;
		default:
			printf("\n enter choice between 1 - 4 only");
	}
	
}while(choice!=4);
return 0;
}
/*OUTPUT

 1. Push 2. Pop 3. Peek 4.exit 
 Enter your choice:1
 Enter the item to be pushed:23

 1. Push 2. Pop 3. Peek 4.exit 
 Enter your choice:1
 Enter the item to be pushed:34

 1. Push 2. Pop 3. Peek 4.exit 
 Enter your choice:1
 Enter the item to be pushed:45

 1. Push 2. Pop 3. Peek 4.exit 
 Enter your choice:1

 Stack is full

 1. Push 2. Pop 3. Peek 4.exit 
 Enter your choice:3

 item at top of stack:45

 1. Push 2. Pop 3. Peek 4.exit 
 Enter your choice:2

 item popped from top of stack:45

 1. Push 2. Pop 3. Peek 4.exit 
 Enter your choice:2

 item popped from top of stack:34

 1. Push 2. Pop 3. Peek 4.exit 
 Enter your choice:2

 item popped from top of stack:23

 1. Push 2. Pop 3. Peek 4.exit 
 Enter your choice:2

 Stack Underflow

 1. Push 2. Pop 3. Peek 4.exit 
 Enter your choice:4
*/