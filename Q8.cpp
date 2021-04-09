#include<stdio.h>
#include<stdlib.h>
#include<bits/stdc++.h>
//Define N here as size the number of blocks of that are required


using namespace std;

#define size 10 
int c;

struct node
{
    int d;
    struct node *nxt;
};

struct node *chain[size];

void initial()
{
    int j;
    for(j = 0; j < size; j++)
        chain[j] = NULL;
}

void insert(int val)
{
    //creating a newnode with value
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->d = val;
    newNode->nxt = NULL;

    //calculating the block which it belongs to 
    int k = val % size;

    //check if chain[k] is empty
    if(chain[k] == NULL)
        chain[k] = newNode;//If there is no node in the block till now add this node 
    
    else
    {
        //If there us a already a list of nodes(may be 1) add the node at the end of that list of nodes.
        struct node *tmp = chain[k];
        while(tmp->nxt)
        {
            tmp = tmp->nxt;
        }

        tmp->nxt = newNode;
    }
}

struct node* merge(struct node* l, struct node* r)
{
    struct node h;
    struct node* p = &h;
    while(l && r)
    {
        if(l->d <= r->d) //collect left first when left and right are equal same as merge of merge sort
        {
            p->nxt = l;
            l = l->nxt;
        }
        else
        {
            p->nxt = r;
            r = r->nxt;
        }
        p = p->nxt;
    }
    p->nxt = (l == NULL ? r : l);
    return h.nxt; //return without the fake head;
}

struct node* sortList(struct node* h)
{
    if(h == NULL || h->nxt == NULL)
        return h;
    struct node *s1 = h, *s2 = h->nxt;
    while(s2 && s2->nxt) //split the list into two halves;
    {
        s1 = s1->nxt;
        s2 = s2->nxt->nxt;
    }
    s2 = s1->nxt;
    s1->nxt = NULL;
    return merge(sortList(h), sortList(s2)); //merge two parts by invoking recursive method;
}

void sorteachmemoryspace()
{
    int j;
    for(j = 0; j < size; j++)
    {
        struct node *tmp = chain[j];
        chain[j] = sortList(tmp);
    }
}


void getsortedarrayaftersems(int arr[])
{
    int j;
    int k = 0;
    for(j = 0; j < size; j++)
    {
        struct node *tmp = chain[j];
        //printf("chain[%d]-->",j);
        while(tmp)
        {
            //printf("%d",tmp->d);
            //printf("\n");
            arr[k] = tmp->d;
            //printf("%d",arr[k]);
            //printf("\n");
            k++;
            tmp = tmp->nxt;
        }
        //printf("NULL\n");
    }
}

void print()
{
    int j;
    for(j = 0; j < size; j++)
    {
        struct node *tmp = chain[j];
        printf("chain[%d]-->",j);
        while(tmp)
        {
            printf("%d -->",tmp->d);
            tmp = tmp->nxt;
        }
        printf("NULL\n");
    }
}

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition (int arr[], int low, int high)
{
    int pivot = arr[high]; 
    int j = (low - 1);
 
    for (int i = low; i <= high - 1; i++)
    {
        if (arr[i] < pivot)
        {
            j++; 
            swap(&arr[j], &arr[i]);
        }
    }
    swap(&arr[j + 1], &arr[high]);
    return (j + 1);
}
 
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
 



int main()
{
    //initial array of list to NULL
    initial();
    
    
    int c;
    cin >> c;
    
    int inputarr[c];
    
    for(int i = 0;i < c;i++)
    {
        cin >> inputarr[i];
        insert(inputarr[i]);
    }
    
    sorteachmemoryspace();

    print();
    
    getsortedarrayaftersems(inputarr);
    
    
    for(int j = 0;j < c;j++)
    {
      printf("%d ",inputarr[j]);
    }
    
    printf("\n");
    
    quickSort(inputarr, 0, c - 1);
    
    for(int j = 0;j < c;j++)
    {
      printf("%d ",inputarr[j]);
    }
    
    printf("\n");

    return 0;
}
