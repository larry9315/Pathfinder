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

    //uncomment to run and test!!!
    
//    breadth first search
//    Algorithm algo(std::make_shared<Node>(0, 0, 0, nullptr));
//    int length = algo.breathFirstSearch(grid);
//    cout << "Shortest distance length: " << length << endl;
    
    
//    a-star search
//    Algorithm algo(make_shared<Node>(0, 0), make_shared<Node>(2, 4));
//    algo.aStarSearch(grid);
    
    
    
    return 0;
}
