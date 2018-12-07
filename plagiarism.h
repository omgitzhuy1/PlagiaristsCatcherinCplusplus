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

    vector<string> fVect;

    PlagiaristsCatcher();

    PlagiaristsCatcher(const int nwords);

    int getdir (string dir);

    // For Testing getting files
    void vectorFiles(vector<string> &fileList);

    // For Testing opening files
    //void printFileContents(const string dir, const int idx);

    vector<string> getAllWords(const string dir, const int filesIdx);

    vector<string> getAllSequence(vector<string>& words);


private:

    int nWordsSeq;

    //////////////////////////////////////////////////////////////////////////////////////
    // Private function to remove all punctuations and converting capitals to lowercase
    string removePunctuations(string word){
        const int lowerCase = 32;
        string newWord;
        for (int i = 0; i<word.length();i++){
            if ((word[i]<'A' || (word[i]>'Z' && word[i]<'a') || word[i]>'z')){
                word.erase(word.begin()+i);
            }
            else if (word[i] >= 'A' && word[i]<='Z'){
                word[i] = word[i] + 32;
            }
        }
        return word;
    }
    //////////////////////////////////////////////////////////////////////////////////////

};