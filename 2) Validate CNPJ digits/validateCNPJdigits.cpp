#include <bits/stdc++.h>

using namespace std;

bool isNumber( char letra ) {
	if( letra > '9' || letra < '0')
		return false;
	return true;
}


bool isMadeOfNumber ( string str ) {
	for ( int i = 0; i < str.length(); i++ )
			if ( str[i] > '9' || str[i] < '0' ) {
				return false;
			}
	return true;
}

bool validateCNPJformat(string entrada) { // first exercise solution
	//string entrada;

	//cin >> entrada;

	if ( entrada.length() == 14 ) {
		// check if it's all numbers
		if( isMadeOfNumber( entrada ) ) {
			//cout << entrada << " is valid!" << '\n';
			return true;
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
				//cout << entrada << " is valid!" << '\n';
				return true;
			}
	
	//cout << entrada << " is invalid" << '\n';
	//cout << "length: " << entrada.length() << '\n';
	return false;
}

string onlyNumFormater(string str) {
	string formated = "12345678901234";
	for ( int i = 0, j = 0; i < str.length(); i++ )
		if ( isNumber(str[i]) ) {
			//cout << str[i] << " is a number!\n";
			formated[j] = str[i];
			j++;
		}
	return formated;
}

int main() {

	string entrada;
	cin >> entrada;
	int pesos1[] = {5,4,3,2,9,8,7,6,5,4,3,2};	// weight?... 1st verification number
	int pesos2[] = {6,5,4,3,2,9,8,7,6,5,4,3,2}; // weight?... 2nd verification number
	int soma = 0;
	int primeiroDigitoVerificador, segundoDigitoVerificador;


	if ( !validateCNPJformat(entrada) ) {
		cout << entrada << " is not valid!" << '\n';
		return 0;
	}

	// Remove anything that is not a number
	string entradaFormated = onlyNumFormater(entrada);
	//cout << entrada << '\n' << entradaFormated << '\n';

	if (entradaFormated == "00000000000000" || 
		entradaFormated == "11111111111111" || 
		entradaFormated == "22222222222222" || 
		entradaFormated == "33333333333333" || 
		entradaFormated == "44444444444444" || 
		entradaFormated == "55555555555555" || 
		entradaFormated == "66666666666666" || 
		entradaFormated == "77777777777777" || 
		entradaFormated == "88888888888888" || 
		entradaFormated == "99999999999999") {
		cout << entrada << " is not a valid CNPJ!\n";
		return 0;
	}
	

	// ----- 1st Verification Number -----
	//soma = 0;
	for ( int i = 0; i < 12; i++) {
		/*
		ASCII table...
		numberAsChar - '0' = numberAsInt.
		Ex.: '4' - '0' = 4
		*/
		soma += (entradaFormated[i]-'0') * pesos1[i];
		//cout << entradaFormated[i] << " * " << pesos1[i] << " = " << (entradaFormated[i]-'0') * pesos1[i] << '\t' << soma << '\n';
	}
	
	if ( soma%11 < 2 )
		primeiroDigitoVerificador = 0;
	else 
		primeiroDigitoVerificador = 11 - soma%11;

	if (entradaFormated[12]-'0' != primeiroDigitoVerificador){
		cout << entrada << " is not a valid CNPJ!\n";
		return 0;
	}
	//cout << "Primeiro Digito Verificador = " << primeiroDigitoVerificador << '\n';
	// END ----- 1st Verification Number -----
	
	// ----- 2nd Verification Number -----
	soma = 0;
	for (int i = 0; i < 13; i++) {
		soma += (entradaFormated[i]-'0') * pesos2[i];
	}
	if (soma%11 < 2)
		segundoDigitoVerificador = 0;
	else
		segundoDigitoVerificador = 11 - soma%11;

	if (entradaFormated[13]-'0' != segundoDigitoVerificador){
		cout << entrada << " is not a valid CNPJ!\n";
		return 0;
	}
	//cout << "Segundo Digito Verificador = " << segundoDigitoVerificador << '\n';
	// END ----- 2nd Verification Number -----


	cout << entrada << " is a valid CNPJ!\n";
	
	return 1;
}