/*
Problem: 238. Product of Array Except Self
Difficulty: Medium

Approach:
- Traverse the array from left to right and store the product of all elements to the left of each index in the result array.
- Traverse the array from right to left while maintaining the product of all elements to the right.
- Multiply the current value in the result array with the right product to get the final answer.
- This avoids using division and achieves O(n) time complexity.

Time Complexity: O(n)
Space Complexity: O(1)   // Excluding the output array
*/

#include<iostream>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);
        
        // store left products
        int left = 1;
        for(int i=0 ; i<n ; i++){
            ans[i] = left;
            left = left * nums[i];
        }

        // multiply it with right products
        int right = 1;
        for(int i = n-1 ; i>=0 ; i--){
            ans[i] = ans[i] * right;
            right = right * nums[i];
        }
        return ans;
    }
};