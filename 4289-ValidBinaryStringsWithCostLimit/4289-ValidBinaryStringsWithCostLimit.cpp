// Last updated: 7/18/2026, 1:58:46 PM
class Solution {
public:
    vector<string>ans;
     void func( int ind , int n , int k, int sum, string curr ){
          if( sum>k) return;
         if( ind==n) {
              ans.push_back( curr);
             return;
         }
          func( ind+1, n , k , sum , curr+'0');
         if( ind==0 || curr.back()!='1'){
             func( ind+1, n , k ,  sum+ind , curr+'1');
         }
         
     }
    
    vector<string> generateValidStrings(int n, int k) {
         func( 0 , n , k , 0 , "");
         return ans;
        
        
        
        
    }
};