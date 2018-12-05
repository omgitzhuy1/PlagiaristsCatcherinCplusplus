#include <iostream>
#include "plagiarism.h"
#include <string>
#include <vector>
#include "hashTable.h"

using namespace std;


int main() {
    cout << "Hello, World!" << endl;
    string dir = "/Users/Huigi/Downloads/sm_doc_set"; // argv[1]
    int nwords = 6;                                   // argv[2]


    PlagiaristsCatcher test1(nwords);

    test1.getdir(dir);

    cout << "\nTesting getdir:" << endl;

    test1.printFileNames();

    //cout << "\nTesting printFileContents:" << endl;
    //test1.printFileContents(dir, 2);

    cout << "\nTesting getAllwords:" << endl;
    vector<string> words = test1.getAllWords(dir, 2);
    for (int i = 0; i <words.size(); i++){
        cout << words[i];
    }
    return 0;
}