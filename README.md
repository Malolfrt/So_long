# 🕹️ so_long - Projet 42

## 📌 Description

**so_long** est un projet graphique du cursus de l’école **42**.  
Il s’agit de créer un **petit jeu en 2D** en utilisant la bibliothèque graphique **MiniLibX**.  
Le joueur doit se déplacer dans une carte pour **collecter des objets**, **éviter les ennemis** (bonus), et atteindre la **sortie** pour gagner.

Ce projet permet de découvrir les bases du **développement de jeu**, la gestion d’événements clavier, le **rendu graphique**, la lecture de fichiers `.ber` et l’organisation d’un **moteur de jeu simple**.

---

## 🎯 Objectifs pédagogiques

- Charger une **carte** depuis un fichier `.ber`
- Afficher la carte avec **MiniLibX**
- Gérer les **mouvements du joueur** via le clavier
- Implémenter une **vérification de map valide**
- Gérer les éléments : murs, sol, joueur, collectibles, sortie
- Afficher un **compteur de mouvements**
- (Bonus) Ajouter des ennemis ou des animations

---

## 🗺️ Carte - Format `.ber`

La carte est un fichier texte rectangulaire, contenant les caractères suivants :

| Élément     | Caractère | Description                    |
|-------------|-----------|--------------------------------|
| Mur         | `1`       | Infranchissable                |
| Sol         | `0`       | Zone libre                     |
| Joueur      | `P`       | Position de départ             |
| Collectible | `C`       | Objet à ramasser               |
| Sortie      | `E`       | Porte de sortie (active seulement si tous les `C` sont ramassés) |

---

## 🔁 Règles du jeu

- Le joueur peut se déplacer avec les touches **WASD**
- Il ne peut pas traverser les murs (`1`)
- Il doit **ramasser tous les objets `C`** pour débloquer la sortie `E`
- Le jeu se termine lorsque le joueur atteint la sortie

---

## 📦 Tester le projet

```bash
$ git clone https://github.com/vmondor/so_long.git
  cd so_long
  make
  ./so_long maps/map_valid.ber