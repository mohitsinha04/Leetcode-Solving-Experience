#include <bits/stdc++.h>
using namespace std;

class Spreadsheet {
private:
    vector<vector<int>> sp;

    // --- Parse number or cell reference ---
    int parseNumOrCell(string& s, int& i) {
        if (isalpha(s[i])) { // cell reference like A1
            string cell;
            while (i < s.size() && (isalpha(s[i]) || isdigit(s[i])))
                cell += s[i++];
            return get_val(cell);
        } else { // numeric literal
            int res = 0;
            while (i < s.size() && isdigit(s[i])) {
                res = res * 10 + (s[i] - '0');
                i++;
            }
            return res;
        }
    }

    // --- Get value of cell ---
    int get_val(const string& cell) {
        int col = cell[0] - 'A';
        int row = stoi(cell.substr(1));
        return sp[row][col];
    }

    // --- Recursive expression parser ---
    int parseExp(string& s, int& i) {
        vector<int> nums;
        char op = '+';

        while (i < s.size() && op != ')') {
            if (s[i] == ' ') { i++; continue; }

            long curr;
            if (s[i] == '(') curr = parseExp(s, ++i);
            else curr = parseNumOrCell(s, i);

            if (op == '+') nums.push_back(curr);
            else if (op == '-') nums.push_back(-curr);
            else if (op == '*') nums.back() = nums.back() * curr;
            else if (op == '/') nums.back() = nums.back() / curr;

            if (i < s.size()) op = s[i];
            i++;
        }

        int sum = 0;
        for (int n : nums) sum += n;
        return sum;
    }

    int calculate(string s) {
        int i = 0;
        return parseExp(s, i);
    }

public:
    Spreadsheet(int rows) {
        sp = vector<vector<int>>(rows + 1, vector<int>(26));
    }

    void setCell(string cell, int value) {
        int col = cell[0] - 'A';
        int row = stoi(cell.substr(1));
        sp[row][col] = value;
    }

    void resetCell(string cell) {
        setCell(cell, 0);
    }

    int getValue(string formula) {
        // formula like "=A1+B2*3-(C3/2)"
        formula = formula.substr(1);
        return calculate(formula);
    }
};

/**
 * Example:
 * Spreadsheet* sheet = new Spreadsheet(10);
 * sheet->setCell("A1", 5);
 * sheet->setCell("B2", 3);
 * cout << sheet->getValue("=(A1+B2)*2") << endl; // Output: 16
 */
