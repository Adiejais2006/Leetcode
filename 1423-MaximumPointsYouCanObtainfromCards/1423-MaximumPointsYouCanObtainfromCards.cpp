// Last updated: 11/1/2026, 3:01:23 PM
1class Solution {
2public:
3    int maxScore(vector<int>& cardPoints, int k) {
4        int n = cardPoints.size();
5        int sum = 0 ;
6        for(int i = 0 ; i<k ; i++){
7            sum+=cardPoints[i];
8        }
9        int curr = sum ;
10        int l = k-1;
11        int r = n-1;
12        while(k>0){
13            if(l<0)break;
14            curr = curr - cardPoints[l--] + cardPoints[r--];
15            sum=max(sum,curr);
16        }
17        return sum ;
18    }
19};