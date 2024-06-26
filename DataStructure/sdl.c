/**
* 类名:sdl
* 描述:
* 当前用户:21204
* 当前时间:2024/6/26:18:03
*/
#include <SDL2/SDL.h>
#include <stdio.h>

// 定义SDL别名
#define PG SDL

int main(int argc, char* argv[]) {
    // 初始化SDL
    if (PG_Init(PG_INIT_VIDEO) != 0) {
        printf("SDL初始化失败: %s\n", PG_GetError());
        return 1;
    }

    // 创建窗口
    PG_Window *window = PG_CreateWindow("SDL Window",
                                        PG_WINDOWPOS_CENTERED,
                                        PG_WINDOWPOS_CENTERED,
                                        640, 480,
                                        PG_WINDOW_SHOWN);

    if (!window) {
        printf("创建窗口失败: %s\n", PG_GetError());
        PG_Quit();
        return 1;
    }

    // 创建渲染器
    PG_Renderer *renderer = PG_CreateRenderer(window, -1, PG_RENDERER_ACCELERATED | PG_RENDERER_PRESENTVSYNC);
    if (!renderer) {
        printf("创建渲染器失败: %s\n", PG_GetError());
        PG_DestroyWindow(window);
        PG_Quit();
        return 1;
    }

    // 设置渲染器颜色 (红色)
    PG_SetRenderDrawColor(renderer, 255, 0, 0, 255);

    // 清除窗口
    PG_RenderClear(renderer);

    // 显示更新
    PG_RenderPresent(renderer);

    // 等待3秒
    PG_Delay(3000);

    // 清理资源
    PG_DestroyRenderer(renderer);
    PG_DestroyWindow(window);
    PG_Quit();

    return 0;
}
