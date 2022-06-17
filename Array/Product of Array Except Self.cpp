// Question link: https://leetcode.com/problems/product-of-array-except-self/

#include <bits/stdc++.h>
using namespace std;

// Input: nums = [1,2,3,4]
// Output: [24,12,8,6]

// TC: O(N)
// SC: O(1)
// Since don't use any additional array for our computations.
// The problem statement mentions that using the answer array
// doesn't add to the space complexity.

// Logic: We update ith element of answer array with the product of 0 to (i-1)th elements in first iteration
// and will update the ith element of answer array with the product of i+1 to end-of-array in the second iteration.
// In this way, at every ith element we have the product of elements from 0 t i-1 and i+1 to end-of-array.


vector<int> productExceptSelf(vector<int> &nums)
{
    int nums_size = nums.size();
    vector<int> answer(nums_size);

    answer[0] = 1;
    for (int i = 1; i < nums_size; i++)
    {
        // answer[i-1] contains the product of all the elements left of i-1 (excluding (i-1)th element)
        // multiply the answer[i-1] * nums[i-1] will give the product of all the elements left of i. (including (i-1)th element).
        answer[i] = nums[i - 1] * answer[i - 1];
    }

    int right = 1;
    for (int i = nums_size - 1; i >= 0; i--)
    {
        // For element at ith index, the variable 'right' will contain the product of all the elements to the right (of ith element).
        answer[i] = answer[i] * right;
        right *= nums[i];
    }
    return answer;
}

int main()
{
    vector<int> nums = {1,2,3,4};
    vector<int> result = productExceptSelf(nums);

    // print product of all elements except self
    for(auto i: result) {
        cout << i << endl;
    }
    return 0;
}