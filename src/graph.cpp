#include "graph.h"

void Graph::readData() {

    std::ifstream File("data.txt");

    if (!File.is_open()) {
        std::cout << "Failed to open file\n";
        return;
    }

    std::string text;
    
    while (getline(File, text)) {
        data.push_back(std::stoi(text));
    }

    File.close();
}

void Graph::formatData() {

}

const std::vector<int>& Graph::getOriginalGraph() const {
    return data;
}
