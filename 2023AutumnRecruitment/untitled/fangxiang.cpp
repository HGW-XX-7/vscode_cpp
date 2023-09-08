#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

vector<string> dirReduc(const vector<string>& directions) {
    stack<string> path;
    
    for (const auto& dir : directions) {
        if (!path.empty() && 
            ((dir == "NORTH" && path.top() == "SOUTH") || 
            (dir == "SOUTH" && path.top() == "NORTH") || 
            (dir == "EAST" && path.top() == "WEST") || 
            (dir == "WEST" && path.top() == "EAST"))) {
            
            path.pop();
        } else if (!path.empty() && dir == path.top()) {
            path.pop(); // Remove adjacent duplicate directions
        } else {
            path.push(dir);
        }
    }
    
    vector<string> simplifiedPath;
    
    while (!path.empty()) {
        simplifiedPath.push_back(path.top());
        path.pop();
    }
    
    reverse(simplifiedPath.begin(), simplifiedPath.end());
    
    return simplifiedPath;
}


int main() {
    std::vector<std::string> directions = {"NORTH", "SOUTH","SOUTH","EAST", "WEST", "NORTH", "WEST"};
    std::vector<std::string> simplifiedDirections = dirReduc(directions);

    for (const auto& direction : simplifiedDirections) {
        std::cout << direction << " ";
    }
    std::cout << std::endl;

    return 0;
}