class MyCalendarTwo {
public:
    map<int, int> line;
    MyCalendarTwo() {
        
    }
    
    bool book(int startTime, int endTime) {
        int count = 0;
        line[startTime]++;
        line[endTime]--;
        for (auto m : line) {
            count += m.second;
            if (count >= 3) {
                line[startTime]--;
                line[endTime]++;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */