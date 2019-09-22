/*
 * Given a string containing just the characters '(' and ')',
 * find the length of the longest valid (well-formed) parentheses
 * substring.
 *
 * https://leetcode-cn.com/problems/longest-valid-parentheses
 */
#include "pub.h"

int longestValidParentheses(char * s){
	int len = strlen(s), i, n=0, max=0, sp=-1;
	int *st = malloc(len * sizeof(int)); 
	for(i=0; i<len; i++) {
		char c = s[i];
		s[i] = 0;
		if(c == '(') st[++sp] = i;
		else if(sp>=0) s[st[sp--]] = s[i] = 1;
	}
	for(i=0;i<len;i++) {
		n = s[i] ? n+1 : 0;
		max = (n > max) ? n : max;
	}
	free(st);
	return max;
}


int main() {
	char s[] = "((())((((()";
	printf("%d\n", longestValidParentheses(s));
	return 0;
}
