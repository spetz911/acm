#include<stdio.h>

inline bool is_letter(char c)
{
	return (c >= 'A' && c <= 'Z');
}

inline char lower(char c)
{
	return c + 'a' - 'A';
}

inline bool is_sep(char c)
{
	return (c=='.'||c=='!'||c=='?')?(true):false;
}


char inp[10002];

int main() {
	
	bool endln = true;
	
	
	while (fgets(inp, 10001, stdin)) {
		char *s = inp;
		
		while (*s) {
			if (endln && is_letter(*s))
				endln = false;
			else if (!endln && is_sep(*s))
				endln = true;
			else if (!endln && is_letter(*s))
				*s = lower(*s);
			s++;
		}
		
		fputs(inp, stdout);
	}
	return 0;
}
