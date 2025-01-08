class Solution {
public:
    bool canChange(string start, string target) {
        int startInd = 0, targetInd = 0;

        while (startInd < start.size() || targetInd < start.size()) {
            while (startInd < start.size() && start[startInd] == '_') {
                startInd++;
            }
            while (targetInd < start.size() && target[targetInd] == '_') {
                targetInd++;
            } 
            if (startInd == start.size() || targetInd == start.size()) {
                return startInd == start.size() && targetInd == start.size();
            }
            if (start[startInd] != target[targetInd] ||
             (start[startInd] == 'L' && startInd < targetInd) ||
             (start[startInd] == 'R' && startInd > targetInd)) return false;

             startInd++;
             targetInd++;
        }
        return true;
    }
};