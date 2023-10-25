#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int main(){
    vector<int> ans;
    int arr[7] = {2,1,4,3};
    stack<int> st;
    st.push(-1);
    for(int i = 3; i>= 0;--i){
        // int curr = arr[i];

        while(st.top() >= arr[i]){
            st.pop();
        }
    ans.push_back(st.top());
    st.push(arr[i]);

    }
//    for(int itr: ans) cout<<itr<<" "; the answer is in reverse order
for(int i = 3;i>=0;--i) cout<<ans[i]<<" ";

}