INCLUDE(FindPkgConfig)
PKG_CHECK_MODULES(PC_EVENTSIM eventsim)

FIND_PATH(
    EVENTSIM_INCLUDE_DIRS
    NAMES eventsim/api.h
    HINTS $ENV{EVENTSIM_DIR}/include
        ${PC_EVENTSIM_INCLUDEDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/include
          /usr/local/include
          /usr/include
)

FIND_LIBRARY(
    EVENTSIM_LIBRARIES
    NAMES gnuradio-eventsim
    HINTS $ENV{EVENTSIM_DIR}/lib
        ${PC_EVENTSIM_LIBDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/lib
          ${CMAKE_INSTALL_PREFIX}/lib64
          /usr/local/lib
          /usr/local/lib64
          /usr/lib
          /usr/lib64
)

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(EVENTSIM DEFAULT_MSG EVENTSIM_LIBRARIES EVENTSIM_INCLUDE_DIRS)
MARK_AS_ADVANCED(EVENTSIM_LIBRARIES EVENTSIM_INCLUDE_DIRS)

