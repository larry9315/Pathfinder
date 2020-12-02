//
//  node.cpp
//  test
//
//  Created by Larry Park on 2020-10-13.
//

#include <stdio.h>

class Node {
private:
    int row;
    int col;
    int distance;
    Node* prev;
    
    
    //starting node distance
    int gCost;
    //end node distance
    int hCost;
public:
    Node(){}
    
    Node(int row, int col, int distance, Node* node) {
        this->row = row;
        this->col = col;
        this->distance = distance;
        prev = node;
    }
    
    Node(int row, int col) {
        this->row = row;
        this->col = col;
    }
    
    void setRowCol(int row, int col) {
        this->row = row;
        this->col = col;
    }
    
    int getRow() const {
        return row;
    }
    
    int getCol() const {
        return col;
    }
    
    int getDistance() const {
        return distance;
    }
    
    Node* getPrev(){
        return prev;
    }
    
    void setPrev(Node* prev) {
        this->prev = prev;
    }
    
    void setGCost(int gCost) {
        this->gCost = gCost;
    }
    
    void setHCost(int hCost) {
        this->hCost = hCost;
    }
    
    int getGCost() const {
        return gCost;
    }
    
    int getHCost() const {
        return hCost;
    }
    
    void setDistance() {
        distance = gCost + hCost;
    }
    
    void operator = (const Node* node ) {
        row = node->row;
        col = node->col;
        prev = node->prev;
        
        gCost = node->gCost;
        hCost = node->hCost;
        distance = node->distance;
        
    }
    friend bool operator == (const Node& lhs, const Node& rhs) {
        return (lhs.row == rhs.row
                && lhs.col == rhs.col);
    }
    
    bool operator < (const Node& obj) const {
        return getDistance() < obj.getDistance()
        || (getDistance() == obj.getDistance() && hCost < obj.hCost);
    }
    
    
};

struct CompareDistance {
    bool operator() (const Node& n1, const Node& n2) {
        return n1.getDistance() > n2.getDistance();
    }
};
