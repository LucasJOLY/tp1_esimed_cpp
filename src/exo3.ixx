module;
// Nommage et exportation de ce module
export module exo3;

// Import rapide de la bibliothèque standard
import std;

// On met toutes les structures du module dans un espace de nom
// ayant le même nom que le module pour plus de clarté et éviter
// les conflits de nommage.
// On exporte la totalité des structures de l'espace de nom.
export namespace exo3 {

    // Structure Vector représentant un vecteur à trois dimensions
    struct Vector {
        // Données membres initialisées à leur valeur par défaut
        double x{0.0};
        double y{0.0};
        double z{0.0};

        // Conversion en chaîne de caractères
        std::string ToString() const {
            return std::format("({0:.2f},{1:.2f},{2:.2f})", x, y, z);
        }

        // Opérateur + : addition de deux vecteurs
        Vector operator+(const Vector& other) const {
            return Vector{x + other.x, y + other.y, z + other.z};
        }

        // Opérateur * : multiplication par un scalaire
        Vector operator*(const double factor) const {
            return Vector{x * factor, y * factor, z * factor};
        }

        // Opérateur == : comparaison de deux vecteurs (avec friend)
        friend bool operator==(const Vector& lhs, const Vector& rhs) {
            return lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z;
        }
    };

}

