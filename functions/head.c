#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node* next;
};

void append(struct Node** head_ref, int new_data) {
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
  struct Node* last = *head_ref;
  new_node->data = new_data;
  new_node->next = NULL;

  if (*head_ref == NULL) {
    *head_ref = new_node;
    return;
  }

  while (last->next != NULL) last = last->next;

  last->next = new_node;
  return;
}

void printList(struct Node* node) {
  while (node != NULL) {
    printf(" %d ", node->data);
    node = node->next;
  }
}

void test(struct Node** p) { append(p, 6); }

int main() {
  struct Node* head = NULL;

  test(&head);
  // append(&head, 6);
  printList(head);
  return 0;
}