# JOISS-2020

JOI 夏季セミナー 2020 (8/25 〜 8/28) の成果物です。

テキスト : 高速文字列解析の世界（著:岡野原大輔)

## 1. Suffix Array

Induced Sorting と呼ばれるSuffix ArrayをO(N)で構築するアルゴリズムを実装しました (8/25) 。

(参考文献)

- [2段階ソート - Shogo Computing Laboratory](https://shogo82148.github.io/homepage/memo/algorithm/suffix-array/two-stage.html)
- [SA-IS - Shogo Computing Laboratory](https://shogo82148.github.io/homepage/memo/algorithm/suffix-array/sa-is.html)

[ソースコード](./src/SuffixArray.cpp)

[Verify](https://judge.yosupo.jp/submission/20027)

## 2. Burrows Wheeler

Suffix Arrayを用いたBWT変換を実装しました (8/25) 。

[ソースコード](./src/BWT.cpp)