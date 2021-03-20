//
//  algorithm.hpp
//  test
//
//  Created by Larry Park on 2020-10-13.
//

#pragma once

#include <stdio.h>
#include "node.cpp"
#include <map>

using namespace std;

#define R 5
#define C 5

class Algorithm {
private:
    std::shared_ptr<Node> startingPosition;
    std::shared_ptr<Node> finalPosition;
    
    
    
public:
    Algorithm();
    
    Algorithm(std::shared_ptr<Node> startingPosition);
    
    Algorithm(shared_ptr<Node> startingPosition, shared_ptr<Node> finalPosition);
    
    int breathFirstSearch(char maze[][C]);
    
    int aStarSearch(char maze[][C]);
    
    void setNeighbors(Node maze[][C], Node beginning, Node ending, int row, int col);
    
    int getDistance(const Node& start, const Node& end);
};



