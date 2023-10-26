#include <stdio.h>
#include <stdlib.h>
#include "source.h"


list *createNode(int data)
{
	list *newNode = (list*)malloc(sizeof(list));
	
	newNode->data = data;
	newNode->next = NULL;
	
	return newNode;
}

void makelist(list **head, int data) 
{
	
	list *newNode = createNode(data);
	
	if(*head == NULL) 
	{
		*head = newNode;
		return;
	}
	
	list *lastNode = *head;
	while(lastNode->next != NULL) 
	{
		lastNode = lastNode->next;
	}
	
	lastNode->next = newNode;
}

void printlist(list *head)
{
	
	list *curr = head;
	
	while(curr != NULL) 
	{
		printf("%d\t", curr->data);
		curr = curr->next;
	}
}

list *reverse(list *head) 
{
	list *current = head;
	list *prev = NULL;
	list *next = NULL;
	
	while(current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	
	return prev;
}

int countthenodes(list *head)
{
	list *curr = head;
	
	int count = 0;
	while(curr != NULL) 
	{
		count++;
		curr = curr->next;
	}
	
	return count;
}

list *insertatFront(list *head, int data) 
{
	
	list *newNode = (list*)malloc(sizeof(list));
	
	newNode->data = data;
	newNode->next = head;
	
	return newNode;
}

void insertatEnd(list **head, int data)
{
	
	list *newNode = (list*)malloc(sizeof(list));
	
	newNode->data = data;
	newNode->next = NULL;
	
	if(*head == NULL)
	{
		*head = newNode;
		return;
	}
	
	list *st = *head;
	while(st->next != NULL)
	{
		st = st->next;
	}
	
	st->next = newNode;
}

list *insertatMid(list *head, int data)
{
	
	list *newNode = (list*)malloc(sizeof(list));
	
	newNode->data = data;
	
	list *curr = head;
	list *prev = head;
	while(curr != NULL && curr->next != NULL) 
	{
		curr = curr->next->next;
		prev = prev->next;
	}
	
		newNode->next = prev->next;
		prev->next = newNode;
	
	return head;
}

list *deletefirstlist(list *head) 
{
	
	list *curr = head->next;
	free(head);
	
	return curr;
}

list *deletemiddle(list *head) 
{
	list *curr = head;
	list *prev = head;
	while(curr != NULL && curr->next != NULL)
	{
		curr = curr->next->next;
		prev = prev->next;
	}
	
	list *kewk = curr->next;
	prev->next = curr->next;
	free(curr);
	
	return head;
}

list *deleteend(list *head) 
{
	list *curr = head;
	while(curr != NULL)
	{
		curr = curr->next;
	}
	
	free(curr->next);
	
	return head;
}

list *search(list *head, int data)
{
	
	list *curr = head;
	
	int found = 0;
	while(curr != NULL)
	{
		if(curr->data = data)
		{
			found = 1;
			break;
		}
		
		curr = curr->next;
	}
	if(found) 
	{
		printf("The element is existing and found.\n");
	}
	else 
	{
		printf("The element is not exisitng and not found.\n");
	}
}

list *insertatPos(list **head, int data, int pos)
{
	
	list *newNode = (list*)malloc(sizeof(list));
	
	newNode->data = data;
	newNode->next = NULL;
	
	pos--;
	
	if(*head == NULL) 
	{
		*head = newNode;
		return *head;
	}
	
	list *current = *head;
	int count = 1;
	
	while(count < pos && current->next) 
	{
		current = current->next;
		count++;
	}
	
	if(current == NULL)
	{
		printf("Invalid position\n");
		return *head;
	}
	
	newNode->next = current->next;
	current->next = newNode;
	
	return *head;
}

int sumoflist(list *head) 
{
	list *curr = head;
	int sum = 0;
	while(curr != NULL) 
	{
		sum+= curr->data;
		curr = curr->next;
	}
	
	return sum;
}

float average(list *head) 
{
	list *curr = head;
	int sum = 0;
	int count = 0;
	while(curr != NULL)
	{
		count++;
		sum+= curr->data;
		curr = curr->next;
	}
	
	float avg = (float) sum / count;
	
	return avg;
}

list *addatBefore(list **head, int num, int data)
{
	
	list *newNode = (list*)malloc(sizeof(list));
	
	newNode->data = data;
	newNode->next = NULL;
	
	if(*head == NULL) 
	{
		return newNode;
	}
	
	if((*head)->data == num)
	{
		newNode->next = *head;
		*head = newNode;
		return *head;
	}
	list *curr = *head;
	
	while(curr->next != NULL && curr->next->data != num)
	{
		curr = curr->next;
	}
	
	if(curr == NULL)
	{
		printf("%d is not exiting the the list.\n", num);
		return *head;
	}
	
	newNode->next = curr->next;
	curr->next = newNode;
	
	return *head;
}

list *addatAfter(list *head, int num, int data)
{
	
	list *newNode = (list*)malloc(sizeof(list));
	
	newNode->data = data;
	newNode->next = NULL;
	
	if(head == NULL)
	{
		return newNode;
	}
	
	list *curr = head;
	while(curr->next != NULL && curr->next->data != num)
	{
		curr = curr->next;
	}
	
	if(curr == NULL)
	{
		printf("%d is not exiting in the list.\n", num);
		return head;
	}
	
	newNode->next = curr->next;
	curr->next = newNode;
	
	return head;
}
