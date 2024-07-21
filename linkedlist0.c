#include <stdio.h>
#include <stdlib.h>

//1. Node creation
struct node
{
    int data;
    struct node* next;
};


void insertatthebeginning(struct node** head, int data);
void printlist(struct node* node);

int main()
{
    //initialize head pointer as null for empty list

    struct node* head = NULL;
    //insert elements at the beginning
    insertatthebeginning(&head, 1);
    insertatthebeginning(&head, 2);
    insertatthebeginning(&head, 3);

    //print the linkedlist
    printlist(head);
    return 0;
}

//inserts a new node at the beginning of the list

void insertatthebeginning(struct node** head, int data)
{
    //allocate memory for the new node
    struct node* newnode = (struct node*) malloc(sizeof(struct node));
    newnode ->data = data;

    //make the new node point to the current head
    newnode ->next = *head;

    //update the head pointer to point to the new node
    *head = newnode;

}

void printlist(struct node* node)
{
    while(node!=NULL)
    {
        printf("%d\n", node->data);
        node = node ->next;
    }
    printf("\n");
}