#include <stdio.h>
using namespace std;
typedef struct Node
{
    int value;
    struct Node *next;
} Node;
void pop(Node **head)
{
    if (head != NULL)
    {
        Node *prev = NULL;
        prev = *head;
        (*head) = (*head)->next;
        delete (prev);
    }
}
Node *getNth(Node *head, int n)
{
    int i = 0;
    while (i < n && head)
    {
        head = head->next;
        i++;
    }
    return head;
}
Node *getLast(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    while (head->next)
    {
        head = head->next;
    }
    return head;
}
void push(Node **head, int data)
{
    Node *tmp = new Node;
    tmp->value = data;
    tmp->next = (*head);
    (*head) = tmp;
}
void pushBack(Node *head, int value)
{
    Node *last = getLast(head);
    Node *temp = new Node;
    temp->value = value;
    temp->next = NULL;
    last->next = temp;
}

void deleteNth(Node **head, int n)
{
    if (n == 0)
    {
        pop(head);
    }
    else
    {
        Node *prev = getNth(*head, n - 1);
        Node *elm = prev->next;
        prev->next = elm->next;
        delete (elm);
    }
}
Node *searchNth(Node *head, int n)
{
    if (n == 0)
    {
        return NULL;
    }
    else
    {
        int i = 0;
        while (head != NULL)
        {
            if (head->value == n)
                return head;
            head = head->next;
        }
    }
    return NULL;
}
void deleteList(Node **head)
{
    while ((*head)->next)
    {
        pop(head);
        *head = (*head)->next;
    }
    delete (*head);
}
void printLinkedList(const Node *head)
{
    while (head)
    {
        printf("%d ", head->value);
        head = head->next;
    }
    printf("\n");
}
int main()
{
    Node *head = NULL;
}
