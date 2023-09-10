#include<iostream>
#include<cstring>

int main(){
    int num;
    std::cin>>num;
    std::string roman[] ={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        int values[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};

        std::string ans = "";
        for(int i = 0; i < 13;i++){//have to take 13 here not values.size() coz not a structure or union
            while(num>=values[i]){
                ans += roman[i];
                num -= values[i];
            }
        }  
        std::cout<< ans;

}