#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;
void rotateShip ( pair <char , int > instruction , vector <int> &d ) {
    //Rotation vector L90 { { 0 , 1} , { -1 , 0 } } , L180 { { -1 , 0 } , { 0 , -1 } } , L270 { { 0 , -1 } , { 1 , 0 }}
    // (degrees/ 90) % 4 give the times of rotation. L would keep the vectors the same
    // so even would be fine. if it is -1 or -3 , then add 4?? and I wouldn't have to

    int numOfRotations = (instruction.second/90) % 4 ; // number of 90 degree rotations

    if( numOfRotations == 2 ) {
        int d0 = (-1) * d[0] + 0 * d[0];
        int d1 = 0 * d[0] + (-1) * d[1];
        d = { d0 , d1}; //after rotations
    }
    else if ( numOfRotations == 1 ) {

        int d0 = (0 * d[0] + (-1) * d[1]) * (instruction.first == 'L' ? 1 : -1 );
        int d1 = (1 * d[0] + 0 * d [1]) * (instruction.first == 'L' ? 1 : -1 );
        d = { d0 , d1 };
        //cout << " xx " << d[0] << "x" << d[1] << endl;
    }
    else if ( numOfRotations == 3) {
        int d0 = (0 * d[0] + 1 * d[1]) * (instruction.first == 'L' ? 1 : -1 );
        int d1 =( (-1) * d[0] + 0 * d [1]) * (instruction.first == 'L' ? 1 : -1 );
        d = {d0 , d1 };
    }
    else {
        // Do nothing :)
    }
}
void moveShip ( pair <char , int > instruction , vector <int> &d , vector <int> &sP) {
    switch ( instruction.first) {
        case 'N' :
            sP[1] += instruction.second; // sp is ( e , n )
            break;
        case 'S':
            sP[1] -= instruction.second;
            break;
        case 'E':
            sP[0] += instruction.second;
            break;
        case 'W':
            sP[0] -= instruction.second;
            break;
        case 'L': case'R':
            rotateShip( instruction, d);
            break;
        case 'F':

            sP[0] += d[0] * instruction.second;
            sP[1] += d[1] * instruction.second;

            break;
        default :
            cerr << "Error in input " << endl;
            break;

    }
}

int star1 ( vector <pair < char , int > > instructions ) {
    vector <int> d = { 1 , 0 } ; //Initial direction vector
    vector <int> shipPosition = { 0 , 0 } ;//Initial ship position as 0E, 0N

    for ( auto it : instructions) {
        moveShip( it , d , shipPosition );
    }
    cout << shipPosition[0] <<  " , " <<shipPosition[1] << endl;
    return (abs(shipPosition[0]) + abs(shipPosition[1]));
}
void moveShip2 ( pair <char , int > instruction , vector <int> &d , vector <int> &sP) {
    switch ( instruction.first) {
        case 'N' :
            d[1] += instruction.second; // sp is ( e , n )
            break;
        case 'S':
            d[1] -= instruction.second;
            break;
        case 'E':
            d[0] += instruction.second;
            break;
        case 'W':
            d[0] -= instruction.second;
            break;
        case 'L': case'R':
            rotateShip( instruction, d);
            break;
        case 'F':

            sP[0] += d[0] * instruction.second;
            sP[1] += d[1] * instruction.second;

            break;
        default :
            cerr << "Error in input " << endl;
            break;

    }
}

int star2 ( vector <pair < char , int > > instructions ) {
    vector <int> d = { 10 , 1 } ; //Initial direction vector
    vector <int> shipPosition = { 0 , 0 } ;//Initial ship position as 0E, 0N

    for ( auto it : instructions) {
        moveShip2( it , d , shipPosition );
    }
    cout << shipPosition[0] <<  " , " <<shipPosition[1] << endl;
    return (abs(shipPosition[0]) + abs(shipPosition[1]));
}

int main() {
    ifstream myFile ;
    myFile.open("input");
    stringstream ss;
    //Get input. vector of pairs ??
    vector < pair <char , int > > instructions;
    char i ;
    int n;
    char buf;
    string temp ;
    while ( getline ( myFile , temp)) {
        ss << temp;
        ss >> i >> n;
        instructions.push_back ( { i , n});
        //myFile >> buf; //Get rid of the '\n' at the end
        ss.str("");
        ss.clear();

    }
    //cout << instructions.size() <<endl;
    cout << "star1 : " << star1 ( instructions) << endl;
    //Setting direction vector.
    cout << "star2 : " << star2 (instructions) << endl;

    return 0;
}
