#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// given schedules for trucks at a warehouse, where each schedule has the start, end time
// find the maximum of warehouse doors that need to be operated during a particula day
int findMaxDoors(vector<pair<double,double>> sched) {

    using schedule = pair<double,double>;
    int maxDoor = 0;
    auto cmp = [](schedule left, schedule right) { 
        return (left.second) > (right.second);
    };
    priority_queue<schedule, vector<schedule>, decltype(cmp)> pq(cmp);
    sort(sched.begin(), sched.end());
    for (auto it = sched.begin(); it!=sched.end(); it++) {
        if (pq.empty()) {
             pq.push(*it);
        } else {
            schedule temp=pq.top();
            if (it->first > temp.second) {
                pq.pop();
            }
            pq.push(*it);
            maxDoor = max((int)pq.size(), maxDoor);
        }
    }
    return maxDoor;
}


int main() {

    vector<pair<double,double>> sched = { make_pair(8.5,9.1), make_pair(8.25,10.5), 
                        make_pair(9.0,10.0), make_pair(7.0,9.5), make_pair(6.30, 7.40), make_pair(5.45,9.45) ,
                        make_pair(8.0,9.30), make_pair(7.30,8.30), make_pair(7.45, 8.45), make_pair(8.25, 9.35) };
    int d = findMaxDoors(sched);
    cout << d << endl;

    return 0;
}