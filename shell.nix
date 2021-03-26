with import <nixos> {};

stdenv.mkDerivation {
  name = "cpp-benchmark-shell";
  buildInputs = [
    python38Packages.jinja2
    python38Packages.jsonschema
  ];
}
