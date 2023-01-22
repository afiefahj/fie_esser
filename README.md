# fie_esser

• Cite the article properly
Minimum Spanning Tree using Heap. (May-2017). International Journal of Scientific & Engineering Research Volume 8, Issue 5, 1755 ISSN 2229-5518
https://www.ijser.org/researchpaper/Minimum-Spanning-Tree-using-Heap.pdf

• What was the basic algorithm
  The basic of this modification algorithm is a prim algorithm that will find the minimum spanning tree in a graph. This standard algorithm has a time complexity of O(V^2) when using an adjacency matrix to represent the graph. One of the challenges when implementing Prim's algorithm is its time complexity, which can be significant when working with large graphs. To improve the performance of Prim's algorithm, researchers have proposed various optimizations. One of the most effective optimizations is the use of a heap data structure. By using a heap to store the edges, the time complexity of the algorithm can be reduced from O(V^2) to O(E log V).

• What was the modification
  The heap-based implementation of Prim's algorithm involves the use of a priority queue to maintain the edges of the graph, which are ordered according to their weight. The algorithm initiates by inserting all the edges of a selected starting vertex into the priority queue and then proceeds by extracting the edge with the lowest weight. If the extracted edge connects a vertex that is not yet included in the tree to a vertex that is already present, the edge is added to the tree and the edges of the newly added vertex are also inserted into the priority queue. This process is repeated until all the vertices are included in the tree.


• Why it was modified that way
  The version of Prim's algorithm doesn't use a heap data structure to extract the vertex with the minimum key value, instead of using a heap, it uses a linear search to find the vertex with the minimum key value, which can cause poor performance and longer time complexity than the version using a heap while Prim's algorithm uses a heap data structure to extract the vertex with the minimum key value, which can improve the performance of the algorithm and decrease the time complexity. Thus,  the use of a heap data structure is employed, reducing the time complexity from O(V^2) to O(E log V).
