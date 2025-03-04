#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <iostream>
using namespace std;
#include "Numbers.h"
namespace seneca
{

    Numbers::~Numbers()
    {
        if (m_isOriginal)
        {
            save();
        }
        delete[] m_numbers;
        delete[] m_filename;
    }

    Numbers::Numbers(const Numbers &other)
    {
        setEmpty();
        m_isOriginal = false;
        m_numCount = other.m_numCount;
        if (other.m_numbers)
        {
            m_numbers = new double[m_numCount];
            for (size_t i = 0; i < m_numCount; i++)
            {
                m_numbers[i] = other.m_numbers[i];
            }
        }
        // m_filename？
    }

    Numbers &Numbers::operator=(const Numbers &other)
    {
        if (this != &other)
        {
            delete[] m_numbers;
            m_numCount = other.m_numCount;
            if (other.m_numbers)
            {
                m_numbers = new double[m_numCount];
                for (size_t i = 0; i < m_numCount; i++)
                {
                    m_numbers[i] = other.m_numbers[i];
                }
            }
            // m_isOriginal = false;
            // m_filename？
        }
        return *this;
    }

    size_t Numbers::numberCount() const
    {
        ifstream file(m_filename);
        size_t count = 0;
        char ch;
        while (file.get(ch))
        {
            if (ch == '\n')
            {
                count++;
            }
        }
        return count;
    }

    bool Numbers::load()
    {
        if (m_numCount > 0)
        {
            m_numbers = new double[m_numCount];
            ifstream file(m_filename);

            if (!file.is_open())
            {
                delete[] m_numbers;
                setEmpty();
                return false;
            }

            size_t i = 0;
            while (i < m_numCount && file >> m_numbers[i])
            {
                i++;
            }
            bool success = (i == m_numCount);
            double test;
            if (file >> test)
            {
                success = false;
            }
            file.close();
            if (!success)
            {
                delete[] m_numbers;
                setEmpty();
            }

            return success;
        }
        return false;
    }

    void Numbers::save()
    {
        if (m_isOriginal && !isEmpty())
        {
            ofstream file(m_filename);
            for (size_t i = 0; i < m_numCount; i++)
            {
                file << m_numbers[i] << endl;
            }
        }
    }

    Numbers &Numbers::operator+=(double value)
    {
        if (!isEmpty())
        {
            double *temp = new double[m_numCount + 1];
            for (size_t i = 0; i < m_numCount; i++)
            {
                temp[i] = m_numbers[i];
            }
            temp[m_numCount] = value;
            m_numCount++;
            delete[] m_numbers;
            m_numbers = temp;
            sort();
        }
        return *this;
    }

    ostream &Numbers::display(ostream &ostr) const
    {
        if (isEmpty())
        {
            ostr << "Empty list";
        }
        else
        {
            ostr << "=========================" << endl;
            if (m_isOriginal)
            {
                ostr << m_filename << endl;
            }
            else
            {
                ostr << "*** COPY ***" << endl;
            }
            ostr << fixed;
            ostr.precision(2);
            for (size_t i = 0; i < m_numCount; i++)
            {

                ostr << m_numbers[i];
                if (i < m_numCount - 1)
                {
                    ostr << ", ";
                }
            }
            ostr << endl
                 << "-------------------------" << endl;
            ostr << "Total of " << m_numCount << " number(s)" << endl;
            ostr << "Largest number:  " << max() << endl;
            ostr << "Smallest number: " << min() << endl;
            ostr << "Average:         " << average() << endl;
            ostr << "=========================";
        }
        return ostr;
    }

    ostream &operator<<(ostream &os, const Numbers &N)
    {
        return N.display(os);
    }

    istream &operator>>(istream &istr, Numbers &N)
    {
        double value;
        istr >> value;
        if (!istr.fail())
        {
            N += value;
        }
        return istr;
    }
}