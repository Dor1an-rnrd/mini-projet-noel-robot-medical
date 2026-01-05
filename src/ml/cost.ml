let path_cost (g : Graphe.graph) path =
  let rec aux acc = function
    | [] | [_] -> acc
    | u :: v :: r ->
        let w = g.mat.(u).(v) in
        if w = 0 then max_int else aux (acc + w) (v :: r)
  in
  aux 0 path