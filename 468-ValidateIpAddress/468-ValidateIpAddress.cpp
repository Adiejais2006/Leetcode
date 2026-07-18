// Last updated: 7/18/2026, 2:04:26 PM
class Solution {
public:
    string validIPAddress(string queryIP) {
        if (queryIP.find('.') != string::npos) {
            if (isValidIPv4(queryIP)) return "IPv4";
        } else if (queryIP.find(':') != string::npos) {
            if (isValidIPv6(queryIP)) return "IPv6";
        }
        return "Neither";
    }

private:
    bool isValidIPv4(string ip) {
        int count = 0;
        for (char c : ip) if (c == '.') count++;
        if (count != 3) return false;
        
        stringstream ss(ip);
        string segment;
        int segments = 0;
        while (getline(ss, segment, '.')) {
            segments++;
            if (segment.empty() || segment.size() > 3 || (segment.size() > 1 && segment[0] == '0')) return false;
            for (char c : segment) if (!isdigit(c)) return false;
            int val = stoi(segment);
            if (val < 0 || val > 255) return false;
        }
        return segments == 4;
    }

    bool isValidIPv6(string ip) {
        int count = 0;
        for (char c : ip) if (c == ':') count++;
        if (count != 7) return false;
        
        stringstream ss(ip);
        string segment;
        int segments = 0;
        while (getline(ss, segment, ':')) {
            segments++;
            if (segment.empty() || segment.size() > 4) return false;
            for (char c : segment) {
                if (!isxdigit(c)) return false;
            }
        }
        return segments == 8;
    }
};