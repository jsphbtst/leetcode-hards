#include <unordered_map>

class Node {
public:
  int key;
  int value;
  Node *next;
  Node *prev;

  Node(int key, int value) {
    this->key = key;
    this->value = value;
    this->next = nullptr;
    this->prev = nullptr;
  }
};

class LRUCache {
private:
  int capacity;
  std::unordered_map<int, Node *> cache;
  Node *left;  // LRU sentinel
  Node *right; // MRU sentinel

  void remove(Node *node) {
    Node *prev = node->prev;
    Node *next = node->next;

    prev->next = next;
    next->prev = prev;
  }

  void insert(Node *node) {
    Node *prev = right->prev;
    Node *next = right;

    prev->next = node;
    next->prev = node;
    node->prev = prev;
    node->next = next;
  }

public:
  LRUCache(int capacity) {
    this->capacity = capacity;
    left = new Node(0, 0);
    right = new Node(0, 0);

    left->next = right;
    right->prev = left;
  }

  int get(int key) {
    if (cache.find(key) != cache.end()) {
      Node *node = cache[key];
      remove(node); // Move to MRU position
      insert(node);
      return node->value;
    }
    return -1;
  }

  void put(int key, int value) {
    if (cache.find(key) != cache.end()) {
      remove(cache[key]);
    }

    Node *node = new Node(key, value);
    insert(node);
    cache[key] = node;

    // If over capacity, remove LRU
    if (cache.size() > capacity) {
      Node *lru = left->next;
      remove(lru);
      cache.erase(lru->key);
      delete lru;
    }
  }

  ~LRUCache() {
    Node *current = left;
    while (current != nullptr) {
      Node *next = current->next;
      delete current;
      current = next;
    }
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */