let time f x =
  let t0 = Unix.gettimeofday () in
  let r = f x in
  let t1 = Unix.gettimeofday () in
  (r, t1 -. t0)

let compare_algos g =
  let (res_ex, t_ex) = time Exhaustive.exhaustive g in
  let (res_bb, t_bb) = time Branch_and_bound.branch_and_bound g in

  Printf.printf "=== Comparaison OCaml ===\n";
  Printf.printf "%-20s | %-4s | %-10s\n" "Algorithme" "Coût" "Temps (s)";
  Printf.printf "%s\n" (String.make 36 '-');
  Printf.printf "%-20s | %4d | %.6f\n" "Exhaustive" res_ex t_ex;
  Printf.printf "%-20s | %4d | %.6f\n" "Branch & Bound" res_bb t_bb;

  if res_ex = res_bb then
    Printf.printf "\n✔ Résultats identiques\n"
  else
    Printf.printf "\n✘ Résultats différents\n"