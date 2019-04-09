# Generate output for many probabilities

n = 100;
p = (0:1/n:1)(2:end-1);
err = [];

for i = p
  system(["./../../../tp1 test_15_segundos.txt " num2str(i)]);
  system(["mv test_15_segundos.txt.out test_15_segundos_" num2str(i)(3:end) ".txt.out"]);

  system(["./../../../generateMatrixA " num2str(i)  " test_15_segundos.txt test_15_segundos_matriz_" num2str(i)(3:end) ".txt.out"]);

  x = dlmread(["test_15_segundos_" num2str(i)(3:end) ".txt.out"], ' ', 1, 0);
  A = dlmread(["test_15_segundos_matriz_" num2str(i)(3:end) ".txt.out"], ' ', 0, 0);
  err = [err norm(A*x - x, 2)];

  system(["rm test_15_segundos_" num2str(i)(3:end) ".txt.out test_15_segundos_matriz_" num2str(i)(3:end) ".txt.out"]);
endfor

hf = figure();
plot(p, err);
xlabel("p")
ylabel("||Ax - x||")
title("Error en función de p")
axis([0, 1, min(err), max(err)])
print(hf, "p_error.pdf", "-dpdflatexstandalone");