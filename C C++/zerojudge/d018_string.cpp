#include <stdio.h>
#include <iostream>
#include <string>

int main(){
	std::string s;
	while(std::getline(std::cin,s)){
		double e_o[2] = {0,0};
		while(s.find(' ') != -1){
			std::string ss[2] = {s.substr(0,s.find(' ')),s.substr(s.find(' ') + 1,s.length())};
			std::string i_d[2] = {ss[0].substr(0,ss[0].find(':')),ss[0].substr(ss[0].find(':') + 1,ss[0].length())};
			int index = atoi(i_d[0].c_str());
			double num = stod(i_d[1]);
			e_o[index % 2] += num;
			s = ss[1];
		}
		std::string i_d[2] = {s.substr(0,s.find(':')),s.substr(s.find(':') + 1,s.length())};
		int index = atoi(i_d[0].c_str());
		double num = stod(i_d[1]);
		e_o[index % 2] += num;
		std::cout << e_o[1] - e_o[0] << "\n";
	}
	return 0;
}
