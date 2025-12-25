// Populated by CMake; not installed

// if we're a DFSG build, we leave out references to certain demos
/* #undef DFSG_BUILD */

// if we're an ASAN build, we don't use sigaltstack() ourselves
/* #undef USE_ASAN */
#define USE_DEFLATE
/* #undef USE_GPM */
/* #undef USE_QRCODEGEN */
// exclusive with USE_OIIO
/* #undef USE_FFMPEG */
// exclusive with USE_FFMPEG
/* #undef USE_OIIO */
// set if either USE_FFMPEG || USE_OIIO
#if defined(USE_FFMPEG) || defined(USE_OIIO)
#define NOTCURSES_USE_MULTIMEDIA
#endif
#define NOTCURSES_SHARE "C:/Program Files (x86)/MySSH/share/notcurses"
