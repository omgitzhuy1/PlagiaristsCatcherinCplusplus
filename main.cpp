#include <iostream>
#include "plagiarism.h"
#include <string>
#include <vector>

using namespace std;

int main() {
    cout << "Hello, World!" << endl;

    PlagiaristsCatcher test1;
    string dir = "/Users/Huigi/Downloads/sm_doc_set";

    test1.getdir(dir);

    cout << "\nTesting getdir:" << endl;

    test1.printFileNames();

    cout << "\nTesting printFileContents:" << endl;
    test1.printFileContents(dir, 2);

    return 0;
}