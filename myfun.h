// return y = x^n mod p; ��ƪ��ˤl�O�ƻ�....���O����@, �b�᭱ XD 
int function_name(int x, int n, int p)
{
	int i, m;
	m = x % p;
	for(i=1;i<n;++i)
	{
		m = (m * x) % p;
	}
	return m;	
} 
// compute n!
int fractorial(int n)
{
	return 1;
}