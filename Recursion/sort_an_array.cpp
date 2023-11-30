#include<iostream>
#include<vector>
using namespace std;

void insert(vector<int> &v,int temp){
    //base case
    if(v.size() == 0 || v[v.size() - 1] <= temp){
        v.push_back(temp);
        return;
    }
    //hypothesis : put the temp variable at its corerct position
    //induction : compare the temp variable with last element if not greater than keep deleting the last element and when you get an
    //element smaller than temp push temp in it
    int last_ele = v[v.size() - 1];
    v.pop_back();
    insert(v,temp);
    v.push_back(last_ele);
}

void sort(vector<int> &v,int n){
    if(n == 0){
        return;
    }
    //hypothesis: give sorted array
    //induction pop_back and insert at correct position
    int temp = v[v.size() - 1];
    v.pop_back();
    sort(v,n-1);
    insert(v,temp);

}
signed main(){
    vector<int> v{8,67,5,4,4,3};
    sort(v,v.size());

    for(int it: v) cout<<it<<" ";
}