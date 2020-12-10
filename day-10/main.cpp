#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>
#include <set>
#include <deque>
#include <string>
#include <list>
using namespace std;
/*Day-10 AoC 2020
 * Uddeep Karki
 *
/*long long*/ void star2test ( vector <int> v , map <int , long long > &p) { // This is my solution, couldn't clean it up
    long long n = 0;


    auto it = v.begin()+1;

    while ( *v.begin() - *it <= 3 && it!= v.end()) {
        auto it2 = p.find(*it);
        n = n +  it2->second;
        //cout << "here "<< endl;
        it++;
    }
    //return n ;
    if(v[0] == 0) {
        n =  1;
    }
    p.insert( { *v.begin() , n }) ;
}
long long star2 ( vector <int> v) {  //The recursive function that would have worked. However, too big an input and ....

    if(v[0] == 0) {
        return 1;
    }
    long long n = 0;
    auto it = v.begin()+1;

    while ( *v.begin() - *it <= 3 && it!= v.end()) {
        n = n +  star2 ( vector <int > (it , v.end()) );
        it++;
    }
    return n ;
}

int main() {
    ifstream myFile;
    myFile.open("input");
    deque <int> joltageAdapters;
    stringstream ss;
    int adapter;
    while (myFile >> adapter) {
        joltageAdapters.push_back(adapter);
    }
    sort(joltageAdapters.begin(), joltageAdapters.end());
    //ss.str("");
    //ss.clear();

    int jump1 = 0; int jump3 = 0;

    joltageAdapters.push_front(0);
    joltageAdapters.push_back(*(joltageAdapters.end()-1) + 3);
    for(auto it = joltageAdapters.begin()+1 ; it != joltageAdapters.end() ; ++it ) {
        auto d = *it - *(it-1) ;
        switch(d) {
            case 1:
                jump1++;
                break;
            case 3:
                jump3++;
                break;
        }


    }
    map <int , long long > paths ;

    for ( auto it = joltageAdapters.begin(); it!= joltageAdapters.end() ;++it) {
        ///////////////////////////////
        // Revisit : Use STL or other tools to clean up the next two lines.
        vector <int > subVec ( joltageAdapters.begin() , it +1 );
        vector <int> subVecRev ( subVec.rbegin() , subVec.rend()) ;

        star2test ( subVecRev , paths);
        //cout << testxyz.size() << " " << testxyz[0] << endl;
        //break;
    }

    cout << "star1: " << jump1*jump3 << " star2: " << paths.rbegin()->second<<endl;
    //vector <int> v2 ( joltageAdapters.rbegin(), joltageAdapters.rend());
    //cout << star2(v2) <<endl;

    myFile.close();
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}
