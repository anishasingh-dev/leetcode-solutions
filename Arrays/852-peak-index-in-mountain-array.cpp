/*
Problem : 852. Peak Index In Mountain Array
Difficulty : medium

Approach : 
find middle index using binary search
if element of middle index is smaller than the  element of next index
    shift first pointer to the next index of middle  index
otherwise shift last pointer to the middle index;

Time complexity = o(log n);
Space complexity = o(1);
*/

#include<iostream>
using namespace std;

int occurence(vector<int> &arr , int n , int k , bool findFirst){
    int s = 0;
    int e = n-1;
    int ans = -1;

    int mid = s + (e-s)/2;
    while(s<=e){
        if(arr[mid]==k){
            ans = mid;

            if(findFirst){     //left m check 
                e = mid-1;
            }
            else{              //right me check
                s = mid+1;
            }
        }
        else if(arr[mid] < k){
            s = mid+1;
        }
        else{
            e = mid-1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
}
pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
   pair<int , int> p;
   p.first = occurence(arr , n , k , true);
   p.second = occurence(arr , n ,k, false);
   return p;
}
