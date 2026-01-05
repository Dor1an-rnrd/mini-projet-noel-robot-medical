open Graphe
open Compare
open Io

let () =
  Printf.printf "=== Projet Robot Médical – OCaml ===\n\n";

  if Array.length Sys.argv < 2 then begin
    Printf.printf "Usage: %s <fichier_graphe.txt>\n" Sys.argv.(0);
    exit 1
  end;

  let filename = Sys.argv.(1) in
  let g = load_graph filename in

  Printf.printf "=== Graphe chargé ===\n";
  Array.iter (fun row ->
      Array.iter (fun v -> Printf.printf "%d " v) row;
      Printf.printf "\n"
  ) g.mat;

  Printf.printf "\n";
  compare_algos g
  