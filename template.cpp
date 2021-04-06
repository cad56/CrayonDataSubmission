#include <bits/stdc++.h>
using namespace std;
#define MAX 1000000
class Queue
{
  int rear,front;
  public:
    char a[MAX];
    Queue(){
      rear=0;
      front=0;
    }
    bool empty(){
      return(front==rear);
    }
    bool isFull(){
      return(rear>=MAX);
    }
    void push(char x){
      if(!isFull()){
        a[rear]=x;
        rear++;
      }
      else{
        cout<<"Queue is full"<<endl;
      }
    }
    int start(){
        return a[front];
    }
    void pop(){
      if(!empty()){

          for (int i = 0; i < rear - 1; i++) {
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
  

    //queue<char> q;
    Queue q;
    int CountofCharaters[26] = { 0 };
  
    int n;
    cin >> n;

    char s[n];

    for(int i = 0;i < n;i++)
    {
      cin >> s[i];
    }

    for (int i = 0; i < n; i++) {
  

        q.push(s[i]);
        CountofCharaters[s[i] - 'a']++;
  
        while (!q.empty()) {
            if (CountofCharaters[q.start() - 'a'] > 1)
                q.pop();
            else {
                char c = q.start();
                cout << c << " ";
                break;
            }
        }
  
        if (q.empty())
            cout << "-" << " ";
    }
    cout << endl;

}