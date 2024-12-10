// calculate execution time
//#include "helper"
#include <iostream>
#include <chrono>

using namespace std;

typedef chrono::microseconds uSEC;
typedef chrono::high_resolution_clock HRC;
uSEC start;
uSEC endTime;

void startTimerInMicroSeconds()
{
    auto start = HRC::now();
}

void stopTimerInMicroSeconds()
{
    auto endTime = HRC::now();
}

auto getEcecTimeInMicroSeconds()
{
    auto exec_time = chrono::duration_cast<uSEC>(endTime-start);
    return exec_time.count(); 
}

/* Test Code 
int main ()
{
    auto start = HRC::now();
    // write logic between start and end
    for(int i=0; i<1000; i++)
    {
        cout<<i<<endl;
    }
    auto end = HRC::now();
    auto exec_time = chrono::duration_cast<uSEC>(end-start);

    // print execution time
    cout<< "Execution Time: " << exec_time.count() << "us" <<endl;

    return 0;
}
*/