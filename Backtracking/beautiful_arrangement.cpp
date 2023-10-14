#include<iostream>
#include<vector>

using namespace std;

void beautifularr(vector<int> &v,int &n,int &ans,int ind){
        //B.Case
        if(ind >= n +1){
            ans++;
            return;
        }
        for(int i = 1;i<=n;i++){
            if(v[i] == 0 && (ind % i == 0 || i % ind == 0)){
                v[i] = ind;
                beautifularr(v,n,ans,ind+1);
                v[i] = 0;//Backtracking
            }
        }
    }
int main(){
    int n = 4;
        vector<int> v(n+1);
        int ans = 0;
        beautifularr(v,n,ans,1);
        cout<< ans<<" ";
}