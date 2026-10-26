DSP Lab — C++ Programs (Syllabus Problems 02–09)

Converted from the C files in DSP_Lab_C_Problems_2_to_9.zip.
The original loop-based DSP algorithms, sample-index assumptions, input prompts,
zero-padding, and calculations are preserved. C stdio was converted to
C++ cin/cout, and fixed arrays were converted to std::vector.
No signal-processing libraries or ready-made convolution functions are needed.

02  Problem_02_Addition.cpp          Sample-wise addition
03  Problem_03_Multiplication.cpp    Sample-wise multiplication
04  Problem_04_Amplitude_Scaling.cpp Amplitude scaling
05  Problem_05_Even_Odd.cpp         Even/Odd signal decomposition
06  Problem_06_Linear_Convolution.cpp Linear convolution
07  Problem_07_Deconvolution.cpp    Linear deconvolution + verification
08  Problem_08_Circular_Circle.cpp  Circular convolution — Circle method
09  Problem_09_Circular_Matrix.cpp  Circular convolution — Matrix method

Compile example (g++):
  g++ -std=c++17 -Wall -Wextra Problem_02_Addition.cpp -o addition
Run on Linux/macOS: ./addition
Run on Windows: addition.exe

Input sample limits remain 1..100 per signal.
The circular-convolution length N is the larger input signal length, just as
in the provided C program. The two input sequences are treated as starting
at the same sample index in addition and multiplication.
