// Last updated: 7/18/2026, 2:04:41 PM
class Solution {int stduent( vector<int> &a , int pages){
        int pagestudent = 0 ;
        int count =  1;
        for(int i = 0 ; i < a.size() ; i++){
            if((pagestudent + a[i] )<=pages){
                pagestudent+= a[i];
            }
            else {
                count++;
                pagestudent=a[i];
            }
        }
        return count;
    }
public:
    int splitArray(vector<int>& a, int k) {
        int ans =-1;
        int low = *max_element(a.begin(), a.end());
        int high = accumulate(a.begin() , a.end() , 0);
        while(low<=high){

            int mid =(low+high)/2;
            int val = stduent(a , mid);
            if (val > k ){
                low=mid+1;
            }
            else if ( val<=k){
                ans =mid;
                high=mid-1;
            }
        }
    return ans;
    }
};