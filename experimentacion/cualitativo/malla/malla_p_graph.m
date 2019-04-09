# Generate output for many probabilities

p = [0.0001 0.25 0.5 0.75 0.999];
hf = figure();
c = 1;

for i = p
  system(["./../../../tp1 malla.txt " num2str(i)]);

  x = dlmread(["malla.txt.out"], ' ', 1, 0);
  pages = (1:length(x));
  subplot(3, 3, c);
  bar(pages, x);
  xlabel("Páginas");
  ylabel("Rankings");
  title(["Ranking de Malla con p = " num2str(i)]);
  ylim([0, 1]);
  c += 1;
endfor


print(hf, "malla_distintos_p.pdf", "-dpdflatexstandalone");