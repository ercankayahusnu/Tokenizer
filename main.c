#include <stdbool.h> 
#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 

// deneme.txt
int main(int argc, char *argv[]) {
	
    char *fileName = malloc(sizeof(char) * 20);
	printf( "Dosya ismini giriniz: ");
	scanf("%s", fileName);
    FILE *file;
    
	file=fopen(fileName, "r");
	char *letter;
	
	printf("\n\n -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- SOURCE CODE WITH INDENTATION  *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-* \n\n");
	
	if(file != NULL){
		
		while (! feof(file)) {
		    letter = fgetc(file);
			printf("%c ", letter);
		}
		
	} else {
		printf("File was not found.");
		return 0;
	}
	
	fclose(file);
	
	printf("\n\n -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-* SOURCE CODE WITH COMMA -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-* \n\n");
	
	file=fopen(fileName,"r");
	
	if(file != NULL){
		
		printf("{ ");
		
		while( !feof(file) ){
			
		    letter = fgetc(file);
		    
		    if(letter != ' ' && letter != '\n' && letter != EOF) {
		    	printf("%c, ", letter);
			}
		}
		
		printf(" }");
		
	} else {
		printf("File was not found.");
		return 0;
	}
	
	fclose(file);
	
	printf("\n\n -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- RESULT OF TOKENILIZER -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-* \n\n");
	
	file=fopen(fileName,"r");
	char ch;
	
	if(file != NULL){
		
		char *previousCharType = "other";
		
		printf("{ ");
		
		while( !feof(file) ){
			
		    ch = fgetc(file);
		    
		    if(ch == ' ' || ch == '  ' || ch == '\n' && letter == EOF) continue;
		    
		    bool isDelimiter = ( ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == ',' || ch == ';' || ch == '>' ||  
		                         ch == '<' || ch == '=' || ch == '(' || ch == ')' || ch == '[' || ch == ']' || ch == '{' || ch == '}' 
							   );
								  
			bool isOperator = ( ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '>' || ch == '<' || ch == '=' );
		    
		    bool isNumber = ( ch == '0' || ch == '1' || ch == '2' || ch == '3' || ch == '4' || ch == '5' || ch == '6' || ch == '7' || ch == '8' || ch == '9' );		
			
			if(previousCharType == "other"){
				if(isOperator){
					previousCharType = "operator";
					printf(", %c", ch);
					
				} else if(isDelimiter) {
				    previousCharType = "delimiter";
					printf(", %c", ch);
				
				} else if(isNumber) {
					previousCharType = "number";
					printf(", %c", ch);
				
				} else {
					previousCharType = "other";
					printf("%c", ch);
				}	
			} else if(previousCharType == "operator") {
				if(isOperator){
					previousCharType = "operator";
					printf("%c", ch);
					
				} else if(isDelimiter) {
				    previousCharType = "delimiter";
					printf(", %c", ch);
				
				} else if(isNumber) {
					previousCharType = "number";
					printf(", %c", ch);
				
				} else {
					previousCharType = "other";
					printf(", %c", ch);
				}
			} else if(previousCharType == "delimiter") {
				if(isOperator){
					previousCharType = "operator";
					printf(", %c", ch);
					
				} else if(isDelimiter) {
				    previousCharType = "delimiter";
					printf(", %c", ch);
				
				} else if(isNumber) {
					previousCharType = "number";
					printf(", %c", ch);
				
				} else {
					previousCharType = "other";
					printf(", %c", ch);
				}
			} else if(previousCharType == "number") {
				if(isOperator){
					previousCharType = "operator";
					printf(", %c", ch);
					
				} else if(isDelimiter) {
				    previousCharType = "delimiter";
					printf(", %c", ch);
				
				} else if(isNumber) {
					previousCharType = "number";
					printf("%c", ch);
				
				} else {
					previousCharType = "other";
					printf(", %c", ch);
				}
			} 
				
			
			/*			
		    if(isDelimiter || isOperator || isNumber) {
				if(isPreviousChar) {
					printf(", ");
					isPreviousChar = false;
				}
				
				printf("%c, ", ch);
			
			} else {
				isPreviousChar = true;
				printf("%c", ch);
			}
			*/
		}
		
		printf(" }");
		
	} else {
		printf("File was not found.");
	}
	
	fclose(file);
	
	printf("\n\n -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- THE END  *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-* \n\n");
	
	return 0;
}
