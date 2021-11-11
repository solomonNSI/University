/**
* Title: Balanced Search Trees, Hashing and Graphs * Author: Name Surname
* ID: 21901009
* Section: 1
* Assignment: 4
* Description: The hw assigned functions for the WordNetwork
*/

#ifndef WORDNETWORK_H
#define WORDNETWORK_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include "Hashtable.cpp"

#define VertexSize 7
#define EdgeSize 5
using namespace std;

class WordNetwork{
    public:
        WordNetwork(const string vertexFile, const string edgeFile);
        ~WordNetwork();

        void listNeighbors(const string word);
        void listNeighbors(const string word, const int distance);

        void listConnectedComponents();
        void findShortestPath(const string word1, const string word2);
    private:
        string** wordNetwork;
        int hash( const string &key, int tableSize);

};

#endif
