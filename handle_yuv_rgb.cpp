/**
 * Created by hengfeng zhuo on 2019-03-04.

- 分离YUV420P像素数据中的Y、U、V分量
- 分离YUV444P像素数据中的Y、U、V分量
- 将YUV420P像素数据去掉颜色（变成灰度图）
- 将YUV420P像素数据的亮度减半
- 将YUV420P像素数据的周围加上边框
- 生成YUV420P格式的灰阶测试图
- 计算两个YUV420P像素数据的PSNR
- 分离RGB24像素数据中的R、G、B分量
- 将RGB24格式像素数据封装为BMP图像
- 将RGB24格式像素数据转换为YUV420P格式像素数据
- 生成RGB24格式的彩条测试图
 */

#include <iostream>

/**
 * 剥离YUV420数据中的Y,U,V 三个分量
 * @param url
 * @param w
 * @param h
 * @param num
 * @return
 */
int yuv420_split(const char* url, int w, int h, int num ) {

    // 打开YUV420原始图片
    FILE* fd_yuv = fopen(url, "rb+");

    FILE* fd_y = fopen("../out/result_y.y", "wb+");
    FILE* fd_u = fopen("../out/result_u.y", "wb+");
    FILE* fd_v = fopen("../out/result_v.y", "wb+");

    // 读出来的数据buffer, y/u/v存储的数据量为  长*高*3/2  == Y + U/4 + V/4
    unsigned char* pic = (unsigned char *)malloc(w * h * 3 / 2);

    for (int i = 0; i < num; i++) {
        fread(pic, 1, w*h*3/2, fd_yuv);
        // y
        fwrite(pic, 1, w*h, fd_y);
        // u
        fwrite(pic+w*h, 1, w*h/4, fd_u);
        // v
        fwrite(pic+w*h+w*h/4, 1, w*h/4, fd_v);
    }

    free(pic);
    fclose(fd_yuv);
    fclose(fd_y);
    fclose(fd_u);
    fclose(fd_v);

    return 0;
}

/**
 * 剥离YUV420数据中的Y,U,V 三个分量
 * @param url
 * @param w
 * @param h
 * @param num
 * @return
 */
int yuv444_split(const char* url, int w, int h, int num ) {

    // 打开YUV444原始图片
    FILE* fd_yuv = fopen(url, "rb+");

    FILE* fd_y = fopen("../out/result_444_y.y", "wb+");
    FILE* fd_u = fopen("../out/result_444_u.y", "wb+");
    FILE* fd_v = fopen("../out/result_444_v.y", "wb+");

    // 读出来的数据buffer,那么一帧YUV444P像素数据一共占用w*h*3 Byte的数据。其中前w*h Byte存储Y，接着的w*h Byte存储U，最后w*h Byte存储V
    unsigned char* pic = (unsigned char *)malloc(w * h * 3);

    for (int i = 0; i < num; i++) {
        fread(pic, 1, w*h*3, fd_yuv);
        // y
        fwrite(pic, 1, w*h, fd_y);
        // u
        fwrite(pic+w*h, 1, w*h, fd_u);
        // v
        fwrite(pic+w*h*2, 1, w*h, fd_v);
    }

    free(pic);
    fclose(fd_yuv);
    fclose(fd_y);
    fclose(fd_u);
    fclose(fd_v);

    return 0;
}