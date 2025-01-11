/**
 * I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
 * 	Name :		Yicheng Wang
 * 	Email :		ywang841@myseneca.ca
 * 	Student ID :150868206
 *	Date :		2025/1/10
 */

#ifndef SENECA_MOVIE_H_
#define SENECA_MOVIE_H_

namespace seneca {

	struct Movie {
		char m_title[128];
		int m_year;
		char m_rating[6];
		int m_duration;
		char m_genres[10][11];
		float m_consumerRating;
	};

	bool loadMovies();
	bool hasGenre(const Movie* mvp, const char genre[]);
	void displayMovie(const Movie* mvp);
	void displayMoviesWithGenre(const char genre[]);
}
#endif // !SENECA_MOVIE_H_
