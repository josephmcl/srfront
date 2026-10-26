#pragma once

/* Stochastic-rounding intrinsics.                                  */

typedef struct { int family; } sr_family;
typedef struct { int value; } sr_key;

#define SR_FAMILY(name) extern const sr_family name

/* Return a key from RNG family, f, and int keys for indepdencence 
   properties.                                                      */
sr_key key(sr_family f, ...);

/* Round x stochastically to an FP grid.                            */
float  sr_fp8(float x, sr_key k);
float  sr_bf16(float x, sr_key k);
float  sr_fl(float x, sr_key k);
float  sr_fixed(float x, int e, sr_key k); /* Grid gets 2^e         */

/* Random input                                                     */
void   sr_random(const char *input);

/* Input on grid got 2^e                                            */
void   sr_on_grid(const char *input, const char *e);

/* Observe the current value of a variable at a call site.          */
void   sr_observe(const char *name, float value);
