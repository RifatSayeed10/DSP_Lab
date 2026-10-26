DSP Lab C Programs | Syllabus Problems 02-09

These are independently written C programs following the same fundamental
algorithms as the GitHub examples and the corresponding Python files.
They are NOT byte-for-byte copies of the original GitHub repository.

Problem 02 - Problem_02_Addition.c            (sample-wise addition)
Problem 03 - Problem_03_Multiplication.c      (sample-wise multiplication)
Problem 04 - Problem_04_Amplitude_Scaling.c   (amplitude scaling)
Problem 05 - Problem_05_Even_Odd.c            (even/odd decomposition)
Problem 06 - Problem_06_Linear_Convolution.c  (linear convolution)
Problem 07 - Problem_07_Deconvolution.c       (linear deconvolution)
Problem 08 - Problem_08_Circular_Circle.c     (circular, circle method)
Problem 09 - Problem_09_Circular_Matrix.c     (circular, matrix method)

Compile: gcc -std=c11 -Wall -Wextra Problem_02_Addition.c -o addition
Run:     ./addition    (Windows: addition.exe)

Note: These programs limit each input sequence to at most 100 samples.
The C and Python versions use the same sample-index assumptions as shown
in their prompts. The amplitude scaling print bug was corrected.
For the source author's original C files, see:
https://github.com/arsizan/Digital-Signal-Processing-Lab
