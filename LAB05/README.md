# LAB 05 - Parallel Algorithms and Patterns

## About the lab

In this lab, I tested different methods for calculating the sum of numbers.

The goal was to compare the accuracy and execution time of each method and see how floating-point calculations can affect the final result.

## Methods

I tested five methods:

**1. Standard Double**

This method was already provided in the professor's code. It uses a simple loop to add all numbers.

**2. Long Double**

I used `long double` instead of `double` for the sum. This gives better precision and reduces rounding errors.

**3. Pairwise Summation**

This method divides the array into two parts and calculates the sum of each part. It repeats this until the parts contain only one element.

**4. Kahan Summation**

This method uses an extra variable to keep track of rounding errors while adding numbers.

**5. Knuth Summation**

This method uses the TwoSum algorithm to calculate rounding errors. I used an extra variable to store the corrections.

## Testing

I used the professor's test program and added the other methods.

I tested array sizes from 2^10 to 2^27.

For each method, I checked the error and execution time.

## Results

These are my results for the largest array (2^27 elements):

| Method | Error | Runtime (s) |
|---|---:|---:|
| Standard Double | -0.01333 | 0.423339 |
| Long Double | -8.792e-07 | 0.575014 |
| Pairwise | 0 | 1.160235 |
| Kahan | 0 | 1.293499 |
| Knuth | 0 | 0.994536 |

From these results, I can see that Standard Double was the fastest, but it also had the biggest error.

Long Double had a much smaller error.

Pairwise, Kahan and Knuth gave the same result as the reference sum in this test.

The reference sum is calculated using `double`, so an error of zero does not always mean the result is completely exact.

## Floating-Point Problems

Floating-point numbers have limited precision, so the order of addition can change the result.

For example, `(a + b) + c` can give a slightly different result than `a + (b + c)`.

In parallel programming, different processors can add numbers in different orders. Because of this, the final sum may not always be the same.

Using methods like Pairwise, Kahan and Knuth can help reduce these errors.

## How to Run

To compile the program:

```bash
make
```

To run the program:

```bash
./sum_test
```

To save the results:

```bash
./sum_test > results.txt
```

## Google Sheets

I also added the results to Google Sheets.

[My results](https://docs.google.com/spreadsheets/d/1m4f9BzZrSnKFImqS9N8PUo888jXFkUVliJAVwAwiUP4/edit?usp=sharing)

All test results are also saved in `results.txt`.

## Conclusion

In this lab, I learned that different summation methods can give different results.

Standard Double was the fastest in my largest test, but it had the biggest error.

The other methods improved the accuracy, but they needed more time.

I also learned that the order of adding numbers is important, especially in parallel programming.
