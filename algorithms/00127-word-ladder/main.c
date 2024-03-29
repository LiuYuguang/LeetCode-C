#include <stdio.h>
#include <string.h>

int canChange(char * beginWord, char * endWord){
    int count = 0;
    char *p1 = beginWord,*p2 = endWord;
    while(*p1 != '\0'){
        if(*p1++ != *p2++){
            count++;
        }
    }
    return count == 1;
}

int ladderLength(char * beginWord, char * endWord, char ** wordList, int wordListSize){
    char* queue[5000] = {0};
    int counts[5000] = {0};
    int i,j,l;
    int head=0,tail=0,count = 2;
    int endIndex = -1;

    for(i=0;i<wordListSize && strcmp(endWord,wordList[i]) != 0;i++){}
    if(i == wordListSize){
        return 0;
    }
    endIndex = i;

    for(i=0;i<wordListSize;i++){
        if(canChange(beginWord,wordList[i])){
            counts[i] = count;
            queue[head++] = wordList[i];
        }
    }

    while(counts[endIndex] == 0 && tail != head){
        l = head - tail;
        count++;
        for(i=0;i<l && counts[endIndex] == 0;i++){
            beginWord = queue[tail++];
            for(j=0;j<wordListSize && counts[endIndex] == 0;j++){
                if(counts[j]==0 && canChange(beginWord,wordList[j])){
                    counts[j] = count;
                    queue[head++] = wordList[j];
                }
            }
        }
    }

    return counts[endIndex];
}

