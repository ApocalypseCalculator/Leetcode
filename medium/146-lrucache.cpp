// 146. LRU Cache

// strat: doubly linked list for O(1) LRU eviction, hashmap for O(1) access
// could be faster, also there is some redundant code

#include <unordered_map>
#include <iostream>
using namespace std;
struct Node {
    int key;
    int value;
    Node* prev;
    Node* next;
};

class LRUCache {
    Node* first;
    Node* last;
    unordered_map<int, Node*> m;
    int capacity;
public:
    LRUCache(int capacity) {
        this->first = nullptr;
        this->last = nullptr;
        this->capacity = capacity;
        this->m.reserve(capacity);
    }
    
    int get(int key) {
        if(m.find(key) != m.end()) {
            Node* val = m[key];
            if(m.size() == 1) {
                // DONT SWITCH
                return val->value;
            }

            if(val->key == first->key) {
                return val->value;
            }
            if(val->key == last->key) { // edge case: switching last place
                last = val->prev;
            }
            if(val->prev != nullptr) {
                val->prev->next = val->next;
            }
            if(val->next != nullptr) {
                val->next->prev = val->prev;
            }
            val->prev = nullptr;
            val->next = first;
            first->prev = val;
            first = val;

            return val->value;
        }
        else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        if(m.find(key) != m.end()) {
            Node* val = m[key];
            val->value = value;
            if(m.size() == 1) {
                // DONT SWITCH
                return;
            }
            if(val->key == first->key) {
                return;
            }
            if(val->key == last->key) { // edge case: switching last place
                last = val->prev;
            }
            if(val->prev != nullptr) {
                val->prev->next = val->next;
            }
            if(val->next != nullptr) {
                val->next->prev = val->prev;
            }
            val->prev = nullptr;
            val->next = first;
            first->prev = val;
            first = val;
            return;
        }
        else {
            if(m.size() == capacity) {
                //evict
                // last must exist
                m.erase(last->key);
                if(last->prev != nullptr) {
                    Node* prevval = last->prev;
                    prevval->next = nullptr;
                    delete last;
                    last = prevval;
                }
                else { // only 1 element in cache
                    if(last->key == first->key) {
                        first = nullptr;
                    }
                    delete last;
                    last = nullptr;
                }
            }
            Node* val = new Node();
            val->key = key;
            val->value = value;
            val->next = first;
            val->prev = nullptr;
            if(first != nullptr) {
                first->prev = val;
            }
            first = val;
            if(last == nullptr) { // this val is the first element
                last = val;
            }
            m[key] = val;
            return;
        }
    }
    
    void print() {
        if(first == nullptr) {
            cout << "nothing :(" << endl;
            return;
        }
        Node* cur = first;
        cout << ">>>>>" << endl;
        cout << "first: " << first->key << " last: " << last->key << endl;
        while(true) {
            cout << cur->key << " = " << cur->value << endl;
            if(cur->next == nullptr) {
                break;
            }
            else {
                cur = cur->next;
            }
        }
        cout << "<<<<<" << endl;
    }
};