/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollock <cpollock@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 13:24:23 by cpollock          #+#    #+#             */
/*   Updated: 2026/01/28 13:24:34 by cpollock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <sstream>
#include <iostream>

PmergeMe::PmergeMe(void) {}

PmergeMe::PmergeMe(const PmergeMe &other) {
	*this = other;
}

PmergeMe::~PmergeMe(void) {}

PmergeMe	&PmergeMe::operator=(const PmergeMe &other) {
	this->_sortVector = other._sortVector;
	this->_sortDeque = other._sortDeque;
	return (*this);
}

//************************** SET UP CONTAINERS ***************************
void	PmergeMe::push_to_cont(const std::string &num) {
	std::stringstream	ssNum(num);
	std::string			strGet;
	int					numGet;

	while (ssNum >> strGet) {
		std::stringstream	ssGet(strGet);
		for (size_t i = ((strGet.size() > 1) && (strGet[0] == '+'
		|| strGet[0] == '-')) ? 1 : 0; i < strGet.size(); i++) {
			if (!std::isdigit(strGet[i]))
				throw (PmergeMe::InvalidValueException());
		}
		ssGet >> numGet;
		if ((ssGet.fail()))
			throw (PmergeMe::InvalidValueException());
		if (numGet < 0)
			throw (PmergeMe::NegativeIntException());
		this->_sortVector.push_back(numGet);
		this->_sortDeque.push_back(numGet);
	}
}

//************************** DISPLAY CONTAINERS **************************
void	PmergeMe::display_vector(void) const {
	std::vector<int>::const_iterator	it = this->_sortVector.begin();
	std::vector<int>::const_iterator	ite = this->_sortVector.end();
	while (it != ite) {
		std::cout << *it;
		if (++it != ite)
			std::cout << ' ';
	}
	std::cout << '\n';
}

void	PmergeMe::display_deque(void) const {
	std::deque<int>::const_iterator	it = this->_sortDeque.begin();
	std::deque<int>::const_iterator	ite = this->_sortDeque.end();
	while (it != ite) {
		std::cout << *it;
		if (++it != ite)
			std::cout << ' ';
	}
	std::cout << '\n';
}

//************************** CHECK CONTAINERS **************************
void	PmergeMe::sortCheckVector(void) const {
	std::vector<int>::const_iterator	it = this->_sortVector.begin();
	std::vector<int>::const_iterator	ite = this->_sortVector.end();
	if (this->_sortVector.size() < 2)
		return ;
	while (++it != ite) {
		if (it[0] < (it - 1)[0])
			throw (PmergeMe::BadSortException());
	}
}

void	PmergeMe::sortCheckDeque(void) const {
	std::deque<int>::const_iterator	it = this->_sortDeque.begin();
	std::deque<int>::const_iterator	ite = this->_sortDeque.end();
	if (this->_sortDeque.size() < 2)
		return ;
	while (++it != ite) {
		if (it[0] < (it - 1)[0])
			throw (PmergeMe::BadSortException());
	}
}


//**************************** VECTOR SORTING ****************************
/*static void	displayGroups(std::vector<int> &cont, size_t groupLen) {
	size_t	i, pairLen = groupLen * 2;
	if (groupLen <= 0) {
		groupLen = 1;
		pairLen = 1;
	}

	for (i = 0; i + pairLen <= cont.size(); i += pairLen) {
		
		std::string	strCol = "\e[96m";
		if (cont[i + groupLen - 1] > cont[i + pairLen - 1])
			strCol = "\e[93m";
		std::cout << strCol << '[';
		for (size_t j = 0; j < pairLen; j++) {
			bool	isBig = (j == groupLen - 1 || j == pairLen - 1);
			if (j == groupLen)
				std::cout << "| ";
			if (isBig)
				std::cout << "\e[4m" "\e[1m";
			std::cout << cont[i + j];
			if (isBig)
				std::cout << "\e[0m" << strCol;
			if (j + 1 < pairLen)
				std::cout << ' ';
		}
		std::cout << "] ";
	}
	if (i + groupLen <= cont.size()) {
		std::string	strCol = "\e[94m";
		std::cout << strCol << '[';
		for (size_t j = 0; j < groupLen; j++) {
			bool	isBig = (j == groupLen - 1);
			if (isBig)
				std::cout << "\e[4m" "\e[1m";
			std::cout << cont[i + j];
			if (!isBig)
				std::cout << ' ';
			else
				std::cout << "\e[0m" << strCol;
		}
		std::cout << "] ";
		i += groupLen;
	}
	std::cout << "\e[90m";
	while (i < cont.size())
		std::cout << cont[i++] << ' ';
	std::cout << "\e[0m" << '\n';
}*/

