var x,cuv:string;
    l:byte;
    nr:longint;
    f:text;
Function verifcuv(x:string):boolean;
var cod:boolean;
    i:byte;
begin
i:=2;
COD:=TRUE;
while (i<=length(x)) and cod do
      begin;
      cod:=x[i]>x[i-1];
      inc(i);
      end;
verifcuv:=cod;
end;
Procedure Sol(x:string);
begin
    if x=cuv then
        begin
             WriteLn(f,nr);
             close(f);
             Halt(0);
     end;
end;

Procedure Back(i:byte);
var j,aa:char;
begin
     if i=1 then aa:='a' else aa:=succ(x[i-1]);
     for j:=aa to 'z' do
         begin
              x:=X+j;
              if i<l then Back(i+1)
                 else begin
                      nr:=nr+1;
                      sol(x);
              end;
              delete(x,i,1);
     end;
end;

begin
     assign(f,'cod.in');
     reset(f);
     ReadLn(f,cuv);
     close(f);
     assign(f,'cod.out');
     rewrite(f);
     nr:=0;
     if verifcuv(cuv) then
          for l:=1 to length(cuv) do
              Back(1)
                    else
                writeln(f,0);
     close(f);
     end.
