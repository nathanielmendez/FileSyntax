#include <iostream>
#include <fstream>
#include "parser.cpp"
#include "create.cpp"
#include <string>

using namespace std;

int main(){
    int input = -1;
    cout<<"Welcome to Texitor \n";
    cout<<"Please select an option: \n";
    cout<<"1. Create a file \n";
    cout<<"2. View a file \n";
    cout<<"3. Exit \n";
    while(input<0 || input > 3){
        cout<<"Selection: ";
        cin>>input;
        if(input>0 && input < 4){
            break;
        }else{
            cout<<"\n Invalid option \n";
            cin.clear();
            cin.ignore(1000,'\n');
        }
    }

    switch (input){
        case 1:
            createFile();
            break;

        case 2:
            {
                string name;
                cout<<"Enter a filename with path included \n";
                cout<<"File: ";
                cin>>name;
                cout<<"\n";
                ifstream file;
                file.open(name);
                string line;
                int size = name.size();
                string extension{name[size-3],name[size-2],name[size-1]};
                while(getline(file,line)){
                    if(extension=="txt"){
                        cout<<line<<"\n";
                    }else{
                        parseString(line);
                    }
                }
            }
            break;

        case 3:
            cout<<"Goodbye.";
            break;
        
        default:
            cout<<"Unknown Error. Exiting.."<<"\n";
            break;
    }

    return 0;
}