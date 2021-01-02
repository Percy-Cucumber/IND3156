#importing your own complete text and parsing it into sentences
#import nltk
#from nltk import sent_tokenize

from vaderSentiment.vaderSentiment import SentimentIntensityAnalyzer
analyzer = SentimentIntensityAnalyzer() # easier to use with shorter name

print("\n\n\nSecond Example.\n")
# Example for multiple sentences
# create a load the array of strings
sentences = []
sentences.append("I very much enjoy lovingly ticking very cute very happy pupies as it is very enjoyable, and leaves me feeling very content and very satisfied.")
sentences.append("I very much hate torturing people, savagely murdering things, and violently destroying the world.")
sentences.append("I am the machine!")

# loop through it once for the scores
for x in sentences:
    print(x)
    vs = analyzer.polarity_scores(x)
    print("\t" + str(vs) + "\n\n")


# here is some info on the contents of the new variable
print('Data type returned: ', type(complete_score))
print('One element looks like this: ', complete_score[1])
print('Data type of element : ', type(complete_score[1]))
# Select and print the compound score using its dictionary key rather than its list/array index
polarity = [line.get('compound') for line in complete_score]
print('The array of compound values from the preceding example: ', polarity)
