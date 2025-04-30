typedef struct s_flags
{
    int minus;      // '-' flag
    int zero;       // '0' flag
    int hash;       // '#' flag
    int plus;       // '+' flag
    int space;      // ' ' flag
    int width;      // minimum field width
    int precision;  // precision (after '.')
    int dot;        // whether precision was specified
} t_flags;

t_flags	init_flags(void);
int is_flag(char c);
const char *parse_flags(const char *format, t_flags *flags);
const char *parse_width(const char *format, t_flags *flags);
const char *parse_precision(const char *format, t_flags *flags);





