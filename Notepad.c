#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<windows.h>
#include<time.h>
int password();
void addnote();
void viewnote();
void editnote();
void searchnote();
void editpassword();
void deletenote();
void colorcode();
void filestore(char s[100]);
void viewlist();

int main()
{
    int ch;
    printf("\n\n\t***********************\n");
    printf("\t*CONSOLE BASED NOTEPAD*\n");
    printf("\t***********************");
   while(1)
   {
        printf("\n\n\t      MAIN MENU:");
        printf("\n\n\tADD NOTE\t[1]");
        printf("\n\tVIEW NOTE\t[2]");
        printf("\n\tEDIT NOTE\t[3]");
        printf("\n\tDELETE NOTE\t[4]");
        printf("\n\tSEARCH NOTE\t[5]");
        printf("\n\tCHANGE COLOR\t[6]");
	    printf("\n\tNOTE LIST\t[7]");
        printf("\n\tEDIT PASSWORD\t[8]");
        printf("\n\tEXIT\t\t[9]");
        printf("\n\n\tENTER YOUR CHOICE:");
        scanf("%d",&ch);

        switch(ch){
            case 1: addnote();
                    break;

            case 2: viewnote();
                    break;

            case 3: system("cls");
                    editnote();
                    break;

            case 4: deletenote();
                    break;
                    
            case 5: searchnote();
			        break;        

            case 6: colorcode();
			        break;
			        
			case 7: viewlist();
			        break;        

			case 8: editpassword();
                    break;

            case 9: printf("\n\n\t\tTHANK YOU......");
                    getch();
                    exit(0);
                    
            default:printf("\nYOU ENTERED INCORRECT CHOICE..");
                    printf("\nPRESS ANY KEY TO TRY AGAIN");
                    getch();
                    break;
        }
        system("cls");
    }
    return 0;
}
void addnote( )
{
    system("cls");
    FILE *fp,*file ;
    char another = 'Y';
    char filename[50],str[500];
    int choice;
    printf("\n\n\t\t***************************\n");
    printf("\t\t* WELCOME TO THE ADD MENU *");
    printf("\n\t\t***************************\n\n");
    while ( another == 'Y'|| another=='y' )
    {
        choice=0;
        printf("\n\n\tENTER NAME OF YOUR NOTE(MAX 50 CHARACTERS):");
        fflush(stdin);
        gets(filename);
        if ((file = fopen(filename, "r")))
        {
            fclose(file);
            printf("\n\tTHE NOTE ALREADY EXISTS.\n");
            choice=1;
        }
        else{
			fp = fopen (filename, "a+" ) ;
		}
        if ( fp == NULL )
        {
            fp=fopen(filename,"w+");
            if(fp==NULL)
            {
                printf("\nSYSTEM ERROR...");
                printf("\nPRESS ANY KEY TO EXIT");
                getch();
                return ;
            }
        }
        if(choice==0)
        {
            fflush(stdin);
            printf("\tNOTE:");
            fflush(stdin);
            gets(str);
			fprintf(fp,"%s",str);
			fclose(fp);
			filestore(filename);
            printf("\nYOUR note IS ADDED...\n");
        }
        printf ( "\n\tADD ANOTHER note...(Y/N) " ) ;
        fflush ( stdin ) ;
        another = getchar( ) ;
    }

    printf("\n\n\tPRESS ANY KEY TO EXIT...");
    getch();
}

