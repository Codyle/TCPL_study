#include <stdio.h>

#define MAXLEN	255

int expand( char[], char[] );

main()
{
	char c, src[MAXLEN], exp[MAXLEN];
	int i;
	c = 0;

	for( i=0; i<MAXLEN; i++ )
		src[i]=exp[i]=' ';

	printf("Enter a string to expand : ");
	i=0;
	while( c=getchar() )
	{
		if( c!=EOF && c!='\n' )
			src[i] = c;
		else break;

		i++;
	}
	src[i] = '\0';

	if( !expand(src, exp) )
		printf("Source string is : %s\nExpanded string is : %s\n", src, exp);
	else
		return -1;

	return 0;
}

int expand( char s1[], char s2[] )
{
	int i, j, k, start, end;
	int IN=0;

	j=0;

	for( i=0; i<MAXLEN && s1[i]!='\0'; i++ )
	{
		if( !IN )
		{
			s2[j] = s1[i];
			IN = 1;
			start = s1[i];
			j++;
		}
		else
		{
			if( s1[i] == '-' )
			{
				IN = 2;
				s2[j] = s1[i];
			}
			else
			{
				if( IN == 1 )
				{
					s2[j] = s1[i];
					start = s1[i];
					j++;
				}
				else if ( IN == 2 )
				{
					end = s1[i];
					if ( end > start )
					{
						for( k=0; k < (end-start); k++ )
						{
							s2[j] = start+k+1;
							j++;
						}
					} 
					else
					{
						for( k=0; k < (start-end); k++ )
						{
							s2[j] = start-k-1;
							j++;
						}
					}
					start = s1[i];
					IN = 1;
				}
			}
		}
	}
	s2[++j] = '\0';
	return 0;
}		
