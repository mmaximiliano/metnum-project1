# Tabla para pagina popular

hf = figure();

system("./../../../tp1 roba_exito.txt 0.65");
x = dlmread(["roba_exito.txt.out"], ' ', 1, 0);
pages = {};

for i = 1:length(x)
  pages{i} = ["Nodo " num2str(i) " - " num2str(x(i))];
endfor

explode = repmat(1, length(x), 1);
pie(x, explode, pages);
title("Ranking de Roba Éxito con p = 0.65");

print(hf, "roba_exito_rank.pdf", "-dpdflatexstandalone");