void viewnote( )
{
    FILE *fptr ;
    system("cls");
    char choice,filename[50],c;
    printf("\n\n\t\t****************************\n");
    printf("\t\t* HERE IS THE VIEWING MENU *");
    printf("\n\t\t****************************\n\n");
    choice=password();
    if(choice!=0)
    {
        return ;
    }
    do
    {
        printf("\n\tENTER THE NOTE TO BE VIEWED:");
        fflush(stdin);
        gets(filename);

        fptr = fopen ( filename, "r" ) ;
        if ( fptr == NULL )
        {
            puts ( "\nTHE NOTE DOES NOT EXIST...\n" ) ;
            printf("PRESS ANY KEY TO EXIT...");
            getch();
            return ;
        }
        system("cls");

	    printf("\nYOUR NOTE IS:\n");
		c=fgetc(fptr);
		while (c != EOF)
        {
            printf ("%c", c);
            c = fgetc(fptr);
        }

        fclose(fptr);
        printf("\n\nWOULD YOU LIKE TO CONTINUE VIEWING...(Y/N):");
        fflush(stdin);
        scanf("%c",&choice);
    }while(choice=='Y'||choice=='y');
    fclose (fptr) ;
    return ;
}
void editnote()
{
    system("cls");
    FILE *fptr,*fp ;
    int n,t;
    char choice,filename[50],c,str[500],read[100], replace[100],word[100];
    int num,count=0;
    printf("\n\n\t\t*******************************\n");
    printf("\t\t* WELCOME TO THE EDITING MENU *");
    printf("\n\t\t*******************************\n\n");
    choice=password();
    if(choice!=0)
    {
        return ;
    }
    printf("\n\tENTER THE NAME OF NOTE TO BE EDITED:");
    fflush(stdin);
    gets(filename);
    fptr = fopen ( filename, "r+" ) ;
    if ( fptr == NULL )
    {
        printf( "\nNOTE DOES NOT EXISTS:" ) ;
        printf("\nPRESS ANY KEY TO GO BACK");
        getch();
        return;
    }
	printf("\nYOUR OLD NOTE IS:\n");
	c=fgetc(fptr);
	while (c != EOF)
    {
        printf ("%c", c);
        c = fgetc(fptr);
    }
	fclose(fptr);
        printf("\n\n\t\t1.WANT TO EDIT..");
	    printf("\n\n\t\t2.APPEND TO THE LAST..");
	    printf("\n\n\t\t3.INSERT IN THE BEGINNING..");
	    printf("\n\n\t\t4.DELETE LINE..");
	    printf("\n\n\t\t5.REPLACE WORD..");
        printf("\n\n\t\t6.GO BACK TO MAIN MENU.\n");
        printf("\n\tENTER YOUR CHOICE:");
        fflush(stdin);
        scanf("%d",&num);
        fflush(stdin);
        switch(num)
        {
            case 1: printf("ENTER THE NEW NOTE:");
                    printf("\nNOTE:");
                    gets(str);
				    fptr = fopen(filename, "w");
					fprintf(fptr,"%s",str);
			        fclose(fptr);
                    break;

			case 2: printf("APPEND TEXT TO THE END");
                    printf("\nNOTE:");
                    gets(str);
					fptr = fopen(filename, "a");
					fputs(str,fptr);
					fclose(fptr);
					break;

		    case 3: printf("INSERT TEXT A THE BEGINNING");
                    printf("\nNOTE:");
                    gets(str);
					fp = fopen("temp.txt", "a");
					fprintf(fp,"%s",str);
					t=1;
					fptr = fopen(filename,"r");
					c = fgetc(fptr);
                    while (c != EOF)
                    {
                        fputc(c, fp);
                        c = fgetc(fptr);
                    }
					fclose(fp);
					fclose(fptr);
					remove(filename);
					rename("temp.txt",filename);
					break;

            case 4: printf("ENTER LINE NUMBER TO DELETE:");
			        scanf("%d",&n);
					fp=fopen("temp.txt","w");
					fptr = fopen(filename,"r");
					c = getc(fptr);
					t=1;
					while(c!=EOF)
					{
						if (c == '\n')
                            t++;

                        if (t != n)
                        {
                            putc(c, fp);
                        }
						c=getc(fptr);
                    }
                    fclose(fptr);
                    fclose(fp);
                    remove(filename);
                    rename("temp.txt", filename);
					break;
					
			case 5: fp=fopen("temp.txt","w");
					fptr = fopen(filename,"r");
			        printf("Enter the word to be replaced:");
			        fgets(word, 100, stdin);
			        word[strlen(word) - 1] = word[strlen(word)]; 
                    puts("Enter the word to replace it with :"); 
                    fgets(replace, 100, stdin); 
                    replace[strlen(replace) - 1] = replace[strlen(replace)]; 
                    while (!feof(fptr)) {   
                        fscanf(fptr, "%s", read);   
                        if (strcmp(read, word) == 0) { 
                            strcpy(read, replace); 
                        } 
                        fprintf(fp, "%s ", read); 
                    }
                    fclose(fptr);
                    fclose(fp);
                    remove(filename);
                    rename("temp.txt", filename);
			        break;				
			
            case 6: printf("\nPRESS ANY KEY TO GO BACK...\n");
                    getch();
                    return ;
                    break;

            default:printf("\nYOU TYPED SOMETHING ELSE...TRY AGAIN\n");
                    break;
        }
        //system("cls");
        printf("\n\t\tEDITING COMPLETED...\n");
        printf("--------------------\n");
        printf("THE NEW NOTE IS:\n");
        printf("--------------------\n");
        fptr=fopen(filename,"r");
        c=fgetc(fptr);
	while (c != EOF)
    {
        printf ("%c", c);
        c = fgetc(fptr);
    }

    fclose(fptr);
    sleep(10);
    printf("\n\n\tWOULD YOU LIKE TO EDIT ANOTHER NOTE.(Y/N)");
    scanf("%c",&choice);
	if ((choice == 'N') || (choice == 'n')) {
	    printf("\nEDITING PROCESS IS COMPLETED::\n");
    }
    else{
	    fflush(stdin);
	   // sleep(50);
	    system("cls");
	    editnote();
	}
}
void searchnote( )
{
    FILE *fptr ;
    system("cls");
    char choice,filename[50],c;
    printf("\n\n\t\t******************************\n");
    printf("\t\t* HERE IS THE SEARCHING MENU *");
    printf("\n\t\t******************************\n\n");
    choice=password();
    if(choice!=0)
    {
        return ;
    }
    do
    {
        printf("\n\tENTER THE NOTE TO BE SEARCHED:");
        fflush(stdin);
        gets(filename);

        fptr = fopen ( filename, "r" ) ;
        if ( fptr == NULL )
        {
            puts ( "\nTHE NOTE DOES NOT EXIST...\n" ) ;
            printf("PRESS ANY KEY TO EXIT...");
            getch();
            return ;
        }
        system("cls");
        printf("\nNOTE FOUND...\n");
	    printf("\nYOUR NOTE IS:\n");
		c=fgetc(fptr);
		while (c != EOF)
        {
            printf ("%c", c);
            c = fgetc(fptr);
        }

        fclose(fptr);
        printf("\n\nWOULD YOU LIKE TO CONTINUE SEARCHING...(Y/N):");
        fflush(stdin);
        scanf("%c",&choice);
    }while(choice=='Y'||choice=='y');
    fclose (fptr) ;
    return ;
}
int password()
{
    char pass[15]={0},check[15]={0},ch;
    FILE *fpp;
    int i=0,j;
    printf("::FOR SECURITY PURPOSE::");
    printf("::ONLY THREE TRIALS ARE ALLOWED::");
    for(j=0;j<3;j++)
    {
        i=0;
        printf("\n\n\tENTER THE PASSWORD:");
        pass[0]=getch();
        while(pass[i]!='\r')
        {
            if(pass[i]=='\b')
            {
                i--;
                printf("\b");
                printf(" ");
                printf("\b");
                pass[i]=getch();
            }
            else
            {
                printf("*");
                i++;
                pass[i]=getch();
            }
        }
        pass[i]='\0';
        fpp=fopen("SE","r");
        if (fpp==NULL)
        {
            printf("\nPlease SET your PASSWORD before doing anything else.\n");
            getch();
            return 1;
        }
        else
        i=0;
        while(1)
        {
            ch=fgetc(fpp);
            if(ch==EOF)
            {
                check[i]='\0';
                break;
            }
            check[i]=ch-5;
            i++;
        }
        if(strcmp(pass,check)==0)
        {
            printf("\n\n\tACCESS GRANTED...\n");
            return 0;
        }
        else
        {
            printf("\n\n\tWRONG PASSWORD..\n\n\tACCESS DENIED...\n");
        }
    }
        printf("\n\n\t::YOU ENTERED WRONG PASSWORD::YOU ARE NOT ALLOWED TO ACCESS ANY FILE::\n\n\tPRESS ANY KEY TO GO BACK...");
        getch();
        return 1;
}
void editpassword()
{
    system("cls");
    printf("\n");
    char pass[15]={0},confirm[15]={0},ch,firstpass[6]="ENTER";
    int choice,i,check;
    FILE *fp;
    fp=fopen("SE","rb");
    if(fp==NULL)
    {
        fp=fopen("SE","wb");
        if(fp==NULL)
        {
            printf("SYSTEM ERROR...");
            getch();
            return ;
        }
        i=0;
        while(firstpass[i]!='\0')
        {
            ch=firstpass[i];
            putc(ch+5,fp);
            i++;
        }
        putc(EOF,fp);
        fclose(fp);
        printf("\nSYSTEM RESTORED...\nYOUR PASSWORD IS 'ENTER'\n PRESS ENTER TO CHANGE PASSWORD\n\n");
        getch();
    }
    fclose(fp);
    check=password();
    if(check==1)
    {
        return ;
    }
    do
    {
        if(check==0)
        {
            i=0;
            choice=0;
            printf("\n\n\tENTER THE NEW PASSWORD:");
            fflush(stdin);
            pass[0]=getch();
            while(pass[i]!='\r')
            {
                if(pass[i]=='\b')
                {
                    i--;
                    printf("\b");
                    printf(" ");
                    printf("\b");
                    pass[i]=getch();
                }
                else
                {
                    printf("*");
                    i++;
                    pass[i]=getch();
                }
			}
            pass[i]='\0';
            i=0;
            printf("\n\tCONFIRM PASSWORD:");
            confirm[0]=getch();
            while(confirm[i]!='\r')
            {
                if(confirm[i]=='\b')
                {
                    i--;
                    printf("\b");
                    printf(" ");
                    printf("\b");
                    confirm[i]=getch();
                }
                else
                {
                    printf("*");
                    i++;
                    confirm[i]=getch();
                }
            }
            confirm[i]='\0';
            if(strcmp(pass,confirm)==0)
            {
                fp=fopen("SE","wb");
                if(fp==NULL)
                {
                    printf("\n\t\tSYSTEM ERROR");
                    getch();
                    return ;
                }
                i=0;
                while(pass[i]!='\0')
                {
                    ch=pass[i];
                    putc(ch+5,fp);
                    i++;
                }
                putc(EOF,fp);
                fclose(fp);
            }
            else
            {
                printf("\n\tTHE NEW PASSWORD DOES NOT MATCH.");
                choice=1;
            }

        }
    }while(choice==1);

    printf("\n\n\tPASSWORD CHANGED...\n\n\tPRESS ANY KEY TO GO BACK...");
    getch();
}

