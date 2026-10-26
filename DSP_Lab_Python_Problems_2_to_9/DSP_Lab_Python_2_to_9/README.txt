Digital Signal Processing Lab - Problems 02 through 09
======================================================
Each .py file is a separate stand-alone program converted from the C logic in
https://github.com/arsizan/Digital-Signal-Processing-Lab

No NumPy or third-party packages required. Python 3 only.
Open a terminal in this folder and run, for example:
    python Problem_02_Addition.py

Signals are entered as one sample per prompt (press Enter after each one).
Problem 05 uses a 1-based ORIGIN POSITION: for [1, 2, 3], origin 2 means
x[-1]=1, x[0]=2 and x[1]=3.
Problems 06 and 07 ask for the STARTING INDEX of signals (e.g. 0 or -1).
Problems 08 and 09 follow the original C code's N = max(length1, length2),
with zero padding. If your lab specifies another N, adjust y_size.
Problem 07 includes one additional full-output reconstruction check.
Problem 04 fixes the C source's incorrect integer format used for float samples.
