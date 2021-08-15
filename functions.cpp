unsigned int MySimpleHash(std::string str){
	unsigned int hash = 0;
 	int* ascii_str = new int[str.length()];
	for (int i = 0; i < str.length(); ++i){
		ascii_str[i] = str[i];
		hash += ascii_str[i];
	}
	return hash % 2000000;
}

unsigned int BetterHash(std::string s_str){
	unsigned int b = 498791;
	unsigned int a = 83117;
	unsigned int hash = 0;
	unsigned int i = 0, len = s_str.length();
	const char *str = s_str.c_str();
	for (i = 0; i < len; str++, i++) {
		hash = hash * a + (unsigned char)(*str);
		a = a * b;
	}
	return hash % 2000000;
}