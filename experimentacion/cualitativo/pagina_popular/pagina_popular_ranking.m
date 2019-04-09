# Tabla para pagina popular

hf = figure();

system("./../../../tp1 pagina_popular.txt 0.65");
x = dlmread(["pagina_popular.txt.out"], ' ', 1, 0);
pages = {};

for i = 1:length(x)
  pages{i} = ["Nodo " num2str(i) " - " num2str(x(i))];
endfor

explode = repmat(1, length(x), 1);
pie(x, explode, pages);
title("Ranking de Página Popular con p = 0.65");

print(hf, "pagina_popular_rank.pdf", "-dpdflatexstandalone");