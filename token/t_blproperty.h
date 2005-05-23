#ifndef _TOKEN_T_BLPROPERTY_H
#define _TOKEN_T_BLPROPERTY_H

typedef enum {
  BLP_ALIGN,
  BLP_OFFSET,
  BLP_BYTE_ORDER,
  BLP_MAX_ALIGN,
  BLP_BLOCK_SIZE,
  INVALID_BLPROPERTY
} BLProperty;

typedef enum {
  BLPV_BIG_ENDIAN,
  BLPV_LITTLE_ENDIAN,
  INVALID_BLPROPVAL
} BLPropValStr;

#endif
