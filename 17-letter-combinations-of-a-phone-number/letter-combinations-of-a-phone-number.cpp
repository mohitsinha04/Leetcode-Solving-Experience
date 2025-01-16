class Solution {
public:
    vector<string> combinations;
    unordered_map<char, string> letters = {
        {'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
        {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
    string phoneDigits;
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return {};
        phoneDigits = digits;
        backtrack(0, "");
        return combinations;
    }
    void backtrack(int i, string path) {
        if (path.size() == phoneDigits.size()) {
            combinations.push_back(path);
            return;
        } 
        string currLetter = letters[phoneDigits[i]];
        for (char letter : currLetter) {
            path.push_back(letter);
            backtrack(i + 1, path);
            path.pop_back();
        }
    }
};