#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>

class Graph {
    private:
        bool edges[8][8]; // set to true means an edge exists between the two vertices, false means no edge
        bool marks[8]; // an 8 element array of bools. true means the vertex is marked, false means the vertex is unmarked. helps execute searching algorithm.
        std::string vertices[8];

    public:
        Graph();
        void addVertex(std::string label, int i);
        void addEdge(std::string from, std::string to);
        bool hasPath(std::string from, std::string to);
        int getVertexIndex(std::string label);
};

// Constructor - initializes all elements of the edges array to false.
Graph::Graph() {
    for (int i = 0; i < 8; i++) {
        marks[i] = false;
        for (int j = 0; j < 8; j++) {
            edges[i][j] = false;
        }
    }
}

// addVertex - accepts a label for a vertex and an index as it's only arguments.  Stores the label in the element of the vertices array at the indicated index.
void Graph::addVertex(std::string label, int i) {
    vertices[i] = label;
}

// addEdge - accepts two labels as it's only arguments.  It then calls the getVertexIndex method for each label to get indices to use with the edges array.  Sets the corresponding edges array element to true.
void Graph::addEdge(std::string from, std::string to) {
    int fromIndex = getVertexIndex(from);
    int toIndex = getVertexIndex(to);
    edges[fromIndex][toIndex] = true;
}

// hasPath - Accepts a starting vertex label and destination vertex label as it's only arguments. Performs either a depth-first search or a breadth-first search (your choice) to determine if a path exists between the two vertices. Returns true if a path was found, false otherwise.
bool Graph::hasPath(std::string from, std::string to) {
    int fromIndex = getVertexIndex(from);
    int toIndex = getVertexIndex(to);
    if (edges[fromIndex][toIndex] == true) {
        return true;
    } else {
        return false;
    }
}

// getVertexIndex - accepts a vertex label as it's only argument. Returns the index of the element in which it's found in the vertices array or -1 if it's not found.
int Graph::getVertexIndex(std::string label) {
    for (int i = 0; i < 8; i++) {
        if (vertices[i] == label) {
            return i;
        }
    }
    return -1;
}



#endif