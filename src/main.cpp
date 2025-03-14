#include "graph.h"

#include <iostream>
#include <filesystem>

int main() {
    std::ifstream file(std::filesystem::path(PROJECT_ROOT) / "data/graph.txt");

    if (file) {
        try {
            std::vector<std::vector<int>> graph = readGraphFromFile(file);

            int start;
            if (!(file >> start)) {
                throw std::runtime_error("Error: start vertex number is missing");
            }

            std::vector<int> distance = BFS(graph, start);

            for (const auto& d : distance) {
                std::cout << d << '\n';
            }
        } catch (std::exception& e) {
            std::cerr << e.what() << '\n';
        }
    } else {
        std::cerr << "Error: couldn't open file graph.txt\n";
    }
    return 0;
}
