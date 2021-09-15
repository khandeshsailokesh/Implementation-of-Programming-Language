/*To run the Code the commands are 
 - lex myscanner.l
 - gcc lex.yy.c
 - ./a.out >> fileout.txt
*/

%{
  #include<stdio.h>
  #include<stdlib.h>
  typedef enum { F, T } boolean;
  
  /* Defined a data structure "block" to create a hashmap containing a boolean and string to store */
  //block contain a boolean to check if block os empty and tno to store token number
  struct block{
  char m[40];
  boolean b;
  int tno;
  };
  int yyval=-1;      //To store the value of index in the hashmap and print it
  
  /*Defined a array of struct block*/
  
  struct block hm[25];
  extern int install_id();
  extern int install_num();
  
%}


/*Standard regular equations*/

W                 [ \t\n]+
ID                [A-Za-z]([A-Za-z]|[0-9])*
N                 [0-9]+

%option yylineno


%%



{W}                       {;}
"PROGRAM"                 { return(1);}
"VAR"                     { return(2);}
"BEGIN"                   { return(3);}
"END."                    { return(5);}
"END"                     { return(4);}
"INTEGER"                 { return(6);}
"FOR"                     { return(7);}
"READ"                    { return(8);}
"WRITE"                   { return(9);}
"TO"                      { return(10);}
"DO"                      { return(11);}
";"                       { return(12);}
":"                       { return(13);}
","                       { return(14);}
"="                       { return(15);}
"+"                       { return(16);}
"-"                       { return(17);}
"*"                       { return(18);}
"DIV"                     { return(19);}
"("                       { return(20);}
")"                       { return(21);}
{ID}                      { yyval=install_id();return(22);}
{N}                       { yyval=install_num();return(23);}
%%

int yywrap(void){
   if (feof(stdin)) return 1;
   return 1;
}

int install_id()
{
   int y=0;
  char r[40]="";
    strcpy(r,yytext);
    int size = strlen(r);
    int j=0;
    //Adding the ASCII of string to map it in hashmap
    while(j<size)
    {
     y+=r[j];
     j++;
    }
    int s=y%25;
    y=y-1;
    if(y<0){
        y=y+25;
    }
    
    /*USED THE LINEAR PROBING ALGORITHM TO STORE THE ID'S IN HASHMAP*/
    
    while(s!=y){

        if(hm[s].b==F){
            strcpy(hm[s].m,r);
             hm[s].b=T;
             hm[s].tno=22;
            return s;
        }
        else if(!strcmp(hm[s].m,r)){
            hm[s].tno=22;
            return s;
        }      
        s=(s+1)%25;
    }
    return -1;
}

int install_num()
{
  int y= atoi(yytext);  //converting string to int
  int s=y%25;
    y=y-1;
    if(y<0){
        y=y+25;
    }
  char r[40]="";
  strcpy(r,yytext);
  
  /*USED THE LINEAR PROBING ALGORITHM TO STORE THE VALUE OF NUMBER'S IN HASHMAP*/
  
    while(s!=y){

        if(hm[s].b==F){
            strcpy(hm[s].m,r);
            hm[s].b=T;
            hm[s].tno=23;
            return s;
        }
        else if(!strcmp(hm[s].m,r)){
            hm[s].tno=23;
            return s;
        }      
        s=(s+1)%25;
    }
    return -1;
}

int main()
{
 int t;
 for(int l=0;l<25;l++)
    {
        hm[l].b= F;
    }
    
    yyin=fopen("i1.txt","r");
    int it=0;
    t = yylex(); //Extracting the token using yylex()
    
    printf("%s\t%s\t%s\n","LNO","T_NO","INDEX");
    
    //Traversing the input file till the NULL token is appeared
    while(t)
    {
       if(t==22)                   //if token is an ID
       {
            if(it==yylineno){
                printf("\t%d\t%d\n",t,yyval);
            }
            else
                printf("%d\t%d\t%d\n",yylineno,t,yyval);
        }
        else if(t==23)               //if token is number
        {
           if(it==yylineno){
                printf("\t%d\t%d\n",t,yyval);
            }
            else
               printf("%d\t\t%d\t\t%d\n",yylineno,t,yyval);
        }
        else 
        {
            if(it==yylineno){
                printf("\t%d\n",t);
              }
            else
                printf("%d\t%d\n",yylineno,t);
        }
        it=yylineno;
        t = yylex();
    }
    /*PRINTING THE HASHMAP OF ID AND SYMBOLS*/
    printf("\n %s \n","****************HASH_MAP SYMBOL_TABLE VALUES****************");
    printf("\n%s\t%s\t%s\n","INDEX","TNO","LEXEME");
    for(int i=0;i<25;i++)
    {
     if(hm[i].tno!=0)
     printf("%d\t%d\t%s\n",i,hm[i].tno,hm[i].m);
     else
     printf("%d\t%s\t%s\n",i,"  ",hm[i].m);
    }
}
