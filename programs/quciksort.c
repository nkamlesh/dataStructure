/*
Name:
Roll no:
Branch:
Title:Implementation of Quicksort
*/
#include <stdio.h>
#include<stdlib.h>
int partition(int *a, int s,int e){ // s- start of array, e- end of array
    int pivot=a[e];//taking last element as pivot elemeny
    int i=s-1,j,temp; //inialize i to start-1
    for(j=s;j<=e-1;j++){
        if(a[j]<pivot){
            i++;
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
    temp=a[i+1];
    a[i+1]=a[e];
    a[e]=temp;
    return i+1; //return position of pivot element in array, by placing pivot element at correct place.
}
//recursively apply the partitioning stratagy on subarrays to sort the list
void quicksort(int *a,int s,int e){
    int p;
    if(s<e){
        p=partition(a,s,e);
        //parition into left and right subarrays
        quicksort(a,s,p-1); //call of parition on left subarray
        quicksort(a,p+1,e);//call of parition on right subarray
    }
}

int main()
{
    int n,*a,i;
    printf("\nEnter the number of elements:");
    scanf("%d",&n);
    a=(int *)calloc(n,sizeof(int)); //dynmically allocates a memory
    if(a==NULL){
        printf("\nProgram can't Memory Not allocated");
    }
    //read the values of array
    printf("\nEnter the element values:");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    //display content before sorting 
    printf("\n content of array before sorting:");
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    //call to quicksort for soriting elements of array
    quicksort(a,0,n-1);
    //display content after sorting
    printf("\n content of array after sorting:");
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    return 0;
}

/*
Output:

Enter the number of elements:8

Enter the element values:1 3 5 6 2 4 8 0

 content of array before sorting:1 3 5 6 2 4 8 0 
 content of array after sorting:0 1 2 3 4 5 6 8 
*/