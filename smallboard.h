#include<iostream>
#include "cell.h"
using namespace std;

class Smallboard
{
    Cell cells[3][3];
    int count;
    bool status;
    public:
    Smallboard()
    {
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                cells[i][j]=Cell();
            }
        }
        count=0;
        status=false;
    }
    string* displaySmallBoard()
    {
        string* rows = new string[3];
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                // cout<<" "<< cells[i][j].getValue()<<"";
                rows[i].push_back(' ');
                rows[i].push_back(cells[i][j].getValue());
                if(j<2)
                {
                    // cout<<"|";
                    rows[i].push_back('|');
                }
            }
            // cout<<endl;
            // cout<< (i==2?"":"---------");
            // rows[i + 1] = i == 2 ? "" : "---------";
            // cout<<endl;
        }
        // cout<<"-----------------------------------";
        // cout<<endl;
        return rows;
    }
    bool placeMark(char mark,int row, int col)
    {
         cells[row][col].setValue(mark);
        count++;    
    }
    char checkWin()
    {
        for(int i=0;i<3;i++)
        {
            if(cells[i][0]==cells[i][1]&&cells[i][1]==cells[i][2]&&cells[i][0].getValue() !=' ')//&&cells[i][2]==cells[i][2])
            {
                status=true;
                return cells[i][0].getValue();
            }
        }
        for(int j=0;j<3;j++)
        {
            if(cells[0][j]==cells[1][j]&&cells[1][j]==cells[2][j]&&cells[0][j].getValue() !=' ')//&&cells[1][j]==cells[0][j])
            {
                status=true;
                return cells[0][j].getValue();
            }
        }
        if (cells[0][0] == cells[1][1] && 
            cells[1][1] == cells[2][2] && 
            cells[0][0].getValue() != ' ') {
            status=true;
            return cells[0][0].getValue();
        }

        if (cells[0][2] == cells[1][1] && 
            cells[1][1] == cells[2][0] && 
            cells[0][2].getValue() != ' ') {
            status=true;
            return cells[0][2].getValue() ; 
        }
        return false;
    }
    bool isFull()
    {
        bool noSpace;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(cells[i][j].getValue()!=' ')
                {
                    noSpace=true;
                }
            }
        }
    return (count==8&&noSpace)? true:false;
    }
    bool getStatus()
    {
        return status;
    }
};