module;
// Nommage et exportation de ce module
export module exo2;

// Import rapide de la bibliothèque standard
import std;

// On met toutes les classes du module dans un espace de nom
// ayant le même nom que le module pour plus de clarté et éviter
// les conflits de nommage.
// On exporte la totalité des classe de l'espace de nom.
export namespace exo2 {

    // Classe Vector représentant un vecteur à trois dimensions
    class Vector {
    public:
        // Constructeur par défaut
        Vector() {
            std::cout << "Constructeur par défaut appelé\n";
        }

        // Constructeur à trois arguments
        Vector(const double x, const double y, const double z)
            : x{x}, y{y}, z{z} {
            std::cout << "Constructeur à trois arguments appelé\n";
        }

        // Constructeur par copie
        Vector(const Vector& other)
            : x{other.x}, y{other.y}, z{other.z} {
            std::cout << "Constructeur par copie appelé\n";
        }

        // Accesseurs
        double GetX() const { return x; }
        double GetY() const { return y; }
        double GetZ() const { return z; }

        // Modificateurs
        void SetX(const double x) { this->x = x; }
        void SetY(const double y) { this->y = y; }
        void SetZ(const double z) { this->z = z; }

        // Homothétie : multiplie les composantes par une valeur
        void Homothety(const double factor) {
            x *= factor;
            y *= factor;
            z *= factor;
        }

        // Somme 1 : passage par copie
        void Sum1(const Vector other) {
            x += other.x;
            y += other.y;
            z += other.z;
        }

        // Somme 2 : passage par référence
        void Sum2(const Vector& other) {
            x += other.x;
            y += other.y;
            z += other.z;
        }

        // Conversion en chaîne de caractères
        std::string ToString() const {
            return std::format("({0:.2f},{1:.2f},{2:.2f})", x, y, z);
        }

    private:
        // Composantes du vecteur
        double x{0.0};
        double y{0.0};
        double z{0.0};
    };

    // Classe Application pour la démonstration
    class Application {
    public:
        // Tout le code de l'exercice doit être dans ce constructeur
        Application() {
            std::cout << "=== Démonstration passage par référence vs copie ===\n\n";

            std::cout << "Création de v1:\n";
            const auto v1 = Vector{12.34, 34.56, 56.78};
            std::cout << "v1 = " << v1.ToString() << "\n\n";

            std::cout << "Création de v2:\n";
            const auto v2 = Vector{1.1, 2.2, 3.3};
            std::cout << "v2 = " << v2.ToString() << "\n\n";

            std::cout << "Appel de Sum1 (passage par copie):\n";
            auto v3 = Vector{12.34, 34.56, 56.78};
            v3.Sum1(v2);
            std::cout << "v3 après Sum1 = " << v3.ToString() << "\n\n";

            std::cout << "Appel de Sum2 (passage par référence):\n";
            auto v4 = Vector{12.34, 34.56, 56.78};
            v4.Sum2(v2);
            std::cout << "v4 après Sum2 = " << v4.ToString() << "\n\n";
        }
    };

}

