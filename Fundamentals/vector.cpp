/* Store data using vectors and print */

#include <iostream>
#include <vector>
using std::vector;
using std::cout;

int main() 
{
    // 1D Vector
	cout << "1D Vector" << '\n';
	vector<int> a = {0, 1, 2, 3, 4};
    for(int index = 0; index < a.size(); index++)
	{
		cout << a[index] << ' ';
	}
	
	cout << '\n';
	
	// 2D Vector
	cout << "2D Vector" << '\n';
	vector<vector<int>> b = {{1, 1, 2, 3},
                             {2, 1, 2, 3},
                             {3, 1, 2, 3}};
    for(int i = 0; i < b.size(); i++)
	{
		for(int j = 0; j < b[0].size(); j++)
		{
			cout << b[i][j] << ' ';
		}
		cout << '\n';
	}

	// Range based for loop
	cout << "Print container using range based for loop" << '\n';
	for (auto i : b)
	{
		for (int j : i)
		{
			cout << j << " ";
		}
		cout << '\n';
	}
}