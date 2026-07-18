// Last updated: 7/18/2026, 2:03:11 PM
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
         map<int, int> mpp;
        int five=0;
         int ten = 0 ;

         for( int i = 0 ; i < bills.size();i++){
            if(bills[i]==5){
                five++;
            }
            else if ( bills[i]==10){
                ten++;
                if(five){
                    five--;
                }
                else return false;
            }
            else{
                
                if(five>0 && ten >0){
                    five--;
                    ten--;
                }
                else if (five>=3){
                    five= five-3;
                }
                else {
                    return false;
                }
            }
         }
         return true;
    }
};