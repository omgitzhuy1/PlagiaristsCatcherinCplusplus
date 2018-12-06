#include <iostream>
#include "plagiarism.h"
#include <string>
#include <vector>
#include "hashTable.h"

using namespace std;


int main() {
    cout << "Hello, World!" << endl;
    string dir = "/Users/Huigi/Downloads/sm_doc_set";                                   // replace w/ argv[1], change dir when on your computer
    int nwords = 6;                                                                     // replace w/ argv[2]
    int criteria;                                                                       // argv[3], at least this much matching to print result


    PlagiaristsCatcher test1(nwords);

    test1.getdir(dir);

    //cout << "\nTesting getdir:" << endl;                                              // works

    //test1.printFileNames();

    //cout << "\nTesting printFileContents:" << endl;
    //test1.printFileContents(dir, 2);

    //cout << "\nTesting getAllwords:" << endl;                                         // Works
    vector<string> words = test1.getAllWords(dir, 2);
    /*for (unsigned int i = 0; i < words.size(); i++){
        cout << words[i];
    }*/

    //cout << "\n\nTesting getAllSequence:" << endl;                                    // Works
    vector<string> nSequence = test1.getAllSequence(words);
    /*for (unsigned int i = 0; i < nSequence.size(); i++){
        cout << nSequence[i] << endl;
    }*/

    // cout << "Size of words vector (should be zero): " << words.size() << endl;       // Works

    HashTable testHash;


    vector<unsigned long long int> keys;                                              // Works
    /*unsigned int matchCount = 0;
    cout << "\n\nTesting HashFunction and getKey:" << endl;
    unsigned long long int maxKey = 0;
    for (unsigned int i = 0; i<nSequence.size(); i++){
        unsigned long long int key = testHash.getKey(nSequence[i]);
        cout << "key: " << key << " " << nSequence[i] << endl;
        if (key > maxKey) maxKey = key;
        keys.push_back(key);
    }
    cout << "\nmaxKey: " << maxKey << endl;

    for (unsigned long long int i = 0; i<(keys.size()-1); i++ ){
        for (unsigned long long int j = i+1; j<keys.size(); j++){
            if (keys[i] == keys[j]) {
                cout << "Match: " << keys[i] << endl;
                matchCount++;
            }
        }
    }
    cout << "\nmatchCount: " << matchCount << endl;*/

    return 0;
}