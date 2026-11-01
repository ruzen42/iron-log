{
  description = "iron - stupid logger library for C";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";
    flake-utils.url = "github:numtide/flake-utils";
  };

  outputs = { self, nixpkgs, flake-utils }:
    flake-utils.lib.eachDefaultSystem (system:
      let
        pkgs = import nixpkgs { inherit system; };

        app = pkgs.stdenv.mkDerivation {
          pname = "libiron";
          version = "2.0.0";

          src = ./.;

          buildInputs = with pkgs; [ muon samurai gcc pkg-config];

          buildPhase = ''
            make CC=gcc CFLAGS="-Os -flto"
          '';

          installPhase = ''
            mkdir -p $out/lib $out/include/{iron,pkg-config}
            cp libiron.so $out/lib/

            cp include/iron/{logger.h,logger_file.h} $out/include/iron
            cp libiron.pc $out/include/pkg-config/
          '';
        };

      in {
        packages.default = app;

        devShells.default = pkgs.mkShell {
          buildInputs = with pkgs; [
            gcc 
            muon 
            samurai
            pkg-config
          ];

        };
      }
    );
}
