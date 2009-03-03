######################################################################

######################################################################

from nltk import tokenize, pos_tag, word_tokenize
from nltk import UnigramTagger
from nltk.corpus import brown


_FILE_LOAD_ = "test"

_EXAMPLE_TEXT =  """Mr Blobby is a fictional character who featured on Noel
    Edmonds' Saturday night entertainment show Noel's House Party,
    which was often a ratings winner in the 1990s. Mr Blobby also
    appeared on the Jamie Rose show of 1997. He was designed as an
    outrageously over the top parody of a one-dimensional, mute novelty
    character, which ironically made him distinctive, absurd and popular.
    He was a large pink humanoid, covered with yellow spots, sporting a
    permanent toothy grin and jiggling eyes. He communicated by saying
    the word "blobby" in an electronically-altered voice, expressing
    his moods through tone of voice and repetition."""

######################################################################

tokenizer = None
tagger = None

def init_nltk():
    global tokenizer
    global tagger
    ####################
    tokenizer = tokenize.RegexpTokenizer(r'\w+|[^\w\s]+')
    tagger = UnigramTagger(brown.tagged_sents())

def tag_document(text):
    global tokenizer
    if not tokenizer:
        init_nltk()

    doc_tokens = word_tokenize(text)
    #Use of the default pos tag
    #pos_tag(doc_tokens)
    return tagger.tag(doc_tokens)
	
if __name__ == '__main__':
	print "Running parse_document.py"
	doc = open(_FILE_LOAD_, 'r').read()
	res = tag_document(doc)
	for n in res:
		print n
	print "Done"

##############################
# End of File
##############################
