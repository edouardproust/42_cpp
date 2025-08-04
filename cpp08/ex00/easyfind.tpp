template <typename T>
int	easyfind(T const& haystack, int needle) {
	if (std::find(haystack.begin(), haystack.end(), needle) != haystack.end()) {
		return needle;
	} else {
		throw std::runtime_error("Item not found");
	}
}
