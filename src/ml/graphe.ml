type graph = {
  n : int;
  mat : int array array;
}

let load_graph filename =
  let ic = open_in filename in
  let n = int_of_string (input_line ic) in
  let mat = Array.make_matrix n n 0 in
  for i = 0 to n - 1 do
    let line = input_line ic |> String.split_on_char ' ' in
    List.iteri (fun j v -> mat.(i).(j) <- int_of_string v) line
  done;
  close_in ic;
  { n; mat }
