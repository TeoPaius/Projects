{autor,Carmen Minca}
var f,g:text;
    x,cmax,c,z,k,nrmax,i,j,nc,a,maxpar,n,nr:longint;
begin
  assign(f,'alice.in');
  reset(f);
  assign(g,'alice.out');
  rewrite(g);
  readln(f,n,k);

  for j:=1 to n do begin
      read(f,a);
      x:=a; z:=a;
      if (a mod 2 = 0) and (maxpar<a) then maxpar:=a;
      repeat
        a:=z; z:=x;
        cmax:=0; nc:=0;
        while x>0 do begin
          c:=x mod 10; x:=x div 10;
          if c>cmax then cmax:=c;
          nc:=nc+1
        end;
        nrmax:=0;
        for i:=1 to nc do nrmax:=nrmax*10+cmax;
        x:=nrmax-z;
      until (x<=9) or (x=z) or (x=a);

     if x=k then nr:=nr+1;
  end;


  writeln(g,maxpar);
  writeln(g,nr);
  close(f);
  close(g);
end.
