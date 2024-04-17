#include<bits/stdc++.h>
using namespace std;


void helper(int ind,vector<int>& ans, vector<int>  &ds) 
{
    if(ind >= ds.size())  {
        for(int it: ans) cout << it << " ";
        cout << endl;
        return;
    }

    //Pick
    ans.push_back(ds[ind]);
    helper(ind + 1, ans, ds);
    ans.pop_back();
    //Not pick
    helper(ind + 1, ans, ds);
    return;
}
int main() {
vector<int> ds  = {3,1,2};
vector<int> ans;
helper(0,ans, ds);


return 0;
}