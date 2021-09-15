THE COMMANDS TO RUN ARE
//

yacc -d codeparser.y
lex runcompiler.l
gcc -w y.tab.c lex.yy.c -ll
./a.out input.txt

//

The input is taken from the command line  "./a.out input.txt" and the output is given in output.txt

The "codeparser.y" file parses the code using the tokens given by the "runcompiler.l" file 

If there are any errors i.e semantic or syntactic in the input code then it is printed in output.txt file 

The input.txt file that is submmited has few semantic and syntactic errors ,So that the "codeparser.y" detects and prints in output.txt

