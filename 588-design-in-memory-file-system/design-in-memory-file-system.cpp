class FileSystem {
private:
    struct Node {
        bool isFile;
        string content;
        unordered_map<string, Node*> children;
        Node(): isFile(false), content("") {}
    };
    
    Node* root;
    
    // Split path by '/'
    vector<string> split(const string &path) {
        vector<string> parts;
        string token;
        for (char c : path) {
            if (c == '/') {
                if (!token.empty()) {
                    parts.push_back(token);
                    token.clear();
                }
            } else token.push_back(c);
        }
        if (!token.empty()) parts.push_back(token);
        return parts;
    }

    // Traverse tree; create nodes if create=true
    Node* traverse(const vector<string>& parts, bool create = false) {
        Node* cur = root;
        for (auto &p : parts) {
            if (!cur->children.count(p)) {
                if (!create) return nullptr;
                cur->children[p] = new Node();
            }
            cur = cur->children[p];
        }
        return cur;
    }

public:
    FileSystem() { root = new Node(); }

    vector<string> ls(string path) {
        if (path == "/" || path.empty()) {
            vector<string> res;
            for (auto &kv : root->children) res.push_back(kv.first);
            sort(res.begin(), res.end());
            return res;
        }

        vector<string> parts = split(path);
        Node* node = traverse(parts, false);
        if (!node) return {};
        
        if (node->isFile) return { parts.back() };
        
        vector<string> res;
        for (auto &kv : node->children) res.push_back(kv.first);
        sort(res.begin(), res.end());
        return res;
    }

    void mkdir(string path) {
        if (path == "/" || path.empty()) return;
        traverse(split(path), true);
    }

    void addContentToFile(string filePath, string content) {
        Node* node = traverse(split(filePath), true);
        node->isFile = true;
        node->content += content;
    }

    string readContentFromFile(string filePath) {
        Node* node = traverse(split(filePath), false);
        return (node && node->isFile) ? node->content : "";
    }
};
