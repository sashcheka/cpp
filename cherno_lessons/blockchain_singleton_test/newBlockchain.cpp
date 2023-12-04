#include "newBlockchain.h"

Singleton& Singleton::Get() {
  static Singleton instance;
  return instance;
}