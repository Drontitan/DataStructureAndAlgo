#include <iostream>
#include <unordered_map>
using namespace std;

int countEqualSubsequences(string str) {
    unordered_map<int, int> diffMap;
    int count = 0;
    int diff = 0;
    
    // Initialize with diff 0, to count subsequences starting from index 0
    diffMap[0] = 1;
    
    for (char c : str) {
        // Increment diff for '1', decrement for '0'
        if (c == '1') {
            diff++;
        } else {
            diff--;
        }
        
        // If this diff has been seen before, it means we found subsequences
        // that have equal number of '1's and '0's between the previous occurrence and this one
        if (diffMap.find(diff) != diffMap.end()) {
            count += diffMap[diff];
        }
        
        // Update the map with the current diff count
        diffMap[diff]++;
    }
    
    return count;
}

int main() {
    string str;
    cin >> str;
    
    cout << countEqualSubsequences(str) << endl;
    
    return 0;
}
