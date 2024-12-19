# Heap Sort Algorithm

## Part (a): Algorithms for Heap-Sort



#### 1. Heapify Algorithm:
- This function ensures that a subtree rooted at a given index follows the Max-Heap property.
- If the root is smaller than its children, swap it with the largest child and recursively apply heapify.

#### 2. Build Max-Heap:
- Convert an unsorted array into a Max-Heap by calling the heapify function on all non-leaf nodes in reverse level order.

#### 3. Heap Sort:
- Repeatedly swap the root (largest element) with the last element of the heap.
- Reduce the size of the heap by 1.
- Call heapify on the root.

---

## Part (b): Detailed Analysis

### 1. Heapify Function:
- **Time Complex               **O(logn)** (because the height of the heap is log n).

### 2. Build Max-Heap:
- **Time Complexity:**         **O(n)**, as heapify is called for n/2 non-leaf nodes, and the cost decreases as we move up the heap.

### 3. Heap Sort:
- **Time Complexity:**         **O(nlogn)**, as we extract the maximum element n times, and each extraction involves heapify with O(logn) cost.

### Overall Time Complexity:
- **O(nlogn)** for Heap-Sort.

