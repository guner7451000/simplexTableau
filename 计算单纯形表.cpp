#include<iostream>
#include<vector>

/**
 * 
 * create by Naiping Xiao
 * 
 **/ 
/**
样例
转化为标准形式吼 
X1 + 4X2 + 2X3 - X4 + X5 = 8
3X1 + 2X2 - X6 + X7 = 6 
X1,X2,X3,X4,X5,X6,X7 >= 0
Max Z = -2X1 -3X2 -X3 + 0X3 - MX5 + 0X6 - MX7

输入参数 
2
7
1 4 2 -1 1 0 0
3 2 0 0 0 -1 1
-2 -3 -1 0 -100000 0 -100000
-100000 -100000
4 6
8 6


 **/ 
using namespace std;

int x, y;
vector<int> cb;
vector<int> xb;
vector<double> b;
vector<int> value;
vector<vector<double>> calc;
vector<double> z;
vector<double> t;
void init();
void calcZ();
void calcM(int r, int l);
void calcT(int r);
int findMax(vector<double> v);
int findMin(vector<double> v);
void show();
bool check();
int main()
{
	init();
	while(1){
		calcZ();
		int tempR = findMax(z);
		calcT(tempR);
		show();
		if(check())break;
		getchar();
		getchar(); 
		int tempL = findMin(t);
		cb[tempL] = value[tempR];
		xb[tempL] = tempR;
		calcM(tempR, tempL);
	}
} 
/**
 * @brief 初始化, 输入
 *  
 * 
 **/ 
void init(){
	cout<<"input lines and columns"<<endl;
	cin>>x>>y;
		cb.resize(x);
		xb.resize(x);
		calc.resize(x);
		value.resize(y);
		z.resize(y);
		t.resize(x);
		b.resize(x);
		for(int i=0;i<x;i++){
			calc[i].resize(y);
			cout<<"input NO. "<<i+1<<" line"<<endl;
			for(int j=0;j<y;j++)cin>>calc[i][j];
		}
		cout<<"input value"<<endl;
		for(int i=0;i<y;i++)cin>>value[i];
		cout<<"input cb "<<endl;
		for(int i=0;i<x;i++){
			cin>>cb[i];
		}
		cout<<"input xb "<<endl;
		for(int i=0;i<x;i++)cin>>xb[i];
		cout<<"input b"<<endl;
		for(int i=0;i<x;i++)cin>>b[i]; 
}
/**
 * @brief 计算检验数 
 * 
 **/ 
void calcZ(){
	for(int i=0;i<y;i++){
		double temp = value[i];
		for(int j=0;j<x;j++)temp -= cb[j] * calc[j][i];
		z[i] = temp;
	}
}
/**
 * @brief 
 * 
 * @param v 
 * 
 * @return  最大值对应下标 
 **/ 
int findMax(vector<double> v){
	int ans = 0;
	int temp = v[0];
	for(int i = 0; i < v.size();i++){
		if(temp < v[i]){
			temp = v[i];
			ans = i;
		}
	}
	return ans;
}
/**
 * @brief 找到最小值对应下标, 大于0的最小值 
 * 
 * @param v 
 * 
 * @return 
 **/ 
int findMin(vector<double> v){
	
	int ans = 0;
		int temp = v[0];
		int i = 0;
		for(; i < v.size(); i++)
			if(v[i] > 0){
				temp = v[i];
				ans = i;
				break;
			}
		for(; i < v.size();i++){
			if(temp > v[i]&&v[i]>0){
				temp = v[i];
				ans = i;
			}
		}
		return ans;
}
/**
 * @brief 
 * 计算theta 
 * @param r 
 **/ 
void calcT(int r){
	for(int i=0;i<x;i++){
		if(calc[i][r] == 0){
			t[i] = -1;
		}
		else if(b[i] / calc[i][r] <= 0){
			t[i] = -1;
		}else t[i] = b[i] / calc[i][r];
	}
}
/*
	计算中间的矩阵
	输入参数 r 表示列, l 表示行 
*/
void calcM(int r, int l){
	double temp = calc[l][r];
	for(int i=0;i<y;i++)calc[l][i] /= temp;
	b[l] /= temp;
	for(int i=0;i<x;i++){
		if(i == l)continue;
		double temp2 = calc[i][r];
		for(int j=0;j<y;j++)
			calc[i][j] -= calc[l][j] * temp2;
		b[i] -= b[l]*temp2;
	}
}
/*
信息展示 
*/ 
void show(){
	cout<<"	Cj		";
	for(int i=0;i<y;i++)
		cout<<value[i]<<"	";
	cout<<endl;
	cout<<"Cb	Xb	b	";
	for(int i=0;i<y;i++)
		cout<<"X"<<i+1<<"	";
	cout<<"	theta"<<endl;
	for(int i=0;i<x;i++){
		cout<<cb[i]<<"	";
		cout<<"X"<<xb[i] + 1<<"	";
		cout<<b[i]<<"	";
		for(int j=0;j<y;j++)
			cout<<calc[i][j]<<"	";
		cout<<"	"<<t[i]<<endl;
	}
	cout<<"----------------------------------------------------------------------------------------------------------"<<endl; 
	cout<<"z		";
	for(int i=0;i<y;i++)
		printf("%.2f\t",z[i]);
	cout<<endl;
	cout<<"----------------------------------------------------------------------------------------------------------"<<endl;
	cout<<endl;
}
/**
 * @brief 
 * 检查是否所有的检验数是否全部小于0  
 * 
 * @return 
 **/ 
bool check(){
	for(int i=0;i<y;i++)if(z[i]>0)return false;
	return true;
}
