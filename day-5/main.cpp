using namespace std;
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
int seatNumber ( int rowBegin , int rowEnd, int columnBegin, int columnEnd , string str) {
    switch (str[0]) {
        case 'F':
            rowEnd -= (rowEnd - rowBegin+1)/2;
            break;
        case 'B':
            rowBegin += (rowEnd - rowBegin+1)/2;
            break;
        case 'L':
            columnEnd -= (columnEnd-columnBegin+1)/2;
            break;
        case 'R':
            columnBegin += (columnEnd-columnBegin+1)/2;
            break;
        default:
            return rowBegin* 8 + columnBegin; // begin and end should be equal ?
            break;
    }

    return seatNumber ( rowBegin , rowEnd, columnBegin,  columnEnd , ((str.size() == 1) ? "x" :str.substr(1)));
}
void getSorted( vector <int> &v) {
    for(int i = 0 ; i < v.size()-1 ; i++) {
        for (int j = i+1 ; j < v.size() ; j++) {
            if( v[i] > v[j]) {
                int temp = v[i];
                v[i] = v[j];
                v[j] = temp;
            }
        }
    }
}
int main() {
    ifstream myFile;
    myFile.open("input");
    string input ;
    int max=0;
    vector <int> seats;
    while (getline(myFile, input)) {
        int currentSeat = seatNumber ( 0 , 127 , 0 , 7 , input);
        seats.push_back(currentSeat);
        if (currentSeat > max) {
            max = currentSeat ;
        }
    }
    cout << max <<endl;

    // maybe arrange it from less to greater because seat id is continuous in rows.
    // then check if +1 is there but +2 is miss ? or check seat ids and average them and if missing
    //seat is +1 or -1 then it is the seat id...

    //Getting a sorted array of seatId for further processing.
    getSorted(seats);

    // Check seatIds for missing middle numbers
    for (int i = 0 ; i < seats.size() -1 ; i++) {
        int midSeatId = (seats[i] + seats[i+1])/2;
        if( (midSeatId == seats[i] +1) &&(midSeatId == seats [i+1]-1))
            cout << midSeatId <<endl;
    }
    //vector <vector <bool>> isMySeat //
    return 0;
}
