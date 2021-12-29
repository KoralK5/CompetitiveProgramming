#include <iostream>
#include <vector>
using namespace std;

int main() {
	int x,y;
	cin>>x>>y;
	vector<vector<int>> s(100, vector<int>(100, 0));
	s[50][50]=x;
	char dir='d';
	int locX=50, locY=50;
	for (int i=x+1; i<=y; i++) {
		if (dir=='d') {
			locX++;
			if (s[locX][locY+1] == 0) dir='r';
		}
		else if (dir=='u') {
			locX--;
			if (s[locX][locY-1] == 0) dir='l';
		}		
		else if (dir=='l') {
			locY--;
			if (s[locX+1][locY] == 0) dir='d';
		}
		else if (dir=='r') {
			locY++;
			if (s[locX-1][locY] == 0) dir='u';
		}
		s[locX][locY] = i;
	}
	while (true) {
		if (dir=='d') {
			locX++;
			if (s[locX][locY+1] == 0) break;
		}
		else if (dir=='u') {
			locX--;
			if (s[locX][locY-1] == 0) break;
		}		
		else if (dir=='l') {
			locY--;
			if (s[locX+1][locY] == 0) break;
		}
		else if (dir=='r') {
			locY++;
			if (s[locX-1][locY] == 0) break;
		}
		s[locX][locY] = -1;
	}

			
	for (int i=0; i<100; i++) {
		int pr=false;
		for (int j=0; j<100; j++) {
			if (s[i][j] == -1) {
				cout<<"   ";
			}
			else if (s[i][j] != 0) {
				if (s[i][j] < 10) {
					cout<<" ";
				}
				cout<<s[i][j]<<" ";
				pr=true;
			}
		}
		if (pr) {
			cout<<'\n';
		}
	}
}	
			
	
	
