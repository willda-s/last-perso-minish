#include "includes/minishell.h"

static size_t	count_word_with_quotes(char const *s, char c)
{
    size_t	i = 0;
    size_t	count = 0;
    bool	inword = false;
    char	quote = '\0';

    while (s[i])
    {
        if ((s[i] == '\'' || s[i] == '"'))
        {
            if (quote == '\0')
            {
                quote = s[i];
                if (!inword)
                {
                    inword = true;
                    count++;
                }
            }
            else if (quote == s[i])
            {
                quote = '\0';
            }
        }
        else if (s[i] == c && quote == '\0')
        {
            inword = false;
        }
        else if (!inword)
        {
            inword = true;
            count++;
        }
        i++;
    }
    return (count);
}

static int	ft_strlenword_with_quotes(const char *str, char c)
{
    int		i;
    char	quote;

    i = 0;
    quote = '\0';
    while (str[i])
    {
        if ((str[i] == '\'' || str[i] == '"') && (quote == '\0' || quote == str[i]))
        {
            if (quote == '\0')
                quote = str[i];
            else
                quote = '\0';
        }
        else if (str[i] == c && quote == '\0')
            break;
        i++;
    }
    return (i);
}

char	**ft_split_with_quotes(char const *s, char c)
{
    size_t	i;
    size_t	j;
    size_t	length;
    char	**dst;

    if (!s)
        return (NULL);
    i = 0;
    j = 0;
    dst = ft_calloc(count_word_with_quotes(s, c) + 1, sizeof(char *));
    if (!dst)
        return (NULL);
    while (s[j])
    {
        while (s[j] == c && s[j])
            j++;
        if (s[j] != c && s[j])
        {
            length = ft_strlenword_with_quotes(&s[j], c);
            dst[i] = ft_strndup(&s[j], length);
            if (!dst[i])
                return (ft_free(dst, i));
            i++;
            j += length;
        }
    }
    return (dst);
}

int main (void)
{
	int i = 0;
	char *s = "salut ca va 'd' bien' \"et toi\"";
	char **result = ft_split_with_quotes(s, ' ');
	while (result[i])
		printf("%s\n", result[i++]);
	return (0);
}