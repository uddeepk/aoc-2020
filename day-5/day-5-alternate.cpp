/*This is very close to what my Professor did because it is. I tried to think through the binary way. Doing it I thought
 * was the best way to learn. Also ,this way I have a record of it
 */
using namespace std;
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>

int getSeatNumber ( string s) {
    int seat = 0;
    for(auto a : s) {
        seat *= 2;
        if( a == 'B' || a== 'R') {
            seat++;
        }
        //Notice the instructions FBFBFBFRLR . the first 7 bits denote the the up down, then the last 3
        //denote the
    }
    return seat;
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
    int max=0 ;
    vector <int> seats;
    int altSeat ;
    
    while (getline(myFile, input)) {
        int currentSeat = getSeatNumber (  input);
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


    //Who caares if it is inefficient. Just trying something.
    ;
    for ( int i = 0 ; i < seats.size()-1; ++i ) {
        if(seats[i+1] - seats[i] == 2)
            cout << seats[i] +1 << endl;
    }
    
    return 0;
}
