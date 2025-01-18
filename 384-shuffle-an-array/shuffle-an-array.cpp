class Solution {
public:
    vector<int> array;
    vector<int> original;

    
    Solution(vector<int>& nums) {
        array = nums;
        original = nums;
        srand(time(0));
    }
    int randRange(int min, int max) {
        return min + rand() % (max - min);
    }
    
    vector<int> reset() {
        array = original;
        return original;
    }
    
    vector<int> shuffle() {
        for (int i = 0; i < array.size(); i++) {
            int j = randRange(i, array.size());
            swap(array[i], array[j]);
        }
        return array;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */