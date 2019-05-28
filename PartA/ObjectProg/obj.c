#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main()
{
 FILE *f1;
 f1=fopen("input.txt","r");
 int address,sa,la,len;
 char label[20],opcode[20],operand[20],objcode[20],saddress[20],startaddress[20];
 fscanf(f1,"%x%s%s%s%s",&address,label,opcode,operand,objcode);
 if(strcmp(opcode,"START")==0)
  sa=address;
 while(strcmp(opcode,"END")!=0)
     fscanf(f1,"%x%s%s%s%s",&address,label,opcode,operand,objcode);
     la=address;
 len=la-sa;
 printf("Length of Program is:%x\n",len);
 fclose(f1);
 f1=fopen("input.txt","r");
 fscanf(f1,"%s%s%s%s%s",saddress,label,opcode,operand,objcode);
 strcpy(startaddress,saddress);
 char temp[80],textrec[50];
 int textlen=0;
 printf("H %s %s %06x\n",label,saddress,len);
 fscanf(f1,"%s%s%s%s%s",saddress,label,opcode,operand,objcode);
 strcat(temp,"");
 strcpy(textrec,"T 00");
 strcat(textrec,saddress);
 while(strcmp(opcode,"END")!=0){
  if((textlen==30)||strcmp(opcode,"RESB")==0||strcmp(opcode,"RESW")==0||textlen+   (strlen(objcode)/2)>30)
  {
   printf("%s %x %s\n",textrec,textlen,temp);
   textlen=0;
   strcpy(temp,"");
   strcpy(textrec,"T 00");
   fscanf(f1,"%s%s%s%s%s",saddress,label,opcode,operand,objcode);
   if(strcmp(objcode,"-")!=0){
     strcat(temp,objcode);
     strcat(temp,"");
     strcat(textrec,saddress);
     textlen+=strlen(objcode)/2;
    }
  }
  else
  {
   textlen+=(strlen(objcode)/2);
   strcat(temp,objcode);
   strcat(temp," ");
  }
  fscanf(f1,"%s%s%s%s%s",saddress,label,opcode,operand,objcode);
 }
 if(textlen!=0)
   printf("%s %x %s\n",textrec,textlen,temp);
 printf("E 00 %s\n\n",startaddress);
 fclose(f1);
}
 

