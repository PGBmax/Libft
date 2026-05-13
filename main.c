/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 17:48:09 by pboucher          #+#    #+#             */
/*   Updated: 2026/05/13 18:23:53 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>

/* ── Colours ───────────────────────────────────────────────────────────────── */
#define RED     "\033[0;31m"
#define GREEN   "\033[0;32m"
#define YELLOW  "\033[0;33m"
#define BLUE    "\033[0;34m"
#define MAGENTA "\033[0;35m"
#define CYAN    "\033[0;36m"
#define BOLD    "\033[1m"
#define RESET   "\033[0m"

/* ── Global counters ───────────────────────────────────────────────────────── */
static int	g_ok = 0;
static int	g_ko = 0;

/* ── Helpers ───────────────────────────────────────────────────────────────── */
static void	section(const char *name)
{
	printf("\n" BOLD CYAN "══════════════════════════════\n");
	printf("  %s\n", name);
	printf("══════════════════════════════" RESET "\n");
}

static void	subsection(const char *name)
{
	printf(YELLOW "  ── %s\n" RESET, name);
}

static void	check(int cond, const char *label)
{
	if (cond)
	{
		printf(GREEN "  [OK]" RESET "  %s\n", label);
		g_ok++;
	}
	else
	{
		printf(RED "  [KO]" RESET "  %s\n", label);
		g_ko++;
	}
}

/*
** run_forked: run fn in a child process.
** If it segfaults/crashes, print a warning. Parent never crashes.
** Returns 1 if child exited normally, 0 if it was killed by a signal.
*/
static int	run_forked(void (*fn)(void), const char *label)
{
	pid_t	pid;
	int		status;

	fflush(stdout);
	pid = fork();
	if (pid == 0)
	{
		fn();
		fflush(stdout);
		_exit(0);
	}
	waitpid(pid, &status, 0);
	if (WIFSIGNALED(status))
	{
		printf(RED "  [CRASH]" RESET MAGENTA "  %s" RESET
			" → signal %d\n", label, WTERMSIG(status));
		return (0);
	}
	return (1);
}

/* ── Character checks & conversions ───────────────────────────────────────── */
static void	test_char_checks(void)
{
	section("CHARACTER CHECKS & CONVERSIONS");

	subsection("ft_isalpha");
	check(ft_isalpha('a') != 0,    "ft_isalpha('a')  → non-zero");
	check(ft_isalpha('Z') != 0,    "ft_isalpha('Z')  → non-zero");
	check(ft_isalpha('1') == 0,    "ft_isalpha('1')  → 0");
	check(ft_isalpha(' ') == 0,    "ft_isalpha(' ')  → 0");
	check(ft_isalpha('\0') == 0,   "ft_isalpha('\\0') → 0");

	subsection("ft_isdigit");
	check(ft_isdigit('0') != 0,    "ft_isdigit('0')  → non-zero");
	check(ft_isdigit('9') != 0,    "ft_isdigit('9')  → non-zero");
	check(ft_isdigit('a') == 0,    "ft_isdigit('a')  → 0");
	check(ft_isdigit('/') == 0,    "ft_isdigit('/')  → 0 (just before '0')");
	check(ft_isdigit(':') == 0,    "ft_isdigit(':')  → 0 (just after '9')");

	subsection("ft_isalnum");
	check(ft_isalnum('b') != 0,    "ft_isalnum('b')  → non-zero");
	check(ft_isalnum('3') != 0,    "ft_isalnum('3')  → non-zero");
	check(ft_isalnum('!') == 0,    "ft_isalnum('!')  → 0");
	check(ft_isalnum(0) == 0,      "ft_isalnum(0)    → 0");

	subsection("ft_isascii");
	check(ft_isascii(0) != 0,      "ft_isascii(0)    → non-zero");
	check(ft_isascii(127) != 0,    "ft_isascii(127)  → non-zero");
	check(ft_isascii(128) == 0,    "ft_isascii(128)  → 0");
	check(ft_isascii(-1) == 0,     "ft_isascii(-1)   → 0");

	subsection("ft_isprint");
	check(ft_isprint(' ') != 0,    "ft_isprint(' ')  → non-zero");
	check(ft_isprint('~') != 0,    "ft_isprint('~')  → non-zero");
	check(ft_isprint(7) == 0,      "ft_isprint(7)    → 0 (BEL)");
	check(ft_isprint(127) == 0,    "ft_isprint(127)  → 0 (DEL)");
	check(ft_isprint(31) == 0,     "ft_isprint(31)   → 0 (US)");

	subsection("ft_toupper / ft_tolower");
	check(ft_toupper('a') == 'A',  "ft_toupper('a')  → 'A'");
	check(ft_toupper('z') == 'Z',  "ft_toupper('z')  → 'Z'");
	check(ft_toupper('A') == 'A',  "ft_toupper('A')  → 'A' (no-op)");
	check(ft_toupper('1') == '1',  "ft_toupper('1')  → '1' (no-op)");
	check(ft_tolower('Z') == 'z',  "ft_tolower('Z')  → 'z'");
	check(ft_tolower('A') == 'a',  "ft_tolower('A')  → 'a'");
	check(ft_tolower('a') == 'a',  "ft_tolower('a')  → 'a' (no-op)");
	check(ft_tolower('0') == '0',  "ft_tolower('0')  → '0' (no-op)");
}

