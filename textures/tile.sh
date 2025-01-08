#!/bin/bash

# Dossier contenant les fichiers PNG
input_dir="Objects/5_Grass"  # Remplace par le chemin du dossier si nécessaire

# Taille cible
resize_dim="50x50"

# Parcourir tous les fichiers .png dans le dossier
for file in "$input_dir"/*.png; do
    # Vérifie que des fichiers .png existent
    if [ -e "$file" ]; then
        # Récupère le nom de fichier sans l'extension
        base_name=$(basename "$file" .png)
        # Définit le nom de sortie
        output_file="$input_dir/${base_name}.xpm"
        # Redimensionne l'image et convertit au format .xpm
        convert "$file" -resize "$resize_dim" "$output_file"
        echo "Converti : $file -> $output_file"
        rm "$file"
        echo "$file supprime"
    fi
done

echo "Traitement terminé."

