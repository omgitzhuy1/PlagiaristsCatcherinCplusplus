//
// Created by Huy Do on 12/2/18.
//

#include <iostream>
#include <fstream>
#include "plagiarism.h"

using namespace std;

PlagiaristsCatcher::PlagiaristsCatcher() {
    nWordsSeq = 6;             // 6 as default for testing
}

PlagiaristsCatcher::PlagiaristsCatcher(const int nwords) {
    nWordsSeq = nwords;
}

int PlagiaristsCatcher::getdir(string dir){
    DIR *dp;
    struct dirent *dirp;
    if((dp  = opendir(dir.c_str())) == NULL) {
        cout << "Error(" << errno << ") opening " << dir << endl;
        return errno;
    }

    while ((dirp = readdir(dp)) != NULL) {
        files.push_back(string(dirp->d_name));
    }
    files.erase(files.begin(), files.begin()+2);                    // erases . and ..
    closedir(dp);
    return 0;
}

void PlagiaristsCatcher::printFileNames() {
    for (int i = 0;i < files.size();i++) {
        cout << i << " " << files[i] << endl;
    }
}

/*void PlagiaristsCatcher::printFileContents(const string dir, const int idx) {
    string filePath = dir + "/" + files[idx];
    string line;
    fstream opnFile;
    opnFile.open(filePath);
    if(opnFile.is_open()){
        cout << files[idx] << " opened" << endl;
        while (getline(opnFile, line)){
            cout << line << endl;
        }
        opnFile.close();
    }
    else
        cout << "Error. File cannot open" << endl;

}
Used for testing purposes */

vector<string> PlagiaristsCatcher::getAllWords(const string dir, const int filesIdx){
    vector<string> wordsInFile;
    string filePath = dir + "/" + files[filesIdx];
    string word;
    fstream opnFile;
    opnFile.open(filePath);
    if (opnFile.is_open()){
        while (opnFile >> word){
            string newWord = removePunctuations(word);
            wordsInFile.push_back(newWord);
        }
    }
    return wordsInFile;
}