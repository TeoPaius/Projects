//brute force
var k,mini,i,u,v,n,ct,umini,vmini,qq:longint;
    f,g : text;
function ggt(a,b:longint):longint;
begin
  if a mod b = 0 then ggt := b
  else
    ggt := ggt(b, a mod b)
end;

begin
assign(f,'cmmmc.in');  reset(f);
assign(g,'cmmmc.out'); rewrite(g);
read(f,k);

for qq := 1 to k do
begin

  mini := maxlongint;
  ct := 0;
  read(f,n);
  for u := 1 to n do
    for v := u to n do
     if u div ggt(u,v) *v = n then
      begin
        //writeln(u,' ',v);
        inc(Ct);
        if u+v < mini then
        begin
          mini := u+v;
          umini := u;
          vmini := v;
        end;
      end;
  write(g,ct,' ');
  writeln(g,umini, ' ',vmini);
end;
close(g);
//readln
end.
