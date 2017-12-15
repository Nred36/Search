//
//  main.cpp
//  Radix Search
//
//  Created by JFRE74692 on 2017-12-13.
//  Copyright © 2017 JFRE74692. All rights reserved.
//
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;
vector<string> curr;
int run=0;
int off=0;
vector<string> search(string c, vector <string> sample){
    curr.clear();
    for(int i =0;i<sample.size(); i++){
        if((sample.at(i).length()>off+c.length()-1)&&(c.length()>run)){
            if(sample.at(i).at(off+run)==c.at(run)){
                curr.push_back(sample.at(i));
                //cout<< run <<"   "<< sample.at(i)<<"   "<< off<<"\n";
            }
        }
    }
    
    if(curr.size()>1&&(c.length()>run+1)){
        run++;
        //cout<<"???"<<run;
        return(search(c, curr));
    }else if(curr.size()==0){
        vector<string> end={};        
        return end;
    }else{
        for(int t=0; t<c.length();t++){
            if(c.at(t)!=curr.at(0).at(t)){
                vector<string> end={};
                return(end);
            }
        }
        return curr;
    }
}

void sort(int i){ //bubble y not
    //string sorted [curr.size()];
    string temp="";
    int y =i;
    //for(int y=i; y<curr.at(0).size();y++){
    for(int z=i; z<curr.size();z++){
        for(int x=0; x<curr.size()-1; x++){
            if(curr.at(x).at(y)>curr.at(x+1).at(y)){
                temp = curr.at(x+1);
                curr.at(x+1)=curr.at(x);
                curr.at(x)=temp;
            }
       // }
        }
    }
}

int main(int argc, const char * argv[]) {
    string term = "co"; //The start of the word you are looking for
    vector <string> array;
    vector <string> finish;
    string line;
    ifstream file("/Users/jfre74692/Documents/Radix Search/Radix Search/words.txt");
    while (file >> line){
        array.push_back(line);
    }
    file.close();
    
    for(int r=0;r<20;r++){
        off=r;
        search(term, array); //word to search for, vector to search through and the index to start looking at
        //run=0;
        //cout<<"HELP";
        sort(term.length()+r);
        for(int i=0;i<curr.size();i++){
            finish.push_back(curr.at(i));
        }
        run=0;
    }
    for(int i=0;i<finish.size();i++){
        for(int b=i-1; b>0; b--){
         if(finish.at(i)==finish.at(b)){
         //cout << i << finish.at(i) << " and " << b << finish.at(b)<<"\n";
         finish.erase(finish.begin() + i);
         //cout << finish.size();
            // cout<<finish.at(i)<<", ";
         //i--;
         }
         }
        cout<<finish.at(i)<<", ";
    }
    return 0;
}
