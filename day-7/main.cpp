#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;
bool canContainSG ( vector <string> s, vector <vector<string>> v) {
    auto itX = s.begin();
    if(*itX == "shinygold" ) {
        return true;
    }

    ++itX;
    while(itX != s.end()) {
        for(auto itY = v.begin() ; itY!= v.end() ; ++itY) {
            if(*itX == (*itY)[0]) {
                if (canContainSG(*itY, v)){
                    //cout <<"\t" << *itX << endl;
                    return true;
                }
            }
        }
        ++itX;
    }

    return false;
}
int containsBags ( vector < pair< int ,string>> s, vector <pair <string, vector < pair <int ,string> > >> v) {
    int n = 1;
    if ( s.empty()) {
        return 1;
    }


    for ( auto it = s.begin() ; it != s.end() ; ++it) {

        for ( auto it2 = v.begin() ; it2 != v.end() ; ++it2) {

            if( it->second == it2->first ) {
                n += it->first*containsBags( it2->second, v);

            }
        }

    }

    // if empty it'll skip for loop
    return n; // or 0 ?
}

int main() {
    stringstream ss;
    string temp;
    ifstream myFile;
    myFile.open("input1");
    vector <vector <string>> bagsWithBags;
    vector <pair <string, vector < pair <int ,string> > >> bags;


    while (getline(myFile , temp)) {

        ss.str(temp);
        string bagColor1, bagColor2;
        ss>> bagColor1 >> bagColor2;
        string throwaway, throwaway2;
        bagColor1 +=bagColor2;

        vector <string> justBagColors;

        justBagColors.push_back(bagColor1);
        //cout << bagColor1<<endl;
        ss >> throwaway >> throwaway2;

        int numberOfBags;
        string insideBagC1 ,insideBagC2;
        pair <string, vector < pair <int, string>> > current;
        current.first = bagColor1;

        while(ss >> numberOfBags >> insideBagC1 >> insideBagC2) {

            pair <int, string> numColor ;
            insideBagC1 += insideBagC2;
            numColor = make_pair(numberOfBags, insideBagC1);
            current.second.push_back(numColor);

            justBagColors.push_back(insideBagC1);
            ss>>throwaway;
        }
        /*if(current.second.empty()) {
            pair numNBag = make_pair( 0 , "x");
            current.second.push_back(numNBag);
        }*/
        bags.push_back(current);
        bagsWithBags.push_back(justBagColors);
        ss.str("");
        ss.clear();


    }
    //cout << bagsWithBags[577][2] << endl;
    string test = "shinygold";
    int n = 0;
    
    for(auto it = bagsWithBags.begin() ; it != bagsWithBags.end() ; ++it) {
        //cout << it->second.size() <<endl;
        if ((*it)[0] != "shinygold") {

            if (canContainSG(*it , bagsWithBags)){
                //cout << (*it)[0] <<endl;
                n++; }
        }
    }

    cout << n <<endl;
    int n2 = 0;
    for(auto i = bags.begin() ; i != bags.end() ; ++i)  {
        if ( i->first == "shinygold") {
            //cout << i->second[0].first << endl;
            n2 = containsBags( i->second , bags) - 1 ;
        }

    }
    //cout << bags[6].second[0].second<<endl;
    cout << n2 << endl;


    return 0;
}
