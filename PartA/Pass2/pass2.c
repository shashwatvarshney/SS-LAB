#include<stdio.h>
#include<string.h>

void main(){
	FILE *f1,*f2,*f3,*f4;
	f1=fopen("interip.txt","r");
	f4=fopen("output2.txt","w");
	
	char label[20],opcode[20],operand[20];
	int address,sa,len;
	fscanf(f1,"%x%s%s%s",&address,label,opcode,operand);
	fprintf(f4,"%x\t%s\t%s\t%s\n",address,label,opcode,operand);
	fscanf(f1,"%x%s%s%s",&address,label,opcode,operand);
	while(strcmp(opcode,"END")!=0)
	{
		fprintf(f4,"%x\t%s\t%s\t%s",address,label,opcode,operand);
		
				
		char tempcode[20],tempval[20];
		f2=fopen("optab.txt","r");
		fscanf(f2,"%s%s",tempcode,tempval);
		while(!feof(f2)){
			if(strcmp(tempcode,opcode)==0){
				fprintf(f4,"\t%s",tempval);
				break;
				}
			else
				fscanf(f2,"%s%s",tempcode,tempval);
				}
		fclose(f2);
		char actoperand[20];
		int i=0;
		strcpy(actoperand,"");
		if(operand[strlen(operand)-1]=='X'){
			for(i=0;i<strlen(operand-2);i++)
				actoperand[i]=operand[i];
				actoperand[i]='\0';
						   }
		else
			strcpy(actoperand,operand);
		f3=fopen("symtab.txt","r");
		char symcode[20],symval[20];
		fscanf(f3,"%s%s",symcode,symval);
		while(!feof(f3)){
			if(strcmp(symcode,actoperand)==0){
				int lval=strtol(symval,NULL,16);
				if(operand[strlen(operand)-1]=='X')
					lval+=0x8000;
				fprintf(f4,"%x\n",lval);
				break;
				}
			else
				fscanf(f3,"%s%s",symcode,symval);
				}
		fclose(f3);
		if(strcmp(opcode,"WORD")==0){
			int ci=strtol(operand,NULL,16);
			char copy[20];
			fprintf(f4,"\t");
			sprintf(copy,"%X",ci);
			len=strlen(copy);
			while(len<6){
				fprintf(f4,"0");
				len++;
				}
			fprintf(f4,"%s\n",copy);
				}
		if(strcmp(opcode,"BYTE")==0){
			fprintf(f4,"\t");
			if(operand[0]=='X'){
	
				for( i=2;i<strlen(operand)-1;i++)
					fprintf(f4,"%c",operand[i]);
				fprintf(f4,"\n");
					}
			if(operand[0]=='C'){
	
				for(i=2;i<strlen(operand)-1;i++)
					fprintf(f4,"%02X",operand[i]);
				fprintf(f4,"\n");
					}
				
				}	
		if(strcmp(opcode,"RESB")==0||strcmp(opcode,"RESW")==0)
			fprintf(f4,"\t-\n");
		fscanf(f1,"%x%s%s%s",&address,label,opcode,operand);
	}
	fprintf(f4,"%x\t%s\t%s\t%s\n",address,label,opcode,operand);
	printf("Output printed in output2.txt");
	fclose(f1);
	fclose(f4);
}
