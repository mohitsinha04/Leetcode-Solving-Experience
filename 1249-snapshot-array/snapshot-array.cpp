class SnapshotArray {
public:
    unordered_map<int, vector<pair<int, int>>> map;
    int snapId;
    SnapshotArray(int length) {
        snapId = 0;
        // records.resize(length);
        // for (int i = 0; i < length; i++) {
        //     records[i].push_back({0, 0});
        // }
    }
    
    void set(int index, int val) {
        // records[index].push_back({snapId, val});
        if (!map[index].empty() && map[index].back().first == snapId) {
            map[index].back().second = val;
            return;
        }
        map[index].emplace_back(snapId, val);
    }
    
    int snap() {
        return snapId++;
    }
    
    int get(int index, int snap_id) {
        auto &arr = map[index];
        int left = 0, right = arr.size() - 1, ans = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid].first <= snap_id) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return ans == -1 ? 0 : arr[ans].second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */