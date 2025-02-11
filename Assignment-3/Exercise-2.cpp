// EXERCISE: 2
// There are n cars at given miles away from the starting mile 0, traveling to reach the mile target.
// You are given two integer array position and speed, both of length n, where position[i] is the starting mile of the ith car and speed[i] is the speed of the ith car in miles per hour.
// A car cannot pass another car, but it can catch up and then travel next to it at the speed of the slower car.
// A car fleet is a car or cars driving next to each other. The speed of the car fleet is the minimum speed of any car in the fleet.
// If a car catches up to a car fleet at the mile target, it will still be considered as part of the car fleet.
// Return the number of car fleets that will arrive at the destination.

// Constraints:
// n == position.length == speed.length
// 1 <= n <= 105
// 0 < target <= 106
// 0 <= position[i] < target
// All the values of position are unique.
// 0 < speed[i] <= 106

// Solution

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int carFleet(int target, vector<int>& position, vector<int>& speed) {
    int n = position.size();
    vector<pair<int, double>> cars;
    
    for (int i = 0; i < n; i++) {
        cars.push_back({position[i], (double)(target - position[i]) / speed[i]});
    }
    
    sort(cars.rbegin(), cars.rend());
    int fleets = 0;
    double maxTime = 0;
    
    for (auto& car : cars) {
        if (car.second > maxTime) {
            maxTime = car.second;
            fleets++;
        }
    }
    
    return fleets;
}

int main() {
    int target = 12;
    vector<int> position = {10, 8, 0, 5, 3};
    vector<int> speed = {2, 4, 1, 1, 3};
    cout << carFleet(target, position, speed) << endl;
    return 0;
}
