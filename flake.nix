{
  description = "iron - simple logger library for C";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";
    flake-utils.url = "github:numtide/flake-utils";
  };

  outputs = { self, nixpkgs, flake-utils }:
    flake-utils.lib.eachDefaultSystem (system:
      let
        pkgs = import nixpkgs { inherit system; };

        app = pkgs.stdenv.mkDerivation {
          pname = "ironLib";
          version = "1.0.0";

          src = ./.;

          buildInputs = with pkgs; [
            tinycc
            gnumake
          ];

          buildPhase = ''
            make CC=tcc
          '';

          installPhase = ''
            mkdir -p $out/lib
            cp libiron.so $out/lib/
          '';
        };

      in {
        packages.default = app;

        devShells.default = pkgs.mkShell {
          buildInputs = with pkgs; [
            tinycc
            gnumake
          ];

        };
      }
    );
}
