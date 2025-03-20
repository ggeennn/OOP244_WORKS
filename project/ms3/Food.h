#include "Billable.h"

namespace seneca {
    class Food : public Billable {
        bool m_ordered = false;
        bool m_child = false;
        char* m_customize = nullptr;
    public:
        Food()=default;
        Food(const Food&);
        Food& operator=(const Food&);
        ~Food();
        
        std::ostream& print(std::ostream& ostr= std::cout) const override;
        bool order() override;
        bool ordered() const override { return m_ordered; }
        std::ifstream& read(std::ifstream& file) override;
        double price() const override;
    };
}
