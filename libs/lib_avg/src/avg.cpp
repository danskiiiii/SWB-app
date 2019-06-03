#include "avg.h"
#include <iostream>
#include <vector>

using namespace std; 

float avg(vector<int> v)
{

    int sum = 0;
    for ( unsigned int i = 0; i < v.size(); i++){
        sum += v[i];
    }
    
    return float(sum) / v.size();
}