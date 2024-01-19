#include<iostream>
#include<queue>

using namespace std;
int main(){

vector<int> arr {6,7,3,11,1,5};
//sorted:1,3,5,6,7,11 and kth:6

// std::priority_queue<int,deque<int>, std::greater<int> > minq(arr.begin(),arr.end());
// int k = 4;
// for(int i = 1;i <= k -1;++i)minq.pop();
// cout<<minq.top();    O(N) & O(1)
// int k = 4;
// std::priority_queue<int, deque<int> , greater<int> > maxq(arr.begin(),arr.begin() + k);
/*
Goal/Logic: We want to create a heap data structure that contains
 the first k smallest elements and the largest among them is the kth smallest
*/

int k = 2;
std::priority_queue<int, deque<int> > maxq(arr.begin(),arr.begin() + k);

for(int i = k; i < 6;++i){
    if(arr[i] < maxq.top()){
        maxq.pop();
        maxq.push(arr[i]);
    }
}
cout<<"The kth smallest element is "<<maxq.top();
/* O(k) && O(1)*/
}