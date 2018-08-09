#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

class Tag {
public:
	Tag() {

	}

	void init(const string &value) {
		stringstream ss(value);
		char specSymbol;
		ss >> specSymbol;
		ss >> name;
		ss >> specSymbol;
		if (specSymbol != '>') { //parsing attributes
			string aName;
			string aValue;
			while (!ss.eof()) {
				ss >> aName;
			}
		}
	}

	Tag(const Tag&) = delete;
	~Tag() = default;

	void addTag(const Tag* tag) {
		childTags.push_back(tag);
		childNames.push_back(tag->getName());
	}

	const string& getName() const {
		return name;
	}

private:
	string name;

	vector<string> attrNames;
	vector<string> attrValues;
	
	vector<const Tag*> childTags;
	vector<string> childNames;
};

bool isStartTag(const string& value) {
	return value[1] != '/';
}

int main() {
	int lines = 0;
	int queries = 0;

	vector<Tag> allTags(1000);
	Tag* root = 0;
	vector<Tag*> currentTag (1000);

	int uniqID = 0;

	cin >> lines >> queries;
	int currentLevel = 0;
	for (int i = 0; i < lines; ++i) {
		string value;
		cin >> value;
		if (isStartTag(value)) {
			Tag* newTag = &allTags[uniqID++];
			newTag->init(value);
			if (currentLevel != 0) {
				currentTag[currentLevel]->addTag(newTag);
			}
			currentTag[currentLevel++] = newTag;
		} else {
			--currentLevel;
		}
	}


	return 0;
}