#include <cc_parser.h>
#include <errno.h>
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>

bool ccp_parse_int(const char *input, int *parsed_value)
{

    if (input == NULL || *input == '\0') {
        return false;
    }

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

bool ccp_parse_int_range(const char *input, int min_val, int max_val, int *parsed_value)
{
    if (input == NULL || *input == '\0' || parsed_value == NULL) {
        return false;
    }
    char *end;
    errno = 0;

    long value = strtol(input, &end, 10);

    if (end == input || *end != '\0' || errno == ERANGE)
        return false;

    if (value < min_val || value > max_val)
        return false;
    if (parsed_value != NULL)
        *parsed_value = (int)value;

    return true;
}
