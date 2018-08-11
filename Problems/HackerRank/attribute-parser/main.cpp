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
		string data;
		char specSymbol = 0;
		ss >> specSymbol;
		ss >> name;
		if (name.back() == '>')
			name.pop_back();
		else {
			ss >> data;
			if (data.compare(">") != 0) {
				while (!ss.eof()) {
					string aName = data;
					string aValue;


					ss >> specSymbol;
					ss >> specSymbol;
					ss >> aValue;
					if (aValue[aValue.length() - 1] == '>') {
						aValue.pop_back();
					}
					aValue.pop_back();

					attrNames.push_back(aName);
					attrValues.push_back(aValue);

					ss >> data;
				}
			}
		}
	}

	Tag(const Tag&) = delete;
	~Tag() = default;

	void addTag(const Tag* tag) {
		childTags.push_back(tag);
		childNames.push_back(tag->getName());
	}

	const Tag* getTag(const string& name) const {
		int index = 0;
		for (const auto& tagName : childNames) {
			if (tagName.compare(name) == 0)
				break;
			++index;
		}
		if (index < childTags.size())
			return childTags[index];
		return nullptr;
	}

	bool getValue(const string& attrName, string& value) const {
		int index = 0;
		for (const auto& name : attrNames) {
			if (name.compare(attrName) == 0)
				break;
			++index;
		}
		if (index < attrValues.size()) {
			value = attrValues[index];
			return true;
		}
		return false;
	}

	const string& getName() const {
		return name;
	}

	void setName(const string& aName) {
		name = aName;
	}

private:
	string name;

	vector<string> attrNames;
	vector<string> attrValues;
	
	vector<const Tag*> childTags;
	vector<string> childNames;
};

bool isStartTag(const string& value) {
	return value[1] != '/' && value[0] != '/';
}

int main() {

#ifdef LOCAL_TESTS
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif

	int lines = 0;
	int queries = 0;

	vector<Tag> allTags(1000);
	Tag* root = 0;
	vector<Tag*> currentTag (1000);

	int uniqID = 0;

	cin >> lines >> queries;
	int currentLevel = 0;

	Tag* newTag = &allTags[uniqID++];
	newTag->setName("root");
	currentTag[currentLevel] = newTag;

	for (int i = 0; i < lines; ++i) {
		string value;
		while (value.size() == 0 && !cin.eof()) {
			getline(cin, value);
		}
		if (isStartTag(value)) {
			newTag = &allTags[uniqID++];
			newTag->init(value);
			currentTag[currentLevel]->addTag(newTag);
			currentTag[++currentLevel] = newTag;
		} else {
			--currentLevel;
		}
	}

	for (int i = 0; i < queries; ++i) {
		string query;
		while (query.size() == 0 && !cin.eof()) {
			getline(cin, query);
		}

		std::vector<std::string> tagNames;
		string attrName;
		{
			std::string tag;
			{
				std::stringstream ss(query);
				while (getline(ss, tag, '.')) {
					tagNames.push_back(tag);
				}
			}
			{
				std::stringstream ss(tagNames.back());
				getline(ss, tag, '~');
				ss >> attrName;
				tagNames.back() = tag;
			}
		}

		const Tag* tagNode = currentTag[0];
		for (const auto& name : tagNames) {
			tagNode = tagNode->getTag(name);
			if (tagNode == nullptr) {
				break;
			}
		}

		string attrValue;
		if (!tagNode || !tagNode->getValue(attrName, attrValue))
			cout << "Not Found!";
		else
			cout << attrValue;
		if (i + 1 < queries)
			cout << endl;
	}

	return 0;
}