# Compilateurs
CC = gcc
CFLAGS = -Wall -Wextra -O2 -Ic

OCAMLC = ocamlc
OCAMLFLAGS = unix.cma

# Dossiers
C_SRC = c
ML_SRC = ml
BUILD = build

OCAMLINC = -I $(BUILD)

# Fichiers C
C_FILES = \
	$(C_SRC)/common/graphe.c \
	$(C_SRC)/common/io.c \
	$(C_SRC)/common/cost.c \
	$(C_SRC)/algo/glouton.c \
	$(C_SRC)/algo/mst.c \
	$(C_SRC)/main.c

# Création du dossier build
$(BUILD):
	mkdir -p $(BUILD)

# Programme C
c_prog: $(BUILD)
	$(CC) $(CFLAGS) $(C_FILES) -o $(BUILD)/c_prog

# Cibles
all: c_prog ml_prog 

# Programme OCaml
ml_prog: $(BUILD)
	ocamlc -c ml/graphe.ml -o $(BUILD)/graphe.cmo
	ocamlc $(OCAMLINC) -c ml/io.ml -o $(BUILD)/io.cmo
	ocamlc $(OCAMLINC) -c ml/cost.ml -o $(BUILD)/cost.cmo
	ocamlc $(OCAMLINC) -c ml/exhaustive.ml -o $(BUILD)/exhaustive.cmo
	ocamlc $(OCAMLINC) -c ml/bound.ml -o $(BUILD)/bound.cmo
	ocamlc $(OCAMLINC) -c ml/branch_and_bound.ml -o $(BUILD)/branch_and_bound.cmo
	ocamlc $(OCAMLINC) -c ml/compare.ml -o $(BUILD)/compare.cmo
	ocamlc $(OCAMLINC) -c ml/main.ml -o $(BUILD)/main.cmo

	ocamlc -o $(BUILD)/ml_prog unix.cma \
	  $(BUILD)/graphe.cmo \
	  $(BUILD)/io.cmo \
	  $(BUILD)/cost.cmo \
	  $(BUILD)/exhaustive.cmo \
	  $(BUILD)/bound.cmo \
	  $(BUILD)/branch_and_bound.cmo \
	  $(BUILD)/compare.cmo \
	  $(BUILD)/main.cmo

clean:
	rm -rf $(BUILD)/* *.cmo *.cmi

.PHONY: all clean