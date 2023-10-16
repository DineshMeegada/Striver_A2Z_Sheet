#include <bits/stdc++.h>
using namespace std;

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> words(wordList.begin(), wordList.end());

    queue<pair<string, int>> q;
    q.push({beginWord, 1});
    words.erase(beginWord);

    while (!q.empty()){
        string curr = q.front().first;
        int steps = q.front().second;
        q.pop();

        if (curr==endWord) return steps;

        for (int i=0; i<curr.size(); i++){
            char original = curr[i];
            for (char ch='a'; ch<='z'; ch++) {
                curr[i] = ch;

                if (words.find(curr) != words.end()) {
                    q.push({curr, steps+1});
                    words.erase(curr);
                }
            }

            curr[i] = original;
        }
    }

    return 0;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    
    
    
    return 0;
}