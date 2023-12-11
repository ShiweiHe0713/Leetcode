class Solution {
public:
    int countSubstrings(string s) {
        int result = 0;
        for(int i = 0; i < s.length(); i++) {
            result += countPali(s, i, i);
            result += countPali(s, i, i + 1);
        }
        return result;
    }
private:
    int countPali(string s, int l, int r) {
        int result = 0;
        while(l >= 0 && r < s.length() && s[l] == s[r]) {
            result++;
            l--;
            r++;
        }
        return result;
    }
};
