#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

char firstNonRepeating(string s) {
    unordered_map<char, int> freq;
    queue<char> q;

    for (char c : s) {
        freq[c]++;
        q.push(c);

        while (!q.empty() && freq[q.front()] > 1) {
            q.pop();
        }
    }

    return q.empty() ? '-' : q.front();
}

int main() {
    string s = "abcabc";
    char ans = firstNonRepeating(s);
    if (ans == '-') cout << "No non-repeating char"<<endl;
    else cout << "First non-repeating: " << ans << endl;
    return 0;
}
