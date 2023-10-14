#include<iostream>
#include<vector>
using namespace std;
void helper(vector<int> &candidates,int target,vector<vector<int>> &ans,vector<int> &v,int ind){
    //B.Case
    if(target == 0){
        ans.push_back(v);
        return;
    }
    if(target < 0) return;
    for(int i = ind; i< candidates.size();i++){
        v.push_back(candidates[i]);
        helper(candidates,target -candidates[i],ans,v,ind);
        v.pop_back();
    }
}
int main(){
    std::vector<int> candidates {1,2,4,5,64,6,7};
    int target = 13;
    vector<vector<int>> ans;
    vector<int> v; // Make v a non-constant object
    helper(candidates,target,ans,v,0);
    return ans;
}