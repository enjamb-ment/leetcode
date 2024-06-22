/* 824. Goat Latin
You are given a string sentence that consist of words separated by spaces. Each word consists of lowercase and uppercase letters only.

We would like to convert the sentence to "Goat Latin" (a made-up language similar to Pig Latin.) The rules of Goat Latin are as follows:

If a word begins with a vowel ('a', 'e', 'i', 'o', or 'u'), append "ma" to the end of the word.
For example, the word "apple" becomes "applema".
If a word begins with a consonant (i.e., not a vowel), remove the first letter and append it to the end, then add "ma".
For example, the word "goat" becomes "oatgma".
Add one letter 'a' to the end of each word per its word index in the sentence, starting with 1.
For example, the first word gets "a" added to the end, the second word gets "aa" added to the end, and so on.
Return the final sentence representing the conversion from sentence to Goat Latin.

uff da.  Did a looooot of tweaking on that one.
*/

class Solution {
public:

    string maas(int a) {
        string as = "ma";
        for (int i = 0; i <= a; i++)
        {
            as += "a";
        }
        return as;
    }

    string toGoatLatin(string sentence) {
        string newSentence;
        char leadLetter = sentence[0];
        string token;
        string delimeter = " ";
        int a = 0;
        sentence = sentence + " ";

        while (sentence.size() > 0)
        {
            if (leadLetter == 'a' || leadLetter == 'e' || leadLetter == 'i' || leadLetter == 'o' || leadLetter == 'u' || 
                leadLetter == 'A' || leadLetter == 'E' || leadLetter == 'I' || leadLetter == 'O' || leadLetter == 'U')
            {
                token = sentence.substr(0, sentence.find(delimeter));
                //cout << "Token: " << token << endl;
                sentence.erase(0, token.length() + delimeter.length());
                newSentence = newSentence + token + maas(a) + " ";
            } else
            {
                token = sentence.substr(1, sentence.find(delimeter)-1);
                //cout << "Token: " << token << endl;
                sentence.erase(0, token.length() + delimeter.length()+1);
                newSentence = newSentence + token + leadLetter + maas(a) + " ";
            }
            a++;            
            leadLetter = sentence[0];
            //cout << newSentence << endl << sentence << endl << a << endl;
        }
    newSentence.erase(newSentence.size()-2, newSentence.size()-1);
    return newSentence + 'a';
    }
};
