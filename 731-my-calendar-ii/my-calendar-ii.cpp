class MyCalendarTwo {
public:
    map<int, int> line;
    int maxOverlaping;
    MyCalendarTwo() {
        maxOverlaping = 3;
    }
    
    bool book(int startTime, int endTime) {
        line[startTime]++;
        line[endTime]--;
        
        int overlapCount = 0;
        for (auto l : line) {
            overlapCount += l.second;
            
            if (overlapCount == maxOverlaping) {
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