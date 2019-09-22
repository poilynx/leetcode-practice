/*
 * Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*'.
 * 
 * '?' Matches any single character.
 * '*' Matches any sequence of characters (including the empty sequence).
 * The matching should cover the entire input string (not partial).
 * 
 * https://leetcode-cn.com/problems/wildcard-matching
 */
#include "pub.h"

char *sp = NULL;
int width = 0;
bool isMatch1(char * s, char * p, int i, int j){
	int ret = false;
	if(p[j] == 0) return (s[i] == 0);
	if(sp[i*width+j]>=0)
		return sp[i*width+j];
	if(s[i] && (p[j] == s[i] || p[j] == '?')) {
		ret = isMatch1(s, p, i+1, j+1);
	}
	if(p[j] == '*')
		ret = (s[i] && isMatch1(s, p, i+1, j)) || isMatch1(s, p, i, j+1);
	sp[i*width+j] = ret;
	return ret;
}

bool isMatch(char * s, char * p){
	int ns = strlen(s)+1, np = strlen(p)+1, ret;
	sp = malloc(ns*np);
	width = np;
	memset(sp, -1, ns*np);
	ret = isMatch1(s, p, 0, 0);
	free(sp);
	return ret;
}

int main() {
	char a[] = "aaaabaaaabbbbaabbbaabbaababbabbaaaababaaabbbbbbaabbbabababbaaabaabaaaaaabbaabbbbaababbababaabbbaababbbba";
	char b[] = "*****b*aba***babaa*bbaba***a*aaba*b*aa**a*b**ba***a*a*";
	printf("%d\n", isMatch(a, b));
	return 0;
}
