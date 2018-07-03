#include<bits/stdc++.h>
using namespace std;

//soduku solver

 bool correct(int board[9][9],int row,int col,int i)
 {
     if(board[row][col]!=0)
     return false;

     for(int j=0;j<9;j++)
     {
         if(board[row][j]==i)
         return false;

         if(board[j][col]==i)
         return false;
     }


     int r=row/3,c=col/3;

     r=r*3;
     c=c*3;

     for(int j=r;j<r+3;j++)
     {
         for(int k=c;k<c+3;k++)

         if(board[j][k]==i)
         return false;
     }


     return true;
 }

 bool soduku(int board[9][9],int row,int col)
 {
    if(row==9)
    return true;

    if(col==9)
    return soduku(board,row+1,0);

    for(int i=1;i<=9;i++)
    {
        if(board[row][col]!=0)
        return soduku(board,row,col+1);

        bool check=correct(board,row,col,i);

        if(check==true)
        {
            board[row][col]=i;

            bool now=soduku(board,row,col+1);

            if(now==true)
            return true;

            board[row][col]=0;
        }

    }


    return false;
 }

int main()
{
    int board[9][9]={ {5,3,0,0,7,0,0,0,0},
                      {6,0,0,1,9,5,0,0,0},
                      {0,9,8,0,0,0,0,6,0},
                      {8,0,0,0,6,0,0,0,3},
                      {4,0,0,8,0,3,0,0,1},
                      {7,0,0,0,2,0,0,0,6},
                      {0,6,0,0,0,0,2,8,0},
                      {0,0,0,4,1,9,0,0,5},
                      {0,0,0,0,8,0,0,7,9}
                    };



    bool check=soduku(board,0,0);

    if(check==true)
    {
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            cout<<setw(3)<<board[i][j];

            cout<<"\n";
        }
    }
}
