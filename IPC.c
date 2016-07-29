#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include<string.h>

char* cmd1;
char* cmd2;

void parseInput(char*);
int main(int argc, char* argv[])
{
parseInput(argv[1]);

int pipe_desc[2];
pipe(pipe_desc);

int pid=fork();

if (pid!=0) {
 //   close(1);       
    dup2(pipe_desc[1],1);   
    close(pipe_desc[0]); 
    execlp(cmd1,"", NULL);
             } 
             else 
             {
//    close(0);       
    dup2(pipe_desc[0],0);  
    close(pipe_desc[1]); 
 
        execlp(cmd2,"", NULL);
             }
return 0;
}


void parseInput(char* str)
{
cmd1=(char*)malloc(sizeof(char)*100);
cmd2=(char*)malloc(sizeof(char)*100);

int c1=0,c2=0,i=0;
const char* delim="-";
         
while(str[i]!='\0' && str[i]!='|')
{
if(str[i]!=' ' ){   cmd1[c1++]=str[i++]; }
else {  i++;}
}
while(str[i]!='\0')
{
if(str[i]!=' ' && str[i]!='|' ) {   cmd2[c2++]=str[i++]; }
else {  i++;}
}

}
