//Profile a connected undirected unweighted graph for the following properties.

// Constraints:
// 1. Graph is connected 
// 2. Graph is undirected
// 3. Graph is unweighted
// 4. Graph has at least 3 vertices and upmost 100 vertices
// 5. No self loops and no parallel edges
// 6. A testcase must complete within 1 second of time
// 7. Graph input is a 0/1 matrix

// 1. What is average degree of a vertex in the graph?
int avgDegree(int **g, int n);

// 2. Is the graph a regular graph?
int isRegular(int **g, int n);

// 3. Is the graph a complete graph?
int isComplete(int **g, int n);

// 4. Is the graph a cycle graph?
int isCycleGraph(int **g, int n);

// 5. Is the graph a path graph but not a cycle graph?
int isPathGraph(int **g, int n);

// 6. Does the graph has an Euler circuit?
int hasEulerCkt(int **g, int n);

// 7. Does the graph has an Euler path but not an Euler circuit?
int hasEulerPath(int **g, int n);

// 8. Does the graph satisfy the sufficient condition of the Ore's theorem?
// Sufficient condition for the graph to have a Hamilton according the Ore's theorem:
// deg(u) + deg(v) ≥ n for every pair of nonadjacent vertices u and v in the graph
int satifiesOresTheorem(int **g, int n);
