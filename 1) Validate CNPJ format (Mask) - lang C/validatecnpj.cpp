#include <bits/stdc++.h>

using namespace std;

bool isMadeOfNumber ( string str ) {
	for ( int i = 0; i < str.length(); i++ )
			if ( str[i] > '9' || str[i] < '0' ) {
				return false;
			}
	return true;
}

int main() {
	string entrada;

	cin >> entrada;

	if ( entrada.length() == 14 ) {
		// check if it's all numbers
		if( isMadeOfNumber( entrada ) ) {
			cout << entrada << " is valid!" << '\n';
			return 1;
		}
	}
	else if ( entrada.length() == 18 )
		// check if it's "01.345.789/1234-67"
		if ( entrada[2] == '.'  && entrada[6] == '.' && entrada[10] == '/' && entrada[15] == '-' )
			if (
				isMadeOfNumber( entrada.substr(0, 2) ) &&
				isMadeOfNumber( entrada.substr(3, 3) ) &&
				isMadeOfNumber( entrada.substr(7, 3) ) &&
				isMadeOfNumber( entrada.substr(11, 4) ) &&
				isMadeOfNumber( entrada.substr(16, 2) )
				)
			{
				cout << entrada << " is valid!" << '\n';
				return 1;
			}
	
	cout << entrada << " is invalid" << '\n';
	cout << "length: " << entrada.length() << '\n';
	return 0;
}