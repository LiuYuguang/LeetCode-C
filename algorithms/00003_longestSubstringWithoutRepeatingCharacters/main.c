#include <stdio.h>
#include <string.h>

int lengthOfLongestSubstring(char * s){
	int head,tail;
	int index[128] = {0};
	int len,max_len=0;
	memset(index,0xff,sizeof(index));
	for(head=0,tail=0;s[head] != '\0';head++){
		if(index[s[head]] > tail){
			len = head - tail;
			if(len > max_len)
				max_len = len;
			tail = index[s[head]];
		}
		index[s[head]] = head+1;
	}
	len = head - tail;
	if(len > max_len)
		max_len = len;
	return max_len;
}

int main(int argc, char **argv){
	{
		char s[] = "abcabcbb";
		printf("%d\n",lengthOfLongestSubstring(s));
	}

	{
		char s[] = "bbbbb";
		printf("%d\n",lengthOfLongestSubstring(s));
	}

	{
		char s[] = "pwwkew";
		printf("%d\n",lengthOfLongestSubstring(s));
	}

	{
		char s[] = "";
		printf("%d\n",lengthOfLongestSubstring(s));
	}
}
