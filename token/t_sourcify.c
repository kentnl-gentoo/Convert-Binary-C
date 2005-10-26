typedef enum {
  SOURCIFY_OPTION_Context,
  INVALID_SOURCIFY_OPTION
} SourcifyConfigOption;

static SourcifyConfigOption get_sourcify_config_option( const char *option )
{
if (option[0] == 'C' &&
    option[1] == 'o' &&
    option[2] == 'n' &&
    option[3] == 't' &&
    option[4] == 'e' &&
    option[5] == 'x' &&
    option[6] == 't' &&
    option[7] == '\0')
{                                                 /* Context    */
  return SOURCIFY_OPTION_Context;
}

goto unknown;

unknown:
  return INVALID_SOURCIFY_OPTION;
}
