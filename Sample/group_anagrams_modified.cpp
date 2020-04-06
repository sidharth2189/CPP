/*

GROUP ANAGRAMS

Given an array of strings, group anagrams together.

Example:

Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note:

All inputs will be in lowercase.
The order of your output does not matter.
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    bool does_exist(const vector<vector<string>>&  v, string item)
        {
            vector<vector<string>>::const_iterator row;

            for (row = v.begin(); row != v.end(); row++) 
            {
                if(find(row->begin(), row->end(), item) != row->end() )
                    return true;
            }

            return false;
        }
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result = {strs};
        
        if ((strs.empty() == false) && (strs.size() > 1))
        {
            vector<string> part_result, part_result_worst, worst_new;
            result.clear();
            int worst_case_count = 0;
            for (auto x: strs)
            {
                sort(x.begin(), x.end());
                worst_new.push_back(x);
            }
            for (int y = 0; y < worst_new.size(); y++)
            {
                part_result_worst.clear();
                if (count(worst_new.begin(), worst_new.end(), worst_new[y]) == 1)
                {
                    worst_case_count++;
                    part_result_worst.push_back(strs[y]);
                    result.push_back(part_result_worst);
                }
            }
                
            if (worst_case_count == worst_new.size())
            {
                return result;
            }
            
            result.clear();
            
            for (int index = 0; index < strs.size(); index++)
            {
                string str1 = strs[index];
                string str1_sort(str1);
                if (!does_exist(result, str1))
                {
                    int n1 = str1.length();
                    part_result.push_back(str1);
                    sort(str1_sort.begin(), str1_sort.end());
                    for (int in_index = index+1; in_index < strs.size(); in_index++)
                    {
                        string str2 = strs[in_index];
                        string str2_sort(str2);
                        int n2 = str2.length();

                        if (n1==n2)
                        { 
                            sort(str2_sort.begin(), str2_sort.end());

                            if (str2_sort == str1_sort)
                            {
                                part_result.push_back(str2);
                            }
                        }
                    }
                    sort(part_result.begin(), part_result.end());
                    result.push_back(part_result);
                    part_result.clear(); 
                }
            }
        }
        return result;
    }
};

int main()
{
    Solution sol;
    vector<string> strs{};
    vector<vector<string>> result{};

    // Test cases
    strs = {"eat", "tea", "tan", "ate", "nat", "bat"};

    strs = {"nozzle","punjabi","waterlogged","imprison","crux","numismatists","sultans",\
    "rambles","deprecating","aware","outfield","marlborough","guardrooms","roast","wattage",\
    "shortcuts","confidential","reprint","foxtrot","dispossession","floodgate","unfriendliest",\
    "semimonthlies","dwellers","walkways","wastrels","dippers","engrossing","undertakings",\
    "unforeseen","oscilloscopes","pioneers","geller","neglects","cultivates","mantegna",\
    "elicit","couriered","shielded","shrew","heartening","lucks","teammates","jewishness",\
    "documentaries","subliming","sultan","redo","recopy","flippancy","rothko","conductor",\
    "e","carolingian","outmanoeuvres","gewgaw","saki","sarah","snooping","hakka","highness",\
    "mewling","spender","blockhead","detonated","cognac","congaing","prissy","loathes","bluebell",\
    "involuntary","aping","sadly","jiving","buffalo","chided","instalment","boon","ashikaga",\
    "enigmas","recommenced","snell","parsley","buns","abracadabra","forewomen","persecuted",\
    "carsick","janitorial","neonate","expeditiously","porterhouse","bussed","charm","tinseled",\
    "pencils","inherits","crew","estimate","blacktop","mythologists","essequibo","dusky","fends",\
    "pithily","positively","participants","brew","tows","pentathlon","misdiagnoses","paraphrase",\
    "telephoning","engining","anglo","duisburg","shorthorns","physical","enquiries","grudging",\
    "floodlit","safflower","asphalts","representing","airbrush","bedevilling","fulminations",\
    "peacefuller","hurl","unequalled","wiser","vinson","paglia","doggones","optimist","rulering",\
    "katmandu","flutists","sterling","oregonians","boosts","slaver","straightedges","stendhal",\
    "defaulters","stylize","chucking","adulterate","partaking","omelettes","monochrome","bitched",\
    "foxhound","tapir","vocalizing","manifolding","northerner","ineptly","dunce","matchbook",\
    "locutions","docudrama","sinkers","paralegal","sip","maliced","lechers","zippy","tillman",\
    "penknives","olympias","designates","mossiest","leanne","lavishing","understate","underwriting",\
    "showered","belittle","propounded","gristly","toxicity","trike","baudelaire","sheers","annmarie",\
    "poultices","therapeutics","inputs","bailed","minutest","pynchon","jinx","jackets","subsections",\
    "harmonizes","caesareans","freshened","haring","disruption","buckle","per","pined","solemnity",\
    "recombined","chamber","tangling","pitiful","authoritarians","oort","ingratiate","refreshed",\
    "bavarian","generically","rescheduled","typewritten","level","magnetism","socialists","oligocene",\
    "resentful","lambast","counteroffer","firefight","phil","attenuates","teary","demarcated",\
    "moralities","electrified","pettiness","unpacking","hungary","heavies","tenancies","tirade",\
    "solaria","scarcity","prettiest","carrillo","yodel","cantilever","ridiculously","tagalog",\
    "schismatics","ossification","hezbollah","downscaling","calking","tapped","girl","alba",\
    "lavishness","stepparents","integrator","overact","father","fobbing","pb","require","toes",\
    "sweats","prisoners","mbabane","hatch","motleyer","worlds","decentralize","ingrained",\
    "shekels","directorship","negotiating","hiawatha","busying","reciprocate","spinsterhood",\
    "supervened","scrimmage","decolonized","buildups","sedative","swats","despotic","driblets",\
    "redoubting","stoic","xeroxes","satellited","exteriors","deregulates","lawful","flunk","broached",\
    "energetics","moodily","popinjays","shoshone","misleads","abduct","nonevent","flees","harry",\
    "cleverness","manipulative","shoplifts","tom","junk","poniard","transmute","stricter","trochees",\
    "snack","relations","edger","culminate","implication","carjacked","kissers","federate","offsetting",\
    "sutures","wakened","axis","boxcars","grinds","scenting","cordoba","lumberyards","incendiary",\
    "antiphonal","decipherable","gilliam","redecorates","plum","nitpickers","linefeed","awakes",\
    "embittering","spewing","annul","filial","scarlet","connors","sanctum","scotsman","isobar",\
    "activity","overthrowing","unseasoned","tarantulae","outtake","diego","mars","stunted","hunted",\
    "sublimation","barbadian","barbarisms","epidemic","assesses","imposture","freaks","detroit",\
    "bloodiest","avails","prenatal","connecticut","guardsmen","betwixt","windsock","neutralized",\
    "psychoanalysis","rubberized","overproduces","narcissism","tallow","cringes","resinous",\
    "paintbrushes","duality","paints","deactivated","expertly","speedsters","coward","bass",\
    "psychiatrist","curies","betrays","bubble","mellow","showy","retarding","radishes","coy",\
    "unreservedly","larks","apportioned","flaccid","relabelling","alphabeted","anointment",\
    "helms","gillian","trophying","breakage","underbrush","directest","wingtips","pretence",\
    "preshrink","remarries","addle","brouhaha","mobbing","g","dings","gains","stockade","ouch",\
    "particulates","listens","habituation","kill","crouped","hyperbolae","hutching","stoney",\
    "rightness","davids","questioned","ethiopians","courtliness","delays","navahos","devils",\
    "keeling","accelerators","investigator","spindling","illegality","extremer","revlon","purity",\
    "bradly","jut","machs","liquidated","informant","smartly","disfigure","parliaments","croup",\
    "teletypes","impression","trainee","implications","embed","podiatrists","jewelled","brokenhearted",\
    "spaceman","unsteadier","kitchen","twirling","conurbations","pygmies","lourdes","watertight",\
    "reassessing","dempsey","matriarch","alas","abscissae","decanter","commentated","sandy",\
    "idler","soybean","cutoff","dictate","credibility","indeterminable","release","blank",\
    "curitiba","pericardia","probably","indisposition","hesitantly","duff","ratty","derivative",\
    "decals","explication","cockier","monoxides","hyperventilate","genially","polluter","divan",\
    "may","convalesces","morpheme","pupa","prospered","tagging","nerdier","detached","spearing",\
    "hilbert","russeted","amanuensis","periwinkles","jujube","guarantors","premises","descanting",\
    "baned","deviance","sidearms","lamentable","barristers","climes","succulence","mauve",\
    "oceanographers","migraine","bisexual","peruvians","fatheads","parsimony","pilaf","portly",\
    "conniving","insidiously","inventing","constabulary","cling","stunting","accessioned",\
    "deadliness","overthrow","expectorant","agamemnon","blindfold","striker","shrugging","jibes"};

    // Result
    result = sol.groupAnagrams(strs);
    
    // Display
    cout << "{";
    for (auto x: result)
    {
        cout << "{";
        for (auto y : x)
        {
            cout << y;
        }
        if (x != result.back()) {cout << "}, ";}
        else {cout << "}";}
    }
    cout << "}" << endl;

}