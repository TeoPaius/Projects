program rezolvare;
var c:array['a'..'z'] of byte;
    n:array[0..9] of char;
    s:array[0..9999] of longint;
    g,f, h:text;
    i:byte;p:word;
    x2,x:string;k:longint;b:boolean;
{procedurile sunt fara variabile locale deoarece initial a fost un program fara subprograme}

procedure rezolva(nu:string);
begin
assign(f,nu);
reset(f);
readln(f,x);
for i:=0 to 9 do
 begin
  c[x[i+1]]:=i;
  n[i]:=x[i+1];
 end;
while not eof(f) do
 begin
   readln(f,x);
   p:=c[x[1]]*1000+c[x[2]]*100+c[x[3]]*10+c[x[4]];
   inc(s[p]);
 end;
close(f);
assign(f,'dqwtwau.wkt');
rewrite(f);
for p:=0 to 9999 do
  for k:=1 to s[p] do
  writeln(f,n[p div 1000]+n[(p div 100) mod 10]+n[(p div 10) mod 10]+n[p mod 10]);
close(f);
end;
procedure compara(nu1,nu2:string);
begin
assign(f,nu1);assign(g,nu2);
reset(f);reset(g);
b:=true;
while (not eof(f))and(not eof(g))and b do
 begin
   readln(f,x);readln(g,x2);
   b:=b and (x=x2);
 end;
 b:=b and eof(f)and eof(g);
end;

Begin

assign(h, 'seti.pct'); 
{$I-}
append(h);
{$I+}
If IOResult<>0 then ReWrite(h);
if paramcount=2 then
                    begin
                      rezolva(paramstr(1));
                      compara(paramstr(2),'dqwtwau.wkt');
                    end
                else
                    begin
                         rezolva('SETI.in');
                         compara('SETI.out','dqwtwau.wkt');
                    end;
if b then begin writeln(h, 10);writeln(' Ok-testul a fost trecut');end
  else begin writeln(h, 0);writeln(' test eronat');end;
close(h);
End.
