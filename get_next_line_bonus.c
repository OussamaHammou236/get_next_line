/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohammou- <ohammou-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 22:15:53 by ohammou-          #+#    #+#             */
/*   Updated: 2023/12/18 17:36:36 by ohammou-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*before_new_line(char *bfr)
{
	int		i;
	char	*str;

	i = 0;
	if (!bfr)
		return ("");
	while (bfr[i++] != '\n' && bfr[i])
		;
	str = malloc(i + 1);
	ft_strlcpy(str, bfr, i + 1);
	free(bfr);
	return (str);
}

char	*after_new_line(char *bfr)
{
	int		i;
	char	*str;

	i = 0;
	if (!bfr)
		return ("");
	while (*bfr != '\n' && *bfr != '\0')
		bfr++;
	if (*bfr == '\n')
	{
		str = malloc(ft_strlen(bfr + 1) + 1);
		ft_strlcpy(str, bfr + 1, ft_strlen(bfr) + 1);
		return (str);
	}
	return (NULL);
}

void	ft_bzero(char *s, size_t n)
{
	while (n--)
		s[n] = '\0';
}

char	*get_rest(char *bfrcopy, int fd, char *bfr, ssize_t len)
{
	static char	*remaining[OPEN_MAX];

	while (!ft_strchr(bfrcopy, '\n'))
	{
		len = read(fd, bfr, BUFFER_SIZE);
		if (len < 0)
		{
			free(remaining[fd]);
			remaining[fd] = NULL;
			return (free(bfr), NULL);
		}
		bfr[len] = '\0';
		bfrcopy = ft_strjoin(bfrcopy, remaining[fd] ,bfr);
		ft_bzero(bfr, BUFFER_SIZE);
		free(remaining[fd]);
		remaining[fd] = NULL;
		if (len == 0)
			break ;
	}
	remaining[fd] = after_new_line(bfrcopy);
	if (len == 0 && bfrcopy[0] == '\0')
		return (free(bfrcopy), free(bfr), NULL);
	bfrcopy = before_new_line(bfrcopy);
	free(bfr);
	return (bfrcopy);
}

char	*get_next_line(int fd)
{
	char	*bfr;
	char	*bfrcopy;
	ssize_t	len;

	bfrcopy = "";
	len = 0;
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	bfr = malloc(BUFFER_SIZE + 1);
	if (!bfr)
		return (NULL);
	bfrcopy = get_rest(bfrcopy, fd, bfr, len);
	return (bfrcopy);
}
 int main(void)
 {
	char *str;
    int fd1 = open("test1",  O_RDONLY);
	int fd2 = open("test2",O_RDONLY);
	while(1)
	{
        str = get_next_line(fd1);
		if (str)
        	printf("%s",str);
		str = get_next_line(fd2);
		if (str)
			printf("%s",str);
		else 
			break ;
        free(str);	
	}
	//get_next_line(fd);
	//get_next_line(f);
	//get_next_line(f);
	//  printf("%s",get_next_line(fd));
	//  printf("%s",get_next_line(f));
	//  printf("%s",get_next_line(fd));
	   close(fd1);
	   close(fd2);
	return 0;
}