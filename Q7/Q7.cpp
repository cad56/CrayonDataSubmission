#include<stdio.h>
#include<stdlib.h>
#include<bits/stdc++.h>

using namespace std;

#define size 10 //Define N here it is the no of blocks of space u need

int expo;

int cnt;

struct node
{
    int data;
    struct node *next;
};

struct node *chain[size];

void init()
{
    int i;
    for(i = 0; i < size; i++)
        chain[i] = NULL;
}

void insert(int value)
{
    //create a newnode with value
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;

    //calculate hash key
    //int key = value % size;
    int key = (value / expo) % 10;

    //check if chain[key] is empty
    if(chain[key] == NULL)
        chain[key] = newNode;
    //collision
    else
    {
        //add the node at the end of chain[key].
        struct node *temp = chain[key];
        while(temp->next)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }
}

struct node* merge(struct node* l, struct node* r)
{
    struct node head;
    struct node* p = &head;
    while(l && r)
    {
        if(l->data <= r->data) //collect left first when left and right are equal;
        {
            p->next = l;
            l = l->next;
        }
        else
        {
            p->next = r;
            r = r->next;
        }
        p = p->next;
    }
    p->next = (l == NULL ? r : l);
    return head.next; //return without the fake head;
}

struct node* sortList(struct node* head)
{
    if(head == NULL || head->next == NULL)
        return head;
    struct node *s1 = head, *s2 = head->next;
    while(s2 && s2->next) //split the list into two halves;
    {
        s1 = s1->next;
        s2 = s2->next->next;
    }
    s2 = s1->next;
    s1->next = NULL;
    return merge(sortList(head), sortList(s2)); //merge two parts by invoking recursive method;
}

void sorteachmemoryspace()
{
    int i;

    for(i = 0; i < size; i++)
    {
        struct node *temp = chain[i];
        chain[i] = sortList(temp);
    }
}


void getsortedarrayaftersems(int arr[])
{
    int i;
    int k = 0;
    for(i = 0; i < size; i++)
    {
        struct node *temp = chain[i];
        //printf("chain[%d]-->",i);
        while(temp)
        {
            //printf("%d",temp->data);
            //printf("\n");
            arr[k] = temp->data;
            //printf("%d",arr[k]);
            //printf("\n");
            k++;
            temp = temp->next;
        }
        //printf("NULL\n");
    }
}

void print()
{
    int i;
    for(i = 0; i < size; i++)
    {
        struct node *temp = chain[i];
        printf("chain[%d]-->",i);
        while(temp)
        {
            printf("%d -->",temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}


bool issorted(int arr[],int n)
{
    
    for(int i = 0;i < n-1;i++)
    {
        if(arr[i] > arr[i+1])
            return false;
    }
    
    return true;
    
}
 
// A utility function to get maximum value in arr[]
int getMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}



int main()
{
    //init array of list to NULL
    
    
    int cnt;
    cin >> cnt;
    
    int inputarr[cnt];
    
    for(int i = 0;i < cnt;i++)
    {
        cin >> inputarr[i];
    }
    
    int m = getMax(inputarr, cnt);
    
    for (expo = 1; m / expo > 0; expo *= 10)
    {
        init();
        for(int i = 0;i < cnt;i++)
        {
            insert(inputarr[i]);
        }
        sorteachmemoryspace();
        print();
        getsortedarrayaftersems(inputarr);
        for(int i = 0;i < cnt;i++)
        {
          printf("%d ",inputarr[i]);
        }
        printf("\n");
        if(issorted(inputarr,cnt))
            break;
    }

    return 0;
}
