class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int position = 0;
        while (tokens.size() > 1) {
            while (tokens[position] != "+" && tokens[position] != "-" &&
                   tokens[position] != "*" && tokens[position] != "/") {
                position++;
            }
            int number1 = std::stoi(tokens[position - 2]);
            int number2 = std::stoi(tokens[position - 1]);
            int newValue = 0;
            if (tokens[position] == "+") {
                newValue = number1 + number2;
            } else if (tokens[position] == "-") {
                newValue = number1 - number2;
            } else if (tokens[position] == "*") {
                newValue = number1 * number2;
            } else if (tokens[position] == "/") {
                newValue = number1 / number2;
            }
            tokens[position] = std::to_string(newValue);
            tokens.erase(tokens.begin() + position - 2,
                         tokens.begin() + position);
            position--;
        }
        return std::stoi(tokens[0]);
    }
};