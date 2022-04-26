# UVa-OJ-Writeup
[UVa Online Judge](https://uva.onlinejudge.org)

## 2022/4/25 BFS
* BFS: 3★ 10259
給 `n*n` 大小格子，每一步最多可以走距離 k (也就是 `1~k`)
方向有上下左右，隨著測資給定的k大小不同，每到新的位置都有 `4*k` 種鄰近選擇

k = 1 時，有 (0,1), (1,0), (0,-1), (-1,0) 共4種走法
k = 2 時，有 (0,1), (1,0), (0,-1), (-1,0), (0,2), (2,0), (0,-2), (-2,0) 共8種走法
依此類推，所以有 `4*k` 種走法
在進行 BFS 之前的一開始先 push (0,0) 原點，
開始 BFS 時，若 Queue 不為空，則從 Queue pop 出來，更新它鄰近的權重。

使用 Queue，每次當位置的權重更新時，將位置 push 到 Queue 裡。
若更新的權重大於目前儲存的 ans，則更新 ans，
最後 return 的 ans 就是最大權重。

## 2021/7/3

新增1~4星題目

1星多為裸題，2星需要一點點跳脫的思維，3星會需要有演算法的概念，4星會比三星難一些，甚至需要特殊解法

* Dynamic Programming:
  * 3★：10482、10664、10739、10912、11026、12034
  * 4★：147
* 質數表、質因數分解 (Prime Factorization)
  * 2★：1644
  * 3★：10539、10856、11353
  * 4★：11099
* 大數
  * 2★：10220、10924
  * 3★：10433
* 貪婪法則 (Greedy Method)
  * 2★：11264
  * 3★：11330
* BFS
  * 3★：122
* 圖論 Graph
  * Floyd-Warshall algorithm
    * 3★：10048、10099、11463
* 數學題
  * 4★：10396、10990
* 特殊解法
  * 3★：10312 (Super Catalan Number 以及 Catalan Number 特殊公式)



## 2020/02/07

### UVa# 122 Trees on travel
* 資料結構：binary tree
* 演算法：BFS
* 簡單來說就是 BFS的變形，同時判斷他是否為沒有斷掉的binary
* 如果拜訪到的數字與當初輸入的值不符合，則印出 not complete

## 2019/12/14
### UVa# 1644 Prime Gap
* 建立composite table
 * 若是質數(if c[n] == false)則直接印0
 * 若是合數(composite)，則將該值作為composite table 的 index 指針，
  * 指針分別為 b (負責遞減)、 a (負責遞增)
  * 若 c[b] 及 c[a] 為 false，則找到 質數，停止迴圈
  * a-b 即兩個質數的區間大小，就是答案

## 2019/08/19 Submit
### UVa# 623 500!
* 類似題目：UVa# 10220 - I Love Big Numbers !
* Strategy：Dynamic Programming
* 目的：減少重複計算、處理數字較大的問題
  * 舉例來說，測資一需要計算50!，測資二要我們求出48!，此時利用迭代將從1!到50!計算出來，並將結果儲存在陣列
* 利用空間換取時間，建立二維陣列記錄0!~1000!計算階乘之過程及結果
  * Time Complexity：**O(NlogN)**
  * Space Complexity：**O(N^2*logN)** 
* 由於階乘會超過整數值的記憶範圍，因此需額外建立每個階乘的位數，每個陣列元素儲存1個digit，減少每次計算下一個階乘時所要計算該階乘之位數
  * Time Complexity：**O(logN)**
  * Space Complexity：O(log(N!)) = **O(NlogN)**

**以單一測資計算1000!來看**
* Total Time Complexity：**O(NlogN)**
* Total Space Complexity：**O(N^2*logN)**

## Factorial
* UVa 623 568 10220 10323
