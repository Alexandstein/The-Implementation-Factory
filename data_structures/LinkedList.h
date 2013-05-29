#ifndef LINKEDLIST_H
#define LINKEDLIST_H

/*Linked List Node*/
typedef struct Node{
	struct Node* next;
	void* data;
} Node;

/*Linked List data structure*/
typedef struct LinkedList{
	Node* head;
	Node* cursor;
} LinkedList;
#endif

/*Node FUNCTIONS*/
/*Constructor creates empty Node*/
Node* Node_init();

/*Constructor creates list with initial data input*/
Node* Node_initWithInput(void* input);

/*Retrieves and returns the data contained in a node*/
void* Node_getData(Node* dataSource);

/*Sets the data for a node*/
Node* Node_setData(Node* dataTarget, void* input);

/*Gets next Node*/
Node* Node_getNext(Node* node);

/*Attaches child as the 'next' variable for parent.*/
Node* Node_append(Node* parent, Node* child);

/*Deletes Node*/
void Node_free(Node* toDelete);

/*Linked List FUNCTIONS*/
/*Constructor for Linked List.*/
LinkedList* LinkedList_init();

/*Checks if list is empty*/
int LinkedList_isEmpty(LinkedList list);

/*Pushes new Node to replace the head.*/
void LinkedList_pushFromHead(LinkedList* list, void* input);

/*Pops off from head*/
void* LinkedList_popFromHead(LinkedList* list);

/*Pushes Node onto tail*/
void LinkedList_pushFromTail(LinkedList* list, void* input);

/*Pops Node from tail*/
void* LinkedList_popFromTail(LinkedList* list);

/*Resets the cursor*/
void LinkedList_resetCursor(LinkedList* list);

/*Advance the cursor and return the data value.*/
void* LinkedList_next(LinkedList* list);

/*Returns true if there is a next Node, false if tail.*/
int LinkedList_isNext(LinkedList* list);

/*Deletes the linked list from memory*/
void LinkedList_free(LinkedList* list);