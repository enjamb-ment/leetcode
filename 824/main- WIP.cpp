//WIP

class Solution {
public:

    string maas(char leadLetter, int a) {
        string as = "ma";
        for (int i = 0; i < a; i++)
        {
            as += "a";
        }
        return leadLetter + as;
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
                token = sentence.substr(1, sentence.find(delimeter)-1);
            } else
            {
                token = sentence.substr(2, sentence.find(delimeter)-2);
            }
            a++;            
            newSentence = newSentence + token + maas(leadLetter, a) + " ";
            sentence.erase(0, token.length() + delimeter.length());
            leadLetter = sentence[0];
            cout << newSentence << endl << sentence << endl;
        }
    newSentence.erase(newSentence.size()-2, newSentence.size()-1);
    return newSentence;
    }
};
