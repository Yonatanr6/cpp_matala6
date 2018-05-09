/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Board.h"
#include <iostream>
#include <vector>
#include <list>
using namespace std;

ostream& operator<<(ostream& out, Board board){
    out<<"";
 for(int i=0;i<board.size;i++){
     // out << "|" ;
        for(int j=0;j<board.size;j++){
           out << board.board[i][j].get_node(); 
        }
        out << "" <<endl;
    }
	for (int i = 1; i <= board.size; i++)	{
	    out << i;
	}
	 out << "" <<endl;
}

Node& Board::operator[](list<int> list){
    int a=list.front(),b=list.back();
    if(a<0 || a>=size || b<0 || b>=size)
    {
        IllegalCoordinateException ex;
        ex.setA(a); ex.setB(b);
        throw ex;
    }   
    return board[a][b];
}


Node& Node::operator=(char val)
{
   if(val=='X' || val=='O' || val=='.'){
        this->cell = val;
        return *this;
   }
    else
    {
       IllegalCharException ex(val);
        throw ex;
    }
    return *this;
}

char Node::operator=(Node node){
    return node.cell;
}

Node::operator char(){
    return cell;
}

Board& Board::operator=(char c)
{
    if (c=='.') {
        for (int j = 0; j < size; ++j) {
            for (int i = 0; i < size; ++i) {
                board[i][j] = '.';
            }
        }
    }
    else
    {
       IllegalCharException ex(c);
        throw ex; 
    }
    return *this;
}