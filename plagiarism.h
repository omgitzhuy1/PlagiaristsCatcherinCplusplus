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

    vector<string> files = vector<string>();

    PlagiaristsCatcher();

    PlagiaristsCatcher(const int nwords);

    int getdir (string dir);

    // For Testing getting files
    void printFileNames();

    // For Testing opening files
    //void printFileContents(const string dir, const int idx);

    vector<string> getAllWords(const string dir, const int filesIdx);


private:

    int nWordsSeq;

    //////////////////////////////////////////////////////////////////////////////////////
    // Private function to remove all punctuations and converting capitals to lowercase
    string removePunctuations(string word){
        const char A = 'A', Z = 'Z';
        const int lowerCase = 32;
        string newWord;
        for (int i = 0; i<word.length();i++){
            if ((word[i]>=33 && word[i]<=47) || (word[i]>=58 && word[i]<=64)){
                word.erase(word.begin()+i);
            }
            else if (word[i] >= A && word[i]<=Z){
                word[i] = word[i] + 32;
            }
        }
        return word;
    }
    //////////////////////////////////////////////////////////////////////////////////////

};