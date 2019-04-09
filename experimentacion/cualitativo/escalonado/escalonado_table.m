# Tabla para escalonado

hf = figure();

system("./../../../tp1 escalonado.txt 0.65");
x = dlmread(["escalonado.txt.out"], ' ', 1, 0);
pages = {};

for i = 1:length(x)
  pages{i} = ["Nodo " num2str(i) " - " num2str(x(i))];
endfor

explode = repmat(1, length(x), 1);
pie(x, explode, pages);
title("Ranking de Escalonado con p = 0.65");

print(hf, "escalonado_rank.pdf", "-dpdflatexstandalone");