
int strcmp(char * str1, char * str2) {
	
	int i = 0, j = 0, flag = 0;
	while(str1[i] != 0 && str2[j] != 0 && !flag) {
		flag += str1[i++] - str2[j++]; /* If the k-th character are different, flag is set */
	}
	return !flag && str1[i] == 0 && str2[j] == 0;

}
