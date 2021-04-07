
#include <string>
#include "Direction.hpp"
#include <map>
//using namespace std;
namespace ariel{
class Board {
    private:
    std::map<unsigned int,std::map<unsigned int,char>> board;
    unsigned int min_col;
    unsigned int max_col;
    unsigned int min_row;
    unsigned int max_row;
    public:
    Board();
    
     /**
     * Post a message on the board, old message on the same location will get overwriten.
     * @row,col-the postion of the message
     * @direct - the direction of the message horizontal - left to right,  Vertical - up to down.
     * @message - the string message we wont to post on the board
     * */
     void post(unsigned int row,unsigned int col,Direction direct,const std::string &message);
     /**
     * Read the message from the board starting from given possition according to the direction,
     * read num of chars 
     * @row,col-the postion of the message
     * @ direction - the direction of the message horizontal - left to right,  Vertical -up to down .
     * @ numOfChars - the number of chars we want to read from the board 
     * */
     std::string read(unsigned int row,unsigned int col,Direction direct, unsigned int numOfChars);
      /** 
       * show the board on screen
       * **/
     void show() ;
    };
}
