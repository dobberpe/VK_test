#include <fstream>
#include <vector>

std::vector<std::vector<int>> readGraphFromFile(std::ifstream& file);

std::vector<int> BFS(const std::vector<std::vector<int>>& graph, int start);
