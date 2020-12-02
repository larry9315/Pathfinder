//
//  main.cpp
//  test
//
//  Created by Larry Park on 2020-10-12.
//

#include <iostream>
#include "algorithm.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    char grid[R][C] = { { 's', '*', '0', '*', '*' },
                        { '*', '*', '0', '*', '*' },
                        { '*', '*', '0', '*', 'd' },
                        { '*', '*', '0', '*', '*' },
                        { '*', '*', '*', '*', '*' }
    };
    
    
//    breadth first search
//    Algorithm algo(Node(3, 2, 0, NULL), Node (0, 2, 0, NULL));
//    cout << algo.breathFirstSearch(grid) << endl;
    
//    a-star search
    Algorithm algo(Node(0,0), Node(2, 4));

    algo.aStarSearch(grid);
    
    
    
    return 0;
}
