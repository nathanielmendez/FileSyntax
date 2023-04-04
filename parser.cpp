#include <string>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <fstream>

using namespace std;

bool strings = false;

void getColors(string word);

unordered_set <string> flow_control = {"for","if","else","return","in","while"};
unordered_set <string> types =        {"int","double","long","void","null","true","false","char","string"};
unordered_set <string> symbols =      {" ","(",")","[","]","{","}"};
unordered_set <string> functions =    {"range","i","isnumeric","sort","append","get","set","dict","not","in","input","def","print","pass"};
unordered_set <char> separators =     {' ','.','(',')',',','{','}',';',':','%','+','-','/','*','[',']','='};

void lexer(string line,int index,string word,vector<string> *split_word){
    if(index==line.size()){
        split_word->push_back(word);
        split_word->push_back(string(1,line[index]));
        return;
    }
    else if(separators.count(line[index])==1){
        split_word->push_back(word);
        string s(1,line[index]);
        split_word->push_back(s);
        word = "";
        lexer(line,++index,word,split_word);
    }else{
        word = word + line[index];
        lexer(line,++index,word,split_word);
    }
}



void parseString(string line){
    vector<string> split_word;
    lexer(line,0,"", &split_word);
    for(string s:split_word){
        getColors(s);
    }cout<<"\n";
}

void getColors(string word){
    if(flow_control.count(word)==1){
        cout << "\033[31m" << word << "\033[0m";
        return;
    }else if(types.count(word)==1){
        cout << "\033[34m" << word << "\033[0m";
        return;
    }else if(symbols.count(word)==1){
        strings = false;
        cout << "\033[33m" << word << "\033[0m";
        return;

    }else if(functions.count(word)==1){
        cout << "\033[32m" << word << "\033[0m";
        return;
    }else if(word[0] == '"'){
        strings = true;
    }
    
    if(strings == false){
        for(char s:word){
            if(!isdigit(s)){
                cout<<word;
                return;
            }else{
                continue;
            }
        }cout << "\033[34m" << word << "\033[0m";
    }

    else{
        cout << "\033[35m" << word << "\033[0m";
    }
}

