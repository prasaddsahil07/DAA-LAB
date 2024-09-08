/*
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%  Name: Sahil Prasad             		 %
%  Roll: 22CS8168                 		 %
%  Question: multiHeap functions(q no: 1)%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
*/



#include <bits/stdc++.h>
using namespace std;

class MultiHeap {
private:
    int p; // Node capacity
    int n_max; // Maximum number of keys
    int n; // Current number of keys
    int node_count; // Number of nodes currently used
    vector<vector<int>> heap; // The multi-heap structure (each node is a vector of keys)

public:
    MultiHeap(int p, int n_max) : p(p), n_max(n_max), n(0), node_count(0) {
        int max_nodes = (n_max + p - 1) / p; // Calculate maximum number of nodes required
        heap.resize(max_nodes);
    }

    void insert(int x) {
        if (n == n_max) {
            cout << "Heap is full!" << endl;
            return;
        }
        
        int last_node_idx = node_count - 1;
        
        // If last node is full or if no node exists, add a new node
        if (node_count == 0 || heap[last_node_idx].size() == p) {
            heap[node_count].push_back(x);
            node_count++;
        } 
        else {
            heap[last_node_idx].push_back(x);
        }
        
        n++;
        fixUp();
    }

    void fixUp() {
        int i = node_count - 1;
        while (i > 0) {
            int parent_idx = (i - 1) / 2;
            int min_key = *min_element(heap[i].begin(), heap[i].end());
            int max_key_parent = *max_element(heap[parent_idx].begin(), heap[parent_idx].end());

            if (min_key >= max_key_parent) break;

            // Swap largest key from parent with smallest key from current node
            swap(*min_element(heap[i].begin(), heap[i].end()), *max_element(heap[parent_idx].begin(), heap[parent_idx].end()));
            i = parent_idx;
        }
    }

    int findmax() {
        if (n == 0) {
            cout << "Heap is empty!" << endl;
            return INT_MIN;
        }

        return *max_element(heap[0].begin(), heap[0].end());
    }

    void heapify(int i) {
        int left_child = 2 * i + 1;
        int right_child = 2 * i + 2;

        int min_key_parent = *min_element(heap[i].begin(), heap[i].end());
        int max_key_left = (left_child < node_count) ? *max_element(heap[left_child].begin(), heap[left_child].end()) : INT_MIN;
        int max_key_right = (right_child < node_count) ? *max_element(heap[right_child].begin(), heap[right_child].end()) : INT_MIN;

        int largest = i;
        if (left_child < node_count && max_key_left > min_key_parent)
            largest = left_child;
        if (right_child < node_count && max_key_right > max_key_left)
            largest = right_child;

        if (largest != i) {
            swap(*min_element(heap[i].begin(), heap[i].end()), *max_element(heap[largest].begin(), heap[largest].end()));
            heapify(largest);
        }
    }

    void delmax() {
        if (n == 0) {
            cout << "Heap is empty!" << endl;
            return;
        }

        int last_node_idx = node_count - 1;
        if (heap[last_node_idx].empty()) {
            cout << "No elements to delete!" << endl;
            return;
        }

        // Remove the maximum from the root
        swap(*max_element(heap[0].begin(), heap[0].end()), heap[last_node_idx].back());
        heap[last_node_idx].pop_back();
        if (heap[last_node_idx].empty()) {
            node_count--;
        }
        n--;
        heapify(0);
    }

    void prnheap() {
        for (int i = 0; i < node_count; i++) {
            cout << "Node " << i + 1 << ": ";
            for (int key : heap[i]) {
                cout << key << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int p, n;
    cout << "Enter node capacity (p): ";
    cin >> p;
    cout << "Enter number of keys to insert (n): ";
    cin >> n;

    MultiHeap H(p, n);

    vector<int> A(n);
    cout << "Enter the keys: ";
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        H.insert(A[i]);
    }

    cout << "\nMulti-heap after all insertions:\n";
    H.prnheap();

    cout << "\nSorted keys:\n";
    for (int i = n - 1; i >= 0; i--) {
        A[i] = H.findmax();
        H.delmax();
    }

    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    return 0;
}
