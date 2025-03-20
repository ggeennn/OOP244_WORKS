#include "Billable.h"

namespace seneca {
    class Drink : public Billable {
        char m_size = '\0'; // S/M/L/X
    public:
        Drink()=default;
        
        std::ostream& print(std::ostream& ostr= std::cout) const override;
        bool order() override;
        bool ordered() const override { return m_size != '\0'; }
        std::ifstream& read(std::ifstream& file) override;
        double price() const override;
    };
}
