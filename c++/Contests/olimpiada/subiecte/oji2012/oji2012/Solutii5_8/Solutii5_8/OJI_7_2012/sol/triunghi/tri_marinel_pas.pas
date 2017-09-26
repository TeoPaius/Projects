{Serban Marinel - februarie 2012}
Program Triunghi;
CONST DIM = 1001;

Var fin, fout: Text;
    N: Integer;
    p: Array[1..DIM] Of Integer;
    L1, L2, v: Array[1..DIM] Of Int64;

Procedure citire;
Var i: Integer;
Begin
  ReadLn(fin, N);
  For i := N DownTo 1 Do             {le citesc invers ca sa lucrez}
    ReadLn(fin, p[i], v[i]);         {"mai usor" la reconstruire   }
  Close(fin);
End;

Procedure refa;
Var i, j: Integer;
Begin
  For i := 2 To N Do                 {refa linia i (de sus in jos) }
    Begin
      L2[p[i]] := v[i];              {pun in L2 valoarea cunoscuta }
      If p[i] > p[i - 1] Then        {detectez sensul recalcularii }
        Begin
          For j := p[i] - 1 DownTo 1 Do {intai spre stanga}
            L2[j] := L1[j] - L2[j + 1];
          For j := p[i] + 1 To i Do     {apoi spre dreapta}
            L2[j] := L1[j - 1] - L2[j - 1];
	End
      Else
        Begin
          For j := p[i] + 1 To i Do     {intai spre dreapta}
            L2[j] := L1[j - 1] - L2[j - 1];
          For j := p[i] - 1 DownTo 1 Do {apoi spre stanga  }
            L2[j] := L1[j] - L2[j + 1];
	End;
      For j := 1 To i Do                {copiez L2 in L1   }
        L1[j] := L2[j];                 {adica L2 devine L1}
      For j := 1 To i Do                {"curat" L2        }
        L2[j] := 0;                     {nu era neaparat necesar}
    End
End;

Procedure afisare;
Var i: Integer;
Begin
  For i := 1 To N - 1 Do              {afisez primele N-1 valori}
    Write(fout, L1[i], ' ');          {urmate de un spatiu}
  WriteLn(fout, L1[N]);           {apoi ultima valoare urmata de ENTER}
End;

Begin
  Assign(fin, 'triunghi.in');Reset(fin);
  Assign(fout, 'triunghi.out'); ReWrite(fout);
  citire;
  L1[1] := v[p[1]];
  refa;
  afisare;
  close(fout);
End.

