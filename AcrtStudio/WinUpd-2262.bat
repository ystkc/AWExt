@echo off
title WinUpd - ƴһƴ������Ц�ø�����
timeout 1 /nobreak >null
echo �������ȫ�޺���������һЩ���õķ������������(Win10����)
timeout 1 /nobreak >null
echo ��������ʯ����ѧ���л�ԭϵͳ�Ļ��ͣ����򲻻�����ر��Ч��
timeout 1 /nobreak >null
taskkill -f -im TrustedInstaller.exe
taskkill -f -im software_reporter_tool.exe
taskkill -f -im GoogleUpdate.exe
taskkill -f -im WaaSMedicAgent.exe
taskkill -f -im CompatTelRunner.exe
taskkill -f -im backgroundTaskHost.exe
echo ���ڰ�ȫԭ�򣬲����ṩ����Cortana����
taskkill -f -im SearchUI.exe
erase "C:\Users\Administrator\AppData\Local\Google\Chrome\User Data\SwReporter\81.235.200\software_reporter_tool.exe"
erase .\null

echo.
echo.
echo ���޸�ע����ֹWindow Update���ķ�������㻹������������߷����������ֹ
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
echo ���²�����������У������漰�ļ����������޸ģ���ʯ����ѧ����ԭ�����벻Ҫ���Է������Ը�
echo ���幦�ܣ���ren������Cortana
timeout /nobreak
echo ����������ȷ�Ϸ����������е�����ʹ�õ�һ�к��
pause
pause
ren C:\Windows\SystemApps\Microsoft.Windows.Cortana_cw5n1h2txyewy Microsoft.Windows.Cortana_cw5n1h2txyewy1