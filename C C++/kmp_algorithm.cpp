#include <iostream>

using namespace std;
class KMP {
public:
    int valid(string &s, string &p){
        int *failure = new int[p.length()]{0}, i, j = 0;
        for (i = 1; i < p.length(); i++){
            while (j && p[j] != p[i]) {
                j = failure[j - 1];
            }
            if (p[j] == p[i]) { failure[i] = (++j); }
        }
        // printf("F[]\n");
        // for (i = 0; i < p.length(); i++){
        //     printf("%c:%d ", p[i], failure[i]);
        // }
        // printf("\n");
        i = j = 0;
        while (i < s.length() && j < p.length()) {
            if (s[i] == p[j]) {
                i++, j++;
            }
            else {
                if (j) { j = failure[j - 1]; }
                else { i++; }
            }
        }
        delete [] failure; 
        // return j == p.length();
        return j < p.length()? -1: i - p.length();
    }
};

int main(int argc, short const *argv[]){
    string target = "zzzzzzzaabc__aabc_a__aab__zzzz", pattern="aabc__aabc_a__aab__";
    KMP k;
    int pos = k.valid(target, pattern);
    printf((pos > 0)? "%d\n": "Not Exist\n", pos);
    return 0;
}
