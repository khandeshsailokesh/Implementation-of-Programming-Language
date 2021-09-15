//compiled and executed on linux g++
#include<bits/stdc++.h>
#include <sstream>
using namespace std;
int hex_to_int(string hexadecimalvalue){
    int len = hexadecimalvalue.length();  
    int base = 1; 
    int dec_val = 0; 
    for (int i=len-1; i>=0; i--) 
    {    
        if (hexadecimalvalue[i]>='0' && hexadecimalvalue[i]<='9') 
        { 
            dec_val += (hexadecimalvalue[i] - 48)*base; 
            base = base * 16; 
        } 
        else if (hexadecimalvalue[i]>='A' && hexadecimalvalue[i]<='F') 
        { 
            dec_val += (hexadecimalvalue[i] - 55)*base;  
            base = base*16; 
        } 
    }  
    return dec_val;
}
string int_to_hex(int n)
{
    string result = "";
    while (n > 0)
    {
        int rem = n % 16;
        n = n / 16;
        if (rem >= 0 && rem <= 9)
        {
            char x = (char)(rem + 48);
            result = x + result;
        }
        else
        {
            char x = 'A' + (rem - 10);
            result = x + result;
        }
    }
    return result;
}
void splitline(vector<string>&t,string l){
    istringstream sss(l);
    string sub;
    while(sss>>sub){
        t.push_back(sub);
    }
}
int main(){
    unordered_map<string,string>optab;
    unordered_map<string,string>symtab;
    optab["LDA"] = "00";
    optab["LDX"] = "04";
    optab["LDL"] ="08";
    optab["STA"] = "0C";
    optab["STX"] = "10";
    optab["STL"] ="14";
    optab["LDCH"] = "50";
    optab["STCH"] = "54";
    optab["ADD"] = "18";
    optab["SUB"] = "1C";
    optab["MUL"] ="20";
    optab["DIV"] = "24";
    optab["COMP"] = "28";
    optab["J"] = "3C";
    optab["JLT"] = "38";
    optab["JEQ"] = "30";
    optab["JGT"] = "34";
    optab["JSUB"] ="48";
    optab["RSUB"] = "4C";
    optab["TIX"] = "2C";
    optab["TD"] = "E0";
    optab["RD"] = "D8";
    optab["WD"] = "DC";
    string l;
    ifstream myfile("input.txt");
    ofstream interfile("intermediate.txt");
    getline(myfile, l);
    istringstream ss(l);
    string sub;
    vector<string>tmp;
    while(ss >> sub){
        tmp.push_back(sub);
    }
    int index=tmp.size();
    int locationctr=0;
    if(tmp[index-2]=="START"){
        locationctr= hex_to_int(tmp[index-1]);
        tmp.clear();
        interfile<<int_to_hex(locationctr)<<"\t"<<l<<"\n";
        getline(myfile,l);
        istringstream ss(l);
        while(ss>>sub){
            tmp.push_back(sub);
        }
    }
    index=tmp.size();
    while(tmp[0][0]=='.' || tmp[0]=="RSUB" ||(index>1 && tmp[index-2]!="END")){
        if(tmp[0][0]!='.'){
            interfile<<int_to_hex(locationctr)<<"\t"<<l<<"\n";
            if(index==3){
                if(symtab.find(tmp[0])!=symtab.end()){

                }
                else{
                    symtab[tmp[0]]=int_to_hex(locationctr);
                }
            }
            if((index>1 && optab.find(tmp[index-2])!=optab.end()) || (index==1 && optab.find(tmp[index-1])!=optab.end() )){
                locationctr+=3;
            }
            else if((index>1 && tmp[index-2]=="WORD")){
                locationctr+=3;
            }
            else if((index>1 && tmp[index-2]=="RESW")){
                locationctr+=(3*stoi(tmp[index-1]));
            }
            else if((index>1 && tmp[index-2]=="RESB")){
                locationctr+=(stoi(tmp[index-1]));
            }
            else if(tmp[index-2]=="BYTE"){
                if(tmp[index-1][0]=='X'){
                    locationctr+=(tmp[index-1].length()-3)/2;
                }
                else if(tmp[index-1][0]=='C'){
                    locationctr+=(tmp[index-1].length()-3);
                }
            }

        }
        else{
            interfile<<l<<"\n";
        }
        tmp.clear();
        getline(myfile,l);
        istringstream ss(l);
        while(ss>>sub){
            tmp.push_back(sub);
        }
        index=tmp.size();
    }
    interfile<<l<<"\n";
    myfile.close();
    interfile.close();
    string prog_len=int_to_hex(locationctr-hex_to_int("1000"));
    while(prog_len.length()<6){
        prog_len="0"+prog_len;
    }
    ifstream inter_file("intermediate.txt");
    ofstream outputfile("output.txt");
    getline(inter_file, l);
    tmp.clear();
    splitline(tmp,l);
    index=tmp.size();
    string sa,x,storing;
    if(index==4 && tmp[index-2]=="START"){
        while(tmp[1].length()<6){
            tmp[1]+=" ";
        }
        while(tmp[3].length()<6){
            tmp[3]="0"+tmp[3];
        }
        outputfile<<"H"<<tmp[1]<<tmp[3]<<prog_len<<"\n";
        sa=tmp[3];
        x=tmp[3];
    }
    else{
        while(tmp[1].length()<6){
            tmp[1]+=" ";
        }
        outputfile<<"H"<<tmp[1]<<"000000"<<prog_len<<"\n";
        sa="000000";
        x=sa;
    }
    getline(inter_file, l);
    tmp.clear();
    splitline(tmp,l);
    index=tmp.size();
    string t_r="";
    while(tmp[0]=="." || (index>1 && tmp[index-2]!="END")){
        if(tmp[0]!="."){ 
            string a,b;
            if(index>2 && optab.find(tmp[index-2])!=optab.end()){
                a=optab[tmp[index-2]];
                if(index>2){
                    if(symtab.find(tmp[index-1])!=symtab.end()){
                        b=symtab[tmp[index-1]];
                        a=a+b;
                    }
                    else if(tmp[index-1][tmp[index-1].length()-1]=='X' && tmp[index-1][tmp[index-1].length()-2]==','){
                        a=a+"9";
                        for(int i=1;i<symtab[tmp[index-1].substr(0,tmp[index-1].length()-2)].length();i++){
                            a+=symtab[tmp[index-1].substr(0,tmp[index-1].length()-2)][i];
                        }
                    }
                }
    
            }
            else if(index>2 && (tmp[index-2]=="BYTE" )){
                if(tmp[index-1][0]=='X'){
                    a=tmp[index-1].substr(2,tmp[index-1].length()-3);
                }
                else if(tmp[index-1][0]=='C'){
                    for(int i=2;i<tmp[index-1].length()-1;i++){
                        a+=int_to_hex(tmp[index-1][i]);
                    }
                }
            }
            else if(index>2 && tmp[index-2]=="WORD"){
                a=int_to_hex(stoi(tmp[index-1]));
                while(a.length()<6){
                    a="0"+a;
                }
            }
            else if(tmp[index-2]=="RESB" || tmp[index-2]=="RESW"){
                if(t_r.length()>0){
                    outputfile<<"T"<<sa;
                    storing=int_to_hex(t_r.length()/2);
                    while(storing.length()<2){
                        storing="0"+storing;
                    }
                    outputfile<<storing<<t_r<<"\n";
                    t_r="";
                    sa="";
                }
                else{
                    getline(inter_file, l);
                    tmp.clear();
                    splitline(tmp,l);
                    index=tmp.size();
                }
                continue;
            }
            else if(tmp[index-1]=="RSUB"){
                a="4C0000";
            }
            if(t_r.length()+a.length()>60){
                outputfile<<"T"<<sa;
                storing=int_to_hex(t_r.length()/2);
                while(storing.length()<2){
                    storing="0"+storing;
                }
                outputfile<<storing<<t_r<<"\n";
                t_r=a;
                while(tmp[0].length()<6){
                    tmp[0]="0"+tmp[0];
                }
                sa=tmp[0];
            }
            else{
                t_r+=a;
                if(sa==""){
                    while(tmp[0].length()<6){
                        tmp[0]="0"+tmp[0];
                    }
                    sa=tmp[0];
                }
            }

        } 
        if(tmp[0]=="."){
            cout<<tmp[0];
        }
        getline(inter_file, l);
        tmp.clear();
        splitline(tmp,l);
        index=tmp.size();
    }
    outputfile<<"T"<<sa;
    storing=int_to_hex(t_r.length()/2);
    while(storing.length()<2){
        storing="0"+storing;
    }
    outputfile<<storing<<t_r<<"\n";
    outputfile<<"E"<<x<<"\n";  
    inter_file.close();
    outputfile.close();
}
