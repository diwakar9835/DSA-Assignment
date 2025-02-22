// EXERCISE: 20

// In a town, there are n people labeled from 1 to n. There is a rumor that one of these people is secretly the town judge.
// If the town judge exists, then:
// The town judge trusts nobody.
// Everybody (except for the town judge) trusts the town judge.
// There is exactly one person that satisfies properties 1 and 2.
// You are given an array trust where trust[i] = [ai, bi] representing that the person labeled ai trusts the person labeled bi. If a trust relationship does not exist in trust array, then such a trust relationship does not exist.
// Return the label of the town judge if the town judge exists and can be identified, or return -1 otherwise.
// Constraints:
// 1 <= n <= 1000
// 0 <= trust.length <= 104
// trust[i].length == 2
// All the pairs of trust are unique.
// ai != bi
// 1 <= ai , bi <= n

// Solution

#include <iostream>

using namespace std;

int findJudge(int n, int trust[][2], int trustSize) {
    int trustCount[n + 1] = {0};
    int trustedBy[n + 1] = {0};

    for (int i = 0; i < trustSize; i++) {
        int a = trust[i][0];
        int b = trust[i][1];
        trustCount[a]++;
        trustedBy[b]++;
    }

    for (int i = 1; i <= n; i++) {
        if (trustCount[i] == 0 && trustedBy[i] == n - 1) {
            return i;
        }
    }
    return -1;
}

int main() {
    int n, trustSize;
    cin >> n >> trustSize;
    int trust[trustSize][2];
    for (int i = 0; i < trustSize; i++) {
        cin >> trust[i][0] >> trust[i][1];
    }
    cout << findJudge(n, trust, trustSize);
    return 0;
}
