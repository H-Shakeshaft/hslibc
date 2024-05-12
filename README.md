# HS LibC

A series of utility header and header-only file libraries I created to make my C
programming experience a little more enjoyable.

The libraries are implemented in the [STB Style](https://github.com/nothings/stb),
you can see the linked repository for details on what these are and why they are
why I chose to use this style.


## Usage 

In general, if you are inlcuding a header only file you can just include the header
in whichever file you need. To enable compilation however you must add the following
code to **EXACTLY ONE** source file:

```c
#define HSL_<LIB_NAME>_IMPLEMENTATION
#include "<LIB_NAME>"
```

## License

All files are distributed under a [dual license](./LICENCE), chooe whichever option
you prefer:

- MIT
- Public Domain


## Available Files

| File | Is Library | Category | LoC | Descsription | Notes |
| --- | --- | --- | --- | --- | -- |
|  [hls_types.h](./hslibc/hsl_type.h) | N | Utility |  | A series of declarations for different types, with the aim of providing some more decriptive capabilities in to the language. For example, a pre-C99 compatible rendition of fixed-width integers. | Assumess 64-bit support, won't work properly on 32-bit. |
