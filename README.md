# JOISS-2020

JOI 夏季セミナー 2020 (8/25 〜 8/28) の成果物です。

テキスト : 高速文字列解析の世界（著:岡野原大輔)

## 1. Suffix Array

Induced Sorting と呼ばれるSuffix ArrayをO(N)で構築するアルゴリズムを実装しました (8/25) 。

全文検索機能である occ , locate も実装しました。

(参考文献)

- [2段階ソート - Shogo Computing Laboratory](https://shogo82148.github.io/homepage/memo/algorithm/suffix-array/two-stage.html)
- [SA-IS - Shogo Computing Laboratory](https://shogo82148.github.io/homepage/memo/algorithm/suffix-array/sa-is.html)

[ソースコード](./src/SuffixArray.cpp)

[Verify](https://onlinejudge.u-aizu.ac.jp/status/users/define_AC/submissions/1/ALDS1_14_B/judge/4792637/C++14)

## 2. Burrows Wheeler

Suffix Arrayを用いたBWT変換/復元を実装しました (8/25) 。

[ソースコード](./src/BWT.cpp)

## 3. Wavelet Matrix

文字列解析に必要な rank のみ実装しました (8/26) 。

[ソースコード](src/WaveletMatrix.cpp)

## 4. FM-index

FM-index を用いた高速な全文検索を実装しました (8/26) 。

[ソースコード](src/FM_index.cpp)