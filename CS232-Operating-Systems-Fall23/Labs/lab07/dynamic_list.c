#include<stdio.h>
#include<stdlib.h>
#include "node.h"
#include "dynamic_list.h"

void append(struct node **head, int val){
    struct node *n = malloc(sizeof(struct node));
    if(n == NULL){printf("Memory Allocation Failed\n"); return;}
    n->val = val; n->next = NULL;
    if(*head == NULL) *head = n;
    else{
        struct node *temp = *head;
        while(temp->next != NULL) temp = temp->next;
        temp->next = n;
    }
}

int pop_dynamic(struct node **head){
    if(*head == NULL) return -1;
    struct node *temp = *head;
    *head = (*head)->next; int val = temp->val; free(temp);
    return val;
}

int insert(struct node **head, int val, int index){
    if(index < 0){
        printf("Index cannot be negative\n"); return -1;
    }

    struct node *n = malloc(sizeof(struct node));
    if(n == NULL) return -1;
    n->val = val;

    if(index == 0){
        n->next = *head; *head = n; return 1;
    }

    struct node *curr = *head; int i = 0;
    while(curr != NULL && i < index - 1){
        curr = curr->next; i++;
    }
    if(curr == NULL){
        free(n); return -1;
    }
    n->next = curr->next; curr->next = n; return 1;
}

int delete(struct node **head, int index){
    if(index < 0){
        printf("Index cannot be negative\n"); return -1;
    }

    if(*head == NULL) return 0;

    if(index == 0){
        struct node *temp = *head;
        int val = temp->val;
        *head = (*head)->next; free(temp);
        printf("%d\n", val); return 1;
    }

    struct node *curr = *head; int i = 0;
    while(curr->next != NULL && i < index - 1){
        curr = curr->next; i++;
    }
    if(curr->next == NULL) return 0;
    struct node *temp = curr->next;
    int val = temp->val;
    curr->next = temp->next; free(temp); 
    printf("%d\n", val); return 1;
}

int get(struct node **head, int index){
    if(index < 0){
        printf("Index cannot be negative\n"); return -1;
    }

    struct node *curr = *head; int i = 0;
    while(curr != NULL && i < index){
        curr = curr->next; i++;
    }
    if(curr == NULL) return -1;
    int val = curr->val;
    printf("%d\n", val); return 1;
}

int length(struct node **head){
    struct node *curr = *head; int i = 0;
    while(curr != NULL){
        curr = curr->next; i++;
    }
    printf("%d\n", i); return i;
}

void print_dll(struct node *head){
    if(head == NULL) printf("Nothing to print, Stack is empty");
    else{
        while(head != NULL){
            printf("%d", head->val);
            if(head->next != NULL) printf("->");
            head = head->next;
        }
        printf("\n");
    }
}