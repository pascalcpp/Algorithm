#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
std::vector<int> first_Evil_Numbers;
int ncount = 0;
int tmpcount = 0;
int cur_Number=0;
void find_All(int n);
int  find_MaxEvil(int n);
void find_EvilNumbers(int n);
int main()
{
	find_All(0);
	std::sort(first_Evil_Numbers.begin(), first_Evil_Numbers.end());
	int N;
	std::cin >> N;
	find_EvilNumbers(N);      // O(n^2)
	if (ncount != 0)
		std::cout << ncount << std::endl;
	else
		std::cout << "error" << std::endl;   
	return 0;
}
void find_All(int n){
	int tmp = n;
	if (cur_Number == 6)
		return;
	n = tmp * 10 + 7;
	//if (n == 777474747)
	//	return;
	++cur_Number;
	first_Evil_Numbers.push_back(n);
	find_All(n);
	--cur_Number;
	n = tmp * 10 + 4;
	/*if (n == 777474747)
	return;*/
	++cur_Number;
	first_Evil_Numbers.push_back(n);
	find_All(n);
	--cur_Number;
}
int  find_MaxEvil(int n)
{
	int cur = 125;
	while (cur>=0&&first_Evil_Numbers[cur] > n)
	{
		--cur;
	}
	if (cur < 0)
		return 0;
		
		return cur;
}
void find_EvilNumbers(int n){
	int cur;
	cur = find_MaxEvil(n);
	if (cur < 0){
		return;
	}
	if (n < 0)
		return;

	if (n == 0){
		if ((tmpcount < ncount)||(tmpcount>ncount && ncount==0))
			ncount = tmpcount;
			return;
	}
	while (cur >= 0){
		++tmpcount;
		find_EvilNumbers(n - first_Evil_Numbers[cur]);
		--tmpcount;
		--cur;
	}

}



