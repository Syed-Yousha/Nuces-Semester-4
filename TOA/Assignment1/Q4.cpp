#include <iostream>
#include <string>
#include <cstdlib> 

using namespace std;

bool Ending_with_abc(const string& inp) {
    int len = inp.length();

    if (len < 3) {
        cerr << "\nNot valid";
        exit(1);
    }

    string last_three = inp.substr(len - 3);

    return last_three != "abc";
}

int main() {
    string inp;
    cout << "\nEnter any sequence of letters a, b, c: ";
    cin >> inp;

    for (char &c : inp) {
        c = tolower(c);
    }

    if (Ending_with_abc(inp)) {
        cout << "Accepted: The string does not end with 'abc'" << endl;
    } else {
        cout << "Rejected: The string ends with 'abc'" << endl;
    }

    return 0;
}
