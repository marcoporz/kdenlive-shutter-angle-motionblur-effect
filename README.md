# kdenlive-shutterblur

A **motion blur / shutter angle** effect for [Kdenlive](https://kdenlive.org),
fixed at a physically-based **180° shutter** (the classic "film" look).

Animate position, scale, rotation or opacity with keyframes (like the built-in
Transform effect) and this effect leaves a natural motion trail behind fast
movement — instead of the strobing/juddering you get with plain keyframes.

> ⚠️ **Status: early / unofficial.** This is a community packaging of an
> **unmerged, draft** MLT pull request (see [CREDITS.md](CREDITS.md)). It
> works, but expect rough edges: 8-bit only, no anchor-point option, requires
> building from source. Not affiliated with the MLT or Kdenlive projects.

## How it works

Real cameras expose each frame for a fraction of the frame time, called the
*shutter angle*. At 180°, exposure = half a frame. This effect approximates
that by rendering each frame as an average of several sub-frame positions
along the clip's actual keyframed motion (translation, scale, **and**
rotation) — unlike Kdenlive's existing "Directional Blur", which only blurs
in one fixed direction per frame.

## Requirements

- Linux, with **Kdenlive using your system's MLT** (not the Flatpak or
  AppImage build — those bundle their own MLT and won't see this module).
- MLT **>= 7.38** (development headers).
- Qt6 development headers (Gui + Widgets).
- A C/C++ toolchain and CMake.

Check your MLT version:
```bash
pkg-config --modversion mlt-framework-7
```

## Install

### openSUSE (Slowroll / Tumbleweed)
```bash
sudo zypper install libmlt-devel qt6-base-devel libX11-devel cmake gcc-c++ pkgconf-pkg-config
```

### Fedora
```bash
sudo dnf install mlt-devel qt6-qtbase-devel libX11-devel cmake gcc-c++ pkgconf-pkg-config
```

### Debian / Ubuntu
```bash
sudo apt install libmlt-dev qt6-base-dev libx11-dev cmake g++ pkg-config
```

### Arch
```bash
sudo pacman -S mlt qt6-base libx11 cmake gcc pkgconf
```

*(Package names may drift over time/distro version — if a name above is
wrong for your system, search your package manager for `mlt` and
`qt6-base` "devel"/"dev" packages and open an issue so this list can be
fixed.)*

### Build & install (all distros)
```bash
git clone https://github.com/marcoporz/kdenlive-shutterblur.git
cd kdenlive-shutterblur
./install.sh
```

`install.sh` runs `cmake` + `cmake --build`, installs the compiled module
into MLT's module directory (needs `sudo`), and copies the Kdenlive effect
XML into `~/.local/share/kdenlive/effects/`.

**Fully restart Kdenlive** afterwards (it only scans custom effects on
startup).

### Verify before opening Kdenlive (optional but recommended)
```bash
melt -query filters 2>/dev/null | grep shutterblur
```
Should print `- shutterblur`. If it doesn't, the module isn't in MLT's
search path — open an issue with your distro and MLT version.

## Usage

1. Add a clip or image to the timeline.
2. Open the Effects panel, search for **"Motion"** or **"Blur"**.
3. Apply **"Transform + Motion Blur (180°)"**.
4. Animate the **Rectangle** (position/size) and/or **Rotation** parameters
   with at least two keyframes, same as you would with the normal Transform
   effect.

## Uninstall
```bash
sudo rm /usr/lib64/mlt-7/libmltshutterblur.so   # path may differ, see install.sh output
sudo rm -rf /usr/share/mlt-7/shutterblur
rm ~/.local/share/kdenlive/effects/shutterblur.xml
```

## Known limitations

- 8-bit color only.
- No anchor-point / pivot control for rotation.
- No blend-mode options (uses simple alpha compositing, like `qtblend`).
- Not tested at very high resolutions or very long clips.
- Motion is estimated from previous→current keyframe interpolation, so very
  sharp eased/non-linear motion between keyframes may blur slightly
  differently than a "true" per-subframe render.

## Contributing / upstream

The real fix belongs upstream. If you can help test, benchmark, or improve
the filter, consider contributing directly to
[mltframework/mlt#1301](https://github.com/mltframework/mlt/pull/1301) —
that's the canonical, maintained version. This repo exists only as a
stopgap until something like it lands in an official MLT/Kdenlive release.

## License

LGPL-2.1-or-later, same as MLT. See [LICENSE](LICENSE) and
[CREDITS.md](CREDITS.md) for authorship details.
