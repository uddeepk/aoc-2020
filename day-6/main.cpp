#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <bits/stdc++.h>
using namespace std;
int questionsAnswered (vector <string> groupAnswers) {
    int answered=0;
    string together;
    for (auto i: groupAnswers) {
        together+=i;
    }
    for( char j = 'a' ; j <= 'z' ; j++){
        /*for ( char k : together ) { //first way of doing this. this is the way i did it.
            if ( j == k) {
                answered++;
                break;
            }
        }
         */
        if(together.find(j)!=string::npos) //alternate way
            answered++;
    }

    return answered;
}
int questionsAnswered2 (vector <string> groupAnswers) {
    int answered = 0;
    string together;

    for (char c = 'a'; c <= 'z'; c++) {
        int occurance = 0;
        for (string i: groupAnswers) {
            for (char k : i) {
                if (c == k) {
                    occurance++;
                    break;
                }
            }
        }
        if (occurance == groupAnswers.size())
            answered++;
    }
    return answered;
}
int altWay2 (vector <string> s) { // This is an alternate way.
    string  tots;
    int answered=0;
    for (string i: s) {
        tots.append(i);
    }
    for ( char j : s[0]) {
        if (count(tots.begin(), tots.end() , j)== s.size())
            answered++;
    }
    return answered;
}

int main() {
    ifstream myFile;
    myFile.open("input");
    string str;
    vector <vector<string>> answers;
    vector <string> temp;
    while(getline(myFile, str)) {
        if(str!= "") {
            temp.push_back(str); //where my main issue was I was taking empty strings.
        }
        if (str == "" || myFile.peek()==EOF) {
            answers.push_back(temp);
            temp.clear();
        }
    }
    int ans = 0;
    int ans2 = 0;
    int ans3 = 0;
    for(vector<string> a : answers) {
        ans += questionsAnswered(a);
        ans2 += questionsAnswered2(a);
        ans3 += altWay2(a);
    }
    cout << ans << endl;
    cout <<ans2 <<endl;
    cout << ans3 <<endl;
    myFile.close();
    return 0;
}
