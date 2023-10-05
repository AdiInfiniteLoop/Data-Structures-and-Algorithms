#include<iostream>
#include<vector>

void printSolution(std::vector<std::vector<char>> &board,int col,int n){
    for(int i = 0; i < n;i++){
        for(int j = 0;j<n;j++){
            std::cout<<board[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl;
}


//--------------------------------------------------------------------
bool isSafe(std::vector<std::vector<char>> &board,int col,int row, int n){
//To check is the current cell is viable
//We check only 3 directions left-up diagonal,left-down diagonal&left
int i = row;
int j = col;
//Keep decreasing the j value until j reaches the first column i,e,col=0
while(j >= 0){
    //if queen is already there, not safe
    if(board[i][j] == 'Q') return false;
    j--;
}

//Left-up diagonal
//if queen is already there, not safe
i = row;
j= col;
while(j >= 0 && i >= 0){
if(board[i][j] == 'Q') return false;
    i--;
    j--;
}
//Left- Down diagonal
//if queen is already there, not safe
i = row;
j= col;
while(i < n && j >= 0){
if(board[i][j] == 'Q') return false;
    i++;
    j--;
}
return true;
}


//--------------------------------------------------------------------
void nqueen(std::vector<std::vector<char>> &board,int col, int n){
    //Base case
    if(col >= n){
        printSolution(board,col,n);
        return;
    }
    for(int row = 0;row < n; row++){
        if(isSafe(board,col,row,n)){
            board[row][col] = 'Q';
            nqueen(board,col+1,n);//Checking next column
            board[row][col] = '-';//backtracking happened such that common block can be included in every solution
        }
    }
}
int main(){
int n = 4;
std::vector<std::vector<char>> board(n, std::vector<char>(n,'-'));//n x n matrix created
nqueen(board,0,n);

}