#include <iostream>

int kmp_method(std::string pat,std::string tar){
	int failure[pat.length()];
	for(int i = 1,j = failure[0] = -1;i < pat.length();i++){
		while(j >= 0 && pat[j + 1] != pat[i])
			j = failure[j];
			if(pat[j + 1] == pat[i]) 
				j++;
			failure[i] = j;
	}
	    /*
	    printf("Failure Function:\n");
	    for(int i = 0;i < pat.length();i++)
	    	printf("%d ",failure[i]);
	    printf("\n");
	    */
	int posP = 0,posT = 0;
	while(posP < pat.length() && posT < tar.length()){
		if(pat[posP] == tar[posT]){
			posT++;
			posP++;
		}
		else{
			if(!posP)
				posT++;
			else
				posP = failure[posP - 1] + 1;
		}
	}
	return (posP < pat.length())?-1:posT - pat.length();
}
int main(int argc, char *argv[]){
	//std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
	std::string pat,str;
	while(std::cin >> pat >> str){
		int pos = kmp_method(pat,str);
	    printf((pos > 0)?"%d\n":"Not Exist\n",pos);
	}
	return 0;
}