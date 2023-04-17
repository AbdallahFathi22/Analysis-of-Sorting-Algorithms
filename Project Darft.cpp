#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include "SortingAlgorithm.h"
#include "BubbleSort.h"
#include "CountingSort.h"
#include "HeapSort.h"
#include "InsertionSort.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "SelectionSort.h"
#include "ShellSort.h"
#include "TreeSort.h"
#include "SortTester.h"
#include "RandomPermutationArrayGenerator.h"

using namespace std;

class SortingAlgorithm {

public: 

  SortingAlgorithm(string name) {
        Name = name;
        Comparisons = 0;
        Swaps = 0;
    }

 virtual void Sort(vector<int>& arr) = 0; 
    
   int GetComparisons() {
       
       return Comparisons;
       
   }
    
    int GetSwaps() {
       
       return Swaps;
       
   }

protected:
    string Name;
    int Comparisons;
    int Swaps;



};
   

class SelectionSort : public SortingAlgorithm {
public:
    SelectionSort() : SortingAlgorithm("Selection Sort") {} 

    void Sort(vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i < n - 1; i++) {
            int minIdx = i;
            for (int j = i + 1; j < n; j++) {
                if (arr[j] < arr[minIdx]) {
                    minIdx = j;
                }
                Comparisons++;
            }
            swap(arr[i], arr[minIdx]);
            Swaps++;
        }
    }
};

class InsertionSort : public SortingAlgorithm {
public:
    InsertionSort() : SortingAlgorithm("Insertion Sort") {}

    void Sort(vector<int>& arr) {
        int n = arr.size();
        for (int i = 1; i < n; i++) {
            int key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
                Comparisons++;
                Swaps++;
            }
            arr[j + 1] = key;
        }
    }
};

class MergeSort : public SortingAlgorithm {
public:
    MergeSort() : SortingAlgorithm("Merge Sort") {}

    void Sort(vector<int>& arr) {
        int n = arr.size();
        MergeSortHelper(arr, 0, n - 1);
    }

private:
    void MergeSortHelper(vector<int>& arr, int l, int r) {
        if (l < r) {
            int m = l + (r - l) / 2;
            MergeSortHelper(arr, l, m);
            MergeSortHelper(arr, m + 1, r);
            Merge(arr, l, m, r);
        }
    }

    void Merge(vector<int>& arr, int l, int m, int r) {
        int n1 = m - l + 1;
        int n2 = r - m;
        vector<int> L(n1), R(n2);

        for (int i = 0; i < n1; i++) {
            L[i] = arr[l + i];
        }
        for (int j = 0; j < n2; j++) {
            R[j] = arr[m + 1 + j];
        }

        int i = 0, j = 0, k = l;
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[k++] = L[i++];
            } else {
                arr[k++] = R[j++];
                Swaps++;
            }
            Comparisons++;
        }

        while (i < n1) {
            arr[k++] = L[i++];
        }
        while (j < n2) {
            arr[k++] = R[j++];
        }
    }
};

class QuickSort : public SortingAlgorithm {
public:
    enum PivotChoice { First, Random, Median };

    PivotChoice Pivot;

    QuickSort() : SortingAlgorithm("Quick Sort") {}


    void Sort(std::vector<int>& arr) {
        int size = arr.size();
        QuickSortHelper(arr, 0, size - 1);
    }


private:
    void QuickSortHelper(std::vector<int>& arr, int left, int right) {
        if (left < right) {
            int pivot_index = ChoosePivot(arr, left, right);
            pivot_index = Partition(arr, left, right, pivot_index);
            QuickSortHelper(arr, left, pivot_index - 1);
            QuickSortHelper(arr, pivot_index + 1, right);
        }
    }

    int ChoosePivot(std::vector<int>& arr, int left, int right) {
        switch (Pivot) {
        case First:
            return left;
        case Random:
            return rand() % (right - left + 1) + left;
        case Median:
            return MedianOfThree(arr, left, right);
        }
    }

