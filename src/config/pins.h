#pragma once

#if defined(BOARD_XIAO_S3)
    #include "boards/board_xiao_esp32s3.h"

#elif defined(BOARD_HTK_BADUSB)
    #include "boards/htk_badusb.h"

#else
    #error "Board no definida en platformio.ini"
#endif
