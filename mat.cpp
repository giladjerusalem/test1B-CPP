
#include "mat.hpp"

using namespace std;

namespace ariel
{
    std::string mat(int row, int col, char symbol1, char symbol2)
    {

        // char symbol1, char symbol2 must be HASKI !!!!!!

        if ((row % 2 == 0 || col % 2 == 0 )||(row <= 0 || col <=0 ))
        { // if one of number not odd -> throw
            throw exception();
        }
        if (int(symbol1) <33 || int(symbol1) >= 136 )
        { // if one of number not odd -> throw
            throw exception();
        }
        if (int(symbol2) <33 || int(symbol2) >=136 )
        { // if one of number not odd -> throw
            throw exception();
        }
        vector<vector<char>> vect; // define 2D vector

        for (int i = 0; i < row; i++)
        { // Vector to store column elements
            vector<char> v1;
            for (int j = 0; j < col; j++)
            {
                v1.push_back('a');
            }
            // Pushing back above 1D vector
            // to create the 2D vector
            vect.push_back(v1);
        }

        for (int z = 0; z < col; z++)
        { // define the base case-->first line
            vect[0][z] = symbol1;
        }

        for (int i = 1; i < ((row / 2) ); i++)
        { // line 1-->4
            for (int z = 0; z < i; z++)
            { // case 1
                // cout<<"a"<<endl;
                vect[i][z] = vect[i - 1][z];
            }
            for (int z = i; z < col - i; z++)
            { // case 2
                if (i % 2 == 0)
                { // if zugi print symbol1
                    vect[i][z] = symbol1;
                }
                else if (i % 2 == 1)
                { // if odd print symbol2
                    vect[i][z] = symbol2;
                }
            }
            for (int z = col - i; z < col; z++)
            { // case 3
                // cout<<"c"<<endl;
                vect[i][z] = vect[i - 1][z];
            }
        } // close out for



        int i =(row / 2);
            for (int z = 0; z < i; z++)
            { // case 1
                vect[i][z] = vect[i - 1][z];
                
            }
            for (int z = i; z < (col - i); z++)
            { // case 2
            
                if (i % 2 == 0)
                { // if zugi print symbol1
                    vect[i][z] = symbol1;
                }
                else if (i % 2 == 1)
                { // if odd print symbol2
                    vect[i][z] = symbol2;
                }
            }
            for (int z = col - i; z < col; z++)
            { // case 3

                vect[i][z] = vect[i - 1][z];
            }
            



        for (int i = row-1; i >= ((row / 2) + 1); i--)
        {
            for (int j = 0; j < col ;j++)
            {
                vect[i][j] = vect[row-i-1][j];
            }
        }

        //      for (int z = 0; z < col; z++){   //define the base case-->first line
        //     vect[row][z]=symbol1;
        // }
        string s = "";
        for (int i = 0; i < col; i++)
        {
            for (int j = 0; j < row; j++)
            {
                s += vect[j][i];
            }
            s += "\n";
        }
        
        return ""+s;
    }
}