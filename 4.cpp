#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector <string> split(string target, string delimiter);

int main(){
    string target, delimiter;

    cout<<"Please enter a string : ";
    getline(cin, target);
    cout<<"Please enter a delimiter : ";
    getline(cin, delimiter);
    int i;

    for(i = 0;i<split(target, delimiter).size();i++){
        cout<<split(target, delimiter)[i];
        cout<<' ';
    }
    cout<<endl;
    return 0;
}

vector <string> split(string target, string delimiter){
    vector <string> output;
    int i, j, start;
    int check;
    start = 0;
    
    for(i = 0;i<target.length();i++){
        check = 0;
        if (target[i]==delimiter[0]){
            for (j = 0; j <delimiter.length();j++){
                if (target[i+j]!=delimiter[j]){
                    break;
                }
                check = 1;
            }
            if (check == 1){
                output.push_back(target.substr(start, i-start));
                start = i+delimiter.length();
            }
        }
        if(i==target.length()-1){
            if (target[i] == '.'){
                output.push_back(target.substr(start,i-start));            
            }else{
                output.push_back(target.substr(start));
            }
        }
    }
    return output;
}
