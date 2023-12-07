//
//  day5.cpp
//  2023-advent-of-code
//
//  Created by Michael Osvald on 2023-12-05.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include <math.h>
#include <regex>
#include <map>
#include <numeric>
using namespace std;

void getFileLines(string &file, vector<string> &out);
vector<long> getlongs(string seeds);
map<long,pair<long,long>> getMapped(vector<string> &input);
long convertInputType(long in,map<long,pair<long,long>> &mp);
vector<long> expandSeeds(vector<long> &seeds);

int main(){
    string data= "./data/data_5.txt";
    vector<string> lines;
    getFileLines(data, lines);
    vector<long> seedspre = getlongs(lines[0]);
    vector<long> seeds = expandSeeds(seedspre);
    lines.erase(lines.begin(),lines.begin()+2);
    map<long,pair<long,long>> seedToSoil = getMapped(lines);
    lines.erase(lines.begin(),lines.begin()+seedToSoil.size()+1);
    map<long,pair<long,long>> soilToFert = getMapped(lines);
    lines.erase(lines.begin(),lines.begin()+soilToFert.size()+1);
    map<long,pair<long,long>> fertToWater = getMapped(lines);
    lines.erase(lines.begin(),lines.begin()+fertToWater.size()+1);
    map<long,pair<long,long>> waterToLight = getMapped(lines);
    lines.erase(lines.begin(),lines.begin()+waterToLight.size()+1);
    map<long,pair<long,long>> lightToTemp = getMapped(lines);
    lines.erase(lines.begin(),lines.begin()+lightToTemp.size()+1);
    map<long,pair<long,long>> tempToHum = getMapped(lines);
    lines.erase(lines.begin(),lines.begin()+tempToHum.size()+1);
    map<long,pair<long,long>> humToLoc = getMapped(lines);
    lines.erase(lines.begin(),lines.begin()+humToLoc.size());
    vector<long>results;
    for(long i=0;i<seeds.size();i++){
        //cout<<"seed :" << seeds[i]<<endl;
        cout<< "run #"<<i+1<<" of "<<seeds.size()<<endl;
        long output = convertInputType(seeds[i],seedToSoil);
        //cout<<"seed to soil: "<< output<<endl;
        output = convertInputType(output,soilToFert);
        //cout<<"soil to fert: "<< output<<endl;
        output = convertInputType(output,fertToWater);
        //cout<<"fert to water: "<< output<<endl;
        output = convertInputType(output,waterToLight);
        //cout<<"water to light: "<< output<<endl;
        output = convertInputType(output,lightToTemp);
        //cout<<"light to temp: "<< output<<endl;
        output = convertInputType(output,tempToHum);
        //cout<<"temp to hum: "<< output<<endl;
        output = convertInputType(output,humToLoc);
        results.push_back(output);
        //cout<<"Result: "<<output<<endl;
    }
    sort(results.begin(),results.end());
    //for (const auto& result : results)
    cout<<"results "<<results[0]<<endl;
}

vector<long> expandSeeds(vector<long> &seeds){
    
    vector<long> out;
    for(int i = 0; i<seeds.size();i++){
        cout<<"expand seed #"<<i+1<<endl;
        long lowerBound=seeds[i];
        i++;
        long upperBound=seeds[i];
        //cout<<"size: " << upperBound <<endl;
        vector<long> temp(upperBound);
        iota(temp.begin(), temp.end(), lowerBound);
        out.insert(out.end(), temp.begin(), temp.end());
    }
    return out;
}

vector<long> getlongs(string longs){
    vector<long> longsList;
    regex r("[0-9]+");
    sregex_iterator it = sregex_iterator(longs.begin(), longs.end(), r);
    sregex_iterator end_it =  sregex_iterator();
    for(; it!= end_it; it++){
        longsList.push_back(stol(it->str()));
        //cout<<"seeds #"<<it->str()<<endl;
    }
    return longsList;
}

long convertInputType(long in,map<long,pair<long,long>> &mp){
    if (mp.contains(in)){
       // cout<<in<<" found in map"<<endl;
        return mp[in].first;
    }
    for (const auto& [key, value] : mp){
        if(key<in && key+value.second >= in){
           /* cout<<in<<" found in range"<<endl;
            cout<<"lower range: "<<key<<endl;
            cout<<"upper range: "<<key+value.second<<endl;
            cout<<"difference: "<< in-key<<endl;
            cout<<"adding to: "<<value.first<<endl;*/
            return value.first+(in-key);
        }
    }
    //cout<<in<<" not found"<<endl;
    return in;
}

map<long,pair<long,long>> getMapped(vector<string> &input){
    map<long,pair<long,long>> newMap;
    for(long i=0;i<input.size();i++){
        if(!isdigit(input[i][0])){break;}
        else{
            vector<long> vals = getlongs(input[i]);
            //cout<<"key: "<<vals[1]<<" dest: "<<vals[0]<<" range: "<<vals[2]<<endl;
            newMap.insert(pair(vals[1],pair(vals[0],vals[2])));
        }
    }
    return newMap;
}
void getFileLines(string &file, vector<string> &out){
    ifstream infile;
    string input;
    infile.open(file);
    if (infile.is_open()){
        while (getline(infile,input)){
            //input.erase(remove_if(input.begin(), input.end(), [](unsigned char x) { return isspace(x); }), input.end());
            if(input[0]!=0){
                out.push_back(input);
                //cout<<input<<endl;
            }
        }
    }
    infile.close();
}
