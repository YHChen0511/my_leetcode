# 盛最多水的容器

盛水的容量受到短边和双边距离（下标差）影响

为了尽量控制更多的变量，初始情况下左指针指向数组头部，右指针指向数组尾部（这样移动指针可以保证下标差减少）

如果移动长边，则短边不变，下标差减少，容积一定减少

因此移动短边