#include <iostream> 
#include <vector> 
using namespace std; 
  
int main() 
{ 
    string S = "ab##";
    vector<char> S_new(S.begin(), S.end()); 
    int count = S_new.size(), flag = 0, retrieve = 0;
    
    while (count > 0)
    {
        retrieve = 0;
        while (S_new[count-1] == '#' && count > 0)
        {
            if (count > 0) {S_new.erase(S_new.begin()+count-1);}
            else {S_new.clear();}
            count = S_new.size()-1;
            flag++;
        }
        while (flag != 0 && count >= 0) 
        {
            if (S_new.size() > 0) {S_new.erase(S_new.begin()+count-1);}
            else {S_new.clear();}
            count = S_new.size();
            flag--;
            retrieve = 1;
        }
        if (retrieve == 0) { if (count > 0) {count--;} }
    }
  
    // Printing the Vector
    if (!S_new.empty())
    {
        for (auto its = S_new.begin(); its != S_new.end(); ++its)
        {
            cout << *its << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "empty" << endl;
    }
    
    return 0;  
} 
