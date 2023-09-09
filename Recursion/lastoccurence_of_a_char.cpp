#include<iostream>
#include<cstring>
int lastocc(std::string &str,char &ch,int n,int i,int ans){
    if(i >= str.size()) return ans;
    if(str[i] == ch)ans = i;
    return lastocc(str,ch,n,i+1,ans);

}
int main(){
    //This is using standard iterations
// std::string str = "aabdsffnndsslf";
// char ch = 'd';
// int n = str.size();
// for(int i = n-1;i>0;i--){
//     if(str[i] == ch){
//         std::cout<<i;
// break;
// }
// }
std::string str = "hjkfsasafghjhjvhjkcvhjkg";
char ch = 'g';
int n = str.size() - 1;

std::cout<<lastocc(str,ch,n,0,0);
}