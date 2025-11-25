#define CATCH_CONFIG_MAIN
#include <catch2/catch_all.hpp>

// Importation de l'exercice
import exo4;
using namespace exo4;

// Tests unitaires pour la classe Circle avec héritage
TEST_CASE("Exo4", "[Circle]") {
    const auto circle = Circle{1.2};
    REQUIRE(std::format("{0:.2f}", circle.Perimeter()) == "7.54");
}

