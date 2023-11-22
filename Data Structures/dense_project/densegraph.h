#ifndef __DENSE_GRAPH_H__
#define __DENSE_GRAPH_H__

// Your code here
#include <vector>
using namespace std;
class DenseGraph {
   public:
    DenseGraph() {
        // Your code here
        n = 3;
        adj.resize(3, vector<bool>(3, false));
    }

    DenseGraph(int n_in) {
        // Your code here
        n = n_in;
        adj.resize(n_in, vector<bool>(n_in, false));
    }

    DenseGraph(const DenseGraph& G) {
        // Your code here
        adj = G.adj;
        n = G.n;
    }

    void AddEdge(int a, int b) {
        // Your code here
        adj[a][b] = true;
    }

    void RemoveEdge(int a, int b) {
        // Your code here
        adj[a][b] = false;
    }

    bool DoesEdgeExist(int a, int b) const {
        // Your code here
        return adj[a][b];
    }

    DenseGraph Transpose() const {
        // Your code here
        DenseGraph dg(n);
        vector<vector<bool>> transpose(n, vector<bool>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dg.adj[i][j] = adj[j][i];
            }
        }
        return dg;
    }

   protected:
    int n;
    // Your code here
    vector<vector<bool>> adj;
};
#endif  // __DENSE_GRAPH_H__
