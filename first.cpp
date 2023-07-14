#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

class binaray_tree {
    int data;
    binaray_tree *left;
    binaray_tree *right;    
};

template<typename T>
T test(T a, T b) {
    return a + b;
}


class Graph {
    std::map<int, std::vector<int>> adj;
    std::vector<bool> visited;
    std::vector<int> path;
    int num_vertices;
public:

    Graph(int num_vertices) : num_vertices(num_vertices) {
        visited.resize(num_vertices, false);
    }

    void add_edge(int v, int w) {
        adj[v].push_back(w);
        adj[w].push_back(v);
    }

    void dfs(int v) {
        visited[v] = true;
        path.push_back(v);
        for (auto it = adj[v].begin(); it != adj[v].end(); ++it) {
            if (!visited[*it])
                dfs(*it);
        }
    }

    void bfs(int s) {
        std::vector<bool> visited(num_vertices, false);
        std::vector<int> path;
        std::vector<int> queue;
        visited[s] = true;
        queue.push_back(s);
        while (!queue.empty()) {
            s = queue.front();
            path.push_back(s);
            queue.erase(queue.begin());
            for (auto it = adj[s].begin(); it != adj[s].end(); ++it) {
                if (!visited[*it]) {
                    visited[*it] = true;
                    queue.push_back(*it);
                }
            }
        }
    }

    std::vector<int> get_path() {
        return path;
    }

    void prim_algorithm() {
        std::vector<bool> visited(num_vertices, false);
        std::vector<int> path;
        std::vector<int> queue;
        visited[0] = true;
        queue.push_back(0);
        while (!queue.empty()) {
            int s = queue.front();
            path.push_back(s);
            queue.erase(queue.begin());
            for (auto it = adj[s].begin(); it != adj[s].end(); ++it) {
                if (!visited[*it]) {
                    visited[*it] = true;
                    queue.push_back(*it);
                }
            }
        }
    }
};


int main() {
  Graph g(4);
  g.add_edge(0, 1);
  g.add_edge(0, 2);
  g.add_edge(1, 2);
  g.add_edge(2, 3);
  g.dfs(2);
  g.bfs(2);
    auto path = g.get_path();
    for(auto it = path.begin(); it != path.end(); ++it) {
        std::cout << *it << " ";
    }
  return 0;
}
