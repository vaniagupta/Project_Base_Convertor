#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>

bool isBinary(const char *num){
	int len=strlen(num);
	for(int i=0;i<len;i++){
		if(num[i] !='0' && num[i] !='1'){
			return false;
		}
	}
	return true;
}
bool isOctal(const char *num){
	int len=strlen(num);
	for(int i=0;i<len;i++){
		if(num[i] <'0' ||  num[i] >'7'){
			return false;
		}
	}
	return true;
}
bool isDecimal(int decimal){
	if(decimal < 0){
		return false;
	}
	return true;
}
bool isValidHexDigit(char c){
	return (c>='0' && c<='9') || (c>='A' && c<='F') || (c>='a' && c<='f');
}
bool isHexaDecimal(const char *num){
	int len=strlen(num);
	for(int i=0;i<len;i++){
		if(!isValidHexDigit(num[i])){
			return false;
		}
	}
	return  true;
}

int binaryToDecimal(const char *num){
	int decimal=0;
	int len=strlen(num);

	for(int i=len-1;i>=0;i--){
		int digit=num[i]-'0';
		decimal+=digit*pow(2,len-1-i);
	}
	
	return decimal;
}

int octalToDecimal(const char *num){
	int decimal=0;
	int len=strlen(num);

	for(int i=len-1;i>=0;i--){
		int digit=num[i]-'0';
		decimal+= digit * pow(8,len-1-i);
	}
	
	return decimal;
}

int hexaDecimalToDecimal(const char *num){
	int decimal=0;
	int len=strlen(num);

	for(int i=len-1;i>=0;i--){
		int digit=0;
		if(num[i]>='0' && num[i]<='9'){
			digit =num[i]-'0';
		}
		else if(num[i]>='A' && num[i]<='F'){
			digit = num[i]-'A'+10;
		}
		else if(num[i]>='a' && num[i]<='f'){
			digit =num[i] -'a' +10;
		}
		decimal+=digit * pow(16,len-1-i);
	}

}

void decimalToBinary(int decimal){
	if(decimal == 0){
	       printf("0");
       		return;
 	}
	int binary[100];
	int index = 0;
	
	while(decimal > 0){
		binary[index++] = decimal % 2;
		decimal /= 2;
	}

	for(int i=index-1;i>=0;i--){
		printf("%d",binary[i]);
	}

}

void decimalToOctal(int decimal){
	if(decimal == 0){
		printf("0");
		return;
	}

	int octal[100];
	int index = 0;
	while(decimal > 0){
		octal[index++]=decimal%8;
		decimal /= 8;
	}

	for(int i=index-1;i>=0;i--){
		printf("%d",octal[i]);
	}
}

void decimalToHexaDecimal(int decimal){
	if(decimal == 0){
		printf("0");
		return;
	}

	char hex[100];
	int index=0;

	while(decimal>0){
		int remainder=decimal%16;
		if(remainder < 10){
			hex[index++] = remainder + '0';
		}
		else{
			hex[index++] = remainder -10 + 'A';
		}
		decimal /= 16;
	}

	for(int i = index-1;i>=0;i--){
		printf("%c",hex[i]);
	}
}

void binaryToOctal(const char *num){
	int decimal=binaryToDecimal(num);
	decimalToOctal(decimal);
}

void binaryToHexaDecimal(const char *num){
	int decimal=binaryToDecimal(num);
	decimalToHexaDecimal(decimal);
}

void octalToBinary(const char *num){
	int decimal=octalToDecimal(num);
	decimalToBinary(decimal);
}

void octalToHexaDecimal(const char *num){
	int decimal=octalToDecimal(num);
	decimalToHexaDecimal(decimal);
}

void hexaDecimalToBinary(const char *num){
	int decimal=hexaDecimalToDecimal(num);
	decimalToBinary(decimal);
}

