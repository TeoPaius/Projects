program sir;
var f,g:text;
    r,n,i:longint;
    s:longint;
begin
  assign(f,'sir.in');
  assign(g,'sir.out');
  reset(f);rewrite(g);
  s:=0;
  readln(f,n);
  for r:= 1 to n div 2 do
  begin
    i:= n-2*r;
    while i>0 do
    begin
      s:=s+i;
      i:= i-r;
    end;
  end;
  writeln(g,s);
  Close(g)
end.
