/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>

using namespace std;
int getAnswer (vector <int> n) {
   for( int i = 0 ; i <= n.size()-2 ; ++i) {
       for (int j= i+1 ; j <= n.size()-1 ; ++j) {
           if (2020==(n[i]+n[j])) {
               return (n[i]*n[j]);
           }
       }
   } 
   return -1;
}
int getAnswer2(vector <int> n) {
    for(int i = 0; i<=n.size()-3 ; ++i){
        for(int j=i+1; j<=n.size()-2;++j){
            for(int k=j+1; k<=n.size()-1;++k) {
                if(2020==(n[i]+n[j]+n[k])) {
                    return (n[i]*n[j]*n[k]);
                }
            }
        }
    }
    return -1;
}
int main()
{
    vector <int> n;
    int temp;
    while (cin >> temp) {
        n.push_back(temp);
    }
    cout << getAnswer(n) << endl;
    cout << getAnswer2(n) << endl;

    return 0;
}
