
// This is a generated file. Do not edit!

#ifndef FORMA_COMPILER_DETECTION_H
#define FORMA_COMPILER_DETECTION_H

#ifdef __cplusplus
# define FORMA_COMPILER_IS_Comeau 0
# define FORMA_COMPILER_IS_Intel 0
# define FORMA_COMPILER_IS_PathScale 0
# define FORMA_COMPILER_IS_Embarcadero 0
# define FORMA_COMPILER_IS_Borland 0
# define FORMA_COMPILER_IS_Watcom 0
# define FORMA_COMPILER_IS_OpenWatcom 0
# define FORMA_COMPILER_IS_SunPro 0
# define FORMA_COMPILER_IS_HP 0
# define FORMA_COMPILER_IS_Compaq 0
# define FORMA_COMPILER_IS_zOS 0
# define FORMA_COMPILER_IS_XLClang 0
# define FORMA_COMPILER_IS_XL 0
# define FORMA_COMPILER_IS_VisualAge 0
# define FORMA_COMPILER_IS_PGI 0
# define FORMA_COMPILER_IS_Cray 0
# define FORMA_COMPILER_IS_TI 0
# define FORMA_COMPILER_IS_Fujitsu 0
# define FORMA_COMPILER_IS_GHS 0
# define FORMA_COMPILER_IS_SCO 0
# define FORMA_COMPILER_IS_ARMCC 0
# define FORMA_COMPILER_IS_AppleClang 0
# define FORMA_COMPILER_IS_ARMClang 0
# define FORMA_COMPILER_IS_Clang 0
# define FORMA_COMPILER_IS_GNU 0
# define FORMA_COMPILER_IS_MSVC 0
# define FORMA_COMPILER_IS_ADSP 0
# define FORMA_COMPILER_IS_IAR 0
# define FORMA_COMPILER_IS_MIPSpro 0

#if defined(__COMO__)
# undef FORMA_COMPILER_IS_Comeau
# define FORMA_COMPILER_IS_Comeau 1

#elif defined(__INTEL_COMPILER) || defined(__ICC)
# undef FORMA_COMPILER_IS_Intel
# define FORMA_COMPILER_IS_Intel 1

#elif defined(__PATHCC__)
# undef FORMA_COMPILER_IS_PathScale
# define FORMA_COMPILER_IS_PathScale 1

#elif defined(__BORLANDC__) && defined(__CODEGEARC_VERSION__)
# undef FORMA_COMPILER_IS_Embarcadero
# define FORMA_COMPILER_IS_Embarcadero 1

#elif defined(__BORLANDC__)
# undef FORMA_COMPILER_IS_Borland
# define FORMA_COMPILER_IS_Borland 1

#elif defined(__WATCOMC__) && __WATCOMC__ < 1200
# undef FORMA_COMPILER_IS_Watcom
# define FORMA_COMPILER_IS_Watcom 1

#elif defined(__WATCOMC__)
# undef FORMA_COMPILER_IS_OpenWatcom
# define FORMA_COMPILER_IS_OpenWatcom 1

#elif defined(__SUNPRO_CC)
# undef FORMA_COMPILER_IS_SunPro
# define FORMA_COMPILER_IS_SunPro 1

#elif defined(__HP_aCC)
# undef FORMA_COMPILER_IS_HP
# define FORMA_COMPILER_IS_HP 1

#elif defined(__DECCXX)
# undef FORMA_COMPILER_IS_Compaq
# define FORMA_COMPILER_IS_Compaq 1

#elif defined(__IBMCPP__) && defined(__COMPILER_VER__)
# undef FORMA_COMPILER_IS_zOS
# define FORMA_COMPILER_IS_zOS 1

#elif defined(__ibmxl__) && defined(__clang__)
# undef FORMA_COMPILER_IS_XLClang
# define FORMA_COMPILER_IS_XLClang 1

#elif defined(__IBMCPP__) && !defined(__COMPILER_VER__) && __IBMCPP__ >= 800
# undef FORMA_COMPILER_IS_XL
# define FORMA_COMPILER_IS_XL 1

#elif defined(__IBMCPP__) && !defined(__COMPILER_VER__) && __IBMCPP__ < 800
# undef FORMA_COMPILER_IS_VisualAge
# define FORMA_COMPILER_IS_VisualAge 1

