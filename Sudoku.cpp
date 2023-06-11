#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define so sort(a , a+n)
#define migmig ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define defl 0
#define N 9
typedef long long ll;
typedef long double ld;
const int maxn=2*1e5+50;
int row, col;

bool chekdefl(int stage [N][N],int& row, int& col)
{
	for (row = 0; row < N; row++)
		for (col = 0; col < N; col++)
			if (stage [row][col] == defl)
				return true;
	return false;
}
bool CheckRow(int stage [N][N], int row, int i)
{
	for (int col = 0; col < N; col++)
		if (stage [row][col] == i)
			return true;
	return false;
}

bool CheckCol(int stage [N][N], int col, int i)
{
	for (int row = 0; row < N; row++)
		if (stage [row][col] == i)
			return true;
	return false;
}

bool CheckEStage(int stage [N][N], int boxStartRow,int boxStartCol, int i)
{
	for (int row = 0; row < 3; row++)
		for (int col = 0; col < 3; col++)
			if (stage [row + boxStartRow][col + boxStartCol] ==i) return true;
	return false;
}

void print(int stage [N][N])
{
	for (int row = 0; row < N; row++)
		for (int col = 0; col < N; col++)
			cout << stage [row][col] << " ";
		cout << endl;
}

bool isSafe(int stage [N][N], int row,int col, int i)
{
	return !CheckRow(stage , row, i)
		&& !CheckCol(stage , col, i)
		&& !CheckEStage(stage , row - row % 3,col - col % 3, i)
		&& stage [row][col] == defl;
}

bool Sudoku(int stage [N][N])
{
	if (!chekdefl(stage , row, col))
		return true;

	for (int i = 1; i <= 9; i++)
	{
		if (isSafe(stage , row, col, i))
		{
			
			stage [row][col] = i;

			if (Sudoku(stage ))
				return true;

			stage [row][col] = defl;
		}
	}
	
	return false;
}


int main()
{
	int stage [N][N];cout<<"Input your :\n";
	for(int i = 0 ; i < N ; i++)
		for(int j = 0 ; j < N ; j++)
			cin>>stage[i][j];			
	if(Sudoku(stage)) print(stage);
	else cout<<"Invalid input!!!";

}