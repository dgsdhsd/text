#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
typedef struct qdwenti{                //桥岛问题 
	int in=0;
	int out[100];
	int days[100];
	int mm=0;
	
} MM;
MM sum[10000];
char Case[10001];
int I=1;
int J=0;
int num=1;
int funn(int n,int*ZZ){
	int i;
	for(i=0;ZZ[i]!='\0';i++)
	if (n==ZZ[i]) break;
	;
	ZZ[i]=n;
	
}
int fun(int n,int max){
	int i,j,k;
	int ZZ[10000];
	int Z=0;
//	queue<int> order;
	for(i=0;ZZ[Z]!='\0';i=ZZ[Z++]){
	for(j=0;j<sum[i].mm;j++)
	   {
	   	if(sum[i].days[j]>max&&Case[sum[i].out[j]]!='P')
		    {Case[sum[i].out[j]]='P';num++;funn(sum[i].out[j],ZZ);}                //order.push(sum[i].out[j]);
		if(num==n) return 1;
		
		
	}
	for(k=0;ZZ[k]!='\0';k++) cout<<ZZ[k];
	cout<<'p'<<'\n';
}
	return -1;
}

int main(){
	int i,j,k;
	int n,m,max,maxx,man;
	int upper,down;
	int x,y,z;
//	memset(case,-1,sizeof(case));
    freopen("input.txt","r",stdin);
	cin>>n>>m;
	cin>>sum[0].in>>sum[0].out[0]>>sum[0].days[0];
	Case[0]=0;
	max=sum[0].days[0];
	//for(i=1;i<10001;i++) case[i-1]=i;
	memset(Case,'0',sizeof(Case));
	Case[1]='P';
	for(i=1;i<m;i++)                                                    //输入 
	{cin>>x>>y>>z;
	
	if (x!=sum[I-1].in)  {
	sum[I-1].mm=J;sum[I].in=x;sum[I].out[0]=y;sum[I].days[0]=z;I++;J=0;
	
	if(z>max) max=z;
	continue;} 
	
		if(y==sum[I-1].out[J])
		{
			if(z>max) {max=z;sum[I-1].days[J]=z;}
		}
		else {
			sum[I-1].out[++J]=y;sum[I-1].days[J]=z;
		}
		
	}
	maxx=max/5+1;
	upper=max;down=0;
	while(1){
		man=fun(n,maxx);
		//cout<<upper<<' '<<down<<'\n';
		if(upper-down==1){
		//	cout<<upper<<' '<<down<<'\n';
			if(man>0)  cout<<maxx<<'Z';
			if(man==-1&&maxx!=upper) cout<<maxx+1<<'p';
			if(man==-1&&maxx!=down)   cout<<maxx-1<<'Q';
			break; 
		}
		if(man>0) {down=maxx;maxx=(upper-maxx)/2+1+down;}                  //这里在6到8 会有错误，一会解决 
		else if(man==-1)  {upper=maxx;maxx=(maxx-down)/2-1+down;}
		
		 
		
	}
	return 0;
} 
