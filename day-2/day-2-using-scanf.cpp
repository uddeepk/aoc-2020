#include <iostream>
#include <string>

using std::string;

bool validPass( int mn , int mx, char c, string s) {
    int count = 0;
    for( char a : s) {
        if(a==c)
            ++count;
    }
    return (count >= mn && count <= mx) ;
}
bool validPass2( int i1 , int i2 , char c , string s) { //part 2
    // Exacty one of the positions must contain the character
    // Exclusive or would work.
    return s[i1]==c ^ s[i2]==c;
}
int main() {
    int min, max;
    char c;
    char s[100];
    int pass = 0;
    int pass2 = 0;
    int i = 0;
    while (scanf("%d-%d %c: %s" ,&min, &max, &c, s )!=EOF) {

        if (validPass(min, max, c, s))
            ++pass;
        //std::cout << sizeof(s) << std::endl; //wtf
        if (validPass2(min-1, max-1, c, s))
            ++pass2;
    }
    std::cout << pass << " " << pass2 << std::endl;
    return 0;
}
