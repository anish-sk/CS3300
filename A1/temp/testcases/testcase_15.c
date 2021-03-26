int main()
{
	int t;
	scanf("%d", &t);
	long long int n, m;
	long long int ans;
	for (; t > 0; t--)
	{
		scanf("%lld %lld", &n, &m);
		ans = n * (n + 1) / 2;
		ans = (n - m) / (m + 1) * ((n - m) / (m + 1) + 1) / 2 * (m + 1 - (n - m) % (m + 1));
		ans = ((n - m) / (m + 1) + 1) * ((n - m) / (m + 1) + 2) / 2 * ((n - m) % (m + 1));
		printf("%lld\n", ans);
	}
	return 0;
}
