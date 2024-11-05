#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


int Count_Vowel(string str) 
{ 
//   transform(str.begin(), str.end(), str.begin(), ::tolower); 
	int count = 0; 
	for(auto ele:str){
        
		if (ele == 'a' || ele == 'e' || ele == 'i'
			|| ele == 'o' || ele == 'u') { 
			count++; 
		} 
	} 

	return count; 
} 

int main() 
{ 
	
	string str;
    getline(std::cin, str);
    
    // cout<<str<<endl;
    cout<<Count_Vowel(str)<<endl;
	return 0; 
} 

