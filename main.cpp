#include <iostream>
#include "stdlib.h"

/**
本项目包含如下几种视音频数据解析示例：
 (1)像素数据处理程序。包含RGB和YUV像素格式处理的函数。
 (2)音频采样数据处理程序。包含PCM音频采样格式处理的函数。
 (3)H.264码流分析程序。可以分离并解析NALU。
 (4)AAC码流分析程序。可以分离并解析ADTS帧。
 (5)FLV封装格式分析程序。可以将FLV中的MP3音频码流分离出来。
 (6)UDP-RTP协议分析程序。可以将分析UDP/RTP/MPEG-TS数据包。
 */


extern int yuv420_split(const char* url, int w, int h, int num );

extern int yuv444_split(const char* url, int w, int h, int num );

int main() {

    // 分离YUV420, Y,U,V数据
    yuv420_split("../resources/lena_256x256_yuv420p.yuv", 256, 256, 1);

    // 分离YUV444, Y,U,V数据
    yuv444_split("../resources/lena_256x256_yuv444p.yuv", 256, 256, 1);










    return 0;
}

