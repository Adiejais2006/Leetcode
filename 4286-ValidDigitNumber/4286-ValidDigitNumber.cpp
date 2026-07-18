// Last updated: 7/18/2026, 1:58:47 PM
class Solution {
public:
    bool validDigit(int n, int x) {
        bool one = false; 
        bool two = true;
        while(n>0){
            int r = n%10;
            if(r==x) one=true;
            if(n/10 ==0){
                if(r==x) two =false;
            }
            n=n/10;
        }

        return (one&&two);
    }
};