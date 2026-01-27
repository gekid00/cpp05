# CPP05 - Context & Progress Tracker

**Date de création** : 2026-01-20
**Objectif** : Compléter le module CPP05 (Exceptions et Bureaucratie)

---

## 📊 État d'avancement global

- [X] Ex00 : Bureaucrat (base avec exceptions) ✅
- [X] Ex01 : Form (formulaires à signer) ✅
- [X] Ex02 : Formulaires concrets (héritage + AForm) ✅
- [X] Ex03 : Intern (factory pattern) ✅

---

## 🎯 Exercice en cours : **TOUS TERMINÉS ✅**

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

### Ex00 - TERMINÉ ✅
- Toutes les fonctionnalités implémentées et testées

### Ex01 - TERMINÉ ✅
- Classe Form avec signing logic
- Intégration avec Bureaucrat

### Ex02 - TERMINÉ ✅
- AForm (classe abstraite)
- 3 formulaires concrets : ShrubberyCreationForm, RobotomyRequestForm, PresidentialPardonForm
- Méthode execute() avec vérifications
- Tests complets

### Ex03 - TERMINÉ ✅
- Classe Intern avec makeForm()
- Factory pattern avec tableau de pointeurs sur fonctions
- Message "Intern creates <form>" lors de la création

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
- **2026-01-27** :
  - Implémentation complète de Ex00, Ex01, Ex02 (version verbose)
  - **REFACTORISATION MINIMALE** : Code nettoyé pour être minimal
    - Suppression de tous les std::cout de debug (constructeurs/destructeurs)
    - Conservation uniquement des messages requis par le sujet
    - Tests simplifiés au strict minimum
    - Code réduit à l'essentiel
  - Implémentation de Ex03 (Intern avec factory pattern)
  - **TOUS LES EXERCICES TERMINÉS** ✅

---

## 💬 Notes pour l'IA

### Approche pédagogique (MISE À JOUR)
L'étudiant a changé d'approche :
- ~~Voulait apprendre étape par étape~~ → A demandé l'implémentation complète
- Les exercices 00, 01 et 02 sont maintenant terminés
- Reste uniquement Ex03 (Intern avec factory pattern)

### Ce qui a été implémenté

#### Ex00 - Bureaucrat
- Classe avec name (const) et grade (1-150)
- Exceptions : GradeTooHighException, GradeTooLowException
- incrementGrade() / decrementGrade()
- Orthodox Canonical Form respectée
- Tests complets

#### Ex01 - Form
- Classe Form avec signed, gradeToSign, gradeToExecute
- beSigned() pour signature par bureaucrat
- signForm() ajoutée à Bureaucrat
- Gestion des exceptions
- Tests complets

#### Ex02 - AForm (Abstract)
- AForm devient classe abstraite
- Méthode pure virtuelle executeAction()
- Méthode execute() qui vérifie signature et grade
- 3 formulaires concrets :
  - **ShrubberyCreationForm** : crée fichier *_shrubbery avec ASCII trees
  - **RobotomyRequestForm** : drilling noises + 50% success rate
  - **PresidentialPardonForm** : pardon message par Zaphod Beeblebrox
- executeForm() ajoutée à Bureaucrat
- Tous les tests passent

---

**Dernière mise à jour** : 2026-01-27
**Statut** : ✅ MODULE CPP05 TERMINÉ (version minimale)
