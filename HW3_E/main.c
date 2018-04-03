/* Author: Michael Pritugin 241 gr
Development was cunducted from 28.10.2017 to 29.10.2017
Program "sort" betta version

Possible parameters:
+n: sort since n of a line
-m: merge all files
-o: using output file
-r: upside-down

Possible mistakes:
#3: error opening of the file
#2: error of closing of the file
#1: file deletion error */
/* MODE`s bytes */
#define PAR_R (1<<3)
#define PAR_N (1<<2)
#define PAR_M (1<<1)
#define PAR_O (1)
/* MODE`s mask */
#define MOD_R(a) (((a)>>3)&1)
#define MOD_N(a) (((a)>>2)&1)
#define MOD_M(a) (((a)>>1)&1)
#define MOD_O(a) ((a)&1)

/* debuf setting */
#define NO_DEBUG
//--------------------------------------------------
/* The program is changed to the task of the AaDS */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//#include "sort.h"
#define too(a) (1<<a)
#define last(b) (strlen(b)-1)
#define bit(c) (c&1)



// int fputs( const char * string, FILE * filestream );
// char * fgets( char * string, int num, FILE * filestream );
// int strcmp( const char * string1, const char * string2 );
// FILE * fopen( const char * fname, const char * modeopen );
// int fclose( FILE * filestream );
// int remove( const char * fname );

void CopyFile(const char* name_input,const char* name_output,char** string,int counter)
{
#ifdef DEBUG
    printf("In function CopyFile\n");
#endif // DEBUG
    FILE* IN = fopen(name_input, "r");
	FILE* OUT = fopen(name_output, "w");
	for (int i = 1; i < counter; i++)
	{
		fgets(string[0], 10011, IN);
		fputs(string[0], OUT);
	}
	fgets(string[0], 10011, IN);
	string[0][last(string[0])] = '\0';
	fputs(string[0], OUT);
	fclose(OUT);
	fclose(IN);
#ifdef DEBUG
    printf("End function CopyFile\n");
#endif // DEBUG
}

