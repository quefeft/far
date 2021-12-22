#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int find_replace(const char * srcname, const char * destname, const char * pattern, const char * replace){
	FILE *sfp = fopen(srcname, "r");

	FILE *tmpf = tmpfile();

	char c = fgetc(sfp);
	while(c != EOF){
		if(c == pattern[0]){
			char *str = (char*)malloc(strlen(pattern));
			int k=0, match = 0;
			str[k] = c;
			while(c == pattern[k] && !match){
				c = fgetc(sfp);
				++k;
				str[k] = c;
				if(pattern[k] == '\0'){match = 1;}
			}//while
			str[k] = '\0';
			if(match == 1){
				fputs(replace, tmpf);
			}
			else{
				fputs(str, tmpf);
			}
		}//first char match
		fputc(c, tmpf);
		c = fgetc(sfp);
	}//while	

	
	fclose(sfp);
	FILE *dfp = fopen(destname, "w");
	rewind(tmpf);
	c = fgetc(tmpf);
	while(c != EOF){
		fputc(c, dfp);
		c = fgetc(tmpf);	
	}//while

	fclose(dfp);
	fclose(tmpf);
	return(1);
}//find replace





int main(int argc, const char * argv[]){


	if(argc < 2){
		fprintf(stderr, "far: error - No arguments given.\n");
		return(-1);
	}


	char *src = (char *)argv[1];
	char *dest;
	char *pattern;
	char *replace;
	
	if(argc == 4){//dest is src
		dest = (char*)argv[1];
		pattern = (char*)argv[2];
		replace = (char*)argv[3];

	}
	else if(argc == 5){//specified dest
		dest = (char*)argv[2];
		pattern = (char*)argv[3];
		replace = (char*)argv[4];
	}
	else{
		fprintf(stderr, "far: error - Argument count error.\n");
		return(-1);
	}

	
	find_replace(src, dest, pattern, replace);

	return(0);
}//main


