/*
Name:
Roll no:
Branch:
Title:Implementation of Doubly Linked List
*/
#include <stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *prev, *next;
};

struct node *start;

void insertFirst(int item){
    struct node * temp;
    temp=(struct node*)malloc(sizeof(struct node));
    if(temp==NULL){
        printf("mem not allocated");
        return;
    }
    temp->data=item;
    temp->prev=NULL;
    if(start==NULL){
        temp->next=NULL;
        start=temp;
    }
    else{
        temp->next=start;
        start->prev=temp;
        start=temp;
    }
    printf("\nnode with value %d inserted successfully",item);
}
void insertLast(int item){
    struct node * temp,*p;
    temp=(struct node*)malloc(sizeof(struct node));
    if(temp==NULL){
        printf("mem not allocated");
        return;
    }
    temp->data=item;
    temp->next=NULL;
    if(start==NULL){
        temp->prev=NULL;
        start=temp;
    }
    else{
        p=start;
        while(p->next!=NULL){
            p=p->next;
        }
        p->next=temp;
        temp->prev=p;
    }
    printf("\nnode with value %d inserted successfully",item);
}
int delFirst(){
    int item;
    struct node *temp;
    if(start==NULL){
        printf("\nlist is empty");
        return -1;
    }
    item=start->data;
    temp=start;
    start=start->next;
    free(temp);
    return item;
}
int delLast(){
    int item;
    struct node *temp;
    if(start==NULL){
        printf("\nlist is empty");
        return -1;
    }
    temp=start;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    item=temp->data;
    if(temp==start){
        start=NULL;
    }
    else{
        temp->prev->next=NULL;
    }
    free(temp);
    return item;
}
void display(){
    struct node *traverse=start;
    int i=0;
    if(start==NULL){
        printf("\nlist is empty");
        return;
    }
    printf("\nlinked list elements:");
    while(traverse!=NULL){
        printf("\n_________________________________");
        printf("\n%d| %10u | %d | %10u |",i+1,traverse->prev,traverse->data,traverse->next);
        printf("\n---------------------------------");
        traverse=traverse->next;
        i++;
    }
}
int main(){
    //initialize to null;
    start=NULL;
    insertFirst(10);
    insertFirst(20);
    insertLast(30);
    insertFirst(40);
    insertFirst(50);
    insertLast(60);
    display();
    delLast();
    display();
    delFirst();
    display();
    return 0;
}
/*
Output

node with value 10 inserted successfully
node with value 20 inserted successfully
node with value 30 inserted successfully
node with value 40 inserted successfully
node with value 50 inserted successfully
node with value 60 inserted successfully
linked list elements:
no  prev       data     next
_________________________________
1|          0 | 50 | 3418814224 |
---------------------------------
_________________________________
2| 3418814256 | 40 | 3418814160 |
---------------------------------
_________________________________
3| 3418814224 | 20 | 3418813088 |
---------------------------------
_________________________________
4| 3418814160 | 10 | 3418814192 |
---------------------------------
_________________________________
5| 3418813088 | 30 | 3418814288 |
---------------------------------
_________________________________
6| 3418814192 | 60 |          0 |
---------------------------------
linked list elements:
_________________________________
1|          0 | 50 | 3418814224 |
---------------------------------
_________________________________
2| 3418814256 | 40 | 3418814160 |
---------------------------------
_________________________________
3| 3418814224 | 20 | 3418813088 |
---------------------------------
_________________________________
4| 3418814160 | 10 | 3418814192 |
---------------------------------
_________________________________
5| 3418813088 | 30 |          0 |
---------------------------------
linked list elements:
_________________________________
1| 3418814256 | 40 | 3418814160 |
---------------------------------
_________________________________
2| 3418814224 | 20 | 3418813088 |
---------------------------------
_________________________________
3| 3418814160 | 10 | 3418814192 |
---------------------------------
_________________________________
4| 3418813088 | 30 |          0 |
---------------------------------
*/