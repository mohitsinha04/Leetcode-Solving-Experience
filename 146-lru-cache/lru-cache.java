import java.util.HashMap;
import java.util.Map;

class LRUCache {
    
    // Node definition for the Doubly Linked List
    private class Node {
        int key, val;
        Node prev, next;
        Node(int k, int v) {
            key = k;
            val = v;
        }
    }

    private int capacity;
    private Map<Integer, Node> map;
    private Node head, tail;

    public LRUCache(int capacity) {
        this.capacity = capacity;
        this.map = new HashMap<>();
        
        // Initialize dummy head and tail nodes
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head.next = tail;
        tail.prev = head;
    }
    
    public int get(int key) {
        if (!map.containsKey(key)) {
            return -1;
        }
        Node node = map.get(key);
        // Move to the front (most recently used)
        remove(node);
        insertToFront(node);
        return node.val;
    }
    
    public void put(int key, int value) {
        if (map.containsKey(key)) {
            Node node = map.get(key);
            node.val = value;
            remove(node);
            insertToFront(node);
        } else {
            if (map.size() >= capacity) {
                // Remove the least recently used item (node right before tail)
                Node lru = tail.prev;
                remove(lru);
                map.remove(lru.key);
            }
            Node newNode = new Node(key, value);
            insertToFront(newNode);
            map.put(key, newNode);
        }
    }

    // Helper method to remove a node from the linked list
    private void remove(Node node) {
        node.prev.next = node.next;
        node.next.prev = node.prev;
    }

    // Helper method to insert a node right after the head (most recently used position)
    private void insertToFront(Node node) {
        node.next = head.next;
        node.prev = head;
        head.next.prev = node;
        head.next = node;
    }
}