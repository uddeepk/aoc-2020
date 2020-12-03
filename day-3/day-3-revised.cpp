#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

int main() {
    ifstream myFile;
    myFile.open("input");
    string s;

    long star =0;
    vector <int> position= { 0 , 0, 0, 0, 0};
    vector <long> stars = {0, 0, 0, 0, 0};
    while(getline(myFile , s)) {
        // s2.push_back(s);
        if(position[0]%2 ==0 ) {
            if (s[position[4] % 31] == '#') {
                stars[4]++;
            }
            position[4]++;
        }
        for (int i = 0; i < 4; ++i) {
            if (s[(position[i] % 31)] == '#')
                stars[i]++;
            position[i] += (2*i +1);
        }
    }
    cout << stars[1] << endl;

    long prod = 1;
    for ( auto y : stars) {
        prod *= y;
    }
    cout << prod << endl;
    return 0;
}
