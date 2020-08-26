//Michael Biwresi
//Sorted Linked List implementation 

#include <stdio.h>
#include <stdlib.h>
#include "SortedList.h"

SortedList * createSortedList(){
//return a new empty List
	SortedList *list = (SortedList *) malloc(sizeof(SortedList));
	list->head = NULL;
	return list;
}

void insert(SortedList *aList, int n){
//PRE: aList has been created and is sorted in ascending order
//insert n into aList so the list remains sorted in ascending order
	Node *insert = (Node *) malloc(sizeof(Node));
	insert->data = n;
	insert->next = NULL;
	Node *current = (Node *) malloc(sizeof(Node));
	current = aList->head;
	Node *prev = (Node *) malloc(sizeof(Node));
	prev = current;
	if(current==NULL){
		aList->head = insert;
	
	}
	else if(current->data>n){
		insert->next = aList->head;
		aList->head = insert;
	}
	else{
		while(current!=NULL&&(current->data)<n){
			prev = current;
			current = current->next;
		}
		prev->next = insert;
		insert->next = current;
	}
}

void delete(SortedList *aList, int n){
//PRE: aList has been created and is sroted in ascending order
//remove all occurrences of n from aList and keep the list sorted
//in ascending order
	Node *temp;
	Node *temp1;
	while((aList->head!=NULL &&aList->head->data == n)){
		temp = aList->head;
		aList->head = aList->head->next;
		free(temp);
	}
	if(aList->head ==NULL)return;
	else if(aList->head->data>n)return; //taking advantage that the list is sorted
	temp = aList->head;
	while(temp->next!=NULL){
		if(temp->next->data==n){
			temp1 = temp->next;
			temp->next = temp->next->next;
			free(temp1);
		}
		else if(temp->next->data>n)return;
		else {
			temp = temp->next;
		}
	}

}

void print(SortedList *aList){
//PRE: aList has been created
	Node *current = aList->head;
	while(current!=NULL){
		if(current->next!=NULL){
			printf("%d, ",current->data);
		}
		else{
			printf("%d",current->data);
		}
		current = current->next;
	}
	printf("\n");
}

void destroySortedList(SortedList *aList){
//PRE: aList has been created
//free space created for aList
	Node *temp;
	Node *temp1;
	temp = aList->head;
	while(temp!=NULL){
		temp1 = temp;
		temp = temp->next;
		free(temp1);
	}
	free(aList);

}

