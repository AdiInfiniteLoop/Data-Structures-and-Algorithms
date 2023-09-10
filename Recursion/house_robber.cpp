#include<iostream>
#include<vector>
#include<algorithm>

int rob (std::vector<int> & nums,int i){
if(i >= nums.size()) return 0;

int incl = nums[i] + rob(nums,i+2); //Including house 1
int excl = 0+ rob(nums,i+1);    //Excluding house 1
return std::max(incl,excl);

}

int main(){
std::vector<int> nums{2,7,9,3,1};
int n = nums.size();
std::cout<<rob(nums,0);

}