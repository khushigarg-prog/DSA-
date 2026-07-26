#include <list>
#include <unordered_map>

using namespace std;

class LRUCache {
public:
    list<int> dll; // Stores keys, front is most recent, back is least recent
    unordered_map<int, pair<list<int>::iterator, int>> mp; // key -> {iterator in dll, value}
    int cap; // Total capacity of the cache

    LRUCache(int capacity) {
        cap = capacity; 
    }
    
    void makeRecentlyUsed(int key){
        dll.erase(mp[key].first);
        dll.push_front(key);
        mp[key].first = dll.begin();
    }
    
    int get(int key) {
        // If key is not found
        if(mp.find(key) == mp.end()){
            return -1;
        }
        
        // If found, move it to the front to mark as recently used
        makeRecentlyUsed(key);
        return mp[key].second;
    }
    
    void put(int key, int value) {
        // Case 1: Key already exists, just update value and move to front
        if(mp.find(key) != mp.end()){
            mp[key].second = value;
            makeRecentlyUsed(key);
        } 
        // Case 2: Key is new
        else {
            // Check if we need to evict an item first
            if(mp.size() == cap){
                int key_to_del = dll.back();
                mp.erase(key_to_del);
                dll.pop_back();
            }
            
            // Insert the new key-value pair
            dll.push_front(key);
            mp[key] = {dll.begin(), value};
        }
    }
};