void external_sorting(const char* name_input,const char* name_output)
{
#ifdef DEBUG
    printf("In function external_sorting\n");
#endif // DEBUG
    int core;
    int i=0, j=0;
    int n=0, k=0;
    int center=0;
    int counter=0;
    FILE * IN = fopen(name_input, "r");
    FILE * bufer[2];
    // bufer files
    bufer[0] = fopen("bufer_0_241.txt", "w");
	bufer[1] = fopen("bufer_1_241.txt", "w");
	FILE * OUT = fopen("bufer_2_241.txt", "w");
	//-----------------------------------------------
	char** string;
	string=(char**)malloc(2*sizeof(char*));
	for(int i=0;i<2;i++)
    {
        string[i]=(char*)malloc(10011*sizeof(char));
    }
    //-----------------------------------------------
	int choose;
#ifdef DEBUG
    printf("After malloc and before Main While\n");
#endif // DEBUG
	while (fgets(string[0], 10011, IN)) { fputs(string[0], bufer[bit(counter)]); counter++; }
	fputc('\n', bufer[!bit(counter)]);
	fclose(IN);
	fclose(bufer[0]); fclose(bufer[1]);
	bufer[0] = fopen("bufer_0_241.txt", "r"); bufer[1] = fopen("bufer_1_241.txt", "r");
#ifdef DEBUG
    printf("After Main While before Main FOR\n");
#endif // DEBUG
	for (core = 0; (counter - 1) >> core > 0; core++)
	{
		n = too(core);
		k = counter >> (core + 1);
		for (center = 0; center < k; center++)
		{
		    fgets(string[0], 10011, bufer[0]);
            fgets(string[1], 10011, bufer[1]);
            i = 0;
            j = 0;
// --------------------------------------- GIPERION -------------------------------------------
#ifdef DEBUG
    printf("Label GIPERION\n");
#endif // DEBUG
			for (; i < n && j < n;)
			{
				choose = strcmp(string[0], string[1]);
				if (choose < 0)
				{
					fputs(string[0], OUT);
					i++;
					if (i < n) fgets(string[0], 10011, bufer[0]);
				}
				else
				{
					fputs(string[1], OUT);
					j++;
					if (j < n) fgets(string[1], 10011, bufer[1]);
				}
			}
			if (i < n)
			{
				fputs(string[0], OUT);
				i++;
				for (; i < n; i++)
				{
					fgets(string[0], 10011, bufer[0]);
					fputs(string[0], OUT);
				}
			}
			if (j < n)
			{
				fputs(string[1], OUT);
				j++;
				for (; j < n; j++)
				{
					fgets(string[1], 10011, bufer[1]);
					fputs(string[1], OUT);
				}
			}
		}
// ------------------------------------------------- KRIOS ---------------------------------------------------
#ifdef DEBUG
    printf("Label KRIOS\n");
#endif // DEBUG
		k = counter & (too(core) - 1);
		center = counter & too(core);

		if (center && k)
		{
		    fgets(string[0], 10011, bufer[0]);
            fgets(string[1], 10011, bufer[1]);
            i = 0;
            j = 0;
			for (; i < n && j < k;)
			{
				choose = strcmp(string[0], string[1]);
				if (choose < 0)
				{
					fputs(string[0], OUT);
					i++;
					if (i < n) fgets(string[0], 10011, bufer[0]);
				}
				else
				{
					fputs(string[1], OUT);
					j++;
					if (j < k) fgets(string[1], 10011, bufer[1]);
				}
			}
			if (i < n)
			{
				fputs(string[0], OUT);
				for (i++; i < n; i++)
				{
					fgets(string[0], 10011, bufer[0]);
					fputs(string[0], OUT);
				}
			}
			if (j < k)
			{
				fputs(string[1], OUT);
				j++;
				for (; j < k; j++)
				{
					fgets(string[1], 10011, bufer[1]);
					fputs(string[1], OUT);
				}
			}
		}
// -------------------------------------------- OKEAN --------------------------------------
		else
		{
#ifdef DEBUG
    printf("Label OKEAN\n");
#endif // DEBUG
		    center+=k;
			for (i = 0; i < center; i++)
			{
				fgets(string[0], 10011, bufer[0]);
				fputs(string[0], OUT);
			}
		}
		fclose(OUT);
		fclose(bufer[0]);
		fclose(bufer[1]);
#ifdef DEBUG
    printf("before BREAK\n");
#endif // DEBUG
		if ((counter - 1) >> core == 1) break;
		OUT = fopen("bufer_2_241.txt", "r");
		bufer[0] = fopen("bufer_0_241.txt", "w");
		bufer[1] = fopen("bufer_1_241.txt", "w");
		n<<=1;
		k = ((counter - 1) / n) + 1;
#ifdef DEBUG
    printf("Label TITAN \n");
#endif // DEBUG
//--------------------------------------------------- TITAN -----------------------------------------------------------
		for (center = 0; center < k; center++)
		{
			i = 0;
			while (i < n && fgets(string[0], 10011, OUT))
			{
			    i++;
				fputs(string[0], bufer[bit(center)]);
			}
		}
		fclose(OUT);
		fclose(bufer[0]);
		fclose(bufer[1]);
		OUT = fopen("bufer_2_241.txt", "w");
		bufer[0] = fopen("bufer_0_241.txt", "r");
		bufer[1] = fopen("bufer_1_241.txt", "r");
	}
#ifdef DEBUG
    printf("Before CopyFile\n");
#endif // DEBUG
	CopyFile("bufer_2_241.txt",name_output,string,counter);
	remove("bufer_0_241.txt");
	remove("bufer_1_241.txt");
	remove("bufer_2_241.txt");
#ifdef DEBUG
    printf("End of function external_sorting\n");
#endif // DEBUG
}


//main
int main(int argc,char* argv[])
{
#ifdef DEBUG
    printf("Start program\n");
#endif // DEBUG
    external_sorting("input.txt","output.txt");
	return 0;
}
