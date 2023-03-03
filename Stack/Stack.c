#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)


typedef struct sNode {

	char* data;
	struct sNode* next;

}Node;


typedef struct listStack {

	Node* peek;
	int size;

}listStack;

void createStack(listStack** Stack) {

	(*Stack) = (listStack*)malloc(sizeof(listStack));
	(*Stack)->peek = NULL;
	(*Stack)->size = 0;


}

Node* creatNode(char* newChar) {

	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = (char*)malloc(strlen(newChar) + 1);

	strcpy(newNode->data, newChar);
	newNode->next = NULL;
	return newNode;
}




void Push(listStack* Stack, Node* newNode) {

	//Empty stack
	if (Stack->size == 0) {
		Stack->peek = newNode;
	}
	// Not empty
	else {
		newNode->next = Stack->peek;
		Stack->peek = newNode;
	}
	Stack->size++;
}

Node* Pop(listStack* Stack) {
	Node* tempNode;

	//Empty stack
	if (Stack->size == 0) {
		printf("Stack is empty\n");
		tempNode = NULL;
	}
	//Not empty
	else {
		tempNode = Stack->peek;
		Stack->peek =Stack->peek->next;
		Stack->size--;
	}
	
	return tempNode;
}

void deleteNode(Node* removeNode) {
	free(removeNode->data);
	free(removeNode);
}

void deleteStack(listStack* Stack) {

	int count = Stack->size;
	int i;
	Node* tempNode;

	for (i = 0; i < count; i++) {
		tempNode = Pop(Stack);
		deleteNode(tempNode);
	}
	free(Stack);
}




int main(void) {

	int i;
	listStack* Stack;

	createStack(&Stack);

	Push(Stack, creatNode("a"));
	Push(Stack, creatNode("b"));
	Push(Stack, creatNode("c"));
	Push(Stack, creatNode("d"));

	printf("abcd pushed\n");
	
	
	printf("\n Stack_size : %d\n", Stack->size);

	Node* horse = Stack->peek;
	for (i = 0; i < (Stack->size); i++) {
		printf("\n%s\n", horse->data);
		horse = horse->next;
	}

	horse = Pop(Stack);
	horse = Pop(Stack);


	printf("\n Stack_size : %d\n", Stack->size);

	horse = Stack->peek;
	for (i = 0; i < (Stack->size); i++) {
		printf("\n%s\n", horse->data);
		horse = horse->next;
	}

	deleteStack(Stack);
	printf("\nstack has been completely freed\n");
	return 0;
}
