#include <iostream>
#include "plagiarism.h"
#include <string>
#include <vector>
#include "hashTable.h"

using namespace std;


int main(int argc, char *argv[]) {
    cout << "Hello, World!" << endl;
    string dir = argv[1];
    int nwords = atoi(argv[2]);                                                                     // replace w/ argv[2]
    int criteria = atoi(argv[3]);                                                                       // argv[3], at least this much matching to print result

    PlagiaristsCatcher start(nwords);
    start.getdir(dir);
    vector<string> fileList;
    start.vectorFiles(fileList);
    HashTable hash;

    for (unsigned int fileIdx = 0; fileIdx < fileList.size(); fileIdx++) {
        vector<string> words = start.getAllWords(dir, fileIdx);
        vector<string> sequences = start.getAllSequence(words);
        for (unsigned int k = 0; k < sequences.size(); k++) {
            hash.InsertNode(sequences[k], fileIdx);
        }
        sequences.clear();
        words.clear();

    }

    const int ROW = 5000;
    const int COL = 5000;
    vector<int> collision;
    vector<int> file1;
    vector<int> file2;
    static int arr[ROW][COL];
    for (int r = 0; r < ROW; r++) {
        for (int c = 0; c < COL; c++) {
            arr[r][c] = 0;
        }
    }

    hash.checkPlag(*arr, ROW, COL);

    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if (arr[i][j] >= criteria) {
                collision.push_back(arr[i][j]);
                file1.push_back(i);
                file2.push_back(j);
            }
        }
    }

    for (int m = 0; m < collision.size();m++) {
        for (int n = m+1; n < collision.size();n++){
            if (collision[m] < collision [n]){
                iter_swap(collision.begin() + m, collision.begin() + n);
                iter_swap(file1.begin() + m, file1.begin() + n);
                iter_swap(file2.begin() + m, file2.begin() + n);
            }
        }
    }

    for (int d = 0; d < collision.size(); d++) {
        cout << collision[d] << " collisions found between " << fileList[file1[d]] << " and " << fileList[file2[d]] << endl;
    }

    return 0;
}