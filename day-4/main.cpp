#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <bits/stdc++.h>

using namespace std;
bool isNumber( string a) {
    for(char c : a) {
        if( c < '0' || c > '9')
            return false;
    }
    return true;
}
bool isValidYr(string b , int min, int max) {

    if(!isNumber(b)){
        return false;
    }
    int temp = stoi(b);

    return (temp>=min && temp <=max);
}

bool isValidHcl( string s) {
    if(s[0] != '#')
        return false;
    if(s.substr(1).size() != 6)
    for (int i = 1 ; i < s.size() ; ++i) {
        char t = s[i];
        if (( t >= '0' && t <= '9') || (t >= 'a' && t<='z')) {
            // do nothing
        }
        else {
            return false;
        }
    }
    return true;
}
bool isValidEcl (string s) {
    bool asdf = (s == "amb" || s == "blu" || s == "brn" || s == "gry" || s == "grn" || s == "hzl" || s == "oth");
    return asdf;
}
bool isValidPid ( string s) {
    return (s.size() == 9 && isNumber(s));
}
bool isValid(string s) {
    istringstream ss(s);
    int  n=0;
    bool cid = false;
    string t;

    while (ss >> t) {


        string temp = t.substr(0, 3);
        if (temp == "cid") {
            n++;
        cid = true;
        }
        //now other checks
        // Thinking if I should have made objects and vectors...

        if (temp == "byr") {
            n++;
            if(!isValidYr(t.substr(4) , 1920 , 2002))
                return false;
        }

        if (temp == "iyr") {
            n++;
            if(!isValidYr(t.substr(4) , 2010 , 2020))
                return false;
        }

        if (temp == "eyr") {
            n++;
            if(!isValidYr(t.substr(4) , 2020 , 2030))
                return false;
        }

        if (temp == "hgt") {
            n++;
            if(t.substr(t.size()-2 ) == "in") {
                if (!isValidYr(t.substr(4, t.size() - 6), 59, 76))
                    return false;
            }
            else if(t.substr(t.size()-2 ) == "cm" ) {
                if(!isValidYr(t.substr(4 , t.size()-6) , 150 , 193))
                    return false;

            }
            else {
                return false;
            }
        }

        if(temp == "hcl") {
            n++;
            if (!isValidHcl(t.substr( 4)))
                return false;
        }

        if(temp =="ecl") {
            n++;
            if(!isValidEcl(t.substr(4)))
                return false;
        }

        if(temp == "pid") {
            n++;
            if (!isValidPid(t.substr(4))) {
                return false;
            }
        }


    }

    return ((n == 8) || ((n==7) && !cid)); // This condition gave me headaches
}
int main() {
    ifstream myFile;
    myFile.open("input");

    // Structuring string

    // Can I use a better way to take in the strings ??
    string temp, str;
    int validPassport = 0;
    while(getline( myFile, temp)) {
        str = str + " " + temp;

        if(temp == "" || myFile.peek()==EOF) { //because getline give t an empty string if it catches only \n

            if(isValid(str)) {
                validPassport++;
            }
            str = "";
        }
    }
    cout << validPassport << endl;
    return 0;
}
