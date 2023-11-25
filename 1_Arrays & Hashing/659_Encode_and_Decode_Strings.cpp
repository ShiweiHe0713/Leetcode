#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <list>
using namespace std;

class Solution {
public:
    /*
     * @param strs: a list of strings
     * @return: encodes a list of strings to a single string.
     */
    string encode(vector<string> &strs) {
        // write your code here
        string encoded_str;
        for(string s : strs) {
            encoded_str = encoded_str + s;
            encoded_str = encoded_str + ":;";
        }
        encode_map[strs] = encoded_str;
        decode_map[encoded_str] = strs;
        return encoded_str;
    }

    /*
     * @param str: A string
     * @return: decodes a single string to a list of strings
     */
    vector<string> decode(string &str) {
        // write your code here
        return decode_map[str];
    }
private:
    // encode_map : list<string> -> string
    unordered_map<vector<string>, string> encode_map;
    // decode_map : string -> list<string>
    unordered_map<string, vector<string> > decode_map;
};

int main() {
    Solution obj;
    vector<string> strs;
    strs.push_back("Hello");
    strs.push_back("World");
    strs.push_back("it");
    strs.push_back("is");
    strs.push_back("me");

    cout << obj.encode(strs) << endl;

}
