program parc_zoli;

type matrice = array [0..1,0..10000] of longint;
type vector  = array [0..10000] of longint;

procedure swap(var x:longint;var y:longint);
var t:longint;
begin
	t:=x;
	x:=y;
	y:=t;
end;

procedure scufundare(p:longint;var a:matrice;n:longint);
var pozmax:longint;
begin
	pozmax:=p;
        if (2*p<=n) and (a[0,pozmax]<a[0,2*p]) then  pozmax:=2*p;
	if (2*p+1<=n) and (a[0,pozmax]<a[0][2*p+1]) then  pozmax:=2*p+1;
	if (p<>pozmax) then
		begin
			swap(a[0,p],a[0,pozmax]);
			swap(a[1,p],a[1,pozmax]);
			scufundare(pozmax,a,n);
		end;
end;

procedure heapsort(var a:matrice;n:longint);      {pistele de biciclete le sortez in ordine crescatoare}
var i:longint;
begin
	for i:=n div 2 downto 1 do
		scufundare(i,a,n);
	for i:=n downto 2 do
		begin
			swap(a[0,1],a[0,i]);
			swap(a[1,1],a[1,i]);
			scufundare(1,a,i-1);
		end;
end;

var pv,po:matrice;
    sv,so,segmx,segmy:vector;
    xp,yp,xg,yg,xpr,ypr,m,n,i,j,p2,startv, finishv,starto,finisho,d_oriz,d_vert,cx,cy,semnx,semny,kx,ky:longint;
    xinv,yinv:boolean;
    lung:real;
    fin,fout:text;

begin
	assign(fin,'parc.in');
        assign(fout,'parc.out');

        reset(fin);
        rewrite(fout);

	readln(fin,xp,yp);
	readln(fin,xg,yg,xpr,ypr);

	xinv:=false;
	yinv:=false;
	semnx:=1;
	semny:=1;

	if (xpr<xg) then       {voi prelucra doar un singur caz: cand gigel este in stanga-jos}
		begin
			xinv:=true;       {iar prietenul este in dreapta-sus}
			xg:=xp-xg;     {pentru a rezolva acest lucru, voi folosi simetrii pe OX si OY daca este necesar}
			xpr:=xp-xpr;
			semnx:=-1;
		end;

	if (ypr<yg) then
		begin
			yinv:=true;
			yg:=yp-yg;
			ypr:=yp-ypr;
			semny:=-1;
		end;

	if (xpr=xg) then
		begin
			writeln(fout,ypr-yg);
			writeln(fout,1);
			close(fout);
			exit;
		end;

	if (ypr=yg) then
		begin
			writeln(fout,xpr-xg);
			writeln(fout,1);
			close(fout);
			exit;
		end;

	readln(fin,m);

	if xinv then
		for i:=1 to m do
			begin
				readln(fin,pv[0,i],pv[1,i]);
				if (pv[0,i]<pv[1,i]) then swap(pv[0,i],pv[1,i]);
				pv[0,i]:=xp-pv[0,i];                           {citesc pistele verticale (x-urile) si daca e nevoie}
				pv[1,i]:=xp-pv[1,i];                           {transform in simetricul lor sa le prelucrez de la st. da dr.}
			end
	else
		for i:=1 to m do
			begin
				readln(fin,pv[0,i],pv[1,i]);
				if (pv[0,i]>pv[1,i]) then swap(pv[0,i],pv[1,i]);
			end;

	heapsort(pv,m);                           {sortez punctele in ordine crescatoare}

	readln(fin,n);

	if yinv then

        		for i:=1 to n do
			begin
				readln(fin,po[0,i],po[1,i]);            {citesc pistele orizontale (y-urile) si daca e nevoie}
				if (po[0,i]<po[1,i]) then swap(po[0,i],po[1,i]);    {le transform in simetricul lor sa le parcurg de jos in sus}
				po[0,i]:=yp-po[0,i];
				po[1,i]:=yp-po[1,i];
		end
	else
		for i:=1 to n do
		begin
			readln(fin,po[0,i],po[1,i]);
			if (po[0,i]>po[1,i]) then swap(po[0,i],po[1,i]);
		end;

	heapsort(po,n);                           {sortez punctele in ordine crescatoare}

	sv[0]:=0;
	for i:=1 to m do
		sv[i]:=sv[i-1]+pv[1,i]-pv[0,i];       {memorez grosimile pistelor, ca si sume partiale}
	so[0]:=0;
	for i:=1 to n do
		so[i]:=so[i-1]+po[1,i]-po[0,i];       {idem}

	startv:=1; 							{ma uit cate piste verticale sunt intre Gigel si prietenul lui}
	while (xg>pv[0,startv]) do
		startv:=startv+1;

	finishv:=m;
	while (xpr<pv[1,finishv]) do
		finishv:=finishv-1;

	starto:=1;					  		{ma uit cate piste orizontale sunt intre Gigel si prietenul lui}
	while (yg>po[0,starto]) do
		starto:=starto+1;

	finisho:=n;
	while (ypr<po[1,finisho]) do
		finisho:=finisho-1;

	d_oriz:=sv[finishv]-sv[startv-1];         {grosimea pistelor verticale}
	d_vert:=so[finisho]-so[starto-1];         {grosimea pistelor verticale}
	cx:=xpr-xg-d_oriz;               		  {cea mai scurta distanta dintre doua puncte se calculeaza dintr-un triunghi}
	cy:=ypr-yg-d_vert;                        {dreptunghic cu catele cx si cy}
	                                          {cx si cy reprezinta lungimile catetelor triunghiului dreptunghic fara pistele orizontale si verticale}
	lung:=sqrt(cx*cx+cy*cy)+d_oriz+d_vert;    {la lungimea ipotenuzei se adauga distantele orizontale si verticale}

	segmx[0]:=pv[0,startv]-xg;
	kx:=0;
	for i:=startv+1 to finishv do
		begin
			kx:=kx+1;
			segmx[kx]:=segmx[kx-1]+pv[0,i]-pv[1,i-1];
		end;

	segmy[0]:=po[0,starto]-yg;
	ky:=0;
	for i:=starto+1 to finisho do
		begin
			ky:=ky+1;
			segmy[ky]:=segmy[ky-1]+po[0,i]-po[1,i-1];
		end;

	p2:=1;
	i:=0;
	j:=0;
	while(i<=kx) and (j<=ky) do
		if (segmx[i]*cy=segmy[j]*cx) then
			begin
				p2:=p2*2;
				i:=i+1;
				j:=j+1;
			end
		else
			if (segmx[i]*cy>segmy[j]*cx) then
				j:=j+1
			else
				i:=i+1;
	writeln(fout,lung:0:6);
	writeln(fout,p2);

	close(fin);
	close(fout);
end.
