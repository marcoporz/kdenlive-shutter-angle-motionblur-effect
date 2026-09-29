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
- Ships it with a default of a **fixed 180° shutter angle**, no user-exposed
  shutter/sample controls, to keep the Kdenlive effect simple.
- Adds a Kdenlive effect XML (`kdenlive/shutterblur.xml`) so it shows up in
  Kdenlive's effect list, modeled on Kdenlive's own `qtblend.xml`.
- Adds a build/install script and this documentation.

If PR #1301 is merged into MLT (possibly folded into `qtblend`, per the
maintainer's suggestion), this repository will likely become unnecessary and
will be archived pointing users to the official release.

**Please star/comment on the upstream PR** if you find this useful — the real
credit and the real work belongs there.
