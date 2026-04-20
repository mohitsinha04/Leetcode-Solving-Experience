class LFUCache {
public:
    int capacity, size, lfu = 0; //lfu is minimum frequent element
    unordered_map<int, list<int>> keys; //recent from lru map from freqeuency to list
    unordered_map<int, pair<int, int>> values; //map from key to -> {value, frequency}
    unordered_map<int, list<int>::iterator> position; //positions of key in list
    
    //this function is use from lru cache
    void update(int key) {
        int freq = values[key].second;
        auto iter = position[key];
        values[key].second++;
        keys[freq].erase(iter);
        keys[freq + 1].push_back(key);
        position[key] = --keys[freq + 1].end();
        if (keys[lfu].empty()) {
            lfu++;
        }
    }
    
    LFUCache(int capacity) {
        this -> capacity = capacity;
        size = 0;
    }
    int get(int key) {
        if(values.count(key)) {
            update(key);
            return values[key].first;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (capacity == 0) {
            return;
        }
        if (values.count(key)) {
            values[key].first = value;
            update(key);
        } else {
            if (size == capacity) {
                int old = keys[lfu].front();
                keys[lfu].pop_front();
                values.erase(old);
                position.erase(old);
            } else {
                size++;
            }
            values[key] = {value, 1};
            keys[1].push_back(key);
            position[key] = --keys[1].end();
            lfu = 1;
        }
    }  
};
/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */