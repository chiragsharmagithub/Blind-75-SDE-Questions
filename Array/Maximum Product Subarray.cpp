// Question link: 

#include<bits/stdc++.h>
using namespace std;

// Input: nums = [2,3,-2,4]
// Output: 6

// Brute force
// TC:O(N ^ 2)
// SC: O(1)
int maxProduct_brute_force(vector<int>& nums) {
    int nums_size = nums.size();
    if(nums_size == 1) return nums[0];
      
    int maxProd = nums[0];
        
    for(int i=0; i<nums_size; i++) {
        int currProd = 1;
        for(int j=i; j<nums_size; j++) {
            currProd *= nums[j];
            maxProd = max(maxProd, currProd);
        }
    }
    return maxProd;
}

// Dynamic Programming
// TC: O(N)
// SC: O(1)
int maxProduct_dp(vector<int>& nums) {
    int nums_size = nums.size();
    if(nums_size == 1) return nums[0];
      
    int maxProd = nums[0];
    int minProd = nums[0];
    int result = maxProd;
      
    for(int i=1; i<nums_size; i++) {
        int current = nums[i];
        int currMaxProd = max(current, max(maxProd * current, minProd * current));
        minProd = min(current, min(maxProd * current, minProd * current));
        maxProd = currMaxProd;
        result = max(maxProd, result);
    }
    return result;
}

int main() {

    vector<int> nums = {2,3,0,-2,4,-5};

    int maxProd_brute_force = maxProduct_brute_force(nums);
    int maxProd_dp = maxProduct_dp(nums);

    cout << "Max Product (brute force) = " << maxProd_brute_force << endl;
    cout << "Max Product (DP) = " << maxProd_dp << endl;


    return 0;
}
