var max,nd,n,i,x:longint;
    a:array[0..64000]of word;

    function pow(x:longint):longint;
var v:longint;
begin
 if x=0 then pow:=1
 else
  if x mod 2=0 then begin
    v:= pow(x div 2);
    pow:= (v * v)mod 12343
  end
  else
    pow:=2 * pow(x-1)
end;

begin
  assign(input,'munte.in'); reset(input);
  assign(output,'munte.out'); rewrite(output);

  readln(n); nd:=0; max:=-1;
  for i:=1 to n do begin
    readln(x);
    if a[x]=0 then inc(nd)
    else if a[x]=1 then dec(nd);
    inc(a[x]);
    if x>max then max:=x;
  end;
  if a[max]>1 then writeln(0)
  else
   if nd=n then
      writeln(pow(n-1)-2)
   else
      writeln(pow(nd-1));
  close(output);
end.