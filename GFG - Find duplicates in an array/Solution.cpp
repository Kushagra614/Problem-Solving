#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> duplicates(long long arr[], int n) {
    unordered_map<int, int> frequency; // Hash table to store frequency of elements
    vector<int> duplicates;
    int flag = -1;

    // Count the frequency of each element
    for (int i = 0; i < n; ++i) {
        frequency[arr[i]]++;
    }

    // Check for elements with frequency greater than 1 (duplicates)
    for (auto& pair : frequency) {
        if (pair.second > 1) {
            duplicates.push_back(pair.first);
            flag = 0;
        }
    }
    if(flag == -1)
    {
        cout<< -1;
        exit;
    }
    
    else{
    sort(duplicates.begin(), duplicates.end());
    return duplicates;

    }
    }
};
