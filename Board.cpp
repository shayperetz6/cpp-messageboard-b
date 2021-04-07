#include "Board.hpp"
#include "Direction.hpp"
using namespace std;
#include <iostream>
#include <map>
#include <string>  
#include <stdexcept>                     
const unsigned int MAX = 4294967295;
const unsigned int MIN=0;

namespace ariel{
    Board::Board()
    {
        min_col=MAX;//the min valu of col start from the max and for every post smaller from the max we update him
        min_row=MAX;//the min valu of row start from the max and for every post smaller from the max we update him
        max_col=MIN;//the max valu of col start from the min and for every post bigger from the min we update him
        max_row=MIN;//the max valu of row start from the min and for every post bigger from the min we update him

    }
     
    void Board::post(unsigned int row,unsigned int col,Direction direct,const std::string &message)
    {
        //checking the bounds and update 
        if(min_row>row)
        {
            min_row=row;
        }
        if(min_col>col)
        {
            min_col=col;
        }
        if (direct==Direction::Horizontal)
        {
            //check if the bound of the board need ro updtae
           
            if(max_col<col+message.length()){
                max_col=col+message.length();}
            if(max_row<row){
                max_row=row;}
           
            for(unsigned int i=0;i<message.length();i++)
            {
                board[row][col+i]=message.at(i);
            }
        }
        if (direct==Direction::Vertical)
        {
            
            if(max_row<row+message.length()){
                max_row=row+message.length();}
            if(max_col<col){
                max_col=col;}
            for(unsigned int i=0;i<message.length();i++)
            {
                board[row+i][col]=message.at(i);
            }
        }

    }
        
    string Board::read (unsigned int row,unsigned int col,Direction direct, unsigned int numOfChars)
    {
        string ans;
        if (direct==Direction::Horizontal){
            for(unsigned int i=0;i<numOfChars;i++)
            {
                if(board[row][col+i] != 0)// 0 means there isnt value mapped to this location
                {
                  ans+=board[row][col+i]; 
                }
               if(board[row][col+i] == 0){
                   ans+="_";
               }
            }
        }
        if (direct==Direction::Vertical){
            for(unsigned int i=0;i<numOfChars;i++)
            {
                if(board[row+i][col] != 0)// 0 means there isnt value mapped to this location
                {
                  ans+=board[row+i][col]; 
                }
               if (board[row+i][col] == 0){
                   ans+="_";
               }    
            }
        }
        return ans;
    }

    void Board::show() 
    {
    
        for (unsigned int row = min_row ; row <= max_row ; row++)
        {
            cout<<"line num"<<row<<": ";
            for (unsigned int col = min_col ; col <=max_col; col++)
            {
                if(board[row][col]  != 0) 
                 {
                    cout <<  board[row][col];
                 }
                else
                {
                    cout << '_';
                }
                    
            }
            cout <<endl;
        }
    }
    
}
