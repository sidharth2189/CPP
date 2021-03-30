/*  
    Author: Sidharth Das
    March, 2021
    
    Implement a data model, which represents a 2D path of 
    variable length. Move the robot along a new path with 
    the folllowing data https://pastebin.com/raw/mLc80Pen. 
    Assume the robot has a square footprint. Write a function 
    which computes the total area that the robot 
    covers with its footprint while it travels the path. 
    
    The total area accumulates as the robot driving along the 
    path. The robot should provide the current accumulated 
    area while progressing the path, and then provide the 
    complete accumulated area covered along the whole path. 
    If the robot covers the same area at multiple time steps, 
    the redundant area should be reduced and only the effectively 
    new area should be counted. Moving the robot along the 
    path and calculating the current total covered area should 
    be done in two asynchronous threads, executing at reasonable 
    times per second. Make reasonable assumptions about the 
    information that you are missing and explain the assumptions. 
    
    Assumptions should be explained directly in the code. 
    Limitations with regards to edge cases should be very briefly described.

    Online compiler code ling: https://godbolt.org/z/Yahfdr4Er
*/

#include <iostream>
#include <future>
#include <vector>
#include <cmath>
#include <algorithm>

namespace AreaCalculatorApp
{
// Assume width of square robot is 5.0
constexpr float robot_width = 5.0;

// Point x, y
struct Points
{
    float x;
    float y;
};

// Vector of initial points
const std::vector<Points> points{
      {0.00359, -0.0013}, {0.00608, -0.00281},  {0.00756, -0.0027},
      {0.00842, -0.00307},  {0.00849, -0.0037},   {0.00846, -0.00387},
      {0.00829, -0.00379},  {0.0084, -0.00388},   {0.00846, -0.00409},
      {0.0138, -0.00347},   {0.0698, -0.00098},   {0.11151, -0.00745},
      {0.167, -0.01404},    {0.32572, -0.05356},  {0.41797, -0.07953},
      {0.52867, -0.11505},  {0.61002, -0.13945},  {0.63633, -0.14954},
      {0.70933, -0.18835},  {0.7191, -0.19822},   {0.72701, -0.20117},
      {0.731, -0.20424},    {0.73371, -0.20805},  {0.77746, -0.2621},
      {0.86029, -0.34734},  {0.88373, -0.37565},  {0.90413, -0.40655},
      {0.92189, -0.43795},  {0.93867, -0.47125},  {0.95337, -0.50479},
      {0.96615, -0.54003},  {0.97729, -0.57518},  {0.98669, -0.60948},
      {0.9944, -0.64442},   {0.99963, -0.67999},  {1.00244, -0.71709},
      {1.00327, -0.75302},  {0.99907, -0.78939},  {0.99464, -0.8237},
      {0.98722, -0.86223},  {0.97558, -0.90511},  {0.96147, -0.94947},
      {0.94402, -0.99336},  {0.92286, -1.03964},  {0.89779, -1.08594},
      {0.8698, -1.13096},   {0.73009, -1.33175},  {0.59053, -1.5304},
      {0.46166, -1.7128},   {0.30239, -1.93285},  {0.25147, -1.99011},
      {0.19826, -2.04254},  {0.14275, -2.09163},  {0.08663, -2.13425},
      {0.03116, -2.17209},  {-0.0238, -2.20402},  {-0.07864, -2.23286},
      {-0.1318, -2.25636},  {-0.1825, -2.27552},  {-0.23171, -2.29113},
      {-0.27795, -2.30206}, {-0.32673, -2.31054}, {-0.37225, -2.31536},
      {-0.41574, -2.31996}, {-0.45496, -2.32042}, {-0.48902, -2.31757},
      {-0.52496, -2.3164},  {-0.55811, -2.31102}, {-0.77049, -2.25292},
      {-0.99, -2.19669},    {-1.19266, -2.14085}, {-1.23428, -2.12438},
      {-1.27377, -2.10614}, {-1.31327, -2.08351}, {-1.39679, -2.03016},
      {-1.48345, -1.95929}, {-1.52353, -1.91628}, {-1.66757, -1.77012},
      {-1.83468, -1.60606}, {-2.01648, -1.41688}, {-2.18845, -1.20596},
      {-2.35403, -0.99207}, {-2.44666, -0.84068}, {-2.48383, -0.76261},
      {-2.51504, -0.68854}, {-2.53995, -0.61543}, {-2.56026, -0.54313},
      {-2.57583, -0.47095}, {-2.58632, -0.40214}, {-2.5929, -0.33388},
      {-2.59584, -0.2669},  {-2.5965, -0.20323},  {-2.59088, -0.13817},
      {-2.58415, -0.07689}, {-2.57404, -0.0163},  {-2.55813, 0.04199},
      {-2.5374, 0.10109},   {-2.51245, 0.15825},  {-2.48738, 0.21222},
      {-2.45803, 0.26488},  {-2.42471, 0.314},    {-2.38647, 0.36297},
      {-2.3471, 0.40819},   {-2.30357, 0.45124},  {-2.1598, 0.59651},
      {-1.99623, 0.75884},  {-1.84116, 0.91525},  {-1.68546, 1.07255},
      {-1.57778, 1.17373}};

// Vector of traversed points
std::vector<Points>  traversal_points;

// Variable for area at each step
static float area;

// Index of traversed points 
static int index;

// Is area calculation applicable
static bool isCalculateArea = false;

// Area calculation
class AreaCalculator
{
// Count of repetition given point
// in traversal point inside index
int count_point(Points point)
{
    std::vector<Points>::iterator ptr;
    int count = 0;
    for (ptr = traversal_points.begin(); 
            ptr < (traversal_points.begin() + index); ptr++)
        {
            if (ptr->x == point.x && ptr->y == point.y)
            {
                count++;
            }
        }
    return count;
}

// Check if iterator is an occurence of current point
bool isSamePoint (std::vector<Points>::iterator iter)
{
    // Current point
    Points current_point = traversal_points.at(index-1);
    if (iter->x == current_point.x && iter->y == current_point.y)
    {
        return true;
    }
    return false;
}

// Neighbour of a current point
bool notNeighbour()
{
    // Initialize variable
    bool is_not_neighbour = false;

    // Next point
    Points next_point = traversal_points.at(index);

    // Current point
    Points current_point = traversal_points.at(index-1);

    // Point before current point
    Points bfr_current_point = traversal_points.at(index-2);

    // Count of repetition of current point
    int count_current = count_point(current_point);

    // Single occurrence of current point
    if(count_current == 1 &&
        bfr_current_point.x != next_point.x && 
        bfr_current_point.y != next_point.y)
    {
        is_not_neighbour = true;
    }

    // Multiple occurrence of current point
    else if(count_current > 1)
    {
        // Find indices of occurence of current point in traversal_points
        std::vector<int> current_instance_indices;
        std::vector<Points>::iterator iter = traversal_points.begin();
        while (iter != traversal_points.begin()+index)
        {
            if (isSamePoint(iter))
            {
                current_instance_indices.push_back(
                    std::distance(traversal_points.begin(), iter));
            }
            iter++;
        }
        
        is_not_neighbour = true;
        for (int i = 0; i < current_instance_indices.size(); i++)
        {
            // Current index
            int curr_index = current_instance_indices.at(i);
            if (curr_index == 0)
            {
                if (traversal_points.at(curr_index+1).x == next_point.x &&
                    traversal_points.at(curr_index+1).y == next_point.y)
                    {
                        is_not_neighbour = false;
                    }
            }
            else if (curr_index > 0 && curr_index < index)
            {
                if (traversal_points.at(curr_index+1).x == next_point.x &&
                    traversal_points.at(curr_index+1).y == next_point.y &&
                    traversal_points.at(curr_index-1).x == next_point.x &&
                    traversal_points.at(curr_index-1).y == next_point.y)
                    {
                        is_not_neighbour = false;
                    }
            }
        }
    }
    
    return is_not_neighbour;
}

// Euclidean distance between two points
float eucledianDist(Points p1, Points p2)
{
    return pow(pow((p1.x - p2.x),2) + pow((p1.y - p2.y),2), 0.5);
}

// Function to determine case of area calculation
int areaValidator()
{
    // Intitate area case variable
    int area_case = -1;

    // Count of repetition of next point (index) in traversal_points
    int count_next = count_point(traversal_points.at(index));
    
    /*
        Consider last two points in the list traversal_points
        till the index
        -> Point before index is current point
        -> Point at index is next point
    */
    /*
        case0: if only one point in traversal list till index
        case1: if point_next is previously not in traversal 
        list till index, where the traversal list till index 
        has two or more points
        case2: if point_next is already present in 
        traversal_list till index and not a neighbour 
        of point_current (from traversal_list till index)
        NOTE: Neighbour of a current point A is a point 
        before point A in the traversal_list or points 
        before/after previous instance (if any) of point A 
        in traversal_list till index
    */
    if (index == 0)
    {
        area_case = 0;
    }
    else if (index > 0 && count_next == 0)
    {
        area_case = 1;
    }
    else if(count_next > 0 && notNeighbour())
    {
        area_case = 2;
    }

    // Return area case
    return area_case;
}

public:
// Area calculator
void calculateArea()
{
    while(index < points.size())
    {
       if(isCalculateArea)
       {
           // Determine which case of area calculation
           int area_case = areaValidator();

           // Initiate area move for current step
           float area_step = 0.0;

           if(area_case == 0)
           {
               // area occupied by still robot
               area_step = pow(robot_width, 2);
           }
           else if (area_case == 1)
           {
               Points next_point = traversal_points.at(index);
               Points current_point = traversal_points.at(index-1);
   
               // calculate area swept between two points
               area_step = eucledianDist(current_point, next_point) * robot_width;
           }
           else if (area_case == 2)
           {
               Points next_point = traversal_points.at(index);
               Points current_point = traversal_points.at(index-1);
               
               // subtract area of robot on pre-traversed point
               area_step = eucledianDist(current_point, next_point) * robot_width - 
                           pow(robot_width, 2);
           }

           // Total area
           area= area + area_step;

           // Print area
           std::cout << "The updated area is " << area << std::endl;

           // Increment index of traversal point
           index++;
       }
       else
       {
           std::cout << "The area is " << area <<std::endl;
       }
    }
}

// Get function for area
float getArea()
{
    return area;
}
};

// Robot movement
class RobotMover
{
public:
void traverseRobot()
{
    // Move robot
    for (int i = 0 ; i < points.size() ; i++)
    {
        // Add point to traversed list after robot moves
        traversal_points.push_back(points.at(i));

        // Print point
        std::cout << points.at(i).x << points.at(i).y << std::endl;

        // If point is added
        if (i)
        {
            isCalculateArea = true;
        }
        else
        {
            isCalculateArea = false;
        }
    }
}
};
} // AreaCalculatorApp

int main()
{
    // Instances
    AreaCalculatorApp::RobotMover rm;

    // Move robot
    rm.traverseRobot();

    // Calculate area in a thread   
    std::thread areaCalc(&AreaCalculatorApp::AreaCalculator::calculateArea, 
                            AreaCalculatorApp::AreaCalculator());

    areaCalc.join();

    // Print cumulative area after completion
    std::cout << "the final area is " << 
        AreaCalculatorApp::AreaCalculator().getArea();
}
