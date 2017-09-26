#include <stdio.h>
#include <string.h>

char e[256];

int nv, pos;
char c[26];
int t[256];

int echivalenta(void);

int not(void)
{
	if (e[pos] == '~')
	{
		pos++;
		return !not();
	}
	else if (e[pos] >= 'a' && e[pos] <= 'z')
	{
  		return t[(int)e[pos++]];
	}
	else if (e[pos] == '(')
	{
		int v;

		pos++;
		v = echivalenta();
		pos++;
		return v;
	}
	
	return 0; // SHOULD NEVER HAPPEN; KEEPS COMPILER HAPPY
}

int si(void)
{
	int value = not(), v;
	
	while (e[pos] == '&')
	{
		pos++;
		v = not();
		value = value && v;
	}
	return value;
}

int sau(void)
{
	int value = si(), v;
	
	while (e[pos] == '|')
	{
		pos++;
		v = sau();
		value = value || v;
	}
	return value;
}

int implicatie(void)
{
	int value = sau(), v;
	
	while (e[pos] == '=')
	{
		pos += 2;
		v = implicatie();
		value = (!value) || v;
	}
	return value;
}

int echivalenta(void)
{
	int value = implicatie(), v;
	
	while (e[pos] == '<')
	{
		pos += 3;
		v = echivalenta();
		value = value == v;
	}
	return value;
}

int main(void)
{
	FILE *fi, *fo;
	int len, result;
	int i, j;
	int a[256];
	
	memset(e, 0, sizeof(e));
	fi = fopen("logic.in", "r");
	fscanf(fi, "%s", e);
	len = strlen(e);
	fclose(fi);

	memset(a, 0, sizeof(a));
	for (i = 0; i < len; i++) a[(int)e[i]]++;
	nv = 0;
	for (i = 'a'; i <= 'z'; i++)
		if (a[i]) c[nv++] = i;

	result = 0;
	for (i = 0; i < (1 << nv); i++)
	{
		for (j = 0; j < nv; j++)
			t[(int)c[j]] = i & (1 << j) ? 1 : 0;
		pos = 0;
  		result += echivalenta();
	}

	fo = fopen("logic.out", "w");
	fprintf(fo, "%d\n", result);
	fclose(fo);

	return 0;
}

