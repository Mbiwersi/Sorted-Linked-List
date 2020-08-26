//Implements a linked list of ints

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct SortedList {
	Node *head;
} SortedList;



SortedList * createSortedList();
//return a new empty List

void insert(SortedList *aList, int n);
//PRE: aList has been created and is sorted in ascending order
//insert n into aList so the list remains sorted in ascending order

void delete(SortedList *aList, int n);
//PRE: aList has been created and is sorted in ascending order
//remove all occurrences of n from aList and keep the list sorted
//in ascending order


void print(SortedList *aList);
//PRE: aList has been created

void destroySortedList(SortedList *aList);
//PRE: aList has been created
//free space created for aList
