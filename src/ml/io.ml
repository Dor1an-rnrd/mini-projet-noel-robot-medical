open Graphe

let load_graph filename =
  let ic = open_in filename in

  (* Lire la taille *)
  let n =
    let l = input_line ic |> String.trim in
    int_of_string l
  in

  let mat = Array.make_matrix n n 0 in

  (* Lire la matrice n x n *)
  for i = 0 to n - 1 do
    let line = input_line ic |> String.trim in
    let values =
      line
      |> String.split_on_char ' '
      |> List.filter (fun s -> s <> "")
      |> List.map int_of_string
    in
    if List.length values <> n then
      failwith
        (Printf.sprintf
           "Mauvais nombre de colonnes à la ligne %d : attendu %d, obtenu %d"
           (i+1) n (List.length values));
    List.iteri (fun j v -> mat.(i).(j) <- v) values
  done;

  close_in ic;
  { n; mat }
