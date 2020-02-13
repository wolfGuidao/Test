class Solution {
public:
	bool Sequence(vector<int> sequence, int start, int end)
	{
		if (sequence.size() < 1 || start > end)
		{
			return false;
		}

		int mid;
		int i;
		int j;
		for (int i = 0; i < end; i++)
		{
			if (sequence[i] > sequence[end])
			{
				mid = i;
				break;
			}
		}
		for (int j = mid; j < end; j++)
		{
			if (sequence[j] < sequence[end])
			{
				return false;
			}
		}
		bool left = true;
		if (i > 0)
		{
			left = Sequence(sequence, 0, mid - 1);
		}
		bool right = true;
		if (j < end)
		{
			right = Sequence(sequence, mid, end);
		}
		return right && left;
	}
	bool VerifySquenceOfBST(vector<int> sequence) {
		if (sequence.size() < 1)
		{
			return false;
		}
		if (sequence.size() == 1)
		{
			return true;
		}

		return Sequence(sequence, 0, sequence.size() - 1);

	}
};
class Solution {
public:
	bool Sequence(vector<int> sequence, int start, int end)
	{
		if (sequence.size() < 1 || start > end)
		{
			return false;
		}

		int mid;
		int i;
		int j;
		for (int i = 0; i < end; i++)//�������飬��Ϊ������������У����һ��Ԫ�ؿ϶��Ǹ����
			//����Ϊ�Ƕ����������������������ȸ�С���������ȸ��󣬱����ҵ���һ���ȸ���Ľڵ�
			//��mid��¼����
		{
			if (sequence[i] > sequence[end])
			{
				mid = i;
				break;
			}
		}
		for (int j = mid; j < end; j++)//�ӵ�һ���ȸ��ڵ��Ľڵ㿪ʼ��������ֱȸ����С�Ľڵ�
			//��ֱ�ӷ���false�������˵�����εݹ���������
		{
			if (sequence[j] < sequence[end])
			{
				return false;
			}
		}
		bool left = true;//�ݹ���ߵı�־
		if (i > 0)
		{
			left = Sequence(sequence, 0, mid - 1);
		}
		bool right = true;//�ݹ��ұߵı�־
		if (j < end)
		{
			right = Sequence(sequence, mid + 1, end - 1);
		}
		return right && left;
	}
	bool VerifySquenceOfBST(vector<int> sequence) {
		if (sequence.size() < 1)
		{
			return false;
		}
		if (sequence.size() == 1)
		{
			return true;
		}

		return Sequence(sequence, 0, sequence.size() - 1);

	}
};