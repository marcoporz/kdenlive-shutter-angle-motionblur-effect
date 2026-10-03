# Credits

**The motion blur filter itself was not written by this repository's maintainer.**
It comes from an open, still-unmerged pull request against the MLT framework:

- Author: **Jannis (RocketJannis)**
- Upstream PR: https://github.com/mltframework/mlt/pull/1301
- File: `src/modules/qt/filter_transformblur.cpp` (and its `.yml` metadata)
- Copyright (C) 2026 Meltytech, LLC — license LGPL-2.1-or-later (see `LICENSE`)

This repository simply:
- Extracts that one filter into a small, standalone MLT module (`libmltshutterblur.so`)
  so it can be built and installed without recompiling all of MLT, while the PR
  is still in review.
- Exposes the filter's **Shutter Angle** (default 180°, 0 = off) and
  **Blur Quality** (sample count) parameters as sliders in the Kdenlive
  effect UI.
- Adds a **rotation pivot** (`pivot_x`/`pivot_y`) on top of the upstream
  filter, so rotation can spin around a corner or edge instead of always
  the rectangle's center. This part is NOT in the original PR #1301 — it's
  a local addition on top of RocketJannis's code, kept in the same file for
  simplicity.
- Adds a Kdenlive effect XML (`kdenlive/shutterblur.xml`) so it shows up in
  Kdenlive's effect list, modeled on Kdenlive's own `qtblend.xml`.
- Adds a build/install script and this documentation.

If PR #1301 is merged into MLT (possibly folded into `qtblend`, per the
maintainer's suggestion), this repository will likely become unnecessary and
will be archived pointing users to the official release.

**Please star/comment on the upstream PR** if you find this useful — the real
credit and the real work belongs there.
