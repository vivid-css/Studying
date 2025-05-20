# Linux使用
---
---
## 1.环境配置
1.root权限配置
- root拥有Linux系统的最高权限
- Ubuntu下直接使用sudo即可

2.软件源配置
- 更新软件包
`sudo apt-get update`
`sudo apt-get upgrade`
---

## 2.基本指令
Linux 中的文件系统是一个树状结构，根目录为 /，所有文件都是从根目录开始的，对系统的使用其实是对文件的操作

**常用指令**
`cd [dirName]`  切换路径
- 以`/``~`的表示绝对路径
- .. 返回当前目录的上一层目录
- .  当前目录

`dir [options] [Directory] [Files]`
`ls [options] [Directory]`展示当前目录下的所有文件
- dir 在Windows中常用
- ls在Linux中可用颜色区分文件类型，还可加入其他参数
- `ls -l           # 以长格式显示当前目录中的文件和目录`
`ls -a           # 显示当前目录中的所有文件和目录，包括隐藏文件`
`ls -lh          # 以人类可读的方式显示当前目录中的文件和目录大小`
`ls -t           # 按照修改时间排序显示当前目录中的文件和目录`
`ls -R           # 递归显示当前目录中的所有文件和子目录`
`ls -l /etc/passwd     # 显示/etc/passwd文件的详细信息`
`pwd [--help] [--version]`

`mkdir [-p] dirName`
- -p 确保目录名称存在，不存在的就建一个

`cp [options] source dest`
- 前者表示源文件，后者表示目标文件，表示将指定源文件复制到目标文件位置。若目标文件不存在则会新建一个（相当于备份），若目标文件存在则会替换（相当于替换）

`mv [options] source dest`
- 前者表示源文件，后者表示目标文件，表示将指定源文件移动到目标文件位置

`ps [options] [--help]`
- 用于显示当前进程的状态

**解压缩** 
|格式|	解压命令	|压缩命令|
|----|-------------|-------|
|.tar|	tar -xvf file.tar|	tar -cvf file.tar dir|
|.gz|	gunzip file.gz|	gzip file|
|.tar.gz|	tar -zxvf file.tar.gz|	tar -zcvf file.tar.gz dir|
|.zip|	unzip file.zip|	zip file.zip dir|
|.rar|	rar -x file.rar|	rar -a file.rar dir
|.bz2|解压1：bzip2 -d FileName.bz2 解压2：bunzip2 FileName.bz2|bzip2 -z FileName|

**其他常用命令**
`sudo command ## 使用root权限执行`
`time command`
`OMMAND < file #表示将指定文件作为执行命令中的输入`
`COMMAND > file #表示将命令输出至指定文件而非终端`

## 3.软件安装
**1.APT包管理**
```bash
sudo apt update    # 列出所有可更新的软件清单
sudo apt upgrade    # 升级软件包
sudo apt install <package_name>    # 安装指定的软件包
sudo apt remove <package_name>    # 删除指定软件包
sudo apt autoremove    #清理不再使用的依赖和库文件
apt list --upgradeable    #列出可更新的软件包及版本信息
```
**2.(.deb 文件)直接使用 dpkg 安装**
```bash
dpkg --help 显示帮助
sudo dpkg -i file.deb 安装指定的软件包
```
**3.软件带有安装程序**
`chmod +x file.txt 给指定文件添加可执行权限`

## 4.文本编辑

**vim使用**
- 打开默认命令模式
`i  -- 切换到输入模式，在光标当前位置开始输入文本`
`x  -- 删除当前光标所在处的字符`
`:  -- 切换到底线命令模式，以在最底一行输入命令`
`dd -- 剪切当前行`
`yy -- 复制当前行`
`p  -- 粘贴剪贴板内容到光标下方`
`P  -- 粘贴剪贴板内容到光标上方`
`u  -- 撤销上一次操作`
`Ctrl+r -- 重做上一次撤销的操作。`
- Esc 返回普通模式
底线命令模式在命令模式下按':'进入
  `:w  -- 保存文件`
`:q  -- 退出 Vim 编辑器`
`:wq -- 保存修改并退出 Vim 编辑器`
`:q! -- 不保存修改强制退出 Vim 编辑器`



