# Shell Sort 

# Introduction

Shell Sort is a sorting algorithm that is an extension of Insertion Sort. 
It was invented by Donald Shell in 1959, and it works by sorting elements that are far apart and then gradually reducing the gap between the elements until the gap is 1. 
At this point, the algorithm is identical to the Insertion Sort algorithm.

# Working of Shell Sort

Shell Sort uses the concept of gap sequences to sort elements in the input array. 
A gap sequence is a sequence of integers that defines the gap between elements to be compared during the sorting process.

The algorithm works by first selecting a gap sequence. One commonly used gap sequence is the Knuth sequence, which is defined as follows: h = 3h + 1, where h is the initial gap value and is set to 1. The gap sequence is generated by repeatedly applying this formula until h is greater than or equal to the size of the input array.

The algorithm then sorts the input array by comparing elements that are h positions apart. Elements that are h positions apart are called a h-sort. After completing the h-sort, the value of h is reduced according to the gap sequence, and the algorithm repeats the sorting process until the gap is 1.

When the gap is 1, the algorithm is identical to the Insertion Sort algorithm. At this point, the input array has been partially sorted, and the final pass of Insertion Sort will complete the sorting process.

# Complexity Analysis

The time complexity of Shell Sort depends on the gap sequence used. The worst-case time complexity is O(n^2) when the gap sequence is 1, which is the same as Insertion Sort. However, the time complexity can be improved by using gap sequences that result in fewer passes.

The best known gap sequence is the one proposed by Sedgewick and is given by {1, 5, 19, 41, 109,...}. The worst-case time complexity of Shell Sort using this gap sequence is O(n^(4/3)), making it faster than Insertion Sort.

Space complexity of Shell Sort is O(1) as it sorts the input array in place.

# Conclusion

Shell Sort is a simple and efficient sorting algorithm that is based on the concept of gap sequences. It works by sorting elements that are far apart and then gradually reducing the gap between elements until the gap is 1, at which point it uses Insertion Sort to complete the sorting process. The time complexity of Shell Sort depends on the gap sequence used and can range from O(n^2) to O(n^(4/3)).

# Refernces 

https://www.geeksforgeeks.org/shellsort/
