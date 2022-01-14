#include<stdio.h>
#include<stdlib.h>
#include<string.h>


char esc_chars[] = {'a','b','f','n','r','t','v','\\','"','\0'};
char esc_codes[] = {0x07,0x08,0x0c,0x0a,0x0d,0x09,0x0b,0x5c,0x22};


char get_escape_code(char c){
	char code=-1;
	int i=0;
	while(code == -1 && esc_chars[i] != '\0'){
		if(esc_chars[i] == c){
			code = esc_codes[i];
		}//match
		++i;
	}//while
	return(code);
}//get_escape_code



void escape_string(char *str){
	int i=0;
	char c = *(str+i);
	while(c != '\0'){
		if(c == '\\'){
			c = *(str+i+1);
			char new_c = get_escape_code(c);
			*(str+i) = new_c;
			//move up rest of string
			int k=1;
			while(*(str+i+k) != '\0'){
				*(str+i+k) = *(str+i+k+1);
				++k;
			}//while move up
		}//if the char is
		++i;
		c = *(str+i);
	}//while
}//escape_string




int find_replace(const char * srcname, const char * destname, const char * pattern, const char * replace){
	FILE *sfp = fopen(srcname, "r");

	FILE *tmpf = tmpfile();

	char c = fgetc(sfp);
	while(c != EOF){
		if((c == pattern[0] && pattern[0] != '\\') || (pattern[0] == '\\' && c == get_escape_code(pattern[1]))){
			char *str = (char*)malloc(strlen(pattern));
			int k=0, match = 0;
			char next_char = pattern[k];
			str[k] = c;
			while(c == next_char && !match){
				c = fgetc(sfp);
				++k;
				next_char = pattern[k];
				if(pattern[k] == '\\'){
					next_char = get_escape_code(pattern[++k]);
					if(next_char == -1){
						fprintf(stderr, "Error parsing escape sequence. Escaped char does not match implemented escape codes. Escaped char hex value: 0x%x\n", pattern[k]);
					}//escape error
				}//slash to get next char

				str[k] = next_char;

				//match at the end
				if(pattern[k] == '\0'){match = 1;}
			}//while
			str[k] = '\0';
			if(match == 1){
				fputs(replace, tmpf);
			}
			else{
				fputs(str, tmpf);
			}
			free(str);
		}//first char match
		else{
			fputc(c, tmpf);
			c = fgetc(sfp);
		}
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


	escape_string(replace);//parse and escape sequences in replacement str.

	
	find_replace(src, dest, pattern, replace);

	return(0);
}//main


