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

short* sp = NULL;
size_t size = 0;
size_t width;

int minDistance1(char * s1, char * s2, int i, int j){
	int m1, m2, m3, n=0;
	if(sp[i*width + j] >=0) return sp[i*width + j];
	if(s1[i] == 0) return (sp[i*width + j] = strlen(s2+j));
	if(s2[j] == 0) return sp[i*width + j] = strlen(s1+i);
	if(s1[i] != s2[j]) n = 1;
	m3 = minDistance1(s1, s2, i+1, j+1) + n;
	m1 = minDistance1(s1, s2, i+1, j) + 1;
	m2 = minDistance1(s1, s2, i, j+1) + 1;
	return (sp[i*width + j] = m1 < m2 ? (m1 < m3 ? m1 : m3) : (m2 < m3 ? m2 : m3));
}
int minDistance(char * word1, char * word2){
	size_t nw1 = strlen(word1), nw2 = strlen(word2);
	size_t spsiz = (nw1+1)*(nw2+1) * sizeof(short);
	if(spsiz > size) {
		if(sp) free(sp);
		sp = malloc(spsiz);
	}
	memset(sp, -1, spsiz);
	size = spsiz;
	width = nw2+1;
	int min = minDistance1(word1, word2, 0, 0);
	return min;

}
int main() {
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

	printf("%d\n", minDistance(s1, s2));
	return 0;
}
