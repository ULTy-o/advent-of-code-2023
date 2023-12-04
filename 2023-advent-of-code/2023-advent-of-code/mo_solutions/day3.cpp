//
//  day3.cpp
//  2023-advent-of-code
//
//  Created by Michael Osvald on 2023-12-03.
//
/*day 3
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include <regex>
#include <set>
using namespace std;
void getFileLines(string &file, vector<string> &out);
vector<int> findValidNums(vector<string> &in);
bool isAdjDigit(vector<string> &in, int x, int y);
int getDigitLine(vector<string> &in,int x,int y);
long getGearRatio(vector<string> &in,int x,int y);
vector<long> findRatioDigits(vector<string> &in);
int main()
{
    string data = "./data/data_3.txt";
    vector<string> lines;
    getFileLines(data, lines);
    vector<long> nums = findRatioDigits(lines);
    long sum = 0;
    for(int i =0;i<nums.size();i++){
        sum+= nums[i];
    }
    cout<<"Sum: "<<sum<<endl;
}

void getFileLines(string &file, vector<string> &out){
    ifstream infile;
    string input;
    infile.open(file);
    if (infile.is_open()){
        while (getline(infile,input)){
            input.erase(remove_if(input.begin(), input.end(), [](unsigned char x) { return isspace(x); }), input.end());
            out.push_back(input);
           cout<<input<<endl;
        }
    }
    infile.close();
}

vector<long> findRatioDigits(vector<string> &in){
    vector<long> digits;
    for(int y=0;y<in.size();y++){
        for(int x=0;x<in[y].size();x++){
            if (in[y][x]=='*'){
                long ratio = getGearRatio(in,x,y);
                digits.push_back(ratio);
            }
        }
    }
    
    
    return digits;
}
    
    long getGearRatio(vector<string> &in,int x,int y){
        set<int> foundRatio;
        int xStart = x-1;
        int yStart = y-1;
        int xEnd = x+2;
        int yEnd = y+2;
        long ratio=1;
        if (x==0){xStart++;}
        if (y==0){yStart++;}
        if (x==in[0].size()-1){xEnd--;}
        if (y==in.size()-1){yEnd--;}
        for(;xStart!=xEnd;xStart++){
            for(int yIter = yStart;yIter!=yEnd;yIter++){
                char point = in[yIter][xStart];
               // cout<<point<<endl;
                if (isdigit(point)){
                    int num = getDigitLine(in,xStart,yIter);
                    foundRatio.insert(num);
                }
            }
            cout<<endl;
        }
        if (foundRatio.size()<2){
            ratio = 0;}
        else{
            for (set<int>::iterator it=foundRatio.begin(); it!=foundRatio.end(); ++it){
                ratio *= *it;
            }
        }
        
        cout<<"ratio found: "<<ratio<<endl;
        return ratio;
    }
    
    int getDigitLine(vector<string> &in,int x,int y){
        int digit = 0;

        int iter = x;
       
        while(iter!=0 && isdigit(in[y][iter-1])){
            iter--;
        }
        cout<<endl;
        
        while(isdigit(in[y][iter])){
            //cout<<"("<<iter<<","<<y<<") - " <<in[y][iter]<< " ";
            digit*=10;
            digit+=(in[y][iter])-'0';
            iter++;
            
        }
        cout<<"result: "<<digit<<endl;
        return digit;
    }
//part one
/*vector<int> findValidNums(vector<string> &in){
    vector<int> digits;
    bool isDig = false;
    int currentDig = 0;
    for(int i=0;i<in.size();i++){
        if(isDig){
            cout <<"Adding: "<<currentDig<<endl;
            digits.push_back(currentDig);
        }
        currentDig=0;
        isDig=false;
        cout<<"------ROW: -----"<< i+1 <<endl;
        cout<<in[i]<<endl;
        for(int j=0;j<in[i].size();j++){
            char point = in[i][j];
            if (isdigit(point)){
                if (currentDig!=0){currentDig*=10;}
                currentDig+=(point)-'0';
                if (!isDig){
                    isDig = isAdjDigit(in,j,i);
                }
            }
            else{
                if(isDig){
                    cout <<"Adding: "<<currentDig<<endl;
                    digits.push_back(currentDig);
                }
                currentDig=0;
                isDig=false;
            }
        }//end line
      
    }
    return digits;
}

bool isAdjDigit(vector<string> &in, int x, int y){
    int xStart = x-1;
    int yStart = y-1;
    int xEnd = x+2;
    int yEnd = y+2;
    //cout<<xStart<<" o "<<yStart<<endl;
    //cout<<xEnd<<" o "<<xEnd<<endl;
    if (x==0){xStart++;}
    if (y==0){yStart++;}
    if (x==in[0].size()-1){xEnd--;}
    if (y==in.size()-1){yEnd--;}
    
    //cout<<xStart<<" o @"<<yStart<<endl;
    //cout<<xEnd<<" o @"<<xEnd<<endl;
    cout<<"checking"<< in[y][x]<<"--"<<endl;
    for(;xStart!=xEnd;xStart++){
        for(int yIter = yStart;yIter!=yEnd;yIter++){
            char point = in[yIter][xStart];
            cout << "("<<xStart<<","<<yIter<<")"<<"["<<point<<"]"<<"  ";
            if (!isdigit(point) && point != '.'){
                cout<<"fired"<<endl;
                return true;
            }
        }
        cout<<endl;
    }
    return false;
}
*/

