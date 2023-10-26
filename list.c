#include <stdio.h>
#include "list.h"
#include <stdlib.h>

list *createNode (int data)
{
    list* newNode = malloc(sizeof(list));

    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

void makelist(list **head , int data)
{
    list* newNode = createNode(data);

    if(*head == NULL)
    {
        *head = newNode;
        return;
    }

    list* st = *head;
    while(st->next != NULL)
    {
        st = st->next;
    }

    st->next = newNode;
}

void printlist(list *st)
{
    while(st != NULL)
    {
        printf("%d ", st->data);
        st = st->next;
    }
    printf("\n\n");
}

list *addatfirst(list *head, int data)
{
    list *st = malloc(sizeof(list));

    st->data = data;
    st->next = head;

    return st;
}

list *addatpos(list **head, int data, int pos)
{
    pos--;

    list *st = malloc(sizeof(list));
    
    st->data = data;
    st->next = NULL;

    if(*head == NULL)
    {
        *head = st;
        return *head;
    }

    list* current = *head;
    int count = 1;

    while(count < pos && current != NULL)
    {
        current = current->next;
        count++;
    }

    if(current == NULL)
    {
        printf("Invalid position\n");
        return *head;
    }

    st->next = current->next;
    current->next = st;
    
    return *head;
}

int countthelist(list *head)
{
    int count = 0;
    list *current = head;

    while(current != NULL)
    {
        count++;
        current = current->next;
    }

    return count;
}

int sumoflist(list *head) 
{
	int sum = 0;
	list *current = head;
	
	while(current != NULL)
	{
		sum+= current->data;
		current = current->next;
	}
	
	return sum;
}

list *addatbefore(list **head, int num, int data)
{
	list *newNode = malloc(sizeof(list));
	
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
	
	list *current = *head;
	while(current->next != NULL && current->next->data != num)
	{
		current = current->next;
	}
	
	if(current->next == NULL) 
	{
	    printf("%d is not existing in the list.\n", num);
		return *head;	
	}
		newNode->next = current->next;
		current->next = newNode;
	
	return *head;
}

float average(list *head) 
{
	int sum = 0;
	int count = 0;
	list *current = head;
	while(current != NULL)
	{
		count++;
		sum+=current->data;
		current = current->next;
	}
	
	float avg = (float) sum / count;
	
	return avg;
}

int addatafter(list *head, int num, int data) 
{
	
	list *newNode = malloc(sizeof(list));
	
	newNode->data = data;
	newNode->next = NULL;
	
	if(head == NULL)
	{
		return newNode;
	}
	
	list *current = head;
	while(current->next != NULL && current->next->data != num)
	{
		current = current->next;
	}
	
	if(current == NULL) 
	{
		printf("%d is not existing in the list.\n", num);
		return head;
	}
	
	newNode->next = current->next;
	current->next = newNode;
	
	return head;
}