#elif defined(__PGI)
# undef FORMA_COMPILER_IS_PGI
# define FORMA_COMPILER_IS_PGI 1

#elif defined(_CRAYC)
# undef FORMA_COMPILER_IS_Cray
# define FORMA_COMPILER_IS_Cray 1

#elif defined(__TI_COMPILER_VERSION__)
# undef FORMA_COMPILER_IS_TI
# define FORMA_COMPILER_IS_TI 1

#elif defined(__FUJITSU) || defined(__FCC_VERSION) || defined(__fcc_version)
# undef FORMA_COMPILER_IS_Fujitsu
# define FORMA_COMPILER_IS_Fujitsu 1

#elif defined(__ghs__)
# undef FORMA_COMPILER_IS_GHS
# define FORMA_COMPILER_IS_GHS 1

#elif defined(__SCO_VERSION__)
# undef FORMA_COMPILER_IS_SCO
# define FORMA_COMPILER_IS_SCO 1

#elif defined(__ARMCC_VERSION) && !defined(__clang__)
# undef FORMA_COMPILER_IS_ARMCC
# define FORMA_COMPILER_IS_ARMCC 1

#elif defined(__clang__) && defined(__apple_build_version__)
# undef FORMA_COMPILER_IS_AppleClang
# define FORMA_COMPILER_IS_AppleClang 1

#elif defined(__clang__) && defined(__ARMCOMPILER_VERSION)
# undef FORMA_COMPILER_IS_ARMClang
# define FORMA_COMPILER_IS_ARMClang 1

#elif defined(__clang__)
# undef FORMA_COMPILER_IS_Clang
# define FORMA_COMPILER_IS_Clang 1

#elif defined(__GNUC__) || defined(__GNUG__)
# undef FORMA_COMPILER_IS_GNU
# define FORMA_COMPILER_IS_GNU 1

#elif defined(_MSC_VER)
# undef FORMA_COMPILER_IS_MSVC
# define FORMA_COMPILER_IS_MSVC 1

#elif defined(__VISUALDSPVERSION__) || defined(__ADSPBLACKFIN__) || defined(__ADSPTS__) || defined(__ADSP21000__)
# undef FORMA_COMPILER_IS_ADSP
# define FORMA_COMPILER_IS_ADSP 1

#elif defined(__IAR_SYSTEMS_ICC__) || defined(__IAR_SYSTEMS_ICC)
# undef FORMA_COMPILER_IS_IAR
# define FORMA_COMPILER_IS_IAR 1


#endif

#  if FORMA_COMPILER_IS_Clang

#    if !(((__clang_major__ * 100) + __clang_minor__) >= 301)
#      error Unsupported compiler version
#    endif

# define FORMA_COMPILER_VERSION_MAJOR (__clang_major__)
# define FORMA_COMPILER_VERSION_MINOR (__clang_minor__)
# define FORMA_COMPILER_VERSION_PATCH (__clang_patchlevel__)
# if defined(_MSC_VER)
   /* _MSC_VER = VVRR */
#  define FORMA_SIMULATE_VERSION_MAJOR (_MSC_VER / 100)
#  define FORMA_SIMULATE_VERSION_MINOR (_MSC_VER % 100)
# endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 301 && __has_feature(cxx_constexpr)
#      define FORMA_COMPILER_CXX_CONSTEXPR 1
#    else
#      define FORMA_COMPILER_CXX_CONSTEXPR 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 301 && __has_feature(cxx_noexcept)
#      define FORMA_COMPILER_CXX_NOEXCEPT 1
#    else
#      define FORMA_COMPILER_CXX_NOEXCEPT 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 304 && __cplusplus > 201103L
#      define FORMA_COMPILER_CXX_ATTRIBUTE_DEPRECATED 1
#    else
#      define FORMA_COMPILER_CXX_ATTRIBUTE_DEPRECATED 0
#    endif

#  elif FORMA_COMPILER_IS_GNU

#    if !((__GNUC__ * 100 + __GNUC_MINOR__) >= 404)
#      error Unsupported compiler version
#    endif

