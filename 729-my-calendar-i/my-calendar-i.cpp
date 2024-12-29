class MyCalendar {
    std::vector<std::pair<int, int>> list;

public:
    MyCalendar() {
        list = {};
    }

    bool book(int start, int end) {
        if (list.empty()) {
            list.emplace_back(start, end);
            return true;
        }

        int left = searchRight(start);
        int right = searchLeft(end);

        if (left == right) {
            list.insert(list.begin() + right, {start, end});
            return true;
        }
        return false;
    }

private:
    int searchRight(int start) {
        int lo = 0, hi = list.size() - 1;

        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (list[mid].second <= start) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return lo;
    }

    int searchLeft(int end) {
        int lo = 0, hi = list.size() - 1;

        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (list[mid].first < end) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return lo;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */