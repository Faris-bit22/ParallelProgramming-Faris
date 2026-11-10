# LAB06 – Assignment 5: Vectorization

## Benchmark Results

Tested on Intel Core i7-4600U (Haswell) using GCC 15.2.0, LIKWID and 256-bit vectors.

Average runtime from 3 runs:

- **run_base** – timestep.c – **0.3997s** – Not vectorized
- **run_opt1** – timestep_opt1.c – **0.3953s** – Partial
- **run_opt2** – timestep_opt2.c – **0.3971s** – Partial
- **run_opt3** – timestep_opt3.c – **0.3949s** – Partial
- **run_opt3_fast** – timestep_opt3.c with extra flags – **0.3240s** – Fully vectorized (Fastest)

All versions returned `Minimum dt is 0.016964`.

## Compiler Feedback & Notes

- **Base:** GCC couldn't vectorize the main loop because of unsupported control flow.
- **Opt1 & Opt2:** GCC reported partial vectorization using 32-byte vectors, but the inner loop still had problems with control flow and `sqrt()`.
- **Opt3:** Similar results to opt1 and opt2. The main calculation was not fully vectorized.
- **Opt3_fast:** Adding `-fno-trapping-math` and `-fno-math-errno` allowed GCC to vectorize the inner loop using 32-byte vectors.

## LIKWID Results

I used `FLOPS_AVX` because `MEM_DP` was not available for my processor.

- **Base:** 4,499 AVX instructions
- **Opt1:** 1,324 AVX instructions
- **Opt2:** 1,253 AVX instructions
- **Opt3:** 1,293 AVX instructions
- **Opt3_fast:** 58,751,179 AVX instructions

## Conclusion

- **Fully vectorized?** Opt3_fast was the only version where GCC reported successful vectorization of the main calculation loops.
- **Vector length?** 256-bit / 32-byte vectors.
- **Fastest version?** Opt3_fast with an average runtime of 0.3240s.
- **Improvement?** Around 19% less runtime compared to the base version.

The extra compiler flags made the biggest difference in my tests.
