:: Windows Auto Pull
@echo off
:: 设置Git仓库路径，多个路径之间用空格分隔
set repos=D:\P\Idea\MyJava D:\P\Code D:\P\ObsidianRe

:: 远程仓库名称 (例如：origin)
set remote=origin

:: 循环遍历每个仓库路径
for %%r in (%repos%) do (
    echo MadMike: Pulling updates for %%r...
    cd %%r
    
    :: 自动拉取远程更新
    git pull %remote%
)

echo MadMike: All repos have been updated!
pause
