#ifndef LCIPHER_H
#define LCIPHER_H

#include <stdlib.h>
#include <inttypes.h>

#define ROUNDS 8
#define SBOX_COUNT 4
#define SBOX_SIZE 128
#define PBOX_SIZE 4
#define FINPUT_SIZE 4
#define BLOCK_SIZE 8
#define PHT_MAX 65536

typedef struct {

    uint32_t key_arr[ROUNDS];

} lc_ctx;

void lc_ctx_expand(lc_ctx *ctx, const char *passphrase, size_t pass_size);

void lc_ctx_invert(lc_ctx *ctx);

void lc_encrypt_buffer(const lc_ctx *ctx, const char *iv, const char *input, size_t insz, char *output);

void lc_decrypt_buffer(const lc_ctx *ctx, const char *input, size_t insz, char *output);

size_t lc_output_size(size_t insz);

#endif