//DO BINARY INSERTION OF PEND ELEMENT INTO MAIN CHAIN
static void	sortBinaryInsertVector(std::vector< std::vector<int>::iterator > &chainMain,
std::vector<int> &groupSmall, size_t searchRange, size_t groupLen, int &comps) {
	size_t	low = 0;
	size_t	top = searchRange - 1;

	while (low < top) {
		size_t	mid = low + ((top - low) / 2);

		/*std::cout << "\e[3m" "\e[32m" "Comparing " << groupSmall[groupLen - 1]
		<< " to " << chainMain[mid][groupLen - 1] << "\e[0m" << '\n';*/

		if (++comps && (groupSmall[groupLen - 1] > chainMain[mid][groupLen - 1]))
			low = mid + 1;
		else if (mid != 0)
			top = mid - 1;
		else
			break;
	}

	size_t	slot = low;
	if (low == top) {

		/*std::cout << "\e[3m" "\e[32m" "Comparing " << groupSmall[groupLen - 1]
		<< " to " << chainMain[low][groupLen - 1] << "\e[0m" << '\n';*/

		if (++comps && (groupSmall[groupLen - 1] > chainMain[low][groupLen - 1]))
			slot++;
	}
	chainMain.insert(chainMain.begin() + slot, groupSmall.begin());
	
	/*std::cout << "Main chain: ";
	for (size_t j = 0; j < chainMain.size(); j++)
		std::cout << chainMain[j][groupLen - 1] << ' ';
	std::cout << '\n';*/
}

//SEPERATE ELEMENTS INTO MAIN CHAIN AND PEND CHAIN, THEN MERGE THEM
static void	sortMergeInsertVector(std::vector<int> &cont, size_t groupLen, int &comps) {
	size_t	pairLen = groupLen * 2;
	if (pairLen > cont.size())
		return ;
	
	size_t	i;
	std::vector< std::vector<int> >				chainBiggie, chainSmalls;
	std::vector< std::vector<int>::iterator >	chainMain;
	for (i = 0; i + pairLen <= cont.size(); i += pairLen) {
		std::vector<int>::iterator	groupIt = cont.begin() + i;
		std::vector<int>			tempSmall(groupIt, groupIt + groupLen);
		std::vector<int>			tempBig(groupIt + groupLen, groupIt + pairLen);
		chainBiggie.push_back(tempBig);
		chainSmalls.push_back(tempSmall);
	}
	if (i + groupLen <= cont.size()) {
		std::vector<int>::iterator	groupIt = cont.begin() + i;
		std::vector<int>			tempOdd(groupIt, groupIt + groupLen);
		chainSmalls.push_back(tempOdd);
	}
	if (chainSmalls.size() > 0)
		chainMain.push_back(chainSmalls[0].begin());
	for (i = 0; i < chainBiggie.size(); i++)
			chainMain.push_back(chainBiggie[i].begin());
	
	/*std::cout << "Main chain: ";
	for (size_t j = 0; j < chainMain.size(); j++)
		std::cout << chainMain[j][groupLen - 1] << ' ';
	std::cout << '\n';*/
	
	//std::cout << "Pend chain: ";
	if (chainSmalls.size() <= 1) {
		/*std::cout << "Empty" << '\n';
		displayGroups(cont, groupLen / 2);*/
		return ;
	}
	/*for (size_t j = 1; j < chainSmalls.size(); j++)
		std::cout << chainSmalls[j][groupLen - 1] << ' ';
	std::cout << '\n';*/

	size_t	prevJcbstl = 1;
	size_t	currJcbstl = 3;
	size_t	pendCheck;
	while (chainSmalls.size() > prevJcbstl) {
		for (pendCheck = currJcbstl; pendCheck != prevJcbstl; pendCheck--) {
			if (pendCheck <= chainSmalls.size()) {

				size_t	searchRange = chainMain.size();
				if (pendCheck <= chainBiggie.size()) {
					searchRange = 0;
					while (chainMain[searchRange] != chainBiggie[pendCheck - 1].begin())
						searchRange++;
				}

				/*std::cout << "\e[3m" "\e[92m" << "Inserting " << chainSmalls[pendCheck - 1].back()
				<< " into Main chain with binary search of range " << searchRange << "\e[0m" << '\n';*/

				sortBinaryInsertVector(chainMain, chainSmalls[pendCheck - 1], searchRange, groupLen, comps);
			}
		}
		size_t	tempJcbstl = currJcbstl;
		currJcbstl += prevJcbstl * 2;
		prevJcbstl = tempJcbstl;
	}

	i = 0;
	for (size_t j = 0; j < chainMain.size(); j++) {
		for (size_t k = 0; k < groupLen; k++)
			cont[i++] = chainMain[j][k];
	}
	//displayGroups(cont, groupLen / 2);
}

