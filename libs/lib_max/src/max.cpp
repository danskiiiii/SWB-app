#include "max.h"
#include <iostream>
#include <vector>

using namespace std;

int max(vector<int> v)
{
    int maximum = 0;
    for (unsigned int i = 0; i < v.size(); i++)
    {
        if(v[i] > maximum)
            maximum = v[i];
    }

    return maximum;
}