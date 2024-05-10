#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
} Node;

Node *head = NULL;

void deleteAlt()
{
    if(!head)
        return;

    Node *temp = head;
    Node *del = temp->next;
    while(del){
        temp->next = del->next;
        free(del);
        temp = temp->next;
        if(temp)
            del = temp->next;
    }
}

void push(int new_data)
{
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data  = new_data;
    new_node->next = head;
    head = new_node;
}

void printList()
{
    printf("printing list: ");
    Node *temp = head;
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void deleteList()
{
    Node *temp = head;
    while(temp != NULL)
    {
        Node *next = temp->next;
        free(temp);
        temp = next;
    }
    head = NULL;
}

int main(){
    push(1);
    push(2);
    push(3);
    push(4);
    printList();
    deleteAlt();
    printList();
    deleteList();
}
