#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

struct instruction
        {
        public:
            string operation ;
            int offset;
            instruction (string s1 , int o ) {
                operation  = s1 ;
                offset = o;
                executed = false;
            }
            bool executed ;
        };

void display(instruction inx ){
    cout << inx.operation << " " << inx.offset << " " << inx.executed << endl;
}

int executeInstructions ( vector <instruction> vinx, vector <unsigned int> &jE, vector  <unsigned int> &nE ) {
    int accumulator = 0;

    auto it = vinx.begin();

    while(!it->executed) {
        it->executed = true;
        if(it->operation == "acc") {
            accumulator += it->offset;
            it++;
        }
        else if (it->operation == "jmp") {
            jE.push_back((it - vinx.begin()));
            it = it + it->offset;
        }
        else if (it->operation == "nop") {
            nE.push_back(it-vinx.begin());
            it++;
        }
        else {
            cout << it->operation <<endl;
            cerr <<"something went wrong. iterator loop" <<endl;
        }
    }
    return accumulator;
}
void star2 ( vector <instruction> vinx) {
    int accumulator = 0;

    vector<instruction>::iterator it;
    it = vinx.begin();

    while(!it->executed && it<vinx.end()) {
        it->executed = true;
        if(it->operation == "acc") {
            accumulator += it->offset;
            it++;
        }
        else if (it->operation == "jmp") {

            it = it + it->offset;
        }
        else if (it->operation == "nop") {
            it++;
        }
        else {
            cerr << it->operation <<endl;
            cerr <<"something went wrong. iterator loop" <<endl;
        }
    }
    if (it == vinx.end())
        cout << "Star 2 =" << accumulator;
}
int main() {
    ifstream myFile;
    myFile.open("input");

    stringstream ss;
    string temp;
    vector <instruction> aocInput ;

    while ( getline(myFile, temp)) {
        ss << temp;
        string op;
        int offst;
        char sign;
        ss >> op >>  sign >> offst;
        //cout << op << sign << offst;
        int multiplier = 0;
        if ( sign == '+') {
            offst*=1;
        }
        else if( sign == '-'){
            offst*=(-1);
        }
        else {
            cerr << "unexpected error! checking input and signs" <<endl;
        }
        aocInput.emplace_back( instruction ( op , offst));
        ss<<"";
        ss.clear();
        // i have had to use ss << "" and ss.clear(). Are there alternatives ???

    }
    /*
    for ( auto it = aocInput.begin() ; it != aocInput.end() ; ++it) {
        display(*it);
        cout << "x" <<endl;
    }
     */
    vector <unsigned int> jmpExecuted , nopExecuted;
    cout << "Star1 = " << executeInstructions( aocInput, jmpExecuted, nopExecuted)<< endl; //also gets me the distances between the jmps and nops and the begin iterator
    //Now I have codes that executed, and one of them is causing the loop.
    auto it = aocInput.begin();
    //Since I have the distance between the iterators, and the jmp and nop statements, I
    // will go through each one separately and chage only one and check for output.
    for(auto i : jmpExecuted ) {
        vector <instruction> temp = aocInput;
        auto it = temp.begin(); //so as to not change the aocInput. Figure out alternative later
        (it+i)->operation = "nop";
        star2(temp);
        // do i need temp.clear(); here ?? 
    }


    for(auto i: nopExecuted) {
        vector <instruction> temp = aocInput;
        auto it = temp.begin();  //so as to not change the aocInput. Figure out alternative later
        (it+i)->operation = "jmp";
        star2(temp);
        // do i need temp.clear() here ??
    }


    myFile.close();
    return 0;
}
