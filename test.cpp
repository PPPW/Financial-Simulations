#include <iostream>
#include <vector>

using namespace std;

int fun(const vector<int>& intVec) {
    const vector<int>* intVecPrt;
    intVecPrt = &intVec;
    return 42;
}
int main() {
    vector<int> intVec(10, 1);    
    cout << fun(intVec) << endl;
}
