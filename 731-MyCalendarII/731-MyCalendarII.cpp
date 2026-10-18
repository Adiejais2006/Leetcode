// Last updated: 10/18/2026, 10:38:22 PM
1class MyCalendarTwo 
2{
3    map<int, int> mp; // key: time; val: +1 if start, -1 if end
4public:
5    bool book(int start, int end) 
6    {
7        mp[start]++;
8        mp[end]--;
9        int booked = 0;
10        for (auto it = mp.begin(); it != mp.end(); it++) 
11        {
12            booked += it->second;
13            if (booked == 3) 
14            {
15                mp[start]--;
16                mp[end]++;
17                return false;
18            }
19        }
20        return true;
21    }
22};