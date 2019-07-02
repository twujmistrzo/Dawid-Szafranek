% Czyszczenie drukarki
while(s.BytesAvailable)
    fscanf(s)
end
poprzedniea = 0;
poprzednieb = 0;
poprzedniec = 0;
for t = 0:0.1:10
    a = round(100 * sin(t))
    b = round(100 * sin(0+ 2/3 * pi))
    c = round(100 * sin(0+ 4/3 * pi))
fprintf(s,'x %d y %d z %d\n',[a- poprzedniea,b- poprzednieb,c- poprzedniec])
while(s.BytesAvailable == 0)
    ;
end
fscanf(s)
poprzedniea = a;
poprzednieb = b;
poprzedniec = c;



% fprintf(s,'x -900 y -900 z -900')
% while(s.BytesAvailable == 0);
% end
% fscanf(s)


end
