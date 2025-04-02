# 两数之和

用哈希表存储遍历过的数以及其位置，每次O(1)的查询即可知道过去的信息

Java中的哈希表：
```java
import java.util.HashMap;
import java.util.Map;

Map <Integer, Integer> map = new HashMap<>();
```

C++中的哈希表：
```cpp
#include <unordered_map>

unordered_map<int, int> hash;
```


