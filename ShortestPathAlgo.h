#ifndef SHORTESTPATHALGO_H
#define SHORTESTPATHALGO_H

#include <vector>
#include <map>
#include <limits>
#include "PriorityQueue.h"
#include "Graph.h"

// ShortestPathAlgo Class
class ShortestPathAlgo {
public:
    
    // Constructor
    ShortestPathAlgo(Graph graph): graph{graph}
    {
        
    }
    
    // From my point of view this method is not useful, graph has nodes
    void vertices(std::vector<Node> nodes) {
        
    }
    
    // Compute the path from node u to node w
    std::string path(Node u, Node w) {
        
        // If they are the same node
        if(u == w) {
            cost = 0;
            return "";
        }
        
        // Create map of costs, with distance to u equal to 0
        std::map<std::string, int> distancesMap;
        auto nodes = graph.get_nodes();
        for (auto it = nodes.begin(); it != nodes.end(); it++) {
            if (*it == u) {
                distancesMap[u.get_name()] = 0;
            } else {
                distancesMap[(*it).get_name()] = std::numeric_limits<int>::max();
            }
        }
        // Init priority queue
        auto priority_queue = PriorityQueue();
        priority_queue.insert(Element(u, 0));
        
        // Map to save the paths to nodes
        std::map<std::string, std::string> paths;
        paths[u.get_name()] = u.get_name();
        
        while (priority_queue.size() > 0) {
            
            // Get node with minimum priority
            auto node = priority_queue.min_priority().get_node();
            
            // Get adjacents edges of node
            auto edges = graph.get_adjacent_edges(node);
            
            // Iterate over the adjacents edges
            for(auto it = edges.begin(); it != edges.end();  it++) {
                auto end = (*it).get_end();
                int cost = (*it).get_cost();
                
                // Validate if cost of end node is greater than initial node plus cost
                if (distancesMap[end.get_name()] > distancesMap[node.get_name()] + cost) {
                    // Assign new cost to end node
                    distancesMap[end.get_name()] = distancesMap[node.get_name()] + cost;
                    
                    // Insert to queue new element with new priority
                    priority_queue.insert(Element(end, distancesMap[end.get_name()]));
                    
                    // Assing updated path to node end
                    paths[end.get_name()] = paths[node.get_name()] + " -> " + end.get_name();
                }
            }
        }
        
        // Get the shortest distance
        cost = distancesMap[w.get_name()];
        
        // Return path to node w
        return paths[w.get_name()];
    }
    
    // Get path cost
    int path_size(Node u, Node w) {
        return cost;
    }
    
private:
    Graph graph;
    int cost;
};

#endif /* SHORTESTPATHALGO_H */

