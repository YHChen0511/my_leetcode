# 轮转数组

如果 $k>n$ ，则取 $k=k \mod n$

对于 $i \leq n-1-k$ 的数，轮转后的位置为 $i+k$ ，对于 $i > n-1-k$ 的数，轮转后的数字为 $i-n+k$。

注意到 $i+k = n + k - (n-i)$, $i-n+k = k - (n-i)$，所以我们可以将数组看作是两个部分， $i \leq n-1-k$ 和 $i > n-1-k$，对整个数组进行翻转($i \rightarrow n - i$)，然后对两个部分进行分别翻转($n - i \rightarrow k - n + i$ if $n - i \leq k$ 和 $n - i \rightarrow k + i$ if $n - i > k$)。
