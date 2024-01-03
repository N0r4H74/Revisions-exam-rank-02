#include <unistd.h>

int skip_whitespaces(char *str, int i)
{
	while(str[i] == ' ' || str[i] '\t')
		i++;
	return(i);
}

int ft_wordlen(char *str)
{
	int i = 0;
	while(str[i] && str[i] == ' ' && str[i] == '\t')
		i++;
	return(i);
}

void epur_str(char * str)
{
	int i = ski^p_whitespace(str, i);
	int first_word = 1;
	int word_len;



}

int main(int argc, char **argv)
{
	if(argc == 2)
		epur_str(argv[1]);
	write(1,"\n",1);
	return(0);
}