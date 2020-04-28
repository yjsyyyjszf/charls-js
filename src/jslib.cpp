#include "JpegLSDecode.hpp"
#include "JpegLSEncode.hpp"

#include <emscripten.h>
#include <emscripten/bind.h>

using namespace emscripten;

EMSCRIPTEN_BINDINGS(FrameInfo) {
  value_object<FrameInfo>("FrameInfo")
    .field("width", &FrameInfo::width)
    .field("height", &FrameInfo::height)
    .field("bitsPerSample", &FrameInfo::bitsPerSample)
    .field("componentCount", &FrameInfo::componentCount)
       ;
}

EMSCRIPTEN_BINDINGS(JpegLSDecode) {
  class_<JpegLSDecode>("JpegLSDecode")
    .constructor<>()
    .function("getEncodedBuffer", &JpegLSDecode::getEncodedBuffer)
    .function("getDecodedBuffer", &JpegLSDecode::getDecodedBuffer)
    .function("decode", &JpegLSDecode::decode)
    .function("getFrameInfo", &JpegLSDecode::getFrameInfo)
    .function("getInterleaveMode", &JpegLSDecode::getInterleaveMode)
    .function("getNearLossless", &JpegLSDecode::getNearLossless)
   ;
}

EMSCRIPTEN_BINDINGS(JpegLSEncode) {
  class_<JpegLSEncode>("JpegLSEncode")
    .constructor<>()
    .function("getDecodedBuffer", &JpegLSEncode::getDecodedBuffer)
    .function("getEncodedBuffer", &JpegLSEncode::getEncodedBuffer)
    .function("setNearLossless", &JpegLSEncode::setNearLossless)
    .function("encode", &JpegLSEncode::encode)
   ;
}
