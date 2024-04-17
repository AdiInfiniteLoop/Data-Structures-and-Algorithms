#include<bits/stdc++.h>
using namespace std;

class Subsequence {
public:
    vector<int> ds;
    vector<int> arr;    
    int req;
    Subsequence(vector<int> ds, vector<int> arr, int req) {
        this->ds = ds;
        this->arr = arr;
        this->req = req;
    }
    void generate(int ind, vector<int> &ds, vector<int> arr, int sum, int req) {
        // Base case
        if (sum > req || ind > arr.size()) return;
        // Print and return when sum equals req
         if (sum == req) {
            for (int it: ds) cout << it << " ";
            cout << endl;
            return;
        }

        // Pick
        sum += arr[ind];
        ds.push_back(arr[ind]);
        generate(ind + 1, ds, arr, sum, req);
        ds.pop_back();
        sum -= arr[ind];
        // Not pick
        generate(ind + 1, ds, arr, sum, req);
    }
};

int main() {
    Subsequence* sub = new Subsequence({}, {1,2, 1}, 2);
    vector<int> ds;
    vector<int> arr = {1,2, 1};
    int sum = 0;
    sub->generate(0,ds, arr,sum, 2);
    delete sub; 
    return 0;
}
