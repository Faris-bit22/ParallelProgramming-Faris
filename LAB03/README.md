# LAB 03 - Performance Limits and Profiling

In this lab, I tested different tools for checking computer performance.
I used HWLOC, STREAM, Roofline, Callgrind and LIKWID.
I also had some problems while running the tests, but I managed to complete them with a few changes.

## Example 1 - HWLOC

I installed HWLOC and used the lstopo command to see the hardware topology of my computer.

The results showed that my processor has 2 physical cores and 4 logical threads. I could also see the cache memory levels.

I took a screenshot of the hardware topology and saved it in the screenshots folder.

## Example 2 - STREAM

In this example, I used STREAM to test memory bandwidth.

I downloaded the STREAM project, compiled it and ran the test.

These are the results I got:

- Copy: 17847.2 MB/s
- Scale: 12391.5 MB/s
- Add: 13196.2 MB/s
- Triad: 12959.0 MB/s

The Copy test had the highest bandwidth.

I saved the results in stream_results.txt and took a screenshot.

## Example 3 - Roofline

In this example, I used the Empirical Roofline Toolkit to check CPU and memory performance.

I downloaded the toolkit, configured it and ran the test.

My results were:

- Peak performance: 60.5 GFLOPS/s
- L1 bandwidth: 335.6 GB/s
- L2 bandwidth: 210.3 GB/s
- L3 bandwidth: 126 GB/s
- DRAM bandwidth: 19.1 GB/s

I generated a Roofline graph and saved it as a PDF file.

I noticed that the cache memory had higher bandwidth than DRAM.

## Example 4 - CloverLeaf and Callgrind

In this example, I used Callgrind to analyze the CloverLeaf program.

First, I downloaded and compiled CloverLeaf.

When I tried to run Callgrind with the original input, the program was killed because it used too much memory.

To fix this problem, I changed the input file:
- Grid size: 256 x 256
- Number of steps: 10

After these changes, Callgrind finished successfully.

I opened the results in KCachegrind to see which functions used the most instructions.

The hydro function had the highest inclusive cost, around 97.64%.

I saved the Callgrind output file and took a screenshot of the results.

## Example 5 - LIKWID

In this example, I used LIKWID to measure the performance of CloverLeaf.

First, I installed LIKWID and checked the available performance groups.

I used the MEM group because MEM_DP was not available on my system.

At first, I had a permission problem, so I ran LIKWID with sudo.

The test finished, but some DRAM counters were not available. Because of this, the memory bandwidth was shown as 0 MB/s. This does not mean the real bandwidth was zero.

I saved the results in likwid_results.txt and took screenshots.

## Conclusion

In this lab, I learned how to use different tools to check CPU and memory performance.

STREAM helped me test memory bandwidth, and Roofline showed the difference between cache and DRAM performance.

I also learned how to use Callgrind and LIKWID to analyze a program.

Some tests did not work on the first try, but I managed to finish them after fixing the problems.
