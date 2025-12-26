# 自动复制 vcpkg SDL2 运行时 DLL 到 build/Release 目录
$src = "${PSScriptRoot}\vcpkg\installed\x64-windows\bin\SDL2.dll"
$dst = "${PSScriptRoot}\build\Release\SDL2.dll"
if (Test-Path $src) {
    Copy-Item $src $dst -Force
    Write-Host "已复制 SDL2.dll 到 build/Release 目录。"
} else {
    Write-Host "未找到 SDL2.dll，请检查 vcpkg 安装路径。"
}
