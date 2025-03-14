#include "graph.h"

#include <queue>
#include <exception>

std::vector<std::vector<int>> readGraphFromFile(std::ifstream& file) {
    int numVertices;
    if (!(file >> numVertices)) {
        throw std::runtime_error("Error: empty file");
    } else if (numVertices <= 0) {
        throw std::runtime_error("Error: invalid number of vertices");
    }

    std::vector<std::vector<int>> graph(numVertices);


    int numEdges;
    if (!(file >> numEdges)) {
        throw std::runtime_error("Error: number of edges is missing");
    } else if (numEdges < 0) {
        throw std::runtime_error("Error: invalid number of edges");
    }

    for (int i = 0; i < numEdges; ++i) {
        int left, right;
        if (!(file >> left >> right) || left < 0 || right < 0 || left >= numVertices || right >= numVertices) {
            throw std::runtime_error("Error: invalid edge data");
        }

        graph[left].push_back(right);
        graph[right].push_back(left);
    }

    return graph;
}

std::vector<int> BFS(const std::vector<std::vector<int>>& graph, int start) {
    int n = graph.size();
    std::vector<int> distance(n, -1);
    std::queue<int> q;

    distance[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int neighbor : graph[v]) {
            if (distance[neighbor] == -1) {
                distance[neighbor] = distance[v] + 1;
                q.push(neighbor);
            }
        }
    }

    return distance;
}
