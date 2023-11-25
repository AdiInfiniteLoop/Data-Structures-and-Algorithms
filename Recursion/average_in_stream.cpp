#include<iostream>
#include<vector>
using namespace std;

vector<int> streamAvg(int arr[], int n,vector<int> &ans,int it,int mean) {
    if(it == n) return ans;
    mean+= arr[it];
    int av = mean;
    av /= (it+1);
    ans.push_back(av);
    streamAvg(arr,n,ans,it+1,mean);
    return ans;
    
}

int main(){
    int arr[6] = {10,20,30,40,50,60};
    int n = 6;
    std::vector<int> ans;
    int mean = arr[0];

    int it = 0;
    for(auto itr:streamAvg(arr,n,ans,1,mean)) cout<<itr<<" ";


}