with import <nixpkgs> {};
pkgs.mkShell {
  # nativeBuildInputs is usually what you want -- tools you need to run
  nativeBuildInputs = [
    # executables
    cmake
    clang-tools
    gcc
    clang_15
  ];
}
