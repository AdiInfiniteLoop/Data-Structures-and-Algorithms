#include<iostream>
#include<queue>
#include<vector> 
#include<map>
#include<math.h>

using namespace std;

int main(){
    // Input array consisting of coordinates
    std::vector<std::vector<int>> arr{{1,3},{-2,2},{5,8},{0,1}};
    int k = 2;
    // Priority queue to store distances along with coordinates
    std::priority_queue<std::pair<int, std::pair<int, int>>, std::vector<std::pair<int, std::pair<int, int>>>> maxq;

    int r = arr.size();
    for(int i = 0;i < r;++i){
        std::pair<int, int> p = make_pair(arr[i][0],arr[i][1]);
        int distance = arr[i][0]*arr[i][0] + arr[i][1]*arr[i][1];
        maxq.push({distance,p});
        if(maxq.size() > k){
            maxq.pop();
        }
    }


    // Now maxq contains the k closest coordinates and their distances
    while(!maxq.empty()){
        auto topElement = maxq.top();
        cout << "Coordinate: (" << topElement.second.first << ", " << topElement.second.second << "), Distance: " << topElement.first << endl;
        maxq.pop();
    }

    return 0;
}
