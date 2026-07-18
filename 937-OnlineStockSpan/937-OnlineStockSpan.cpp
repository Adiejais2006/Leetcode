// Last updated: 7/18/2026, 2:03:06 PM
class StockSpanner {
private:
    stack<pair<int, int>> st;

public:
    StockSpanner() {}
    
    int next(int price) {
        int ans = 1;
        
        while (!st.empty() && st.top().first <= price) {
            ans += st.top().second;
            st.pop();
        }
        
        st.push({price, ans});
        return ans;
    }
};