open Graphe
open Cost

let lower_bound partial_cost remaining_min_edges =
  partial_cost + remaining_min_edges