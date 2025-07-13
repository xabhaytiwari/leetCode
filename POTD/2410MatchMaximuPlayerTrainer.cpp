#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*players = {4, 7, 9} trainers = {8, 2, 5, 8 }*/

class MatchPlayers {
    public:
        int maxMatches(vector<int> &players, vector<int> &trainers) {
            sort(players.begin(), players.end());
            sort(trainers.begin(), trainers.end());
            int i = 0, j = 0, m = players.size(), n = trainers.size();
            int countMatches = 0;
            
            // for(int i = 0; i < players.size(); i++) {
            //     for(int j = 0; j < trainers.size(); j++) {
            //         if(players[i] <= trainers[j]) {
            //             countMatches++;
            //             trainers[j] = -1;
            //             break;
            //         }
            //     }
            // }

            while(i < m && j < n) {
                if(players[i] > trainers[j]) {
                    j++;
                } else {
                    countMatches++;
                    i++;
                    j++;
                }
            }
            return countMatches;
        }
};

int main() {
    vector<int> players = {4, 7, 9};
    vector<int> trainers = {8, 2, 5, 8};
    MatchPlayers solution;
    cout << solution.maxMatches(players, trainers);
    return 0;
}