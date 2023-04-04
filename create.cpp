#include <string>
#include <iostream>
#include <fstream>

using namespace std;

void createFile(){
    string name;
    cout<<"Enter the filename \n";
    cout<<"File: ";
    cin>>name;
    cout<<"\n";
    fstream file;
    file.open(name,ios::out);

    cout<<"^x: Save file\n";
    cout<<"^q: Leave without saving \n";
    cout<<"Enter text: \n";
    while(true){
        string input;
        getline(cin,input);
        if(input == "^q"){
            file.close();
            remove(name.c_str());
            break;
        }else if(input == "^x"){
            file.close();
            cout<<"File saved! \n";
            break;
        }else{
            file<<input<<"\n";
        }
    }
}