# if defined(__GNUC__)
#  define FORMA_COMPILER_VERSION_MAJOR (__GNUC__)
# else
#  define FORMA_COMPILER_VERSION_MAJOR (__GNUG__)
# endif
# if defined(__GNUC_MINOR__)
#  define FORMA_COMPILER_VERSION_MINOR (__GNUC_MINOR__)
# endif
# if defined(__GNUC_PATCHLEVEL__)
#  define FORMA_COMPILER_VERSION_PATCH (__GNUC_PATCHLEVEL__)
# endif

#    if (__GNUC__ * 100 + __GNUC_MINOR__) >= 406 && (__cplusplus >= 201103L || (defined(__GXX_EXPERIMENTAL_CXX0X__) && __GXX_EXPERIMENTAL_CXX0X__))
#      define FORMA_COMPILER_CXX_CONSTEXPR 1
#    else
#      define FORMA_COMPILER_CXX_CONSTEXPR 0
#    endif

#    if (__GNUC__ * 100 + __GNUC_MINOR__) >= 406 && (__cplusplus >= 201103L || (defined(__GXX_EXPERIMENTAL_CXX0X__) && __GXX_EXPERIMENTAL_CXX0X__))
#      define FORMA_COMPILER_CXX_NOEXCEPT 1
#    else
#      define FORMA_COMPILER_CXX_NOEXCEPT 0
#    endif

#    if (__GNUC__ * 100 + __GNUC_MINOR__) >= 409 && __cplusplus > 201103L
#      define FORMA_COMPILER_CXX_ATTRIBUTE_DEPRECATED 1
#    else
#      define FORMA_COMPILER_CXX_ATTRIBUTE_DEPRECATED 0
#    endif

#  elif FORMA_COMPILER_IS_Intel

#    if !(__INTEL_COMPILER >= 1210)
#      error Unsupported compiler version
#    endif

  /* __INTEL_COMPILER = VRP */
# define FORMA_COMPILER_VERSION_MAJOR (__INTEL_COMPILER/100)
# define FORMA_COMPILER_VERSION_MINOR (__INTEL_COMPILER/10 % 10)
# if defined(__INTEL_COMPILER_UPDATE)
#  define FORMA_COMPILER_VERSION_PATCH (__INTEL_COMPILER_UPDATE)
# else
#  define FORMA_COMPILER_VERSION_PATCH (__INTEL_COMPILER   % 10)
# endif
# if defined(__INTEL_COMPILER_BUILD_DATE)
  /* __INTEL_COMPILER_BUILD_DATE = YYYYMMDD */
#  define FORMA_COMPILER_VERSION_TWEAK (__INTEL_COMPILER_BUILD_DATE)
# endif
# if defined(_MSC_VER)
   /* _MSC_VER = VVRR */
#  define FORMA_SIMULATE_VERSION_MAJOR (_MSC_VER / 100)
#  define FORMA_SIMULATE_VERSION_MINOR (_MSC_VER % 100)
# endif
# if defined(__GNUC__)
#  define FORMA_SIMULATE_VERSION_MAJOR (__GNUC__)
# elif defined(__GNUG__)
#  define FORMA_SIMULATE_VERSION_MAJOR (__GNUG__)
# endif
# if defined(__GNUC_MINOR__)
#  define FORMA_SIMULATE_VERSION_MINOR (__GNUC_MINOR__)
# endif
# if defined(__GNUC_PATCHLEVEL__)
#  define FORMA_SIMULATE_VERSION_PATCH (__GNUC_PATCHLEVEL__)
# endif

#    if __cpp_constexpr >= 200704 || __INTEL_COMPILER >= 1400 && ((__cplusplus >= 201103L) || defined(__INTEL_CXX11_MODE__) || defined(__GXX_EXPERIMENTAL_CXX0X__))
#      define FORMA_COMPILER_CXX_CONSTEXPR 1
#    else
#      define FORMA_COMPILER_CXX_CONSTEXPR 0
#    endif

#    if __INTEL_COMPILER >= 1400 && ((__cplusplus >= 201103L) || defined(__INTEL_CXX11_MODE__) || defined(__GXX_EXPERIMENTAL_CXX0X__))
#      define FORMA_COMPILER_CXX_NOEXCEPT 1
#    else
#      define FORMA_COMPILER_CXX_NOEXCEPT 0
#    endif

