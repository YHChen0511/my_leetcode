# 56.合并区间

先按照左端点排序，然后遍历，如果当前区间的左端点小于等于前一个区间的右端点，那么就合并，否则就直接加入答案。