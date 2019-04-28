#include <stdio.h>
#include <conio.h>
#include <string.h>
//#include <fstream> Didn't know it wouldn't work

void mainscr();
void newentry();
void browse_previous();
void delete_en();
void validator();
int main(){
	mainscr();
}
void mainscr(){
	char ch;
	char str_batch_commands[50];
	char cont;
	do{
		mn:
		system("cls");
		system("COLOR 02"); //hacker style, why freakin not?
		printf("Passman v1.0\n");
		printf("\n1. Make a new entry\n2. Browse previous entries");
		printf("\n3: Delete enteries\n4: Exit\t");
		scanf("%d", &ch);
	
		switch(ch){
			case 1: newentry();
					break;
			case 2: browse_previous();
					break;
			case 3: delete_en();
					break;
			case 4: printf("Good to see ya bud, exiting in 2 seconds...");
					strcpy(str_batch_commands, "ping 127.0.0.1 -n 3 > nul"); //holy cow, this hack is amazing
					//hello localfreakinhost btw
					system(str_batch_commands);
					exit(0);
					//strcpy(str_batch_commands, "pause >nul");
					//system(str_batch_commands);
			default: printf("\a\nInvalid choice! Returning to main menu in 2 seconds..");
					 strcpy(str_batch_commands, "ping 127.0.0.1 -n 3 > nul");
					 system(str_batch_commands);
					 goto mn;
		}
	fflush(stdin);
	printf("\nPress y/Y to continue to main menu..");
	scanf("%c", &cont);
	}while(cont=='y'||cont=='Y');
	//main interface is pretty much done
	//choices will be added and new functions will be called accordingly
}
void newentry(){
	//system("COLOR 02");
	FILE *fp;
	char title[20];
	char pass[20];
	char confirm;
	start_ag:
	system("cls");
	printf("Enter a title for the pass (no spaces):\n");
	scanf("%s", &title);
	printf("Enter the password:\n");
	scanf("%s", &pass);
	system("cls");
	printf("\n%s %s", title, pass);
	fflush(stdin);
	printf("\nPress y/Y to confirm entry add, n/N to cancel\t");
	scanf("%c", &confirm);
	if(confirm=='n'||confirm=='N'){
		goto start_ag;
	}
	//confirmation here, is this okay? if not jump to a label
	//time to write these data to a file
	fp=fopen("pass.txt", "a"); //append mode
	//fseek(fp, 0, SEEK_END); //maybe that's just for reading
	fprintf(fp, "%s\t%s\n", title, pass);
	printf("Done writing!");
	fclose(fp);
}
void browse_previous(){
	//system("COLOR 02");
	//basic file handling test using one character read each time
	/*
	FILE *fp;
	char ch;
	fp=fopen("../sample_files/passwords.txt", "r"); //.. to go one directory above, cool
	while(1){
		ch=fgetc(fp);
		if(ch==EOF)
			break;
		printf("%c", ch);
	}
	printf("\n");
	fclose(fp);
	//working as expected, i am very happy now
	*/
	//logic is to be implemented to read word by word
	//logic to fetch a word
	/*
	next to do , figuring out logic to fetch a word
	FILE *fp;
	char ch;
	char word[30];
	fp=fopen("../sample_files/pass_new.txt", "r");
	while(feof(fp)!=0){
		fscanf(fp, "%s", word);
		printf("%s", word);
	}
	*/
	FILE *fp;
	int unsucflg=0;
	char usr_ip[20];
	char title[20];
	char pass[20];
	system("cls");
	printf("Enter the title:\n");
	scanf("%s", &usr_ip);
	fp=fopen("pass.txt", "r");
	fseek(fp, 0, SEEK_SET);
	while(fscanf(fp, "%s\t%s", title, pass)!=EOF){
		if(strcmp(title, usr_ip)==0){
			unsucflg=1;
			printf("Pass entry for %s is: %s\n", title, pass);
		}
		//else{
		//	printf("unsuccessful\n");
		//}
		
	}
	if(unsucflg==0){
		printf("Entry not found! Returning to the main menu in 2 seconds...");
		
	}
	fclose(fp);
	//fseek(fp, 0, SEEK_SET)
}
void delete_en(){
	system("COLOR 04");
}