/* ── String functions ──────────────────────────────────────────────────────── */
static void	test_strlen(void)
{
	subsection("ft_strlen");
	check(ft_strlen("") == 0,             "ft_strlen(\"\")              → 0");
	check(ft_strlen("hello") == 5,        "ft_strlen(\"hello\")         → 5");
	check(ft_strlen("a") == 1,            "ft_strlen(\"a\")             → 1");
	check(ft_strlen("hello\0world") == 5, "ft_strlen stops at '\\0'");
}

static void	test_strlcpy(void)
{
	char	dst[16];
	size_t	ret;

	subsection("ft_strlcpy");
	ret = ft_strlcpy(dst, "hello", sizeof(dst));
	check(ret == 5 && strcmp(dst, "hello") == 0,
		"ft_strlcpy normal copy");
	ret = ft_strlcpy(dst, "toolongstring", 5);
	check(ret == 13 && strcmp(dst, "tool") == 0,
		"ft_strlcpy truncates, returns src len (13)");
	ret = ft_strlcpy(dst, "", sizeof(dst));
	check(ret == 0 && dst[0] == '\0',
		"ft_strlcpy empty src");
}

static void	test_strlcat(void)
{
	char	dst[16];
	size_t	ret;

	subsection("ft_strlcat");
	ft_strlcpy(dst, "hello", sizeof(dst));
	ret = ft_strlcat(dst, " world", sizeof(dst));
	check(ret == 11 && strcmp(dst, "hello world") == 0,
		"ft_strlcat normal concat");
	ft_strlcpy(dst, "abc", sizeof(dst));
	ret = ft_strlcat(dst, "defgh", 6);
	check(ret == 8 && strcmp(dst, "abcde") == 0,
		"ft_strlcat truncates to size-1, returns src+dst len");
	ft_strlcpy(dst, "", sizeof(dst));
	ret = ft_strlcat(dst, "hello", sizeof(dst));
	check(ret == 5 && strcmp(dst, "hello") == 0,
		"ft_strlcat empty dst");
}

static void	test_strchr(void)
{
	subsection("ft_strchr");
	check(strcmp(ft_strchr("libft", 'b'), "bft") == 0,
		"ft_strchr returns ptr to first 'b'");
	check(ft_strchr("libft", 'z') == NULL,
		"ft_strchr returns NULL if not found");
	check(ft_strchr("abc\0def", '\0') != NULL,
		"ft_strchr finds '\\0' terminator");
	check(strcmp(ft_strchr("abcabc", 'a'), "abcabc") == 0,
		"ft_strchr returns FIRST occurrence");
}

static void	test_strrchr(void)
{
	subsection("ft_strrchr");
	check(strcmp(ft_strrchr("abcabc", 'a'), "abc") == 0,
		"ft_strrchr returns LAST occurrence");
	check(ft_strrchr("hello", 'z') == NULL,
		"ft_strrchr NULL if not found");
	check(ft_strrchr("hello", '\0') != NULL,
		"ft_strrchr finds '\\0' terminator");
}

