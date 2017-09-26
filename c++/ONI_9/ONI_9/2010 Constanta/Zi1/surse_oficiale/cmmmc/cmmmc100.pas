//stelian ciurea
//descompunere in factori primi a lui n
//generare submultimi prin reprezentare in baza 2 pentru
//factorii primi care intra in u si respectiv in p
//si pentru calculat perechea de suma minima
//descompunere eficienta in factori primi
var rad,qq,k,nmax,p2,nrfp,n,n1,d,i,j,umini,vmini : longint;
    ct,u, v, rez1, rez2, mini : longint;
    fp,ex:array[1..50] of longint;
    b2:array[1..50] of byte;
    prime:array[1..10000] of longint;
    sita: array[1..50000] of byte;
    f,g : text;

function putere(baza,expo : longint) : longint;
var i:integer;
begin
  putere := 1;
  for i := 1 to expo do
    putere := putere * baza;
end;


begin
  assign(f,'cmmmc.in'); reset(f);
  assign(g,'cmmmc.out'); rewrite(g);

  k := 0;
  for i := 2 to 49999 do
   begin
    if sita[i]=0 then
      begin
        inc(k);
        prime[k] := i;
        j := i;
        while j<50000 do
          begin
            sita[j] := 1;
            inc(j,i)
          end
      end
   end;

{
  for i := 1 to k do
    write(prime[i]:8);
  writeln;
    writeln(k);
}

  readln(f,k);
  for qq := 1 to k do
  begin
  readln(f,n);
  mini := maxlongint;
  rez1 := 0;
  rez2 := 0;
  n1 := n;
  d := 1;
  i := 0;

  rad := trunc(sqrt(n));

  while n1<>1 do
   begin
      Ct := 0;
      while n1 mod prime[d] = 0 do
        begin
          inc(Ct);
          n1 := n1 div prime[d]
        end;
      if ct<>0 then
        begin
          inc(i);
          fp[i] := prime[d];
          ex[i] := ct;
          if n1=1 then break;
        end;
      inc(d);
      if prime[d] > rad then
       begin
        inc(i);
        fp[i] := n1;
        ex[i] := 1;
        break
       end

   end;

   nrfp := i;
   p2 := putere(2,nrfp);
   {
   writeln(p2);
   for i := 1 to nrfp do
     writeln(fp[i],' ',ex[i],' ',putere(fp[i],ex[i]));
   }


   for i := 0 to p2-1 do
     begin
       d := i;
       for j := 1 to nrfp do
       begin
        b2[j] := d mod 2;
        d := d div 2
       end;

       //for j := 1 to nrfp do write(b2[j],' ');  writeln;
       u := 1; v := 1; rez2 := 1;
       //calculez multiplii formati doar din factori primi la puteri maxime
       for j := 1 to nrfp do
         if b2[j]=1 then // astia ii iau in multimplul u
            u := u * putere(fp[j],ex[j])
         else
            v := v * putere(fp[j],ex[j]);
       if u + v < mini then
       begin
           mini := u + v;
           umini := u;
           vmini := v
       end;

       //calculez numarul de combinatii
       for j := 1 to nrfp do
         if b2[j]=1 then //astia ii iau la putere maxima in u => in v pot sa iau ce exponent vreau intre 1 si ex[j]
           rez2 := rez2 * (1+ex[j]);
       for j := 1 to nrfp do
         if b2[j]=0 then
           rez2 := rez2*ex[j];


       //writeln(u,' ',v);
       //writeln(rez2);
       rez1 := rez1 + rez2;
     end;
   write(g,rez1 div 2 + 1,' ');
   if umini < vmini then
     writeln(g,umini,' ',vmini)
   else
     writeln(g,vmini,' ',umini);


   end;
   close(g);
//   readln
end.
