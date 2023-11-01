#include<iostream>
#include<deque>
#include<vector>
using std::cout;
using std::endl;

void sliding_window(std::deque<int> &dq,int *arr,int k){
    int N = 8;
    //trverse the window
    for(int i = 0; i < k;i++){
        if(arr[i] < 0) dq.push_back(i);
    }
    //remaining elements
    for(int i = k;i <= N;i++){
        if(dq.empty()) {
            cout<<0<<" ";
        }
        //the first element in dq is the index
        else{
            cout<<arr[dq.front()]<<" ";
        }
        //remove out of window elements 
        while(i - dq.front() >= k && !dq.empty()){
            dq.pop_front();
        }
        if(arr[i] < 0) dq.push_back(i);
    }
    
}
int main(){
    int arr[] = {2,-5,-7,3,-9,7,0,4};
    int N = 8;
    int k = 3;  //window size
    std::deque<int> dq;
     sliding_window(dq,arr,k);
}