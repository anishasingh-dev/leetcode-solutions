/*
Problem: 1207. Unique Number of Occurrences
Difficulty: Easy

Approach:
- Sort the array
- Count frequencies
- Check if all frequencies are unique

Time Complexity: O(n log n)
Space Complexity: O(n)
*/

#include<iostream>
using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {

        // sort the array 
        sort(arr.begin(), arr.end());

        // to store count of elements
        vector<int> freq ;
        
        // already consider arr[0] so count is starting from 1
        int count = 1;

        for(int i=1 ; i<arr.size() ; i++){
            if(arr[i] == arr[i-1]){
                count++;
            }
            else{
                freq.push_back(count);
                // reset count after counting occurence of similar element
                count = 1;
            }
        }

        // last elemnt's frequency never got pushed in the array as loop ended so
        freq.push_back(count);

        // now checking for duplicates in the frequency array
        for(int i=0; i<freq.size() ; i++){
            for(int j=i+1 ; j<freq.size() ; j++){
                if(freq[j] == freq[i]){
                    return false;
                }
            }
        }
        return true;

    }
};