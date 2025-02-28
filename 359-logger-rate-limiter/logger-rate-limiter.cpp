class Logger {
public:
    unordered_map<string, int> logs;
    Logger() {
        
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        if (logs.count(message) && abs(timestamp - logs[message]) < 10) {
            return false;
        }
        logs[message] = timestamp;
        return true;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */