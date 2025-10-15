Chaque partie explore un mécanisme essentiel utilisé dans les systèmes distribués sécurisés comme Bitcoin ou Ethereum.

Arbre de Merkle (Exercice 1)
→ Construction d’un arbre binaire de hachage permettant de résumer et vérifier l’intégrité des transactions.
Le Merkle Root représente la signature unique de l’ensemble des transactions d’un bloc.

Proof of Work (Exercice 2)
→ Implémentation du minage : un mécanisme de consensus basé sur le calcul intensif d’un hash commençant par un certain nombre de zéros.
Le temps d’exécution augmente avec la difficulté, démontrant la sécurité du PoW mais aussi sa consommation énergétique.

Proof of Stake (Exercice 3)
→ Implémentation d’un consensus alternatif où un validateur est choisi aléatoirement selon sa mise (“stake”).
Ce système est plus rapide et moins énergivore que le PoW, mais repose sur la confiance dans les validateurs.

Mini Blockchain complète (Exercice 4)
→ Intégration des éléments précédents pour créer une blockchain fonctionnelle from scratch, capable de :

Résumer les transactions (Merkle Tree)

Sécuriser les blocs (PoW)

Valider via PoS (alternative rapide)

Vérifier la cohérence et l’intégrité de la chaîne

Une analyse comparative entre PoW et PoS montre que :

PoW est plus sûr mais plus lent et énergivore,

PoS est plus rapide et efficace, idéal pour les blockchains modernes.
