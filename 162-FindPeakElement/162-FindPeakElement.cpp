// Last updated: 7/18/2026, 2:05:50 PM
class Solution {
public:
    int findPeakElement(vector<int>& arr) {
          int m = arr.size();
        if(m==1) return 0;
        if (arr[0] > arr[1]) return 0;
        if (arr[m - 2] < arr[m - 1]) return m-1;
        
        int low = 1 ;
        int high = m-2;
        while(low<=high){
            int mid = (low+high)/2 ;
            if(arr[mid]>arr[mid-1] && arr[mid] > arr[mid+1]) return mid;
            // inccreasung curve
            else if (arr[mid-1] < arr[mid] ) {
                low = mid+1;
            }
            else if (arr[mid-1]> arr[mid]){
                high = mid-1;
            }
        }
        return -1;
    }
};