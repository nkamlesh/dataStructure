/*
Name:
Roll no:
Branch:
Title: Implementation of Circular Queue using array.
*/
#include <stdio.h>
#define size 3

struct queue{
    int q[size];
    int front,rear;
}que;

int is_empty(){
	if(que.front==-1)
		return 1;
	return 0;
}
int is_full(){
	if((que.front==que.rear+1) || (que.front==0 && que.rear==size-1)){
        
        return 1;
    }
	return 0;
}
void enque(int item){
    
    //it item is first element of queue
    if(is_empty()){
        que.front=0;
        que.rear=0;
    }
    else{
        que.rear=(que.rear+1)%size;      
    }
    que.q[que.rear]=item;
    
}

int deque(){
    int temp;
        temp=que.q[que.front];
        if(que.front==que.rear){
            que.front=-1;
            que.rear=-1;
        }
        else{
            que.front=(que.front+1)%size;
        }
    
    return temp;
}

void display(){
	int i;
	
	printf("\nElements in Queue:");
	if(que.rear<que.front){
	   for(i=que.front;i<=size-1;i=i+1){
		    printf("%d ",que.q[i]);
	   }
	   for(i=0;i<=que.rear;i++){
	        printf("%d ",que.q[i]);
	   }
	}
	else{
	    for(i=que.front;i<=que.rear;i=i+1){
		    printf("%d ",que.q[i]);
	   }
	}
	
}

int main()
{
    //intialization part
    que.front=-1;
    que.rear=-1;
	int choice,item;
	do{
		printf("\n1. Insert 2.Delete 3.Display 4.Exit");
		printf("\nEnter your Choice:");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				if(!is_full()){
					printf("\nEnter the item to be inserted:");
					scanf("%d",&item);
					enque(item);
				}
				else{
					printf("\nQueue is full");
				}
			break;
			case 2:
				if(is_empty())
					printf("\nQueue is empty");
				else{
					item=deque();
					printf("\n%d item is dequeued",item);
				}
			break;
			case 3:
				display();
				if(is_empty()){
					printf("No elements in queue");
				}
			break;
			default:
				printf("\nInvalid Choice");
			break;
			
		}
	}while(choice!=4);
	
    return 0;
}
/*output
1. Insert 2.Delete 3.Display 4.Exit

Enter your Choice:1
Enter the item to be inserted:23

1. Insert 2.Delete 3.Display 4.Exit

Enter your Choice:1
Enter the item to be inserted:24

1. Insert 2.Delete 3.Display 4.Exit

Enter your Choice:1
Enter the item to be inserted:25

1. Insert 2.Delete 3.Display 4.Exit

Enter your Choice:2
23 item is dequeued

1. Insert 2.Delete 3.Display 4.Exit

Enter your Choice:3
Elements in Queue:24 25 

1. Insert 2.Delete 3.Display 4.Exit
Enter your Choice:4
Invalid Choice
*/