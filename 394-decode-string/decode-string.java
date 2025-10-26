class Solution {
    public String decodeString(String s) {
        Stack<Integer> countStack = new Stack<>();
        Stack<StringBuffer> stringStack = new Stack<>();
        StringBuffer currString = new StringBuffer();
        int k = 0;
        for (char c : s.toCharArray()) {
            if (Character.isDigit(c)) {
                k = k * 10 + (c - '0');
            } else if (c == '[') {
                countStack.add(k);
                stringStack.add(currString);
                k = 0;
                currString = new StringBuffer();
            } else if (c == ']') {
                String inner = currString.toString();
                int count = countStack.pop();
                StringBuffer prev = stringStack.pop();
                for (int i = 0; i < count; i++) {
                    prev.append(inner);
                }
                currString = prev;
            } else {
                currString.append(c);
            }
        }

        return currString.toString();

    }
}