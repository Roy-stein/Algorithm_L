// Leetcode: 852. Peak Index in a Mountain Array

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l = 0, r = arr.size();
        while(l < r){
            int mid = l + (r-l) / 2;
            if(arr[mid-1] < arr[mid] && arr[mid] < arr[mid+1])
                l = mid+1;
            else if(arr[mid-1] > arr[mid] && arr[mid] > arr[mid+1])
                r = mid;
            else
                return mid;
        }
        return l;
    }
};
