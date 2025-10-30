#include <iostream>
#include <vector>       // Added
#include <algorithm>  // Added
using namespace std;

class heap {
    vector<int> arr; //vector will serve as our heap

    void heapify(int i) {
        int left = 2 * i;
        int right = 2 * i + 1;
        int min_idx = i;

        // Check if left child exists and is smaller
        if (left < arr.size() && arr[left] < arr[min_idx]) {
            min_idx = left;
        }

        // Check if right child exists and is smaller
        if (right < arr.size() && arr[right] < arr[min_idx]) {
            min_idx = right;
        }

        // If min is not the parent, swap and recurse
        if (min_idx != i) {
            swap(arr[i], arr[min_idx]);
            heapify(min_idx);
        }
    }

public:
    heap(int def_size = 10) //providing a default size
    {
        arr.reserve(def_size + 1);
        arr.push_back(-1); //first position is buffer
    }

    void push(int data) {
        arr.push_back(data);
        int idx = arr.size() - 1; //used as a pointer to our current index
        int parent = idx / 2;

        while (idx > 1 && arr[idx] < arr[parent]) //this is the condition for our swapping limit
        {
            swap(arr[parent], arr[idx]);
            idx = parent;  //updating the indices
            parent = parent / 2;
        }
    }

    // Renamed to get_min() for accuracy
    int get_min() {
        if (arr.size() > 1) {
            return arr[1];
        }
        cerr << "Heap is empty!" << endl;
        return -1; // Return an error value
    }

    void pop() {
        if (arr.size() <= 1) {
             cerr << "Heap is empty, cannot pop!" << endl;
             return;
        }
        
        int idx = arr.size() - 1;
        swap(arr[1], arr[idx]); // Swap root with last element
        arr.pop_back();       // Remove last element
        
        if (arr.size() > 1) { // Only heapify if heap is not empty
           heapify(1);          // Fix the heap from the root
        }
    }
};

int main() {
    heap h; // Create a heap object

    cout << "Pushing elements: 10, 5, 20, 2, 8" << endl;
    h.push(10);
    h.push(5);
    h.push(20);
    h.push(2);
    h.push(8);

    cout << "Current minimum (root): " << h.get_min() << endl; // Should print 2

    cout << "Popping root..." << endl;
    h.pop();
    cout << "New minimum (root): " << h.get_min() << endl; // Should print 5

    cout << "Popping root..." << endl;
    h.pop();
    cout << "New minimum (root): " << h.get_min() << endl; // Should print 8
    
    cout << "Popping root..." << endl;
    h.pop();
    cout << "New minimum (root): " << h.get_min() << endl; // Should print 10

    cout << "Popping root..." << endl;
    h.pop();
    cout << "New minimum (root): " << h.get_min() << endl; // Should print 20

    cout << "Popping root..." << endl;
    h.pop(); // Heap is now empty
    h.pop(); // Should print "Heap is empty, cannot pop!"

    return 0;
}