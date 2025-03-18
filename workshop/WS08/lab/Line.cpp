#include "Line.h"
#include "Utils.h"
#include <cstring>
#include <iomanip>

namespace seneca {

    Line::Line() : LblShape(), m_length(0) {}

    Line::Line(const char* label, int length) : LblShape(label) {
        m_length = (length > strlen(label)) 
                 ? length : strlen(label);
    }

    void Line::getSpecs(std::istream& is) {
        LblShape::getSpecs(is);
        is >> m_length;
        is.ignore(1000, '\n'); 
    }

    void Line::draw(std::ostream& os) const {
        if (m_length > 0 && label()) {
            os << label() << '\n'
               << std::setw(m_length) << std::setfill('=') << '=' 
               << std::setfill(' '); 
        }
    }
}