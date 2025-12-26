
// ImGui + SDL2 像素风 terminal UI 示例
#include "imgui.h"
#include "imgui_internal.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_syswm.h>
#include "imgui_impl_sdl2.h"
#include "imgui_impl_sdlrenderer2.h"
#include <stdio.h>

int main(int, char **)
{
    // 初始化 SDL2
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) != 0)
    {
        printf("Error: %s\n", SDL_GetError());
        return -1;
    }
    SDL_Window *window = SDL_CreateWindow("Pixel Terminal UI", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 480, SDL_WINDOW_SHOWN);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);

    // 初始化 ImGui
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO();
    (void)io;
    ImGui::StyleColorsDark();
    // 加载支持中文的字体，解决中文乱码
    io.Fonts->AddFontFromFileTTF("C:/Windows/Fonts/msyh.ttc", 18.0f, NULL, io.Fonts->GetGlyphRangesChineseSimplifiedCommon());
    // 像素风格设置
    ImGuiStyle &style = ImGui::GetStyle();
    style.WindowRounding = 0.0f;
    style.FrameRounding = 0.0f;
    style.ScrollbarRounding = 0.0f;
    style.GrabRounding = 0.0f;
    style.WindowBorderSize = 2.0f;
    style.FrameBorderSize = 1.0f;
    style.WindowPadding = ImVec2(8, 8);
    style.FramePadding = ImVec2(4, 2);
    style.ItemSpacing = ImVec2(4, 2);
    style.Colors[ImGuiCol_WindowBg] = ImVec4(0.1f, 0.1f, 0.12f, 1.0f);
    style.Colors[ImGuiCol_Border] = ImVec4(0.3f, 0.3f, 0.4f, 1.0f);

    ImGui_ImplSDL2_InitForSDLRenderer(window, renderer);
    ImGui_ImplSDLRenderer2_Init(renderer);

    bool show_demo_window = false;
    bool running = true;
    while (running)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            ImGui_ImplSDL2_ProcessEvent(&event);
            if (event.type == SDL_QUIT)
                running = false;
        }

        ImGui_ImplSDLRenderer2_NewFrame();
        ImGui_ImplSDL2_NewFrame();
        ImGui::NewFrame();

        // 像素风 terminal UI 区域
        ImGui::SetNextWindowSize(ImVec2(700, 400), ImGuiCond_Once);
        ImGui::Begin("Pixel Terminal", nullptr, ImGuiWindowFlags_NoResize);
        ImGui::TextColored(ImVec4(0.2f, 1.0f, 0.2f, 1.0f), "█▓▒░ 像素风终端 ░▒▓█");
        ImGui::Separator();
        static char input[256] = "";
        ImGui::InputText("输入命令", input, IM_ARRAYSIZE(input));
        if (ImGui::Button("执行"))
        {
            // 这里可以处理命令
        }
        ImGui::Text("\n█▓▒░ 输出区域 ░▒▓█");
        ImGui::BeginChild("scrolling", ImVec2(0, 200), true, ImGuiWindowFlags_HorizontalScrollbar);
        ImGui::Text("像素风终端输出示例\n> _\n> 支持自定义渲染、色块、字符拼接等");
        ImGui::EndChild();
        ImGui::End();

        if (show_demo_window)
            ImGui::ShowDemoWindow(&show_demo_window);

        ImGui::Render();
        SDL_SetRenderDrawColor(renderer, 20, 20, 30, 255);
        SDL_RenderClear(renderer);
        ImGui_ImplSDLRenderer2_RenderDrawData(ImGui::GetDrawData(), renderer);
        SDL_RenderPresent(renderer);
    }

    ImGui_ImplSDLRenderer2_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}