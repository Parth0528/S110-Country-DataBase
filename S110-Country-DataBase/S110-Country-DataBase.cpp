// S110-Country-DataBase.cpp
//Author: P.Bhamare
//Create a parallel vector database holding information about countries of the world;

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

//Prototype------------------------------------------------
void makeDataBase(vector <string> &vcountry, vector <string>&vcapital, vector <string>&vcurrency, vector <string>&vlanguages);
void queryDataBase(vector <string>vcountry, vector <string>vcapital, vector <string>vcurrency, vector <string>vlanguages);
void populateVector(vector <string>& v, string fileName);
int sequentialSearch(vector<string> v, string strCountry);
int main()
{
	//database 
	vector <string> vcountry,vcapital,vcurrency,vlanguages;

	makeDataBase(vcountry, vcapital, vcurrency, vlanguages);
	queryDataBase(vcountry, vcapital, vcurrency, vlanguages);

}
//User Defined Functions-----------------------------------
void makeDataBase(vector <string> &vcountry, vector <string>&vcapital, vector <string>&vcurrency, vector <string>&vlanguages) {
	populateVector(vcountry, "C:/Temp/xCountry.txt");
	populateVector(vcapital, "C:/Temp/xCapital.txt");
	populateVector(vcurrency, "C:/Temp/xCurrency.txt");
	populateVector(vlanguages, "C:/Temp/xLanguage.txt");

}
void queryDataBase(vector <string>vcountry, vector <string>vcapital, vector <string>vcurrency, vector <string>vlanguages) {
	do {
		cout << "Enter Country [xxx to end]: ";
		string strCountry;
		getline(cin, strCountry);
		if (strCountry == "xxx")break;
		int pos = sequentialSearch(vcountry, strCountry);
		if (pos == -1)
			cout << "Sorry - No Data Found For Given Country" <<endl;
		else {
			cout << "Capital:     " << vcapital[pos] << endl;
			cout << "Currency:    " << vcurrency[pos] << endl;
			cout << "Language(s): " << vlanguages[pos] << endl;
		}

	} while (true);


}

void populateVector( vector <string> &v , string fileName) {
	ifstream infile(fileName);
	if (!infile) {
		cout << "Fatal Error - File Not Found!\n";
		exit(1);
	}
	string strValue;

	while (getline(infile, strValue)) {

		v.push_back(strValue);
	}
	infile.close();
}
int sequentialSearch(vector<string> v, string strCountry) {

	for (int i = 0; i < v.size(); i++) {
		if (strCountry == v[i])
			return i;
	}

	return -1;
}

