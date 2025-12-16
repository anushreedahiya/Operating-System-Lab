//EXP 13:Least Recently Used algorithm
#include <iostream>
using namespace std;

int main() {
    int capacity, n;
    int cache[100]; // Assuming the capacity won't exceed 100
    int currentSize = 0;
    
    int hits = 0;
    int faults = 0;

    cout << "Enter cache capacity: ";
    cin >> capacity;  // Frames
    cout << "Enter number of references: ";
    cin >> n;
    
    cout << "Enter the references (keys to be accessed): " << endl;
    for (int i = 0; i < n; ++i) {
        int key;
        cin >> key;

        // Checking if key is in the cache
        bool found = false;
        int foundIndex = -1;
        for (int j = 0; j < currentSize; ++j) {
            if (cache[j] == key) {
                found = true;
                foundIndex = j;
                break;
            }
        }

        if (found) {
            // Hit - key is in the cache, move it to the front
            hits++;
            for (int j = foundIndex; j > 0; --j) {
                cache[j] = cache[j - 1];
            }
            cache[0] = key;
        } else {
            // Fault - key not in the cache
            faults++;
            if (currentSize < capacity) {
                // Add the new key to the front of the cache
                for (int j = currentSize; j > 0; --j) {
                    cache[j] = cache[j - 1];
                }
                cache[0] = key;
                currentSize++;
            } else {
                // If the cache is full, remove the least recently used item (at the end)
                for (int j = capacity - 1; j > 0; --j) {
                    cache[j] = cache[j - 1];
                }
                cache[0] = key;
            }
        }

        // Display the current cache content
        cout << "Cache content: ";
        for (int j = 0; j < currentSize; ++j) {
            cout << cache[j] << " ";
        }
        cout << endl;
    }

    // Display the number of hits and faults
    cout << "Total Hits: " << hits << endl;
    cout << "Total Faults: " << faults << endl;

    return 0;
}

