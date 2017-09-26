Program Validare_Operatii;
Var f, FOK, FPunct, g  : Text;
    Intrare, Test, FCorect, FConcurent, Rezultate: String;
    Cod, Punctaj       : Integer;
    Min, MinOK,m,n     : longint;
    Op, K, nr          : Integer;
    NrTest             : Byte;
    CorectU, CorectP   : Boolean;
    Grpi, ee           : Integer;
    aa, bb             : File Of Byte;
    s1,s2,s3:string;
Procedure Mesaj(Mes: String; p: Byte);
Var Pct: String;
Begin

   WriteLn(p, ' puncte '+Mes);
   readln;
   halt;
End;

Function o1(n,k:longint):longint;
var p,c,r:longint;
    i:byte;
Begin
p:=1;
for i:=1 to k do
    p:=p*2;
c:=n div p;
r:=n mod p;
o1:=p*(2*c+1)+r;
end;

Function o2(n,k:longint):longint;
var p,c,r:longint;
    i:byte;
Begin
p:=1;
for i:=1 to k do
    p:=p*2;
c:=n div p;
r:=n mod p;
if r<p div 2 then o2:=(p div 2)*c+r
             else o2:=n;
end;

Procedure verif(var m:longint);
var i:byte;
begin
readln(f,nr);
        if IOResult <> 0 Then
                    Mesaj(' Fisierul de iesire contine caractere incorecte! ' , 0);
        if nr>60 then
                    Mesaj(' Numar de operatii prea mare! ' , 0)
                  else
            for i:=1 to nr do
                     begin
                     Read(f, op,k);
                     If (IOResult <> 0) or (k>32 ) Then
                        Mesaj(' Fisierul de iesire contine valori incorecte! ' , 0);
                      case op of
                          1:m:=o1(m,k);
                          2:m:=o2(m,k);
                          else
                        Mesaj(' Operatie incorecta! ' , 0);
                      end;
                     end;
end;

Begin
   {$I-}
   Assign(f, 'operatii.out'); Reset(f);
   If IOResult <> 0 Then
      Mesaj(' Fisierul de iesire ABSENT! ' , 0);
   Assign(g, 'operatii.in'); Reset(g);
   readln(g, m, n);
   close(g);
   Assign(FOK, 'operatii.ok'); Reset(FOK);
   CorectP := True;
   ReadLn(f, min);

   If IOResult <> 0 Then
            Mesaj(' Fisierul de iesire contine caractere incorecte! ' , 0);
   ReadLn(FOK, minOK);
   If min <> minOK Then
     Begin
       str(min, s1);
       str(minok, s2);
       Mesaj(' Valoare minima incorecta '+s1+'<>'+s2+' OK!', 0)
     End
   Else
     Begin
       verif(m);
       if m<>min then
          Mesaj(' Secventa de operatii pentru m nu obtine valoarea minima!', 2);
       verif(n);
       if n<>min then
          Mesaj(' Secventa de operatii pentu n nu obtine valoarea minima!', 2);
     End;
   {$I+}

   Mesaj(' TESTUL  CORECT !', 5)
End.

