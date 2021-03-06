社課測驗
===

# problems set

- 純輸出*1 G
- 簡單語法*1 A
- 數學*1 C
- if-else*2 H 
- for*2 D F
- 陣列*2 E
- 函數*1 B 
- 防破台*1

# 題目驗證說明
假設你寫題目K 則將程式碼命名成p**k**.cpp（J則是pj.cpp
在自己電腦執行一次之後 點擊pJ_check.exe
如果顯示Accept則正確 不然就要修正喔～

# pA. 鉿寽沃得 ok

你確定你真的會用驗證程式嗎？
輸出"Hello world!"來試試看程式碼吧！
```
input:
(沒有輸入喔)
output:
Hello world!
```

# pB.簡易加法 ok

請將你的程式碼命名為pa.cpp 
在自己電腦執行一次之後 點擊pA_check.exe
這題會有兩個輸入a, b兩個數字用空格隔開
請輸出a+b, 並且換行
```
smaple input1:
6 455
sample output1:
461
smaple input2:
-2 -1
sample output2:
-3
```

# pC. 起哲你害我的GPA好醜阿 ok

GPA是大學算分的方式，而他的概念就是把成績對照到固定的分數，就類似會考。
很燙是今年大一的學生，他在一些意外之下，修到了一門奇怪的微積分課，雖然已經學期末了，但是教授一直不跟他說他的微積分成績，很燙想要快速地知道他GPA究竟是多少，請問你能寫一個程式幫他計算他GPA是多少嗎?
每個人的一生中，幾乎可說碰到分數換算GPA這件事，是必然會發生的。李大釗曾經提到過，人生最高理想，在求達於真理。這段話讓我所有的疑惑頓時豁然開朗。一般來講，我們都必須務必慎重的考慮考慮。迪斯里說過一句著名的話，為理想的實現而生活，則生趣盎然。強烈建議大家把這段話牢牢記住。帶著這些問題，我們一起來審視分數換算GPA。分數換算GPA似乎是一種巧合，但如果我們從一個更大的角度看待問題，這似乎是一種不可避免的事實。面對如此難題，我們必須設想周全。
|分數|GPA|
|---|---|
|90-100|4.3|
|85-89|4|
|80-84|3.7|
|77-79|3.3|
|73-76|3|
|70-72|2.7|
|67-69|2.3|
|63-66|2|
|60-62|1.7|
|0-59|0|
```
輸入說明
輸入只有一個數字N，代表很燙拿到的微積分成績，請輸出他的GPA
0≤N≤100
輸出說明
請輸出修改過後的成績，並且將原順序倒過來輸出，請用空白隔開數字。

範例輸入
83

範例輸出
3.7
```

# pD.西式稀釋稀世珍寶
最近很流行什麼西式來、稀釋去的，但大 127 常常不知道要怎麼把A ml稀釋神秘的 $x\%$ 的溶液稀釋成 $y\%$ 的溶液Ｂ。
你能幫他寫一個程式計算嗎？

請假設：
體積具有加成性，即 a ml 的溶液Ａ加上 b ml 的水將會變成 a+b ml。

```
Input
輸入的第一行有兩個整數，x 以及 y。 保證 0<y≤x≤100
Output
請輸出一個整數，代表若要 1 公升的溶液Ｂ，需要多少 毫升 的溶液Ａ？請無條件捨去到整數
smaple input1:
95 75
sample output1:
789
```


# pE. 次方與階乘 ok
請讀入兩個數字$n,m$，並輸出$n^m + \frac{n!}{m!}$

```
輸入說明
輸入有兩個正整數n, m
1<=n<=10
0<=m<=5，且n>=m

輸出說明
請輸出n^m(n的m次方) + n!/m!
注意：請記得考慮m=0的情況(0!=1)

範例輸入
5 3
範例輸出
145
```

# pF. 3n+1 問題 ok
"考拉茲猜想"是指對於每一個正整數 n ，如果它是奇數，則對它乘3再加1，如果它是偶數，則對它除以2，如此循環，最終都能夠得到1。

例如：
n = 6，得到序列$6, 3, 10, 5, 16, 8, 4, 2, 1$，共需要8個步驟。
現在，請聰明的你計算一下，給定一個正整數，計算出它得到1所需的步驟數。
```
Input
輸入的第一行有一個整數n 。 保證 0<n<100
Output
請輸出一行包含一個整數，循環進行操作，得到1所需的步驟數。
Sample Input 1
6
Sample Output 1
8
```

# pG. 我愛零分 ok

就讀建功高中裡的學生大雄，最喜歡考零分了！一天因緣際會，大雄拿到了成績單，但他對自己許多沒考到零分的考卷並不滿意，希望可以把他們通通改成零分！但是因為大雄太厲害了，甚至可以考出低於零分的成績！所以他不希望改掉他負分的成績。
此外他還想惡作劇一下，把分數的順序偷偷顛倒。
現在請你幫忙大雄，把所有成績通通改成他喜歡的 0 分，但是如果有負數的成績，不需要更動。最後再把原本成績順序倒過來輸出。
```
輸入說明
第一行是一個整數n，代表總共有n個成績，接下來的n行裡，每行有一個整數s，代表大雄的原始成績。
1≤n≤10000
−100≤s≤100
輸出說明
請輸出修改過後的成績，並且將原順序倒過來輸出，請用空白隔開數字。

範例輸入
3 -15 33 90
範例說明
3 接下來有三個數字
-15 -> -15 (負分不用改)
33  -> 0 (改)
90  -> 0 (改)

最後再把順序倒過來輸出
範例輸出
0 0 -15
```


# pH.最小公倍數 ok

這題會有兩個輸入a, b兩個數字用空格隔開
請輸出a跟b的最小公倍數, 並且換行

```
smaple input1:
5 12
sample output1:
60
smaple input2:
8 16
sample output2:
16
```

# pI. 矩陣的翻轉 ok

針對所讀取到的矩陣進行翻轉。
```
輸入說明
第一行會有兩個數字，分別為 列(row)<100 和 行(column)<100，緊接著就是這個矩陣的內容

輸出說明
直接輸出翻轉後的矩陣

範例輸入 #1
2 3
3 1 2
8 5 4
範例輸出 #1
3 8
1 5
2 4
```