#include <iostream>
#include <vector>
#include <queue>

using namespact std;

void findMaxDoors(vector<pair<double, double>> sched) {

    sort(sched.begin(), sched.end());

    

}


int main() {

    vector<pair<double,double>> sched = { (8.5,9), (8.25,10.5), (9,10), (7,9.5), (6.30, 7.40), (5.45,9.45) };
    findMaxDoors(sched);

    return 0;
}