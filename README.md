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
 - **soa**: A struct of arrays approach

## Results

### GCC 12

#### Single-threaded

```text
-------------------------------------------------------------------------------------
Benchmark                                           Time             CPU   Iterations
-------------------------------------------------------------------------------------
SoAShapesFixture/TotalAreaSoA                    24.8 ms         24.8 ms           42
OOPShapesFixture/TotalAreaVTBL                    203 ms          203 ms            3
FunShapesFixture/TotalAreaFunc                    102 ms          102 ms            7
OldShapesFixture/TotalAreaSwitch                  111 ms          111 ms            6
CleanerOOPShapesFixture/TotalAreaVTBLClean        208 ms          208 ms            4
```

#### Parallel

```text
-------------------------------------------------------------------------------------
Benchmark                                           Time             CPU   Iterations
-------------------------------------------------------------------------------------
SoAShapesFixture/TotalAreaSoA                    6.22 ms         6.22 ms          100
OOPShapesFixture/TotalAreaVTBL                   10.8 ms         10.7 ms           52
FunShapesFixture/TotalAreaFunc                   4.29 ms         4.29 ms          161
OldShapesFixture/TotalAreaSwitch                 4.87 ms         4.87 ms          137
CleanerOOPShapesFixture/TotalAreaVTBLClean       11.0 ms         11.0 ms           57
```

### Clang 15

#### Single-threaded

```text
-------------------------------------------------------------------------------------
Benchmark                                           Time             CPU   Iterations
-------------------------------------------------------------------------------------
CleanerOOPShapesFixture/TotalAreaVTBLClean        220 ms          220 ms            3
OldShapesFixture/TotalAreaSwitch                  135 ms          135 ms            5
FunShapesFixture/TotalAreaFunc                    134 ms          134 ms            5
OOPShapesFixture/TotalAreaVTBL                    209 ms          209 ms            3
SoAShapesFixture/TotalAreaSoA                    23.3 ms         23.3 ms           45
```

 #### Parallel

```text
-------------------------------------------------------------------------------------
Benchmark                                           Time             CPU   Iterations
-------------------------------------------------------------------------------------
CleanerOOPShapesFixture/TotalAreaVTBLClean       11.5 ms         11.5 ms           61
OldShapesFixture/TotalAreaSwitch                 4.89 ms         4.89 ms          114
FunShapesFixture/TotalAreaFunc                   4.14 ms         4.13 ms          162
OOPShapesFixture/TotalAreaVTBL                   14.3 ms         14.3 ms           50
SoAShapesFixture/TotalAreaSoA                    6.55 ms         6.55 ms          100
```

## Conclusions

Virtual tables are a red herring. It's mostly about how your data is laid out in memory.  
The difference between the OOP approaches on one side and the Imperative and Functional approches on the other, is that the OOP codes iterate over a table of heap-allocated pointers to structs, while the Imperative and Functional iterate over an array of structs.

Worrying about OOP vs. Imperative vs. Functional makes us miss the forest for tree: it is much more important to have your data laid out in Structs of Arrays to take advantage of the prefetcher, and to avoid branching.
