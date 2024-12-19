# Kruskal’s Algorithm

## Part (a) – Algorithms for Kruskal’s Algorithm

### Required Steps

#### 1. Input Representation
- Represent the graph using an **edge list**, where each edge is represented as a tuple of two vertices and a weight: `(u, v, w)`.

#### 2. Sort the Edges
- Sort the edges by their weights in **non-decreasing order**.

#### 3. Union-Find (Disjoint Set)
- Use the **Union-Find algorithm** to detect cycles and ensure that adding an edge does not form a cycle.

##### Functions for Union-Find:
- **Find:** Determines the root of a set.
- **Union:** Merges two sets.

#### 4. Construct the MST
- **Steps:**
  1. Iterate over the sorted edges.
  2. Add an edge to the MST if it does not form a cycle (use Union-Find to check).
  3. Stop when the MST contains `V - 1` edges (where `V` is the number of vertices).

---

## Part (b) – Analysis of the Algorithms

### Analyze Each Component

#### 1. Sorting Edges
- Sorting the edges using a comparison-based algorithm (e.g., **quicksort** or **mergesort**) has a time complexity of:
  
  **`O(E log E)`**, where `E` is the number of edges.

#### 2. Union-Find Operations
- Each **Union** or **Find** operation has a time complexity of:
  
  **`O(α(V))`**, where `α` is the **inverse Ackermann function**, and `V` is the number of vertices.
- With **path compression** and **union by rank**, the amortized cost is effectively constant.

#### 3. Overall Complexity
- Sorting the edges dominates the overall time complexity.
- Therefore, the total time complexity of Kruskal’s Algorithm is:

  **`O(E log E)`**.

---

### Summary
Kruskal’s Algorithm efficiently constructs a Minimum Spanning Tree (MST) by leveraging:
- Edge sorting to minimize weights.
- Union-Find to avoid cycles and maintain disjoint sets.
- An overall time complexity of **`O(E log E)`**, making it suitable for sparse graphs.