void hexaDecimalToOctal(const char *num){
	int decimal=hexaDecimalToDecimal(num);
	decimalToOctal(decimal);
}
int main(){
	int flag=1;
	int op;

	printf("\t COMPLETE NUMBER SYSTEM CONVERSION\n\n");

	while(flag!=0){
		printf("\t CHOOSE THE CONVERSION\n\n");
		printf("1: Binary to Decimal\n");
		printf("2: Binary to Octal\n");
		printf("3: Binary to Hexadecimal\n");

		printf("4: Decimal to Binary\n");
		printf("5: Decimal to Octal\n");
		printf("6: Decimal to HexaDecimal\n");

		printf("7: Octal to Binary\n");
		printf("8: Octal to Decimal\n");
		printf("9: Octal to HexaDecimal\n");

		printf("10: HexaDecimal to Binary\n");
		printf("11: HexaDecimal to Octal\n");
		printf("12: HexaDecimal to Decimal\n");

		printf("\nENTER YOUR CHOICE: ");
		scanf("%d",&op);
		int decimal;
		char num[100];
		switch(op){
			case 1:
				printf("\n**BINARY TO DECIMAL**\n");
				printf("\nEnter the Number in Binary form(0s & 1s): ");
				scanf("%s",num);
				if(isBinary(num)){
					printf("Decimal equivalent: ");
					printf("%d",binaryToDecimal(num));
				}
				else{
					printf("\nInvalid Binary Number\n");
				}
				break;
			case 2: 

				printf("\n**BINARY TO OCTAL**\n");
				printf("\nEnter the Number in Binary form(0s & 1s): ");
				scanf("%s",num);
				if(isBinary(num)){
					printf("Octal equivalent: ");
					binaryToOctal(num);
				}
				else{
					printf("\nInvalid Binary Number\n");
				}
				break;
			case 3:
				printf("\n**BINARY TO HEXADECIMAL**\n");
				printf("\nEnter the Number in Binary form(0s & 1s): ");
				scanf("%s",num);
				if(isBinary(num)){
					printf("HexaDecimal equivalent: ");
					binaryToHexaDecimal(num);
				}
				else{
					printf("\nInvalid Binary Number\n");
				}
				break;
			case 4:
				printf("\n**DECIMAL TO BINARY**\n");
				printf("\nEnter the Number in Decimal form(0-9): ");
				scanf("%d",&decimal);
				if(isDecimal(decimal)){
					printf("Binary equivalent: ");
					decimalToBinary(decimal);
				}
				else{
					printf("\nInvalid Decimal Number\n");
				}
				break;
			case 5: 
				printf("\n**DECIMAL TO OCTAL**\n");
				printf("\nEnter the Number in Decimal form(0-9): ");
				scanf("%d",&decimal);
				if(isDecimal(decimal)){
					printf("Octal equivalent: ");
					decimalToOctal(decimal);
				}
				else{
					printf("\nInvalid Decimal Number\n");
				}
				break;
			case 6:
				printf("\n**DECIMAL TO HEXADECIMAL**\n");
				printf("\nEnter the Number in Decimal form(0-9): ");
				scanf("%d",&decimal);
				if(isDecimal(decimal)){
					printf("Hexadecimal equivalent: ");
					decimalToHexaDecimal(decimal);
				}
				else{
					printf("\nInvalid Decimal Number\n");
				}
				break;
			case 7:
				printf("\n**OCTAL TO BINARY**\n");
				printf("\nEnter the Number in Octal form(0-7): ");
				scanf("%s",num);
				if(isOctal(num)){
					printf("Binary  equivalent: ");
					octalToBinary(num);
				}
				else{
					printf("\nInvalid Octal Number\n");
				}
				break;
			case 8:
				printf("\n**OCTAL TO DECIMAL**\n");
				printf("\nEnter the Number in Octal form(0-7): ");
				scanf("%s",num);
				if(isOctal(num)){
					printf("Decimal  equivalent: ");
					printf("%d",octalToDecimal(num));
				}
				else{
					printf("\nInvalid Octal Number\n");
				}
				break;
			case 9:
				printf("\n**OCTAL TO HEXADECIMAL**\n");
				printf("\nEnter the Number in Octal form(0-7): ");
				scanf("%s",num);
				if(isOctal(num)){
					printf("HexaDecimal  equivalent: ");
					octalToHexaDecimal(num);
				}
				else{
					printf("\nInvalid Octal Number\n");
				}
				break;
			case 10:
				printf("\n**HEXADECIMAL TO BINARY**\n");
				printf("\nEnter the Number in HexaDecimal form(0-9 & A-F): ");
				scanf("%s",num);
				if(isHexaDecimal(num)){
					printf("Binary  equivalent: ");
					hexaDecimalToBinary(num);
				}
				else{
					printf("\nInvalid HexaDecimal Number\n");
				}
				break;
			case 11:
			
				printf("\n**HEXADECIMAL TO OCTAL**\n");
				printf("\nEnter the Number in HexaDecimal form(0-9 & A-F): ");
				scanf("%s",num);
				if(isHexaDecimal(num)){
					printf("Octal  equivalent: ");
					hexaDecimalToOctal(num);
				}
				else{
					printf("\nInvalid HexaDecimal Number\n");
				}
				break;
			case 12:
				 
				printf("\n**HEXADECIMAL TO DECIMAL**\n");
				printf("\nEnter the Number in HexaDecimal form(0-9 & A-F): ");
				scanf("%s",num);
				if(isHexaDecimal(num)){
					printf("Decimal  equivalent: ");
					printf("%d",hexaDecimalToDecimal(num));
				}
				else{
					printf("\nInvalid HexaDecimal Number\n");
				}
				break;
			default:
				printf("\nINVALID NUMBER\n");
				break;
		}
		printf("\nDO YOY WANT TO CONTINUE =(1/0) :\n");
		scanf("%d",&flag);
	}

	return 0;
}
