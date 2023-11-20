#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <string>
#include <list>
using namespace std;

class Solution {
public:
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if(encode_map.find(longUrl) == encode_map.end()) {
            string tinyUrl = base + to_string(encode_map.size() + 1);
            encode_map[longUrl] = tinyUrl;
            decode_map[tinyUrl] = longUrl;
        }
        return encode_map[longUrl];
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return decode_map[shortUrl];
    }
private:
    unordered_map<string, string> encode_map;
    unordered_map<string, string> decode_map;
    string base = "http://shiweihe.com/";
};

int main() {
    Solution obj;
    string url = "www.google.com";
    string url2 = "www.baiduu.com";
    string url3 = "www.uudiab.com";
    // cout << obj.encode(url) << endl;
    // cout << obj.encode(url2) << endl;
    // cout << obj.encode(url3) << endl;
}

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));