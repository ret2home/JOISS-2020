#include "template.cpp"
#pragma once

template<class T,class C>
class WaveletMatrix{
    int N;
    vector<int>index[30];
    map<C,int>st;
public:
    T body;
    int rank(C c,int idx){
        if(st.find(c)==st.end())return 0;
        rev(i,30){
            if(c>>i&1)idx=index[i][idx]+(N-index[i][N]);
            else idx-=index[i][idx];
        }
        return max(0,idx-st[c]);
    }
    int quantile(int l,int r,int c){
        int res=0;
        rev(i,30){
            int cnt=(r-l)-(index[i][r]-index[i][l]);
            if(cnt<=c){
                c-=cnt;
                l=(N-index[i][N])+index[i][l];
                r=(N-index[i][N])+index[i][r];
                res+=1<<i;
            }else {
                l-=index[i][l];
                r-=index[i][r];
            }
        }
        return res;
    }
    WaveletMatrix(T V):N(len(V)),body(V){
        rev(i,30){
            T newV[2];
            index[i].push_back(0);
            rep(j,N){
                index[i].push_back((V[j]>>i&1)+index[i].back());
                newV[V[j]>>i&1].push_back(V[j]);
            }
            V=newV[0];V.insert(V.end(),all(newV[1]));
        }
        rep(i,N)if(st.find(V[i])==st.end())st[V[i]]=i;
    }
};