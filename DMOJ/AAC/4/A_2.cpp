#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

void SplitString(string s, vector<string> &v){
	
	string temp = "";
	for(int i=0;i<s.length();++i){
		
		if(s[i]==' '){
			v.push_back(temp);
			temp = "";
		}
		else{
			temp.push_back(s[i]);
		}
		
	}
	v.push_back(temp);
}

int main() {
	ifstream cin("A.in");
	int n, m;
	cin>>n>>m;

	string s;
	cin>>s;



	vector<string> a(m);
	for (int i=0; i<m; i++) {
		cin>>a[i];
	}

}
