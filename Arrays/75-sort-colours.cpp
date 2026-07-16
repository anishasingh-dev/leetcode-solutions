/*
Problem: 75. sort colours
Difficulty: Medium

Approach:
Use three pointers:
- start  -> next position for 0
- current -> traverses the array
- end    -> next position for 2

Traverse while current <= end:
- If nums[current] == 0, swap with start and increment both.
- If nums[current] == 1, move current.
- If nums[current] == 2, swap with end and decrement end (don't move current).

Time Complexity: O(n)
Space Complexity: O(1) 
*/

#include<iostream>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        // here we use three pointers approach
        int start = 0;
        int current = 0;
        int end = nums.size() - 1;
        
        while(current <= end){
            // case 1
            if(nums[current] == 0){
                swap(nums[current] , nums[start]);
                current++;
                start++;
            }
            // case 2
            else if(nums[current] == 1){
                current++;
            }
            // case 3 i.e nums[current] ==2
            else{
                swap(nums[current] , nums[end]);
                end--;
            }
        }
    }
};