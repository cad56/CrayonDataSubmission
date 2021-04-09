#include<bits/stdc++.h>
using namespace std;

typedef struct node{
	int d;
	struct node * nxt;
}node;
//create a queue
typedef struct queue{
	node * l;
	int size = 0;
}Queue;

// Checking whether Queue is empty or not
bool isEmpty(Queue * q){
	if(q->size)
		return false;
	else
		return true;
}

// Checking size of the Queue
int size(Queue * q){
	return q->size;
}

// Remove the element from the Queue
void pop(Queue * q){
	node * l = q->l;
	q->l = l->nxt;
	free(l);
	q->size -= 1;
}

//  find the top most priority element in Priority Queue
int prior__ele(Queue * q){
	if(!isEmpty(q))
		return q->l->d;
	else{
		cout<<"queue is empty\n";
		return -1;
	}
}

// To add numbers to the minimum Priority queue in order of priority.
void min_push(Queue * q, int d){

	node * l = q->l;

	node * ptr = (node *)malloc(sizeof(node));		
	ptr->d = d;
	ptr->nxt = NULL;

	node * h = l;	

	if(h == NULL)											
		l = ptr;									
	else if(h->d >= d){								
		ptr->nxt = h;										
		l = ptr;
	}	
	else{
		while(h->nxt != NULL and h->nxt->d < d)	  
			h = h->nxt;									
		ptr->nxt = h->nxt;
		h->nxt = ptr;
	}
	q->size += 1;
	q->l = l;									
}

// To add numbers to maximum priority Queue in order of their priority
void max_push(Queue * q, int d){

	node * l = q->l;

	node * ptr = (node *)malloc(sizeof(node));		
	ptr->d = d;
	ptr->nxt = NULL;

	node * h = l;											

	if(h == NULL)											
		l = ptr;									
	else if(h->d <= d){								
		ptr->nxt = h;										
		l = ptr;
	}	
	else{
		while(h->nxt != NULL and h->nxt->d > d)	 
			h = h->nxt;									
		ptr->nxt = h->nxt;
		h->nxt = ptr;
	}
	q->size += 1;
	q->l = l;								
}

int main()
{
	int m,i;

	//To store smaller half of the elements in Maximum Priority Queue
	Queue * max = (Queue *)malloc(sizeof(Queue));
	// To store greater half of the elements in Minimum Priority Queue
	Queue * min = (Queue *)malloc(sizeof(Queue));

	// To find the median , input of the elements is taken
	cout<<"Enter number of elements in Queue : ";
	cin>>m;
	int arr[m];
	cout<<"Enter elements in Queue seperated by space: ";
	for(i=0;i<m;i++)    cin>>arr[i];

	// Intialize and print the first element as median of one element is itself
	double median = arr[0];
    max_push(max,arr[0]);
    cout << median << " ";

	//  read the elements and seperate them one by one to the minimum and maximum priority Queues
    for (int i=1; i < m; i++){
        double y = arr[i];

		/*compare if both queues have equal no of elements then check the current element is less than 
		 previous median then push it to max prior queue, new median will be equal to element 
		which has highest priority.else current element is greater than the previous median then push it to 
		min priority queue */
        if (size(max)==size(min)){
            if (y < median){
                max_push(max,y);
                median = (double) prior__ele(max);
            }
            else{
                min_push(min,y);
                median = (double) prior__ele(min);
            }
        }

		// check if both are not equal we declare the median as average of priority elements of both priority queue
        else if (size(max) > size(min)){
            if (y < median){
                min_push(min,prior__ele(max));
                pop(max);
                max_push(max,y);
            }
            else    min_push(min,y);
            median = (prior__ele(max) + prior__ele(min))/2.0;
        }
        else{
            if (y > median){
                max_push(max,prior__ele(min));
                pop(min);
                min_push(min,y);
            }
            else    max_push(max,y);
            median = (prior__ele(max) + prior__ele(min))/2.0;
        }

		//print the median 
        cout << median << " ";
    }
	cout<<endl;
}
