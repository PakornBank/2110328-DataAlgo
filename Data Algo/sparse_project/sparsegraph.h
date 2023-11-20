#ifndef __SPARSE_GRAPH_H__
#define __SPARSE_GRAPH_H__

// Your code here
#include <set>
#include <utility>

using namespace std;

class SparseGraph {
   public:
    SparseGraph() {
        // Your code here
    }

    SparseGraph(int n_in) {
        // Your code here
    }

    SparseGraph(const SparseGraph& G) : adjList(G.adjList) {
        // Your code here
    }

    void AddEdge(int a, int b) {
        // Your code here
        adjList.emplace(a, b);
    }

    void RemoveEdge(int a, int b) {
        // Your code here
        adjList.erase({a, b});
    }

    bool DoesEdgeExist(int a, int b) const {
        // Your code here
        return adjList.find({a, b}) != adjList.end();
    }

    SparseGraph Transpose() const {
        // Your code here
        SparseGraph transpose;
        for (const auto& i : adjList) {
            transpose.adjList.emplace(i.second, i.first);
        }
        return transpose;
    }

   protected:
    // Your code here
    set<pair<int, int>> adjList;
};
#endif  // __SPARSE_GRAPH_H__
