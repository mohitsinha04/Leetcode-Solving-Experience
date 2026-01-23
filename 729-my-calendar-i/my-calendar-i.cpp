class MyCalendar {
public:
    map<int, int> line;
    // int max_soFar = INT_MIN;
    // int min_soFar = INT_MAX;
    MyCalendar() {
        
    }
    
    bool book(int startTime, int endTime) {
        line[startTime]++;
        line[endTime]--;

        int count = 0;
        for (auto m : line) {
            if (m.first > endTime) break;
            count += m.second;

            if (count > 1) {
                line[startTime]--;
                line[endTime]++;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */