/**********************************************************************
 *
 *  Prototypes
 *
 **********************************************************************/

static enum CbcTagId get_tag_id(const char *tag);
static TAG_SET(Format);
static TAG_GET(Format);
static enum CbcTagFormat GetTagFormat(const char *t);
static TAG_INIT(Hooks);
static TAG_CLONE(Hooks);
static TAG_FREE(Hooks);
static TAG_SET(Hooks);
static TAG_GET(Hooks);

/**********************************************************************
 *
 *  Tag IDs
 *
 **********************************************************************/

static const char *gs_TagIdStr[] = {
  "Format",
  "Hooks",
  "<<INVALID>>"
};

/**********************************************************************
 *
 *  Hooks Vtable
 *
 **********************************************************************/

static CtTagVtable gs_Hooks_vtable = {
  Hooks_Init,
  Hooks_Clone,
  Hooks_Free
};

/**********************************************************************
 *
 *  Tag Method Table
 *
 **********************************************************************/

static const struct {
  TagSetMethod set;
  TagGetMethod get;
  CtTagVtable *vtbl;
} gs_TagTbl[] = {
  { Format_Set, Format_Get, NULL },
  { Hooks_Set, Hooks_Get, &gs_Hooks_vtable },
  {NULL, NULL, NULL}
};

/**********************************************************************
 *
 *  Main Tag Tokenizer
 *
 **********************************************************************/

static enum CbcTagId get_tag_id(const char *tag)
{
  switch (tag[0])
  {
    case 'F':
      if (tag[1] == 'o' &&
          tag[2] == 'r' &&
          tag[3] == 'm' &&
          tag[4] == 'a' &&
          tag[5] == 't' &&
          tag[6] == '\0')
      {                                             /* Format     */
        return CBC_TAG_FORMAT;
      }
  
      goto unknown;
  
    case 'H':
      if (tag[1] == 'o' &&
          tag[2] == 'o' &&
          tag[3] == 'k' &&
          tag[4] == 's' &&
          tag[5] == '\0')
      {                                             /* Hooks      */
        return CBC_TAG_HOOKS;
      }
  
      goto unknown;
  
    default:
      goto unknown;
  }

unknown:
  return CBC_INVALID_TAG;
}

/**********************************************************************
 *
 *  Format Tokenizer
 *
 **********************************************************************/

static enum CbcTagFormat GetTagFormat(const char *t)
{
  switch (t[0])
  {
    case 'B':
      if (t[1] == 'i' &&
          t[2] == 'n' &&
          t[3] == 'a' &&
          t[4] == 'r' &&
          t[5] == 'y' &&
          t[6] == '\0')
      {                                             /* Binary     */
        return CBC_TAG_FORMAT_BINARY;
      }
  
      goto unknown;
  
    case 'S':
      if (t[1] == 't' &&
          t[2] == 'r' &&
          t[3] == 'i' &&
          t[4] == 'n' &&
          t[5] == 'g' &&
          t[6] == '\0')
      {                                             /* String     */
        return CBC_TAG_FORMAT_STRING;
      }
  
      goto unknown;
  
    default:
      goto unknown;
  }

unknown:
  return CBC_INVALID_FORMAT;
}

/**********************************************************************
 *
 *  Format Set/Get Methods
 *
 **********************************************************************/

static TAG_SET(Format)
{
  if (SvOK(val))
  {
    if (SvROK(val))
      Perl_croak(aTHX_ "Value for Format tag must not be a reference");
    else
    {
      const char *valstr = SvPV_nolen(val);
      enum CbcTagFormat Format = GetTagFormat(valstr);

      if (Format == CBC_INVALID_FORMAT)
        Perl_croak(aTHX_ "Invalid value '%s' for Format tag", valstr);

      tag->flags = Format;

      return TSRV_UPDATE;
    }
  }

  return TSRV_DELETE;
}

static TAG_GET(Format)
{
  static const char *val[] = {
    "String",
    "Binary"
  };

  if (tag->flags >= sizeof(val) / sizeof(val[0]))
    fatal("Invalid value (%d) for Format tag", tag->flags);

  return newSVpv(val[tag->flags], 0);
}

