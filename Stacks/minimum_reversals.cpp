#include<iostream>
#include<stack>
using namespace std;


int countRev (string s)
{ 

 stack<char> st;
 if(s.length() & 1) return -1;
 for(auto itr: s){
     if(itr == '{') st.push(itr);
     else{
         if(!st.empty() && st.top() == '{') st.pop();
             else 
                st.push(itr);
         }
     }
 
 int count = 0;
 while(!st.empty()){
     char a = st.top();
     st.pop();
     char b = st.top();
     st.pop();
     if(a == b) count+=1;
     else count +=2;
 }
 return count;
}

int main(){

string s = "{}{{{{}}}}}{";
int ans  = countRev(s);
cout<<ans<<" is the answer";
}