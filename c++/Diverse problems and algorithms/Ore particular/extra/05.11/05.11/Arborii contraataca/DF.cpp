
void DF(int nod)
{
	s[nod] = 1;
	for (PNOD p = L[nod]; p; p = p->urm)
		if ( !s[p->vf] ) DF(p-.vf);
}

//sau
void DF(int nod, int t)
{
	for (PNOD p = L[nod]; p; p = p->urm)
		if (p->vf != t) DF(p->vf, nod);
}

// apelezi DF(1, 0)

//sau

void DF(int nod)
{
	for (PNOD p = L[nod]; p; p = p->urm)
		if ( p->vf != tata[nod])
		{
			DF(p->vf);
			tata[p->vf] = nod;
		}
}
// apelezi DF(radacina)
