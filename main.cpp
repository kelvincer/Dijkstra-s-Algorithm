/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/*
 * File:   main.cpp
 * Author: kelvinc
 *
 * Created on 23 de mayo de 2024, 14:48
 */
#include <iostream>
#include <cstdlib>
#include <random>
#include <algorithm>
#include <set>
#include "Graph.h"
#include "PriorityQueue.h"
#include "ShortestPathAlgo.h"

using namespace std;

// Maximum number of nodes
const int max_nodes = 50;

// Get random cost for edges on graph beetwen [1 , 10]
int get_random_cost(int max) {
    random_device rd;
    default_random_engine engine{rd()};
    uniform_int_distribution<> distribution{1, max};
    return distribution(engine);
}

// Get random index for choosing node from set
int get_random_index(size_t size) {
    random_device rd;
    default_random_engine engine{rd()};
    uniform_int_distribution<> distribution{0, static_cast<int>(size - 1)};
    return distribution(engine);
}

// Main function
int main(int argc, char** argv) {
    
    // Create nodes
    set<Node> nodes;
    for (int i = 0; i < max_nodes; i++) {
        Node node = Node("N" + std::to_string(i));
        nodes.insert(node);
    }
    
    float densities[2] = {0.2, 0.4};
    for(float density: densities) {
        
        // Create edges randomly from selected density
        vector<Edge> edges;
        int total_edges = density * max_nodes * (max_nodes - 1);
        set<Node> connected_nodes;
        while (edges.size() < total_edges) {
            Node n1 = *std::next(nodes.begin(), get_random_index(nodes.size()));
            Node n2 = *std::next(nodes.begin(), get_random_index(nodes.size()));
            if (n1 != n2) {
                
                // Validate if edge have been created
                auto is_same_edge = [n1, n2](Edge edge) {
                    return (edge.get_start() == n1 && edge.get_end() == n2) ||
                    (edge.get_start() == n2 && edge.get_end() == n1);
                };
                if (std::find_if(edges.begin(), edges.end(), is_same_edge) != edges.end()) {
                    continue;
                }
                
                int cost = get_random_cost(10);
                
                // Push edge
                edges.push_back(Edge(n1, n2, cost));
                edges.push_back(Edge(n2, n1, cost));
                // Push node
                connected_nodes.insert(n1);
                connected_nodes.insert(n2);
            }
        }
        
        // Print graph on console
        cout << "Density: " << density;
        cout << endl <<"Graph:" << endl << endl;
        for (auto i = 0; i < edges.size(); i = i + 2) {
            cout << "\t" <<  edges.at(i).get_start() << " -- " << edges.at(i).get_end() << " = " << edges.at(i).get_cost() << endl;
        }
        
        // Get start and end node randomly
        Node start = *std::next(connected_nodes.begin(), get_random_index(connected_nodes.size()));
        Node end = *std::next(connected_nodes.begin(), get_random_index(connected_nodes.size()));
        
        // Create graph
        Graph graph = Graph(nodes, edges);
        // Create ShortestPathaAlgo
        ShortestPathAlgo spa = ShortestPathAlgo(graph);
        // Compute path
        auto path = spa.path(start, end);
        // Get distance
        auto distance = spa.path_size(start, end);
        
        // Print result
        int max_value = std::numeric_limits<int>::max();
        cout << endl << "Path from " << start.get_name() << " to " << end.get_name() << " is : " << path << (path.length() == 0 ? "No path" : "") << endl;
        cout << "Cost from " << start.get_name() << " to " << end.get_name() << " is : " << distance << (distance == max_value ? " (INF)" : "") << endl;
        
        cout << "===================================" << endl;
    }
    
    cout << endl << "This homework was thoughtful, it took me days to implement. I started to implement it by reading the algorithm in plain english, but I didn’t understand it well so after days of thinking I began to do research on the internet. I found several implementations of the Dijkstra algorithm with C++ and I chose one that helps me to implement the algorithm. After some effort I completed the homework. In summary I improved my understanding of the C++ programming language using the standard template library (vector, set, map) and creating my own classes. The program is running with 50 nodes and with densities pointed out by the teacher." << endl;
    
    return 0;
}


