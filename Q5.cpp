#include <bits/stdc++.h>
using namespace std;

//  creating structure for node
struct node {
	int d;
	node* nxt;
};


// The data and the head of linked list
//is taken as an arguement by the
//function and if linkedlist  exists,
//  already, it appends given node at 
//end of the last node if linkedlist 
//doesn't exists, it creates one with the
// head pointing to first node.
node* dataget(node* head, int num)
{

	node* t = new node;
	node* tail = head;

	// data is inserted into the temporary
	// node and point it's next to NULL
	t->d = num;
	t->nxt = NULL;

	// If head is null, create a
	// linked list with t as head
	// and tail of the list
	if (head == NULL) {
		head = t;
		tail = t;
	}

	// Else inserting the temporary node
	// after the tail of the existing
	// node and make the temporary node
	// as the tail of the linked list
	else {

		while (tail != NULL) {

			if (tail->nxt == NULL) {
				tail->nxt = t;
				tail = tail->nxt;
			}
			tail = tail->nxt;
		}
	}

	return head;
}

// Function is to print the linkedlist
void dataset(node* head)
{
	node* temp;
	temp = head;

	while (temp != NULL) {

		cout << temp->d
			<< " -> ";
		temp = temp->nxt;
	}
}


// Function is to concatenate the two lists
node* listmerge(node** h1,
				node** h2)
{

	node* tail = *h1;
	while (tail != NULL) {

		if (tail->nxt == NULL
			&& h2 != NULL) {
			tail->nxt = *h2;
			break;
		}
		tail = tail->nxt;
	}

	// return the concatenated lists as a
	// single list - h1
	return *h1;
}

// Sorting the linkedlist using bubble sort
void listsort(node** h1)
{
	node* curr = *h1;
	node* t= *h1;

	
	while (curr->nxt != NULL) {

		t = curr->nxt;
		while (t != NULL) {

			if (t->d< curr->d) {
				int temp = t->d;
				t->d = curr->d;
				curr->d = temp;
			}
			t = t->nxt;
		}
		curr = curr->nxt;
	}
}


int main()
{
	node* h1 = new node;
	node* h2 = new node;

	h1 = NULL;
	h2 = NULL;

	// Taken Linked List 1
	h1 = dataget(h1, 5);
	h1 = dataget(h1, 8);
	h1 = dataget(h1, 6);

	// Taken Linked List 2
	h2 = dataget(h2, 3);
	h2 = dataget(h2, 2);
	h2 = dataget(h2, 9);
	h2 = dataget(h2, 2);

	// Merge the two lists
	// in a single list
	h1 = listmerge(&h1,
					&h2);

	// Sort the unsorted merged list
	listsort(&h1);

	// sorted merged list
	dataset(h1);
	return 0;
}
