//Algo
/**
 * Entrées: deux listes triées l1 et l2
 * Sortie: une liste triée l3
 * Algo:
 * 
 *  TrieRecursif(l1,l2): 
 * *  Si l1 vide
 *     Ajouter l2 en fin de l3
 * Sinon
 *    Si l2 vide
 *      Ajouter l1 en fin de l3
 * 
 *  si valeur de l1 < valeur de l2:
 *     alors ajouter l1 en tete de l3
 *     TrieRecursif(reste(l1),l2)
 * 
 *  si valeur de l1 > valeur de l2:
 *    alors ajouter l2 en tete de l3
 *   TrieRecursif(l1,reste(l2))
 * 
 *  si valeur de l1 = valeur de l2:
 *   alors ajouter l1 et l2 en tete de l3
 *  TrieRecursif(reste(l1),reste(l2))
 *  
 * 
*/


//code c