# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/ziselite/pico-sdk/tools/pioasm"
  "/mnt/SSD Storage/Libraries/Documents/GitHub/pico-custom-30-button-keypad/build/pioasm"
  "/mnt/SSD Storage/Libraries/Documents/GitHub/pico-custom-30-button-keypad/build/pico-sdk/src/rp2_common/pico_cyw43_driver/pioasm"
  "/mnt/SSD Storage/Libraries/Documents/GitHub/pico-custom-30-button-keypad/build/pico-sdk/src/rp2_common/pico_cyw43_driver/pioasm/tmp"
  "/mnt/SSD Storage/Libraries/Documents/GitHub/pico-custom-30-button-keypad/build/pico-sdk/src/rp2_common/pico_cyw43_driver/pioasm/src/PioasmBuild-stamp"
  "/mnt/SSD Storage/Libraries/Documents/GitHub/pico-custom-30-button-keypad/build/pico-sdk/src/rp2_common/pico_cyw43_driver/pioasm/src"
  "/mnt/SSD Storage/Libraries/Documents/GitHub/pico-custom-30-button-keypad/build/pico-sdk/src/rp2_common/pico_cyw43_driver/pioasm/src/PioasmBuild-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/mnt/SSD Storage/Libraries/Documents/GitHub/pico-custom-30-button-keypad/build/pico-sdk/src/rp2_common/pico_cyw43_driver/pioasm/src/PioasmBuild-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/mnt/SSD Storage/Libraries/Documents/GitHub/pico-custom-30-button-keypad/build/pico-sdk/src/rp2_common/pico_cyw43_driver/pioasm/src/PioasmBuild-stamp${cfgdir}") # cfgdir has leading slash
endif()
