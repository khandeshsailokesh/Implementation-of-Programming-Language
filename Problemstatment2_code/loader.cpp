#include<bits/stdc++.h>
 using namespace std;
 
 string dectohex(int n)
{
    string hexadeci = "";
    if(n<0) n=n*(-1);
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

int hextodec(string hexVal){
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
 
 int main()
 {
   ifstream secondp("input2.txt");
   ofstream write("loaderoutput.txt");
   string  add="4000";
   map<string,string> store;
   map<string,string> m;
   string s="";
    getline(secondp,s);
    store[s.substr(1,5)]=add;
    string l=s.substr(s.length()-6,6);
   while(s!="END")
   {
    getline(secondp,s);
     if(s[0]=='H')
     {
     add=dectohex(hextodec(add)+hextodec(l));
     store[s.substr(1,5)]=add;
     l=s.substr(s.length()-6,6);
     continue;
     }	
     if(s[0]=='D')
     {
       store[s.substr(1,5)]= dectohex(hextodec(add)+hextodec(s.substr(7,6)));
       store[s.substr(13,4)]=dectohex(hextodec(add)+hextodec(s.substr(19,6)));
     }
   }
   /*for(auto i:store)
   {
   cout<<i.first<<" "<<i.second<<endl;
   }*/
   secondp.close();
   ifstream secondpass2("input2.txt");
    add="4000";
   s="";
   string fadd;
   map<string,string> remin;
   map<string,string> sign;
   map<string,string> sto;
   getline(secondpass2,s);
   l=s.substr(s.length()-6,6);
   //cout<<s;
   while(s!="END")
   {
   getline(secondpass2,s);
   if(s[0]=='H')
   {
   add=dectohex(hextodec(add)+hextodec(l));
   l=s.substr(s.length()-6,6);
     continue;
   }
   if(s[0]=='T')
   {
    fadd=dectohex(hextodec(add)+hextodec(s.substr(1,6)));
    //cout<<fadd<<endl;
    int i=9;
    string temp=fadd;
    while(i<s.length())
    {
    m[temp]=s.substr(i,2);
    temp=dectohex(hextodec(temp)+1);
    i+=2;
    }
    //cout<<"out";
   }
   if(s[0]=='M')
   {
    string temp1=dectohex(hextodec(add)+hextodec(s.substr(1,6)));
    string temp2=dectohex(hextodec(add)+hextodec(s.substr(1,6)));
    int r=1;
    string def="";
    while(r<=3)
    {
      def+=m[temp2];
      temp2=dectohex(hextodec(temp2)+1);
      r++;
    }
    
    string succ;
    if(remin[temp1]=="1000000")
    {
    def='1'+def;
    if(sign[temp1]=="1") 
    {
    if(s[9]=='+')
    {
       succ=dectohex(hextodec(def)*(-1)+hextodec(store[s.substr(10,s.length()-10)]));
       int k=hextodec(def)*(-1)+hextodec(store[s.substr(10,s.length()-10)]);
       if(k<0) sign[temp1]="1";
       else sign[temp1]="0";
     }
    if(s[9]=='-') 
    {
      succ=dectohex(hextodec(def)*(-1)-hextodec(store[s.substr(10,s.length()-10)]));
      int k=hextodec(def)*(-1)+hextodec(store[s.substr(10,s.length()-10)]);
       if(k<0) sign[temp1]="1";
       else sign[temp1]="0";
    }
    }
    else
    {
    //if(k<0) sign[temp1]="1";
    if(s[9]=='+'){ 
      succ=dectohex(hextodec(def)+hextodec(store[s.substr(10,s.length()-10)]));
      int k=hextodec(def)+hextodec(store[s.substr(10,s.length()-10)]);
      if(k<0) sign[temp1]="1";
       else sign[temp1]="0";
      }
    if(s[9]=='-'){   
    succ=dectohex(hextodec(def)-hextodec(store[s.substr(10,s.length()-10)]));
    int k=hextodec(def)-hextodec(store[s.substr(10,s.length()-10)]);
    if(k<0) sign[temp1]="1";
       else sign[temp1]="0";
    }
    }
    }
    else
    {
    if(sign[temp1]=="1") 
    {
    if(s[9]=='+')
    {
       succ=dectohex(hextodec(def)*(-1)+hextodec(store[s.substr(10,s.length()-10)]));
       int k=hextodec(def)*(-1)+hextodec(store[s.substr(10,s.length()-10)]);
       if(k<0) sign[temp1]="1";
       else sign[temp1]="0";
     }
    if(s[9]=='-') 
    {
      succ=dectohex(hextodec(def)*(-1)-hextodec(store[s.substr(10,s.length()-10)]));
      int k=hextodec(def)*(-1)+hextodec(store[s.substr(10,s.length()-10)]);
       if(k<0) sign[temp1]="1";
       else sign[temp1]="0";
    }
    }
    else
    {
    //if(k<0) sign[temp1]="1";
    if(s[9]=='+'){ 
      succ=dectohex(hextodec(def)+hextodec(store[s.substr(10,s.length()-10)]));
      int k=hextodec(def)+hextodec(store[s.substr(10,s.length()-10)]);
      if(k<0) sign[temp1]="1";
       else sign[temp1]="0";
      }
    if(s[9]=='-'){   
    succ=dectohex(hextodec(def)-hextodec(store[s.substr(10,s.length()-10)]));
    int k=hextodec(def)-hextodec(store[s.substr(10,s.length()-10)]);
    if(k<0) sign[temp1]="1";
       else sign[temp1]="0";
    }
    }
    }
    while(succ.length()<6)
    {
     succ="0"+succ;
    }
    if(succ.length()==7)
    {
      remin[temp1]="1000000";
      m[temp1]=succ.substr(1,2);
      m[dectohex(hextodec(temp1)+1)]=succ.substr(3,2);
      m[dectohex(hextodec(temp1)+2)]=succ.substr(5,2);
    }
    else
    {
    m[temp1]=succ.substr(0,2);
    m[dectohex(hextodec(temp1)+1)]=succ.substr(2,2);
    m[dectohex(hextodec(temp1)+2)]=succ.substr(4,2);
    }
    //cout<<succ<<endl;
   }
   }
   
    /*for(auto j:m)
   {
   cout<<j.first<<" "<<j.second<<endl;
   }*/
   write<<"MEMORY ADDRESS"<<"\t \t"<<"\t"<<"VALUES"<<"\n";
   write<<"\n";	
   write<<"0000"<<"\t \t"<<"xxxxxxxx"<<"\t \t"<<"xxxxxxxx"<<"\t \t"<<"xxxxxxxx"<<"\t \t"<<"xxxxxxxx"<<"\n";		
   write<<"  .  "<<"\t \t"<<"    .    "<<"\t \t"<<"    .    "<<"\t \t"<<"    .    "<<"\t \t"<<"    .    "<<"\n";
   write<<"  .  "<<"\t \t"<<"    .    "<<"\t \t"<<"    .    "<<"\t \t"<<"    .    "<<"\t \t"<<"    .    "<<"\n";
   write<<"  .  "<<"\t \t"<<"    .    "<<"\t \t"<<"    .    "<<"\t \t"<<"    .    "<<"\t \t"<<"    .    "<<"\n";
   write<<"  .  "<<"\t \t"<<"    .    "<<"\t \t"<<"    .    "<<"\t \t"<<"    .    "<<"\t \t"<<"    .    "<<"\n";
   write<<"3FF0"<<"\t \t"<<"xxxxxxxx"<<"\t \t"<<"xxxxxxxx"<<"\t \t"<<"xxxxxxxx"<<"\t \t"<<"xxxxxxxx"<<"\n";
   string radd="4000";
   for(int i=0;i<23;i++)
   {
     write<<radd<<"\t \t";
     string rlead=radd;
     radd=dectohex(hextodec(radd)+16);
     
     for(int j=0;j<16;j++)
     {
       if(hextodec(rlead)>hextodec("4132")) write<<"xx";
       
       else if(m.find(rlead) == m.end())
       {
         write<<"..";
         rlead=dectohex(hextodec(rlead)+1);
       }
       else
       {
        write<<m[rlead];
        rlead=dectohex(hextodec(rlead)+1);
       }
       if(j%4==3)
       {
       write<<"\t \t";
       }
     }
     write<<endl;
   }		
 }
