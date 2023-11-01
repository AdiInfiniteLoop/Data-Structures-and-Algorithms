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
int main(){
    std::queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    q.push(70);
    q.push(80);
    q.push(90);
    q.push(100);
    q.push(110);
    
    int N = q.size();
    //Auxilliary queue
    std::queue<int> q1;
    std::queue<int> q2;
    int i = 0;
    while(i < N/2){
        int t = q.front();
        q.pop();
        q1.push(t);
        i++;
    }
    i = N/2;
    while(i<N){
        int t = q.front();
        q.pop();
        q2.push(t);
        i++;
    }
    std::queue<int> q3;
    while(!q1.empty() && !q2.empty()){
        int t1 = q1.front();
        q1.pop();
        q3.push(t1);
        int t2 = q2.front();
        q2.pop();
        q3.push(t2);
    }
    while(!q1.empty()){
        q3.push(q1.front());
        q1.pop();
    }
    while(!q2.empty()){
        q3.push(q2.front());
        q2.pop();
    }
    Print(q3);
}