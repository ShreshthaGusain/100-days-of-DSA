// Day 74 - Question 1: Winner of an Election
// Close
// Problem Statement
// Given an array of candidate names where each name represents a vote cast for that candidate, determine the candidate who received the maximum number of votes. In case of a tie, return the lexicographically smallest candidate name.

// Input Format
// First line contains an integer n representing number of votes.
// Second line contains n space-separated strings representing candidate names.

// Output Format
// Print the name of the winning candidate followed by the number of votes received.

// Sample Input
// 13
// john johnny jackie johnny john jackie jamie jamie john johnny jamie johnny john

// Sample Output
// john 4

// Explanation
// Both john and johnny receive 4 votes, but john is lexicographically smaller, so john is declared the winner.

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

void findWinner(int n, vector<string>& votes) {
    unordered_map<string, int> voteCount;

    // 1. Fill the Hash Map with counts
    for (const string& name : votes) {
        voteCount[name]++;
    }

    string winner = "";
    int maxVotes = 0;

    // 2. Iterate through the map to find the max
    for (auto const& [name, count] : voteCount) {
        if (count > maxVotes) {
            maxVotes = count;
            winner = name;
        } 
        // 3. Handle lexicographical tie
        else if (count == maxVotes) {
            if (winner == "" || name < winner) {
                winner = name;
            }
        }
    }

    cout << winner << " " << maxVotes << endl;
}

int main() {
    int n;
    if (!(cin >> n)) return 0;
    
    vector<string> votes(n);
    for (int i = 0; i < n; i++) {
        cin >> votes[i];
    }

    findWinner(n, votes);

    return 0;
}
