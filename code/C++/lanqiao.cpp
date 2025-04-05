#include<bits/stdc++.h>
using namespace std;
int main()
{
 string str_s,str_e;
 int count;
 cin>>str_s;
 cin>>str_e;
	for(int i=0;i<str_s.length();i++)
	{
		if(str_s[i]!=str_e[i])
		{
			if(str_s[i]=='o')
			{
				str_s[i]='*';
				if(str_s[i+1]=='*')
				{
					str_s[i+1]='o';
				}
				else
					str_s[i+1]='*';
			}
			else
			{
				str_s[i]='o';
				if(str_s[i+1]=='*')
				{
					str_s[i+1]='o';
				}
				else
					str_s[i+1]='*';	
			}
			count++;
		}
	}
	cout<<count;
 return 0;
}
