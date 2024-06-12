#include <iostream>
#include <string>
#include <regex>
#include <iterator>
using namespace std;

int main() {
    string s1 = "I am looking for yasirGeeksForGeek \n";
    string s2 = "Some people, when yasirconfronted with a problem, think "
                "\"I know, I'll use regular expressions.\" "
                "Now they have two problems.";

    // Define regular expression patterns
    regex pattern1("yasir[a-zA-z]+"); // Pattern for words beginning with "Geek"
    regex pattern2("regular expressions", regex_constants::icase); // Pattern for "regular expressions"
    regex pattern3("w+[a-zA-z]+"); // Pattern for long words

    // Replace matches with 'geek' for pattern1 in s1
    cout << "After replacing: \n";
    cout << std::regex_replace(s1, pattern1, "hhhh") << '\n';

    // Replace long words with square brackets for pattern3 in s2
   string newText = regex_replace(s2, pattern3, "[$&]");

    cout << "After replacing long words with square brackets:\n";
    cout << newText << '\n';

    // Search for pattern2 in s2
    if (regex_search(s2, pattern2)) {
        cout << "Text contains the phrase 'regular expressions'\n";
    }

    // Count words in s2
    int wordCount = 0;
    string currentWord;
    for (char c : s2) {
        if (isalpha(c)) {
            currentWord += c;
        } else {
            if (!currentWord.empty()) {
                wordCount++;
                currentWord.clear();
            }
        }
    }
    if (!currentWord.empty()) {
        wordCount++;
    }
    cout << "Found " << wordCount << " words\n";

    // Print words longer than N characters in s2
    const int N = 6;
    cout << "Words longer than " << N << " characters:\n";
    currentWord.clear();
    for (char c : s2) {
        if (isalpha(c)) {
            currentWord += c;
        } else {
            if (!currentWord.empty()) {
                if (currentWord.size() > N) {
                    cout << "  " << currentWord << '\n';
                }
                currentWord.clear();
            }
        }
    }
    if (!currentWord.empty() && currentWord.size() > N) {
        cout << "  " << currentWord << '\n';
    }

    return 0;
}

