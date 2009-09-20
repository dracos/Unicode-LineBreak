/*
 *
 */
#ifndef _LINEBREAK_COMMON_H_

#include <errno.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#ifdef USE_LIBTHAI
#    include "thai/thwchar.h"
#    include "thai/thwbrk.h"
#endif /* USE_LIBTHAI */

/* Primitive types */
typedef unsigned int unichar_t;
typedef unsigned char propval_t;

/* Unicode string */
typedef struct {
    unichar_t *str;
    size_t len;
} unistr_t;

/* Grapheme cluster */
typedef struct {
    size_t idx; size_t len;
    size_t col;
    propval_t lbc;
    unsigned char flag;
} gcchar_t;

/* Property map entry */
typedef struct {
    unichar_t beg;
    unichar_t end;
    propval_t lbc;
    propval_t eaw;
    propval_t gbc;
    propval_t scr;
} mapent_t;

/* LineBreak object */
typedef struct {
    mapent_t *map;
    size_t mapsiz;
    unsigned int options;
    unsigned long int refcount;
} linebreak_t;

/* GCString object */
typedef struct {
    unichar_t *str;
    size_t len;
    gcchar_t *gcstr;
    size_t gclen;
    size_t pos;
    linebreak_t *lbobj;
} gcstring_t;


#define LINEBREAK_OPTION_EASTASIAN_CONTEXT (1)
#define PROP_UNKNOWN ((propval_t)~0)

#define M (4)
#define D (3)
#define I (2)
#define P (1)

#define MANDATORY (M)
#define DIRECT (D)
#define INDIRECT (I)
#define PROHIBITED (P)
#define URGENT (200)

#define _LINEBREAK_COMMON_H_
#endif /* _LINEBREAK_COMMON_H_ */
