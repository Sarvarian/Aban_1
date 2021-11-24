target_sources(Aban
PRIVATE
"rtp.c"
PUBLIC
"rtp.h"
)

target_include_directories(Aban
PUBLIC
${CMAKE_CURRENT_LIST_DIR}
)