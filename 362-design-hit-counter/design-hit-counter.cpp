class HitCounter {
public:
    queue<int> hits;
    HitCounter() {
        
    }
    
    void hit(int timestamp) {
        this->hits.push(timestamp);
    }
    
    int getHits(int timestamp) {
        while (!this->hits.empty()) {
            int diff = timestamp - this->hits.front();
            if (diff >= 300) this->hits.pop();
            else break;
        }
        return this->hits.size();
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */