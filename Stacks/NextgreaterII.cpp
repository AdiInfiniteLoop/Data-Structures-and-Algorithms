#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;

int main() {
  vector<int> arr{1,2,1,4,7};
  stack<int> st;
  vector<int> ans;
  int n = arr.size();
  for(int i = 2 * n - 1; i >= 0; --i) {
    while(st.size() > 0 && st.top()<= arr[i%n]){
      st.pop();
    }

    if(i < n) {
      if(st.empty()) {
        ans.push_back(-1);
      }
      else {
        ans.push_back(st.top());
      }
      
    }
    st.push(arr[i%n]);
  }
  std::reverse(ans.begin(), ans.end());
  for(const int &it: ans) {
    cout<<it<<" ";
  }
}
