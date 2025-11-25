module;
// Nommage et exportation de ce module
export module exo4;

// Import rapide de la bibliothèque standard
import std;

// On met toutes les classes du module dans un espace de nom
// ayant le même nom que le module pour plus de clarté et éviter
// les conflits de nommage.
// On exporte la totalité des classes de l'espace de nom.
export namespace exo4 {

    // Classe abstraite Shape
    class Shape {
    public:
        // Fonction virtuelle pure : périmètre
        virtual double Perimeter() const = 0;

        // Fonction virtuelle pure : conversion en chaîne de caractères
        virtual std::string ToString() const = 0;

        // Destructeur virtuel (bonne pratique pour les classes de base)
        virtual ~Shape() = default;
    };

    // Classe Circle héritant de Shape
    class Circle : public Shape {
    public:
        // Constructeur avec un paramètre rayon
        explicit Circle(const double radius) : radius{radius} {}

        // Implémentation de Perimeter (override)
        double Perimeter() const override {
            return 2.0 * std::numbers::pi * radius;
        }

        // Implémentation de ToString (override)
        std::string ToString() const override {
            return std::format("Circle(radius={0:.2f})", radius);
        }

    private:
        double radius{0.0};
    };

    // Classe Application pour la démonstration
    class Application {
    public:
        // Tout le code de l'exercice doit être dans ce constructeur
        Application() {
            std::cout << "=== Démonstration de l'héritage ===\n\n";

            const auto circle = Circle{5.0};
            std::cout << "Création d'un cercle : " << circle.ToString() << std::endl;
            std::cout << "Périmètre du cercle : " << std::format("{0:.2f}", circle.Perimeter()) << std::endl;
        }
    };

}

