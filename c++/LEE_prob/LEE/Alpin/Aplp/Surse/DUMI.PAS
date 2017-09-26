
{ Dumitru Bogdan }

{ schita rezolvarii :
  - punctul 1 : creez un vector de 32.000 in care cate^[i] arata de cate ori
  este gasita valoarea i in matrice.  complexitate : o(n*m) - crearea se
  face baleind matricea citita.  afisez maximul acestui vector.  observatie :
  daca un element apare de mai multe ori in cadrul unei regiuni (evident, pe
  pozitii consecutive) il numar doar o data.
  - punctul 2 : utilizez programarea dinamica.  parcurg matricea de jos in
  sus. la un moment dat analizez elementul (i,j).  retin un vector in care
  pz[k] arata primul element de pe linia k mai mare decat elementul (i,j) -
  adica un posibil succesor pe traseu.  aleg maximul dintre posibilii
  succesori.  complexitate : pentru analiza unei linii se baleiaza matricea
  de sub linia respectiva; deci o(m^2*n). }

program alpinist2;

const ni='harta.in';
      no1='harta1.out';
      no2='harta2.out';
      nmax=50;
      vmax=32000;

type sir=array [0..vmax] of integer;
     psir=^sir;
     celula=record
                  l,c:byte;
            end;

var f:text;
    a:array [1..nmax,1..nmax] of integer;
    max:array [1..nmax,1..nmax] of integer;
    succ:array [1..nmax,1..nmax] of celula;
    s,pz:array [1..nmax] of integer;
    cate:psir;
    next:celula;
    n,m,i,j,k,maxim,l,c,ll,cc:integer;

procedure load;
begin
     new(cate);
     assign(f,ni);reset(f);
     readln(f,n,m);
     for i:=1 to n do begin
        for j:=1 to m do
           read(f,a[i,j]);
        readln(f);
                      end;
     close(f);
end;

procedure punctul_1;
begin
     for i:=0 to vmax do
        cate^[i]:=0;
     for i:=1 to n do begin
        cate^[a[i,1]]:=cate^[a[i,1]]+1;
        for j:=2 to m do
           if a[i,j]>a[i,j-1] then cate^[a[i,j]]:=cate^[a[i,j]]+1;
                      end;
     maxim:=0;
     for i:=0 to vmax do
        if cate^[i]>maxim then begin
          maxim:=cate^[i];
          k:=i;
                               end;
     for i:=1 to n do begin
        s[i]:=0;
        for j:=1 to m do
           if a[i,j]=k then s[i]:=1;
                      end;
     assign(f,no1);rewrite(f);
     writeln(f,k);
     for i:=1 to n do
        if s[i]=1 then write(f,i,' ');
     writeln(f);
     close(f);
end;

procedure punctul_2;
begin
     for i:=1 to m do begin
        max[n,i]:=1;
        succ[n,i].l:=0;
        succ[n,i].c:=0;
                      end;
     for i:=n-1 downto 1 do begin
        for k:=i+1 to n do
           pz[k]:=1;
        for j:=1 to m do begin
           maxim:=-1;
           for k:=i+1 to n do begin
              while (a[k,pz[k]]<=a[i,j]) and (pz[k]<=m) do pz[k]:=pz[k]+1;
              if pz[k]<=m then
                if max[k,pz[k]]+1>maxim then begin
                  maxim:=max[k,pz[k]]+1;
                  next.l:=k;
                  next.c:=pz[k];
                                             end;
                              end;
           if maxim>-1 then begin
             max[i,j]:=maxim;
             succ[i,j]:=next;
                            end
           else begin
               max[i,j]:=1;
               succ[i,j].l:=0;
               succ[i,j].c:=0;
                end;
                         end;
                            end;
     maxim:=0;
     for i:=1 to n do
        for j:=1 to m do
           if max[i,j]>maxim then begin
             maxim:=max[i,j];
             l:=i;
             c:=j;
                                  end;
     assign(f,no2);rewrite(f);
     while not ((l=0) and (c=0)) do begin
          writeln(f,l,' ',c);
          ll:=succ[l,c].l;
          cc:=succ[l,c].c;
          l:=ll;
          c:=cc;
                                    end;
     close(f);
end;

begin {programul principal}
     load;
     punctul_1;
     punctul_2;
end.

