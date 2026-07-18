// Last updated: 7/18/2026, 2:04:14 PM
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& arr) {
       stack<int> st;
        int n = arr.size();
        vector<int> ans (n);
        for(int i = 2*n-1 ; i>=0 ; i--){
            int curIndex = i%n;
            int currElement = arr[curIndex];
            while(!st.empty() && st.top()<=currElement){
                st.pop();
            }
            if(st.empty()){
                ans[curIndex]= - 1 ;
            }
            else{
                ans[curIndex] = st.top();
            }
            st.push(currElement);
        }
        return ans ;  
    }
};