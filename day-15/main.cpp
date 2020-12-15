#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <map>
#include <algorithm>
#include <regex>

using namespace std;

void star1 ( vector <int> &v) {
    unsigned age ;
    auto it = v.rbegin() + 1 ;
    while (it != v.rend()) {
        if(*v.rbegin() == *it ) {
            age = it - v.rbegin();
            break;
        }
        ++it;
    }
    //cout << age << endl;
    if( it != v.rend() ) {
        v.push_back( it - v.rbegin());
    }
    else {
        v.push_back ( 0 );
    }
    if(v.size() != 2020 ) {
        star1(v);
    }
    else {
        cout << *v.rbegin() << endl;
    }
}
void star2 ( vector <int > &v) {
    //unsigned long age ;
    auto it = v.rbegin() + 1 ;
    while (it != v.rend()) {
        if(*v.rbegin() == *it ) {
            //age = it - v.rbegin();
            break;
        }
        ++it;
    }
    //cout << age << endl;
    if( it != v.rend() ) {
        v.push_back( it - v.rbegin());
    }
    else {
        v.push_back ( 0 );
    }
    if(v.size() != 30000000 ) {
        star2(v);
    }
    else {
        cout << *v.rbegin() << endl;
    }
}
void star2Rev ( vector <int> v ) {
    map <int , int> myMap;

    for (decltype(v.size()) i = 0 ; i < v.size() -1 ; ++i ) {
        myMap.insert( {v[i] , i });
    }
    auto lastElement = *v.rbegin();
    //cout << lastElement << endl;
    for (int i = v.size() -1; i < 30000000 - 1  ; ++i) {
        auto it = myMap.find(lastElement );
        //cout << lastElement << " " << i << endl;
        if(it == myMap.end()) {
            myMap.insert({ lastElement , i}) ;
            lastElement = 0;
        }
        else {
            lastElement = i - it->second ;
            it->second = i;
        }
    }

    cout << lastElement <<endl;
}
void testStar2 ( vector <int> v , int n) {
    vector <int> v2  ( n , 0); ;
    int currentNumber ;
    int nextNumber;
    for ( int i = 1 ; i <= v.size() ; ++i ) {
        v2[v[i-1]] = i;
        //currentNumber = v[i];
    }
    currentNumber = 0;
    for ( int i = v.size() + 1 ; i < n ; ++i ) {
        nextNumber =  (v2[currentNumber] == 0 ? 0 : i -v2[currentNumber]);
        v2[currentNumber] = i ;
        currentNumber = nextNumber;
        //cout << currentNumber << endl;
    }
    cout << currentNumber << endl;
}
int main() {
    vector <vector<int>> input = { { 0 , 3 , 6 } ,{ 1 , 3 , 2 } , { 1 , 2 , 3 } , { 2 , 3 , 1 } , { 3 , 2,1} , {3,1,2}};
    vector <int> puzzleInput = { 11,18,0,20,1,7,16};
    vector <int> v2 = puzzleInput;
    //star1 (puzzleInput);
    //star2Rev ( input[5]);
    //star2 (puzzleInput); //doesn'twork  signal11 error.

    //star2Rev(v2);
    //star1X(puzzleInput);
    testStar2( v2 , 2020) ; //star1
    testStar2( v2 , 30000000); //star2
    return 0;
}