    int MedianOfThree(std::vector<int>& arr, int left, int right) {
        int mid = (left + right) / 2;
        if (arr[right] < arr[left]) {
            swap(arr[left], arr[right]);
        }
        if (arr[mid] < arr[left]) {
            swap(arr[left], arr[mid]);
        }
        if (arr[right] < arr[mid]) {
            swap(arr[mid], arr[right]);
        }
        return mid;
    }

    int Partition(std::vector<int>& arr, int left, int right, int pivot_index) {
        int pivot_value = arr[pivot_index];
        swap(arr[pivot_index], arr[right]);
        int store_index = left;
        for (int i = left; i < right; i++) {
            Comparisons++;
            if (arr[i] < pivot_value) {
                swap(arr[i], arr[store_index]);
                store_index++;
            }
        }
        swap(arr[store_index], arr[right]);
        return store_index;
    }
};
  /*
  void Swap(std::vector<int>& arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        Swaps++;
    }
};

*/
class BubbleSort : public SortingAlgorithm {
public:
  
  BubbleSort() : SortingAlgorithm("Bubble Sort") {}

  
    void Sort(std::vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i < n-1; i++) {
            for (int j = 0; j < n-i-1; j++) {
                Comparisons++;
                if (arr[j] > arr[j+1]) {
                    swap(arr[j], arr[j+1]);
                    Swaps++;
                }
            }
        }
    };

/*
private:
    void Swap(std::vector<int>& arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        Swaps++;
    }
};
*/

class HeapSort : public SortingAlgorithm {
public:

HeapSort() : SortingAlgorithm("Heap Sort") {}

    void Sort(std::vector<int>& arr) {
        int n = arr.size();
        BuildMaxHeap(arr, n);
        for (int i = n - 1; i >= 1; i--) {
            swap(arr[0], arr[i]);
            Swaps++;
            Heapify(arr, 0, i);
        }
    }


private:
    void BuildMaxHeap(std::vector<int>& arr, int n) {
        for (int i = n / 2 - 1; i >= 0; i--) {
            Heapify(arr, i, n);
        }
    }

    void Heapify(std::vector<int>& arr, int i, int n) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        Comparisons++;
        if (left < n && arr[left] > arr[largest]) {
            largest = left;
        }

        Comparisons++;
        if (right < n && arr[right] > arr[largest]) {
            largest = right;
        }

        if (largest != i) {
            swap(arr[i], arr[largest]);
            Swaps++;
            Heapify(arr, largest, n);
        }
    };
/*
    void Swap(std::vector<int>& arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        Swaps++;
    }
};
*/

class ShellSort : public SortingAlgorithm {
public:
  ShellSort() : SortingAlgorithm("Shell Sort") {}

  
    void Sort(std::vector<int>& arr) {
        int n = arr.size();
        for (int gap = n / 2; gap > 0; gap /= 2) {
            for (int i = gap; i < n; i++) {
                int temp = arr[i];
                int j;
                for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                    arr[j] = arr[j - gap];
                    Comparisons++;
                    Swaps++;
                }
                arr[j] = temp;
                Swaps++;
            }
        }
    }
};




class TreeSort : public SortingAlgorithm {
public:

TreeSort() : SortingAlgorithm("Tree Sort") {}

    void Sort(std::vector<int>& arr) {
        Node* root = nullptr;
        for (int num : arr) {
            root = Insert(root, num);
        }
        TraverseInOrder(root, arr);
    }


private:
    struct Node {
        int val;
        Node* left;
        Node* right;

        Node(int v) : val(v), left(nullptr), right(nullptr) {}
    };

    Node* Insert(Node* root, int num) {
        if (!root) {
            return new Node(num);
        }

        Comparisons++;
        if (num < root->val) {
            root->left = Insert(root->left, num);
        } else {
            root->right = Insert(root->right, num);
        }

        return root;
    }

    void TraverseInOrder(Node* root, std::vector<int>& arr) {
        if (!root) {
            return;
        }
        TraverseInOrder(root->left, arr);
        arr.push_back(root->val);
        TraverseInOrder(root->right, arr);
    }
};




class RandomPermutationVectorGenerator {
public:
    static std::vector<int> GenerateVector(int n) {
        std::vector<int> vec(n);
        for (int i = 0; i < n; i++) {
            vec[i] = i + 1;
        }
        std::shuffle(vec.begin(), vec.end(), std::mt19937(std::random_device()()));
        return vec;
    }
};



