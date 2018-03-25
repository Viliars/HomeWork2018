#include<stdio.h>
#include<string.h>

void external_sorting(const char* name_input,const char* name_output)
{
    unsigned core;
    unsigned count = 0;
    unsigned i, j, n, k, c;
    FILE * input = fopen(name_input, "r");
    FILE * bufer[2];
    bufer[0] = fopen("bufer_0_241.txt", "w");
	bufer[1] = fopen("bufer_1_241.txt", "w");
	FILE * output = fopen("bufer_2_241.txt", "w");
	char str1[10002];
	char str2[10002];
	int choose;
	while (fgets(str1, 10001, input)) fputs(str1, bufer[count++ & 1]);
	fputc('\n', bufer[!(count & 1)]);
	fclose(input);
	fclose(bufer[0]);
	fclose(bufer[1]);
	bufer[0] = fopen("bufer_0_241.txt", "r");
	bufer[1] = fopen("bufer_1_241.txt", "r");
	for (core = 0; (count - 1) >> core > 0; core++)
	{
		n = (1 << core);
		k = count >> (core + 1);
		for (c = 0; c < k; ++c)
		{
			for (i = 0, j = 0,
				fgets(str1, 10001, bufer[0]),
				fgets(str2, 10001, bufer[1]);
				i < n && j < n;)
			{
				choose = strcmp(str1, str2);
				if (choose < 0)
				{
					fputs(str1, output);
					if (++i < n) fgets(str1, 10001, bufer[0]);
				}
				else
				{
					fputs(str2, output);
					if (++j < n) fgets(str2, 10001, bufer[1]);
				}
			}
			if (i < n)
			{
				fputs(str1, output);
				for (++i; i < n; ++i)
				{
					fgets(str1, 10001, bufer[0]);
					fputs(str1, output);
				}
			}
			if (j < n)
			{
				fputs(str2, output);
				for (++j; j < n; ++j)
				{
					fgets(str2, 10001, bufer[1]);
					fputs(str2, output);
				}
			}
		}
		k = count & ((1 << core) - 1);
		c = count & (1 << core);
		if (!(c && k))
		{
			c += k;
			for (i = 0; i < c; ++i)
			{
				fgets(str1, 10001, bufer[0]);
				fputs(str1, output);
			}
		}
		else
		{
			for (i = 0, j = 0,
				fgets(str1, 10001, bufer[0]),
				fgets(str2, 10001, bufer[1]);
				i < n && j < k;)
			{
				choose = strcmp(str1, str2);
				if (choose < 0)
				{
					fputs(str1, output);
					++i;
					if (i < n) fgets(str1, 10001, bufer[0]);
				}
				else
				{
					fputs(str2, output);
					++j;
					if (j < k) fgets(str2, 10001, bufer[1]);
				}
			}
			if (i < n)
			{
				fputs(str1, output);
				for (++i; i < n; ++i)
				{
					fgets(str1, 10001, bufer[0]);
					fputs(str1, output);
				}
			}
			if (j < k)
			{
				fputs(str2, output);
				for (++j; j < k; ++j)
				{
					fgets(str2, 10001, bufer[1]);
					fputs(str2, output);
				}
			}
		}
		fclose(output);
		fclose(bufer[0]);
		fclose(bufer[1]);
		if ((count - 1) >> core == 1)
			break;
		output = fopen("bufer_2_241.txt", "r");
		bufer[0] = fopen("bufer_0_241.txt", "w");
		bufer[1] = fopen("bufer_1_241.txt", "w");
		k = ((count - 1) / (n <<= 1)) + 1;
		for (c = 0; c < k; ++c)
		{
			i = 0;
			while (i++ < n && fgets(str1, 10001, output))
			{
				fputs(str1, bufer[c & 1]);
			}
		}
		fclose(output);
		fclose(bufer[0]);
		fclose(bufer[1]);
		output = fopen("bufer_2_241.txt", "w");
		bufer[0] = fopen("bufer_0_241.txt", "r");
		bufer[1] = fopen("bufer_1_241.txt", "r");
	}
	input = fopen("bufer_2_241.txt", "r");
	output = fopen(name_output, "w");
	for (i = 1; i < count; ++i)
	{
		fgets(str1, 10001, input);
		fputs(str1, output);
	}
	fgets(str1, 10001, input);
	str1[strlen(str1) - 1] = '\0';
	fputs(str1, output);
	fclose(output);
	fclose(input);
	remove("bufer_0_241.txt");
	remove("bufer_1_241.txt");
	remove("bufer_2_241.txt");
}



int main()
{
    external_sorting("input.txt","output.txt");
	return 0;
}
