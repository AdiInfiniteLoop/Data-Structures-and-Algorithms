#include<iostream>
#include<stack>
#include<algorithm>
#include<climits>
#include<vector>

using namespace std;
class Solution {
public:
    vector<int> NSR(vector<int> &arr) {
    vector<int> ans;
    stack<int> st;
    int n = arr.size();
    for(int i = n-1; i >= 0; --i) {

        while(st.size() > 0 && arr[st.top()] >= arr[i]) {
            st.pop();
        }

        if(st.empty()) ans.push_back(n);

        else {
        ans.push_back(st.top());
        }

        st.push(i);
        }
        return ans;
    }

    vector<int> NSL(vector<int> &arr) {
    vector<int> ans;
    stack<int> st;
    int n = arr.size();
    for(int i = 0; i < n; ++i) {

        while(st.size() > 0 && arr[st.top()] >= arr[i]) {
            st.pop();
        }
        if(st.empty()) ans.push_back(-1);

        else {
        ans.push_back(st.top());
       }

        st.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int> left = NSL(heights);
        vector<int> right = NSR(heights);
        std::reverse(right.begin(), right.end());//reverse tera baap karega 
        int n = heights.size();
        vector<int> width(n);

        for(int i = 0; i < n; ++i) {
            width[i] = right[i] - left[i] - 1;
        }

        int maxi = INT_MIN;
        for(int i = 0; i < n; ++i) {
            int area = (heights[i])*(width[i]);
            maxi = max(maxi, area);
        }
        return maxi;
    }
};
int main() {
vector<int> arr{2,1,3,5,6,2,3};
Solution* s = new Solution();
int ans = s->largestRectangleArea(arr);
cout<<ans<<" ";
}