static void	test_strncmp(void)
{
	subsection("ft_strncmp");
	check(ft_strncmp("abc", "abc", 3) == 0,
		"ft_strncmp equal strings → 0");
	check(ft_strncmp("abc", "abd", 3) < 0,
		"ft_strncmp 'c' < 'd' → negative");
	check(ft_strncmp("abd", "abc", 3) > 0,
		"ft_strncmp 'd' > 'c' → positive");
	check(ft_strncmp("abc", "abcdef", 3) == 0,
		"ft_strncmp stops at n");
	check(ft_strncmp("abc", "abc", 0) == 0,
		"ft_strncmp n=0 → 0");
	check(ft_strncmp("", "", 1) == 0,
		"ft_strncmp empty strings → 0");
	check(ft_strncmp("a", "", 1) > 0,
		"ft_strncmp longer vs empty → positive");
}

static void	test_strnstr(void)
{
	subsection("ft_strnstr");
	check(strcmp(ft_strnstr("libft42", "ft", 7), "ft42") == 0,
		"ft_strnstr finds \"ft\" in \"libft42\"");
	check(ft_strnstr("libft42", "ft", 3) == NULL,
		"ft_strnstr needle starts after range → NULL");
	check(ft_strnstr("hello", "", 5) != NULL,
		"ft_strnstr empty needle → returns big");
	check(ft_strnstr("hello", "hello", 5) != NULL,
		"ft_strnstr full-length match");
	check(ft_strnstr("hello", "world", 5) == NULL,
		"ft_strnstr not found → NULL");
	check(ft_strnstr("", "a", 0) == NULL,
		"ft_strnstr empty haystack, len=0 → NULL");
	check(ft_strnstr("abc", "abcd", 3) == NULL,
		"ft_strnstr needle longer than haystack → NULL");
}

static void	test_strdup(void)
{
	char	*d;

	subsection("ft_strdup");
	d = ft_strdup("hello");
	check(d && strcmp(d, "hello") == 0, "ft_strdup normal string");
	free(d);
	d = ft_strdup("");
	check(d && d[0] == '\0',            "ft_strdup empty string");
	free(d);
}

static void	test_substr(void)
{
	char	*s;

	subsection("ft_substr");
	s = ft_substr("hello world", 6, 5);
	check(s && strcmp(s, "world") == 0,  "ft_substr normal");
	free(s);
	s = ft_substr("hello", 10, 5);
	check(s && s[0] == '\0',             "ft_substr start > len → empty");
	free(s);
	s = ft_substr("hello", 0, 0);
	check(s && s[0] == '\0',             "ft_substr len=0 → empty");
	free(s);
	s = ft_substr("hi", 0, 100);
	check(s && strcmp(s, "hi") == 0,     "ft_substr len > strlen clips");
	free(s);
	s = ft_substr("abcdef", 2, 3);
	check(s && strcmp(s, "cde") == 0,    "ft_substr middle slice");
	free(s);
}

static void	test_strjoin(void)
{
	char	*j;

	subsection("ft_strjoin");
	j = ft_strjoin("foo", "bar");
	check(j && strcmp(j, "foobar") == 0, "ft_strjoin normal");
	free(j);
	j = ft_strjoin("", "bar");
	check(j && strcmp(j, "bar") == 0,    "ft_strjoin empty s1");
	free(j);
	j = ft_strjoin("foo", "");
	check(j && strcmp(j, "foo") == 0,    "ft_strjoin empty s2");
	free(j);
	j = ft_strjoin("", "");
	check(j && j[0] == '\0',             "ft_strjoin both empty");
	free(j);
}

static void	test_strtrim(void)
{
	char	*t;

	subsection("ft_strtrim");
	t = ft_strtrim("  42  ", " ");
	check(t && strcmp(t, "42") == 0,        "ft_strtrim leading/trailing spaces");
	free(t);
	t = ft_strtrim("xxhelloxx", "x");
	check(t && strcmp(t, "hello") == 0,     "ft_strtrim 'x' set");
	free(t);
	t = ft_strtrim("hello", "xyz");
	check(t && strcmp(t, "hello") == 0,     "ft_strtrim set not in string");
	free(t);
	t = ft_strtrim("aaaa", "a");
	check(t && t[0] == '\0',                "ft_strtrim all trimmed → empty");
	free(t);
	t = ft_strtrim("", " ");
	check(t && t[0] == '\0',                "ft_strtrim empty string");
	free(t);
	t = ft_strtrim("abc", "");
	check(t && strcmp(t, "abc") == 0,       "ft_strtrim empty set");
	free(t);
}

static void	free_split(char **sp)
{
	int	i;

	i = 0;
	while (sp[i])
		free(sp[i++]);
	free(sp);
}

static void	test_split(void)
{
	char	**sp;

	subsection("ft_split");
	sp = ft_split("one:two:three", ':');
	check(sp && strcmp(sp[0], "one") == 0
		&& strcmp(sp[1], "two") == 0
		&& strcmp(sp[2], "three") == 0
		&& sp[3] == NULL,
		"ft_split normal 3 words");
	free_split(sp);

	sp = ft_split("::hello::", ':');
	check(sp && strcmp(sp[0], "hello") == 0 && sp[1] == NULL,
		"ft_split leading/trailing delimiters");
	free_split(sp);

	sp = ft_split("", ':');
	check(sp && sp[0] == NULL,
		"ft_split empty string → empty array");
	free(sp);

	sp = ft_split("nospace", ':');
	check(sp && strcmp(sp[0], "nospace") == 0 && sp[1] == NULL,
		"ft_split no delimiter found");
	free_split(sp);

	sp = ft_split("a::b::c", ':');
	check(sp && strcmp(sp[0], "a") == 0
		&& strcmp(sp[1], "b") == 0
		&& strcmp(sp[2], "c") == 0
		&& sp[3] == NULL,
		"ft_split consecutive delimiters skipped");
	free_split(sp);
}

static char	upper_fn(unsigned int i, char c)
{
	(void)i;
	return ((char)ft_toupper(c));
}

static void	upper_iter(unsigned int i, char *c)
{
	(void)i;
	*c = (char)ft_toupper(*c);
}

static void	test_strmapi(void)
{
	char	*m;

	subsection("ft_strmapi");
	m = ft_strmapi("hello", upper_fn);
	check(m && strcmp(m, "HELLO") == 0, "ft_strmapi to uppercase");
	free(m);
	m = ft_strmapi("", upper_fn);
	check(m && m[0] == '\0',            "ft_strmapi empty string");
	free(m);
	m = ft_strmapi("42abc", upper_fn);
	check(m && strcmp(m, "42ABC") == 0, "ft_strmapi digits unchanged");
	free(m);
}

static void	test_striteri(void)
{
	char	s1[] = "hello";
	char	s2[] = "";
	char	s3[] = "libft42";

	subsection("ft_striteri");
	ft_striteri(s1, upper_iter);
	check(strcmp(s1, "HELLO") == 0,  "ft_striteri to uppercase");
	ft_striteri(s2, upper_iter);
	check(s2[0] == '\0',             "ft_striteri empty string");
	ft_striteri(s3, upper_iter);
	check(strcmp(s3, "LIBFT42") == 0, "ft_striteri mixed string");
}

static void	test_strings(void)
{
	section("STRING FUNCTIONS");
	test_strlen();
	test_strlcpy();
	test_strlcat();
	test_strchr();
	test_strrchr();
	test_strncmp();
	test_strnstr();
	test_strdup();
	test_substr();
	test_strjoin();
	test_strtrim();
	test_split();
	test_strmapi();
	test_striteri();
}

/* ── Number functions ──────────────────────────────────────────────────────── */
static void	test_numbers(void)
{
	char	*s;

	section("NUMBER CONVERSIONS");

	subsection("ft_atoi");
	check(ft_atoi("42") == 42,                "ft_atoi \"42\"        → 42");
	check(ft_atoi("-10") == -10,              "ft_atoi \"-10\"       → -10");
	check(ft_atoi("  7") == 7,               "ft_atoi leading spaces");
	check(ft_atoi("+5") == 5,                "ft_atoi \"+5\"        → 5");
	check(ft_atoi("0") == 0,                 "ft_atoi \"0\"         → 0");
	check(ft_atoi("2147483647") == 2147483647,
		"ft_atoi INT_MAX");
	check(ft_atoi("-2147483648") == -2147483648,
		"ft_atoi INT_MIN");
	check(ft_atoi("abc") == 0,               "ft_atoi non-numeric  → 0");
	check(ft_atoi("   -42abc") == -42,       "ft_atoi stops at non-digit");
	check(ft_atoi("  \t\n\r\f\v1") == 1,    "ft_atoi all whitespace types");

	subsection("ft_itoa");
	s = ft_itoa(0);
	check(s && strcmp(s, "0") == 0,           "ft_itoa 0");
	free(s);
	s = ft_itoa(42);
	check(s && strcmp(s, "42") == 0,          "ft_itoa 42");
	free(s);
	s = ft_itoa(-99);
	check(s && strcmp(s, "-99") == 0,         "ft_itoa -99");
	free(s);
	s = ft_itoa(2147483647);
	check(s && strcmp(s, "2147483647") == 0,  "ft_itoa INT_MAX");
	free(s);
	s = ft_itoa(-2147483648);
	check(s && strcmp(s, "-2147483648") == 0, "ft_itoa INT_MIN");
	free(s);
}

/* ── Memory functions ──────────────────────────────────────────────────────── */
static void	test_memory(void)
{
	char	buf[32];
	char	src[16];
	char	dst2[16];
	char	overlap[16];
	int		*arr;

	section("MEMORY FUNCTIONS");

	subsection("ft_memset");
	ft_memset(buf, 'X', 5);
	buf[5] = '\0';
	check(strcmp(buf, "XXXXX") == 0,    "ft_memset fills 5 bytes");
	ft_memset(buf, 0, 1);
	check(buf[0] == '\0',               "ft_memset value=0");
	ft_memset(buf, 'A', 0);
	check(buf[0] == '\0',               "ft_memset n=0 is no-op");

	subsection("ft_bzero");
	ft_memset(buf, 'Z', 8);
	ft_bzero(buf, 5);
	check(buf[0] == 0 && buf[4] == 0 && buf[5] == 'Z',
		"ft_bzero zeros first 5, leaves rest intact");
	ft_bzero(buf, 0);
	check(buf[5] == 'Z',                "ft_bzero n=0 is no-op");

	subsection("ft_memcpy");
	memcpy(src, "copy_me!", 9);
	ft_memcpy(dst2, src, 9);
	check(memcmp(dst2, "copy_me!", 9) == 0, "ft_memcpy normal copy");
	ft_memcpy(dst2, src, 1);
	check(dst2[0] == 'c',               "ft_memcpy 1 byte");

	subsection("ft_memmove");
	memcpy(overlap, "abcdefgh", 9);
	ft_memmove(overlap + 2, overlap, 5);
	check(overlap[2] == 'a' && overlap[6] == 'e',
		"ft_memmove src before dst (overlap)");
	memcpy(overlap, "abcdefgh", 9);
	ft_memmove(overlap, overlap + 2, 5);
	check(overlap[0] == 'c' && overlap[4] == 'g',
		"ft_memmove src after dst (overlap)");
	memcpy(overlap, "abcdef", 7);
	ft_memmove(overlap, overlap, 6);
	check(memcmp(overlap, "abcdef", 6) == 0,
		"ft_memmove src == dst no change");

	subsection("ft_memchr");
	check(ft_memchr("search", 'r', 6) != NULL,
		"ft_memchr finds 'r'");
	check(strcmp((char *)ft_memchr("search", 'r', 6), "rch") == 0,
		"ft_memchr returns correct ptr");
	check(ft_memchr("search", 'z', 6) == NULL,
		"ft_memchr not found → NULL");
	check(ft_memchr("abc", 'c', 2) == NULL,
		"ft_memchr out of range → NULL");
	check(ft_memchr("abc", 'a', 3) != NULL,
		"ft_memchr finds first byte");

	subsection("ft_memcmp");
	check(ft_memcmp("abc", "abc", 3) == 0, "ft_memcmp equal → 0");
	check(ft_memcmp("abc", "abd", 3) < 0,  "ft_memcmp less → negative");
	check(ft_memcmp("abd", "abc", 3) > 0,  "ft_memcmp greater → positive");
	check(ft_memcmp("abc", "abc", 0) == 0, "ft_memcmp n=0 → 0");

	subsection("ft_calloc");
	arr = ft_calloc(5, sizeof(int));
	check(arr && arr[0] == 0 && arr[2] == 0 && arr[4] == 0,
		"ft_calloc 5 ints zero-initialised");
	free(arr);
	arr = ft_calloc(1, 1);
	check(arr != NULL,                  "ft_calloc(1, 1) returns non-NULL");
	free(arr);
}

/* ── FD output functions (visual, run in fork) ─────────────────────────────── */
static void	child_putchar(void)
{
	ft_putchar_fd('A', 1);
	ft_putchar_fd('B', 1);
	ft_putchar_fd('C', 1);
	ft_putchar_fd('\n', 1);
}

static void	child_putstr(void)
{
	ft_putstr_fd("hello fd", 1);
	ft_putchar_fd('\n', 1);
}

static void	child_putendl(void)
{
	ft_putendl_fd("with newline", 1);
}

static void	child_putnbr(void)
{
	ft_putnbr_fd(0, 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(42, 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(-2147483648, 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(2147483647, 1);
	ft_putchar_fd('\n', 1);
}

static void	test_fd_output(void)
{
	section("FILE DESCRIPTOR OUTPUT");
	printf(MAGENTA "  (visual — compare printed values to labels)\n" RESET);
	printf(BLUE "  ft_putchar_fd 'A','B','C': " RESET);
	run_forked(child_putchar, "ft_putchar_fd");
	printf(BLUE "  ft_putstr_fd \"hello fd\":  " RESET);
	run_forked(child_putstr, "ft_putstr_fd");
	printf(BLUE "  ft_putendl_fd + newline:  " RESET);
	run_forked(child_putendl, "ft_putendl_fd");
	printf(BLUE "  ft_putnbr_fd 0,42,INT_MIN,INT_MAX:\n  " RESET);
	run_forked(child_putnbr, "ft_putnbr_fd");
}

/* ── Linked list bonus ─────────────────────────────────────────────────────── */
static void	del_free(void *content)
{
	free(content);
}

static void	print_node(void *content)
{
	printf("    " CYAN "→" RESET " %s\n", (char *)content);
}

static void	*dup_node(void *content)
{
	return (ft_strdup((char *)content));
}

static void	test_list(void)
{
	t_list	*head;
	t_list	*copy;
	t_list	*lone;

	section("BONUS — LINKED LIST");

	subsection("ft_lstnew");
	head = ft_lstnew(ft_strdup("first"));
	check(head != NULL, "ft_lstnew creates node");
	check(strcmp((char *)head->content, "first") == 0,
		"ft_lstnew stores content correctly");
	check(head->next == NULL, "ft_lstnew next is NULL");

	subsection("ft_lstadd_back / ft_lstadd_front");
	ft_lstadd_back(&head, ft_lstnew(ft_strdup("second")));
	ft_lstadd_back(&head, ft_lstnew(ft_strdup("third")));
	ft_lstadd_front(&head, ft_lstnew(ft_strdup("zero")));
	check(strcmp((char *)head->content, "zero") == 0,
		"ft_lstadd_front → \"zero\" is new head");

	subsection("ft_lstsize");
	check(ft_lstsize(head) == 4, "ft_lstsize → 4 after 4 inserts");
	check(ft_lstsize(NULL) == 0, "ft_lstsize(NULL) → 0");

	subsection("ft_lstlast");
	check(strcmp((char *)ft_lstlast(head)->content, "third") == 0,
		"ft_lstlast → \"third\"");

	subsection("ft_lstiter");
	printf(MAGENTA "  ft_lstiter output (expect: zero first second third):\n"
		RESET);
	ft_lstiter(head, print_node);

	subsection("ft_lstmap");
	copy = ft_lstmap(head, dup_node, del_free);
	check(copy && ft_lstsize(copy) == 4,
		"ft_lstmap produces 4-node copy");
	check(copy && strcmp((char *)copy->content, "zero") == 0,
		"ft_lstmap first node content matches");
	ft_lstclear(&copy, del_free);
	check(copy == NULL, "ft_lstclear on mapped list → NULL");

	subsection("ft_lstdelone");
	lone = ft_lstnew(ft_strdup("standalone"));
	ft_lstdelone(lone, del_free);
	check(1, "ft_lstdelone doesn't crash");

	subsection("ft_lstclear");
	ft_lstclear(&head, del_free);
	check(head == NULL, "ft_lstclear on main list → NULL");

	head = NULL;
	ft_lstclear(&head, del_free);
	check(head == NULL, "ft_lstclear(NULL list) is no-op");
}

/* ── Forked crash guard (NULL / dangerous inputs) ──────────────────────────── */
static void	crash_strlen_null(void)   { ft_strlen(NULL); }
static void	crash_strchr_null(void)   { ft_strchr(NULL, 'a'); }
static void	crash_strrchr_null(void)  { ft_strrchr(NULL, 'a'); }
static void	crash_memset_null(void)   { ft_memset(NULL, 0, 4); }
static void	crash_memcpy_null(void)   { char b[4]; ft_memset(b, 0, 4); ft_memcpy(NULL, b, 4); }
static void	crash_putstr_null(void)   { ft_putstr_fd(NULL, 1); }
static void	crash_putendl_null(void)  { ft_putendl_fd(NULL, 1); }

static void	test_crash_cases(void)
{
	int	r;

	section("CRASH GUARD  (NULL / edge inputs in fork)");
	printf(MAGENTA
		"  Functions called with NULL — if they segfault the child\n"
		"  process crashes, parent catches it and continues.\n"
		"  'OK' means no crash (graceful), 'CRASH' means segfault.\n"
		RESET "\n");
	r = run_forked(crash_strlen_null,   "ft_strlen(NULL)");
	if (r)
		printf(GREEN "  [OK]" RESET "  ft_strlen(NULL) handled gracefully\n");
	r = run_forked(crash_strchr_null,   "ft_strchr(NULL, 'a')");
	if (r)
		printf(GREEN "  [OK]" RESET "  ft_strchr(NULL,'a') handled gracefully\n");
	r = run_forked(crash_strrchr_null,  "ft_strrchr(NULL, 'a')");
	if (r)
		printf(GREEN "  [OK]" RESET
			"  ft_strrchr(NULL,'a') handled gracefully\n");
	r = run_forked(crash_memset_null,   "ft_memset(NULL, 0, 4)");
	if (r)
		printf(GREEN "  [OK]" RESET "  ft_memset(NULL,...) handled gracefully\n");
	r = run_forked(crash_memcpy_null,   "ft_memcpy(NULL, buf, 4)");
	if (r)
		printf(GREEN "  [OK]" RESET "  ft_memcpy(NULL,...) handled gracefully\n");
	r = run_forked(crash_putstr_null,   "ft_putstr_fd(NULL, 1)");
	if (r)
		printf(GREEN "  [OK]" RESET "  ft_putstr_fd(NULL,1) handled gracefully\n");
	r = run_forked(crash_putendl_null,  "ft_putendl_fd(NULL, 1)");
	if (r)
		printf(GREEN "  [OK]" RESET
			"  ft_putendl_fd(NULL,1) handled gracefully\n");
}

/* ── Entry point ───────────────────────────────────────────────────────────── */
int	main(int ac, char **av)
{
	(void)ac;
	(void)av;

	printf(BOLD CYAN
		"\n╔══════════════════════════════╗\n"
		"║     LIBFT  TEST  SUITE       ║\n"
		"╚══════════════════════════════╝\n"
		RESET);

	test_char_checks();
	test_strings();
	test_numbers();
	test_memory();
	test_fd_output();
	test_list();
	test_crash_cases();

	printf(BOLD
		"\n╔══════════════════════════════╗\n"
		"║           RESULTS            ║\n"
		"╠══════════════════════════════╣\n" RESET);
	printf(BOLD "║  " GREEN "OK : %-4d" RESET BOLD
		"  " RED "KO : %-4d" RESET BOLD
		"  Total: %-3d ║\n" RESET,
		g_ok, g_ko, g_ok + g_ko);
	printf(BOLD "╚══════════════════════════════╝\n\n" RESET);

	return (g_ko > 0 ? 1 : 0);
}
