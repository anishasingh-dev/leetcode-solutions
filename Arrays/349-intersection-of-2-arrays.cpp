/*
Problem: 349. Intersection of Two Arrays
Difficulty: Easy

Approach:
- Sort both arrays.
- Use two pointers to compare elements.
- If equal, add to answer (avoid duplicates) and move both pointers.
- If nums1[i] < nums2[j], move i.
- Otherwise, move j.

Time Complexity: O(n log n + m log m)
Space Complexity: O(1) (excluding output)
*/

#include<iostream>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin() , nums1.end());
        sort(nums2.begin() , nums2.end());

        vector<int>ans;

        int i = 0;
        int j = 0;
        while(i < nums1.size() && j < nums2.size()){
          if(nums1[i] == nums2[j]){
            if(ans.empty() || ans.back() != nums1[i]){
                ans.push_back(nums1[i]);
            }
            i++;
            j++;
          }
          else if(nums1[i] < nums2[j]){
            i++;
          }
          else{
            j++;
          }
        }
        return ans;
        
    }
};