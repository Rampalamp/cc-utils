#include <cc_parser.h>
#include <errno.h>
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>

bool ccp_parse_int(const char *input, int *parsed_value)
{
    char *end;
    errno = 0;

    long value = strtol(input, &end, 10);

    if (end == input || *end != '\0' || errno == ERANGE)
        return false;

    if (value < INT_MIN || value > INT_MAX)
        return false;

    if (parsed_value != NULL)
        *parsed_value = (int)value;

    return true;
}