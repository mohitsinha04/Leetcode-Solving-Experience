/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
// https://leetcode.com/problems/nested-list-weight-sum-ii/solutions/1447325/bfs-java-solution-explanation-included-beats-100
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        queue<NestedInteger> q;
        int prevSum = 0;
        int total = 0;

        for (NestedInteger next : nestedList) {
            q.push(next);
        }

        while (!q.empty()) {
            int size = q.size();
            int levelSum = 0;
            for (int i = 0; i < size; i++) {
                NestedInteger curr = q.front();
                q.pop();

                if (curr.isInteger()) {
                    levelSum += curr.getInteger();
                } else {
                    for (NestedInteger adj : curr.getList()) {
                        q.push(adj);
                    }
                }
            }
            prevSum += levelSum;
            total += prevSum;
        }
        return total;
    }
};