class TwoSum {
public:
    unordered_map<long long, long long> map;
    TwoSum() {
        
    }
    
    void add(int number) {
        map[number]++;
    }
    
    bool find(int value) {
        for (auto m : map) {
            long long c = value - m.first;
            if (c != m.first) {
                if (map.count(c)) return true;
            } else if (map[c] > 1) return true;
        }
        return false;
    }
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */