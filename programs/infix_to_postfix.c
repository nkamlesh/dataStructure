/*
Name:
Roll no:
Branch:
Title: Program on implementation of stack using array
*/
#include<stdio.h>
#include<string.h>
#define SIZE 20
struct stack{
    int a[SIZE];
    int top;
}s;
//returns 1 if empty, else 0
int is_empty(){
    if(s.top==-1)
        return 1;
    return 0;
}
//returns 1 if full, else 0
int is_full(){
    if(s.top==SIZE-1)
        return 1;
    return 0;
}
//push into stack
void push(int item){
    if(is_full()){
        return;
    }
    s.top=s.top+1;
    s.a[s.top]=item;
}
//pop from stack
int pop(){
    int temp;
    if(is_empty()){
        return -1;
    }    
    temp=s.a[s.top];
    s.top=s.top-1;
    return temp;
}
//return top element of stack
int peek(){
    int temp;
    if(is_empty()){
        return -1;
    }    
    temp=s.a[s.top];
    return temp;
}
//check char is operand
int is_operand(char c){
    if((c>='a' && c<='z')||(c>='A' && c<='Z'))
        return 1;
    return 0;
}
//check char is bracket
int is_bracket(char c){
    switch(c){
        case '(':
        case '{':
        case '[':
            return 1;
        break;
        case ')':
        case '}':
        case ']':
            return 2;
        break;
        default:
            return 0;
    }
}
//check char is operator
int is_operator(char c){
    switch(c){
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
            return 1;
        break;
    }
    return 0;
}
int op_pred(char c){
    
    switch(c){
        case '+':
        case '-':
                return 1;
        break;
        case '*':
        case '/':
                return 2;
        break;
        case '^':
                return 3;
        break;
        case '(':
        case '{':
        case '[':
            return 0;
        break;
        default:
            return -1;
        break;
    }
}
int is_pair(char x,char y){
    if(x==-1){
        return -1;
    }
    if((x=='{' && y=='}')||(x=='(' && y==')')||(x=='[' && y==']'))
        return 1;
    return 0;
}
int main(){
    
    //initilization
    s.top=-1;
    int length,i; //length contains length of infix
    
    int postfix_length=0,temp,flag=0;
    char curr_char; //hold curr_char under scan
    char infix[50],postfix[50];
    printf("Enter the infix String:");
    scanf("%s",infix);
    length=strlen(infix);
    //scanning from left to right
    for(i=0;i<length;i++){
        //current charcter under scanning
        curr_char=infix[i];
        // if current char is operand , we add to output string
        if(is_operand(curr_char)){
            postfix[postfix_length]=curr_char;
            postfix_length=postfix_length+1;
        }        
        else{ 
            //if current character is bracket
            temp=is_bracket(curr_char);
            //if it is opening bracket, add to the stack
            if(temp==1){
                push(curr_char);
            }
            //if it is closing bracket, remove continuously from stack, until we get matching closing pair
            else if(temp==2){
                while(!is_pair(peek(),curr_char)){
                    temp=pop();
                    postfix[postfix_length]=temp;
                    postfix_length=postfix_length+1;
                }
                // discard the cosing bracket, if empty set error flag
                if(pop()==-1){
                    flag=1;
                    break;
                }
            }
            else{
                if(is_operator(curr_char)){
                    //continuously pop from stack, until stack is empty or operator on top of stack is of lower prec
                    while(op_pred(curr_char)<=op_pred(peek())){
                            temp=pop();
                            postfix[postfix_length]=temp;
                            postfix_length=postfix_length+1;
                    }
                    //add the current operator onto stack
                    push(curr_char);
                }
                else{
                    flag=1;
                    break;
                }
            }
        }
        
    }
    
    while(!is_empty()){
        temp=pop();
        //if any of the bracket is remaining, set error flag
        if(is_bracket(temp)){
            flag=1;
            break;
        }
        postfix[postfix_length]=temp;
        postfix_length=postfix_length+1;    
    }
    if(flag==1){
        printf("\nInvalid Expression");
        return 1;
    }
    postfix[postfix_length]='\0';
    postfix_length=postfix_length+1;
    printf("postfix: %s",postfix);    
    return 0;
}

/*
output
Enter the infix String:(a+b*c
Invalid Expression

Enter the infix String:a+b)*c
Invalid Expression

Enter the infix String:(a+b]*c
Invalid Expression

Enter the infix String:(a+b)*c
postfix: ab+c*

*/

