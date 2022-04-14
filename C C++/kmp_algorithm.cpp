#include <iostream>

using namespace std;
class KMP {
public:
    int vaild(string &s, string &p){
        int *failure = new int[p.length()]{0}, i, j = 0;
        for (i = 1; i < p.length(); i++){
            if (p[j] == p[i]) { failure[i] = (++j); }
            else { failure[i] = 0; }
        }
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
    string target, pattern;
    KMP k;
    while (cin >> target >> pattern) {
        int pos = k.valid(target, pattern);
        printf((pos > 0)? "%d\n": "Not Exist\n", pos);
    }
    return 0;
}
