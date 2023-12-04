//
//  day4.cpp
//  2023-advent-of-code
//
//  Created by Michael Osvald on 2023-12-04.
//
/*
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

void getFileLines(string &file, vector<string> &out);
void removeCardNameText(vector<string> &out);
vector<string> splitGroups(vector<string> &in);
vector<vector<int>> splitData(vector<string> &in);
int getMatchCount(vector<int> &wins, vector<int> &nums);

bool containsNum(vector<int> &in, int num);
int main(){
    string data= "./data/data_4.txt";
    vector<string> lines;
    getFileLines(data, lines);
    removeCardNameText(lines);
    vector<string>winningString = splitGroups(lines);
    vector<vector<int>> winningNums = splitData(winningString);
    vector<vector<int>> nums = splitData(lines);
    vector<pair<int,int>> winCounts(nums.size(),pair(0,1));
 /// this is exteremly slow lol
    for(int i = 0;i<winCounts.size();i++){
        int matches = getMatchCount(winningNums[i], nums[i]);
        winCounts[i].first=matches;
        cout<<"card "<<i<<" matches "<<matches<<endl;
        for(int l=0;l<winCounts[i].second;l++){
            for(int j=0;j<matches;j++){
                cout<<"---- adding card "<<i+j+1<<endl;
                winCounts[i+j+1].second++;
            }
        }
    }
    int total=0;
    for(int i = 0; i<winCounts.size();i++){
        total+=(winCounts[i].second);
    }
    //int sum = getMatches(winningNums, nums);
    cout<<"Totat "<<total<<endl;
}

int getMatchCount(vector<int> &wins, vector<int> &nums){
    int matchCount = 0;
    for(int i =0; i<nums.size(); i++){
            if (containsNum(wins,nums[i])){
                matchCount++;
            }
        }
    return matchCount;
}

/* part 1
int getMatches(vector<vector<int>>wins, vector<vector<int>>nums){
    int sum=0;
    for(int i =0; i<nums.size(); i++){
        int matchCount = 0;
        for(int j=0;j<nums[i].size(); j++){
            if (containsNum(wins[i],nums[i][j])){
                matchCount++;
            }
        }
        if(matchCount==1){
            sum+=1;
        }
        else if(matchCount>1){
            sum+=pow(2,matchCount-1);
            cout<<"Adding to sum: "<<pow(2,matchCount-1)<<endl;
        }
    }
    return sum;
}
bool containsNum(vector<int> &in, int num){
    
    return find(in.begin(), in.end(), num) != in.end();
}

void getFileLines(string &file, vector<string> &out){
    ifstream infile;
    string input;
    infile.open(file);
    if (infile.is_open()){
        while (getline(infile,input)){
            //input.erase(remove_if(input.begin(), input.end(), [](unsigned char x) { return isspace(x); }), input.end());
            out.push_back(input);
           cout<<input<<endl;
        }
    }
    infile.close();
}

void removeCardNameText(vector<string> &out){
    for (int i=0;i<out.size();i++){
        size_t colon_pos = out[i].find(": ");
        out[i] = out[i].substr(colon_pos+1);
        cout <<"card number: " <<i+1 << "-" <<out[i]<<endl;
    }
}

vector<vector<int>> splitData(vector<string> &in){
    vector<vector<int>>out;
    for(int i=0;i<in.size();i++){
        vector<int>row;
        stringstream ss(in[i]);
        string numStr;
        int j=0;
        while (!ss.eof()) {
            getline(ss, numStr, ' ');
            if(isdigit(numStr[0])){
                row.push_back(stoi(numStr));
            }
        }
        out.push_back(row);
    }
    return out;
}

vector<string> splitGroups(vector<string> &in){
    vector<string> out;
    vector<string> inNew;
    bool isRight=false;
    for (int i=0;i<in.size();i++){
        stringstream ss(in[i]);
        string word;
        while (!ss.eof()) {
            getline(ss, word, '|');
            if (!isRight){
                cout<<" key line: "<<word<<endl;
                out.push_back(word);
                isRight = true;
            }
            else{
                inNew.push_back(word);
                isRight = false;
                cout<<" value line: "<<word<<endl;
            }
       }
    }
    in=inNew;
    return out;
}
*/
