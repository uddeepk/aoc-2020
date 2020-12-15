#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <regex>
#include <map>
using namespace std;

void getMasks ( string mask  , unsigned long long &ms0 , unsigned long long &ms1 ) { //mask1 for or and 1s mask0 for and and 0s

    ms1 = 0 , ms0 = 0;
    for (auto a : mask ) {
        switch ( a ) {
            case '1':
                ms1 = ms1*2 + 1;
                ms0 = ms0*2 + 1;

                break;
            case '0':
                ms1 = ms1*2 + 0;
                ms0 = ms0*2 + 0;

                break;
            case 'X':
                ms1 = ms1*2 + 0;
                ms0 = ms0*2 + 1;

                break;
            default:
                cerr << "Incorrect input getmasks switch case " << endl;
                break;
        }

    }
    //vector <unsigned long long> temp = { ms0 , ms1};
    //return  temp;
}

void getMasks2 ( string mask  , unsigned long long &ms0 , vector <unsigned long long> &ms1 ) { //mask1 for or and 1s mask0 for and and 0s

    ms1 = {0} ;
    ms0 = 0;
    vector <unsigned long long > temp;
    for (auto a : mask ) {
        auto oldSize = ms1.size();
        switch ( a ) {
            case '1':
                //ms1 = ms1*2 + 1;
                ms0 = ms0*2 + 1;
                for ( auto &x : ms1) {
                    x = x*2 + 1;
                }
                break;
            case '0':
                for ( auto &x : ms1 ) {
                    x = x*2 + 0;
                }
                //ms1 = ms1*2 + 0;
                ms0 = ms0*2 + 1;

                break;
            case 'X':

                //ms1 = ms1*2 + 0;
                ms0 = ms0*2 + 0;
                for ( decltype(ms1.size()) i = 0 ; i < oldSize ; ++i ) {
                    ms1.push_back(ms1[i] * 2 + 1);
                    ms1[i] = ms1[i] * 2 + 0;
                }

                break;
            default:
                cerr << "Incorrect input getmasks switch case " << endl;
                break;
        }
        //for (auto x : temp ) {

        //}
    }
    //vector <unsigned long long> temp = { ms0 , ms1};
    //return  temp; //returning vectors did not work. so I used references
}

int main() {
    ifstream myFile ;
    myFile.open("input");
    string s;
    map <unsigned long long, unsigned long long> bloc;

    vector<unsigned long long> ms = {0,0};
    //For star 2
    vector <unsigned long long > maskStarX ;
    unsigned long long  maskPart20;
    map <unsigned long long ,unsigned long long> star2;
    string mask;
    while (getline ( myFile , s)) {
        //Input sequence start
        //string s("mask = XXXXXXXXXXXXXXXXXXXXXXXXXXXXX1XXXX0X");

        if ( s.substr(0 , 4) == "mask" ) {

            //string mask;
            regex r("([0-1_X]+)");

            smatch m;

            regex_search(s, m, r);
            mask = m.str();

            getMasks(mask, ms[0], ms[1]);

            getMasks2(mask , maskPart20 , maskStarX);




        }
        else {
            //string s2("mem[8] = 11");
            regex rmem("([0-9]+)");
            smatch m;

            regex_search(s, m, rmem);
            unsigned long long memAdd = stoull(m.str());

            s = m.suffix();
            regex_search(s, m, rmem);
            unsigned long long val = stoull(m.str());
            //cout << val << endl;
            auto it = bloc.find(memAdd) ;
            if( it == bloc.end() ) {
                bloc.insert({memAdd, ((val & ms[0]) | ms[1])});
            }
            else {
                bloc.erase(it); // i did this to see if it'll change stuff. I am getting the incorrect answers
                bloc.insert({memAdd, ((val & ms[0]) | ms[1])});

            }
            //star2

            unsigned long long rawTemp = memAdd & maskPart20;

            for ( auto x : maskStarX) {
                auto y = rawTemp | x;
                auto it2 = star2.find(y);
                if(it2 != star2.end()) {
                    it2->second = val;
                }
                else {
                    star2.insert( {y , val});
                }
            }

        }
    }
    unsigned long long sum = 0;
    for ( auto it = bloc.begin() ; it != bloc.end() ; ++it) {

        sum += it->second;

    }
    cout << "star 1 : " << sum << endl;

    unsigned long long sums = 0;
    for ( auto it2 = star2.begin() ; it2 != star2.end() ; ++it2 ) {

        sums += it2->second ;
    }
    cout << "star 2: " << sums << endl;
    myFile.close();
    return 0;
}
