#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>

using namespace std;

const int MAX_STATES = 100;

struct DFA {
    int numStates;
    int numInputs;
    int transition[MAX_STATES][MAX_STATES];
    bool isFinal[MAX_STATES];
};

void minimizeDFA(const DFA& dfa) {
    int numStates = dfa.numStates;
    vector<set<int>> equivalent(numStates, set<int>());
    vector<set<int>> partitions(2);

    for (int i = 0; i < numStates; ++i) {
        partitions[dfa.isFinal[i]].insert(i);
    }

    queue<pair<int, int>> pending;

    for (int i = 0; i < numStates; ++i) {
        for (int j = i + 1; j < numStates; ++j) {
            if (dfa.isFinal[i] != dfa.isFinal[j]) {
                equivalent[i].insert(j);
                equivalent[j].insert(i);
                pending.push({i, j});
            }
        }
    }

    while (!pending.empty()) {
        auto [state1, state2] = pending.front();
        pending.pop();
        for (int input = 0; input < dfa.numInputs; ++input) {
            int nextState1 = dfa.transition[state1][input];
            int nextState2 = dfa.transition[state2][input];
            if (equivalent[nextState1].count(nextState2) == 0) {
                equivalent[nextState1].insert(nextState2);
                equivalent[nextState2].insert(nextState1);
                pending.push({nextState1, nextState2});
            }
        }
    }

    map<int, int> newStateMapping;
    int newStateCount = 0;
    for (int i = 0; i < numStates; ++i) {
        if (equivalent[i].empty()) {
            newStateMapping[i] = newStateCount++;
        }
    }

    cout << "Minimized DFA Transition Table:" << endl;
    cout << "States: " << newStateCount << endl;
    cout << "Inputs: " << dfa.numInputs << endl;
    for (int i = 0; i < numStates; ++i) {
        if (equivalent[i].empty()) {
            cout << "State " << i << ": ";
            for (int input = 0; input < dfa.numInputs; ++input) {
                cout << dfa.transition[i][input] << " ";
            }
            cout << endl;
        }
    }
}

int main() {
    DFA dfa;
    cout << "Enter number of states: ";
    cin >> dfa.numStates;
    cout << "Enter number of inputs: ";
    cin >> dfa.numInputs;

    cout << "Enter transition table:" << endl;
    for (int i = 0; i < dfa.numStates; ++i) {
        for (int j = 0; j < dfa.numInputs; ++j) {
            cin >> dfa.transition[i][j];
        }
    }

    cout << "Enter final states: ";
    for (int i = 0; i < dfa.numStates; ++i) {
        cin >> dfa.isFinal[i];
    }

    minimizeDFA(dfa);

    return 0;
}

