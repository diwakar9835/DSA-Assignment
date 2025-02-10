// EXERCISE: 14
//  John is organizing a party at his house. For the party, he needs exactly N donuts for the guests. John decides to order the donuts from a nearby restaurant, which has L chefs and each chef has a rank R. 
// A chef with rank R can make 1 donut in the first R minutes, 1 more donut in the next 2R minutes, 1 more donut in 3R minutes, and so on.
// For example. a chef with rank 2, can make one donut in 2 minutes, one more donut in the next 4 minutes, and one more in the next 6 minutes. So, it take 2 + 4 + 6 = 12 minutes to make 3 donuts. A chef can move on to making the next donut only after completing the previous one. All the chefs can work simultaneously.
// Since, it's time for the party, John wants to know the minimum time required in completing N donuts. Return an integer denoting the minimum time.

// Solution

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int donutsInTime(int rank, int time) {
    int donuts = 0;
    int currentTime = rank;
    while (time >= currentTime) {
        donuts++;
        time -= currentTime;
        currentTime += rank;
    }
    return donuts;
}

bool canMakeDonutsInTime(vector<int>& ranks, int time, int N) {
    int totalDonuts = 0;
    for (int rank : ranks) {
        totalDonuts += donutsInTime(rank, time);
        if (totalDonuts >= N) return true;
    }
    return totalDonuts >= N;
}

int minTimeToMakeDonuts(vector<int>& ranks, int N) {
    int left = 1, right = 1000000000;
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        
        if (canMakeDonutsInTime(ranks, mid, N)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    
    return left;
}

int main() {
    int N = 10;
    int L = 3;
    vector<int> ranks = {1, 2, 3};
    
    cout << "Minimum time to make " << N << " donuts is: " << minTimeToMakeDonuts(ranks, N) << " minutes" << endl;
    return 0;
}
