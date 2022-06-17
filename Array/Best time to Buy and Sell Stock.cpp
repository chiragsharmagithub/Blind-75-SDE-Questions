// Question linK: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

#include <bits/stdc++.h>
using namespace std;

// Input: prices = [7,1,5,3,6,4]
// Output: 5

// Brute force approach - gives TLE (Time Limit Exceeded)
// TC: O(N^2)
// SC: O(1)

int maxProfit_brute_force(vector<int> &prices)
{
    int maxProfit = 0;
    int prices_Size = prices.size();
    for (int i = 0; i < prices_Size - 1; i++)
    {
        for (int j = i + 1; j < prices_Size; j++)
        {
            int currentProfit = prices[j] - prices[i];
            if (currentProfit > maxProfit)
            {
                maxProfit = currentProfit;
            }
        }
    }
    return maxProfit;
}

// Optimized solution: using the concept of find min and max prices at any given day.
// TC: O(N)
// SC: O(1)
// where N = number of elements in prices array

int maxProfit_optimized(vector<int> &prices)
{
    int minPrice = INT_MAX;
    int maxProfit = 0;
    for (int i : prices)
    {
        if (i < minPrice)
        {
            minPrice = i;
        }
        int currentProfit = i - minPrice;
        if (currentProfit > maxProfit)
        {
            maxProfit = currentProfit;
        }
    }
    return maxProfit;
}

int main()
{

    vector<int> prices = {7, 1, 5, 3, 6, 4};

    // brute force
    int profit_brute_force = maxProfit_brute_force(prices);
    cout << "Max profit (brute force) = " << profit_brute_force << endl;

    // Optimized solution - Using max, and min prodit concept
    int profit_optimized = maxProfit_optimized(prices);
    cout << "Max profit (optimized approach) = " << profit_optimized << endl;

    return 0;
}
