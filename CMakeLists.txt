cmake_minimum_required(VERSION 3.5)

project(ussd7bit
        LANGUAGES C
        VERSION 0.1.0
        HOMEPAGE_URL "https://github.com/wolandtel/smstools"
        )

set(CMAKE_C_STANDARD 11)

add_executable(ussd_encode ussd7bit/encode.c)
target_link_libraries(ussd_encode m)

add_executable(ussd_decode ussd7bit/decode.c)

install(TARGETS ussd_encode DESTINATION bin)
install(TARGETS ussd_decode DESTINATION bin)

if (NOT DEFINED PACKAGE_ARCHITECTURE)
    execute_process (
            COMMAND dpkg --print-architecture
            OUTPUT_VARIABLE PACKAGE_ARCHITECTURE
            OUTPUT_STRIP_TRAILING_WHITESPACE
    )
endif()

set(CPACK_GENERATOR "DEB")
set(CPACK_PACKAGE_NAME "${PROJECT_NAME}")
set(CPACK_PACKAGE_VERSION "${PROJECT_VERSION}")
set(CPACK_PACKAGE_FILE_NAME "${CPACK_PACKAGE_NAME}_${CPACK_PACKAGE_VERSION}_${PACKAGE_ARCHITECTURE}")
set(CPACK_DEBIAN_PACKAGE_SECTION "comm")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Vadim Cherenev <sl@anhot.ru>")
set(CPACK_DEBIAN_PACKAGE_DESCRIPTION "Helps transcode PDU-encoded USSD messages.")
set(CPACK_DEBIAN_PACKAGE_DEPENDS "")
set(CPACK_DEBIAN_PACKAGE_SUGGESTS "smstools")
set(CPACK_DEBIAN_PACKAGE_ARCHITECTURE "${PACKAGE_ARCHITECTURE}")
set(CPACK_PACKAGING_INSTALL_PREFIX "usr")

include(CPack)
