inline char toLower(const char c) {
	return (c >= 'A' && c <= 'Z' ? c + 'a' - 'A' : c);
}

int strcasecmp(const char *s1, const char *s2) {
	while (toLower(*s1) == toLower(*s2)) {
		s1++; s2++;
	}
	s1--; s2--;
	return *s1 || *s2;
}

int strncasecmp(const char *s1, const char *s2, int amount) {
	int i = 0;
	for (; i < amount; i++) {
		if (toLower(*s1) != toLower(*s2)) {
			return 1;
		}
		s1++;
		s2++;
	}
	return 0;
}