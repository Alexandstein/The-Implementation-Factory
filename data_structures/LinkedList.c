#include "LinkedList.h"
#include <stdlib.h>
#include <stdio.h>

/*Node FUNCTIONS*/
/*Constructor creates empty Node*/
Node* Node_init()
{
	Node* output = (Node*)malloc(sizeof(Node));		//Allocate memory
	
	Node_setData(output, NULL);						//Initialize data to NULL
	Node_append(output, NULL);
	
	return output;
}

/*Constructor creates list with initial data input*/
Node* Node_initWithInput(void* input)
{
	Node* output = (Node*)malloc(sizeof(Node));		//Allocate memory
	
	Node_setData(output, input);					//Initialize data
	Node_append(output, NULL);						//Next is NULL
	
	return output;
}

/*Retrieves and returns the data contained in a node*/
void* Node_getData(Node* dataSource)
{
	return dataSource->data;						//Return data
}

/*Sets the data for a node*/
Node* Node_setData(Node* dataTarget, void* input)
{
	dataTarget->data = input;
	
	return dataTarget;
}

/*Get in the next node*/
Node* Node_getNext(Node* node)
{
	return node->next;
}

/*Attaches child as the 'next' variable for parent.*/
Node* Node_append(Node* parent, Node* child)
{
	parent->next = child;
	return parent;
}

/*Deletes Node*/
void Node_free(Node* toDelete)
{
	toDelete->next = NULL;
	free(toDelete->data);
	free(toDelete->next);
	free(toDelete);

	return;
}

/*Linked List FUNCTIONS*/
/*TODO Constructor for Linked List.*/
LinkedList* LinkedList_init()
{
	LinkedList* output = (LinkedList*)malloc(sizeof(LinkedList));
	output->head = NULL;
	output->cursor = NULL;
	
	return output;
}

/*Checks if list is empty*/
int LinkedList_isEmpty(LinkedList* list){
	if(list->head == NULL){
		return 1;
	}else{
		return 0;
	}
}

/*Pushes new Node to replace the head.*/
void LinkedList_pushFromHead(LinkedList* list, void* input)
{	
	Node* toPush = Node_initWithInput(input);
	
	if(LinkedList_isEmpty(list)){						//Check if empty
		list->head 	 = toPush;
		list->cursor = toPush;
		return;
	}else{												//Not empty
		Node_append(toPush, list->head);				//Link Nodes together
		list->head = toPush;							//Replace the head with new Node
		return;
	}
}

/*TODO Pops off from head*/
void* LinkedList_popFromHead(LinkedList* list)
{
	void* output;
	Node* toDelete;
	
	if(LinkedList_isEmpty(list)){						//Check if list is empty
		return NULL;									//Empty; return NULL
	}else{												//List is not empty; continue
		if(list->cursor == list->head){
			LinkedList_next(list);						//If cursor is on head, advance one.	
		}
	
		toDelete = list->head;
		output = Node_getData(toDelete);
		list->head = Node_getNext(list->head);
		//TODO Deal with Cursor Pointers.
		free(toDelete);
		return output;
	}
}

/*Pushes Node onto tail*/
void LinkedList_pushFromTail(LinkedList* list, void* input)
{
	Node* temp = list->cursor;							//Save cursor location
	Node* toPush = Node_initWithInput(input);
	
	if(LinkedList_isEmpty(list)){						//Check if empty
		list->head 	 = toPush;
		list->cursor = toPush;
		return;
	}else{												//Not empty
		while(LinkedList_isNext(list)){ 				//Iterate to end of list
			LinkedList_next(list);
		}
		Node_append(list->cursor, toPush);
		list->cursor = temp;							//Return cursor location
		return;
	}
}

/*TODO Pops Node from tail*/
void* LinkedList_popFromTail(LinkedList* list)
{
	Node* beforeNext = NULL;						//Keep track of node before cursor
	Node* temp = list->cursor;						//Store user's cursor location.
	Node* output;
	
	if(LinkedList_isEmpty(list)){						//Check if list is empty
		return NULL;									//Empty; return NULL
	}else{												//List is not empty; continue
		while(LinkedList_isNext(list)){					//Iterate to end.
			beforeNext = list->cursor;
			LinkedList_next(list);
		}
		output = list->cursor;
		beforeNext->next = NULL;						//Sever connection
	
		if(output == temp){
			temp = list->head;							//If cursor is on tail, set on head.	
		}
	
		list->cursor = temp;							//Return cursor
		return output;	
	}
}

/*Resets the cursor*/
void LinkedList_resetCursor(LinkedList* list)
{
	list->cursor = list->head;
	return;
}

/*Advance the cursor and return the data value.*/
void* LinkedList_next(LinkedList* list)
{
	if(list->cursor == NULL){
		return NULL;							//return null if there is no node on cursor.
	}
	
	void* output = Node_getData(list->cursor);
	list->cursor = Node_getNext(list->cursor);
	
	return output;
}

/*Returns true if there is a next Node, false if tail or NULL.*/
int LinkedList_isNext(LinkedList* list)
{
	if(list == NULL || Node_getNext(list->cursor) == NULL){
		return 0;
	}
		return 1;
}

/*Deletes the linked list from memory*/
void LinkedList_free(LinkedList* list)
{
	while(list->cursor != NULL){			//Keep iterating through to delete all nodes.
		free(LinkedList_popFromTail(list));
	}
	free(list);								//Finally, the list itself
	
	return;
}