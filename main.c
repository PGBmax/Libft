/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 17:48:09 by pboucher          #+#    #+#             */
/*   Updated: 2026/05/13 18:05:12 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static void	test_char_checks(void)
{
	printf("=== ft_isalpha ===\n");
	printf("ft_isalpha('a') = %d (expected non-zero)\n", ft_isalpha('a'));
	printf("ft_isalpha('Z') = %d (expected non-zero)\n", ft_isalpha('Z'));
	printf("ft_isalpha('1') = %d (expected 0)\n", ft_isalpha('1'));

	printf("=== ft_isdigit ===\n");
	printf("ft_isdigit('5') = %d (expected non-zero)\n", ft_isdigit('5'));
	printf("ft_isdigit('a') = %d (expected 0)\n", ft_isdigit('a'));

	printf("=== ft_isalnum ===\n");
	printf("ft_isalnum('b') = %d (expected non-zero)\n", ft_isalnum('b'));
	printf("ft_isalnum('3') = %d (expected non-zero)\n", ft_isalnum('3'));
	printf("ft_isalnum('!') = %d (expected 0)\n", ft_isalnum('!'));

	printf("=== ft_isascii ===\n");
	printf("ft_isascii(65)  = %d (expected non-zero)\n", ft_isascii(65));
	printf("ft_isascii(200) = %d (expected 0)\n", ft_isascii(200));

	printf("=== ft_isprint ===\n");
	printf("ft_isprint(' ') = %d (expected non-zero)\n", ft_isprint(' '));
	printf("ft_isprint(7)   = %d (expected 0)\n", ft_isprint(7));

	printf("=== ft_toupper / ft_tolower ===\n");
	printf("ft_toupper('a') = %c (expected A)\n", ft_toupper('a'));
	printf("ft_tolower('Z') = %c (expected z)\n", ft_tolower('Z'));
}

static void	test_strings(void)
{
	char	dst[32];

	printf("=== ft_strlen ===\n");
	printf("ft_strlen(\"hello\") = %zu (expected 5)\n", ft_strlen("hello"));

	printf("=== ft_strlcpy ===\n");
	ft_strlcpy(dst, "world", sizeof(dst));
	printf("ft_strlcpy -> \"%s\" (expected world)\n", dst);

	printf("=== ft_strlcat ===\n");
	ft_strlcat(dst, "!!!", sizeof(dst));
	printf("ft_strlcat -> \"%s\" (expected world!!!)\n", dst);

	printf("=== ft_strchr ===\n");
	printf("ft_strchr(\"libft\", 'b') -> \"%s\" (expected bft)\n",
		ft_strchr("libft", 'b'));
	printf("ft_strchr(\"libft\", 'z') -> %p (expected NULL)\n",
		(void *)ft_strchr("libft", 'z'));

	printf("=== ft_strrchr ===\n");
	printf("ft_strrchr(\"abcabc\", 'a') -> \"%s\" (expected abc)\n",
		ft_strrchr("abcabc", 'a'));

	printf("=== ft_strncmp ===\n");
	printf("ft_strncmp(\"abc\",\"abc\",3) = %d (expected 0)\n",
		ft_strncmp("abc", "abc", 3));
	printf("ft_strncmp(\"abc\",\"abd\",3) = %d (expected negative)\n",
		ft_strncmp("abc", "abd", 3));

	printf("=== ft_strnstr ===\n");
	printf("ft_strnstr(\"libft42\",\"ft\",7) -> \"%s\" (expected ft42)\n",
		ft_strnstr("libft42", "ft", 7));

	printf("=== ft_strdup ===\n");
	char *dup = ft_strdup("dup_test");
	printf("ft_strdup(\"dup_test\") -> \"%s\" (expected dup_test)\n", dup);
	free(dup);

	printf("=== ft_substr ===\n");
	char *sub = ft_substr("hello world", 6, 5);
	printf("ft_substr(\"hello world\",6,5) -> \"%s\" (expected world)\n", sub);
	free(sub);

	printf("=== ft_strjoin ===\n");
	char *joined = ft_strjoin("foo", "bar");
	printf("ft_strjoin(\"foo\",\"bar\") -> \"%s\" (expected foobar)\n", joined);
	free(joined);

	printf("=== ft_strtrim ===\n");
	char *trimmed = ft_strtrim("  42  ", " ");
	printf("ft_strtrim(\"  42  \",\" \") -> \"%s\" (expected 42)\n", trimmed);
	free(trimmed);

	printf("=== ft_split ===\n");
	char **sp = ft_split("one:two:three", ':');
	printf("ft_split(\"one:two:three\",':') -> [%s][%s][%s]\n",
		sp[0], sp[1], sp[2]);
	free(sp[0]);
	free(sp[1]);
	free(sp[2]);
	free(sp);

	printf("=== ft_strmapi ===\n");
	char *mapped = ft_strmapi("hello", (char (*)(unsigned int, char))ft_toupper);
	printf("ft_strmapi(\"hello\", toupper) -> \"%s\" (expected HELLO)\n", mapped);
	free(mapped);

	printf("=== ft_striteri ===\n");
	char str[] = "hello";
	ft_striteri(str, (void (*)(unsigned int, char *))ft_toupper);
	printf("ft_striteri(\"hello\", toupper) -> \"%s\" (expected HELLO)\n", str);
}

static void	test_numbers(void)
{
	printf("=== ft_atoi ===\n");
	printf("ft_atoi(\"42\")   = %d (expected 42)\n", ft_atoi("42"));
	printf("ft_atoi(\"-10\")  = %d (expected -10)\n", ft_atoi("-10"));
	printf("ft_atoi(\"  7\")  = %d (expected 7)\n", ft_atoi("  7"));

	printf("=== ft_itoa ===\n");
	char *s = ft_itoa(12345);
	printf("ft_itoa(12345)  = \"%s\" (expected 12345)\n", s);
	free(s);
	s = ft_itoa(-99);
	printf("ft_itoa(-99)    = \"%s\" (expected -99)\n", s);
	free(s);
}

static void	test_memory(void)
{
	char	buf[16];

	printf("=== ft_memset ===\n");
	ft_memset(buf, 'X', 5);
	buf[5] = '\0';
	printf("ft_memset -> \"%s\" (expected XXXXX)\n", buf);

	printf("=== ft_bzero ===\n");
	ft_bzero(buf, 5);
	printf("ft_bzero -> buf[0]=%d (expected 0)\n", buf[0]);

	printf("=== ft_memcpy ===\n");
	char src[] = "copy_me";
	char dst[16];
	ft_memcpy(dst, src, 8);
	printf("ft_memcpy -> \"%s\" (expected copy_me)\n", dst);

	printf("=== ft_memmove ===\n");
	char overlap[] = "abcdefgh";
	ft_memmove(overlap + 2, overlap, 5);
	printf("ft_memmove (overlap) -> \"%s\" (expected ababcde... overlap)\n",
		overlap);

	printf("=== ft_memchr ===\n");
	char *found = ft_memchr("search", 'r', 6);
	printf("ft_memchr(\"search\",'r') -> \"%s\" (expected rch)\n", found);

	printf("=== ft_memcmp ===\n");
	printf("ft_memcmp(\"abc\",\"abc\",3) = %d (expected 0)\n",
		ft_memcmp("abc", "abc", 3));

	printf("=== ft_calloc ===\n");
	int *arr = ft_calloc(5, sizeof(int));
	printf("ft_calloc(5,int) -> arr[2]=%d (expected 0)\n", arr[2]);
	free(arr);
}

static void	test_fd_output(void)
{
	printf("=== ft_putchar_fd ===\n");
	ft_putchar_fd('A', 1);
	ft_putchar_fd('\n', 1);

	printf("=== ft_putstr_fd ===\n");
	ft_putstr_fd("hello fd\n", 1);

	printf("=== ft_putendl_fd ===\n");
	ft_putendl_fd("with newline", 1);

	printf("=== ft_putnbr_fd ===\n");
	ft_putnbr_fd(-2147483648, 1);
	ft_putchar_fd('\n', 1);
}

static void	test_list(void)
{
	t_list	*head;
	t_list	*node;

	printf("=== linked list bonus ===\n");
	head = ft_lstnew("first");
	ft_lstadd_back(&head, ft_lstnew("second"));
	ft_lstadd_back(&head, ft_lstnew("third"));
	ft_lstadd_front(&head, ft_lstnew("zero"));

	printf("ft_lstsize -> %d (expected 4)\n", ft_lstsize(head));
	printf("ft_lstlast -> \"%s\" (expected third)\n",
		(char *)ft_lstlast(head)->content);

	node = head;
	while (node)
	{
		printf("  node: %s\n", (char *)node->content);
		node = node->next;
	}

	ft_lstclear(&head, (void (*)(void *))free);
	printf("ft_lstclear -> head=%p (expected NULL)\n", (void *)head);
}

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	printf("==============================\n");
	printf("        LIBFT TEST SUITE      \n");
	printf("==============================\n\n");

	printf("--- Character checks ---\n");
	test_char_checks();

	printf("\n--- String functions ---\n");
	test_strings();

	printf("\n--- Number functions ---\n");
	test_numbers();

	printf("\n--- Memory functions ---\n");
	test_memory();

	printf("\n--- FD output functions ---\n");
	test_fd_output();

	printf("\n--- Bonus: linked list ---\n");
	test_list();

	printf("\n==============================\n");
	printf("           ALL DONE           \n");
	printf("==============================\n");
	return (0);
}