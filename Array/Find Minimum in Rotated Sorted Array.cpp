// Question link: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

#include <bits/stdc++.h>
using namespace std;

// Input: nums = [3,4,5,1,2]
// Output: 1
// Explanation: The original array was [1,2,3,4,5] rotated 3 times.

// Brute force
// TC: O(N)
// SC: O(1)

// Logic: We iterate over the nums array and find the inflection point.
// Inflection point - left elements > right elements
//                    left elements (of inflection point) > right elements (of inflection point)
// While iterating over the array, if we encounter nums[i] > nums[i+1],
// then nums[i+1] is the inflection point.

int findMin_brute_force(vector<int> &nums)
{
    int nums_size = nums.size();
    if (nums_size == 1)
        return nums[0];
    for (int i = 0; i < nums_size - 1; i++)
    {
        if (nums[i] > nums[i + 1])
        {
            return nums[i + 1];
        }
    }
    return nums[0];
}

// Binary Search (modified) - Optimized solution
// O(Log N)
// O(1)

// Logic: We will find the inflection point using binary search.
// Check in-code comments.

int findMin_binary_search(vector<int> &nums)
{
    int nums_size = nums.size();
    if (nums_size == 1)
        return nums[0];

    // Initializing 2 pointers, left and right
    int left = 0, right = nums_size - 1;

    // If the last element is greater than the first element then there is no rotation. Hence first element of array is the smallest element.
    if (nums[right] > nums[0]) // No rotation
    {
        return nums[0];
    }

    // Binary search
    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        // Inflection point - Point of change from higher to lower.
        // condition 1
        // If the mid element is greater than its next element, then mid+1 element is the smallest element.
        if (nums[mid] > nums[mid + 1])
        {
            return nums[mid + 1];
        }

        // condition 2
        // If the mid element is lesser than its previous element, then mid-1 element is the smallest element.
        if (nums[mid - 1] > nums[mid])
        {
            return nums[mid];
        }

        // If the mid element value is greater than the 0th element this means
        // the least value is still somewhere to the right as we are still dealing with elements greater than nums[left].
        if (nums[mid] > nums[left])
        {
            left = mid + 1;
        }
        // If nums[left] is greater than the mid element then this means the smallest value is somewhere to the left.
        else
        {
            right = mid - 1;
        }
    }
    return -1;
}

int main()
{
    vector<int> nums = {3,4,5,1,2};

    int smallestElement_brute_force = findMin_brute_force(nums);
    int smallestElement_binary_search = findMin_binary_search(nums);

    cout << "The smallest element (using brute force method) = " << smallestElement_brute_force << endl;
    cout << "The smallest element (using binary search - Optimized solution) = " << smallestElement_binary_search << endl;
    
    return 0;
}


/*
Additional notes on "Binary search method"

Inflection point - Point of change from higher to lower.
All the elements to the left of inflection point > first element of the array.
All the elements to the right of inflection point < first element of the array.

Algorithm

1. Find the mid element of the array.

2. If mid element > first element of array this means that we need to look for the inflection point on the right of mid.

3. If mid element < first element of array this that we need to look for the inflection point on the left of mid.

Array: 4, 5, 6, 7, 2, 3.
       L     M        R

6 > 4
M > L
nums[mid] > nums[left]

L - Left
M - Mid
R - Right

In the above example mid element 6 is greater than first element 4. 
Hence we continue our search for the inflection point to the right of mid.

4 . We stop our search when we find the inflection point, 
when either of the two conditions is satisfied:


nums[mid] > nums[mid + 1] Hence, mid+1 is the smallest.

nums[mid - 1] > nums[mid] Hence, mid is the smallest.

Array: 4, 5, 6, 7, 2, 3.
                L  M  R

In the above example. With the marked left and right pointers. 
The mid element is 2. The element just before 2 is 7 and 7>2 i.e. nums[mid - 1] > nums[mid]. 
Thus we have found the point of inflection and 2 is the smallest element.

for more clarity/ information visit Leetcode solution (Try to implement it yourself first)
Link: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/solution/

*/