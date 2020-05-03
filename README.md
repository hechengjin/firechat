# firechat
chat client

Qt Creator 4.8.0  ----Qt 5.12.0



---------------
Qt Creator 3.5.1 (opensource)  Desktop_Qt_5_5_1_MSVC2013_32bit
Qt5.5.1 

git 2.5.1 TortoiseGit 1.8.14.0

git clone https://github.com/hechengjin/firechat.git
windows下默认下载下来的是Unix风格代码，报如下错误:
firechat\boxes\main_widget.h:-1: warning: C4819: 该文件包含不能在当前代码页(936)中表示的字符。请将该文件保存为 Unicode 格式以防止数据丢失

在TortoiseGit中进行设置
右键 设置 Git 自动CrLf换行转换 设置为true
--------------