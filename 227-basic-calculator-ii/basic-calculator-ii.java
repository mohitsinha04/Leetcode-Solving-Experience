class Solution {
    public int calculate(String s) {
        int i = 0;
        return parseExp(s, i);
    }

    private int parseExp(String s, int i) {
        ArrayList<Integer> nums = new ArrayList<>();
        char operation = '+';

        while (i < s.length() && s.charAt(i) != ')') {
            if (s.charAt(i) == ' ') {
                i++;
                continue;
            }
            int current = s.charAt(i) == ')' ? parseExp(s, i++) : parseNum(s, i);
            if (operation == '*') {
                int n = nums.size();
                nums.set(n - 1, nums.get(n- 1) * current);
            } else if (operation == '/') {
                int n = nums.size();
                nums.set(n - 1, nums.get(n- 1) / current);
            } else if (operation == '+') {
                nums.add(current);
            } else if (operation == '-') {
                nums.add( -1 * current);
            }

            if (i < s.length()) {
                operation = s.charAt(i);
            }
            i++;
        }
        int sum = 0;
        for (Integer num : nums) {
            sum += num;
        }
        return sum;
    }

    int parseNum (String s, int i) {
        long n = 0;
        while (i < s.length() && Character.isDigit(s.charAt(i))) {
            n = n * 10 + (s.charAt(i) - '0');
            i++;
        }
        return ((int)n);
    }
}