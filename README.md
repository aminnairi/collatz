# collatz

Command line interface to compute & print the [Collatz conjecture](https://en.wikipedia.org/wiki/Collatz_conjecture).

## :book: Requirements

- UNIX-like operating system
- Superuser privileges
- [Git](https://git-scm.com/)
- [GCC](https://gcc.gnu.org/)
- [GNU C Library](https://www.gnu.org/software/libc/)
- [GNU/Make](https://www.gnu.org/software/make/)
- [Man](https://www.gnu.org/prep/standards/html_node/Man-Pages.html#Man-Pages)

## :sparkles: Initialization

```console
$ git clone https://github.com/aminnairi/collatz.git
$ cd collatz
```

## :hammer: Compilation

```console
$ make          # for the lazy ones
$ make compile  # alternative
```

## :arrow_down: Installation

```console
$ make install
```

> *Note: this will copy the program to the `/usr/local/bin` folder as well as copying the man page to the `/usr/local/man/man1` folder, requiring superuser access.*

## :runner: Run

```console
$ collatz 15
15 46 23 70 35 106 53 160 80 40 20 10 5 16 8 4 2 1
$ collatz 5
5 16 8 4 2 1
```

> *`collatz` only accepts one integer number greater or equal to one.*

## :thinking: Help

```console
$ man collatz
```

## :fire: Uninstallation

```console
$ make uninstall
```

> *Note: this will remove the copy of the program from the `/usr/local/bin` folder as well as removing the man page from the `/usr/local/man/man1` folder, requiring superuser access.*

## :recycle: Clean

```console
$ make clean
```

This will remove the `objects` folder.

## :wastebasket: Hard clean

```console
$ make mrproper
```

This will remove the `objects` & `binaries` folder.
