//
//  algorithm.cpp
//  test
//
//  Created by Larry Park on 2020-10-13.
//

#include "algorithm.hpp"
#include <queue>
#include <iostream>
#include <cmath>
#include <unordered_map>


using namespace std;



Algorithm::Algorithm(){}

Algorithm::Algorithm (shared_ptr<Node> startingPosition) {
    this->startingPosition = startingPosition;
    
}

Algorithm::Algorithm(shared_ptr<Node> startingPosition, shared_ptr<Node> finalPosition) {
    this->startingPosition = startingPosition;
    this->finalPosition = finalPosition;
}

int Algorithm::breathFirstSearch(char maze[][C]) {
    
    bool visited[R][C];
    
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (maze[i][j] == '0') {
                visited[i][j] = true;
            } else {
                visited[i][j] = false;
            }
        }
    }

    queue<shared_ptr<Node>> myQueue;
    
    myQueue.push(startingPosition);
    visited[startingPosition->getRow()][startingPosition->getCol()] = true;
    
    
    
    
    while (!myQueue.empty()) {
        
        shared_ptr<Node> temp = myQueue.front();
        
        if (maze[temp->getRow()][temp->getCol()] == 'd') {
            int distance = temp->getDistance();
            while (temp->getPrev() != nullptr) {
                cout << "temp row: " << temp->getRow() << " temp col: " << temp->getCol() << endl;
                
                temp = temp->getPrev();
            }
            return distance;
        }
        
        myQueue.pop();
        
        if (temp->getRow() - 1 >= 0
            && visited[temp->getRow() - 1][temp->getCol()] == false) {
            
            shared_ptr<Node> nodePtr = make_shared<Node>(temp->getRow() - 1, temp->getCol(), temp->getDistance() + 1, temp);
            myQueue.push(nodePtr);
            visited[temp->getRow() - 1][temp->getCol()] = true;
        }
        
        if (temp->getRow() + 1 < R
            && visited[temp->getRow() + 1][temp->getCol()] == false) {

            shared_ptr<Node> nodePtr = make_shared<Node>(temp->getRow() + 1, temp->getCol(), temp->getDistance() + 1, temp);
            myQueue.push(nodePtr);
            visited[temp->getRow() + 1][temp->getCol()] = true;
        }

        if (temp->getCol() - 1 >= 0
            && visited[temp->getRow()][temp->getCol() - 1] == false) {
            
            shared_ptr<Node> nodePtr = make_shared<Node>(temp->getRow(), temp->getCol() - 1, temp->getDistance() + 1, temp);
            myQueue.push(nodePtr);
            visited[temp->getRow()][temp->getCol() - 1] = true;
        }

        if (temp->getCol() + 1 < C
            && visited[temp->getRow()][temp->getCol() + 1] == false) {
            
            shared_ptr<Node> nodePtr = make_shared<Node>(temp->getRow(), temp->getCol() + 1, temp->getDistance() + 1, temp);
            myQueue.push(nodePtr);
            visited[temp->getRow()][temp->getCol() + 1] = true;
        }
        
    }
    
    
    return -1;
}

