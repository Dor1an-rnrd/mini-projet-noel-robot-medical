open Graphe

let branch_and_bound (g : Graphe.graph) =
  let n = g.n in
  let mat = g.mat in
  let visited = Array.make n false in
  let best = ref max_int in

  let rec dfs path cost =
    if cost >= !best then ()
    else if List.length path = n then
      best := min !best cost
    else
      for v = 0 to n - 1 do
        if not visited.(v) then begin
          let u = List.hd (List.rev path) in
          let w = mat.(u).(v) in
          if w > 0 then begin
            visited.(v) <- true;
            dfs (path @ [v]) (cost + w);
            visited.(v) <- false
          end
        end
      done
  in

  visited.(0) <- true;
  dfs [0] 0;
  !best