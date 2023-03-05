# Sum of shapes benchmark

This experiment has been prompted by Casey Muratori's video on the inefficiency of clean code.

Its purpose is to investigate the effect of various C++ syntaxes and how they are treated by the compiler.

## Use

Clone the project recursively.

Use `nix-shell` if you have Nix installed to set up the compilers environment.

Build with cmake. The files are `shapes_benchmark` and `shapes_benchmark_parallel` in `build/src`.

## Approaches

 - **oop**: The original "clean code" example showed in the video
 - **cstyle**: The first implementation of C-style code showed in the vide
 - **cleaneroop**: A modernized version of the OOP code
 - **functional**: A functional approach using variants

## Results

### GCC 12

#### Single-threaded

```text
-------------------------------------------------------------------------------------
Benchmark                                           Time             CPU   Iterations
-------------------------------------------------------------------------------------
OOPShapesFixture/TotalAreaVTBL                    204 ms          204 ms            3
FunShapesFixture/TotalAreaFunc                    103 ms          103 ms            7
OldShapesFixture/TotalAreaSwitch                  107 ms          107 ms            7
CleanerOOPShapesFixture/TotalAreaVTBLClean        209 ms          209 ms            4
```

#### Parallel

```text
-------------------------------------------------------------------------------------
Benchmark                                           Time             CPU   Iterations
-------------------------------------------------------------------------------------
OOPShapesFixture/TotalAreaVTBL                   15.8 ms         15.7 ms           34
FunShapesFixture/TotalAreaFunc                   4.39 ms         4.39 ms          159
OldShapesFixture/TotalAreaSwitch                 4.77 ms         4.77 ms          105
CleanerOOPShapesFixture/TotalAreaVTBLClean       17.3 ms         17.3 ms           37
```

### Clang 15

#### Single-threaded

```text
-------------------------------------------------------------------------------------
Benchmark                                           Time             CPU   Iterations
-------------------------------------------------------------------------------------
CleanerOOPShapesFixture/TotalAreaVTBLClean        221 ms          221 ms            3
OldShapesFixture/TotalAreaSwitch                  134 ms          134 ms            5
FunShapesFixture/TotalAreaFunc                    133 ms          133 ms            5
OOPShapesFixture/TotalAreaVTBL                    210 ms          210 ms            3
```

 #### Parallel

```text
-------------------------------------------------------------------------------------
Benchmark                                           Time             CPU   Iterations
-------------------------------------------------------------------------------------
CleanerOOPShapesFixture/TotalAreaVTBLClean       16.6 ms         16.6 ms           33
OldShapesFixture/TotalAreaSwitch                 5.00 ms         5.00 ms          112
FunShapesFixture/TotalAreaFunc                   4.66 ms         4.66 ms          118
OOPShapesFixture/TotalAreaVTBL                   10.2 ms         10.2 ms           64
```
