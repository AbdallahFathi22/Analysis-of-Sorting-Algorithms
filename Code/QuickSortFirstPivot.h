#include <vector>
#include "SortingAlgorithm.h"

class QuickSortFirstPivot : public SortingAlgorithm {
public:
    QuickSortFirstPivot();
    void Sort(std::vector<int>& vec); 

private:
    void QuickSortHelper(std::vector<int>& vec, int left, int right); 
    int Partition(std::vector<int>& vec, int left, int right, int pivotIndex); 
    
};
