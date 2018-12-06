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
#include <cmath>
#include <stdlib.h>
#include <cstdint>

using namespace std;

class HashNode{

public:
    unsigned int fileIdx;
    HashNode* next;
    explicit HashNode(const unsigned int Idx){
        this->fileIdx = Idx;
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

    void InsertNode(const string& nwords, const unsigned int Idx) {   // idx == fileIndex
        unsigned long int key = HashFunctionKey(nwords);
        HashNode* newNode = new HashNode(Idx);
        if (hTable[key] == NULL)
            hTable[key] = newNode;
        else if (hTable[key] != NULL) {
            newNode->next = hTable[key];
            hTable[key] = newNode;
        }
    }

    void RemoveNode(const unsigned long key, const unsigned int Idx){
        HashNode* prev = NULL;
        HashNode* curr = hTable[key];
        if (hTable[key] == NULL) return;
        else
            while (curr!=NULL) {
                if (curr->fileIdx == Idx) {
                    if (prev == NULL) {                     // curr is top of linkedlist of hTable[key]
                        hTable[key] = curr->next;
                        delete curr;
                    }
                    else {
                        prev->next = curr->next;            // curr is not top of linkedlist of hTable[key]
                        delete curr;
                    }
                }
                else {
                    prev = curr;
                    curr = curr->next;
                }
            }
    }

    // Testing purposes
    /*unsigned long long int getKey(const string& sentence){
        return HashFunctionKey(sentence);
    }*/

    void CheckOccupied(){
        for (unsigned long int i = 0; i <TableSz ; i++){
            if (hTable[i]!=NULL){
                HashNode* temp = hTable[i];
                cout << "hTable[" << i << "]: ";
                while (temp!=NULL){
                    cout << temp->fileIdx << " ";
                    temp = temp->next;
                }
                cout << endl;
            }
        }
    }

private:
    unsigned long long int HashFunctionKey(const string& k){
        unsigned long long int key = 0;
        const unsigned int base = 11;
        const unsigned int letters = 16;
        for (unsigned int i = 0; i<letters; i++){
            key = key + ((unsigned long long int)k[i]*((unsigned long long int)pow(base,i)));
        }
        return (key%TableSz);
    }
    const unsigned long int TableSz = 199999;
    HashNode** hTable;                                      // hTable is a pointer to a bunch of HashNodes
};


#endif //PLAGIARISMCATCHER_HASHTABLE_H

