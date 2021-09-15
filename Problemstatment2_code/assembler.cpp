#include<bits/stdc++.h>

using namespace std;

void func(vector<string>&t,string s){
istringstream sss(s);
t.clear();
string sub;
while(sss>>sub){
t.push_back(sub);
}
}

void extract_i(vector<string>&t,string s)
{
istringstream si(s);
t.clear();
string sub;
while(si>>sub)
{
t.push_back(sub);
}
int k=t.size();
if(k==2)
{
  string temp1=t[0];
  string temp2=t[1];
  t[0]="";
  t[1]=temp1;
  t.push_back(temp2);
}
if(k==1)
{
string temp=t[0];
t[0]="";
t.push_back(temp);
t.push_back("");
}
if(k==0)
{
t.push_back("");
t.push_back("");
t.push_back("");
}

}

void extract_filein(vector<string>&t,string s)
{
istringstream si(s);
t.clear();
string sub;
while(si>>sub)
{
t.push_back(sub);
}
int k=t.size();
if(k==2)
{
string temp1=t[0];
string temp2=t[1];
t[0]="";
t[1]="";
t.push_back(temp1);
t.push_back(temp2);
}
else 
{  if(k==3)
{
string temp1=t[0];
string temp2=t[1];
string temp3=t[2];
t[0]=temp1;
t[1]="";
t[2]=temp2;
t.push_back(temp3);
}
else
{
if(k==4)
{
return;
}
}
}

}

string decToHexa(int n)
{
    string hexadeci = "";
    while (n > 0)
    {
        int rem = n % 16;
        n = n / 16;
        if (rem >= 0 && rem <= 9)
        {
            char x = (char)(rem + 48);
            hexadeci = x + hexadeci;
        }
        else
        {
            char x = 'A' + (rem - 10);
            hexadeci = x + hexadeci;
        }
    }
    return hexadeci;
} 

int hexatodec(string hexVal){
    int len = hexVal.length();  
    int base = 1; 
    int deci = 0; 
    for (int i=len-1; i>=0; i--) 
    {    
        if (hexVal[i]>='0' && hexVal[i]<='9') 
        { 
            deci += (hexVal[i] - 48)*base; 
            base = base * 16; 
        } 
        else if (hexVal[i]>='A' && hexVal[i]<='F') 
        { 
            deci += (hexVal[i] - 55)*base;  
            base = base*16; 
        } 
    }  
    return deci;
}


string HexToBin(string hexdec)
{
    long int i = 0;
    string binary="";
    while (hexdec[i]) {
         //cout<<hexdec[i]<<endl;
        switch (hexdec[i]) {
        case '0':
             binary+="0000";
            break;
        case '1':
            binary+="0001";
            break;
        case '2':
            binary+="0010";
            break;
        case '3':
            binary+="0011";
            break;
        case '4':
           binary+="0100";
            break;
        case '5':
            binary+="0101";
            break;
        case '6':
            binary+="0110";
            break;
        case '7':
           binary+="0111";
            break;
        case '8':
             binary+="1000";
            break;
        case '9':
            binary+="1001";
            break;
        case 'A':
        case 'a':
            binary+="1010";
            break;
        case 'B':
        case 'b':
            binary+="1011";
            break;
        case 'C':
        case 'c':
            binary+="1100";
            break;
        case 'D':
        case 'd':
           binary+="1101";
            break;
        case 'E':
        case 'e':
            binary+="1110";
            break;
        case 'F':
        case 'f':
            binary+="1111";
            break;
        }
        i++;
    }
    return binary;
}

void createMap(unordered_map<string, char> *um)
{
    (*um)["0000"] = '0';
    (*um)["0001"] = '1';
    (*um)["0010"] = '2';
    (*um)["0011"] = '3';
    (*um)["0100"] = '4';
    (*um)["0101"] = '5';
    (*um)["0110"] = '6';
    (*um)["0111"] = '7';
    (*um)["1000"] = '8';
    (*um)["1001"] = '9';
    (*um)["1010"] = 'A';
    (*um)["1011"] = 'B';
    (*um)["1100"] = 'C';
    (*um)["1101"] = 'D';
    (*um)["1110"] = 'E';
    (*um)["1111"] = 'F';
}

string convertBinToHex(string bin)
{
	int l = bin.size();
	int t = bin.find_first_of('.');
	
	
	int len_left = t != -1 ? t : l;
	
	
	for (int i = 1; i <= (4 - len_left % 4) % 4; i++)
		bin = '0' + bin;
	
	if (t != -1) 
	{
		
		int len_right = l - len_left - 1;
		
		
		for (int i = 1; i <= (4 - len_right % 4) % 4; i++)
			bin = bin + '0';
	}
	
	
	unordered_map<string, char> bin_hex_map;
	createMap(&bin_hex_map);
	
	int i = 0;
	string hex = "";
	
	while (1)
	{
		
		hex += bin_hex_map[bin.substr(i, 4)];
		i += 4;
		if (i == bin.size())
			break;
			
		
		if (bin.at(i) == '.') 
		{
			hex += '.';
			i++;
		}
	}
	
	
	return hex; 
}

