# LAB 06 – Assignment 5: Vectorization

**Student:** Faris  
**Course:** IT2004 – Parallel Programming

## 1. Introduction

In this assignment, I tested different versions of the timestep program from Chapter 6 of the *Essentials of Parallel Computing* repository.

The main goal was to see how vectorization affects program performance. I used GCC to check which loops were vectorized and LIKWID to measure the performance.

I tested five versions: the original program, three optimized versions, and a final version with additional compiler flags.

## 2. Tools

I used the following tools:

- Ubuntu (WSL)
- GCC 15.2.0
- LIKWID 5.5.1
- Intel Core i7-4600U (Haswell)

## 3. Compilation and Vectorization Results

I compiled the programs using GCC with `-O3`, `-march=native`, `-fopenmp-simd`, and vectorization reporting options.

| Version | GCC Result |
|---|---|
| Original | Main timestep loop was not vectorized |
| Opt1 | Some loops were vectorized, but GCC still reported unsupported control flow |
| Opt2 | Some loops were vectorized, but GCC still reported unsupported control flow |
| Opt3 | Some loops were vectorized, but GCC still reported unsupported control flow |
| Opt3 final | GCC reported successful vectorization of both timestep loops |

GCC reported 32-byte vectors, which means 256-bit vector instructions.

For the final version, I added these compiler flags:

`-fno-trapping-math -fno-math-errno -mprefer-vector-width=256`

After adding these flags, GCC was able to vectorize the loop that previously failed.

For example, the final compilation reported:

```text
timestep_opt3.c:8:9: optimized: loop vectorized using 32 byte vectors
timestep_opt3.c:10:19: optimized: loop vectorized using 32 byte vectors
```

## 4. LIKWID Results

I used the `FLOPS_AVX` performance group because `MEM_DP` was not available for my processor.

These are the results from my first measurements:

| Version | Runtime (s) | AVX Instructions | Packed DP (MFLOP/s) |
|---|---:|---:|---:|
| Original | 0.5666 | 4,499 | 0.0318 |
| Opt1 | 0.4536 | 1,324 | 0.0117 |
| Opt2 | 0.4313 | 1,253 | 0.0116 |
| Opt3 | 0.4361 | 1,293 | 0.0119 |
| Opt3 final | 0.3405 | 58,751,179 | 690.1844 |

The final version had many more AVX calculation instructions than the other versions. This matches the GCC output, which showed additional vectorization.

## 5. Repeated Runtime Measurements

I ran each version three more times to compare the execution times.

| Version | Run 1 (s) | Run 2 (s) | Run 3 (s) | Average (s) |
|---|---:|---:|---:|---:|
| Original | 0.4122 | 0.3856 | 0.4014 | 0.3997 |
| Opt1 | 0.3913 | 0.3972 | 0.3974 | 0.3953 |
| Opt2 | 0.4032 | 0.3965 | 0.3916 | 0.3971 |
| Opt3 | 0.3992 | 0.3920 | 0.3934 | 0.3949 |
| Opt3 final | 0.3220 | 0.3224 | 0.3276 | 0.3240 |

The original and first three optimized versions had similar execution times.

The final version was the fastest. Its average runtime was about 18.9% lower than the original version.

## 6. Program Output

All five versions printed the same result:

```text
Minimum dt is 0.016964
```

This shows that the displayed numerical result did not change after the optimizations.

## 7. Conclusion

From my tests, I learned that adding optimization directives does not always mean that the compiler can vectorize the complete calculation.

In the first three optimized versions, GCC still reported problems with the inner loop.

The biggest improvement happened when I compiled the third optimized version with `-fno-trapping-math` and `-fno-math-errno`.

The final version used 256-bit vectors and had the best average runtime in my tests.

I also noticed that the runtime results changed between runs, so repeating measurements was useful.

Overall, this assignment helped me understand how compiler options and vectorization can improve program performance.

## 8. Source

Original examples: https://github.com/EssentialsofParallelComputing/Chapter6

## 9. How to Compile and Run

I compiled all versions using GCC.

```bash
gcc -O3 -march=native -mprefer-vector-width=256 -fopenmp-simd main.c timestep.c -lm -o timestep_base
gcc -O3 -march=native -mprefer-vector-width=256 -fopenmp-simd main.c timestep_opt1.c -lm -o timestep_opt1
gcc -O3 -march=native -mprefer-vector-width=256 -fopenmp-simd main.c timestep_opt2.c -lm -o timestep_opt2
gcc -O3 -march=native -mprefer-vector-width=256 -fopenmp-simd main.c timestep_opt3.c -lm -o timestep_opt3
gcc -O3 -march=native -mprefer-vector-width=256 -fopenmp-simd -fno-trapping-math -fno-math-errno main.c timestep_opt3.c -lm -o timestep_opt3_final



### Checking Vectorization

I used the following command to check if GCC was able to vectorize the loops:

```bash
gcc -O3 -march=native -mprefer-vector-width=256 -fopenmp-simd -fno-trapping-math -fno-math-errno -fopt-info-vec-optimized -fopt-info-vec-missed main.c timestep_opt3.c -lm -o timestep_opt3_final
```

### Measuring Performance

I used LIKWID with the FLOPS_AVX group to measure performance:

```bash
sudo likwid-perfctr -C 0 -g FLOPS_AVX ./timestep_opt3_final
```

The MEM_DP group was not available on my Haswell processor, so I used FLOPS_AVX instead.