#    if __INTEL_COMPILER >= 1500 && ((__cplusplus >= 201300L) || ((__cplusplus == 201103L) && !defined(__INTEL_CXX11_MODE__)) || ((((__INTEL_COMPILER == 1500) && (__INTEL_COMPILER_UPDATE == 1))) && defined(__GXX_EXPERIMENTAL_CXX0X__) && !defined(__INTEL_CXX11_MODE__) ) || (defined(__INTEL_CXX11_MODE__) && defined(__cpp_aggregate_nsdmi)) )
#      define FORMA_COMPILER_CXX_ATTRIBUTE_DEPRECATED 1
#    else
#      define FORMA_COMPILER_CXX_ATTRIBUTE_DEPRECATED 0
#    endif

#  elif FORMA_COMPILER_IS_MSVC

#    if !(_MSC_VER >= 1600)
#      error Unsupported compiler version
#    endif

  /* _MSC_VER = VVRR */
# define FORMA_COMPILER_VERSION_MAJOR (_MSC_VER / 100)
# define FORMA_COMPILER_VERSION_MINOR (_MSC_VER % 100)
# if defined(_MSC_FULL_VER)
#  if _MSC_VER >= 1400
    /* _MSC_FULL_VER = VVRRPPPPP */
#   define FORMA_COMPILER_VERSION_PATCH (_MSC_FULL_VER % 100000)
#  else
    /* _MSC_FULL_VER = VVRRPPPP */
#   define FORMA_COMPILER_VERSION_PATCH (_MSC_FULL_VER % 10000)
#  endif
# endif
# if defined(_MSC_BUILD)
#  define FORMA_COMPILER_VERSION_TWEAK (_MSC_BUILD)
# endif

#    if _MSC_VER >= 1900
#      define FORMA_COMPILER_CXX_CONSTEXPR 1
#    else
#      define FORMA_COMPILER_CXX_CONSTEXPR 0
#    endif

#    if _MSC_VER >= 1900
#      define FORMA_COMPILER_CXX_NOEXCEPT 1
#    else
#      define FORMA_COMPILER_CXX_NOEXCEPT 0
#    endif

#    if _MSC_VER >= 1900
#      define FORMA_COMPILER_CXX_ATTRIBUTE_DEPRECATED 1
#    else
#      define FORMA_COMPILER_CXX_ATTRIBUTE_DEPRECATED 0
#    endif

#  else
#    error Unsupported compiler
#  endif

#  if defined(FORMA_COMPILER_CXX_CONSTEXPR) && FORMA_COMPILER_CXX_CONSTEXPR
#    define FORMA_CONSTEXPR constexpr
#  else
#    define FORMA_CONSTEXPR 
#  endif


#  if defined(FORMA_COMPILER_CXX_NOEXCEPT) && FORMA_COMPILER_CXX_NOEXCEPT
#    define FORMA_NOEXCEPT noexcept
#    define FORMA_NOEXCEPT_EXPR(X) noexcept(X)
#  else
#    define FORMA_NOEXCEPT
#    define FORMA_NOEXCEPT_EXPR(X)
#  endif


#  ifndef FORMA_DEPRECATED
#    if defined(FORMA_COMPILER_CXX_ATTRIBUTE_DEPRECATED) && FORMA_COMPILER_CXX_ATTRIBUTE_DEPRECATED
#      define FORMA_DEPRECATED [[deprecated]]
#      define FORMA_DEPRECATED_MSG(MSG) [[deprecated(MSG)]]
#    elif FORMA_COMPILER_IS_GNU || FORMA_COMPILER_IS_Clang
#      define FORMA_DEPRECATED __attribute__((__deprecated__))
#      define FORMA_DEPRECATED_MSG(MSG) __attribute__((__deprecated__(MSG)))
#    elif FORMA_COMPILER_IS_MSVC
#      define FORMA_DEPRECATED __declspec(deprecated)
#      define FORMA_DEPRECATED_MSG(MSG) __declspec(deprecated(MSG))
#    else
#      define FORMA_DEPRECATED
#      define FORMA_DEPRECATED_MSG(MSG)
#    endif
#  endif

#endif

#endif
