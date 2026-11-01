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
          pname = "iron";
          version = "2.0.0";

          src = ./.;

          nativeBuildInputs = with pkgs; [ muon samurai pkg-config ];

          configurePhase = ''
            muon meson setup build --prefix=$out
          '';

          buildPhase = ''
            samu -C build
          '';

          installPhase = ''
            samu -C build install
            
            mkdir -p $out/lib/pkgconfig
            cp libiron.pc $out/lib/pkgconfig/
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
