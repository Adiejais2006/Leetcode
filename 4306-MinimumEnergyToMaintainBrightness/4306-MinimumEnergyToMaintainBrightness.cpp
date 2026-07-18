// Last updated: 7/18/2026, 1:58:38 PM
class Solution {
public:
    long long minEnergy(int n, int brightness, vector<vector<int>>& intervals) {
           long long ans =0;
          long long pingu = (brightness+2)/3;
           sort( intervals.begin(),intervals.end());
         long long lastEnd = -1;
        
         for ( int i =0;i<intervals.size();i++){
              long long dingu=0 ;
              if( i==0){
                  dingu = intervals[i][1]- intervals[i][0]+1;
                  lastEnd = intervals[i][1];
              }
              else{
                  if( intervals[i][0] <= lastEnd){
                      if( intervals[i][1] > lastEnd){
                          dingu = intervals[i][1] -lastEnd;
                          lastEnd = intervals[i][1];
                      }
                  }
                  else{
                      dingu = intervals[i][1]- intervals[i][0]+1;
                      lastEnd = intervals[i][1];
                  }
              }
             ans+=dingu*pingu;
         }
        return ans;
        
        
        
    }
};