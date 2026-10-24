class TrieNode {
public:
    TrieNode* child[26] = {};
    vector<string> suggestions;
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());

        TrieNode* root = new TrieNode();

        // Build the trie.
        for (const string& word : products) {
            TrieNode* node = root;
            for (char c : word) {
                int index = c - 'a';
                if (!node->child[index])
                    node->child[index] = new TrieNode();
                node = node->child[index];

                if (node->suggestions.size() < 3)
                    node->suggestions.push_back(word);
            }
        }

        vector<vector<string>> result;
        TrieNode* node = root;

        // Collect suggestions for each successive prefix.
        for (char c : searchWord) {
            if (node)
                node = node->child[c - 'a'];
            if (node)
                result.push_back(node->suggestions);
            else
                result.push_back({});
        }

        return result;
    }
};