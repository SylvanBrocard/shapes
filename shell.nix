with import <nixpkgs> {};
pkgs.mkShell {
  # nativeBuildInputs is usually what you want -- tools you need to run
  nativeBuildInputs = [
    # executables
    cmake
    ninja
    clang-tools
    gcc
    llvmPackages.bintools
    llvmPackages.openmp
    llvmPackages.clang
  ];
}
