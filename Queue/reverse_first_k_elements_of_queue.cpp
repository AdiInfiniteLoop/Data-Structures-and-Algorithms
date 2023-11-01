#include<iostream>
#include<queue>

using std::cout;
using std::endl;

static void Print(std::queue<int> q){

    while(!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
}
void reverse_k(std::queue<int> &q, int k){

    //Base Case
    if(k <= 0){
        return;
    }
    int t = q.front();
    q.pop();
    --k;
    reverse_k(q,k);
    q.push(t);
}
int main(){
    std::queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    cout<<"Before reversing: ";
    Print(q);
    int k = 3;
    reverse_k(q,k);
    int i = 0;
    int N = q.size();
    while(i < N - k){
        int t = q.front();
        q.pop();
        q.push(t);
        i++;
    }
    cout<<"After reversing\n";
    Print(q);
    //other way is using stacks
}