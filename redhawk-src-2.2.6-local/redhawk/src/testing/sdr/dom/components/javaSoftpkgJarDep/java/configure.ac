AC_INIT(javaSoftpkgJarDep, 1.0.0)
AM_INIT_AUTOMAKE([nostdinc foreign])
AC_CONFIG_MACRO_DIR([m4])

OSSIE_CHECK_OSSIE
OSSIE_SDRROOT_AS_PREFIX

PKG_CHECK_MODULES([OSSIE], [ossie >= 2.0])

RH_JAVA_HOME
RH_PROG_JAVAC([1.6])
RH_PROG_JAR

RH_PKG_CLASSPATH([REDHAWK], [ossie])
RH_SOFTPKG_JAVA([/deps/java_dep1/java_dep1.spd.xml])

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
