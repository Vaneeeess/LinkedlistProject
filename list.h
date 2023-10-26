#ifndef List_H
#define List_H


struct Node
{
    int data;
    struct Node* next;
};

typedef struct Node list;
list *createNode (int data);
void makelist(list **head, int data);
void printlist(list *head);
list *addatfirst(list *head, int data);
list *addatpos(list **head, int data, int pos);
int countthelist(list *head);
int sumoflist(list *head);
list *addatbefore(list **head, int num, int data);
float average(list *head);
int addatafter(list *head, int num, int data);
#endif
