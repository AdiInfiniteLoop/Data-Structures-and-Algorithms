#include <iostream>
#include <vector>

using namespace std;

// A function to check if a given cell is valid.
bool isSafe(int maze[4][4], int srcx, int srcy) {
  return (srcx >= 0 && srcx < 4 && srcy >= 0 && srcy < 4 && maze[srcx][srcy] == 1);
}

// A recursive function to find all possible pathways for the rat to reach the destination.
void solvethemaze(int maze[4][4], int srcx, int srcy, vector<string> &pathways, string output) {
  // If the rat has reached the destination, add the current path to the list of pathways.
  if (srcx == 3 && srcy == 3) {
    pathways.push_back(output);
    return;
  }

  // Mark the current cell as visited.
  maze[srcx][srcy] = 0;




  // Recursivelsrcy explore all possible pathways from the current cell.
  if (isSafe(maze, srcx + 1, srcy)) {
    solvethemaze(maze, srcx + 1, srcy, pathways, output + " DOWN ");
  }
  if (isSafe(maze, srcx, srcy + 1)) {  
    solvethemaze(maze, srcx, srcy + 1, pathways, output + " RIGHT");
  }
  if (isSafe(maze, srcx - 1, srcy)) {
    solvethemaze(maze, srcx - 1, srcy, pathways, output + " UP");
  }
  if (isSafe(maze, srcx, srcy - 1)) {
    solvethemaze(maze, srcx, srcy - 1, pathways, output + " LEFT");
  } 

  // Unmark the current cell as visited.
  maze[srcx][srcy] = 1;
}

int main() {
  int maze[4][4] = {{1, 0,0, 1}, {1, 1, 0,1}, {1,1, 1, 1},{0,0,1,1}};

  vector<string> pathways;
  solvethemaze(maze, 0, 0, pathways, "");

  // Print all possib<le pathways.
  for (auto itr : pathways) {
    cout << itr << endl;
  }
  if(pathways.empty())std::cout<<"No ways are possible";
}
