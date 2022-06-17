// Question link:

// Possible approaches
// brute force O(N^2),O(1)
// Sorting - O(N * Log N), O(1)
// 2 pointer - O(N), O(1)
// Hashmap - O(N), O(N)

#include <bits/stdc++.h>
using namespace std;

// Input: nums = [1,2,3,1]
// Output: true

// Brute force method
// TC: O(N ^ 2)
// SC: O(1)

// Logic: Run 2 FOR loops, and cheeck if nums[i] == nums[j], 
// if yes, then => Array contains duplicates.
bool containsDuplicate_brute_force(vector<int> &nums)
{
    int nums_size = nums.size();
    if (nums_size == 1)
        return false;
    for (int i = 0; i < nums_size - 1; i++)
    {
        for (int j = i + 1; j < nums_size; j++)
        {
            if (nums[i] == nums[j])
            {
                return true;
            }
        }
    }
    return false;
}

// Sorting
// TC: O(N * log N)
// SC: O(1)

// Logic: Sort the array in O(N * Log N) time, run a FOR loop and
// check if there are any adjacent elements, if same adjacent elements are present.
// This implies that the array contains duplicates.

bool containsDuplicate_sorting(vector<int> &nums)
{
    int nums_size = nums.size();
    if (nums_size == 1)
        return false;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums_size - 1; i++)
    {
        if (nums[i] == nums[i + 1])
        {
            return true;
        }
    }
    return false;
}

// Hash map method
// TC: O(N)
// SC: O(N)

// Logic: Store the element in hashmap along with its frequency, and increment its
// frequency upon each encounter.
// At every iteration of FOR loop, check if the frequency of current element > 1,
// if the frequency of any element is > 1,
// this implies that, that element is already visited (having frequency > 1).
// Hence, the array contains duplicates.

bool containsDuplicate_Hashmap(vector<int> &nums)
{
    int nums_size = nums.size();
    if (nums_size == 1)
        return false;
    unordered_map<int, int> hash(10);
    for (int i = 0; i < nums_size; i++)
    {
        if (hash.count(nums[i]))
        {
            return true;
        }
        hash[nums[i]]++;
    }
    return false;
}

int main()
{
    vector<int> nums = {1, 2, 3, 1};

    // Brute force
    bool isDuplicatedPresent_brute_force = containsDuplicate_brute_force(nums);
    cout << "Brute Force method\n";
    isDuplicatedPresent_brute_force ? cout << "Yes, duplicates are present" : cout << "No duplicates found";

    // Hashmap - Optimal
    bool isDuplicatedPresent_Hashmap = containsDuplicate_Hashmap(nums);
    cout << "\n\nHashmap method\n";
    isDuplicatedPresent_Hashmap ? cout << "Yes, duplicates are present" : cout << "No duplicates found";

    // Sorting - Optimal
    bool isDuplicatedPresent_sorting = containsDuplicate_sorting(nums);
    cout << "\n\nSorting method\n";
    isDuplicatedPresent_sorting ? cout << "Yes, duplicates are present" : cout << "No duplicates found";

    return 0;
}
