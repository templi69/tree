#include <iostream>
using namespace std;

// Recursive function to find the index of the largest number
int findLargestIndex(int arr[], int size, int index = 0, int maxIndex = 0) {
    if (index == size) return maxIndex;
    if (arr[index] > arr[maxIndex]) maxIndex = index;
    return findLargestIndex(arr, size, index + 1, maxIndex);
}

// Recursive function to check if subset sum equals target
bool isSubsetSum(int arr[], int size, int target, int index = 0) {
    if (target == 0) return true;
    if (index == size || target < 0) return false;

    // Include current element
    if (isSubsetSum(arr, size, target - arr[index], index + 1))
        return true;

    // Exclude current element
    return isSubsetSum(arr, size, target, index + 1);
}

// Recursive function to find the magic number
int findMagicNumber(int arr[], int size) {
    if (size == 0) return -1;

    int largestIndex = findLargestIndex(arr, size);
    int largest = arr[largestIndex];

    // Create new array without the largest element
    int newSize = size - 1;
    int* remaining = new int[newSize];
    int idx = 0;

    for (int i = 0; i < size; ++i) {
        if (i != largestIndex)
            remaining[idx++] = arr[i];
    }

    // Check if largest is a subset sum of remaining
    if (isSubsetSum(remaining, newSize, largest)) {
        delete[] remaining;
        return largest;
    }

    // Recurse with remaining elements
    int result = findMagicNumber(remaining, newSize);
    delete[] remaining;
    return result;
}

int main() {
    int arr[] = { 3, 34, 4, 12, 5, 2 };  // Example: magic number is 12 (5 + 4 + 3)
    int size = sizeof(arr) / sizeof(arr[0]);

    int magic = findMagicNumber(arr, size);
    if (magic != -1)
        cout << "Magic number found: " << magic << endl;
    else
        cout << "No magic number exists." << endl;

    return 0;
}
