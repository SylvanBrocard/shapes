with import <nixpkgs> {};
pkgs.mkShell {
  # nativeBuildInputs is usually what you want -- tools you need to run
  nativeBuildInputs = [
    # executables
    cmake
    ninja
    clang-tools
    gcc
    llvmPackages_15.bintools
    llvmPackages_15.openmp
    llvmPackages_15.clang
    tbb
  ];
}
