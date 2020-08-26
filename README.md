# JOISS-2020

JOI 夏季セミナー 2020 (8/25 〜 8/28) の成果物です。

テキスト : 高速文字列解析の世界（著:岡野原大輔)

## 1. Suffix Array

Induced Sorting と呼ばれるSuffix ArrayをO(N)で構築するアルゴリズムを実装しました 。

全文検索機能である occ , locate も実装しました。

(参考文献)

- [2段階ソート - Shogo Computing Laboratory](https://shogo82148.github.io/homepage/memo/algorithm/suffix-array/two-stage.html)
- [SA-IS - Shogo Computing Laboratory](https://shogo82148.github.io/homepage/memo/algorithm/suffix-array/sa-is.html)

[ソースコード](./src/SuffixArray.cpp)

## 2. Burrows Wheeler

Suffix Arrayを用いたBWT変換/復元を実装しました。

[ソースコード](./src/BWT.cpp)

## 3. Bit Vector

Wavelet Matrixに使うためのBit Vectorを実装しました。

[ソースコード](./src/BitVector.cpp)

## 3. Wavelet Matrix

rank と quantile を実装しました 。

[ソースコード](src/WaveletMatrix.cpp)

## 4. FM-index

FM-index を用いた高速な全文検索を実装しました。メモリ圧縮はまだしていません。

[ソースコード](src/FM_index.cpp)

## Verify

Suffix Array , BWT , Bit Vector , Wavelet Matrix::rank , FM-index : https://onlinejudge.u-aizu.ac.jp/status/users/define_AC/submissions/1/ALDS1_14_B/judge/4797440/C++14

Wavelet Matrix::quantile : https://judge.yosupo.jp/submission/20203