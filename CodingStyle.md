# Coding Style - CUHKSZLIB

## Name
- variable (function parameters and `protected` fields)

  Every first character in a word use uppercase, except first one. Local variables and `private` data fields are not limited as they are not included in document.

  e.g. `packetNum`, `batchSize`, `packetSizewarning`

- constant

  The same as variable.

- `#define` constant

  Every character use uppercase, use underline (remmber to `#undef` it after use if it is not intended to be exported).

  e.g. `MAX_DEGREE`, `BATSDECODER_MAXBATCH`, `PRECODE_RATE`

- type, struct and class

  Every first character in a word use uppercase.

  e.g. `SymbolType`, `KeyType`, `Class`

- function, method and method like macro

  Every first character in a word use uppercase, except first one

  e.g. `getBatch()`, `setDegDist()`


- file

    Class: `<Classname>.h` e.g. BigNum.h

    Package: `<package>.h`  e.g. math.h

    Free functions only: `<package_functions.h>` e.g. math_functions.h

    Source file: use `.cpp`

- header guard

    CUHKSZ_PACKAGE_FILENAME

    e.g. `CUHKSZ_MATH_FRACTION` for `math/Fraction.h`

- namespace

  `cuhksz` for **all** classes and functions

  Exception:
  use `cuhksz::private_` if you have to write some classes/functions in the headers that are not intended to be exported  (like class templates)

Please see the project code for detail, if you see some inconsistency in the source, feel free to post a pull request.
