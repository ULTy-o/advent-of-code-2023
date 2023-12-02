//
//  day1.cpp
//  2023-Advent-Of-Code
//
//  Created by Michael Osvald on 2023-12-01.
//

#include <algorithm>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <regex>
using namespace std;
void getFileLines(string& file, vector<string>& out);
int getDigits(string input, bool isFirst);
int alphaToDigit(string number);

int _main(int argc, const char * argv[]) {
    vector<string> inputs;
    string me ="./data/data_1.txt";
    getFileLines(me ,inputs);
    int sum = 0;
    for(int i = 0; i <inputs.size();i++){
        int firstDigit = -1;
        int secondDigit = -1;
        string line = inputs[i];
        cout<<line<<endl;
        firstDigit=getDigits(line,true);
        secondDigit=getDigits(line,false);
        cout<< "first digit :"<<firstDigit<<" second digit: "<<secondDigit<<endl;
        firstDigit*=10;
        int digitSum =(firstDigit+secondDigit);
        cout<<digitSum<<endl;
        sum+=digitSum;
    }//end i
    cout<<"Sum: "<<sum<<endl;
    return 0;
}

void _getFileLines(string &file, vector<string> &out)
{
    ifstream infile;
    string input;
    infile.open(file);
    if (infile.is_open()){
        while (getline(infile,input)){
            out.push_back(input);
        }
    }
    infile.close();
}

int getDigits(string input, bool isFirst)
{
    string chars = "";
    regex r("one.*|two.*|three.*|four.*|five.*|six.*|seven.*|eight.*|nine.*");
    regex r2("one|two|three|four|five|six|seven|eight|nine");
    sregex_iterator it = sregex_iterator(input.begin(), input.end(), r2);
    sregex_iterator end_it =  sregex_iterator();

    string alpha_num = "";
    int alpha_pos = -1;
    if (isFirst){
        for(; it!= end_it; it++){
            alpha_num = it->str();
            alpha_pos = (int)it->position();
            if (isFirst){break;}
        }
    }
    else{
        string tmp = "";
        for(int i = (int)input.size()-1;i>0;i--){
            tmp = input[i]+tmp;
           // cout<<tmp<<endl;
            if (regex_match(tmp,r)){
                alpha_num = tmp;
                alpha_pos = i;
             //   cout<<tmp<<endl;
                i=0;
            }
        }
        sregex_iterator it = sregex_iterator(tmp.begin(), tmp.end(), r2);
        sregex_iterator end_it =  sregex_iterator();
        alpha_num = it->str();
    }
    
    char digit_num = ' ';
    int digit_pos = -1;
    for(int i = 0; i < input.size(); i++){
        if (isdigit(input[i])){
            digit_num = input[i];
            digit_pos = i;
            if (isFirst){break;}
        }
    }
    
    int result = 0;
    if (digit_pos != -1){
        result = digit_num - '0';
    }
    if(isFirst && alpha_pos!=-1){
        if(digit_pos==-1 ||alpha_pos < digit_pos ){
            cout<<"getting alpha"<<endl;
            result = alphaToDigit(alpha_num);
        }
    }
    else if (!isFirst&&alpha_pos!=-1){
        if(digit_pos==-1 ||alpha_pos > digit_pos ){
            cout<<"getting alpha"<<endl;
            result = alphaToDigit(alpha_num);
        }
    }

    return result;
}

int alphaToDigit(string number){
    int result = 0;
    if(number == "one"){
        result = 1;
    }
    else if(number == "two"){
        result = 2;
    }
    else if(number == "three"){
        result = 3;
    }
    else if(number == "four"){
        result = 4;
    }
    else if(number == "five"){
        result = 5;
    }
    else if(number == "six"){
        result = 6;
    }
    else if(number == "seven"){
        result = 7;
    }
    else if(number == "eight"){
        result = 8;
    }
    else{
        result = 9;
    }
    return result;
}
