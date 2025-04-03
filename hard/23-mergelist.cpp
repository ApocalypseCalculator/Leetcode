// 23. Merge k Sorted Lists

// strat: min heap binary tree, O(nlogk) time, O(k) space

#include <vector>
using std::vector;
class Solution
{
    struct ListNode
    {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

    struct HeapNode {
        int val;
        ListNode *node;
        HeapNode() : val(0), node(nullptr) {}
        HeapNode(int v, ListNode *n) : val(v), node(n) {}
    };

    class MinHeap {
        HeapNode* heap;
        int size;
        int capacity;
        int parent(int i) {
            return (i - 1) / 2;
        }
        int left_child(int i) {
            return (2*i + 1);
        }
        int right_child(int i) {
            return (2*i + 2);
        }
        void heapify(int i) {
            int smallest = i;
            int left = left_child(i);
            int right = right_child(i);
            if (left < this->size && this->heap[left].val < this->heap[smallest].val) {
                smallest = left;
            }
            if (right < this->size && this->heap[right].val < this->heap[smallest].val) {
                smallest = right;
            }
            if (smallest != i) {
                HeapNode temp = this->heap[i];
                this->heap[i] = this->heap[smallest];
                this->heap[smallest] = temp;
                heapify(smallest);
            }
        }
    public:
        const int get_size() {
            return this->size;
        }
        MinHeap(int capacity) : size(0), capacity(capacity) {
            heap = new HeapNode[capacity];
        }

        ~MinHeap() {
            delete[] heap;
        }

        void insert(int val, ListNode *node) {
            // assume capacity is enough
            this->heap[this->size] = {
                val,
                node
            };
            this->size++;

            int curr = this->size - 1;
            while (curr > 0 && this->heap[parent(curr)].val > this->heap[curr].val) {
                HeapNode temp = this->heap[parent(curr)];
                this->heap[parent(curr)] = this->heap[curr];
                this->heap[curr] = temp;
                curr = parent(curr);
            }
            return;
        }

        HeapNode delete_min() {
            HeapNode min = heap[0];
            HeapNode last_element = this->heap[this->size-1];
            this->heap[0] = last_element;
            this->size--;
            heapify(0);
            return min;
        }

    };

public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        int k = lists.size();
        if (k == 0) {
            return nullptr;
        }
        MinHeap min_heap(k);
        for (int i = 0; i < k; i++) {
            if (lists[i] != nullptr) {
                min_heap.insert(lists[i]->val, lists[i]);
            }
        }
        ListNode *head = new ListNode(0);
        ListNode *curr = head;
        while (min_heap.get_size() > 0) {
            HeapNode min_node = min_heap.delete_min();
            curr->next = new ListNode(min_node.val);
            curr = curr->next;
            if (min_node.node->next != nullptr) {
                min_heap.insert(min_node.node->next->val, min_node.node->next);
            }
        }
        return head->next;
    }
};
