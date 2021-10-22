# git

## git submodule

    git submodule add https://github.com/jjkkwym/EasyLogger.git EasyLogger

## git configure remote for a fork

- 使用

        git remote -v

- 查看远程状态

- 确定一个将被同步的上游仓库

        git remote add upstream 仓库地址

- 从上游fetch分支和提交点，提交给本地master,并被存储为一个本地分支

        git fetch upstream

- 切换到本地主分支

        git checkout master

- upstream/master与主分支合并

        git merge upstream/master

- update github fork

        git push origin master

## 下载github上某个文件夹

需要下载这个文件夹下所有内容https://github.com/anzhihe/learning/tree/master/shell
将/tree/master替换为/trunk
svn checkout https://github.com/anzhihe/learning/trunk/shell

