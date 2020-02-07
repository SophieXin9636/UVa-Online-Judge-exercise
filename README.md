# UVa-OJ-Writeup
[UVa Online Judge](https://uva.onlinejudge.org)

## 2019/02/07
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
