#include<iostream>
#include<vector>
#include<limits.h>
#include<algorithm>

int buyandsell(std::vector<int> v,int n, int mini,int maxi, int i,int prof){
    if(i >= n) return prof;
        mini = std::min(v[i],mini);//Buying the stock
        prof = v[i] - mini;//Selling the stock
        prof = std::max(prof,maxi);//Checking if it is profitabl
        return buyandsell(v,n,mini,maxi,i+1,prof);
    
}
int main(){
    std::vector<int> v{7,5,45,4,3,6,67,3463,0,56445,346};//Edge case when the last element is smaller than second last element
    int n = v.size();
    int mini = INT_MAX;
    int maxi = INT_MIN;
std::cout<<buyandsell(v,n,mini,maxi,0,0);

}