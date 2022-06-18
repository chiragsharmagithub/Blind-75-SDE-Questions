// Question link: https://leetcode.com/problems/3sum/

#include <bits/stdc++.h>
using namespace std;

// Input: nums = [-1,0,1,2,-1,-4]
// Output: [[-1,-1,2],[-1,0,1]]

// Brute force
// O(N^3)
// SC: O(N) // to store the result (to be returned as answer)

// Logic: Use 3 FOR loops, and check if the adjacent element are equal, increment the
// loop counter to avoid duplicate triplets 

// -----------------------------------------------------

// Sorting + 2 Pointers Method
// TC:O(N ^ Log N) + O(N ^ 2) = O(N ^ 2)
// This is asymptotically equivalent to O(N^2)

// SC: O(N) // result, and temp arrays

// Logic: First sort the array.
// Check if the first element of array is > 0, nums[0]. Return empty vector. 
// Because if the sum of three triplets == 0, the first element must be <= 0.

// Start with the FOR loop and check (in each iteration) if nums[i] (first elemnt of triplet) <= 0.
// Increment i, if nums[i] == nums[i-1] when i>0.

// Assign 2 pointers, start and end, assign start = i+1 and end = nums.size() - 1;
// Run a while loop and check if the triplet's sum (nums[i] + nums[start] + nums[end]) == 0
// If sum < 0, increment start variable, start++.
// If sum > 0, decrement end variable, end--.
// else if sum == 0, store these 3 elements in result variable (in the form of triplet).
    // check for duplicate element from nums[start]'s side, nums[start] != nums[start+1], if yes, start++.
    // Check for duplicate elements from nums[end]'s side, nums[end] != nums[end-1], if yes, end--.

vector<vector<int>> threeSum_optimized(vector<int> &nums)
{
    int nums_size = nums.size();
    if (nums_size < 3)
        return {};

    vector<vector<int>> result;

    sort(nums.begin(), nums.end());
    // After sorting, If the first element of array is > 0, then there will be no triplets having sum == 0.
    if (nums[0] > 0)
        return {};

    for (int i = 0; i < nums_size - 2; i++)
    {
        // If the first element of a candidate-for-answer trplet is > 0, then there will be no possible triplet having sum == 0.
        if (nums[0] > 0)
        {
            break;
        }
        // To fulfil 'have unique triplets'
        // Or To avoid having duplicate triplets
        if (i > 0 && nums[i] == nums[i - 1])
        {
            continue;
        }
        int start = i + 1, end = nums_size - 1;

        while (start < end)
        {
            int isSumZero = nums[i] + nums[start] + nums[end];
            if (isSumZero > 0)
            {
                end--;
            }
            else if (isSumZero < 0)
            {
                start++;
            }
            else if (isSumZero == 0)
            {
                result.push_back({nums[i], nums[start], nums[end]});
                // checking for duplicates
                while (start < end && nums[start] == nums[start + 1])
                {
                    start++;
                }
                while (start < end && nums[end] == nums[end - 1])
                {
                    end--;
                }
                start++;
                end--;
            }
        }
    }
    return result;
}

int main()
{
    vector<int> nums {-1,0,1,2,-1,-4};
    vector<vector<int>> answer = threeSum_optimized(nums);
    for(auto i: answer) {
        cout << "[ " << i[0] << ", " << i[1] << ", " << i[2] << " ]\n";
    }
    return 0;
}
