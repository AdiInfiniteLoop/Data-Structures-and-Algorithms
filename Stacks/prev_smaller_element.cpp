#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int main(){
    vector<int> arr;
    vector<int> ans(arr.size());
    stack<int> st;
    st.push(-1);
    arr.push_back(2);
    arr.push_back(1);
    arr.push_back(4);
    arr.push_back(3);
    for(int i = 0;i < arr.size();i++){
        int curr = arr[i];
        while(curr <= st.top())
        {
            st.pop();
        }
        ans.push_back(st.top());
        st.push(curr);
    }

    for(int itr : ans) cout<<itr<<" ";
}