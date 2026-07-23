// Last updated: 7/24/2026, 12:12:57 AM
1class Solution {
2public:
3    int height(int a,int b) {
4        int h=0;
5        int i=1;
6        while(a>=0 && b>=0) {
7            if(h%2==0) a-=i;
8            else b-=i;
9            i+=1;
10            if(a>=0 && b>=0) h+=1;
11        }
12        if(a>=0 && a-i>=0 && h%2==0) h+=1;
13        if(b>=0 && b-i>=0 && h%2!=0) h+=1;
14        return h;
15    }
16    int maxHeightOfTriangle(int red, int blue) {
17        return max(height(red,blue),height(blue,red));        
18    }
19
20};