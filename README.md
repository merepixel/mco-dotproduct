# LBYARCH x86 to C Interface Programming Project

## Program Specifications
Write the kernel in (1) C program and (2) an x86-64 assembly language. The kernel is to perform a dot product between vector A and vector B and place the result in sdot.
- Required to use functional scalar SIMD registers
- Required to use functional scalar SIMD floating-point instructions
Input: Scalar variable n (integer) contains the length of the vector; Vectors A and B are both double-precision float. Scalar sdot is a double-precision float.

Process: $$sdot = \sum_{i=1}^n a_i b_i = a_1 b_1 + a_2 b_2 + ... + a_n b_n$$
Output: store the result in memory location sdot. Display the result for all versions of the kernel (i.e., C and x86-64).

## How to run the program
1. Clone the repo
2. Open the .sln file in Visual Studio
3. Run the code with the appropriate mode (debug/release)
4. Enter your desired array size (limited to 2^x)
5. Wait for the code to finish running

## Comparison and Analysis of Execution times

In Debug Mode, Assembly Language (ASM) runs significantly faster than C, with speed advantages of around 48.57%, 50.47%, and 53.89% across array sizes (20, 24, 30). ASM's low-level nature enables direct optimization within the code, while C's Debug Mode disables optimizations and adds overhead for debugging features, resulting in slower performance.

In Release Mode, the outputs are closer to each other...

| Debug Mode | $2^{20}$ | $2^{24}$ | $2^{30}$ |
| --- | --- | --- | --- |
| C | 2.33 | 38.77 | 25640.73 |
| ASM | 1.20 | 19.20 | 11824.07 |

| Release Mode | $2^{20}$ | $2^{24}$ | $2^{30}$ |
| --- | --- | --- | --- |
| C | 1.9 | 21.97 | # |
| ASM | 2.63 | 27.27 | # |

## Screenshots with Correctness Checking
We verified the correctness of the C kernel by ensuring consistent output across all runs. Similarly, for the ASM kernel, we compared each output to the corresponding C kernel output to ensure accuracy.

### Debug Mode Outputs

#### $2^{20}$
![Screenshot Debug 20](/imgs/Debug20.PNG)

#### $2^{24}$
![Screenshot Debug 24](/imgs/Debug24.PNG)

#### $2^{30}$
![Screenshot Debug 30](/imgs/Debug30.PNG)


### Release Mode Outputs

#### $2^{20}$
![Screenshot Debug 20](/imgs/Release20.png)

#### $2^{24}$
![Screenshot Debug 24](/imgs/Release24.png)

#### $2^{30}$
![Screenshot Debug 30](/imgs/Release30.PNG)


