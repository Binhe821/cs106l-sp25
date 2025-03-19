#include "spellcheck.h"

#include <algorithm>
#include <iostream>
#include <numeric>
#include <ranges>
#include <set>
#include <vector>

template <typename Iterator, typename UnaryPred>
std::vector<Iterator> find_all(Iterator begin, Iterator end, UnaryPred pred);

Corpus tokenize(const std::string& source) {
  /* TODO: Implement this method */
  std::vector<std::string::const_iterator> spaces = find_all(source.begin(),source.end(),isspace);

  std::set<Token> tokens;
  std::transform(spaces.begin(),spaces.end()-1,spaces.begin()+1,std::inserter(tokens,tokens.end()),[&](auto it1, auto it2) {return Token{source,it1,it2};});
  std::erase_if(tokens,[](Token token){return token.content.empty();});
  return tokens;
}
namespace rv = std::ranges::views;
std::set<Mispelling> spellcheck(const Corpus& source, const Dictionary& dictionary) {
  /* TODO: Implement this method */
  auto view = source | rv::filter([&dictionary](const Token& s){ return !dictionary.contains(s.content); }) | rv::transform([&dictionary](const Token& t){
    auto sug = dictionary | rv::filter([&t](const std::string u){ return levenshtein(t.content, u) == 1; });
    std::set<std::string> suggestions(sug.begin(), sug.end());
    return Mispelling{t,suggestions};
  }) | rv::filter([](const Mispelling& v) { return !v.suggestions.empty();});
  std::set<Mispelling> result(view.begin(),view.end());
  return result;
};

/* Helper methods */

#include "utils.cpp"