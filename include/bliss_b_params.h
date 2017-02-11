#ifndef __BLISS_B_PARAMS__
#define __BLISS_B_PARAMS__

#include <stdint.h>
#include <stdlib.h>


/* Names for the five varieties of bliss-b */
typedef enum { BLISS_B_0, BLISS_B_1, BLISS_B_2, BLISS_B_3, BLISS_B_4 } bliss_kind_t;

typedef struct {
  bliss_kind_t kind;    /* the kind of bliss-b (i.e. *this* choice of parameters)  */
  int32_t q;            /* field modulus  */
  int32_t n;            /* ring size (x^n+1)  */
  int32_t d;            /* bit drop shift  */
  int32_t mod_p;        /* magic modulus  */
  int32_t kappa;        /* index vector size  */
  int32_t q2;           /* 2 * field modulus  */
  int32_t q_inv;        /* floor(2^32/q)      */
  int32_t q2_inv;       /* floor(2^32/q2)     */
  int32_t one_q2;        /* 1/(q+2) mod 2q     */
  size_t  theta;        /* cseed in bytes  */
  int32_t b_inf;        /* infinite norm  */
  int32_t b_l2;         /* L2 norm  */
  int32_t nz1;          /* nonzero +-1  */
  int32_t nz2;          /* nonzero +-2  */
  int32_t pmax;         /* derived from nt, nz2, n, kappa  */
  long double sigma;    /* standard deviation  */
  long double m;        /* repetition rate  */
  const int32_t *w;     /* n roots of unity (mod q)  */
  const int32_t *r;     /* w[i]/n (mod q)  */
} bliss_param_t;




extern void bliss_params_init(bliss_param_t *params, bliss_kind_t kind);



#endif
