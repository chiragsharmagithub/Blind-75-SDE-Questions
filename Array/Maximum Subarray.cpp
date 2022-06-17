// Question link: https://leetcode.com/problems/maximum-subarray/

#include <bits/stdc++.h>
using namespace std;

// Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
// Output: 6

// Optimized brute force
// TC: O(N ^ 2)
// SC: O(1)

// Logic: Check each subarray's sum and update the maxSum variable.
// Use 2 FOR loops for find the running sum of subarrays.

int maxSumArray_brute_force(vector<int> nums)
{
    int nums_size = nums.size();
    if (nums_size == 1)
        return nums[0];
    int maxSum = INT_MIN;

    for (int i = 0; i < nums_size - 1; i++)
    {
        int currentSum = 0;
        for (int j = i + 1; j < nums_size; j++)
        {
            currentSum += nums[j];
            maxSum = max(maxSum, currentSum);
        }
    }
    return maxSum;
}

// Dynamic Programming - Kandane's algo
// TC: O(N)
// SC: O(1)

// Logic: use 2 variables currentSum (to keep track of current subarray's sum) and 
// maxSum to store the max sum of all subarrays.
// At any moment, if the sum of surrent subarray is negative or less than the next element, then
// there is no point in continuing with the elements of current subarray. Drop the subarray. 
// Start a new subarray with next element of array.
// and keep updating the maxSum variable.

int maxSubArray_dp(vector<int> nums)
{
    int nums_size = nums.size();
    if (nums_size == 1)
    {
        return nums[0];
    }
    // We are choosing the currentSum and maxSum variable to be starting-element of array.
    int currentSum = nums[0];
    int maxSum = nums[0];

    for (int i = 1; i < nums_size; i++)
    {
        // If the value of currentSum variable becomes negative, it isn't worth keep it.
        // Drop the subarray.
        currentSum = max(currentSum + nums[i], nums[i]);
        maxSum = max(currentSum, maxSum);
    }
    return maxSum;
}

int main()
{
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};

   int maxSum_brute_force = maxSumArray_brute_force(nums);
    int maxSum_dp = maxSubArray_dp(nums);

   cout << "Max sum of Subarray (using brute force) = " << maxSum_brute_force << endl;
    cout << "Max sum of subarray (using DP Kandane's algo) = " << maxSum_dp << endl;

    return 0;
}
