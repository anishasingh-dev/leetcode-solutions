/*
Problem: 3046. Split the Array
Difficulty: Easy

Approach:
- Sort the array , count consecutive occurrences
  of each element.
- If any element appears more than twice, return false.
- Otherwise, return true.

Key Idea:
Each subarray can contain an element only once. Since there are
two subarrays, an element can appear at most twice in the original array.

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include<iostream>
using namespace std;

class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        int count = 1;

        for (int i = 1; i < nums.size(); i++) {

            if (nums[i] == nums[i - 1]) {
                count++;

                if (count > 2)
                    return false;
            }
            else {
                count = 1;
            }
        }

        return true;
    }
};