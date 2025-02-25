class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
    unordered_map<string, unordered_map<string, double>> graph;

        // Build the graph
        for (int i = 0; i < equations.size(); i++) {
            string a = equations[i][0];
            string b = equations[i][1];
            double value = values[i];
            graph[a][b] = value;
            graph[b][a] = 1.0 / value;
        }

        vector<double> result;
        for (auto& query : queries) {
            string start = query[0];
            string end = query[1];
            if (!graph.count(start) || !graph.count(end)) {
                result.push_back(-1.0);
                continue;
            }
            if (start == end) {
                result.push_back(1.0);
                continue;
            }

            queue<pair<string, double>> q;
            unordered_map<string, bool> visited;
            q.push({start, 1.0});
            bool found = false;

            while (!q.empty() && !found) {
                auto [node, value] = q.front();
                q.pop();
                visited[node] = true;

                for (auto& neighbor : graph[node]) {
                    if (visited.count(neighbor.first)) continue;
                    double newValue = value * neighbor.second;
                    if (neighbor.first == end) {
                        result.push_back(newValue);
                        found = true;
                        break;
                    }
                    q.push({neighbor.first, newValue});
                }
            }

            if (!found) result.push_back(-1.0);
        }
        return result;
    }
};