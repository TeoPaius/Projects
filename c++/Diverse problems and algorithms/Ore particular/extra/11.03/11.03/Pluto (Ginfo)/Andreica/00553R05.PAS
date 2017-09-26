{ Mugurel Ionut Andreica - Bucuresti, ROMANIA }

Program _PLUTO_;

const filein='PLUTO.IN';
      fileout='PLUTO.OUT';
      MAXN=51;

var cap,flux:array[0..2*MAXN+1,0..2*MAXN+1] of byte;
    tata,tip:array[0..2*MAXN+1] of integer;
    extramat:array[1..MAXN,1..MAXN] of longint;
    i,j,k,m,n,p,t,nt,nl,fmax,po,nel,last:longint;
    q:array[1..3*MAXN] of longint;
    inq:array[0..2*MAXN+1] of boolean;

begin
assign(input,filein);
reset(input);

read(n,m);
last:=2*n+1;

fillchar(cap,sizeof(cap),0);
for i:=1 to n do
  read(cap[0,i]);
for i:=n+1 to 2*n do
  read(cap[i,last]);

for i:=1 to n do
  for j:=n+1 to 2*n do
    cap[i,j]:=1;

for i:= 1 to n do
  cap[i,i+n]:=0;

fmax:=0;
fillchar(flux,sizeof(flux),0);

for p := 1 to n do
  while (flux[0, p] < cap[0, p]) do
    begin
      fillchar(inq,sizeof(inq),false);
      fillchar(tata,sizeof(tata),0);
      fillchar(tip,sizeof(tip),0);

      po:=1; nel:=1;
      q[1]:=p;
      inq[p]:=true;

      while (po<=nel) and (not inq[last]) do
        begin
          i:=q[po];
          if (i<=n) then
            begin
              for j:=n+1 to 2*n do
                if (cap[i,j]=1) and (flux[i,j]=0) and (not inq[j]) then
                  begin
                    inq[j]:=true;
                    inc(nel);
                    q[nel]:=j;
                    tata[j]:=i;
                    tip[j]:=1;
                  end;
            end
          else
            begin
              if (cap[i,last] > flux[i,last]) then
                begin
                  inq[last]:=true;
                  tata[last]:=i;
                  tip[last]:=1;
                end;

              for j:=1 to n do
                if (cap[j,i]=1) and (flux[j,i]=1) and (not inq[j]) then
                  begin
                    inq[j]:=true;
                    inc(nel);
                    q[nel]:=j;
                    tata[j]:=i;
                    tip[j]:=2;
                  end;
            end;

          inc(po);
        end;

      if (inq[last]) then
        begin
          inc(fmax);
          inc(flux[0, p]);

          j:=last;
          i:=tata[last];

          while (i>0) do
            begin
              if (tip[j]=1) then
                begin
                  inc(flux[i,j]);
                  j:=i;
                  i:=tata[i];
                end
              else
                begin
                  dec(flux[j,i]);
                  j:=i;
                  i:=tata[i];
                end;
            end;
        end
      else
        break;
    end;

assign(output,fileout);
rewrite(output);
if (fmax < m) then
  writeln('NO')
else
  begin
    writeln('YES');

    for i:=1 to n do
      for j:=1 to n do
        if (flux[i,j+n] = 1) then
          writeln(i, ' ', j);
  end;

close(output);
end.