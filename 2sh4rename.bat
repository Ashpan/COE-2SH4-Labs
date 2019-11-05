@echo off
set /p lab="Enter the lab number: "
cd Lab%lab%
mkdir files_to_submit
for /R %f in (.\*) do @echo %f
findstr /r "^Q.*.c$"
