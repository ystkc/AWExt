@echo off
title WinUpd - 拼一拼，龙哥笑得更开心
timeout 1 /nobreak >null
echo 本插件安全无害，仅禁用一些无用的服务以提高性能(Win10适用)
timeout 1 /nobreak >null
echo 仅适用于石门中学带有还原系统的机型，否则不会产生特别的效果
timeout 1 /nobreak >null
taskkill -f -im TrustedInstaller.exe
taskkill -f -im software_reporter_tool.exe
taskkill -f -im GoogleUpdate.exe
taskkill -f -im WaaSMedicAgent.exe
taskkill -f -im CompatTelRunner.exe
taskkill -f -im backgroundTaskHost.exe
echo 鉴于安全原因，不再提供禁用Cortana命令
taskkill -f -im SearchUI.exe
erase "C:\Users\Administrator\AppData\Local\Google\Chrome\User Data\SwReporter\81.235.200\software_reporter_tool.exe"
erase .\null

echo.
echo.
echo 将修改注册表禁止Window Update核心服务，如果你还想留着这个鸡肋服务，你可以阻止
echo.
reg add HKLM\SYSTEM\CurrentControlSet\Services\WaaSMedicSvcServices /v FailureActions /t REG_BINARY /d 840300000000000000000000030000001400000000000000C0D4010000000000E09304000000000000000000 /f
reg add HKLM\SYSTEM\CurrentControlSet\Services\Schedule /v FailureActions /t REG_BINARY /d 805101000000000000000000030000001400000000000000000000000000000060EA00000000000000000000 /f
reg add HKLM\SYSTEM\CurrentControlSet\Services\WaaSMedicSvc /v Start /t REG_DWORD /d 4 /f
reg add HKLM\SYSTEM\CurrentControlSet\Services\Schedule /v Start /t REG_DWORD /d 4 /f


sc config wuauserv start= disabled
sc stop wuauserv
sc config Schedule start= disabled
sc stop Schedule
sc config EventLog start= disabled
sc stop EventLog
sc config WaaSMedicSvc start= disabled
sc stop WaaSMedicSvc
sc config TrustedInstaller start= disabled
sc stop TrustedInstaller
sc config netprofm start= disabled
sc stop netprofm
sc config NlaSvc start= disabled
sc stop NlaSvc
sc config EventLog start= disabled
sc stop EventLog
sc config SysMain start= disabled
sc stop SysMain
sc config hidserv start= disabled
sc stop hidserv

exit


@echo off
echo 以下部分请谨慎运行，部分涉及文件夹永久性修改，非石门中学带还原机型请不要尝试否则后果自负
echo 具体功能：①ren并禁用Cortana
timeout /nobreak
echo 继续即代表确认符合条件并承担不当使用的一切后果
pause
pause
ren C:\Windows\SystemApps\Microsoft.Windows.Cortana_cw5n1h2txyewy Microsoft.Windows.Cortana_cw5n1h2txyewy1