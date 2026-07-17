/*
Problem: 287. Find the Duplicate Number
Difficulty: Medium

Approach:
Use Binary Search on the range of possible values (1 to n-1).

- Find the middle value (mid).
- Count how many numbers in the array are less than or equal to mid.
- If count > mid, the duplicate lies in the left half.
- Otherwise, the duplicate lies in the right half.
- Repeat until low == high.

Key Idea:
If there are more than 'mid' numbers in the range [1, mid],
then by the Pigeonhole Principle, the duplicate must be in that range.

Time Complexity: O(n log n)
Space Complexity: O(1)
*/

#include<iostream>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int low = 1;
        int high = nums.size() - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            int count = 0;
            for (int x : nums) {
                if (x <= mid)
                    count++;
            }

            if (count > mid)
                high = mid;
            else
                low = mid + 1;
        }

        return low;
    }
};