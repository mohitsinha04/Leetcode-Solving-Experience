/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */

class Solution {
public:
    vector<vector<int>> dir{ { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };
    set<pair<int, int>> vis;
    // Robot robot;

    void goBack(Robot& robot) {
        robot.turnRight();
        robot.turnRight();
        robot.move();
        robot.turnRight();
        robot.turnRight();
    }

    void backtrack(int row, int col, int d, Robot& robot) {
        vis.insert({row, col});
        robot.clean();

        for (int i = 0; i < 4; i++) {
            int newD = (d + i) % 4;
            int newRow = row + dir[newD][0];
            int newCol = col + dir[newD][1];

            if (!vis.count({newRow, newCol}) && robot.move()) {
                backtrack(newRow, newCol, newD, robot);
                goBack(robot);
            }
            robot.turnRight();
        }
    }
 
    void cleanRoom(Robot& robot) {
        // this->robot = robot;
        backtrack(0, 0, 0, robot);
    }
};