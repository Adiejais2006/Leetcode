// Last updated: 7/18/2026, 2:04:27 PM
class LFUCache {
private:
    int cap, mn;
    unordered_map<int, pair<int, int>> kvf;
    unordered_map<int, list<int>> f_keys;
    unordered_map<int, list<int>::iterator> k_iter;

    void update(int key) {
        int f = kvf[key].second;
        f_keys[f].erase(k_iter[key]);
        kvf[key].second++;
        f_keys[f + 1].push_front(key);
        k_iter[key] = f_keys[f + 1].begin();
        
        if (f_keys[mn].empty()) {
            mn++;
        }
    }

public:
    LFUCache(int capacity) {
        cap = capacity;
        mn = 0;
    }
    
    int get(int key) {
        if (!kvf.count(key)) {
            return -1;
        }
        update(key);
        return kvf[key].first;
    }
    
    void put(int key, int value) {
        if (cap <= 0) {
            return;
        }
        
        if (kvf.count(key)) {
            kvf[key].first = value;
            update(key);
            return;
        }
        
        if (kvf.size() >= cap) {
            int old = f_keys[mn].back();
            f_keys[mn].pop_back();
            kvf.erase(old);
            k_iter.erase(old);
        }
        
        kvf[key] = {value, 1};
        f_keys[1].push_front(key);
        k_iter[key] = f_keys[1].begin();
        mn = 1;
    }
};