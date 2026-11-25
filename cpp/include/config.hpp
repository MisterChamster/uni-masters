#pragma once

#include <string_view>

namespace config {
    inline const int NODE_NEIGHBORS_COUNT = 6;
    inline const int DEFAULT_CONTROL_PARAM = 1;
    inline const int DEFAULT_TURNS_OMIT_SIGMA = 10;

    inline const std::string DEFAULT_MIDSPACE_CHAR = " ";

    // Sigma Over Time
    inline const std::string SOT_FILE_EXT = "txt";
    inline const std::string SOT_FILENAME_BASE = "sigma_over_time";
    inline const std::string SOT_DIRNAME_BASE = "sot_simulation";
}