string ob(vector<string>&a,map<string,string>&op,map<string,string>&sy,map<string,pair<string,int>>&ltr)
{
  string f="",f1,f2;
  string n,i,x,b,p,e;
  if(a[3][0]=='#')
  {
  n='0';
  }
  else
  {
  n='1';
  }
  if(a[3][0]=='@')
  {
  i='0';
  }
  else
  {
  i='1';
  }
  if(a[3][a[3].length()-2]==','&&a[3][a[3].length()-1]=='X')
  {
   x='1';
  }
  else
  {
  x='0';
  }
  if(a[2][0]=='+')
  {
   b='0';
   p='0';
  }
  else
  {
  b='0';
  p='1';
  }
  if(a[2][0]=='+')
  {
   e='1';
  }
  else
  {
  e='0';
  }
  f+=n+i+x+b+p+e;
  if(op.find(a[2])!=op.end() || a[2][0]=='+')
  {
  
  if(a[2][0]=='+')
  {
   string f1=HexToBin(op[a[2].substr(1,a[2].length()-1)]);
  }
  else
  {
   f1=HexToBin(op[a[2]]);
  
  }
   f1=f1.substr(0,6);
  
  }
  f1+=f;
  f2=convertBinToHex(f1);
  return f2;
}

int main()
{
string s;
 ifstream store("opcode.txt");
 ofstream write("inter.txt");
 map<string,string> op;
 map<string,string> sy;
 vector<string> ge;
 ge.push_back("00002B");
 ge.push_back("00001C");
 map<string,pair<string,int>> ltr;
 vector<string> endadd;
 vector<string>t;
 t.push_back("");
 
 while(t.size()!=0){
 getline(store,s);
 func(t,s);
 op[t[0]]=t[1];
  }
  //cout<<op["LDA"];
  ifstream i_f("input.txt");
  s="";
  int locate=0;
  vector<string> arr;
  getline(i_f,s);
  extract_i(arr,s);
 write<<"0000"<<"\t"<<arr[0]<<"\t"<<arr[1]<<"\t"<<arr[2]<<endl;
 
 while(arr[1]!="END")
  {
  getline(i_f,s);
  extract_i(arr,s);
  
  if(arr[1]=="EXTDEF" || arr[1]=="EXTREF" )
  {
  write<<"\t"<<"\t"<<arr[1]<<"\t"<<arr[2]<<endl;
  continue;
  }
  if(arr[0]=="."||arr[1]==".")
  {
  write<<"\t"<<s<<endl;
  }
  if(arr[0]!="" )
  {
  sy[arr[0]]=decToHexa(locate);
  //cout<< sy[arr[0]]<<" "<<arr[0]<<endl;
  }
  if(arr[2]=="CSECT")
  {
  endadd.push_back(decToHexa(locate));
  locate=0;
  write<<"\n"<<"0000"<<"\t"<<s<<endl;
  continue;
  }
  
  if(arr[1][0]=='+')
  {
  string temp=decToHexa(locate);
  while(temp.length()<4) 
  {
  temp="0"+temp;
  }
  write<<temp<<"\t"<<s<<endl;
  locate+=4;
  continue;
  }
  if(arr[1]=="RESW")
  {
  string temp=decToHexa(locate);
  while(temp.length()<4) 
  {
  temp="0"+temp;
  }
  write<<temp<<"\t"<<s<<endl;
  locate+=stoi(arr[2])*3;
  continue;
  }
  if(arr[1]=="RESB")
  {
  string temp=decToHexa(locate);
  while(temp.length()<4) 
  {
  temp="0"+temp;
  }
  write<<temp<<"\t"<<s<<endl;
  locate+=stoi(arr[2]);
  continue;
  }
  if(arr[1]=="EQU")
  {
  string temp=decToHexa(locate);
  while(temp.length()<4) 
  {
  temp="0"+temp;
  }
  write<<temp<<"\t"<<s<<endl;
  continue;
  }
  if(arr[1]=="WORD")
  {
  string temp=decToHexa(locate);
  while(temp.length()<4) 
  {
  temp="0"+temp;
  }
  write<<temp<<"\t"<<s<<endl;
  continue;
  }
  if(arr[1]=="BYTE")
  {
  string temp=decToHexa(locate);
  while(temp.length()<4) 
  {
  temp="0"+temp;
  }
  write<<temp<<"\t"<<s<<endl;
  if(arr[2][0]=='X')
  {
   locate+=(arr[2].length()-3)/2;
  }
  continue;
  }
  if(arr[1]=="LTORG")
  {
    write<<"\t"<<s<<endl;
    for(auto i: ltr)
    {
      if(i.second.first=="")
      {
       i.second.first=decToHexa(locate);
       string temp=decToHexa(locate);
  while(temp.length()<4) 
  {
  temp="0"+temp;
  }
  write<<temp<<"\t"<<"*"<<"\t"<<i.first<<endl;
  locate+=i.second.second;
      }
    }
    continue;
  }
  
  
  //write<<arr[0]<<"\t"<<arr[1]<<"\t"<<arr[2]<<endl;
  if(op.find(arr[1])!=op.end())
  {
  
  if(arr[1][0]=='+')
  {
  string temp=decToHexa(locate);
  while(temp.length()<4) 
  {
  temp="0"+temp;
  }
  write<<temp<<"\t"<<s<<endl;
  locate+=4;
  }
  
  if(arr[1]=="COMPR" || arr[1]=="CLEAR" || arr[1]=="TIXR")
  {
  string temp=decToHexa(locate);
  while(temp.length()<4) 
  {
  temp="0"+temp;
  }
  write<<temp<<"\t"<<s<<endl;
  locate+=2;
  continue;
  }
  string temp=decToHexa(locate);
  while(temp.length()<4) 
  {
  temp="0"+temp;
  }
  write<<temp<<"\t"<<s<<endl;
  locate+=3;
  }
  if(arr[2][0]=='=')
  {
  ltr[arr[2]]={"",arr[2].length()-4};
  }
  }
  write<<"\t"<<"\t"<<s<<endl;
  for(auto i: ltr)
    {
      if(i.second.first=="")
      {
       i.second.first=locate;
       string temp=decToHexa(locate);
  while(temp.length()<4) 
  {
  temp="0"+temp;
  }
  write<<temp<<"\t"<<"*"<<"\t"<<i.first<<endl;
  locate+=i.second.second;
      }
    }
    //cout<<endadd[0]<<" "<<endadd[1];
    write.close();
    store.close();
    
    //PASS 2 IMPLIMENTATION
    ifstream filein("inter.txt");
    ofstream filewrite("object.txt");
    s="";
    locate=0;
    vector<string> a;
    set<string> ext;
    getline(filein,s);
    extract_filein(a,s);
    string temp=endadd[0];
    while(temp.length()<6) 
    {
    temp="0"+temp;
    }
    filewrite<<"H"<<a[1]<<"  "<<"000000"<<temp<<"\n";
    
    int c=0;
    while(a[2]!="END")
    {
    getline(filein,s);
    extract_filein(a,s);
    if(a[3]=="CSECT")
    {
      if(c==0) 
      {
      filewrite<<"E"<<"000000"<<endl<<endl;
      filewrite<<"H"<<a[2]<<" "<<"000000"<<ge[0]<<endl;
      }
      if(c==3)
      {
      filewrite<<"E"<<endl<<endl;
       filewrite<<"H"<<a[2]<<" "<<"000000"<<ge[1]<<endl;
       }
      c++;
      //cout<<c<<endl;
      continue;
    }
    if(a[2]=="EXTDEF" || a[2]=="EXTREF")
    {
     if(a[2]=="EXTDEF")
     {
      filewrite<<"D"<<a[3].substr(0,6)<<"0000"+sy[a[3].substr(0,6)]<<a[3].substr(7,6)<<"00"+sy[a[3].substr(7,6)]<<a[3].substr(14,6)<<"0000"+sy[a[3].substr(14,6)]<<"\n";
      continue;
      }
     else
     {
     string k=a[3];
     int st=0;
     for(int i=0;i<k.size();i++)
     {
     if(k[i]==',') 
     {
     ext.insert(k.substr(st,i-st));
     filewrite<<k.substr(st,i-st);
     st=i+1;
     
     }
     }
      ext.insert(k.substr(st,k.length()-st));
      filewrite<<k.substr(st,k.length()-st)<<endl;
      
      continue;
     }
    }
    if(op.find(a[2])!=op.end() || a[2][0]=='+')
    {
    string p=ob(a,op,sy,ltr);
    
    //cout<<p<<endl;
    //cout<<a[2]<<" "<<a[3]<<" "<<p<<endl;
    }
    }
     //cout<<HexToBin("28")<<endl;
     //cout<<convertBinToHex("110001110");
    filewrite<<endl<<"E"<<endl;
  
  //cout<<decToHexa(14);
  //cout<<hexatodec("E");
}
