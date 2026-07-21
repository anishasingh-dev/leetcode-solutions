/*
Problem: 154. Find Minimum in Rotated Sorted Array II
Difficulty: Hard

Approach:
Use Binary Search.

- If nums[mid] > nums[end], the minimum lies in the right half.
- If nums[mid] < nums[end], the minimum lies in the left half (including mid).
- If nums[mid] == nums[end], we cannot determine the side, so decrement end by 1.

Time Complexity:
- Average: O(log n)
- Worst Case: O(n) (when many duplicates exist)

Space Complexity: O(1)
*/

#include<iostream>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int s = 0;
        int e = nums.size() - 1;
        int mid = s + (e-s)/2;

        while(s<e){
            if(nums[mid] > nums[e]){
                s = mid + 1;
            }
            else if(nums[mid] < nums[e]){
                e = mid;
            }
            else{
                e-- ;
            }
            mid = s + (e-s)/2;
        }
        return nums[s];
    }
};