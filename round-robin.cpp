#include <stdio.h>
#include <string.h>
int main() {
  int n, i; 
  char teams[1000][50];  // 二维数组 
  int score[1000]={0}, pure[1000]={0};
  int champin[1000];
  // 输入代码 
  scanf("%d", &n);
  for(i = 0; i < n; i+=1)
    scanf("%s", teams[i]);
  gets(teams[999]);
  for(i = 0; i < n*(n-1)/2; i+=1) { 
    char match[1000];
    char t1[50], t2[50];
    int s1, s2, j = 0;
    int t1_index, t2_index;
    //scanf("%s", match);
    gets(match);
    printf("%s\n", match);
    while(match[j] != 0) {
      if (match[j] == '-' || match[j] == ':')
        match[j] = ' ';
      j += 1;
	}
	// printf("%s\n", match);
    // 不断地累积积分和净得分 
    sscanf(match, "%s %s %d %d", t1, t2, &s1, &s2);
    printf("%s vs. %s == %d vs. %d \n", t1, t2, s1, s2);
    for(j = 0; j < n; j += 1) {
      if (strcmp(teams[j], t1) == 0)
        t1_index = j;
      if (strcmp(teams[j], t2) == 0)
        t2_index = j;
	}
	if (s1 > s2) {
	  score[t1_index] += 3;
	  score[t2_index] += 0;
	  pure[t1_index] += s1 - s2;
	  pure[t2_index] -= s1 - s2;
	}
	else if (s1 == s2) {
	  score[t1_index] += 1;
	  score[t2_index] += 1;
	  pure[t1_index] += 0;
	  pure[t2_index] += 0;
	}
	else {
	  score[t1_index] += 0;
	  score[t2_index] += 3;
	  pure[t2_index] += s2 - s1;
	  pure[t1_index] -= s2 - s1;
	}
  }
  for(i = 0; i < n; i += 1) {
  	//printf("%s, %d, %d\n", teams[i], score[i], pure[i]);
  	champin[i] = i;
  }
  for(i = 0; i < n-1; i+=1) {
  	for(int j = i+1; j < n; j+=1){
      if (score[champin[i]] < score[champin[j]]) {
        int temp = champin[i];
        champin[i] = champin[j];
        champin[j] = temp;
      }
      else if (score[champin[i]] == score[champin[j]]) {
        if (pure[champin[i]] < pure[champin[j]]) {
          int temp = champin[i];
          champin[i] = champin[j];
          champin[j] = temp;
	    }
	    else if (pure[champin[i]] == pure[champin[j]]) {
	      //???
	    }
      }
    }
  } 
  int seq = 0;
  for(i = 0; i < n; i += 1) {
  	//printf("%s, %d, %d\n", teams[i], score[i], pure[i]);
  	if (i == 0) {
  	  printf("%s, %d\n", teams[champin[i]], seq);//score[champin[i]], pure[champin[i]]);
  	  continue;
    }
  	if (score[champin[i]] == score[champin[i-1]] && pure[champin[i]] == pure[champin[i-1]])
  	  printf("%s, %d\n", teams[champin[i]], seq);//score[champin[i]], pure[champin[i]]);
  	else {
  	  seq += 1;
  	  printf("%s, %d\n", teams[champin[i]], seq);//score[champin[i]], pure[champin[i]]);
	}
  }
  return 0;
} 
