class RandomizedSet {
public:
    unordered_map<int, int> indexMap;
    vector<int> dataStructure;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if (indexMap.count(val)) return false;
        indexMap[val] = dataStructure.size();
        dataStructure.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if (!indexMap.count(val)) return false;
        int index = indexMap[val];
        indexMap[dataStructure[dataStructure.size() - 1]] = index;
        swap(dataStructure[index], dataStructure[dataStructure.size() - 1]);
        dataStructure.pop_back();
        indexMap.erase(val);
        return true;
    }
    
    int getRandom() {
        return dataStructure[rand() % dataStructure.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */