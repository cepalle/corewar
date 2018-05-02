/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   libft.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cepalle <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/04 10:37:50 by cepalle      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/30 16:40:36 by ppichier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <sys/types.h>
# include <string.h>
# include <stdarg.h>
# include <inttypes.h>
# include <limits.h>
# include <wchar.h>

# define BUFF_SIZE		1023
# define STR_SIZE		127
# define QUEU_INIT_SIZE	2

void		*ft_memset(void *b, int c, size_t len);
void		ft_bzero(void *s, size_t n);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memccpy(void *dst, const void *src, int c, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t len);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
size_t		ft_strlen(const char *str);
char		*ft_strdup(const char *s1);
char		*ft_strcpy(char *dest, const char *src);
char		*ft_strncpy(char *dest, const char *src, size_t n);
char		*ft_strcat(char *s1, const char *s2);
char		*ft_strncat(char *s1, const char *s2, size_t n);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
char		*ft_strstr(const char *haystack, const char *needle);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_atoi(const char *str);
int			ft_atoi_only(const char *str, int *er);
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
int			ft_toupper(int c);
int			ft_tolower(int c);
int			ft_isblank(char c);
void		*ft_realloc(void *pt, int so, int sn);
char		*ft_strndup(char *str, int n);
void		ft_free_tabchar(char **tab);
int			ft_lentabchar(char **tab);
void		ft_free_print_exit(void *pt, char *str, int n);

void		*ft_memalloc(size_t size);
void		ft_memdel(void **ap);
char		*ft_strnew(size_t size);
void		ft_strdel(char **as);
void		ft_strclr(char *s);
void		ft_striter(char *s, void (*f)(char *));
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
char		*ft_strmap(char const *s, char (*f)(char));
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int			ft_strequ(char const *s1, char const *s2);
int			ft_strnequ(char const *s1, char const *s2, size_t n);
char		*ft_strsub(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s);
char		**ft_strsplit(char const *s, char c);
char		*ft_itoa(int n);
void		ft_putchar(char c);
void		ft_putstr(char const *s);
void		ft_putendl(char const *s);
void		ft_putnbr(int n);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char const *s, int fd);
void		ft_putendl_fd(char const *s, int fd);
void		ft_putnbr_fd(int n, int fd);
char		*ft_itoa_base(int value, int base);

int			get_next_line(int fd, char **line);

struct		s_format
{
	char	flag_hash;
	char	flag_0;
	char	flag_minus;
	char	flag_plus;
	char	flag_space;
	int		width;
	int		precision;
	char	lenght;
	char	type;
};

typedef struct s_format	t_format;

int			ft_printf(const char *format, ...);

int			pf_format_atoi(const char *format, int *i);
t_format	pf_get_format(const char *format, int *i);
void		pf_get_format_flags(const char *format, int *i, t_format *fm);
char		pf_get_format_type(const char *format, int *i, t_format *fm);
void		pf_handler_format(t_format *fm);
char		*pf_arg_to_str(t_format *fm, va_list *ap);

char		*pf_arg_oux_to_str(t_format *fm, va_list *ap);
char		*pf_arg_di_to_str(t_format *fm, va_list *ap);
char		*pf_arg_p_to_str(t_format *fm, va_list *ap);
char		*pf_arg_s_to_str(t_format *fm, va_list *ap);
char		*pf_arg_c_to_str(t_format *fm, va_list *ap);
char		*pf_not_arg_to_str(t_format *fm, va_list *ap);
int			pf_print_arg_oux(t_format *fm, char *str_arg);
int			pf_print_arg_i(t_format *fm, char *str_arg);
int			pf_print_arg_p(t_format *fm, char *str_arg);
int			pf_print_arg_s(t_format *fm, char *str_arg);
int			pf_print_arg_c(t_format *fm, char *str_arg);
int			pf_print_not_arg(t_format *fm, char *str_arg);
int			pf_print_not_type(t_format *fm, char *str_arg);
char		*pf_arg_not_type_to_str(t_format *fm, va_list *ap);

int			pf_padding_width(t_format *fm, char *str_arg);
int			pf_print_flags(t_format *fm, char *str_arg);
int			pf_padding_precision(t_format *fm, char *str_arg);

char		*pf_itoa(signed long long n, t_format *fm);
char		*pf_utoa(unsigned long long int n, t_format *fm);
char		pf_choose_ou_char(unsigned c);
char		pf_choose_x_char(unsigned c);
char		pf_choose_xx_char(unsigned c);

char		*pf_strnew(size_t size);
void		*pf_memalloc(size_t size);
char		*pf_strdup(const char *s1);
void		*pf_memcpy(void *dst, const void *src, size_t n);
char		*pf_strcpy(char *dest, const char *src);
size_t		pf_strlen(const char *str);
void		pf_putchar(char c);
int			pf_putstr(char const *s);
int			pf_put_n_char(char c, int nb);
int			pf_put_wc(wchar_t cc);
char		pf_is_num(char c);
int			pf_size_wc(wchar_t wc);
int			pf_wstrlen(wchar_t *wstr);
char		*pf_strrev(char *str);
char		is_flags(char c);
char		is_num(char c);
char		is_lenght(char c);

struct		s_queu
{
	int		*queu;
	int		nb_el;
	int		size;
};

typedef struct s_queu	t_queu;

void		ft_queu_add(t_queu *q, int n);
int			ft_queu_pop(t_queu *q);
void		ft_queu_init(t_queu *q);
char		ft_queu_is_in(t_queu *g, int n);

#endif
