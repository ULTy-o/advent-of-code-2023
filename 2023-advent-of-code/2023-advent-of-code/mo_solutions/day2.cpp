//
//  day2.cpp
//  2023-advent-of-code
//
//  Created by Michael Osvald on 2023-12-02.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <fstream>
/*
 #include <vector>
#include <string>
#include <regex>
using namespace std;

void _getFileLines(string &file, vector<string> &out);
void removeGameText(vector<string> &out);
vector<vector<string>> parseGame(vector<string> &in);
vector<vector<vector<pair<int,string>>>> parseGameResults(vector<vector<string>> &in);
bool isValidMatch(vector<pair<int,string>> &max, vector<vector<pair<int,string>>> &matches);
int getCubePower(vector<vector<pair<int,string>>> &matches);
int _main()
{
    vector<pair<int,string>> game_max = {pair<int,string>(12,"red"),pair<int,string>(13,"green"),pair<int,string>(14,"blue")};
    string data = "./data/data_2.txt";
    vector<string> lines;
    _getFileLines(data, lines);
    removeGameText(lines);
    vector<vector<string>> games = parseGame(lines);
    vector<vector<vector<pair<int,string>>>> gameResults =  parseGameResults(games);
    int sum=0;
    bool isMatch;
    cout<<"games "<<gameResults.size()<<endl;
    for(int i = 0; i<gameResults.size();i++){
        /*isMatch =isValidMatch(game_max,gameResults[i]);
        if (isMatch){
            sum+=(i+1);
            cout<<"valid match: "<<i+1<<endl;
        }
        int power =getCubePower(gameResults[i]);
        cout<< i+1 <<" power: "<<power<<endl;
        sum+=power;
    }
    
    cout<<"result:"<< sum <<endl;
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
            cout<<input<<endl;
        }
    }
    infile.close();
}

void removeGameText(vector<string> &out){
    for (int i=0;i<out.size();i++){
        size_t colon_pos = out[i].find(": ");
        out[i] = out[i].substr(colon_pos+1);
        cout <<"game number " <<i+1 << "-" <<out[i]<<endl;
    }
}

vector<vector<string>> parseGame(vector<string> &in){
    vector<vector<string>> out;
    for (int i=0;i<in.size();i++){
        vector<string>line;
        stringstream ss(in[i]);
        string word;
        while (!ss.eof()) {
            getline(ss, word, ';');
            line.push_back(word);
            cout<<" adding line: "<<word<<endl;
            
       }
        cout<<"add line to game"<<endl;
    out.push_back(line);
    }
    return out;
}

vector<vector<vector<pair<int,string>>>> parseGameResults(vector<vector<string>> &in){
    vector<vector<vector<pair<int,string>>>> games;
    for (int i=0;i<in.size();i++){  //loop game
        cout<<"--game "<<i+1<<endl;
        vector<vector<pair<int,string>>> match;
        for (int j=0;j<in[i].size();j++){   //loop match
            cout<<"----match "<<j+1<<" - "<<in[i][j]<<endl;
            stringstream ss(in[i][j]);
            string word;
            vector<pair<int,string>> round;
            while (!ss.eof()) { //get round
                getline(ss, word, ',');
                word.erase(remove_if(word.begin(), word.end(), [](unsigned char x) { return isspace(x); }), word.end());
                int amount = 0;
                int position = 0;
                
                for(int k=0;k<word.size();k++){
                    if (isdigit(word[k])){
                        if (amount>0){
                            amount*=10;
                        }
                        amount+=(int)(word[k]-'0');
                    }
                    else{
                        position=k;
                        k=(int)word.size();
                    }
                }
                word = word.substr(position);
                cout<<"---round  "<<amount<< " - " <<word<<endl;
                pair<int,string> result(amount,word);
                round.push_back(result);
            }
            match.push_back(round);
        }
        games.push_back(match);
    }
    return games;
}
bool isValidMatch(vector<pair<int,string>> &max, vector<vector<pair<int,string>>> &matches){
    for(int i=0;i<matches.size();i++){
        //cout<< "match "<<i+1<<endl;
        for(int j=0;j<matches[i].size();j++){
            //cout<< "--round "<<j+1 << matches[i][j].second << endl;
            for(int k=0;k<max.size();k++){
                if (matches[i][j].second == max[k].second){
                    if (matches[i][j].first>max[k].first){return false;}
                }
            }
        }
    }
    return true;
}

int getCubePower(vector<vector<pair<int,string>>> &matches){
    int max_blue=0;
    int max_red=0;
    int max_green=0;
    for(int i=0;i<matches.size();i++){
        //cout<< "match "<<i+1<<endl;
        for(int j=0;j<matches[i].size();j++){
            int matches_num = matches[i][j].first;
            string matches_colour=matches[i][j].second;
            if (matches_colour=="blue"){
                if(matches_num > max_blue){ max_blue = matches_num;}
            }
            else if (matches_colour=="red"){
                    if(matches_num > max_red){ max_red = matches_num;}
            }
            else{
                if(matches_num > max_green){ max_green = matches_num;}
            }
        }
    }
    return (max_blue*max_red*max_green);
}
*/
