#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <map>
#include <algorithm>
#include <set>
#include <deque>

using namespace std;
pair <long long , long long > getSum (vector <long long> v) {
    long long sum = 0;
    for ( auto it : v) {
        sum += it;
    }
    sort(v.begin(), v.end());
    return {sum , *v.begin() + *(v.end()-1)};
}
map <long long, long long > stars(vector <long long> v , int length) {

    map <long long, long long> temp;
    for ( auto it = v.begin() ; it != v.end(); ++it) {
        vector < long long > tempVec ;
        for (auto it2 = it ; (it2 - it) != length && it2!= v.end() ; it2++) {

            tempVec.push_back(*it2);

        }
        temp.insert(getSum(tempVec));
    }

    //length++;

    return temp;
}

set <long long> getSums (deque <long long> d  ) {
    set <long long> sums;
    for ( decltype(d.size()) i = 0 ; i < d.size() -1; ++i ) {
        for (decltype(d.size()) j = i+1 ; j < d.size() ; ++j) {
            if(d[i] != d[j]) {
                sums.insert(d[i]+d[j]);
            }
        }
    }
    return sums;
}
long long  start(vector <long long> v , int p)  {
    set <long long> sums ;
    deque <long long> deck; // lets' figure out how to use deque today
    for ( auto it = v.begin() ; (it - v.begin()) != p; ++it) { // 0 to pth number
        deck.push_back(*it); // got deck ready. First time using it :)
    }
    for( auto it = v.begin() + p ; it != v.end() ; ++it ) {

        sums = getSums(deck);

        if ( sums.find(*it) == sums.end()) {
            return *it;
        }

        deck.erase(deck.begin());

        deck.push_back(*it);

        sums.clear();

    }
    cout << "wtf" << endl;
    return -1;
}
long long star2 ( vector <long long> v, long long star1) {
    long long sum = 0;
    auto itStart = v.begin();
    auto itEnd = v.begin();

    while ( sum != star1 && itStart != v.end()-1) { // now use pointers for the biggest elements ?
        if (itStart == itEnd) {
            itEnd = itStart +1;
            sum = *itStart + *itEnd;
            continue;
        }
        if(sum < star1) {
            ++itEnd;
            sum+= *itEnd;
        }
        else if (sum > star1) {
            sum -= *itStart;
            ++itStart;
        }

    }

    //partial sort
    sort (itStart, itEnd+1 );
    return (*itStart + *itEnd);
}
int main() {
    ifstream myFile;
    myFile.open("input");
    istringstream iss ;
    long long number;
    vector <long long> vecNumbers;
    while ( myFile >> number) {
        vecNumbers.push_back(number); //putting numbers in vecgtor
    }
    // To clear iss of eof, and flags and bits >
    //iss.str("");
    //iss.clear();
    int preamble = 25;
    long long star1 = start (vecNumbers , preamble);
    cout << star1 <<endl;
    /*
    map < long long , long long > m;
    int l = 2;
    long star2 = 0;

    for ( auto it = vecNumbers.begin() ; it != vecNumbers.end() && l <= vecNumbers.size() ; ++it) {
        m.merge( stars(vecNumbers , l));
        l++;
        auto it2 = m.find(star1);
        if( it2 != m.end()) {
            //cout << "here " <<endl;
            star2 = it2->second;
            //cout << it2->second;
        }
        m.clear();
    }
     */
    // star2 is much faster

    cout << star2( vecNumbers, star1) <<endl;
    myFile.close();
    return 0;
}
