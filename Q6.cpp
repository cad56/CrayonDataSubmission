//finding the median of
//a sorted linkedlist
#include <bits/stdc++.h>
using namespace std;

// create a linkedlist node
struct Node {
  int d;
  struct Node* nxt;
};

/* Function to find the median of the linked list */
void printMidean(Node* head)
{
  Node* s = head;
  Node* f = head;
  Node* p = head;

  if (head != NULL) {
    while (f != NULL && f->nxt != NULL) {

      f = f->nxt->nxt;
      p = s;
      s = s->nxt;
    }

    // if the linked list
    // contain odd Node
    // simply return middle element
    if (f != NULL)
      cout << "Median is : " << s->d;

    // else linked list contain even element
    else
      cout << "Median is : "
        << float(s->d + p->d) / 2;
  }
}

/*  Reference (pointer to
  pointer) to the head of a list
  and an integer, push a new node on
  the front of the list. */
void push(struct Node** h_ref, int new_d)
{
  // allocate node
  Node* new_node = new Node;

  new_node->d = new_d;

  // link the old list
  // off the new node
  new_node->nxt = (*h_ref);

  // move the head to point
  // to the new node
  (*h_ref) = new_node;
}


int main()
{
  // Starting with the
  // empty list
  struct Node* head = NULL;

  // To construct the 
  //list Used push() 
  // 1->2->3->4->5->6
  push(&head, 6);
  push(&head, 5);
  push(&head, 4);
  push(&head, 3);
  push(&head, 2);
  push(&head, 1);

  
  printMidean(head);

  return 0;
}
