#include "testlib.h"
#include<bits/stdc++.h>
using namespace std;


void writeTest(int test)
{
    startTest(test);
    cout << 1 << '\n';
}


int main(int argc, char* argv[])
{
    int tests = atoi(argv[1]);
    for (int i = 0; i < tests; i++)
        writeTest(i);
    return 0;
}
