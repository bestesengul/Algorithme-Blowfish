#ifndef BLOWFISH_H_
#define BLOWFISH_H_

#include <stdint.h>

typedef struct {
   uint32_t P[16 + 2];
   uint32_t S[4][256];
} BLOWFISH_CTX;


unsigned long F(BLOWFISH_CTX *ctx, uint32_t x);
void Blowfish_Encrypt(BLOWFISH_CTX *ctx, uint32_t *xl, uint32_t *xr);
void Blowfish_Decrypt(BLOWFISH_CTX *ctx, uint32_t *xl, uint32_t *xr);
void Blowfish_Init(BLOWFISH_CTX *ctx, uint16_t *key, int KeyLen);

#endif // BLOWFISH_H_


