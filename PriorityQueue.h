//
//  PQ.h
//  Dijkstra's Algorithm
//
//  Created by kelvin cervan ruiz on 27/05/24.
//

#ifndef PQ_h
#define PQ_h

#include "Graph.h"

// Class Element for using on priority queue
class Element {
public:
    // Constructor
    Element(Node node, int priority): node{node}, priority{priority} {
        
    }
    
    // Get priority
    int get_priority() const {
        return priority;
    }
    
    // Get Node
    Node get_node() const {
        return node;
    }
    
    // Set priority
    void set_priority(int priority) {
        this->priority = priority;
    }
    
    // Set node
    void set_node(Node node) {
        this->node = node;
    }
    
private:
    int priority;
    Node node;
};

// Priority Queue class
class PriorityQueue {
public:
    
    // Constructor
    PriorityQueue() {
        
    }
    
    // Change priority
    void chgPriority(Element element, int priority) {
        element.set_priority(priority);
    }
    
    // Get minimum priority
    Element min_priority() {
        std::vector<Element>::iterator iterator = get_top_iterator();
        Element copy = *iterator;
        queue.erase(iterator);
        return copy;
    }
    
    // Validate iff element is in queue
    bool contains(Element queue_element) {
        for (auto & e : queue) {
            if (e.get_node() == queue_element.get_node()) {
                return true;
            }
        }
        return false;
    }
    
    // Insert new element to queue
    void insert(Element queue_element) {
        queue.push_back(queue_element);
    }
    
    // Get minimum element without deleting it
    Element top() {
        std::vector<Element>::iterator iterator = get_top_iterator();
        return *iterator;
    }
    
    // Get queue size
    size_t size() {
        return queue.size();
    }
    
private:
    std::vector<Element> queue;
    
    // Get element with minimum priority
    std::vector<Element>::iterator get_top_iterator() {
        int max_value = std::numeric_limits<int>::max();
        std::vector<Element>::iterator iterator;
        
        for (auto it = queue.begin(); it != queue.end(); it++) {
            if (it->get_priority() < max_value) {
                iterator = it;
                max_value = it->get_priority();
            }
        }
        return iterator;
    }
};

#endif /* PQ_h */
