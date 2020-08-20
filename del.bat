@echo off
echo 正在清除项目临时文件，请稍等......

del /f /s /q %~dp0\*.bin
del /f /s /q %~dp0\*.ncb
del /f /s /q %~dp0\*.user
del /f /s /q %~dp0\*.pch
del /f /s /q %~dp0\*.obj
del /f /s /q %~dp0\*.tlh
del /f /s /q %~dp0\*.tli
del /f /s /q %~dp0\*.res
del /f /s /q %~dp0\*.idb
del /f /s /q %~dp0\*.pdb
del /f /s /q %~dp0\*.aps
del /f /s /q %~dp0\*.manifest
del /f /s /q %~dp0\*.dep
del /f /s /q %~dp0\*.log
del /f /s /q %~dp0\*.txt
del /f /s /q %~dp0\*.cjstyles
del /f /s /q %~dp0\*.hwl
del /f /s /q %~dp0\*.ilk
del /f /s /q %~dp0\*.rar
del /f /s /q %~dp0\*.zip
del /f /s /q %~dp0\*.exe
del /f /s /q %~dp0\*.dll
del /f /s /q %~dp0\*.SRDB
del /f /s /q %~dp0\*.SRDB.Bakup
del /f /s /q %~dp0\*.jar
del /f /s /q %~dp0\*.db
del /f /s /q %~dp0\*.png
del /f /s /q %~dp0\UpgradeLog.XML
del /f /s /q %~dp0\UpgradeLog.XML
del /f /s /q %~dp0\*.sdf
del /f /s /q %~dp0\*.opensdf
del /f /s /q %~dp0\*.i
del /f /s /q %~dp0\*.clw
del /f /s /q %~dp0\*.opt
del /f /s /q %~dp0\*.plg
del /f /s /q %~dp0\*.tlog
del /f /s /q %~dp0\*.recipe
del /f /s /q %~dp0\*.lastbuildstate




if exist _UpgradeReport_Files (
    cd _UpgradeReport_Files
echo 当前目录[%cd%]
del /f /s /q *.*
    cd..
rd _UpgradeReport_Files
echo del _UpgradeReport_Files


)




if exist Release (
    cd Release 
echo 准备删除 Release 目录下的所有文件,请确认一下当前目录是否正确.再继续
echo 当前目录[%cd%]
del /f /s /q *.*
    cd..
rd Release 
echo del Release 
)




if exist Debug (
    cd Debug
echo 当前目录[%cd%]
del /f /s /q *.*
    cd..
rd Debug
echo del Debug
)




pause