//SORT PAIRS OF ELEMENTS RECURSIVELY
static void	sortPairsVector(std::vector<int> &cont, size_t groupLen, int &comps) {
	size_t	pairLen = groupLen * 2;
	if (pairLen > cont.size())
		return ;
	
	//displayGroups(cont, groupLen);
	for (size_t i = 0; i + pairLen <= cont.size(); i += pairLen) {
		size_t	pairHalf = i + groupLen - 1;
		size_t	pairEnd = i + pairLen - 1;
		if (++comps && (cont[pairHalf] > cont[pairEnd])) {
			for (size_t j = i; j <= pairHalf; j++) {
				int	mem = cont[j];
				cont[j] = cont[j + groupLen];
				cont[j + groupLen] = mem;
			}
		}
	}
	//displayGroups(cont, groupLen);
	sortPairsVector(cont, pairLen, comps);
	sortMergeInsertVector(cont, groupLen, comps);
}

void	PmergeMe::sortVector(void) {
	int	comps = 0;
	sortPairsVector(this->_sortVector, 1, comps);
	/*std::cout << "\e[1m" "\e[4m" "\e[95m" "Total Comparisons:"
	<< "\e[0m" "\e[1m" "\e[95m" " " << comps << "\e[0m" <<'\n';*/
}


//**************************** DEQUE SORTING *****************************
static void	sortBinaryInsertDeque(std::deque< std::deque<int>::iterator > &chainMain,
std::deque<int> &groupSmall, size_t searchRange, size_t groupLen) {
	size_t	low = 0;
	size_t	top = searchRange - 1;

	while (low < top) {
		size_t	mid = low + ((top - low) / 2);
		if (groupSmall[groupLen - 1] > chainMain[mid][groupLen - 1])
			low = mid + 1;
		else if (mid != 0)
			top = mid - 1;
		else
			break;
	}

	size_t	slot = low;
	if (low == top) {
		if (groupSmall[groupLen - 1] > chainMain[low][groupLen - 1])
			slot++;
	}
	chainMain.insert(chainMain.begin() + slot, groupSmall.begin());
}

static void	sortMergeInsertDeque(std::deque<int> &cont, size_t groupLen) {
	size_t	pairLen = groupLen * 2;
	if (pairLen > cont.size())
		return ;
	
	size_t	i;
	std::deque< std::deque<int> >				chainBiggie, chainSmalls;
	std::deque< std::deque<int>::iterator >	chainMain;
	for (i = 0; i + pairLen <= cont.size(); i += pairLen) {
		std::deque<int>::iterator	groupIt = cont.begin() + i;
		std::deque<int>			tempSmall(groupIt, groupIt + groupLen);
		std::deque<int>			tempBig(groupIt + groupLen, groupIt + pairLen);
		chainBiggie.push_back(tempBig);
		chainSmalls.push_back(tempSmall);
	}
	if (i + groupLen <= cont.size()) {
		std::deque<int>::iterator	groupIt = cont.begin() + i;
		std::deque<int>			tempOdd(groupIt, groupIt + groupLen);
		chainSmalls.push_back(tempOdd);
	}
	if (chainSmalls.size() > 0)
		chainMain.push_back(chainSmalls[0].begin());
	for (i = 0; i < chainBiggie.size(); i++)
			chainMain.push_back(chainBiggie[i].begin());
	if (chainSmalls.size() <= 1)
		return ;

	size_t	prevJcbstl = 1;
	size_t	currJcbstl = 3;
	size_t	pendCheck;
	while (chainSmalls.size() > prevJcbstl) {
		for (pendCheck = currJcbstl; pendCheck != prevJcbstl; pendCheck--) {
			if (pendCheck <= chainSmalls.size()) {
				size_t	searchRange = chainMain.size();
				if (pendCheck <= chainBiggie.size()) {
					searchRange = 0;
					while (chainMain[searchRange] != chainBiggie[pendCheck - 1].begin())
						searchRange++;
				}
				sortBinaryInsertDeque(chainMain, chainSmalls[pendCheck - 1], searchRange, groupLen);
			}
		}
		size_t	tempJcbstl = currJcbstl;
		currJcbstl += prevJcbstl * 2;
		prevJcbstl = tempJcbstl;
	}

	i = 0;
	for (size_t j = 0; j < chainMain.size(); j++) {
		for (size_t k = 0; k < groupLen; k++)
			cont[i++] = chainMain[j][k];
	}
}

static void	sortPairsDeque(std::deque<int> &cont, size_t groupLen) {
	size_t	pairLen = groupLen * 2;
	if (pairLen > cont.size())
		return ;

	for (size_t i = 0; i + pairLen <= cont.size(); i += pairLen) {
		size_t	pairHalf = i + groupLen - 1;
		size_t	pairEnd = i + pairLen - 1;
		if (cont[pairHalf] > cont[pairEnd]) {
			for (size_t j = i; j <= pairHalf; j++) {
				int	mem = cont[j];
				cont[j] = cont[j + groupLen];
				cont[j + groupLen] = mem;
			}
		}
	}
	sortPairsDeque(cont, pairLen);
	sortMergeInsertDeque(cont, groupLen);
}

void	PmergeMe::sortDeque(void) {
	sortPairsDeque(this->_sortDeque, 1);
}