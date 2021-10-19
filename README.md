# simplexTableau
可以计算简单的单纯形表问题, 如运筹学课本习题
# 使用方法
需要手动将问题转化为标准型, 之后按照提示输入

这里给个样例

![样例1](https://github.com/guner7451000/simplexTableau/blob/main/1.jpg)

输入

2

7

1 4 2 -1 1 0 0

3 2 0 0 0 -1 1

-2 -3 -1 0 -100000 0 -100000

-100000 -100000

4 6

8 6

结果输出为单纯形表, 每一轮迭代都会输出

![结果1](https://github.com/guner7451000/simplexTableau/blob/main/1.png)

![样例2](https://github.com/guner7451000/simplexTableau/blob/main/2.jpg)

输入

3 7

5 3 1 1 0 0 0 

-5 6 15 0 1 0 0

2 1 1 0 0 -1 1

0 0 0 0 0 0 -1

0 0 -1

3 4 6

9 15 5

## 一些废话

在上运筹学这门课, 但是单纯形表的计算太麻烦了, 经常算错, 于是写了这个小东西进行辅助计算
如果有不对的地方,欢迎指正
