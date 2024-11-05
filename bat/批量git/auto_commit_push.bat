:: Windows Auto Commit & Push
@echo off
:: 设置Git仓库路径，多个路径之间用空格分隔
set repos=("F:\------------------OWN\IDEA\MyJava" "F:\------------------OWN\VSCode" "F:\------------------OWN\ObisidianGit")

:: 远程仓库名称 (例如：origin)
set remote=origin

:: 循环遍历每个仓库路径
for %%r in %repos% do (
    echo MadMike: Processing...%%r
    :: 打开TortoiseGit的提交页面
    start "" "TortoiseGitProc.exe" /command:commit /path:%%r

    :: 等待用户提交完成后，自动推送到远程
    cd %%r
    git push %remote%
)

echo MadMike: All repos has been processed!
pause
