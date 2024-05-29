#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <string>
#include <set>

// Node class
class Node {
public:
    // Constructor
    Node(std::string name): name{name} {
    }
    
    // Get node identifier
    std::string get_name() const {
        return name;
    }
    
    // Set node identifier
    void set_name(std::string name) {
        this->name = name;
    }
    
    bool operator==(Node other) const {
        return other.name.compare(name) == 0;
    }
    
    bool operator!=(Node other) {
        return other.name.compare(name) != 0;
    }
    
    friend std::ostream& operator<<(std::ostream& os, const Node& node) {
        os << node.get_name();
        return os;
    }
    
    bool operator<(const Node& node) const {
        return name < node.get_name();
    }
    
private:
    std::string name;
};

// Edge Class
class Edge {
public:
    
    // Constructor
    Edge(Node start, Node end, int cost) : start{start}, end{end}, cost{cost}
    {
    }
    
    // Get edge start node
    Node get_start() const {
        return start;
    }
    
    // Get edge end node
    Node get_end() const {
        return end;
    }
    
    // Get cost of edge
    float get_cost() const {
        return cost;
    }
    
    // Set cost of edge
    void set_cost(float cost) {
        this->cost = cost;
    }
    
private:
    Node start;
    Node end;
    int cost;
};

// Graph Class
class Graph {
public:
    
    // Constructor
    Graph(std::set<Node> nodes, std::vector<Edge> edges) : nodes{nodes}, edges{edges} {
        
    }
    
    // Get nodes size
    size_t v() {
        return nodes.size();
    }
    
    // Get edges size
    size_t e() {
        return edges.size();
    }
    
    // Validate if node x and node y are adjacents
    bool adjacent(Node x, Node y) {
        for (const auto & e : edges) {
            if (e.get_start() == x && e.get_end() == y) {
                return true;
            }
        }
        return false;
    }
    
    // Get neighbors of node x
    std::vector<Node> neighbors(Node x) {
        
        std::vector<Node> neighbors;
        
        for (const auto & e : edges) {
            if (x == e.get_start()) {
                neighbors.push_back(e.get_end());
            }
        }
        return neighbors;
    }
    
    // Add new edge to graph
    void add(Node x, Node y, int cost) {
        edges.push_back(Edge{x, y, cost});
    }
    
    // Delete an edge
    void delete_edge(Node x, Node y) {
        for (auto it = edges.begin(); it != edges.end(); it++) {
            if (x == it->get_start() && y == it->get_end()) {
                edges.erase(it);
            }
        }
    }
    
    // Get node identifier
    std::string get_node_value(Node x) {
        return x.get_name();
    }
    
    // Set node identifier
    void set_node_value(Node x, std::string a) {
        x.set_name(a);
    }
    
    // Get edge cost
    int get_edge_value(Node x, Node y) {
        for (auto & e : edges) {
            if (e.get_start() == x && e.get_end() == y) {
                return e.get_cost();
            }
        }
        return 0;
    }
    
    // Set edge cost
    void set_edge_value(Node x, Node y, float v) {
        for (auto & e : edges) {
            if (e.get_start() == x && e.get_end() == y) {
                return e.set_cost(v);
            }
        }
    }
    
    // Get nodes
    std::set<Node> get_nodes() {
        return nodes;
    }
    
    // Get adjacents edges of node
    std::vector<Edge> get_adjacent_edges(Node node) {
        std::vector<Edge> edges;
        
        for (const auto & e : this->edges) {
            if (node == e.get_start()) {
                edges.push_back(e);
            }
        }
        return edges;
    }
    
private:
    std::set<Node> nodes;
    std::vector<Edge> edges;
};

#endif

