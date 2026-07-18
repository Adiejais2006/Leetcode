// Last updated: 7/18/2026, 1:58:59 PM
class Solution {
public:
    long long sumAndMultiply(int n) {
        long long place = 1;
        long long no = 0;
        while (n != 0) {
            long long r = n % 10;
            if (r != 0) {
                no += place * r;
                place*=10;;
            }
            n = n / 10;
        }
        long long orig = no;
        long long sum = 0 ;
        while(no!=0){
            sum+=no%10;
            no=no/10;
        }
        return orig*sum;

    }
};