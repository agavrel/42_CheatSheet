#ifndef SIMD_H_
#define SIMD_H_

#include <ctype.h>
#include <stdint.h>

#if !defined(NO_SIMD) && defined(__AVX512F__) && defined(__AVX512BW__)
#include <immintrin.h>
#include <nmmintrin.h>
#define simd_vector_from_mask(a)   _mm512_movm_epi8(a)
#define simd_imask_from_mask(a)    _cvtmask64_u64(a)
#define simd_set_i8(a)             _mm512_set1_epi8(a)
#define simd_setzero()             _mm512_setzero_si512()
#define simd_cmpeq_i8_mask(a, b)   _mm512_cmpeq_epi8_mask((a), (b))
#define simd_andnot_i8(a, b)       _mm512_andnot_si512((a), (b))
#define simd_add_i64(a, b)         _mm512_add_epi64((a), (b))
#define simd_sub_i8(a, b)          _mm512_sub_epi8((a), (b))
#define simd_sad_u8(a, b)          _mm512_sad_epu8((a), (b))
#define simd_imask_popcnt(a)       _mm_popcnt_u64(a)
#define simd_cmpeq_i8(a, b)        simd_vector_from_mask(simd_cmpeq_i8_mask((a), (b)))
#define simd_cmpws_i8(a)           simd_vector_from_mask(simd_cmpws_i8_mask(a))
#define simd_store(a, b)          _mm512_store_si512((a), (b))
typedef __m512i simd_vector;
typedef uint64_t simd_imask;
typedef __mmask64 simd_mask;
static inline simd_mask simd_cmpws_i8_mask(simd_vector a)
{
	simd_vector shuffle_src = _mm512_set_epi64(0x0d0c0b0a0900, 0x20,
	                                           0x0d0c0b0a0900, 0x20,
	                                           0x0d0c0b0a0900, 0x20,
	                                           0x0d0c0b0a0900, 0x20);
	return simd_cmpeq_i8_mask(_mm512_shuffle_epi8(shuffle_src, a), a);
}
// shift a left by 1 byte, shifting in byte from the end of b
static inline simd_vector simd_shl1_from_i8(simd_vector a, simd_vector b)
{
	__m512i idx = _mm512_setr_epi64(14, 15, 0, 1, 2, 3, 4, 5);
	return _mm512_alignr_epi8(a, _mm512_permutex2var_epi64(a, idx, b), 15);
}
// endif AVX512
#elif !defined(NO_SIMD) && defined(__AVX2__)
#include <immintrin.h>
#include <nmmintrin.h>
#define simd_vector_from_mask(a)  (a)
#define simd_imask_from_mask(a)   _mm256_movemask_epi8(a)
#define simd_set_i8(a)            _mm256_set1_epi8(a)
#define simd_setzero()            _mm256_setzero_si256()
#define simd_cmpeq_i8(a, b)       _mm256_cmpeq_epi8((a), (b))
#define simd_andnot_i8(a, b)      _mm256_andnot_si256((a), (b))
#define simd_add_i64(a, b)        _mm256_add_epi64((a), (b))
#define simd_sub_i8(a, b)         _mm256_sub_epi8((a), (b))
#define simd_sad_u8(a, b)         _mm256_sad_epu8((a), (b))
#define simd_imask_popcnt(a)      _mm_popcnt_u32(a)
#define simd_cmpeq_i8_mask(a, b)  simd_cmpeq_i8((a), (b))
#define simd_cmpws_i8_mask(a)     simd_cmpws_i8(a)
#define simd_store(a, b)          _mm256_store_si256((a), (b))
typedef __m256i simd_vector;
typedef uint32_t simd_imask;
typedef simd_vector simd_mask;
static inline simd_vector simd_cmpws_i8(simd_vector a)
{
	simd_vector shuffle_src = _mm256_set_epi64x(0x0d0c0b0a0900, 0x20,
	                                            0x0d0c0b0a0900, 0x20);
	return simd_cmpeq_i8(_mm256_shuffle_epi8(shuffle_src, a), a);
}
// shift a left by 1 byte, shifting in byte from the end of b
static inline simd_vector simd_shl1_from_i8(simd_vector a, simd_vector b)
{
	return _mm256_alignr_epi8(a, _mm256_permute2x128_si256(b, a, 0x21), 15);
}
// endif AVX2
#elif !defined(NO_SIMD) && (defined(__SSE2__) || defined(_M_X64) || _M_IX86_FP == 2)
#include <emmintrin.h>
#include <immintrin.h>
#include <nmmintrin.h>
#include <tmmintrin.h>
#define simd_vector_from_mask(a)  (a)
#define simd_imask_from_mask(a)   _mm_movemask_epi8(a)
#define simd_set_i8(a)            _mm_set1_epi8(a)
#define simd_setzero()            _mm_setzero_si128()
#define simd_cmpeq_i8(a, b)       _mm_cmpeq_epi8((a), (b))
#define simd_andnot_i8(a, b)      _mm_andnot_si128((a), (b))
#define simd_add_i64(a, b)        _mm_add_epi64((a), (b))
#define simd_sub_i8(a, b)         _mm_sub_epi8((a), (b))
#define simd_sad_u8(a, b)         _mm_sad_epu8((a), (b))
#define simd_cmpeq_i8_mask(a, b)  simd_cmpeq_i8((a), (b))
#define simd_cmpws_i8_mask(a)     simd_cmpws_i8(a)
#define simd_store(a, b)          _mm_store_si128((a), (b))
#if defined(__AVX__) || defined(__POPCNT__)
#define simd_imask_popcnt(a)      _mm_popcnt_u32((simd_imask)(a))
#endif
typedef __m128i simd_vector;
typedef uint16_t simd_imask;
typedef simd_vector simd_mask;
static inline simd_vector simd_cmpws_i8(simd_vector a)
{
#if defined(__AVX__) || defined(__SSSE3__)
	simd_vector shuffle_src = _mm_set_epi64x(0x0d0c0b0a0900, 0x20);
	return simd_cmpeq_i8(_mm_shuffle_epi8(shuffle_src, a), a);
#else
	return _mm_or_si128(_mm_cmpgt_epi8(_mm_add_epi8(a, _mm_set1_epi8(113)),
	                                   _mm_set1_epi8(121)),
	                    _mm_cmpeq_epi8(a, _mm_set1_epi8(' ')));
#endif
}
// shift a left by 1 byte, shifting in byte from the end of b
static inline simd_vector simd_shl1_from_i8(simd_vector a, simd_vector b)
{
#if defined(__AVX__) || defined(__SSSE3__)
	return _mm_alignr_epi8(a, b, 15);
#else
	return _mm_or_si128(_mm_bslli_si128(a, 1), _mm_bsrli_si128(b, 15));
#endif
}
// endif SSE2+
#else // NO_SIMD
#ifndef NO_SIMD
#define NO_SIMD 1
#endif
typedef uint8_t simd_vector;
#endif



