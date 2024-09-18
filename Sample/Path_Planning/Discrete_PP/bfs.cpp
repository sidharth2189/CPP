#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

// Map class
class Map {
public:
    const static int mapWidth = 6;
    const static int mapHeight = 5;
    vector<vector<int> > grid = {
        { 0, 1, 0, 0, 0, 0 },
        { 0, 1, 0, 0, 0, 0 },
        { 0, 1, 0, 0, 0, 0 },
        { 0, 1, 0, 0, 0, 0 },
        { 0, 0, 0, 1, 1, 0 }
    };
};

// Planner class
class Planner : Map {
public:
    int start[2] = { 0, 0 };
    int goal[2] = { mapHeight - 1, mapWidth - 1 };
    int cost = 1;

    string movements_arrows[4] = { "^", "<", "v", ">" };

    vector<vector<int> > movements{
        { -1, 0 },
        { 0, -1 },
        { 1, 0 },
        { 0, 1 }
    };
};

// Template function to print 2D vectors of any type
template <typename T>
void print2DVector(T Vec)
{
    for (int i = 0; i < Vec.size(); ++i) {
        for (int j = 0; j < Vec[0].size(); ++j) {
            cout << Vec[i][j] << ' ';
        }
        cout << endl;
    }
}

/*#### TODO: Code the search function which will generate the expansion list ####*/
// You are only required to print the final triplet values
void search(Map map, Planner planner)
{
    // Initial open list contains start position
    vector<vector<int>> open{{0, planner.start[0], planner.start[1]}};
     
    while (!open.empty())
    {
        // Expand first cell in open. If cell to be expanded is the goal, break.
        if ((open[0][1] == planner.goal[0]) && (open[0][2] == planner.goal[1]))
        {
            cout << open[0][0] << " " << open[0][1] << " " << open[0][2] << endl;
            break;
        }
        
        for (int i = 0; i < planner.movements.size(); i++)
        {        
            // Expand first element in open list
            int g = open[0][0] + planner.cost;
            int x = open[0][1] + planner.movements[i][0];
            int y = open[0][2] + planner.movements[i][1];
            vector<int> cell{g, x, y};
        
            // If explored cell is within grid, not closed and not already in open list, then add to open list.
            if ((x < map.mapHeight) && (x >= 0) && (y < map.mapWidth) && (y >= 0) && (map.grid[x][y] != 1) && 
            (find(open.begin(), open.end(), cell) == open.end()))
            {
                open.push_back(cell);
            }
        }
    
        // Remove expanded cell after exploration
        open.erase(open.begin());
    }

    // Roadblock
    if (open.empty())
    {
        cout << "Failed to reach the goal" << endl;
    }
}

int main()
{
    // Instantiate map and planner objects
    Map map;
    Planner planner;

    // Search for the expansions
    search(map, planner);

    return 0;
}
