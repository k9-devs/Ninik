#include <stdio.h>
#include <conio.h>
#include <string.h>
//#include <fstream>

void mainscr();
void newentry();
void browse_previous();
void delete_en();
void validator();
void change_entry_pass();
void entry_pass_find(); //normal writing is not providing the compatible format
void write_pass_to_file();
char entrypass[40];
//entrypass is retrieved from a file
//strcpy(entrypass, "Ninik");
int main(){
	//system("@echo off");
    //system("start /max");
	//write_pass_to_file();
    entry_pass_find();
	validator();
}
void mainscr(){
	char ch;
	char str_batch_commands[50];
	char cont;
	system("title Ninik Password Manager v1.0");
	do{
		mn:
		system("cls");
		system("COLOR 02");
		printf("Ninik Password Manager v1.0\n");
		printf("\n1. Make a new entry\n2. Browse previous entries");
		printf("\n3: Delete entry\n4: Change entry pass\n");
		printf("5: Exit\n\n> ");
		scanf("%d", &ch);
	
		switch(ch){
			case 1: newentry();
					break;
			case 2: browse_previous();
					break;
			case 3: delete_en();
					break;
			case 4: change_entry_pass();
					break;
			case 5: printf("Good to see ya bud, exiting in 2 seconds...");
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
	printf("\nPress y/Y to confirm entry addition, n/N to cancel\t");
	scanf("%c", &confirm);
	if(confirm=='n'||confirm=='N'){
		goto start_ag;
	}
	//confirmation here, is this okay? if not jump to a label
	//if yes, time to write this data to a file
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
		//strcpy(str_batch_commands, "ping 127.0.0.1 -n 3 > nul");
		system("ping 127.0.0.1 -n 3 > nul");
	}
	fclose(fp);
	//fseek(fp, 0, SEEK_SET)
}
void delete_en(){
	//logic: copy all lines, except one, to a new file and then renaming the file4
	char title2[40];
	char title[40], pass[40];
	system("COLOR 04");
	FILE *fp1, *fp2;
	fp1=fopen("pass.txt", "r");
	fp2=fopen("passtemp.txt", "w");
	system("cls");
	printf("\aWarning! These changes are irreversible, proceed with caution!\n");
	printf("Enter the title");
	scanf("%s", &title2);
	while(fscanf(fp1, "%s\t%s", title, pass)!=EOF){
    	if(strcmp(title, title2)!=0){
			fprintf(fp2, "%s\t%s\n", title, pass);
		}
	}
	fclose(fp1);
	fclose(fp2);
	remove("pass.txt");
	//might show error if the above and below lines are switched, not testsed yet
	rename("passtemp.txt", "pass.txt");
	printf("Entry deletion successful! Returning to the main menu in 2 seconds...");
	system("ping 127.0.0.1 -n 3 > nul");
}
void validator(){
	char userpass[40];
	//validator code
	loop:
	system("cls");
	printf("Entry password: ");
	scanf("%s", &userpass);
	if(strcmp(userpass, entrypass)!=0){
		printf("Wrong password! Returning to the first screen in 2 seconds...\n");
		system("ping 127.0.0.1 -n 3 > nul");
		goto loop;
	}
	else{
		mainscr();
	}
}
void change_entry_pass(){
	system("cls");
	FILE *fp;
	fp=fopen("en_pass.txt", "w");
	char new_pass[40];
	printf("Enter new entry pass(no spaces):");
	scanf("%s", &new_pass);
	fseek(fp, 0, SEEK_SET);
	fprintf(fp, "%s", new_pass);
	//not keeping the record of old passwords, replacing stuff
	fclose(fp);
}

void entry_pass_find(){
	FILE *fp;
	char pass[40];
	fp=fopen("en_pass.txt", "r");
	fscanf(fp, "%s\n", pass);
	strcpy(entrypass, pass);
	fclose(fp);
}
void write_pass_to_file(){
	FILE *fp;
	char temp[40]="Ninik";
	fp=fopen("en_pass.txt", "w");
	fprintf(fp, "%s\n", temp);
	printf("\nChanging password success! Returning in 2 seconds...");
	system("ping 127.0.0.1 -n 3 >nul");
	fclose(fp);
}