class SortTester {
public:
    static void TestSortingAlgorithm(SortingAlgorithm* algorithm) {
        int sizes[] = {1000, 2000, 3000, 5000, 7000, 10000};
        int num_sizes = sizeof(sizes) / sizeof(int);

        for (int i = 0; i < num_sizes; i++) {
            int n = sizes[i];
            int* vec = RandomPermutationArrayGenerator::GenerateArray(n);

            auto start_time = std::chrono::high_resolution_clock::now();
            algorithm->Sort(vec, n);
            auto end_time = std::chrono::high_resolution_clock::now();

            std::chrono::duration<double, std::milli> elapsed_time = end_time - start_time;
            std::cout << "Size " << n << ": " << algorithm->GetComparisons() << " comparisons, "
                      << algorithm->GetSwaps() << " swaps, " << elapsed_time.count() << " ms elapsed" 
                      << std::endl;

            delete[] vec;
        }
    }
};




int main() {
    const int numTests = 6;
    int testSizes[numTests] = {1000, 2000, 3000, 5000, 7000, 10000};

    // Create instances of sorting algorithms to be tested
    BubbleSort bubbleSort;
    CountingSort countingSort;
    HeapSort heapSort;
    InsertionSort insertionSort;
    MergeSort mergeSort;
    QuickSort quickSort;
    SelectionSort selectionSort;
    ShellSort shellSort;
    TreeSort treeSort;

    // Create instance of array generator
    RandomPermutationArrayGenerator arrayGenerator;

    // Create instance of sort tester
    SortTester sortTester;

    // Test each sorting algorithm with various array sizes
    for (int i = 0; i < numTests; i++) {
        int vectorSize = testSizes[i];
        int* vector = arrayGenerator.GenerateArray(vectorSize);

        std::cout << "Testing bubble sort with array size " << vectorSize << "..." << std::endl;
        sortTester.TestSortingAlgorithm(bubbleSort, vector, vectorSize);

        std::cout << "Testing counting sort with array size " << vectorSize << "..." << std::endl;
        sortTester.TestSortingAlgorithm(countingSort, vector, vectorSize);

        std::cout << "Testing heap sort with array size " << vectorSize << "..." << std::endl;
        sortTester.TestSortingAlgorithm(heapSort, vector, vectorSize);

        std::cout << "Testing insertion sort with array size " << vectorSize << "..." << std::endl;
        sortTester.TestSortingAlgorithm(insertionSort, vector, vectorSize);

        std::cout << "Testing merge sort with array size " << vectorSize << "..." << std::endl;
        sortTester.TestSortingAlgorithm(mergeSort, vector, vectorSize);

        std::cout << "Testing quick sort (first element pivot) with array size " << vectorSize << "..." << std::endl;
        quickSort.ChoosePivot(QuickSort::PivotChoice::FIRST_ELEMENT);
        sortTester.TestSortingAlgorithm(quickSort, vector, vectorSize);

        std::cout << "Testing quick sort (random element pivot) with array size " << vectorSize << "..." << std::endl;
        quickSort.ChoosePivot(QuickSort::PivotChoice::RANDOM_ELEMENT);
        sortTester.TestSortingAlgorithm(quickSort, vector, vectorSize);

        std::cout << "Testing quick sort (median-of-three pivot) with array size " << vectorSize << "..." << std::endl;
        quickSort.ChoosePivot(QuickSort::PivotChoice::MEDIAN_OF_THREE);
        sortTester.TestSortingAlgorithm(quickSort, vector, vectorSize);

        std::cout << "Testing selection sort with array size " << vectorSize << "..." << std::endl;
        sortTester.TestSortingAlgorithm(selectionSort, vector, vectorSize);

        std::cout << "Testing shell sort with array size " << arraySize << "..." << std::endl;
        sortTester.TestSortingAlgorithm(shellSort, vector, vectorSize);

        std::cout << "Testing tree sort with array size " << arraySize << "..." << std::endl;
        sortTester.TestSortingAlgorithm(treesort, vector, vectorSize);


        delete[] vector;
    }

    return 0;
}
