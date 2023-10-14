#include <iostream>
#include <vector>

bool isSafe(int board[9][9], int n, int val, int i, int j){
for(int k = 0; k < n;k++){
    //row
    if(board[i][k] == val || board[k][j] == val || board[3*(i/3)+ (k/3)][3*(j/3) + (k%3)] == val) return false;
}
return true;
}

bool solve(int board[9][9], int n){
    //No Base Caserequired here
    for(int i = 0; i < n; i++){
        for(int j = 0; j< n;j++){
            if(board[i][j] == 0)//0 represents empty cell
            {
                for(int val = 1; val <= 9 ;val++){
                    //check if isSafe
                    if(isSafe(board,n,val,i,j)){
                        board[i][j] = val;
                        //recursive call
                        if(solve(board,n) == true) return true;
                        //always backtracking after recursion
                        board[i][j] = 0;

                    }
                }
                return false;
            }
        }
    }
    return true;
    
}
int main()
{
int board[9][9]= {{4,5,0,0,0,0,0,0,0},//Bo

{0,0,2,0,7,8,6,3,0},
{0,0,0,0,0,0,0,2,8},
{0,0,0,9,5,0,0,0,0},
{0,8,6,0,0,0,2,0,0},
{0,2,8,6,0,0,7,5,0},
{0,0,0,0,0,0,4,7,6},
{0,7,0,0,4,5,0,0,0},
{0,0,8,0,0,9,0,0,0}};

int n = 9;
solve(board,n);

for(int i = 0; i < 9;i++){
    for(int j = 0; j<9;j++){
        std::cout<<board[i][j]<<" ";
    }
    std::cout<<std::endl;
}

}