#if defined(NO_SIMD)

typedef enum { LCOUNT_INITIAL } lcount_state;
typedef enum { WCOUNT_CONTINUE, WCOUNT_INITIAL } wcount_state;

static inline void wcount_state_set(wcount_state *state, bool wcontinue)
{
	*state = wcontinue ? WCOUNT_CONTINUE : WCOUNT_INITIAL;
}

static inline uint64_t count_lines_final(lcount_state *state)
{
	(void)state;
	return 0;
}
static inline uint64_t count_words_final(wcount_state *state)
{
	(void)state;
	return 0;
}

static inline int count_lines(simd_vector vec, lcount_state *state)
{
	(void)state;
	return vec == '\n';
}
static inline int count_words(simd_vector vec, wcount_state *state)
{
	if (!isspace(vec)) {
		if (*state == WCOUNT_INITIAL) {
			*state = WCOUNT_CONTINUE;
			return 1;
		}
	} else
		*state = WCOUNT_INITIAL;
	return 0;
}

//endif defined(NO_SIMD)
#elif defined(SIMD_USE_POPCNT) && defined(simd_imask_popcnt)

typedef enum { LCOUNT_INITIAL } lcount_state;
typedef enum { WCOUNT_CONTINUE, WCOUNT_INITIAL } wcount_state;

static inline void wcount_state_set(wcount_state *state, bool wcontinue)
{
	*state = wcontinue ? WCOUNT_CONTINUE : WCOUNT_INITIAL;
}

static inline uint64_t count_lines_final(lcount_state *state)
{
	(void)state;
	return 0;
}
static inline uint64_t count_words_final(wcount_state *state)
{
	(void)state;
	return 0;
}

