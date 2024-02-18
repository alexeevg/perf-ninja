#include "solution.hpp"

uint16_t checksum(const Blob &blob) {
  uint32_t acc = 0;
  for (auto value : blob) {
    acc += value;
  }
  
  acc = (acc & 0x0000FFFF) + (acc >> 16);
  acc = (acc & 0x0000FFFF) + (acc >> 16);
  return acc;
}
