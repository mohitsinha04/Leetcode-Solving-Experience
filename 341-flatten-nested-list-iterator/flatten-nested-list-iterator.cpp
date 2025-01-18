/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    NestedInteger n;
    vector<int> integers;
    int p = 0;
    NestedIterator(vector<NestedInteger> &nestedList) {
        // this.nestedList = nestedList;
        flattenList(nestedList);
    }

    void flattenList(vector<NestedInteger>& nestedList) {
        for (auto n : nestedList) {
            if (n.isInteger()) {
                integers.push_back(n.getInteger());
            } else {
                flattenList(n.getList());
            }
        }
    }
    
    int next() {
        return integers[p++];
    }
    
    bool hasNext() {
        return p < integers.size();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */