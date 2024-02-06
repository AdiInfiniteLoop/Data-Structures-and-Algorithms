#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

int main() {
  std::vector<int> arr{1,4,3,2};
  std::vector<int> ans;
  stack<int> st;

  for(int i = arr.size() - 1; i>= 0; --i) {

    while(st.size() > 0 && st.top() <= arr[i]) {
      st.pop();
    }

    if(st.empty()) {
      ans.push_back(-1);
    }
    else {
      ans.push_back(st.top());
    }
    st.push(arr[i]);
  }
  std::reverse(ans.begin(), ans.end());
  for(const int &it: ans ) {
    cout<< it<<"\n";
  }
}
