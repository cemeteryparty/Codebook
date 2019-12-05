#include <iostream>

void postorder(std::string pre,std::string in){
	if(pre.length() == 1){
		std::cout << pre[0];
		return;
	}
	int root = in.find(pre[0]);
	std::string subin[2] = {in.substr(0,root),in.substr(root + 1,in.length())};
	std::string subpre[2] = {pre.substr(1,root),pre.substr(root + 1,in.length())};
	std::string rootstr = "";
	rootstr += pre[0];
	if(subpre[0].length())
		postorder(subpre[0],subin[0]);
	if(subpre[1].length())
		postorder(subpre[1],subin[1]);
	postorder(rootstr,rootstr);
}
int main(int argc,char const *argv[]){
	std::string s1,s2;
	while(std::cin >> s1 >> s2){
		postorder(s1,s2);
		std::cout << '\n';
	}
	return 0;
}