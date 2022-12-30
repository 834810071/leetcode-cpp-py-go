#include <iostream>
#include <unordered_map>

using namespace std;


struct Node{
    int key;
    int value;
    Node* pre;
    Node* next;
    Node(): pre(nullptr), next(nullptr) {}
    Node(int k, int v): key(k), value(v), pre(nullptr), next(nullptr) {}
};


class LRUCache {
public:
    LRUCache(int capacity) {
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->pre = head;
        cap = capacity;
        size = 0;
    }
    
    int get(int key) {
        if (m.count(key)) {
            Node* t = m[key];
            t->next->pre = t->pre;
            t->pre->next = t->next;
            moveHead(t);
            return t->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (m.count(key)) {
            Node* t = m[key];
            t->value = value;
            t->next->pre = t->pre;
            t->pre->next = t->next;
            moveHead(t);
            return;
        }

        Node* t = new Node(key, value);
        moveHead(t);
        m[key] = t;
        ++size;
        if (size > cap) {
            m.erase(tail->pre->key);
            eraseTail();
        }
    }

    void moveHead(Node *t) {
        t->next = head->next;
        head->next->pre = t;
        t->pre = head;
        head->next = t;
    }

    void eraseTail() {
        Node* t = tail->pre;
        tail->pre = t->pre;
        t->pre->next = tail;
        delete t;
    }
private:
    Node* head;
    Node* tail;
    int cap;
    int size;
    unordered_map<int, Node*> m;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
int main() {
    LRUCache lRUCache = LRUCache(2);
    lRUCache.put(1, 1); // 缓存是 {1=1}
    lRUCache.put(2, 2); // 缓存是 {1=1, 2=2}
    cout<< lRUCache.get(1) << endl;    // 返回 1
    lRUCache.put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
    cout<< lRUCache.get(2) << endl;    // 返回 -1 (未找到)
    lRUCache.put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
    cout<< lRUCache.get(1) << endl;    // 返回 -1 (未找到)
    cout<< lRUCache.get(3) << endl;    // 返回 3
    cout<< lRUCache.get(4) << endl;    // 返回 4
    return 0;
}