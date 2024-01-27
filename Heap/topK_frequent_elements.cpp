#include<iostream>
#include<queue>
#include<vector>
#include<unordered_map>
using namespace std;

int main(){
    // Input array
    vector<int> arr{1, 1, 1, 2, 3, 3, 4, 4, 5};
    int k = 2; // Number of top frequent elements to find

    // Count the frequency of each element using an unordered_map
    std::unordered_map<int, int> mp;
    for(int &it : arr){
        mp[it]++;
    }

    // Create a min heap (priority queue) to store pairs of frequency and element
    std::priority_queue<std::pair<int, int>, std::vector<pair<int, int>>, std::greater<pair<int, int>>> minq;

    // Iterate through the unordered_map and push elements into the priority queue
    for(auto &it : mp){
        pair<int, int> p = make_pair(it.second, it.first);
        minq.push(p);

        // If the size of the priority queue exceeds k, pop the smallest element
        if(minq.size() > k){
            minq.pop();
        }
    }

    // Extract the top k most frequent elements from the priority queue
    vector<int> ans;
    while(!minq.empty()){
        ans.push_back(minq.top().second);
        minq.pop();
    }

    // Print the result
    for(int &it : ans){
        cout << it << " ";
    }

    return 0;
}
