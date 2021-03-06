# Generate output for many probabilities

n = 100;
p = (0:1/n:1)(2:end-1);
hf = figure();

mejor = [];
peor = [];
dif = [];

for i = p
  system(["./../../../tp1 pagina_popular.txt " num2str(i)]);

  x = dlmread(["pagina_popular.txt.out"], ' ', 1, 0);
  mejor = [mejor max(x)];
  peor = [peor min(x)];
  dif = [dif (max(x) - min(x))];
endfor

subplot(2, 1, 1);
hold on;
plot(p, mejor);
plot(p, peor);
hold off;
legend("El mejor ranking", "El peor ranking", "location", "northwest");
xlabel("p");
ylabel("Rankings");
title("Página Popular en función de p");
ylim([0, 1]);

subplot(2, 1, 2);
plot(p, dif);
legend("Diferencia entre el mejor y el peor", "location", "northwest");
xlabel("p");
ylabel("Diferencias");
title("Página Popular en función de p");
ylim([0, 1]);


print(hf, "pagina_popular_distintos_p.pdf", "-dpdflatexstandalone");