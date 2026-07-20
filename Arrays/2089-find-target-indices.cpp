/*
Problem : 2089.find tareget indices after sorting array
Dificulty : easy

Approach : 
sort the array
compare each element of the array with the target
if target matched store the index of that element in the answer
return answer

Time Complexity: O(n log n)
Space Complexity: O(log n)
*/

#include<iostream>
using namespace std;

class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin() , nums.end());
        vector<int> ans;
        for(int i=0 ; i<nums.size() ; i++){
            if(nums[i] == target){
                ans.push_back(i);
            }
        }
        return ans;
    }
};