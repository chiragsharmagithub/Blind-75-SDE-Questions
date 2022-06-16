// Question link: https://leetcode.com/problems/two-sum/

#include<bits/stdc++.h>
using namespace std;

// Brute Force method

// TC: O(N ^ 2)
// For each element, we try to find its complement by looping through the rest of the array which 
// takes O(n) time. Therefore, the time complexity is O(n^2).

// SC: O(1)
// The space required does not depend on the size of the input array, so only constant space is used.
vector<int> TwoSum_brute_Force(vector<int> nums, int target) {
    int nums_Size = nums.size();
    for(int i=0; i<nums_Size-1; i++) {
        for(int j=i+1; j<nums_Size; j++) {
            if(nums[i] + nums[j] == target) {
                return {i, j};
            }
        }
    }
    // This statement will never execute.
    // Because we are given that a pair of two element having sum == target is always present in nums array.
    return {0, 0};
}

// Optimal code - Using hashmap
// Name of technique: One pass hashmap

// TC: O(N)
// We traverse the list containing nn elements only once. Each lookup in the table costs only O(1) time.

// SC O(N)
// The extra space required depends on the number of items stored in the hash table, which stores at most N elements.
vector<int> twoSum_hashMap(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        int nums_size = nums.size();
        for(int i=0; i<nums_size; i++) {
            int reqNum = target - nums[i];
            if(hash.count(reqNum) != 0) {
                return {i, hash[reqNum]};
            }
            hash[nums[i]] = i;
        }
        return {0, 0};
    }

int main() {
    vector<int> nums = {3, 2, 4};
    int target = 6;

    // Brute force
    vector<int> twoSumIndices = TwoSum_brute_Force(nums, target);
    cout << "The indices (brute force) are " << twoSumIndices[0] << ", " << twoSumIndices[1];

    // One-pass Hashmap 
    vector<int> twoSumIndices1 = twoSum_hashMap(nums, target);
    cout << "The indices (hash map) are " << twoSumIndices1[0] << ", " << twoSumIndices1[1];

    return 0;
}
