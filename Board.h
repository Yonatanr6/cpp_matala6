/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Board.h
 * Author: Yoni
 *
 * Created on May 8, 2018, 6:33 PM
 */

#include <iostream>
#include <vector>
#include <exception>
#include <list>
using namespace std;



class IllegalCoordinateException : public exception{
    int a,b;
    public: 
        void setA(int row){
            this->a=row;
            }
        void setB(int col){
            this->b=col;
            }
        string theCoordinate ()const
        {
            return to_string(a)+","+to_string(b);
        }
};

class IllegalCharException : public exception{
    char ch;
public:
     IllegalCharException(char input){
        ch = input;
    }
    const char theChar() const throw () {
        return ch;
   }
};


class Node{
    char cell;
public:
    Node(){
        
    };
    
    Node(const char &ch){
          if(ch=='X' || ch== 'O' || ch=='.')
        this->cell = ch;
    else{
        IllegalCharException ex(ch);
        throw ex;
    }
};

Node(const Node& n){
    this->cell = n.get_node();
};


char get_node() const {
    return this->cell;
}
Node& operator=(char val);
char operator=(Node node);
friend ostream& operator<<(ostream& out, Node& node);
operator char();


};



inline ostream& operator<<(ostream& out, Node& node){
    out<<"";
    out<<node.get_node();
     out << "" <<endl;
}


class Board{
public:    
    int size;
   Node **board;
   

    
    friend ostream& operator<<(ostream& out, Board board);
    Board& operator=(char c);
     Node& operator[](const list<int> list);
     
    Board(){
        
    };
    
    Board(int num){
      size=num; 
      board = new Node*[num];
      for (int i = 0; i < size; i++) {
	board[i] = new Node[size];
	}
    for(int i = 0; i < size; i++) {
	for(int j = 0; j < size; j++) {
	board[i][j]= '.';
		}
	}
    };
    
};