int Algorithm::aStarSearch(char maze[][C]) {
    map<Node, int> open;
    map<Node, int> closed;
    Node grid[R][C];
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            
            
            int tempGCost = abs((startingPosition->getRow() - i)) + abs((startingPosition->getCol() - j));
            int tempHCost = abs((finalPosition->getRow() - i)) + abs((finalPosition->getCol() - j));
            grid[i][j].setRowCol(i, j);
            grid[i][j].setGCost(tempGCost);
            grid[i][j].setHCost(tempHCost);
            grid[i][j].setDistance();
            
            
        }
    }
                
    
    
    //start
    
    Node current = grid[startingPosition->getRow()][startingPosition->getCol()];

    grid[current.getRow()][current.getCol()].setGCost(0);
    grid[current.getRow()][current.getCol()].setHCost(getDistance(current, *finalPosition));
    grid[current.getRow()][current.getCol()].setDistance();

    shared_ptr<Node> ptr = make_shared<Node>(startingPosition->getRow(), startingPosition->getCol(), grid[startingPosition->getRow()][startingPosition->getCol()].getDistance(), nullptr);
    grid[startingPosition->getRow()][startingPosition->getCol()].setPrev(ptr);

    open.insert(make_pair(grid[current.getRow()][current.getCol()], 0));
    cout << endl;
    
    
    
    while (open.size() > 0) {

        current = open.begin()->first;
        open.erase(current);
        closed[current] = 0;


        if (current == grid[finalPosition->getRow()][finalPosition->getCol()]) {
            
            shared_ptr<Node> temp = make_shared<Node>(current.getRow(), current.getCol(), current.getDistance(), current.getPrev());
            shared_ptr<Node> status = temp;
            
            while (status->getPrev() != nullptr) {

                status = status->getPrev();
                cout << "temp row: " << status->getRow() << " temp col: " << status->getCol() << endl;
            }

            break;
        }

        int distance = grid[current.getRow()][current.getCol()].getGCost()
                            + getDistance(current, grid[current.getRow() - 1][current.getCol()]);
        if (current.getRow() - 1 >= 0
            && closed.find(grid[current.getRow() - 1][current.getCol()]) == closed.end()
            && maze[current.getRow() - 1][current.getCol()] != '0') {
            if (distance < grid[current.getRow() - 1][current.getCol()].getGCost() ||
                open.find(grid[current.getRow() - 1][current.getCol()]) == open.end()) {

                    grid[current.getRow() - 1][current.getCol()].setRowCol(current.getRow() - 1, current.getCol());
                    grid[current.getRow() - 1][current.getCol()].setGCost(distance);
                    grid[current.getRow() - 1][current.getCol()].setHCost(getDistance(grid[current.getRow() - 1][current.getCol()], *finalPosition));
                    grid[current.getRow() - 1][current.getCol()].setDistance();

                    shared_ptr<Node> ptr = make_shared<Node>(current.getRow() - 1, current.getCol(), grid[current.getRow() - 1][current.getCol()].getDistance(), current.getPrev());
                    grid[current.getRow() - 1][current.getCol()].setPrev(ptr);

                    if (open.find(grid[current.getRow() - 1][current.getCol()]) == open.end()) {
                        open.insert(make_pair(grid[current.getRow() - 1][current.getCol()], 0));
                    }

            }
        }

        distance = grid[current.getRow()][current.getCol()].getGCost()
                    + getDistance(current, grid[current.getRow() + 1][current.getCol()]);
        if (current.getRow() + 1 < R
            && closed.find(grid[current.getRow() + 1][current.getCol()]) == closed.end()
            && maze[current.getRow() + 1][current.getCol()] != '0') {
            if (distance < grid[current.getRow() + 1][current.getCol()].getGCost() ||
                open.find(grid[current.getRow() + 1][current.getCol()]) == open.end()) {

                    grid[current.getRow() + 1][current.getCol()].setRowCol(current.getRow() + 1, current.getCol());
                    grid[current.getRow() + 1][current.getCol()].setGCost(distance);
                    grid[current.getRow() + 1][current.getCol()].setHCost(getDistance(grid[current.getRow() + 1][current.getCol()], *finalPosition));
                    grid[current.getRow() + 1][current.getCol()].setDistance();

                    shared_ptr<Node> ptr = make_shared<Node>(current.getRow() + 1, current.getCol(), grid[current.getRow() + 1][current.getCol()].getDistance(), current.getPrev());
                    grid[current.getRow() + 1][current.getCol()].setPrev(ptr);

                    if (open.find(grid[current.getRow() + 1][current.getCol()]) == open.end()) {
                        open.insert(make_pair(grid[current.getRow() + 1][current.getCol()], 0));
                    }
            }
        }

        distance = grid[current.getRow()][current.getCol()].getGCost()
                    + getDistance(current, grid[current.getRow()][current.getCol() - 1]);
        if (current.getCol() - 1 >= 0
            && closed.find(grid[current.getRow()][current.getCol() - 1]) == closed.end()
            && maze[current.getRow()][current.getCol() - 1] != '0') {
            if (distance < grid[current.getRow()][current.getCol() - 1].getGCost() ||
                open.find(grid[current.getRow()][current.getCol() - 1]) == open.end()) {

                    grid[current.getRow()][current.getCol() - 1].setRowCol(current.getRow(), current.getCol() - 1);
                    grid[current.getRow()][current.getCol() - 1].setGCost(distance);
                    grid[current.getRow()][current.getCol() - 1].setHCost(getDistance(grid[current.getRow()][current.getCol() - 1], *finalPosition));
                    grid[current.getRow()][current.getCol() - 1].setDistance();

                    shared_ptr<Node> ptr = make_shared<Node>(current.getRow(), current.getCol() - 1, grid[current.getRow()][current.getCol() - 1].getDistance(), current.getPrev());
                    grid[current.getRow()][current.getCol() - 1].setPrev(ptr);

                    if (open.find(grid[current.getRow()][current.getCol() - 1]) == open.end()) {
                        open.insert(make_pair(grid[current.getRow()][current.getCol() - 1], 0));
                    }
            }
        }

        distance = grid[current.getRow()][current.getCol()].getGCost()
                    + getDistance(current, grid[current.getRow()][current.getCol() + 1]);
        if (current.getCol() + 1 < C
            && closed.find(grid[current.getRow()][current.getCol() + 1]) == closed.end()
            && maze[current.getRow()][current.getCol() + 1] != '0') {
            if (distance < grid[current.getRow()][current.getCol() + 1].getGCost() ||
                open.find(grid[current.getRow()][current.getCol() + 1]) == open.end()) {

                    grid[current.getRow()][current.getCol() + 1].setRowCol(current.getRow(), current.getCol() + 1);
                    grid[current.getRow()][current.getCol() + 1].setGCost(distance);
                    grid[current.getRow()][current.getCol() + 1].setHCost(getDistance(grid[current.getRow()][current.getCol() + 1], *finalPosition));
                    grid[current.getRow()][current.getCol() + 1].setDistance();

                    shared_ptr<Node> ptr = make_shared<Node>(current.getRow(), current.getCol() + 1, grid[current.getRow()][current.getCol() + 1].getDistance(), current.getPrev());
                    grid[current.getRow()][current.getCol() + 1].setPrev(ptr);

                    if (open.find(grid[current.getRow()][current.getCol() + 1]) == open.end()) {
                        open.insert(make_pair(grid[current.getRow()][current.getCol() + 1], 0));
                    }
            }
        }

    }
    
    
    return -1;
}



int Algorithm::getDistance(const Node& start, const Node& end) {
    int xDistance = abs(start.getCol() - end.getCol());
    int yDistance = abs(start.getRow() - end.getRow());

    return xDistance + yDistance;
}

