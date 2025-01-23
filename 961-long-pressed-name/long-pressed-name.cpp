class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i = 0, j = 0;
        if (name.size() > typed.size()) return false;
        if (name.size() == typed.size()) return name == typed;
        while (i < name.size() && j < typed.size()) {
            if (name[i] == typed[j]) {
                i++;
                j++;
            } else if (j >= 1 && typed[j] == typed[j-1]) j++;
            else return false;
        }
        if (i != name.size()) return false;
        while (j < typed.size()) {
            if (typed[j] != typed[j-1]) return false;
            j++;
        }
        return true;
    }
};