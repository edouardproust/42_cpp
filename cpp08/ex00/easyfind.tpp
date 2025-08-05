template <typename Container>
int	easyfind(Container& c, int needle) {
	if (std::find(c.begin(), c.end(), needle) != c.end()) {
		return needle;
	} else {
		throw NotFoundException();
	}
}

char const*	NotFoundException::what() const throw() {
	return ("not found");
}
