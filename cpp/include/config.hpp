#pragma once

#include <string_view>

namespace config {
    inline const int NODE_NEIGHBORS_COUNT = 6;
    inline const int DEFAULT_CONTROL_PARAM = 1;
    inline const int DEFAULT_TURNS_OMIT_SIGMA = 10;

    inline const std::string DEFAULT_MIDSPACE_CHAR = " ";

    // Example Sigma Over Time
    inline const std::string ESOT_FILE_EXT = "txt";
    inline const std::string ESOT_FILENAME_BASE = "example_sigma_over_time";
    inline const std::string ESOT_DIRNAME_BASE = "esot_simulation";
}
