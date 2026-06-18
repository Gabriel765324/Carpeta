// DO NOT SUBMIT THIS FILE

// Compile with this file to test locally
// use e.g. the command `g++ grader.cpp secretagents.cpp -o secretagents` to compile
//
// We recommend you to update the 2nd part of the tests which check the alterations
//
// The format of an input consists of a line containing N, the number of agents, followed by N
// lines, each with a agent name

#include <cassert>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

#include "agentes.h"

using namespace std;

int main() {
    unsigned int N;
    cin >> N >> ws;
    assert(N >= 2 && "N should be at least 2");

    vector<string> names(N);

    for (unsigned int i = 0; i < N; i++) {
        getline(cin, names[i]);
    }

    vector<int> ids = encode(names);

    if (ids.size() != N) {
        cerr << "Failed: The list of ids returned by 'encode' must have the same size as 'agents'."
             << endl;
        return 0;
    }
    for (vector<int>::iterator it = ids.begin(); it != ids.end(); ++it) {
        if (*it < 0 || *it > 999999) {
            cerr << "Failed: Ids must be positive and have at most 6 digits. (got: " << *it << ")"
                 << endl;
            return 0;
        }
    }

    // Testing part: calling 'decode'.
    // The following part is just some sample tests that you can modify for testing your 'decode'
    // function. This is NOT what we use for grading where we do a much detailed testing.

    // just checking that submitting the unaltered ids returns the expected name
    for (unsigned int i = 0; i < ids.size(); ++i) {
        cout << "Testing decode with id '" << ids[i] << "', expecting '" << names[i] << "' ... ";
        string decoded = decode(names, ids[i]);
        if (decoded.compare(names[i]) != 0) {
            cout << "wrong (got '" << decoded << "')" << endl;
            return 0;
        }
        cout << "correct" << endl;
    }

    // some additional id-to-be-decoded, expected answer to be tested
    vector<pair<int, string> > tests{
        pair<int, string>(5, "Damian Adamson"),
        pair<int, string>(5, "Damian Adamson")};  // <-- CHANGE THESE TESTS
    for (vector<pair<int, string> >::iterator it = tests.begin(); it != tests.end(); ++it) {
        cout << "Testing decode with id '" << (*it).first << "', expecting '" << (*it).second
             << "' ... ";
        string decoded = decode(names, (*it).first);
        if (decoded.compare((*it).second) != 0) {
            cout << "wrong (got '" << decoded << "')" << endl;
            return 0;
        }
        cout << "correct" << endl;
    }

    cout << "Success on all tests!" << endl;
}