#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<n;i++)
#define rev(i,n) for(int i=n-1;i>=0;i--)
#define all(v) v.begin(),v.end()
#define P pair<int,int>
#define len(s) (int)s.size()
 
template<class T> inline bool chmin(T &a, T b){
	if(a>b){a=b;return true;}
	return false;
}
template<class T> inline bool chmax(T &a, T b){
	if(a<b){a=b;return true;}
	return false;
}
constexpr int mod = 1e9+7;
constexpr long long inf = 3e18;

template<class T>
class SuffixArray{
	#define typeS make_pair(false,false)
	#define LMS make_pair(false,true)
	#define typeL make_pair(true,true)
	using TYPE=pair<bool,bool>;
	vector<TYPE>assignType(vector<int>&S){
		vector<TYPE>type(len(S));
		type[len(S)-1]={0,0};
		for(int i=len(S)-2;i>=0;i--){
			if(S[i]<S[i+1])type[i]=typeS;
			else if(S[i]>S[i+1]){
				type[i]=typeL;
				if(type[i+1]==typeS)type[i+1]=LMS;
			}else type[i]=type[i+1];
		}
		return type;
	}
	vector<int>getBucket(vector<int>&S,int alph){
		vector<int>bucket(alph);
		for(int i:S)bucket[i]++;
		rep(i,len(bucket)-1)bucket[i+1]+=bucket[i];
		return bucket;
	}
	void sortTypeL(vector<int>&S,vector<int>&SA,vector<TYPE>&type,int alph){
		vector<int>bucket=getBucket(S,alph);
		rep(i,len(S))if(SA[i]>0&&type[SA[i]-1]==typeL)SA[bucket[S[SA[i]-1]-1]++]=SA[i]-1;
	}
	void sortTypeS(vector<int>&S,vector<int>&SA,vector<TYPE>&type,int alph){
		vector<int>bucket=getBucket(S,alph);
		rev(i,len(S))if(SA[i]>0&&type[SA[i]-1]==typeS||type[SA[i]-1]==LMS){
			SA[--bucket[S[SA[i]-1]]]=SA[i]-1;
		}
	}
	vector<int>InducedSorting(vector<int>&S,int alph){
		vector<int>SA(len(S),-1);
		vector<TYPE>type=assignType(S);
		vector<int>bucket=getBucket(S,alph);
		vector<int>nextlms(len(S),-1),ordered_lms;
		int lastlms=-1;
		rep(i,len(S))if(type[i]==LMS){
			SA[--bucket[S[i]]]=i;
			if(lastlms!=-1)nextlms[lastlms]=i;
			lastlms=i;
			ordered_lms.push_back(i);
		}
		nextlms[lastlms]=lastlms;
		sortTypeL(S,SA,type,alph);
		sortTypeS(S,SA,type,alph);
		vector<int>lmses;
		for(int i:SA)if(type[i]==LMS)lmses.push_back(i);
		int nowrank=0;
		vector<int>newS={0};
		REP(i,len(lmses)){
			int pre=lmses[i-1],now=lmses[i];
			if(nextlms[pre]-pre!=nextlms[now]-now)newS.push_back(++nowrank);
			else {
				bool flag=false;
				rep(j,nextlms[pre]-pre+1){
					if(S[pre+j]!=S[now+j]){flag=true;break;}
				}
				if(flag)newS.push_back(++nowrank);
				else newS.push_back(nowrank);
			}
		}
		if(nowrank+1!=len(lmses)){
			vector<int>V(len(S),-1);
			rep(i,len(lmses)){
				V[lmses[i]]=newS[i];
			}
			vector<int>newnewS;
			rep(i,len(S))if(V[i]!=-1)newnewS.push_back(V[i]);
			vector<int>SA_=InducedSorting(newnewS,nowrank+1);
			vector<int>newlmses;
			for(int i:SA_)newlmses.push_back(ordered_lms[i]);
			lmses=newlmses;
		}else {
			vector<int>newlmses(len(lmses));
			rep(i,len(lmses))newlmses[newS[i]]=lmses[i];
			lmses=newlmses;
		}
		SA.assign(len(S),-1);
		bucket=getBucket(S,alph);
		rev(i,len(lmses)){
			SA[--bucket[S[lmses[i]]]]=lmses[i];
		}
		sortTypeL(S,SA,type,alph);
		sortTypeS(S,SA,type,alph);
		return SA;
	}
public:
	vector<int>SA;
	SuffixArray(T &S){
		int mn=inf,mx=-inf;
		for(auto i:S){
			chmin(mn,(int)i);chmax(mx,(int)i);
		}
		vector<int>newS;
		for(auto i:S)newS.push_back(i-mn+1);
		newS.push_back(0);
		SA=InducedSorting(newS,mx-mn+2);
	}
};
signed main(){
	cin.tie(0);ios::sync_with_stdio(false);
	string s;cin>>s;
	SuffixArray<string>SA(s);
	REP(i,len(SA.SA))cout<<SA.SA[i]<<" ";
	cout<<endl;
}
