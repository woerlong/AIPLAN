#github
###一、下载源代码
在源码页点clone 复制地址
进入想要保存的文件夹，右键git bash here 
$git clone 网址


###二、issue
问题板块，可向原作者提出问题

###三、找开源项目
根据国籍，语言，找最近star数多的项目  https://github.com/trending/
推荐项目的媒体  https://github.com/521xueweihan/HelloGitHub
搜 awesome xxx 找关于xxx的相关帖子
找例子 xxx sample
找空项目架子 xxx starter
找教程 xxx tutorial

###四、连接git和github
在git界面输入ssh 检查是否安装ssh
输入ssh-keygen -t rsa 敲三次回车键生成密钥id_rsa和公钥id_rsa.pub
将公钥添加到github进行连接
setting->SSH and GPG keys->New ssh key
用记事本将公钥打开并复制到github添加ssh即可
在git界面输入ssh -T git@github.com 检验是否连接成功

###五、git基本命令
1、将本地代码推到远程仓库
git push origin master
2、将远程仓库代码拉到本地
git pull origin master
