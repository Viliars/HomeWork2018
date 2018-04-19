#include <iostream>
#include <string>

int main()
{
	std::string s1, s2;
	std::cin>>s1;
	std::cin>>s2;
	int buf1, buf2;
	int i = 0;
	int j = 0;
	while ((i < s1.length()) && (s2[i] != '*'))
	{
        if ((s2[i] != s1[i]) && (s2[i] != '?'))
            {
                std::cout<<"NO"; return 0;
            }
        ++i;
	}
	j = i;
	while (i < s1.length())
	{
		if (s2[j] == '*')
		{
			if (++j == s2.length())  { std::cout<<"YES"; return 0; }
			buf2 = j;
			buf1 = i + 1;
		}
		else
        if ((j < s2.length()) && ((s2[j] == s1[i]) || (s2[j] == '?')))
        {
            ++i;
            ++j;
        }
		else
		{
			j = buf2;
			i = buf1++;
		}
	}
	while (s2[j++] == '*'); if(--j == s2.length()) std::cout<<"YES"; else std::cout<<"NO";
	return 0;
}
