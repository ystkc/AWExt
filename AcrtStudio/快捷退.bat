@echo off
title By ţ��
taskkill -f -im Student.exe&taskkill -f -im StudentTools.exe
taskkill -f -im Student.exe&taskkill -f -im StudentTools.exe
taskkill -f -im Student.exe&taskkill -f -im StudentTools.exe
taskkill -f -im Student.exe&taskkill -f -im StudentTools.exe
if not exist .\ntsd.exe echo û��ntsd
if not exist .\ntsd.exe pause
.\ntsd.exe -pn StudentMain.exe -r q