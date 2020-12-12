#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "unistd.h"
using namespace std;

void getSeatPositions ( string s , vector<vector <char>> &ferry) {
    vector < char > currentRow;
    for ( auto a : s) {
        currentRow.push_back(a);
    }
    ferry.push_back(currentRow);
}
int checkAdjacentSeats ( vector <string> &ferry , int i , int j) {
    int seats = 0;
    // A vector with the coordinates :) 8 elements { -1 , -1 } , { -1 , 0 }  , { -1 , 1 } , { 0 , -1 } , { 0 , 1 } , { 1 , -1 } , { 1 , 0 } , { 1 , 1 }
    vector <vector <int>> adj = {{ -1 , -1 } , { -1 , 0 }  , { -1 , 1 } , { 0 , -1 } , { 0 , 1 } , { 1 , -1 } , { 1 , 0 } , { 1 , 1 } };

    for ( auto a : adj ) {
        //First check if the co-oridnates are in bound. Could I have use a data structure for ease, and just run through it ?
        // If I already programmed adjacent nodes then it would be easy ....
        int row = i + a[0] , col = j + a[1];
        if ( row >= 0 && row < ferry.size()  &&  col >= 0  && col < ferry [i].length()) {
            //Now checking the particular adjacent seat
            if ( ferry [row][col] == '#' ) { //ferry [row][col] != 'L' && ferry[row][col] != '.') { //check if not L or . or i can use # ferry[row][col] == '#'
                seats++;
                // should i stop at 5 ? because we only need it to be 4 or more .
                //if (seats == 5) { return seats ;}
            }
        }
    }

    return seats;
}
void getAdjacentSeats (vector <vector<int>> &vSeats , vector <string> &ferry ) {

    for(auto i = 0 ; i < ferry.size() ; i++) {
        for ( auto j = 0 ; j < ferry[i].length() ; j++) {
            if ( ferry [i][j] != '.') {
                vSeats [i][j] = checkAdjacentSeats ( ferry , i , j );
            }
        }

    }
}
void getNextPositions ( vector <string> &ferryNext , vector <vector<int>> &adjacentSeatsFilled ) {
    vector <vector<int>> &a = adjacentSeatsFilled;
    vector <string> &f = ferryNext;
    for ( int i = 0 ; i < f.size() ; ++i ) {
        for ( int j = 0 ; j < f[i].length() ; ++j) {
            if( f[i][j] == 'L' && a[i][j] == 0 ) {
                f[i][j] = '#';
            }
            else if ( f[i][j] == '#' && a[i][j] >= 4 ) {
                f[i][j] = 'L';
            }
            else {
                // do nothing
            }
        }
    }
}
void getNextPositions2 ( vector <string> &ferryNext , vector <vector<int>> &adjacentSeatsFilled ) {
    vector <vector<int>> &a = adjacentSeatsFilled;
    vector <string> &f = ferryNext;
    for ( int i = 0 ; i < f.size() ; ++i ) {
        for ( int j = 0 ; j < f[i].length() ; ++j) {
            if( f[i][j] == 'L' && a[i][j] == 0 ) {
                f[i][j] = '#';
            }
            else if ( f[i][j] == '#' && a[i][j] >= 5 ) {
                f[i][j] = 'L';
            }
            else {
                // do nothing
            }
        }
    }
}
vector<vector<int>> getVecRec ( vector <string> &ferry) {
    vector <string> &f = ferry;
    vector <vector<int>> adj;
    for ( auto i : ferry ) {
        vector <int> row;
        for(auto j :  i ) {
            row.push_back( 0 );
        }
        adj.push_back ( row );
        row.clear();
    }

    return adj;
}
void displayFerrySim ( vector <string> &v ) {
    ostringstream oss;
    oss << string ( 40 , '\n');
    for ( auto i : v) {
        oss << i;
        oss << '\n';

    }

    //cin.ignore();
    usleep(25 * 1000);
    cout << oss.str() << endl;
    oss.clear();
}
void star1 ( vector <string> ferry) {
    //Preparing a vector of empty ?
    vector <vector <int>> adjacentSeatsFilled = getVecRec( ferry );
    //vector <vector<int>> adjacentSeatsFilled [ferry.size()] [ferry[0].length()]   ;
    vector <string> ferryNext = ferry; // ( ferry );
    do {
        //Copying the ferry next
        ferry = ferryNext ;

        //Now we get the adjacent seats in a 2D array so that easier to see. // wow or I could use numbers ...
        getAdjacentSeats( adjacentSeatsFilled, ferry) ;
        //cout << adjacentSeatsFilled[0][0] << endl;

        getNextPositions( ferryNext , adjacentSeatsFilled);
        //cout << ( ferry == ferryNext) << endl;
        //cout << ferryNext[0][0] << endl;

        //displayFerrySim ( ferryNext );
        //wait first. so calculations are already finished
        //buffer character
        //print

    }while (ferry != ferryNext);

    int occupied = 0;
    for ( auto a : ferry) {
        for ( auto b : a) {
            if ( b == '#') {
                occupied++;
            }
        }
    }
    cout << occupied << endl;
}
bool checkWithinRange ( int i , int j , int r , int c , int fRows , int fCols ) {
    int row = i + r , col = j + c;
    return ( row >=0 && row <fRows && col>= 0 && col < fCols );
}
int checkFirstSeats ( vector <string> &ferry , int i , int j) {
    int seats = 0;
    // A vector with the coordinates :) 8 elements { -1 , -1 } , { -1 , 0 }  , { -1 , 1 } , { 0 , -1 } , { 0 , 1 } , { 1 , -1 } , { 1 , 0 } , { 1 , 1 }
    vector <vector <int>> adj = {{ -1 , -1 } , { -1 , 0 }  , { -1 , 1 } , { 0 , -1 } , { 0 , 1 } , { 1 , -1 } , { 1 , 0 } , { 1 , 1 } };

    //check 1 direction at a time. using the vectors above by using multipliers.
    for ( auto a : adj ) {

        for ( int b = 1 ; checkWithinRange( i , j , a[0]*b , a[1]*b , ferry.size() , ferry[i].length()) ; b++) {


            if (ferry[i + b * a[0]][j + b * a[1]] == '#') {
                seats++;
                break;
                // Check if seats > =5 ??
            }
            if (ferry[i + b * a[0]][j + b * a[1]] == 'L') {
                //Empty seat in this direction
                break;
                // Check if seats > =5 ??
            }



        }
    }

    return seats;
}
void getFirstSeats (vector <vector<int>> &vSeats , vector <string> &ferry ) {

    for(auto i = 0 ; i < ferry.size() ; i++) {
        for ( auto j = 0 ; j < ferry[i].length() ; j++) {
            if ( ferry [i][j] != '.') {
                vSeats [i][j] = checkFirstSeats ( ferry , i , j );
            }
        }

    }
}
void star2 ( vector <string> ferry) {
    //Preparing a vector of 0
    vector <vector <int>> firstSeatsFilled = getVecRec( ferry );
    //vector <vector<int>> adjacentSeatsFilled [ferry.size()] [ferry[0].length()]   ;
    vector <string> ferryNext = ferry; // ( ferry );
    do {
        //Copying the ferry next
        ferry = ferryNext ;

        //Now we get the adjacent seats in a 2D array so that easier to see. // wow or I could use numbers ...
        getFirstSeats( firstSeatsFilled, ferry) ;
        //cout << firstSeatsFilled[0][0] << endl;

        getNextPositions2( ferryNext , firstSeatsFilled);

    }while (ferry != ferryNext);

    int occupied = 0;
    for ( auto a : ferry) {
        for ( auto b : a) {
            if ( b == '#') {
                occupied++;
            }
        }
    }
    cout << occupied << endl;
}
int main() {
    ifstream myFile;
    myFile.open("input");
    string str;

    vector <string> ferry ;

    // Getting input
    while (getline( myFile , str)) {

        //getSeatPositions(str , ferry); //Insert the chars into the vector. On second thought don't need this
        ferry.push_back (str);
    }
    star1 ( ferry );
    star2(ferry);
    myFile.close();
    return 0;
}
