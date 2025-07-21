class SnakeGame {
private:
    int w,h;
    vector<vector<int>> food;
    int foodPos;
    deque<pair<int,int>> snake;
    set<pair<int, int>> snake_map;
public:
    SnakeGame(int width, int height, vector<vector<int>>& food) {
        w = width;
        h = height;
        foodPos = 0;
        this->food = food;
        snake.push_front({0,0});
        snake_map.insert({0,0});
    }
    
    int move(string direction) {
        int i = snake.front().first;
        int j = snake.front().second;
        if(direction=="U") i--;
        else if(direction=="L")  j--;
        else if(direction=="R")  j++;
        else if(direction=="D")  i++;

        //hits boundary
        if(i<0||i>=h||j<0||j>=w) return -1;
        //bites it's body
        pair<int, int> temp = make_pair(i,j);
        auto tail_cord = snake.back();

        if (snake_map.count(temp) && !(i == tail_cord.first && j == tail_cord.second)) 
            return -1;

        if(foodPos < food.size() && i==food[foodPos][0] && j==food[foodPos][1]){
            foodPos++;
        } else {
            snake_map.erase(tail_cord);
            snake.pop_back();
        }

        snake_map.insert(temp);
        snake.push_front(temp);
        return snake.size() -1;
    }
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame* obj = new SnakeGame(width, height, food);
 * int param_1 = obj->move(direction);
 */