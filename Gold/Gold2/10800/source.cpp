// 204ms, 40320KB

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<int> colors(N + 1), sizes(N + 1); //[공번호]
	for (int i = 1; i <= N; ++i)
		cin >> colors[i] >> sizes[i];
	vector<int> sortedBySize(N);
	for (int i = 0; i < N; ++i)
		sortedBySize[i] = i + 1;
	sort(sortedBySize.begin(), sortedBySize.end(), [&sizes](int a, int b) {
		return sizes[a] < sizes[b];
	});
	vector<int> indexs(N + 1); //[공번호]->sortedBySize에서의 인덱스
	vector<vector<int>> sortedBySizeGroupByColor(N + 1); //[색번호]->해당 색상을 가진 공들의 size기준 오름차순한 공번호 리스트
	indexs[0] = -1;
	for (int i = 0; i < N; ++i)
	{
		int num = sortedBySize[i];
		indexs[num] = i;
		sortedBySizeGroupByColor[colors[num]].push_back(num);
	}

	vector<int> prefixSumOfSortedBySize(N), prevSizeIdx(N);
	prefixSumOfSortedBySize[0] = sizes[sortedBySize[0]];
	prevSizeIdx[0] = -1;
	for (int i = 1; i < N; ++i)
	{
		int num = sortedBySize[i];
		prefixSumOfSortedBySize[i] = prefixSumOfSortedBySize[i - 1] + sizes[num];
		prevSizeIdx[i] = sizes[sortedBySize[i - 1]] == sizes[num] ? prevSizeIdx[i - 1] : i - 1;
	}
	
	vector<int> indexs2(N + 1);
	vector<vector<int>> prefixSumOfSortedBySizeGroupByColor(N + 1), prevSizeIdx2(N + 1);
	for (int i = 1; i <= N; ++i)
	{
		int jEnd = sortedBySizeGroupByColor[i].size();
		prefixSumOfSortedBySizeGroupByColor[i].resize(jEnd);
		prevSizeIdx2[i].resize(jEnd);
		if (jEnd)
		{
			int num = sortedBySizeGroupByColor[i][0];
			indexs2[num] = 0;
			prefixSumOfSortedBySizeGroupByColor[i][0] = sizes[num];
			prevSizeIdx2[i][0] = -1;
		}
		for (int j = 1; j < jEnd; ++j)
		{
			int num = sortedBySizeGroupByColor[i][j];
			indexs2[num] = j;
			prefixSumOfSortedBySizeGroupByColor[i][j] = prefixSumOfSortedBySizeGroupByColor[i][j - 1] + sizes[num];
			prevSizeIdx2[i][j] =
				j > 1 ?
				(prefixSumOfSortedBySizeGroupByColor[i][j - 1] - prefixSumOfSortedBySizeGroupByColor[i][j - 2] == sizes[num] ? prevSizeIdx2[i][j - 1] : j - 1) :
				(prefixSumOfSortedBySizeGroupByColor[i][j - 1] == sizes[num] ? prevSizeIdx2[i][j - 1] : j - 1);
		}
	}
	for (int i = 1; i <= N; ++i)
	{
		int color = colors[i];
		int idx1 = prevSizeIdx[indexs[i]];
		int sum1 = idx1 == -1 ? 0 : prefixSumOfSortedBySize[idx1];
		int idx2 = prevSizeIdx2[color][indexs2[i]];
		int sum2 = idx2 == -1 ? 0 : prefixSumOfSortedBySizeGroupByColor[color][idx2];
		cout << sum1 - sum2 <<'\n';
	}
}