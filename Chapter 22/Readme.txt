CycleInDG项目中,
line 13: list<int> *adj

此行略微诡异, 为何adj不被声明为: **adj
因为在代码中adj明明被作为二维数组使用
TestList就是为了验证CycleInDG中的代码
而TestList的代码也确实是一维数组!
https://blog.csdn.net/u014546553/article/details/53644898

line 13 是构造adjacent list的关键语法!

对Stack地应用非常到位,refer to E:\Project\VC\Interview\Chapter04\PathsWithSum4-12

============================================
SCC对Stack地应用也非常到位, stack在递归过程中, 可以显示记录process, refer to hanoi tower