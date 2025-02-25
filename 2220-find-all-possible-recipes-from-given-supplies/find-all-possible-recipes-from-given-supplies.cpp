class Solution{
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies){
        int n = recipes.size();
        
        unordered_set<string> recipeSet;
        unordered_map<string, int> indegree;
        unordered_map<string, vector<string>> adjList;
        
        for(int i = 0; i < n; i++){
            recipeSet.insert(recipes[i]);
            for(int j = 0; j < ingredients[i].size(); j++){
                adjList[ingredients[i][j]].push_back(recipes[i]);
            }
            indegree[recipes[i]] = ingredients[i].size();
        }
        
        queue<string> q;
        for(auto &supply: supplies){
            q.push(supply);
        }
        
        vector<string> ans;
        while(!q.empty()){
            string curr = q.front();
            q.pop();
            
            if(recipeSet.count(curr)) ans.push_back(curr);
            
            for(auto it: adjList[curr]){
                indegree[it]--;
                
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }
        return ans;
    }
};