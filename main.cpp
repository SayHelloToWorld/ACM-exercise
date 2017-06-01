#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stack>
#include<vector>
#include<cmath>
#include<string>
#include<queue>
#include<cstring>
#include<sstream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<time.h>
using namespace std;

const int maxn = 10000;
const int len = 32;
char s[maxn];
int buf[len][len];
int cnt;
int p;

void draw(char* s, int r, int c, int w) {
	char ch = s[p++];
	if (ch == 'p') {
		draw(s, r,c+w/2,w/2);
		draw(s,  r,c,w/2);
		draw(s, r+w/2,c,w/2);
		draw(s, r+w/2,c+w/2,w/2);
	}
	else if (ch == 'f') {
		for (int i = r; i < r + w; i++) {
			for (int j = c; j < c + w; j++) {
				if (buf[i][j] == 0) {
					buf[i][j] = 1;
					cnt++;
				}
			}
		}
	}
}


int main()
{
	double begin = clock();
	freopen("run.in", "r" , stdin);
	freopen("run.out", "w", stdout);

	int T;
	scanf("%d", &T);
	
	while (T--) {
		memset(buf, 0, sizeof(buf));
		cnt = 0;
		for (int i = 0; i < 2; i++) {
			scanf("%s", s);
			p = 0;
			draw(s, 0, 0, len);
		}
		printf("There are %d black pixels.\n", cnt);

	}

	printf("Time used : %.3f\n\n", clock()-begin / CLOCKS_PER_SEC);
	//system("pause");
	return 0;
}