/*
Name:
Roll no:
Branch:
Title:Implementation of Hashing Concept
*/
#include<stdio.h>
#define size 7
int arr[size];
void init()
{   
    int i;
    for(i = 0; i < size; i++)
        arr[i] = -1;
}
void insert(int value)
{   
    int key = value % size;
    
    if(arr[key] == -1)
    {   
        arr[key] = value;
        printf("%d inserted at arr[%d]\n", value,key);
    }
    else
    {   
        printf("Collision : arr[%d] has element %d already!\n",key,arr[key]);
        printf("Unable to insert %d\n",value);
    }
}
void del(int value)
{
    int key = value % size;
    if(arr[key] == value)
        arr[key] = -1;
    else
        printf("%d not present in the hash table\n",value);
}

void search(int value)
{
    int key = value % size;
    if(arr[key] == value)
        printf("Search Found\n");
    else
        printf("Search Not Found\n");
}

void print()
{
    int i;
    printf("\n Hash Table:\n");
    for(i = 0; i < size; i++)
        printf("|%d:%d",i,arr[i]);
    printf("|\n");
}

int main()
{
    init();
    insert(10); //key = 10 % 7 ==> 3
    insert(4);  //key = 4 % 7  ==> 4
    insert(2);  //key = 2 % 7  ==> 2
    insert(3);  //key = 3 % 7  ==> 3 (collision)

    printf("Hash table\n");
    print();
    printf("\n");

    printf("Deleting value 10..\n");
    del(10);
    printf("After the deletion hash table\n");
    print();
    printf("\n");

    printf("Deleting value 5..\n");
    del(5);
    printf("After the deletion hash table\n");
    print();
    printf("\n");

    printf("Searching value 4..\n");
    search(4);
    printf("Searching value 10..\n");
    search(10);

    return 0;
}
/*
10 inserted at arr[3]
4 inserted at arr[4]
2 inserted at arr[2]
Collision : arr[3] has element 10 already!
Unable to insert 3
Hash table

 Hash Table:
|0:-1|1:-1|2:2|3:10|4:4|5:-1|6:-1|

Deleting value 10..
After the deletion hash table

 Hash Table:
|0:-1|1:-1|2:2|3:-1|4:4|5:-1|6:-1|

Deleting value 5..
5 not present in the hash table
After the deletion hash table

 Hash Table:
|0:-1|1:-1|2:2|3:-1|4:4|5:-1|6:-1|

Searching value 4..
Search Found
Searching value 10..
Search Not Found

*/