研究生在研究生目录下：
本科生在本科生目录下:
每人一个以自己名字命名的文件夹

里面至少包含两个文件：
plan.md
plan_mark.md
xxxx.md

plan.md为5周的学习计划，扣除掉过年1周。
plan_mark.md 为计划执行情况，每天记录下简要记录今天完成的内容，每日更新。
xxxx为某一个方面的学习笔记，每日更新。 例如xxxx为谋篇论文的阅读笔记  例如 学习css，命名为css.md，里面记录学习css的重点内容笔记

编辑md可以使用VS code，基本满足需求。更丰富功能的编辑器也有很多，自行谷歌吧。


注意主项目可能会更新，导致你本地项目与主项目结构不一致。可以先到网页查看自己的fork页面，里面有fetch upstream，通过这个可以将自己fork的项目与主项目的内容保持最新。

然后用destop 软件更新到本地。

注意不要删除项目中除了自己目录以外的任何文件。


# github配合github desktop操作简易说明
<https://docs.github.com/cn/desktop>

github desktop说明书

打不开的话，用谷歌浏览器打开

初始化部分

![](media/180b152c7d8b58519a50d6613518b7bf.png)

1.首先与原库进行关联，点击fork按键进行操作

![](media/3ae7507fbbc4f489c65890591d312b05.png)

2.成功后可在自己的github主页看到新添加的库

![](media/7513c3f6d8c06fd6e15cf8201727d1dc.png)

3.安装github desktop并打开

![](media/e5966eba6f18904c8ec8edcca0aeb6ed.png)

4.在菜单中选择file→clone
respository，打开克隆库选项窗口。选择第三个“URL”方式，在第一行里填写库的网址，第二行填写存储在本地磁盘的位置，注意必须是空文件夹，否则会报错

![](media/1e4472d127e15a5f968028a219e05b34.png)

5.单机左上角的current repository可以查看已经添加到本地的库

更新部分

![](media/c744d9ee9aac18394e9040f5a6fcd8ce.png)

6.进入自己的fork库，点击fetch upstreams→fetch and
merge，将上游库更新的内容同步到自己的fork库里面，以保持自己的库与上游库内容一致

![](media/5d38a031e32293c2499ffbebe39973dc.png)

7.打开github desktop，点击fetch xxxx按键，将fork库中的内容同步到本地磁盘

![](media/2a090e437732be13dbc22a87c0b79241.png)

8.点击 show in explorer，可打开本地磁盘上库所在的文件夹

![](media/7642c0c1b726f7d8e25069162fb95efd.png)

9.直接在文件夹内对文件或文件夹进行修改，包括但不限于修改文件、增删文件、修改文件夹、修改文件的位置（即从文件夹A转移到文件夹B），注意，github项目中不允许存在空文件夹

![](media/92288baefc762bdd896cdcbbfbab1f0a.png)

10.修改后，可在github desktop中看到更改的项目

![](media/da5b7bd185181acf1fe49b8905c1d61f.png)

11.在下方对变更内容编写简要注释，并点击commit提交，提交完成后点击右上角fetch（当出现提示时，直接选绿色选项，可能会出现多次提示）

该步骤完成后，可在网页上自己的fork库中看到更新的内容

![](media/346026444bf210aabe78526e7ca20ed9.png)

12.回到网页上的fork库，创建新的pull request

![](media/01e2736569b94f96b816127abd8b5db1.png)

13.紧跟上一步后，会出现如图界面，左边是目标库，右边是提供变更的库，即左边是上游库，右边是自己的fork库。如果发生变更，下方可看到变更的内容。拉到最下面，对变更做个简要总结，并点击merge或commit进行提交

![C:\\Users\\Administrator\\Documents\\Tencent
Files\\977104006\\Image\\Group2\\XE\\O8\\XEO8YX[7W}MW_RY2RO6[NU2.jpg](media/c15a00f59e2eee839e381bf486624113.jpeg)

14.提交后可在上游库中看到提交的申请，以及申请是被接受或拒绝
