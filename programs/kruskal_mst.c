/*
Name:
Roll no:
Branch:
Title:Kruskal's to find MST
*/
#include <stdio.h>
#define MAX 40
typedef struct edge{
	int x,y,w,mst;
}edge;

typedef struct edgelist{
	edge e[MAX];
	int n;
}edgelist;
edgelist init_list;

void sort(){
	int i,j,min;
	edge temp;
	for(i=0;i<init_list.n;i++){
		min=i;
		for(j=i+1;j<init_list.n;j++){
			//find edge with minimum weight
			if(init_list.e[min].w>init_list.e[j].w){
				min=j;
			}
		}
		//place edge with ith smallest at properplace
		temp=init_list.e[i];
		init_list.e[i]=init_list.e[min];
		init_list.e[min]=temp;
	}
} 
//find edges which are part od MST.
void kruskal(int n){
    int p[MAX],i,v1,v2,nv=0,j;
    edge temp;
    //let every node be parent of itself
    for(i=0;i<n;i++){
        p[i]=i;
    }
    for(i=0;i<init_list.n;i++){
        temp=init_list.e[i];
        v1=p[temp.x];
        v2=p[temp.y];
        // if there parent is not common then it does not form cycle, thus add edge to MST
        if(v1!=v2){
            // for all nodes whose parent is v2, make v1 as parent
            for(j=0;j<n;j++){
                if(p[j]==v2){
                    p[j]=v1;
                }
            }
            //add the edge to MST
            init_list.e[i].mst=1;
        }
    }
}
void print(){
	int i,tc=0;
	printf("\nx  y  w  In_mst");
	for(i=0;i<init_list.n;i++){
		printf("\n%d  %d  %d  %d",init_list.e[i].x,init_list.e[i].y,init_list.e[i].w,init_list.e[i].mst);
		if(init_list.e[i].mst==1){
		    tc+=init_list.e[i].w;
		}
	}
	printf("\n Total Cost = %d \n",tc);
}
void main(){
	int n,e,i;
	printf("Enter the No. of Vertices:");
	scanf("%d",&n);
	printf("Enter the no. edges:");
	scanf("%d",&e);
	printf("\nEnter the edge details as follows : start_point end_point weight");
	init_list.n=e;
	for(i=0;i<e;i++){
		printf("\nEnter edge %d details:",i+1);
		scanf("%d %d %d",&init_list.e[i].x,&init_list.e[i].y,&init_list.e[i].w);
		init_list.e[i].mst=0;
	}
	sort();
	print();
	kruskal(n);
	print();
}
/*output:
Enter the No. of Vertices:6
Enter the no. edges:10

Enter the edge details as follows : start_point end_point weight
Enter edge 1 details:0 2 1 

Enter edge 2 details:3 5 2

Enter edge 3 details:1 4 3

Enter edge 4 details:0 1 3

Enter edge 5 details:2 5 4

Enter edge 6 details:1 2 5

Enter edge 7 details:2 3 5

Enter edge 8 details:0 3 6

Enter edge 9 details:4 2 6

Enter edge 10 details:4 5 6

x  y  w  In_mst
0  2  1  0
3  5  2  0
1  4  3  0
0  1  3  0
2  5  4  0
1  2  5  0
2  3  5  0
0  3  6  0
4  2  6  0
4  5  6  0
 Total Cost = 0 

x  y  w  In_mst
0  2  1  1
3  5  2  1
1  4  3  1
0  1  3  1
2  5  4  1
1  2  5  0
2  3  5  0
0  3  6  0
4  2  6  0
4  5  6  0
 Total Cost = 13 

*/