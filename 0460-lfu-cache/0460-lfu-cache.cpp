class LFUCache {
public:
    unordered_map<int, list<vector<int>>::iterator> hash;  //pushing key and address value in dll itself 
    map<int,list<vector<int>>> freq;   //for frequency ke correspnding values
    int size;
    LFUCache(int capacity) {
        size = capacity;
    }
    
    void lastUsed(int key,int val){
        int f = (*hash[key])[2];

        freq[f].erase(hash[key]);
        if(freq[f].size() == 0) freq.erase(f);

        freq[f+1].push_front({key,val,f+1});     
        hash[key] = freq[f+1].begin(); // hash table entry updated       
    }

    int get(int key) {
        int val = -1;
        if(hash.find(key)!=hash.end()){
            val = (*hash[key])[1];
        }
        if(val!=-1) lastUsed(key,val);
        return val;
    }
    
    void put(int key, int value) {
        if(size == 0 && hash.find(key) == hash.end()){
            // cache full and this is a new key -> evict first
            int min_f = freq.begin()->first;
            int k = freq[min_f].back()[0];
            freq[min_f].pop_back();
            if(freq[min_f].empty()) freq.erase(min_f);
            hash.erase(k);
            size++;
        }

        if(hash.find(key) == hash.end()){
            freq[1].push_front({key,value,1});
            hash[key] = freq[1].begin();
            size--;
        }
        else{
            lastUsed(key,value);
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */