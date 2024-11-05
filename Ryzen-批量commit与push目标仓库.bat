:: Windows Auto Commit & Push
@echo off
:: 设置Git仓库路径，多个路径之间用空格分隔
set repos=D:\P\Idea\MyJava D:\P\Code D:\P\ObsidianRe

:: 远程仓库名称 (例如：origin)
set remote=origin

:: 循环遍历每个仓库路径
for %%r in (%repos%) do (
    echo MadMike: Processing...%%r
    :: 检查是否是Git仓库
    if exist "%%r\.git" (
        :: 打开TortoiseGit的提交页面并等待用户完成提交
        start /wait "" "TortoiseGitProc.exe" /command:commit /path:%%r

        :: 用户提交完成后，自动推送到远程
        cd %%r
        git push %remote%
    ) else (
        echo %%r is not a valid Git repository.
    )
)

echo MadMike: All repos has been processed!
pause
