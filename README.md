Le Minishell est un projet réalisé au cours de la première année d'Epitech. C'est une implémentation basique d'un interpréteur de commandes (ou Shell Unix).

Implémentations :
- Récupération de l'environnement
- Gestion de l'environnement à l'aide des builtins env, setenv, unsetenv
- Gestion du prompt à l'aide des variables d'environnement USER, PWD et HOME
- Récupération des binaires à l'aide de la variable d'environnement PATH
- Exécution des binaires avec arguments
- Gestion du multi-commande (Les commandes doivent être séparées par un ';')
- Gestion des redirections droites simple et double
- Détection des signaux (SIGINT) et builtin "exit" implémenté

Projet respectant la norme Epitech : Un maximum de 5 fonctions par fichier, 24 lignes par fonction et 80 colonnes par ligne. Doit compiler avec les flags de compilations -ansi et -pedantic.
Les fonctions autorisées sont : write, malloc, free, exit, open, close, dup, fork, execve et wait.