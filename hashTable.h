//
// Created by Huy Do on 12/4/18.
//

#ifndef PLAGIARISMCATCHER_HASHTABLE_H
#define PLAGIARISMCATCHER_HASHTABLE_H

#include <string>
#include <vector>
#include <array>
#include <cstdlib>
#include <cstdio>
#include <iostream>

using namespace std;

class HashNode{

public:
    unsigned long int HashKey;
    unsigned int fileIdx;
    HashNode* next;
    HashNode(const unsigned long int key, const unsigned int idx){
        this->HashKey = key;
        this->fileIdx = idx;
        this->next = NULL;
    }
};

class HashTable{

public:
    HashTable(){
        hTable = new HashNode*[TableSz];
        for (int i = 0; i<TableSz; i++) hTable[i] = NULL;
    }
    ~HashTable(){
        HashNode* curr;
        HashNode* remove = NULL;
        for (int i = 0; i<TableSz; i++){
            curr = hTable[i];
            while (curr!=NULL){
                remove = curr;
                curr = curr->next;
                delete remove;
            }
        }
        delete[] hTable;                                    // deleting the Hash Table array
    }

    void Insert(unsigned long int key, unsigned int idx){   // idx == fileIndex
    }

private:
    const unsigned long int TableSz = 100007;
    HashNode** hTable;                                      // hTable is a pointer to a bunch of HashNodes

};



#endif //PLAGIARISMCATCHER_HASHTABLE_H

