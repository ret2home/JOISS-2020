#include "WaveletMatrix.cpp"
#include "BWT.cpp"
#pragma once

template<class T,class C>
class FMIndex{
    int N,base;
    T bwt;
    vector<int>c;
    WaveletMatrix<T,C>WM;
    SuffixArray<T>SA;
    public:
    T ST;
    P occ(T &S){
        for(auto i:S)if((int)i<base||(int)i-base>=len(c))return P(0,0);
        int sp=0,ep=N;
        rev(i,len(S)){
            sp=c[(int)S[i]-base]+WM.rank(S[i],sp);
            ep=c[(int)S[i]-base]+WM.rank(S[i],ep);
            if(sp>=ep)return P(0,0);
        }
        return P(sp,ep);
    }
    vector<int>locate(T &S){
        P range=occ(S);
        vector<int>res;
        for(int i=range.first;i<range.second;i++)res.emplace_back(SA[i]);
        sort(all(res));
        return res;
    }
    FMIndex(T S):N(len(S)+1),ST(S+'$'),WM(S),SA(S){
        bwt=BWT(S,SA);
        WM=WaveletMatrix<T,C>(bwt);
        int mn=inf,mx=-inf;
        for(C i:ST){
            chmin(mn,(int)i);
            chmax(mx,(int)i);
        }
        c.resize(mx-mn+2);
        for(C i:ST){
            c[(int)i-mn+1]++;
        }
        rep(i,mx-mn+1)c[i+1]+=c[i];
        base=mn;
    }
};