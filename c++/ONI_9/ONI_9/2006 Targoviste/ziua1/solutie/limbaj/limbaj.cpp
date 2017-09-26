#include <stdio.h>
#include <string.h>

int to_lower(char *string){
	int i=0;
	for(i=0;i<strlen(string);i++){
		if ((string[i]<91) && (string[i]>=65)) string[i]+=32;
	}
	return 0;
}

int main(){
	freopen("limbaj.in","rt",stdin);
	freopen("limbaj.out","wt",stdout);
	int v[26];
	int nivel[2500];
	memset(nivel,0,2500*sizeof(int));
	int niv=0;
	for(int i=0;i<26;i++){
		scanf("%d",&v[i]);
	}
	
	int flag=0;
	char string[200];
	
	while(scanf("%s",string)>0){
		to_lower(string);

		if(flag=1 && strlen(string)==3 && string[1]=='='){
			v[string[0]-97]=v[string[2]-97];
			continue;
		}
		
		if(!strcmp(string,"if")){
			scanf("%s",string);
			if(string[0]=='='){
				if(v[string[1]-97]==v[string[2]-97])
					nivel[niv]=1;
			}
			if(string[0]=='>'){
				if(v[string[1]-97]>v[string[2]-97])
					nivel[niv]=1;
			}
			if(string[0]=='<'){
				if(v[string[1]-97]<v[string[2]-97])
					nivel[niv]=1;
			}
			niv++;
			continue;
		}
		
		if(!strcmp(string,"fi")){
			nivel[niv-1]=0;
			niv--;
		}
		//sar peste toate liniile din da, daca asta e fals
		if((!strcmp(string,"da")) && (nivel[niv-1]==0)){
			flag=0;
			char string1[10];
			int niv1=0;
			while(flag==0){
				scanf("%s",string1);
				if(!strcmp(string1,"if")) niv1++;
				if(!strcmp(string1,"fi")&&(niv1>0)) niv1--;
				if(!strcmp(string1,"fi")&&(niv1==0)) flag=1;
				if(!strcmp(string1,"nu")&&(niv1==0)) flag=1;
			}
			continue;
		}
		//sar peste toate liniile din nu, daca asta e fals
		if((!strcmp(string,"nu")) && (nivel[niv-1]==1)){
			flag=0;
			char string1[10];
			int niv1=0;
			while(flag==0){
				scanf("%s",string1);
				if(!strcmp(string1,"if")) niv1++;
				if(!strcmp(string1,"fi")&&(niv1>0)) niv1--;
				if(!strcmp(string1,"fi")&&(niv1==0)) flag=1;
			}
			continue;
		}
	}
	
	//afisarea
	for(int j=0;j<26;j++)
		printf("%d ",v[j]);
	printf("\n");
	return 0;
}
