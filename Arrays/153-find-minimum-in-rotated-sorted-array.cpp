/*
problem : 153. Find Minimum in Rotated Sorted Array
Difficulty : Medium

Approach : 
find middle index of the array using binary search
if element of middle index is greater than the element of e
shift pointer to right of the middle index
otherwise shift e to the middle index

Time complexity : o(log n)
Space complexity : o(1)
*/

#include<iostream>
using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {
        int s = 0;
        int e = nums.size()-1;

        int mid = s + (e-s)/2;
        while(s<e){
            if(nums[mid]> nums[e]){
                s = mid+1;
            }
            else{
                e = mid;
            }
            mid = s + (e-s)/2;
        }
        return nums[s];
    }
};