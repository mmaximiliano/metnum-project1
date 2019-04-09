# Calculate errors from all results.
files = {"test_15_segundos"; "test_30_segundos"; "test_aleatorio_desordenado";
         "test_aleatorio"; "test_completo"; "test_sin_links"; "test_trivial"};

for i = 1:rows(files)
  resultsPropios = ["outputs/" files{i} ".txt.out"];
  resultsCatedra = ["../../tests/txt/" files{i} ".txt.out"];

  v = dlmread(resultsPropios, ' ', 1, 0);
  w = dlmread(resultsCatedra, ' ', 1, 0);

  err2 = norm(v-w);
  puts([files{i} "\n"]);
  puts([repmat("-", 1, length(files{i})) "\n"]);
  puts(["Norma 2: " num2str(err2) "\n"]);

  err1 = norm(v-w, 1);
  puts(["Norma 1: " num2str(err1) "\n"]);

  mat = ["matrices/" files{i} "_matriz.txt"];
  A = dlmread(mat, ' ', 0, 0);
  err2mat = norm(A*v - v);
  puts(["||Ax - x||2: " num2str(err2mat) "\n"]);

  err1mat = norm(A*v - v, 1);
  puts(["||Ax - x||1: " num2str(err1mat) "\n\n"]);
endfor
