#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
  std::vector<int> arr {100,80,70,60,75,85};
  stack<pair<int, int>> st;
  std::vector<int> ans;
  
  for(int i = 0; i < arr.size(); ++i ) {

    while(st.size() > 1 && st.top() < arr[i]) {
      st.pop();
    }
    
    if(st.empty()) {
      ans.push_back(1);
    }
    else {
      ans.push_back(i - st.top().second);
    }
    st.push({arr[i],i});
    
  }
  for(int i = 0; i < ans.size(); ++i) {
    cout<<ans[i]<<" ";
  }


}
