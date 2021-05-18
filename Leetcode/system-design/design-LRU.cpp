/*
https://leetcode.com/problems/lru-cache/
*/
class LRUCache {
public:
    
    int capacity;
    map<int, pair<int, int>> mp;
    int timestamp;
    
    LRUCache(int capacity) {
        
        timestamp = 0;
        this->capacity = capacity;
        
    }
    
    int get(int key) {

        for(auto it = mp.begin(); it!=mp.end(); it++){
            
            pair<int, int> temp = it->second;            
            if(temp.first==key){
                mp.erase(it);
                timestamp++;
                mp[timestamp] = {temp.first, temp.second}; //Update timestamp
                return temp.second;
            }
            
        }
        return -1;
    }
    
    void put(int key, int value) {
        
        
        for(auto it = mp.begin(); it!=mp.end(); it++){ //Check if already exists
                        
            pair<int, int> temp = (it->second);            
            if(temp.first==key){ 
             
                mp.erase(it);
                timestamp++;
                mp[timestamp] = {key, value};
                return;
                
            }                
        }
        
        //If key doesn't exist, need to evict
        
        // if map is not at full capacity
        if(mp.size()<capacity){
            
            timestamp++;
            mp[timestamp] = {key, value};
            return;
            
        }
        
        //If map is at full capacity, need to evict, Least Recently Used
        // Remove first element since map is sorted by timestamp
        
        auto it = mp.begin();        
        mp.erase(it);
        
        timestamp++;
        mp[timestamp] = {key, value};
        
        return;
    
        
        
        
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
