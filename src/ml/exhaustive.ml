open Graphe
open Cost

let split_at n l =
  let rec aux i acc = function
    | [] -> List.rev acc, []
    | x :: xs as l ->
        if i = 0 then List.rev acc, l
        else aux (i - 1) (x :: acc) xs
  in
  aux n [] l

let rec permutations = function
  | [] -> [ [] ]
  | x :: xs ->
      List.concat (
        List.map
          (fun p ->
            List.init (List.length p + 1)
              (fun i ->
                let a, b = split_at i p in
                a @ [x] @ b))
          (permutations xs)
      )

let exhaustive (g : Graphe.graph) =
  let n = g.n in
  let nodes = List.init n (fun i -> i) in
  let best = ref max_int in

  List.iter (fun p ->
    let c = Cost.path_cost g p in
    if c < !best then best := c
  ) (permutations nodes);

  !best