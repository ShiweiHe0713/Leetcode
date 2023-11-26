class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> m;
        for(char c : t) {
            m[c]++;
        }
        int l = 0, r = 0;
        int minStart = 0, minLen = INT_MAX;
        int counter = t.length();

        while(r < s.size()) {
            if(m[s[r]] > 0) {
                counter--;
            }
            m[s[r]]--;
            r++;
            while(counter == 0) {
                if(r - l < minLen) {
                    minStart = l;
                    minLen = r - l;
                }
                m[s[l]]++;
                if(m[s[l]] > 0) {
                    counter++;
                }
                l++;
            }
        }
        cout << minStart << " : " << minLen << endl;

        if(minLen != INT_MAX) {
            return s.substr(minStart, minLen);
        }
        return "";
    }   
};
