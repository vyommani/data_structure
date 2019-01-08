#include<stdio.h>
#include<string.h>

int checkIfAnagrams(char* first, char* second){
    if(first == NULL || second == NULL)
	    return 0;
    else if(strlen(first) == 0 || strlen(second) == 0)
	    return 0;
    else if(strlen(first) != strlen(second))
	    return 0;
    else{
    	char arr[256]; // only ASCII
	memset(arr, 0, 256);
	while(*first != 0){
	    arr[*first] += 1;
	    first++;
	}
	while(*second != 0){
	    arr[*second] -= 1;
	    second++;
	}
	int result=0;
	for(int i=0;i< 256; i++){
	    result+=arr[i];
	}
	return ( result == 0);
    }
}

void runCheck(char* first, char* second){
    if(checkIfAnagrams(first, second)){
        printf("\n%s, and %s, are anagrams\n", first, second);
    }else{
        printf("\n%s, and %s, are not anagrams\n", first, second);
    }
}

int main(){
    char* first="stackoverflow";
    char* second="flwerovstack";

    runCheck(first,second);
    runCheck("vyommanitewari", "tewarivyommani");
    runCheck(NULL, NULL);
    runCheck("", "");
    return 0;
}
