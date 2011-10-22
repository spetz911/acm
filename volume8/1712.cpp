#include <cstdio>

using namespace std;


char s[7];
bool Grid[4][4];
char Text[4][4];

void Rotate(bool Grid[4][4])
{
	bool NewGrid[4][4];

	for (int i=0; i<4; ++i)
		for (int j=0; j<4; ++j)
			NewGrid[i][j] = Grid[3-j][i];

	for (int i=0; i<4; ++i)
		for (int j=0; j<4; ++j)
			Grid[i][j] = NewGrid[i][j];
}

void Print(bool Grid[4][4])
{
	for (int i=0; i<4; ++i)
		for (int j=0; j<4; ++j)
			if (Grid[i][j]) printf("%c", Text[i][j]);
}


int main()
{
	for (int i=0; i<4; ++i) {
		scanf("%s", s);
		for (int j=0; j<4; ++j)
			Grid[i][j] = (s[j] == 'X');
	}

	for (int i=0; i<4; ++i) {
		scanf("%s", s);
		for (int j=0; j<4; ++j)
			Text[i][j] = s[j];
	}
	
	Print(Grid);
	Rotate(Grid);
	Print(Grid);
	Rotate(Grid);
	Print(Grid);
	Rotate(Grid);
	Print(Grid);
	
	printf("\n");
	return 0;
}
