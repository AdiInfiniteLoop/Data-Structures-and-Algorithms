#include<bits/stdc++.h>
using namespace std;


int cnt = 0;
void func(int i, int n) {

if(i >= n) {
    cout<<"Returning\n";
    return;
}

cout<<"Before call "<<i<<endl;
func(i+1,n);
cout<<"After call " << i<<endl;
} 
int main() {
cout<<"CALL\n";
func(0, 5);
return 0;
}