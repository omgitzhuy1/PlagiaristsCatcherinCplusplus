//
// Created by Huy Do on 12/2/18.
//

#ifndef PLAGIARISMCATCHER_PLAGIARISM_H
#define PLAGIARISMCATCHER_PLAGIARISM_H

#include <sys/types.h>
#include <vector>
#include <string>
#include <dirent.h>
#include <errno.h>
#include <cstdlib>

#endif //PLAGIARISMCATCHER_PLAGIARISM_H

using namespace std;

class PlagiaristsCatcher{

public:

    PlagiaristsCatcher();

    PlagiaristsCatcher(const int nwords);

    int getdir (string dir);

    // For Testing getting files
    void printFileNames();

    // For Testing opening files
    void printFileContents(const string dir, const int idx);

private:

    vector<string> files = vector<string>();
    int nWordsSeq;

};