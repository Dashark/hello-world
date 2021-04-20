# hello-world
C/C++编程初学者

# Git手册
* [Git Book](https://git-scm.com/book/zh/v2)
* [Git 参考手册](http://gitref.justjavac.com/)
* [Git教程](https://www.liaoxuefeng.com/wiki/0013739516305929606dd18361248578c67b8067c8c017b000)
网上有大量关于Git系统的信息，请自行查阅。

# Git统计方法
* 统计代码量
```
git log --author="$(git config --get user.name)" --pretty=tformat: --numstat | gawk '{ add += $1 ; subs += $2 ; loc += $1 - $2 } END { printf "added lines: %s removed lines : %s total lines: %s\n",add,subs,loc }' -
```
* 统计提交次数
```
git shortlog -s
```

[Code Reference](https://github.com/WangShouDao/count_github_push)