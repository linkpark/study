title: Hexo搭建博客(一)
date: 2014-08-09 10:17:05
categories: 博客搭建
tags: [hexo,博客]
---

一直以来，都想搭建一个自己的博客，然一直愁于时间问题还有平台选型问题，WordPress虽好，但感觉太重，而且搭建博客需要租服务器，购买域名之类的，我本散淡之人，不喜麻烦，于是作罢。

但一个偶然机会，发现同学都在用github，并且github提供免费的博客系统github page，感觉挺有意思的，定制性很强，适合懂技术的童鞋。于是，我便开始折腾如何在github上搭建博客。先前有过web前端开发基础，听说js也可以开发后台——node.js，兴趣使然，在这篇文章[node.js学习路线图](http://mp.weixin.qq.com/s?__biz=MjM5NzA1MTcyMA==&mid=201160414&idx=2&sn=d8d60bc6c1f9fd1b3bac5ecb6b120867&scene=2&from=timeline&isappinstalled=0#rd)看到了Hexo这玩意儿，并且这玩意儿正好能搭建在github上，真是无巧不成章，正好我个人对node.js比较感兴趣，而且又期望在github上搭建自己的博客，只要你肯找，这世上还真有这样两全其美的事儿^_^。<!-- more -->

搭建这个博客，参考的最多的是这个博客系列[Zippera's blog](http://zipperary.com/categories/hexo/)，灰常感谢博主的分享。好了废话不多说，赶紧进入正题，hexo基于nodejs，自然需要nodejs的支持，安装的系统环境，在 linux和windows下我都试过，分别介绍一下吧。

##Linux环境下的hexo博客搭建
###Node.js安装
首先介绍一下我的系统环境——ubuntu12.04 server x_64，然后在官网上下载[node.js源码包](http://www.nodejs.org/download/)，完了之后解压源码包：
```bash
#tar zxvf node-v0.10.30.tar.gz
#cd node-v0.10.30
```

进入文件夹后可以发现，里面有一个configure文件，安装步骤和在linux安装其他源码文件过程一样
```bash
#./configure
#make
#make install
```

安装完毕后，检查安装是否成功：
```bash
#node -v
```

倘若输出nodejs版本号，证明安装成功了。

###Hexo的安装
安装完node.js后，再来安装hexo就容易的多了，直接利用node.js的安装工具npm就可以进行安装了。
```bash
#npm install -g hexo
```
###Hexo博客构建

创建容纳hexo项目的文件夹，并且在文件夹内初始化所有的必要文件，并安装依赖包：
```bash
#mkdir hexo
#cd hexo
#hexo init
#npm install
```
完了之后，应该就可以运行了，在hexo文件夹内输入：
```bash
#hexo generate
#hexo server
```
就完成了服务器的本地启动，之后在浏览器里面访问看看是否成功。

##Windows下hexo环境的构建
###node.js的安装
windows下node.js安装就好弄的多，直接下载[node.js安装包](http://www.nodejs.org/download/)，完了之后像安装平常软件一样安装就行了。
####tips:
>在安装完了之后需要检查一下环境变量的配置，打开cmd窗口，运行node，发现找不到命令，这就说明是环境变量没有配好，检查一下环境变量，将node的安装目录添加到PATH环境变量中（普通用户和管理员用户最好都添加），后面的npm命令执行找不到也是同样的原因。

###github工具安装
我这里用的是github官方提供的windows客户端，感觉还挺好用的，提供图形界面和powerShell两种操作方式，可以去[这里](https://windows.github.com/)下载。

完了之后，利用客户端提供的powershell搭建本地Hexo的后续过程和在linux上没有任何区别，这里就不再赘述了。