#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;
void CreatTxt(string pathName);

int main(){
	string rfilename;
	char c;
	
	cout <<"Enter the location of the file (relative or absolute path): "<<endl;;
	// cin >> rfilename;
	rfilename = "test.txt";
	CreatTxt(rfilename);

	ifstream ReadFile (rfilename);
	ofstream OutputFile ("output.txt");
	
	while(ReadFile.get(c)){
		if (islower(c)){
			c = toupper(c);
		}else if(isupper(c)){
			c = tolower(c);
		}else if(c== ' ' || c=='\n'){
			c = '!';
		}else if(isdigit(c)){
			c = '#';
		}
		OutputFile << c;	
	}

    cout<<"The output file will appear in the same path ! "<<endl;
	OutputFile.close();
	ReadFile.close();
	return 0;
}

void CreatTxt(string pathName){
 	ofstream fout(pathName);
 	if (fout) { 
		fout <<"ABCD efghijk 123"<< endl;
		fout <<"as&56 !55"<< endl;
		fout <<"54"<< endl;
  		fout.close();
 	}
}