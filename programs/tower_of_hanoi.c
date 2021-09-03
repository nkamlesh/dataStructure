/*
Name:
Roll no:
Branch:
Title: Program on Tower of Hanoi, Using Recursion
*/

#include<stdio.h>

void tower_of_hanoi(int n, char source, char target, char auxillary){
	//termination condition for stopping further recursive calls
	if(n==1){
		printf(" Move disk 1 from %c to %c\n",source, target);
		return;
	}
	tower_of_hanoi(n-1,source,auxillary,target);
	printf(" Move disk %d from %c to %c\n",n,source,target);
	tower_of_hanoi(n-1,auxillary,target,source);
}

//Number of recursive calls will be 2^n - 1
int main(){
	int n=3; // number of disk
	tower_of_hanoi(n,'A','C','B');// source=A target=C auxillary=B
	return 0;
}

/*
output:
 Move disk 1 from A to C
 Move disk 2 from A to B
 Move disk 1 from C to B
 Move disk 3 from A to C
 Move disk 1 from B to A
 Move disk 2 from B to C
 Move disk 1 from A to C
*/