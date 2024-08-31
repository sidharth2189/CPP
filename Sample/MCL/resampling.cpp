#include <iostream>
#include <vector>
#include <numeric>
#include <math.h>

using namespace std;

vector<double> w = { 0.6, 1.2, 2.4, 0.6, 1.2 };

//TODO: Define a  ComputeProb function and compute the Probabilities
vector<double> ComputeProb(vector<double> weight)
    {
        // Calculates how likely a measurement should be
        vector<double> prob(weight.size(), 0.0);
        double sum_weight = accumulate(weight.begin(), weight.end(), 0.0);

        for (int i = 0; i < weight.size(); i++) {
            if (sum_weight != 0.0){
                prob[i] = weight[i]/sum_weight;
            }
            else {
                cout << "Sum of weight of particles is zero!" << endl;
                break;
            }
        }

        return prob;
    }


int main()
{
    //TODO: Print Probabilites each on a single line:
    vector<double> probabilities = ComputeProb(w);
    for (int i = 0; i < probabilities.size(); i++){
        cout << "P" << i+1 << "=" << probabilities[i] << endl;
    }
    
    return 0;
}
