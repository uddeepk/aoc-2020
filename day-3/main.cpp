#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;
long star2( vector <string> s2, int r ) {
    int counter = 0;
    long stars = 0;
    for(auto s: s2) {
        if(s[(counter%31)] == '#')
            stars++;
        counter += r;
    }
    return stars;
}
long star2( vector <string> s2, int r, int d) {
    int counter = 0;
    long stars = 0;
    for(int i = 0 ; i < s2.size() ; i=i+2) {
        if(s2[i][counter%31] == '#')
            stars++;
        counter += r;
    }
    return stars;
}
int main() {
    ifstream myFile;
    myFile.open("input");
    string s;
    vector <string> s2;
    long star =0, position =0 ;
    while(getline(myFile , s)) {
        s2.push_back(s);
        if(s[(position%31)] == '#')
            star++;
        position +=3;
    }
    cout << star << endl;
    vector <int> r = { 1 , 5 , 7};
    for ( int i : r) {
        star *= star2(s2 , i);
        cout << star << endl;
    }
    cout << star * star2(s2 , 1 , 2) << endl;
    return 0;
}
