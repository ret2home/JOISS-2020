#include "./SuffixArray.cpp"

template<class T>
T BWT(T S){
    SuffixArray<T>SA(S);
    S+='$';
    T bwt;
    rep(i,len(S)){
        bwt.push_back(S[(SA.SA[i]-1+len(S))%len(S)]);
    }
    return bwt;
}