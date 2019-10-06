/*
A system has R identical resources, P processes competing for them and N is the maximum need of each process. 
The task is to find the minimum number of Resources required So that deadlock will never occur.

R >= P * (N - 1) + 1 
*/


#include <bits/stdc++.h>
using namespace std;

// function that calculates
// the minimum no. of resources
int Resources(int process, int need)
{
    int minResources = 0;

    // Condition so that deadlock
    // will not occuur
    minResources = process * (need - 1) + 1;

    return minResources;
}

// Driver code
int main()
{

    int process , need ;
    cout<<"Enter the number of Process:";
    cin>>process;
    cout<<"Enter the maximum need for each process:";
    cin>>need;
    cout << "R >= " << Resources(process, need);
    return 0;
}
