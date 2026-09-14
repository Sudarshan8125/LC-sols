#include <unordered_map>
#include <map>
#include <list>
#include <vector>

using namespace std;

class LFUCache {
public:
    unordered_map<int, list<vector<int>>::iterator> hash; 
    map<int, list<vector<int>>> freq; 
    
    int size;      
    int capacity;   

    LFUCache(int capacity) {
        this->capacity = capacity;
        this->size = 0;
    }
    
    void lastUsed(int key, int val) {
        int f = (*hash[key])[2];
        
        freq[f].erase(hash[key]);
        if (freq[f].empty()) {
            freq.erase(f);
        }
        
        freq[f + 1].push_front({key, val, f + 1});
        hash[key] = freq[f + 1].begin(); 
    }
    
    int get(int key) {
        if (hash.find(key) == hash.end()) {
            return -1;
        }
        int val = (*hash[key])[1];
        lastUsed(key, val);
        return val;
    }
    
    void put(int key, int value) {
        if (capacity == 0) return; 

        // Scenario 1: Key already exists -> Update value and frequency
        if (hash.find(key) != hash.end()) {
            lastUsed(key, value);
            return;
        }

        // Scenario 2: Cache is full -> Evict the Least Frequently Used (and LRU if tied)
        if (size == capacity) {
            int min_f = freq.begin()->first;
            int key_to_evict = freq[min_f].back()[0];
            
            freq[min_f].pop_back();
            if (freq[min_f].empty()) {
                freq.erase(min_f);
            }
            
            hash.erase(key_to_evict);
            size--;
        }

        // Scenario 3: Insert new key
        freq[1].push_front({key, value, 1});
        hash[key] = freq[1].begin();
        size++; 
    }
};
