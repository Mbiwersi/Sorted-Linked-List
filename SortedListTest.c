//Michael Biwersi
#include <stdio.h>
#include <stdlib.h>
#include "SortedList.h"

int main(int argc, char * argv[]){
	SortedList *x = createSortedList();
	for(int i=0; i< 10; i++){
	//	printf("%d\n", i);
		insert(x, i);
	}
       	print(x);
	for(int i =0; i<10; i+=2){
		delete(x,i);
	}
	print(x);
	for(int i=20; i>10; i--){
		insert(x,i);
	}
	print(x);
	insert(x,0);
	insert(x,21);
	print(x);
	destroySortedList(x);
	printf("destroyed list\n");
	print(x);
	exit(0);
}
