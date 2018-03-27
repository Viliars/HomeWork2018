#include<stdio.h>
#include<string.h>
#include<stdlib.h>


// int fputs( const char * string, FILE * filestream );
// char * fgets( char * string, int num, FILE * filestream );
// int strcmp( const char * string1, const char * string2 );

int too(int core)
{
 // 2^core
    return 1<<core;
}

void CopyFile(const char* name_input,const char* name_output,char** string,int counter)
{
    FILE* IN = fopen(name_input, "r");
	FILE* OUT = fopen(name_output, "w");
	for (int i = 1; i < counter; i++)
	{
		fgets(string[0], 10010, IN);
		fputs(string[0], OUT);
	}
	fgets(string[0], 10010, IN);
	string[0][strlen(string[0]) - 1] = '\0';
	fputs(string[0], OUT);
	fclose(OUT);
	fclose(IN);
}

void external_sorting(const char* name_input,const char* name_output)
{
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
	while (fgets(string[0], 10010, IN)) { fputs(string[0], bufer[counter&1]); counter++; }
	fputc('\n', bufer[!(counter & 1)]);
	fclose(IN);
	fclose(bufer[0]); fclose(bufer[1]);
	bufer[0] = fopen("bufer_0_241.txt", "r"); bufer[1] = fopen("bufer_1_241.txt", "r");
	for (core = 0; (counter - 1) >> core > 0; core++)
	{
		n = too(core);
		k = counter >> (core + 1);
		for (center = 0; center < k; center++)
		{
		    fgets(string[0], 10010, bufer[0]);
            fgets(string[1], 10010, bufer[1]);
            i = 0;
            j = 0;
			for (; i < n && j < n;)
			{
				choose = strcmp(string[0], string[1]);
				if (choose < 0)
				{
					fputs(string[0], OUT);
					i++;
					if (i < n) fgets(string[0], 10010, bufer[0]);
				}
				else
				{
					fputs(string[1], OUT);
					j++;
					if (j < n) fgets(string[1], 10010, bufer[1]);
				}
			}
			if (i < n)
			{
				fputs(string[0], OUT);
				i++;
				for (; i < n; i++)
				{
					fgets(string[0], 10010, bufer[0]);
					fputs(string[0], OUT);
				}
			}
			if (j < n)
			{
				fputs(string[1], OUT);
				j++;
				for (; j < n; j++)
				{
					fgets(string[1], 10010, bufer[1]);
					fputs(string[1], OUT);
				}
			}
		}
		k = counter & (too(core) - 1);
		center = counter & too(core);

		if (center && k)
		{
		    fgets(string[0], 10010, bufer[0]);
            fgets(string[1], 10010, bufer[1]);
            i = 0;
            j = 0;
			for (; i < n && j < k;)
			{
				choose = strcmp(string[0], string[1]);
				if (choose < 0)
				{
					fputs(string[0], OUT);
					i++;
					if (i < n) fgets(string[0], 10010, bufer[0]);
				}
				else
				{
					fputs(string[1], OUT);
					j++;
					if (j < k) fgets(string[1], 10010, bufer[1]);
				}
			}
			if (i < n)
			{
				fputs(string[0], OUT);
				for (i++; i < n; i++)
				{
					fgets(string[0], 10010, bufer[0]);
					fputs(string[0], OUT);
				}
			}
			if (j < k)
			{
				fputs(string[1], OUT);
				j++;
				for (; j < k; j++)
				{
					fgets(string[1], 10010, bufer[1]);
					fputs(string[1], OUT);
				}
			}
		}
		else
		{
		    center+=k;
			for (i = 0; i < center; i++)
			{
				fgets(string[0], 10010, bufer[0]);
				fputs(string[0], OUT);
			}
		}
		fclose(OUT);
		fclose(bufer[0]);
		fclose(bufer[1]);
		if ((counter - 1) >> core == 1) break;
		OUT = fopen("bufer_2_241.txt", "r");
		bufer[0] = fopen("bufer_0_241.txt", "w");
		bufer[1] = fopen("bufer_1_241.txt", "w");
		k = ((counter - 1) / (n <<= 1)) + 1;
		for (center = 0; center < k; center++)
		{
			i = 0;
			while (i < n && fgets(string[0], 10010, OUT))
			{
			    i++;
				fputs(string[0], bufer[center & 1]);
			}
		}
		fclose(OUT);
		fclose(bufer[0]);
		fclose(bufer[1]);
		OUT = fopen("bufer_2_241.txt", "w");
		bufer[0] = fopen("bufer_0_241.txt", "r");
		bufer[1] = fopen("bufer_1_241.txt", "r");
	}
	CopyFile("bufer_2_241.txt",name_output,string,counter);
	remove("bufer_0_241.txt");
	remove("bufer_1_241.txt");
	remove("bufer_2_241.txt");
}



int main(int argc,char* argv[])
{
    external_sorting("input.txt","output.txt");
	return 0;
}
