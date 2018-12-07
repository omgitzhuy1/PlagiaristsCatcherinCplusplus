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
        fVect.push_back(string(dirp->d_name));
    }
    fVect.erase(fVect.begin(), fVect.begin()+2);                    // erases . and ..
    closedir(dp);
    return 0;
}

void PlagiaristsCatcher::vectorFiles(vector<string>& fileList) {
    for (int i = 0;i < fVect.size();i++) {
        fileList.push_back(fVect[i]);
    }
}


vector<string> PlagiaristsCatcher::getAllWords(const string dir, const int filesIdx){
    vector<string> wordsInFile;
    string filePath = dir + "/" + fVect[filesIdx];
    string word;
    fstream opnFile;
    opnFile.open(filePath.c_str());
    if (opnFile.is_open()){
        while (opnFile >> word){
            string newWord = removePunctuations(word);
            wordsInFile.push_back(newWord);
        }
    }
    return wordsInFile;
}

vector<string> PlagiaristsCatcher::getAllSequence(vector<string> &words) {
    vector<string> nSequence;
    string sentence;
    for (unsigned int i =0; (i+(nWordsSeq-1))<words.size();i++){
        sentence = words[i] + words[i+1] + words[i+2] + words[i+3] + words[i+4] + words[i+5];
        nSequence.push_back(sentence);
    }
    words.erase(words.begin(), words.end());
    return nSequence;
}