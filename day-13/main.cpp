#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;
long long inv(long long a, long long m) { //a > m
    long long m0 = m, t, q;
    long long x0 = 0, x1 = 1;

    if (m == 1)
        return 0;

    // Apply extended Euclid Algorithm
    while (a > 1)  {
        // q is quotient
        q = a / m;

        t = m;

        // m is remainder now, process same as
        // euclid's algo
        m = a % m, a = t;

        t = x0;

        x0 = x1 - q * x0;

        x1 = t;
    }

    // Make x1 positive
    if (x1 < 0)
        x1 += m0;

    return abs(x1);
}
void star2crt ( vector <pair<int , int>> v ) {

    long long p = 1;
    long long sums = 0;
    for ( auto i : v ) {
        p *= i.first;

    }

    for (auto i : v ) {
        long long pp = p/i.first;
        sums += ((i.first - i.second) % i.first ) * pp * inv( pp ,i.first ) ; // i[0]-i[1] bcuz that would be the remainder at the numbers...
    }


    cout << sums % p << endl;


}
bool checkStar2 ( long long n , vector <pair <int , int>> bM , int d ) {
    for ( auto i : bM ) {

        if ( (( n + i.second - d ) % i.first) != 0 ) {

            return false;
        }
    }
    return true;
}

void star2 ( vector <pair <int,int>> busIdAndMinutes ) { //A brute force solution. Takes too long.
    //I jumped between iterations with max. and using offset. However, it still takes too long.
    auto &bM = busIdAndMinutes;
    int max = 0;
    int displacement;
    for(auto i : bM) {
        if ( i.first > max) {
            max = i.first;
            displacement = i.second;
        }
    }
    cout << max << " " << displacement << endl;
    long long s2 = -1;
    for ( long long  i = max ;   ;  i = i+max ) {
        if ( checkStar2 ( i , bM , displacement) ) {
            s2 = i - displacement;
            break;
        }
    }
    cout << "star2 " << s2 << endl;
}
int star1 ( int timestamp , vector <int> busId ) {
    int min = timestamp;
    int bus = -1;
    for ( auto i : busId) {
        int x = timestamp % i;
        int timeLeft;
        if (x != 0 ) {
            timeLeft = i - x; }
        else {
            timeLeft = x;
        }

        if ( timeLeft < min ) {
            min = timeLeft;
            bus = i;
        }

    }
    //cout << bus << " " << min << " wait" << endl; //gives you the busId and the wait
    return bus * min;

}

int main() {
    //std::cout << "Hello, World!" << std::endl;

    ifstream myFile;
    myFile.open("input");

    int earliestTimestamp ;

    string temp;
    getline(myFile , temp);

    earliestTimestamp = stoi(temp);
    vector <int> busId ;
    int counter = 0;
    vector <pair <int , int >> busMin;
    string id = "";

    string temp2 ;



   while (getline ( myFile, temp , ',')){
       if ( temp == "x" ) {
           counter ++;
           continue;
       }
       int b = stoi(temp);
       busId.push_back(b);
       busId.push_back(b);

       busMin.push_back ( { b , counter});
       counter++;
    }


    cout << star1( earliestTimestamp , busId) << endl;
    //star2( busMin); //bruteforce, takes too long.
    star2crt(busMin);
    myFile.close();
    //cout << checkStar2(1068785 , busMin , 4) << endl;
    return 0;
}
