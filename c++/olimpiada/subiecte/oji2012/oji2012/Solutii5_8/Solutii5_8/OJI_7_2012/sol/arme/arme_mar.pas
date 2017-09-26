{Serban Marinel  }
{februarie - 2012}
Program Arme;
Type Huse = Array[1..2001] Of Integer;
Var Fin, Fout: Text;
    Brau, Perete: Huse;
    n, m, i, j, k: Integer;

Procedure Citire;
Var i: Integer;
Begin
  ReadLn(Fin, n, m);
  For i := 1 To n Do
    Read(Fin, Brau[i]);
  ReadLn(Fin);
  For i := 1 To m Do
    Read(Fin, Perete[i]);
  Close(Fin);
End;

Procedure Ordonare(Var X: Huse; Dim: Integer);
Var Max, PozMax, i, j: Integer;
Begin
  For i := 1 To Dim - 1 Do
    Begin
      Max := X[i]; PozMax := i;
      For j := i + 1 To Dim Do
        If X[j] > Max Then
          Begin
            Max := X[j]; PozMax := j
          End;
      X[PozMax] := X[i];
      X[i] := Max
    End;
End;

Function Interclasare: LongInt;
Var i, j, k: Integer;
    S: LongInt;
Begin
  S := 0;
  i := 1; j := 1; k := 0;
  While (i <= n) AND (j <= m) AND (k < n) Do
    If Brau[i] > Perete[j] Then
      Begin
        k := k + 1;
        S := S + Brau[i];
        i := i + 1;
      End
    Else
      Begin
        k := k + 1;
        S := S + Perete[j];
        j := j + 1
      End;
  While (i <= n) AND (k < n) Do
    Begin
      k := k + 1;
      S := S + Brau[i];
      i := i + 1
    End;
  While (j <= m) AND (k < n) Do
    Begin
      k := k + 1;
      S := S + Perete[j];
      j := j + 1
    End;
  Interclasare := S
End;

Begin
  Assign(Fin, 'arme.in'); Reset(Fin);
  Assign(Fout, 'arme.out'); ReWrite(Fout);

  Citire;
  Ordonare(Brau, n);
  Ordonare(Perete, m);
  WriteLn(Fout, Interclasare);
  Close(Fout);
End.
