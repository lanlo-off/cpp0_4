/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llechert <llechert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 16:43:20 by ldubois           #+#    #+#             */
/*   Updated: 2026/03/31 13:30:16 by llechert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP

#define BITCOINEXCHANGE_HPP

#include <map>
#include <iostream>
#include <string>

class BitcoinExchange
{
	private:
		std::map<std::string, double>	   _rates;
		std::multimap<std::string, double> _amounts;
		void loadAmount(const std::string& record);
		void loadRate(const std::string& record);

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& rhs);
		~BitcoinExchange();

		const std::map<std::string, double>&	  getRates(void) const;
		const std::multimap<std::string, double>& getAmounts(void) const;

		void loadRates(const std::string& filename);
		void loadAccount(const std::string& filename);
};

std::ostream& operator<<(std::ostream& out, const BitcoinExchange& rhs);

#endif
