#include <iostream>
using namespace std;
//e307 a523 a587 c259
char data[100000000];

int main(int argc, char const *argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	streambuf *buf = cin.rdbuf();
	streamsize ws = 1,cur;
	while(true){
		int c;
		for(c = buf->sgetc();;c = buf->snextc()){//continue?time
			if(c != ' ')
				break;
			else if(c == EOF)
				break;
		}
		if(c == EOF)
			break;
		cur = buf->pubseekoff(0,cin.cur);//last continuous ws
		if((ws - cur + 1) & 1)
			cout << ' ';
		cin >> data;
		cout << data;
		ws = (streamsize)buf->pubseekoff(0,cin.cur) + 1;//first continuous ws
	}
	cout.flush();
	return 0;
}