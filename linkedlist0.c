// A basic program to add a node at the beginning of a linkedlist and to print the list. 

#include <stdio.h>
#include <stdlib.h>

//1. Node creation
struct node
{
    int data;
    struct node* next;
};

//function prototypes - because functions are written after the main function
void insertatthebeginning(struct node** head, int data);
void insertattheend(struct node**,int data);
void printlist(struct node* node);

int main()
{
    //initialize head pointer as null for empty list

    struct node* head = NULL;
    //insert elements at the beginning
    insertatthebeginning(&head, 1);
    insertatthebeginning(&head, 2);
    insertatthebeginning(&head, 3);

    insertattheend(&head,10);
    insertattheend(&head,20);
    insertattheend(&head,30);

    //print the linkedlist
    printlist(head);
    return 0;
}

//inserts a new node at the beginning of the list
//Function definition
void insertatthebeginning(struct node** head, int data)
{
    //allocate memory for the new node
    struct node* newnode = (struct node*) malloc(sizeof(struct node));/*Since the pointer variable newnode is of the type (struct node), 
    it will have both next and data as its properties*/
    newnode ->data = data;

    //make the new node point to the current head
    newnode ->next = *head;

    //update the head pointer to point to the new node
    *head = newnode;

    /*A double pointer is used in the function argument because:
    If you use a single pointer (struct node* head), the function would receive a copy of the head pointer.
    Modifying this copy would not affect the original head pointer in the calling function, so the changes would be lost 
    once the function returns.

    Double Pointer Scenario:
    By using a double pointer (struct node** head), you pass the address of the head pointer. 
    This allows the function to modify the original head pointer, making sure the changes persist after the function returns.
    */

}

void insertattheend(struct node ** head, int data)
{
    // Allocate memory for the new node
    struct node* newnode1=(struct node*)malloc(sizeof(struct node));
    newnode1->data=data;
    newnode1->next=NULL; // Initialize the next pointer of the new node to NULL
    // If the list is empty, make the new node the head
    if (*head == NULL)
    {
        *head = newnode1;
        return;
    }
    
    // Traverse to the end of the list
    struct node* temp = *head;
    while(temp->next != NULL)
    {
        temp=temp->next;
    }
    // Add the new node at the end of the list
    temp->next = newnode1;


}



void printlist(struct node* node)
{
    while(node!=NULL)
    {
       while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
        }
    }

    printf("\n");
}