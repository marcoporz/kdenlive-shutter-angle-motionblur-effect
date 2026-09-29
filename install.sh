#!/usr/bin/env bash
# Build & install the shutterblur MLT module + Kdenlive effect.
# openSUSE deps (names to verify): cmake gcc-c++ pkgconf-pkg-config mlt-devel qt6-base-devel libX11-devel
set -euo pipefail
cd "$(dirname "$0")"
echo "MLT version: $(pkg-config --modversion mlt-framework-7)"
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build -j"$(nproc)"
sudo cmake --install build          # copies libmltshutterblur.so into MLT's module dir
mkdir -p "$HOME/.local/share/kdenlive/effects"
cp kdenlive/shutterblur.xml "$HOME/.local/share/kdenlive/effects/"
echo "Done. Restart Kdenlive and search for 'Motion Blur' in the effects list."
