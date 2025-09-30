![kaguya-banner](https://github.com/ayumi-aiko/banners/blob/main/kaguya.banner.png?raw=true)

# Kaguya
A small fun repository which aims to write the popular "GNU" coreutils using C. 

## Overview

**Kaguya** is a small project that tries to write essential UNIX utilities, starting with [cat](https://www.gnu.org/software/coreutils/cat).
The goal is to:

* Practice low-level C programming more
* Learn about file descriptors, standard I/O, and system calls
* Recreate the behavior of GNU tools from scratch

---

## Current Utilities
* `cat` — with support for options like:

  * `-n` / `--number`: Append line number to all output lines.
  * `-s` / `--squeeze-blank`: Suppress repeated empty output lines.

## To Build:

Clone the repo:

```bash
git clone https://github.com/ayumi-aiko/Kaguya.git
cd Kaguya
```

Build with **make**:

```bash
make <target>
```

Available targets:

* `cat` → builds the `cat` utility

## Usage (cat)
- This basically works like the `cat` found in GNU coreutils but this one works differently.

## Roadmap
* [x] Implement `cat`
* [ ] Add more utilities (`echo`, `head`, `tail`, `ls`, …)

## This project is inspired by:
* **GNU coreutils**, the foundation of UNIX/Linux command line.