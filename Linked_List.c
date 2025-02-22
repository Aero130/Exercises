//
// Created by 123 on 2025/2/9.
//

#include <io_utils.h>
#include <stdlib.h>

typedef struct ListNode{
  int value;
  struct ListNode* next;
}ListNode;

void *CreateNode(int value){
  ListNode *node = malloc(sizeof (ListNode));
  if(!node){
    exit(1);
  }
  node->value = value;
  node->next = NULL;

  return node;
}

void DestroyNode(ListNode **node_ptr){
  (*node_ptr)->next = NULL;
  free(*node_ptr);
  *node_ptr = NULL;
}

void *CreateList(int array[], int length){
  if(length <= 0) return NULL;

  ListNode *head = CreateNode(array[0]);
  ListNode *current = head;

  for(int i=1; i<length; i++){
    current->next = CreateNode(array[i]);
    current = current->next;
  }

  return head;
}

void InsertNode(ListNode **head, int value, int index) {
  if (!head || index < 0) return;
  ListNode *new_node = CreateNode(value);
  if (index == 0) {
    new_node->next = *head;
    *head = new_node;
  } else {
    if (!(*head)) {
      *head = CreateNode(0);
    }
    ListNode *current = *head;
    while (index > 1) {
      if (!current->next) {
        current->next = CreateNode(0);
      }
      current = current->next;
      index--;
    }
    new_node->next = current->next;
    current->next = new_node;
  }
}

ListNode *FindNode(ListNode *head, int value) {
  while (head && head->value != value) {
    head = head->next;
  }
  return head;
}

void DeleteNode(ListNode **head, int value) {
  printf("Delete: %d\n", value);
  if (!head || !(*head)) return;
  if ((*head)->value == value) {
    ListNode *new_head = (*head)->next;
    DestroyNode(head);
    *head = new_head;
    return;
  }
  ListNode *current_node = *head;
  while (current_node->next && current_node->next->value != value) {
    current_node = current_node->next;
  }
  if (current_node->next) {
    ListNode *node_to_delete = current_node->next;
    current_node->next = current_node->next->next;
    DestroyNode(&node_to_delete);
  }
}

void PrintList(ListNode *head){
  while (head){
    printf("%d\t", head->value);
    head = head->next;
  }
  printf("\n");
}

void DestroyList(ListNode **head){
  if(!head || !(*head)) return;
  ListNode *current = *head;
  while (current){
    ListNode *to_be_destroy = current;
    current = current->next;
    DestroyNode(&to_be_destroy);
  }
  *head =NULL;
}

int main(){
  ListNode *node = CreateNode(0);
  DestroyNode(&node);

  int array[] = {1,2,3,4,5,6,7,8,9,'\0'};
  ListNode *head = CreateList(array, 10);
  PrintList(head);
  InsertNode(&head, 100, 3);
  InsertNode(&head, 200, 0);
  InsertNode(&head, 300, 9);
  InsertNode(&head, 400, 10);
  PrintList(head);
  PRINT_HEX(head);

  InsertNode(&head, 10, 0);
  PrintList(head);
  DestroyList(&head);
  InsertNode(&head, 10, 10);
  PrintList(head);
  DestroyList(&head);
  return 0;
}

