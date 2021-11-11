
/**
* Title: Balanced Search Trees, Hashing and Graphs * Author: Name Surname
* ID: 21901009
* Section: 1
* Assignment: 4
* Description: The implementation of the WordNetwork.h file
*/

#include "WordNetwork.h"


WordNetwork::WordNetwork( const string vertexFile, const string edgeFile){
    //To-do
    
    //load the vertex file
    fstream Vertex( vertexFile.c_str());
    string* temp = new string[VertexSize+1];
    string line;
    
    for( int i = 1 ; i <= VertexSize; i++){
        getline(Vertex, line);
        temp[i] = line;
    }

    //now i have the names of the words in a separate array
    //input them into the 
    wordNetwork = new string*[VertexSize+1];
    for( int i = 0; i <= VertexSize; i++){
        wordNetwork[i] = new string[VertexSize+1];
    }
    //2d array created
    //insert the words

    for( int i = 0; i <= VertexSize; i++){
        for(int j = 0; j <= VertexSize; j++){
            if( i == 0){
                if(j == 0)
                    wordNetwork[0][0] = "null";
                else{
                    wordNetwork[i][j] = temp[j];
                }
            }else{
                if( j > 0)
                    break;
                wordNetwork[i][0] = temp[i];
            }
        }
    }

    Vertex.close();
    //Now, the adjacency matrix was created, adding the edges left
    fstream Edges(edgeFile.c_str());
    string edge, fromV, toV;    //fromV and toV are vertices that connect
    while(getline(Edges, edge)){
        stringstream ss(edge);
        getline(ss, fromV, ',');    
        for( int i = 1; i <= VertexSize+1;i++){
            if(fromV == wordNetwork[i][0] ){
                getline(ss, toV, ',');
                for( int j = 1; j <= VertexSize+1; j++){
                    if( toV.substr(0,5) == wordNetwork[0][j]){
                        wordNetwork[i][j] = "y";
                        break;
                    }
                }
            break;
            }
        }
    }
    Edges.close();

    Hashtable h1(500);
    //for( int i = 0; i <= VertexSize; i++){
      //  h1.insert( temp[i]);
    //}
}
WordNetwork::~WordNetwork(){
    for( int i = 0; i < VertexSize+1; i++){
        for( int j = 0; j < VertexSize+1;j++){
            cout<< wordNetwork[i][j]<< " ";
        }
        cout<<endl;
    }

}

void WordNetwork::listNeighbors( const string word){
    cout<<"to-do"<<endl;
}

void WordNetwork::listNeighbors( const string word, const int distance){
    cout<<"to-do"<<endl;
}

void WordNetwork::listConnectedComponents(){
    cout<<"to-do"<<endl;

}

void WordNetwork::findShortestPath( const string word1, const string word2){
    cout<<"to-do"<<endl;
}

