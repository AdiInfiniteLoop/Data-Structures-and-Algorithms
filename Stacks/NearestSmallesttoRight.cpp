#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
  vector<int> arr{2, 1, 5, 6, 2, 3};
  vector<int> ans;
  stack<int> st;
  int n = arr.size();
  for(int i = n-1; i>= 0; --i) {

      while(st.size() > 0 && arr[st.top()] >= arr[i]) {
        st.pop();
      }
    if(st.empty()) ans.push_back(-1);

    else {
      ans.push_back(st.top());
    }

    st.push(i);
  }
  
  std::reverse(ans.begin(), ans.end());
  for(const int it: ans) {
    cout<<it<<" ";
  }


}
