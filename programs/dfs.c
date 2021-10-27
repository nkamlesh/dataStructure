/*
Name:
Roll no:
Branch:
Title:Implementation of DFS
*/
#include <stdio.h>
#include <stdio.h>
#define SIZE 30 //size of stack can be changed from here
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
//Initialize the 2d matrix of graph with 0
void init(int v[][SIZE],int visited[],int n){
    int i,j;
    for(i=0;i<n;i++){
        visited[i]=0;
        for(j=0;j<n;j++){
            v[i][j]=0;
        }
    }
}
//print the 2d matrix of graph and nodes visited in DFS traversal
void print(int v[][SIZE],int visited[],int n){
    int i,j;
    printf("\nnodes part of DFS:");
    
    for(i=0;i<n;i++){
        if(visited[i]==1)
        printf("%d ",visited[i]);
    }
    printf("\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d ",v[i][j]);
        }
        printf("\n");
    }
}
//DFS  traversal Logic
void DFS(int v[][SIZE],int visited[],int start,int n){
    int i,curr;
    // Add the starting vertex in stack
	push(start);
    visited[start]=1;
    //while stack is not empty
    while(!is_empty()){
        curr=pop(); //extract element from stack and mark it as current element
        printf("%d ",curr);
        for(i=n-1;i>=0;i--){
            //add all the neighbours of current element that are not visited to stack and mark them visited
            if(v[curr][i]==1 && visited[i]==0){
                push(i);
                visited[i]=1;
            }
        }
        
    }
}
void main(){
    int v[SIZE][SIZE],n,e,i,j,d,src,des,visited[SIZE];
    s.top=-1;
    printf("\nEnter the number of Vertices:");
    scanf("%d",&n);
    printf("\nEnter the number of Edges:");
    scanf("%d",&e);
    init(v,visited,n);
    printf("\nstarted Reading....");    
    for(i=0;i<e;i++){
        printf("\nEnter the source: ");
        scanf("%d",&src);
        printf("\nEnter the destination: ");
        scanf("%d",&des);
        v[src][des]=1;
        v[des][src]=1;
    }
    print(v,visited,n);
    printf("Enter starting node:");
    scanf("%d",&src);
    printf("\n Result:\n");
    DFS(v,visited,src,n);
    print(v,visited,n);
    printf("\nDone");
}
/*

Enter the number of Vertices:6

Enter the number of Edges:6

started Reading....
Enter the source: 0

Enter the destination: 1

Enter the source: 0

Enter the destination: 2

Enter the source: 0

Enter the destination: 3

Enter the source: 1

Enter the destination: 4

Enter the source: 1

Enter the destination: 5

Enter the source: 2

Enter the destination: 5

nodes part of DFS:
0 1 1 1 0 0 
1 0 0 0 1 1 
1 0 0 0 0 1 
1 0 0 0 0 0 
0 1 0 0 0 0 
0 1 1 0 0 0 
Enter starting node:0

 Result:
0 1 4 5 2 3 
nodes part of DFS:1 1 1 1 1 1 
0 1 1 1 0 0 
1 0 0 0 1 1 
1 0 0 0 0 1 
1 0 0 0 0 0 
0 1 0 0 0 0 
0 1 1 0 0 0 

Done
*/