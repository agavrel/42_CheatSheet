/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   	                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agavrel <angavrel@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/04 23:42:00 by agavrel           #+#    #+#             */
/*   Updated: 2020/44/44 44:44:44 by agavrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// NB : Not my solution, took a random one that looked salvageable
int ft_necklace(char *s1, char *s2)
{
	if (strlen(s1) != strlen(s2))
		return 0;
		
	char *match = strchr(s2, s1[0]);
	char *c;
	while (c = match)
	{
			for (int i = 0; i < strlen(s1); i++)
			{
					if (*c != s1[i])
					{								
						if (!(match = strchr(match + 1, s1[0])))
							return 0;
					}
					else if (*(++c) == '\0')
						c = s2;
			}
			return 1;
	}
	return 0;
}

// Good Main to Test every case.
# define N 11
int main(int argc, char const *argv[])//
{
	char	*res[2] = {"\e[1;31mKO\e[0m", "\e[1;92mOK\e[0m"};

	bool	expected[N] = {1,1,0,1,0,0,0,1,0,0,1};	
	char	s[N][2][50] = {{"nicole", "icolen"}, {"nicole", "lenico"}, {"nicole", "coneli"}, \
	 {"aabaaaaabaab", "aabaabaabaaa"}, {"abc", "cba"}, {"xxyyy", "xxxyy"}, \
	 {"xyxxz", "xxyxz"}, {"x", "x"}, {"x", "xx"}, {"x", ""}, {"", ""}};
		

	for (int i = 0; i < N; i++) {
		bool n = ft_necklace(s[i][0], s[i][1]) == expected[i];
			printf("\t%s\t%s\n\t\t%s\n\n",res[n],s[i][0],s[i][1]);//
	}

	return 0;
}
