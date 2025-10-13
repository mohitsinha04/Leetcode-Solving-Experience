class TrieNode {
    boolean isKey;
    TrieNode[] child;

    TrieNode() {
        isKey = false;
        child = new TrieNode[26];
    }
}

class Trie {
    private TrieNode root;

    public Trie() {
        root = new TrieNode();
    }

     private boolean query(TrieNode lastNode, String word) {
        for (char c : word.toCharArray()) {
            int idx = c - 'a';
            if (lastNode.child[idx] == null)
                return false;
            lastNode = lastNode.child[idx];
        }
        return true;
    }
    
    public void insert(String word) {
        TrieNode lastNode = root;
        for (char c : word.toCharArray()) {
            int idx = c - 'a';
            if (lastNode.child[idx] == null)
                lastNode.child[idx] = new TrieNode();
            lastNode = lastNode.child[idx];
        }
        lastNode.isKey = true;
    }
    
    public boolean search(String word) {
        TrieNode lastNode = root;
        if (!query(lastNode, word))
            return false;
        for (char c : word.toCharArray()) {
            lastNode = lastNode.child[c - 'a'];
        }
        return lastNode.isKey;
    }
    
    public boolean startsWith(String prefix) {
        TrieNode lastNode = root;
        return query(lastNode, prefix);
    }
}

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * boolean param_2 = obj.search(word);
 * boolean param_3 = obj.startsWith(prefix);
 */