static inline int count_lines(simd_vector vec, lcount_state *state)
{
	(void)state;
	simd_mask lfmask = simd_cmpeq_i8_mask(vec, simd_set_i8('\n'));
	return simd_imask_popcnt(simd_imask_from_mask(lfmask));
}
static inline int count_words(simd_vector vec, wcount_state *state)
{
	simd_imask ws = simd_imask_from_mask(simd_cmpws_i8_mask(vec)),
	           first_chars = ~ws & ((ws << 1) + *state);
	*state = ws >> (sizeof(simd_vector) - 1);
	return simd_imask_popcnt(first_chars);
}

//endif defined(SIMD_USE_POPCNT) && defined(simd_imask_popcnt)
#else

typedef struct {
	simd_vector vcount, count;
	uint8_t iterations;
} lcount_state;
typedef struct {
	simd_vector vcount, count, prev_eqws;
	uint8_t iterations;
} wcount_state;
#define LCOUNT_INITIAL \
	(lcount_state){ simd_setzero(), simd_setzero(), 0 }
#define WCOUNT_INITIAL \
	(wcount_state){ simd_setzero(), simd_setzero(), simd_set_i8(-1), 0 }
#define WCOUNT_CONTINUE \
	(wcount_state){ simd_setzero(), simd_setzero(), simd_setzero(), 0 }

static inline void wcount_state_set(wcount_state *state, bool wcontinue)
{
	state->prev_eqws = wcontinue ? simd_setzero() : simd_set_i8(-1);
}

static inline uint64_t count_lines_final(lcount_state *state)
{
	state->count = simd_add_i64(state->count,
	                            simd_sad_u8(state->vcount, simd_setzero()));
	state->vcount = simd_setzero();
	uint64_t sum = 0;
	union {
		simd_vector vec;
		uint64_t u64[sizeof(simd_vector)/sizeof(uint64_t)];
	} unpack;
	simd_store(&unpack.vec, state->count);
	for (int i = 0; i != sizeof(simd_vector)/sizeof(uint64_t); ++i)
		sum += unpack.u64[i];
	return sum;
}
static inline uint64_t count_words_final(wcount_state *state)
{
	state->count = simd_add_i64(state->count,
	                            simd_sad_u8(state->vcount, simd_setzero()));
	state->vcount = simd_setzero();
	uint64_t sum = 0;
	union {
		simd_vector vec;
		uint64_t u64[sizeof(simd_vector)/sizeof(uint64_t)];
	} unpack;
	simd_store(&unpack.vec, state->count);
	for (int i = 0; i != sizeof(simd_vector)/sizeof(uint64_t); ++i)
		sum += unpack.u64[i];
	return sum;
}

static inline int count_lines(simd_vector vec, lcount_state *state)
{
	simd_vector is_line_feed = simd_cmpeq_i8(vec, simd_set_i8('\n'));
	// is_line_feed has a value of -1 for line feeds, 0 otherwise
	state->vcount = simd_sub_i8(state->vcount, is_line_feed);
	state->iterations++;
	if (state->iterations == 255) {
		// sum line feed position counts before they can overflow
		state->count = simd_add_i64(state->count,
		                            simd_sad_u8(state->vcount, simd_setzero()));
		state->vcount = simd_setzero();
		state->iterations = 0;
	}
	return 0;
}

static inline int count_words_wsmask(simd_mask eqmask, wcount_state *state)
{
	simd_vector eqws = simd_vector_from_mask(eqmask),
	            andmsk = simd_shl1_from_i8(eqws, state->prev_eqws),
	            is_first_char = simd_andnot_i8(eqws, andmsk);
	state->prev_eqws = eqws;
	// is_first_char has a value of -1 for word starting characters, 0 otherwise
	state->vcount = simd_sub_i8(state->vcount, is_first_char);
	state->iterations++;
	if (state->iterations == 255) {
		// sum first character position counts before they can overflow
		state->count = simd_add_i64(state->count,
		                            simd_sad_u8(state->vcount, simd_setzero()));
		state->vcount = simd_setzero();
		state->iterations = 0;
	}
	return 0;
}

static inline int count_words(simd_vector vec, wcount_state *state)
{
	return count_words_wsmask(simd_cmpws_i8_mask(vec), state);
}

#endif

#endif // SIMD_H_