void deletenote( )
{
    system("cls");
    FILE *fp,*fptr ;
    char filename[50],another = 'Y';
    int choice,check;
    printf("\n\n\t\t**************************\n");
    printf("\t\t* WELCOME TO DELETE MENU *");
    printf("\n\t\t**************************\n\n");
    check = password();
    if(check==1){
        return ;
    }
    while ( another == 'Y' )
    {
        printf("\n\tENTER THE NAME OF NOTE TO BE DELETED:");
        fflush(stdin);
        gets(filename);
        fp = fopen (filename, "wb" ) ;
        if ( fp == NULL )
        {
            printf("\nTHE FILE DOES NOT EXISTS");
            printf("\nPRESS ANY KEY TO GO BACK.");
            getch();
            return ;
        }
        fclose(fp);
        remove(filename);
        printf("\nDELETED SUCCESFULLY...");
        printf("\n\tDO YOU LIKE TO DELETE ANOTHER note.(Y/N):");
        fflush(stdin);
        scanf("%c",&another);
    }
    printf("\n\n\tPRESS ANY KEY TO EXIT...");
    getch();
}
void colorcode()
{
    system("cls");
    printf("\n    0 = Black       8 = Gray\n\
    1 = Blue        9 = Light Blue\n\
    2 = Green       A = Light Green\n\
    3 = Aqua        B = Light Aqua\n\
    4 = Red         C = Light Red\n\
    5 = Purple      D = Light Purple\n\
    6 = Yellow      E = Light Yellow\n\
    7 = White       F = Bright White\n ");

    char code[15] = "COLOR ";

    printf("\nEnter Color Code For Background : ");
    fflush(stdin);
    scanf("%c",&code[6]);
    printf("Enter Color Code For Text : ");
    fflush(stdin);
    scanf("%c",&code[7]);
    if(code[6]==code[7])
    {
        printf("Both Colors Color Be Same \n");
        system("pause");
        system("cls");
        colorcode();
    }
    else
    {
        system(code);
        system("cls");
        printf("Color Changed Successfully");
    }
    printf("\n\n\tPRESS ANY KEY TO EXIT...");
    getch();
}
void filestore(char s[50]){
	FILE *fp;
	time_t t;
	time(&t);
	fp=fopen("filename.txt","r");
	char a[100]="FILENAME\t\t\tCREATED ON\n";
	char b[100]="\t\t\t";
	char c[100]="\t\t\t\t";
	if(fp==NULL){
		fclose(fp);
		fp=fopen("filename.txt","w");
		fprintf(fp,"%s",a);
		
		fclose(fp);
	}
	else{
		fclose(fp);
    }
    fp=fopen("filename.txt","a");
	fprintf(fp,"%s",s);
    fprintf(fp,"%s",b);
	fprintf(fp,"%s",ctime(&t));
	fclose(fp);	
}
void viewlist(){
	int choice;
	system("cls");
	choice=password();
    if(choice!=0)
    {
        return ;
    }
	printf("\n\n\t\t***************\n");
    printf("\t\t*  FILE LIST  *");
    printf("\n\t\t***************\n\n");
	FILE *fp;
	char c;
	fp=fopen("filename.txt","r");
	if(fp==NULL){
		printf("FILE NOT FOUND");
	}
	c=fgetc(fp);
	while (c != EOF) 
    { 
        printf("%c", c); 
        c = fgetc(fp); 
    } 
    fclose(fp); 
    printf("\n\n\tPRESS ANY KEY TO EXIT...");
    getch();
}
