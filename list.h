#ifndef Source_H
#define Source_H


struct Node {
	
	int data;
	struct Node* next;
};

typedef struct Node list;


list *createNode(int data);
void makelist(list **head, int data);
void printlist(list *head);
list *reverse(list *head);
int countthenodes(list *head);
list *insertatFront(list *head, int data);
void insertatEnd(list **head, int data);
list *insertatMid(list *head, int data);
list *deletefirstlist(list *head);
list *deletemiddle(list *head);
list *deleteend(list *head);
list *search(list *head, int data);
list *insertatPos(list **head, int data, int pos);
int sumoflist(list *head);
float average(list *head);
list *addatBefore(list **head, int num, int data);
list *addatAfter(list *head, int num, int data);

#endif
