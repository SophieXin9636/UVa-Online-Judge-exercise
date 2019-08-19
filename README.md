# UVa-OJ-Writeup
[UVa Online Judge](https://uva.onlinejudge.org)

## 20190819 Submit
### UVa#623 500!
* Strategy：Dynamic Programming
* 目的：減少重複計算
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

## [POJ: Peking University(PKU) Online Judge](http://poj.org/)