int main(){
    {
        // beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
        // 一个最短转换序列是 "hit" -> "hot" -> "dot" -> "dog" -> "cog", 返回它的长度 5。
        char *beginWord = "hit";
        char *endWord = "cog";
        char *wordList[] = {"hot","dot","dog","lot","log","cog"};
        printf("%d\n",ladderLength(beginWord,endWord,wordList,sizeof(wordList)/sizeof(char*)));
    }
    
    {
        // beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"] 0
        char *beginWord = "hit";
        char *endWord = "cog";
        char *wordList[] = {"hot","dot","dog","lot","log"};
        printf("%d\n",ladderLength(beginWord,endWord,wordList,sizeof(wordList)/sizeof(char*)));
    }
    // if(0)
    {
        // beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
        char *beginWord = "qa";
        char *endWord = "sq";
        char *wordList[] = {"si","go","se","cm","so","ph","mt","db","mb","sb","kr","ln","tm","le","av","sm","ar","ci","ca","br","ti","ba","to","ra","fa","yo","ow","sn","ya","cr","po","fe","ho","ma","re","or","rn","au","ur","rh","sr","tc","lt","lo","as","fr","nb","yb","if","pb","ge","th","pm","rb","sh","co","ga","li","ha","hz","no","bi","di","hi","qa","pi","os","uh","wm","an","me","mo","na","la","st","er","sc","ne","mn","mi","am","ex","pt","io","be","fm","ta","tb","ni","mr","pa","he","lr","sq","ye"};
        printf("%d\n",ladderLength(beginWord,endWord,wordList,sizeof(wordList)/sizeof(char*)));
    }

    {
        // "hot"
        // "dog"
        // ["hot","cog","dog","tot","hog","hop","pot","dot"] 3
        char *beginWord = "hot";
        char *endWord = "dog";
        char *wordList[] = {"hot","cog","dog","tot","hog","hop","pot","dot"};
        printf("%d\n",ladderLength(beginWord,endWord,wordList,sizeof(wordList)/sizeof(char*)));
    }

    {
        // "cet"
        // "ism"
        // ["hot","cog","dog","tot","hog","hop","pot","dot"] 3
        char *beginWord = "hot";
        char *endWord = "dog";
        char *wordList[] = {"kid","tag","pup","ail","tun","woo","erg","luz","brr","gay","sip","kay","per","val","mes","ohs","now","boa","cet","pal","bar","die","war","hay","eco","pub","lob","rue","fry","lit","rex","jan","cot","bid","ali","pay","col","gum","ger","row","won","dan","rum","fad","tut","sag","yip","sui","ark","has","zip","fez","own","ump","dis","ads","max","jaw","out","btu","ana","gap","cry","led","abe","box","ore","pig","fie","toy","fat","cal","lie","noh","sew","ono","tam","flu","mgm","ply","awe","pry","tit","tie","yet","too","tax","jim","san","pan","map","ski","ova","wed","non","wac","nut","why","bye","lye","oct","old","fin","feb","chi","sap","owl","log","tod","dot","bow","fob","for","joe","ivy","fan","age","fax","hip","jib","mel","hus","sob","ifs","tab","ara","dab","jag","jar","arm","lot","tom","sax","tex","yum","pei","wen","wry","ire","irk","far","mew","wit","doe","gas","rte","ian","pot","ask","wag","hag","amy","nag","ron","soy","gin","don","tug","fay","vic","boo","nam","ave","buy","sop","but","orb","fen","paw","his","sub","bob","yea","oft","inn","rod","yam","pew","web","hod","hun","gyp","wei","wis","rob","gad","pie","mon","dog","bib","rub","ere","dig","era","cat","fox","bee","mod","day","apr","vie","nev","jam","pam","new","aye","ani","and","ibm","yap","can","pyx","tar","kin","fog","hum","pip","cup","dye","lyx","jog","nun","par","wan","fey","bus","oak","bad","ats","set","qom","vat","eat","pus","rev","axe","ion","six","ila","lao","mom","mas","pro","few","opt","poe","art","ash","oar","cap","lop","may","shy","rid","bat","sum","rim","fee","bmw","sky","maj","hue","thy","ava","rap","den","fla","auk","cox","ibo","hey","saw","vim","sec","ltd","you","its","tat","dew","eva","tog","ram","let","see","zit","maw","nix","ate","gig","rep","owe","ind","hog","eve","sam","zoo","any","dow","cod","bed","vet","ham","sis","hex","via","fir","nod","mao","aug","mum","hoe","bah","hal","keg","hew","zed","tow","gog","ass","dem","who","bet","gos","son","ear","spy","kit","boy","due","sen","oaf","mix","hep","fur","ada","bin","nil","mia","ewe","hit","fix","sad","rib","eye","hop","haw","wax","mid","tad","ken","wad","rye","pap","bog","gut","ito","woe","our","ado","sin","mad","ray","hon","roy","dip","hen","iva","lug","asp","hui","yak","bay","poi","yep","bun","try","lad","elm","nat","wyo","gym","dug","toe","dee","wig","sly","rip","geo","cog","pas","zen","odd","nan","lay","pod","fit","hem","joy","bum","rio","yon","dec","leg","put","sue","dim","pet","yaw","nub","bit","bur","sid","sun","oil","red","doc","moe","caw","eel","dix","cub","end","gem","off","yew","hug","pop","tub","sgt","lid","pun","ton","sol","din","yup","jab","pea","bug","gag","mil","jig","hub","low","did","tin","get","gte","sox","lei","mig","fig","lon","use","ban","flo","nov","jut","bag","mir","sty","lap","two","ins","con","ant","net","tux","ode","stu","mug","cad","nap","gun","fop","tot","sow","sal","sic","ted","wot","del","imp","cob","way","ann","tan","mci","job","wet","ism","err","him","all","pad","hah","hie","aim","ike","jed","ego","mac","baa","min","com","ill","was","cab","ago","ina","big","ilk","gal","tap","duh","ola","ran","lab","top","gob","hot","ora","tia","kip","han","met","hut","she","sac","fed","goo","tee","ell","not","act","gil","rut","ala","ape","rig","cid","god","duo","lin","aid","gel","awl","lag","elf","liz","ref","aha","fib","oho","tho","her","nor","ace","adz","fun","ned","coo","win","tao","coy","van","man","pit","guy","foe","hid","mai","sup","jay","hob","mow","jot","are","pol","arc","lax","aft","alb","len","air","pug","pox","vow","got","meg","zoe","amp","ale","bud","gee","pin","dun","pat","ten","mob"};
        printf("%d\n",ladderLength(beginWord,endWord,wordList,sizeof(wordList)/sizeof(char*)));
    }
}