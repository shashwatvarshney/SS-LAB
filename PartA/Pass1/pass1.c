#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void main()
{
  FILE *f1,*f2,*f3,*f4;
  f1=fopen("input.txt","r");
  f3=fopen("symtab.txt","w");
  f4=fopen("output.txt","w");
  char label[20],opcode[20],operand[20];
  int sa,lc;
  fscanf(f1,"%s %s %s",label,opcode,operand);
  if(strcmp(opcode,"START")==0)
  {
   sa=strtol(operand,NULL,16);
  }
  else
   sa=0;
  fprintf(f4,"%x\t%s\t%s\t%s\n",sa,label,opcode,operand);
  lc=sa;
  fscanf(f1,"%s %s %s",label,opcode,operand);
  while(strcmp(opcode,"END")!=0)
  {
   fprintf(f4,"%x\t%s\t%s\t%s\n",lc,label,opcode,operand);
   if(strcmp(label,"-")!=0){
      fprintf(f3,"%s\t%X\n",label,lc);
   }
   f2=fopen("optab.txt","r");
   char tempcode[20],tempvar[20];
   fscanf(f2,"%s %s",tempcode,tempvar);
   while(!feof(f2)){
     if(strcmp(opcode,tempcode)==0){
        lc+=3;
        break;
     }
     fscanf(f2,"%s%s",tempcode,tempvar);
    }
    fclose(f2);
    if(strcmp(opcode,"WORD")==0)
      lc+=3;
    if(strcmp(opcode,"RESW")==0)
       lc+=3*(strtol(operand,NULL,10));
    if(strcmp(opcode,"RESB")==0)
       lc+=strtol(operand,NULL,10);
    if(strcmp(opcode,"BYTE")==0)
    {
     if(operand[0]=='X')
       lc+=(strlen(operand)-3)*0.5;
     else
       lc+=(strlen(operand)-3);
    }
    fscanf(f1,"%s %s %s",label,opcode,operand);
   }
   printf("Output file generated successfully\n");
   fclose(f3);
   fclose(f1);
   fclose(f4);
}
    
   
