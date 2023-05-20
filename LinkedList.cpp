#include<bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  Node* next;
};

void printo(Node *head)
{
  Node *n = head;
  while (n != NULL)
  {
    cout << n->data << " ";
    n = n->next;
  }

  cout << endl;
}

void insert_at_end(Node *head, int x)
{
  Node *naya = new Node();
  naya->data = x;
  naya->next = NULL;

  Node *n = head;
  while (n->next != NULL)
    n = n->next;
  n->next = naya;
}
Node* insert_at_begin(Node *head, int x)
{
  Node *naya = new Node();
  naya->data = x;
  naya->next = head;
  return naya;
}
Node* insert_at_pos(Node *head, int p, int x)
{
  Node *naya = new Node();
  naya->data = x;
  if (p == 1)
  {
    naya->next = head;
    return naya;
  }
  Node *n = head;
  for (int i = 1; i < p - 1; i++)
  {
    n = n->next;
  }
  naya->next = n->next;
  n->next = naya;

  return head;
}

Node* delete_at_pos(Node *head, int p)
{
  if (p == 1)
    return head->next;
  Node *n = head;
  for (int i = 1; i < p - 1; i++)
    n = n->next;
  n->next = n->next->next;
  return head;
}
Node *reverso(Node *head)
{
  Node *prev = NULL;
  Node *cur_pos = head;
  while (cur_pos != NULL)
  {
    Node *temp = cur_pos->next;
    cur_pos->next = prev;
    prev = cur_pos;
    cur_pos = temp;
  }
  return prev;
}
int main()
{
  Node *first = new Node();
  first->data = 1;

  Node *second = new Node();
  second->data = 7;

  Node *third = new Node();
  third->data = 3;

  Node *forth = new Node();
  forth->data = 9;

  first->next = second;
  second->next = third;
  third->next = forth;
  forth->next = NULL;

  Node *head = first;
  printo(head);

  // insert at end
  insert_at_end(head, 8);
  printo(head);

  // insert at begin
  head = insert_at_begin(head, 11);
  printo(head);

  // insert at any pos
  head = insert_at_pos(head, 1, 19);
  printo(head);

  // deletion at any position
  head = delete_at_pos(head, 5);
  printo(head);

  // reverse a linked list
  head = reverso(head);
  printo(head);
}