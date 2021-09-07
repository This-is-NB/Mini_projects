# source == https://predictivehacks.com/languagetool-grammar-and-spell-checker-in-python/

import language_tool_python
tool = language_tool_python.LanguageTool('en-US')

text = """LanguageTool offers spell and grammar checking. Just paste your text here and click the 'Check Text' button. Click the colored phrases for details on potential errors. or use this text too see an few of of the problems that LanguageTool can detecd. What do you thinks of grammar checkers? Please not that they are not perfect. Style issues get a blue marker: It's 5 P.M. in the afternoon. The weather was nice on Thursday, 27 June 2017"""


# get the matches
matches = tool.check(text)
# for i in range(len(matches)):
#     print(matches[i])

print(tool.correct(text))
