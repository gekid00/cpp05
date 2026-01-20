# CPP05 - Context & Progress Tracker

**Date de création** : 2026-01-20
**Objectif** : Compléter le module CPP05 (Exceptions et Bureaucratie)

---

## 📊 État d'avancement global

- [ ] Ex00 : Bureaucrat (base avec exceptions)
- [ ] Ex01 : Form (formulaires à signer)
- [ ] Ex02 : Formulaires concrets (héritage + AForm)
- [ ] Ex03 : Intern (factory pattern)

---

## 🎯 Exercice en cours : **EX00**

### Objectifs Ex00
- Créer la classe `Bureaucrat` avec :
  - Attribut `name` (constant)
  - Attribut `grade` (1-150)
  - Exceptions personnalisées : `GradeTooHighException` et `GradeTooLowException`
  - Getters : `getName()` et `getGrade()`
  - Méthodes : `incrementGrade()` et `decrementGrade()`
  - Surcharge de l'opérateur `<<` pour afficher : `<name>, bureaucrat grade <grade>.`

### Points clés à retenir
- **Grade 1** = le plus haut (meilleur)
- **Grade 150** = le plus bas (pire)
- **Incrémenter** un grade 3 donne un grade 2 (on monte vers 1)
- **Décrémenter** un grade 3 donne un grade 4 (on descend vers 150)

### Orthodox Canonical Form (obligatoire)
Chaque classe doit avoir :
1. **Constructeur par défaut**
2. **Constructeur de copie**
3. **Opérateur d'affectation** (operator=)
4. **Destructeur**

### Compilation
```bash
c++ -Wall -Wextra -Werror -std=c++98 *.cpp -o bureaucrat
```

---

## 💡 Concepts appris

### Exceptions en C++
- Utilisation de `throw` pour lancer une exception
- Blocs `try/catch` pour capturer les exceptions
- Les exceptions doivent hériter de `std::exception`
- Méthode virtuelle `what()` à override pour le message d'erreur

### Attributs constants
- Déclaration : `const std::string _name;`
- Initialisation obligatoire dans la **liste d'initialisation** du constructeur
```cpp
Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade) {
    // corps du constructeur
}
```

---

## 📝 Décisions de design

### Nommage
- Attributs privés : préfixe `_` (ex: `_name`, `_grade`)
- Classes : UpperCamelCase (ex: `Bureaucrat`)
- Fichiers : selon le nom de la classe (ex: `Bureaucrat.hpp`, `Bureaucrat.cpp`)

### Exceptions
- Classes imbriquées dans `Bureaucrat` :
  - `Bureaucrat::GradeTooHighException`
  - `Bureaucrat::GradeTooLowException`
- Héritent de `std::exception`

---

## 🚧 Prochaines étapes

### Ex00 - TODO
1. [ ] Créer `Bureaucrat.hpp` avec la structure de classe
2. [ ] Implémenter les constructeurs (forme canonique)
3. [ ] Implémenter les classes d'exception
4. [ ] Implémenter getters et increment/decrement
5. [ ] Surcharger l'opérateur `<<`
6. [ ] Créer `main.cpp` avec des tests
7. [ ] Créer le `Makefile`
8. [ ] Tester tous les cas limites (grade 0, 151, increment/decrement aux bornes)

---

## ❓ Questions en suspens
- Aucune pour le moment

---

## 📚 Ressources utiles
- Exception handling C++98 : hériter de `std::exception`, override `what()`
- Liste d'initialisation obligatoire pour les membres `const`
- Opérateur `<<` : signature `std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)`

---

## 🔄 Changelog
- **2026-01-20** : Initialisation du projet, discussion de la structure générale des 4 exercices

---

## 💬 Notes pour l'IA

### Approche pédagogique
L'étudiant veut :
- Comprendre **étape par étape** sans recevoir la solution complète
- Répondre à des questions pour réfléchir par lui-même
- Progresser graduellement en comprenant les concepts

### Ce qu'on a couvert ensemble
- Vue d'ensemble des 4 exercices du CPP05
- Compréhension que ex00 introduit les exceptions
- Compréhension que ex02 utilise l'héritage et les classes abstraites
- Compréhension que ex03 utilise le factory pattern

### Questions posées à l'étudiant (en attente de réponse)
1. Qu'est-ce que ça implique qu'un attribut soit "constant" ?
2. Quels sont les 4 éléments de la forme canonique orthodoxe ?
3. As-tu déjà utilisé throw/try/catch en C++ ?

---

**Dernière mise à jour** : 2026-01-20
**Statut** : Prêt à démarrer Ex00
