void exchange(char a[],int clen)
{
	if (a == NULL || clen <= 0)
	{
		return;
	}

	int count = 0;
	char* s1 = a;
	int len = 0;
	while (*s1 != '\0')
	{
		if (*s1 == ' ')
		{
			++count;
		}
		++len;
		++s1;
	}

	int newlen = len + 2 * count;
	int addlen = 2 * count;
	if (newlen > clen)
		return;
	for (int i = len-1;addlen>=0, i >= 0; i--)
	{
		if (a[i] == ' ')
		{
			a[i + addlen] = '0';
			addlen = addlen - 1;
			a[i + addlen] = '2';
			addlen = addlen - 1;
			a[i + addlen] = '%';

		}
		else
			a[i + addlen] = a[i];
	}

}


int main()
{
	char a[50] = "we are happy.";
	int len = sizeof(a);
	exchange(a,len);
	cout << a<< endl;
	system("pause");
	return 0;
}