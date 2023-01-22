#include <stdio.h>
#include<stdlib.h>

typedef struct listNode {
	int Data;
	struct listNode* Next;
	struct listNode* Prev;
}Node;



//Create
Node* createNode(int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));

	// newNoode init
	newNode->Data = data;
	newNode->Next = NULL;
	newNode->Prev = NULL;

	return newNode;

}


//Search

Node* getNodeAt(Node* head, int index) {

	Node* horse = head;
	int count = 0;

	while (horse != NULL) {

		if (count++ == index) {
			return horse;
		}
		horse = horse->Next;
		
	}
	return NULL;
}


//Delete
void deleteNode(Node* Node) {
	free(Node);
}


//Node Count

int countNode(Node* head) {
	int count = 0;
	Node* horse = head;

	while (horse != NULL) {
		horse = horse->Next;
		count++;
	}
	return count;
}



//Add

void addNode(Node** head, Node* newNode) {
	
	// no list exists
	if (*head == NULL) {
		*head = newNode;
	}

	// list exists
	else {
		Node* horse = (*head);

		while (horse->Next != NULL) {
			horse = horse->Next;
		}
		horse->Next = newNode;
		newNode->Prev = horse;
	}

}


//Insert

void insertAfter(Node * Current,Node * newNode ) {

	//Head

	if (Current->Prev == NULL && Current->Next == NULL) {
		Current->Next = newNode;
		newNode->Prev = Current;
	}

	//Not head

		// Tail

	if (Current->Next == NULL) {
		Current->Next = newNode;
		newNode->Prev = Current;
	}
		// Not tail
	else {
		Current->Next->Prev = newNode;
		newNode->Prev = Current;
		newNode->Next = Current->Next;
		Current->Next = newNode;

	}
}


void removeNode(Node ** head, Node* remove) {
	//Head
	if (*head == remove) {
		*head = remove->Next;

	}
	//when remove has next
	if (remove->Next != NULL) {
		remove->Next->Prev = remove->Prev;
	}
	// when remove has prev

	if (remove->Prev != NULL) {
		remove->Prev->Next = remove->Next;
	}

	deleteNode(remove);
}


int main(void) {

	int i = 0;
	int count =  0;

	Node* List = NULL;

	Node* newNode = NULL;

	Node* Curr = NULL;

	for (i = 0; i < 5; i++) {
	
		newNode = createNode(i);
		addNode(&List, newNode);
	}

	count = countNode(List);

	for (i = 0; i < count; i++) {
		Curr = getNodeAt(List, i);
		printf("List[%d] = %d\n", i, Curr->Data);
	}

	printf("------------------ 5 Nodes created ------------------\n");

	newNode = createNode(99);
	Curr = getNodeAt(List, 0);
	insertAfter(Curr, newNode);

	newNode = createNode(444);
	Curr = getNodeAt(List, 4);
	insertAfter(Curr, newNode);

	count = countNode(List);

	for (i = 0; i < count; i++) {
		Curr = getNodeAt(List, i);
		printf("List[%d] = %d\n", i, Curr->Data);
	}

	printf("------------------ 2 Nodes inserted ------------------\n");

	newNode = getNodeAt(List, 1);
	removeNode(&List, newNode);

	newNode = getNodeAt(List, 0);
	removeNode(&List, newNode);

	count = countNode(List);

	for (i = 0; i < count; i++) {
		Curr = getNodeAt(List, i);
		printf("List[%d] = %d\n", i, Curr->Data);

	}

	printf("------------------ index 1 removed ------------------\n");


	return 0;
}
