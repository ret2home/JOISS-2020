#include "template.cpp"

template<class T>
class WaveletMatrix{
    int N;
    vector<T>index[40];
    map<T,T>st;
public:
    vector<T>body;
    int rank(T c,int idx){
        if(st.find(c)==st.end())return 0;
        rev(i,40){
            if(c>>i&1)idx=index[i][idx+1]+(N-index[i][N])-1;
            else idx-=index[i][idx+1];
        }
        return max(0ll,idx-st[c]+1);
    }
    WaveletMatrix(vector<T>&V):N(len(V)),body(V){
        rev(i,40){
            vector<T>newV[2];
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