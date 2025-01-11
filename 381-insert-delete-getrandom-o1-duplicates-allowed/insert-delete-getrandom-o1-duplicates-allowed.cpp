class RandomizedCollection {
public:
    vector<pair<int, int>> nums;
    unordered_map<int, vector<int>> indexMap;
    RandomizedCollection() {
        
    }
    
    bool insert(int val) {
        auto res = indexMap.find(val) == indexMap.end();
        indexMap[val].push_back(nums.size());
        nums.push_back({val, indexMap[val].size() - 1});
        return res;
        
    }
    
    bool remove(int val) {
        auto res = indexMap.find(val) != indexMap.end();
        if (res) {
            auto last = nums[nums.size() - 1];
            indexMap[last.first][last.second] = indexMap[val].back();
            nums[indexMap[val].back()] = last;
            indexMap[val].pop_back();
            if (indexMap[val].size() <= 0) indexMap.erase(val);
            nums.pop_back();
        }
        return res;
    }
    
    int getRandom() {
        return nums[rand() % nums.size()].first;
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */