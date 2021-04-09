#include <bits/stdc++.h>
using namespace std;

struct node {
	int d;
	node* nxt;
};


node* insertval(node* hoflist, int numb)//We got the head of the list and number to be inserted 
{
    //Basic idea is if LL exists already we append the presend node at the last node
    //if LL doesn't exist we create one head pointing to first node 
    
	node* t = new node;//Craeting a temp node t
	
	node* toflist = hoflist;//Creating a node tail of list same as head of list

	
	t->d = numb;//Now t contains the value to be inserted and the next pointer which is obviously null 
	t->nxt = NULL;

	
	if (hoflist == NULL) {//If the given list was empty we will assign the node to it 
		hoflist = t;
		toflist = t;
	}

	else {

		while (toflist != NULL) {//If it is noth empty then  untill we find a last node we iterate and once 
		//we find the last node we just add our current to that last node

			if (toflist->nxt == NULL) {
				toflist->nxt = t;
				toflist = toflist->nxt;
			}
			toflist = toflist->nxt;
		}
	}

	return hoflist;//Returning the modified list 
}


void printdata(node* hoflist)
{
	node* temp;
	temp = hoflist;

	while (temp != NULL) {

		cout << temp->d;
		if(temp->nxt != NULL)
			cout << " -> ";
		temp = temp->nxt;
	}
}



node* listmerge(node** h1,node** h2)
{
    //so here we are basically taking both the lists and appending them one after the other 
	node* toflist = *h1;//Firstly we point to first list 
	while (toflist != NULL) {

		if (toflist->nxt == NULL
			&& h2 != NULL) {  //When we reach the end of it and we have anyother list remaining which is not null
			toflist->nxt = *h2;//Just start pointing to head of that list and do the same
			break;
		}
		toflist = toflist->nxt;
	}

	
	return *h1;  //at last return the lead of the list where the modified list is stored it is h1
}


void listsort(node** h1)
{
	node* curr = *h1;
	node* t= *h1;

	//Basic idea of selection sort we are using here we implemend the idea of mergge sort well as well in
	//the last question please check that as well 
	while (curr->nxt != NULL) {

		t = curr->nxt;
		while (t != NULL) {//Basically swapping 2 nodes curr and the other node next to it if 
            //they violate the sorting condition basicall is i < j then a[i] <= a[j] is its a[i] > a[j] we are swapping 
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
	node* h1 = new node;//Declaring the lists 
	node* h2 = new node;

	h1 = NULL;
	h2 = NULL;


    //Inserting the corresponding values into the lists 
	h1 = insertval(h1, 4);
	h1 = insertval(h1, 2);
	h1 = insertval(h1, 7);
	h2 = insertval(h2, 5);
	h2 = insertval(h2, 1);

	h1 = listmerge(&h1,&h2);//Merging both the lists 

	listsort(&h1);//Sorting the merged list 

	printdata(h1);//Finally print ing the list 
	return 0;
}
