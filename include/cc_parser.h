#ifndef CC_PARSER_H
#define CC_PARSER_H

#include <stdbool.h>

bool ccp_parse_int(const char *input, int *parsed_result);

bool ccp_parse_int_range(const char *input, int min_val, int max_val, int *parsed_result);

#endif