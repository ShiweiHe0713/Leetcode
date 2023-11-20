#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <string>
#include <list>
using namespace std;

class MyHashMap {
public:
    MyHashMap() {
        hm_map = vector<list<pair<int, int> > >(N);
    }
    
    list<pair<int,int>>::iterator find(int key) {
        int t = key % N;
        for(auto iter = hm_map[t].begin(); iter != hm_map[t].end(); iter++) {
            if(iter->first == key) return iter;
        }
        return hm_map[t].end();
    }

    void put(int key, int value) {
        int t = key % N;
        auto it = find(key);

        if(it == hm_map[t].end()) {
            hm_map[t].push_back({key, value});
        } else {
            it->second = value;
        }
    }
    
    int get(int key) {
        int t = key % N;
        auto it = find(key);
        
        if(it == hm_map[t].end()) {
            return -1;
        } else {
            return it->second;
        }
    }
    
    void remove(int key) {
        int t = key % N;
        auto it = find(key);

        if(it != hm_map[t].end()) {
            hm_map[t].erase(it);
        }
    }
private:
    const int N = 10010;
    vector<list<pair<int, int> > > hm_map;
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */