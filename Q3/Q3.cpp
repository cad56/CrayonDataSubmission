#include <bits/stdc++.h>
using namespace std;
#define MAX 1000000
class Queue
{
  int rear,front;//To get the size of queue and also to avoid overflows we take 2 pointers 
  public:
    char a[MAX];
    Queue(){
      rear=0;
      front=0;//Initialize both of them to start of the array 
    }
    bool empty(){
      return(front==rear);//If bothe are at same point then it meanse no elemnt in between first and last and hence empty 
    }
    bool isFull(){
      return(rear>=MAX);//If you have excced the size then overflows this prevents it 
    }
    void push(char x){
      if(!isFull()){
        a[rear]=x;
        rear++;//Pushing the element from the back of array and incrementing pointer for next one
      }
      else{
        cout<<"Queue is full"<<endl;
      }
    }
    int start(){
        return a[front];//Returns the top of the queue
    }
    void pop(){
      if(!empty()){

          for (int i = 0; i < rear - 1; i++) { //Removes the first element of the queue and readjusts the queue 
                a[i] = a[i + 1];
            }

            rear--;
      }
      else{
        cout<<"Queue is empty"<<endl;
      }
    }
    void show(){
      for(int i=front; i< rear; i++) cout<<a[i]<<" ";
        cout<<'\n';
    }
};

int main(){
  

    Queue q;//Initiated queue 
    int CountofCharaters[26] = { 0 };
    //Count array of size 26 to keep track of no of characters of that type.
  
    int n;
    cin >> n;

    char s[n];

    for(int i = 0;i < n;i++)
    {
      cin >> s[i];
    }
    


//Else if frequency is more than 1, then we pop that element.
//If queue became empty that means there are no non repeating character so we will print -1.

    for (int i = 0; i < n; i++) {
  

        if(CountofCharaters[s[i] - 'a'] == 0)
            q.push(s[i]);//Storing the char in queue and incrementing its freq in count  array.
            
        CountofCharaters[s[i] - 'a']++;
  
        while (!q.empty()) {
            //For every s[i] check front of the queue this is because if it exceed one it will no longer be the
            //non repeating character thus pop it and do the same untill u get a character that is non repeated 
            //Then do if statement outside while loop 
            if (CountofCharaters[q.start() - 'a'] > 1)
                q.pop();
            else {
                //If freq of char @ front of queue is 1 this is nothing but the first non repeating character of it
                char c = q.start();
                cout << c << " ";
                break;
            }
        }
        
        //cout << i << '\n';
  
        if (q.empty())//As there is no non repeating vhar till now print - 
            cout << "-" << " ";
    }
    cout << endl;

}
