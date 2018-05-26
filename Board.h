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
        IllegalCoordinateException(int num, int num2){
            a=num;
            b=num2;
        }
        string theCoordinate ()const{
            return to_string(a)+","+to_string(b);
        }
};

class IllegalCharException : public exception{
    char ch;
public:
     IllegalCharException(char c){
        ch = c;
    }
    const char theChar() const throw (){
        return ch;
   }
};


class Node{
    char cell;
public:
    Node(){};
    
    Node(const char ch){
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
//char operator=(const Node node);
friend ostream& operator<<(ostream& out,const Node& node);
operator char()const;
//bool operator==(char c) const;
//bool operator==(const Node& node) const;
//bool operator!=(char c) const;
//bool operator!=(const Node& node) const;


};


class Coordinate
{
    int row,col;
public:
    
    void setCoordinate(Coordinate c);
    int getRow()const;
    int getCol()const;
    void setRow(int x);
    void setCol(int y);
    
    Coordinate(int x,int y):row(x),col(y) {}
};


inline ostream& operator<<(ostream& out,const Node& node){
    out<<"";
    out<<node.get_node();
     out << "" <<endl;
}


class Board{
public:    
    int size;
   Node **board;
    
    friend ostream& operator<<(ostream& out,const Board& board);
    Board& operator=(char c);
    Node& operator[](const list<int> list);
    Node& operator[](const Coordinate& c) const;
    Board& operator=(const Board& b);
//    bool operator==(const Board& b) const;
    
    Board(){ };
    
     Board(const Board& b){
      size=b.size; 
      board = new Node*[size];
      for (int i = 0; i < size; i++) {
	board[i] = new Node[size];
	}
    for(int i = 0; i < size; i++) {
	for(int j = 0; j < size; j++) {
	board[i][j]= b.board[i][j].get_node();
		}
	}
    };
    
    Board(int num){
      size=num; 
      board = new Node*[size];
      for (int i = 0; i < size; i++) {
	board[i] = new Node[size];
	}
    for(int i = 0; i < size; i++) {
	for(int j = 0; j < size; j++) {
	board[i][j]= '.';
		}
	}
    };
    
    ~Board(){
        for(int i = 0; i < size; i++)
            delete[] board[i];
        delete[] board;
    };
    
};





