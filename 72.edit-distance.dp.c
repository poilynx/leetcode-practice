/*
* Given two words word1 and word2, find the minimum number of operations required to convert word1 to word2.
* 
* You have the following 3 operations permitted on a word:
* 
* Insert a character
* Delete a character
* Replace a character
* 
* https://leetcode-cn.com/problems/edit-distance
*/
#include "pub.h"
#define MIN(a, b) ((a)<(b) ? (a) : (b))
int minDistance(char * word1, char * word2){
	size_t nw1 = strlen(word1)+1, nw2 = strlen(word2)+1;
	int *data = malloc(nw1 * nw2 * sizeof(int)), i, j;
	/* Initialize 2D array dp */
	int **dp = malloc(sizeof(int*) * nw2);
	for(j=0; j<nw2; j++) dp[j] = data + (nw1 * j);
	for(i=0; i<nw1; i++) dp[0][i] = i;
	for(j=0; j<nw2; j++) dp[j][0] = j;

	for(j=1; j<nw2; j++)
		for(i=1; i<nw1; i++)
			dp[j][i] = MIN(MIN(dp[j-1][i], dp[j][i-1])+1, dp[j-1][i-1]+(word1[i-1]!=word2[j-1]));
	free(dp);
	free(data);
	return dp[nw2-1][nw1-1];
}
int main() {
#if 1
	char s1[] =
	"abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwx"
	"yzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuv"
	"wxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrst"
	"uvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqr"
	"stuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnop"
	"qrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmn"
	"opqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijkl"
	"mnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghij"
	"klmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefgh"
	"ijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdef";

	char s2[] =
	 "bcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwx"
	"yzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuv"
	"wxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrst"
	"uvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqr"
	"stuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnop"
	"qrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmn"
	"opqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijkl"
	"mnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghij"
	"klmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefgh"
	"ijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdef"
	"g";
#else
	char s1[] = "horse";
	char s2[] = "ros";
#endif
	printf("%d\n", minDistance(s1, s2));
	return 0;
}
