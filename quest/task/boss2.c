#include <ansi.h>
int do_walk();
inherit NPC;
#include "/quest/menpai/romnpc.c"
#include "/quest/menpai/givegift.c"
string  ask_job();
string *first_name = ({ "��","Ǯ","��","��","��","��","֣","��","��","��","��","��","��","��", }); 
string *name_words = ({ "һ","��","��","��","��","��","��","��","��","ʮ", });
string *color_title = ({"[��ɱ��]ɱ��","[��ɷ��]ɱ��",});
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});
mapping *data=({
(["name":"�ٱ�",	"id":"guan bing",	"mw":-1,"weapon":"gangdao",]),
(["name":"���",	"id":"yu fu",	"mw":-1,]),
(["name":"�к�",	"id":"boy",	"mw":-1,]),
(["name":"Ů��",	"id":"girl",	"mw":1,]),
(["name":"��С��",	"id":"xiao er",	"mw":-1,]),
(["name":"Ա��",	"id":"yuanwai",	"mw":-1,]),
(["name":"���",	"id":"ge ji",	"mw":1,]),					
(["name":"�ܼ�",	"id":"guan jia",	"mw":-1,]),
(["name":"�깫",	"id":"gui gong",	"mw":-1,]),
(["name":"����",	"id":"hong niang",	"mw":1,]),
(["name":"С���",	"id":"xiao hunhun",	"mw":-1,]),
(["name":"��ɮ",	"id":"huogong seng",	"mw":-1,]),
(["name":"���",	"id":"huoji",	"mw":-1,]),
(["name":"����ɮ",	"id":"kanmen seng",	"mw":-1,]),
(["name":"����Ů��",	"id":"girl",	"mw":1,]),
(["name":"̤����Ů",	"id":"girl",	"mw":1,]),
(["name":"����Ů��",	"id":"girl",	"mw":1,]),
(["name":"СѾͷ",	"id":"littlegirl",	"mw":1,]),											
(["name":"��ͯ",	"id":"ma tong",	"mw":-1,]),
(["name":"������ͷ",	"id":"lao tou",	"mw":-1,]),		
(["name":"������",	"id":"lao popo",	"mw":1,]),		
(["name":"ǩ��",	"id":"qian ke",	"mw":-1,]),		
(["name":"����С��",	"id":"tang fan",	"mw":-1,]),				
(["name":"�ò�",	"id":"ya chai",	"mw":-1,]),		
(["name":"ɽ��",	"id":"shan zei",	"mw":-1,]),		
(["name":"��ʦ",	"id":"chu shi",	"mw":-1,]),		
(["name":"�����",	"id":"fu ren",	"mw":1,]),		
(["name":"Ů���",	"id":"guan jia",	"mw":1,]),				
(["name":"����",	"id":"lama",	"mw":-1,]),		
(["name":"������",	"id":"lama",	"mw":-1,]),		
(["name":"����",	"id":"pu yi",	"mw":-1,]),		
(["name":"��ǰ����",	"id":"shi wei",	"mw":-1,	"weapon":"gangdao",]),		
(["name":"����Ӫ����",	"id":"shi wei",	"mw":-1,	"weapon":"gangdao",]),				
(["name":"����",	"id":"tiejiang",	"mw":-1,]),		
(["name":"��ؤ",	"id":"qi gai",	"mw":-1,]),			
(["name":"Ů��ؤ",	"id":"nvqi gai",	"mw":1,]),			
(["name":"��ʿ",	"id":"dao shi",	"mw":-1,]),			
(["name":"Ů��ʿ",	"id":"nv daoshi",	"mw":1,]),
(["name":"Ϸ��",	"id":"xi zi",	"mw":1,]),		
(["name":"Ѿ��",	"id":"ya huan",	"mw":1,]),	
(["name":"԰��",	"id":"yuan ding",	"mw":-1,]),	
(["name":"�ƹ�",	"id":"zhanggui",	"mw":-1,]),	
(["name":"�ɲ�Ů",	"id":"cha girl",	"mw":-1,]),	
(["name":"����ʦ",	"id":"old chanshi",	"mw":-1,]),	
(["name":"����",	"id":"dao ke",	"mw":-1,]),	
(["name":"�����",	"id":"jinxiang ke",	"mw":-1,]),	
(["name":"�컨����",	"id":"hong hua",	"mw":-1,]),	
(["name":"����",	"id":"jian ke",	"mw":-1,]),	
(["name":"���",	"id":"ma fu",	"mw":-1,]),	
(["name":"ý��",	"id":"mei po",	"mw":-1,]),		
(["name":"������",	"id":"mengmianren",	"mw":-1,]),			
(["name":"�",	"id":"poor man",	"mw":-1,]),				
(["name":"����",	"id":"shu sheng",	"mw":-1,]),				
(["name":"�Ϻ���",	"id":"lao heshang",	"mw":-1,]),				
(["name":"Сɳ��",	"id":"xiao shami",	"mw":-1,]),				
(["name":"����",	"id":"tiao fu",	"mw":-1,]),							
(["name":"�ο�",	"id":"youke",	"mw":-1,]),				
(["name":"���Ӹ�",	"id":"gongzi",	"mw":-1,]),				
(["name":"�Ů",	"id":"bi nu",	"mw":1,]),				
(["name":"���",	"id":"ni gu",	"mw":1,]),							
(["name":"С��",	"id":"xiao fan",	"mw":-1,]),			
(["name":"��Ů",	"id":"ji nv",	"mw":1,]),	
(["name":"�ϸ���",	"id":"fu zi",	"mw":1,]),	
(["name":"��ͷ",	"id":"bu tou",	"mw":-1,	]),
(["name":"�첶",	"id":"kuai bu",	"mw":-1,	]),
(["name":"����",	"id":"tie bu",	"mw":-1,	]),
(["name":"����",	"id":"ya yi",	"mw":-1,	]),
(["name":"����",	"id":"gong gong",	"mw":-1,	]),
(["name":"����",	"id":"pao tang",	"mw":-1,	]),
(["name":"�ŷ�",	"id":"jiao fu",	"mw":-1,	]),
(["name":"�÷�",	"id":"cai feng",	"mw":-1,	]),
(["name":"ҩʦ",	"id":"yao shi",	"mw":-1,	]),
(["name":"�ٲ�",	"id":"guan cha",	"mw":-1,	]),
(["name":"�佫",	"id":"wu jiang",	"mw":-1,	]),
(["name":"ɽ��ͷ",	"id":"shan zeitou",	"mw":-1,	]),
(["name":"�͵���",	"id":"huo ji",	"mw":-1,	"weapon":"gangdao",	]),
(["name":"����",	"id":"shi wei",	"mw":-1,	"weapon":"changqiang",	]),
(["name":"����",	"id":"tie jiang",	"mw":-1,	"weapon":"gangdao",	]),
(["name":"��åͷ",	"id":"liumang tou",	"mw":-1,	"weapon":"gangjian",	]),
(["name":"����",	"id":"gui gongzi",		"mw":-1,	"weapon":"gangjian",	]),
(["name":"����",	"id":"xing ze",	"mw":-1,	"weapon":"gangdao",]),
(["name":"����ͷ",	"id":"tufei tou",	"mw":-1,	"weapon":"changbian",	]),
(["name":"Ϸ��",		"id":"xi zi",	"mw":-1,	"weapon":"lianzi",]),
(["name":"̨���̷�",	"id":"shang fan",		"mw":-1,	"weapon":"hammer",	]),
(["name":"��������",	"id":"yi ren",	"mw":-1,	"weapon":"gangjian",]),
(["name":"������",	"id":"kanzu ren",	"mw":-1,	"weapon":"changbian",	]),
(["name":"����",		"id":"lie ren",	"mw":-1,	"weapon":"lianzi",]),
(["name":"̨������",	"id":"old lieren",		"mw":-1,	"weapon":"hammer",	]),
(["name":"������",	"id":"muyang ren",	"mw":-1,	"weapon":"gangjian",]),
(["name":"ũ��",	"id":"nong fu",	"mw":-1,	"weapon":"gangjian",]),
(["name":"Ƥ����",	"id":"pihuo sang",	"mw":-1,	"weapon":"changbian",	]),
(["name":"ʯ��",		"id":"shi jiang",	"mw":-1,	"weapon":"lianzi",]),
(["name":"����",	"id":"dao ren",		"mw":-1,	"weapon":"hammer",	]),
(["name":"�ο�",	"id":"you ke",	"mw":-1,	"weapon":"gangjian",]),
(["name":"��ͯ",	"id":"shu tong",	"mw":1,	"weapon":"gangjian",]),
(["name":"��Ӫ����",	"id":"guan bing",	"mw":-1,	"weapon":"changbian",	]),
(["name":"Ա��",		"id":"yuan wai",	"mw":-1,	"weapon":"lianzi",]),
(["name":"����",	"id":"bi qiu",		"mw":-1,	"weapon":"hammer",	]),
(["name":"��å",	"id":"liu mang",	"mw":-1,	"weapon":"gangjian",]),
});



string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});
mapping *data=({
(["id":"zuizui","title":"ؤ��Ŵ�����","name":"׺׺ ",]),
(["id":"zhword","title":"������������","name":"���� ",]),
(["id":"danyingzi","title":"����BUG","name":"������ ",]),
(["id":"fox","title":"������","name":"���� ",]),
(["id":"cash","title":"���������һ","name":"��Ʊ ",]),
(["id":"fen","title":"����ڰ���ʹ","name":"���� ",]),
(["id":"lting","title":"�����滨���滨����","name":"�L���滨","sex":1,]),
(["id":"shazi","title":"��������ϴ�","name":"��� ",]),
(["id":"hotwing","title":"�������������佫","name":"������ʹ ",]),
(["id":"lavender","title":"�������","name":"޹�²�","sex":1,]),
(["id":"bakangel","title":"���ŵ��ߴ�����","name":"����ʹ","sex":1,]),
(["id":"rains","title":"��ɽ�ɵ�ʮ��������","name":"СС��ʿ ",]),
(["id":"guipu","title":"������å����˭������","name":"���� ",]),
(["id":"flyt","title":"���۸����Ϲ���","name":"����","sex":1,]),
(["id":"qing","title":"���ϵ�һŮ��","name":"����Ũ","sex":1,]),
(["id":"sos","title":"������ͳ","name":"�ɷɷɷɻ� ",]),
(["id":"dings","title":"ֻ����������","name":"Ѽ�� ",]),
(["id":"damenly","title":"�Ҿ������ɱ�ɻ���һë����","name":"ȱ�¾�ʿ ",]),
(["id":"qlbl","title":"�嶾�̳���","name":"��竹��� ",]),
(["id":"xbd","title":"�����һ","name":"С���� ",]),
(["id":"game","title":"Ī˼�����������Ҿ���ǰ���ޱ�","name":"��Ϸ ",]),
(["id":"amei","title":"�嶾�̳���","name":"ǧɽĺѩ","sex":1,]),
(["id":"zbabla","title":"�Ұ��汦��","name":"��ң���� ",]),
(["id":"lunar","title":"�һ����ڶ�������","name":"ѩ÷","sex":1,]),
(["id":"yoyo","title":"�һ����ڶ�������","name":"���� ",]),
(["id":"snowfly","title":"��Ҫ������һ��","name":"ѩ��Ʈ","sex":1,]),
(["id":"wto","title":"���ư��ʮ�������","name":"������ŷ ",]),
(["id":"hadis","title":"���ư��ʮ�������","name":"����˹ ",]),
(["id":"angel","title":"������������������ʮ�ߴ�������","name":"糴嵶�� ",]),
(["id":"zohu","title":"��˵���汻�״�����","name":"���� ",]),
(["id":"dfei","title":"��ң�ɻ���ʹ��","name":"��� ",]),
(["id":"bakangel","title":"���ŵ��ߴ�����","name":"����ʹ","sex":1,]),
(["id":"woodtian","title":"�ҵ�˧������ʮ����͵�����","name":"�Ұ�����Ů ",]),
(["id":"kjhojin","title":"���ŵ��ߴ�����","name":"ˮ���","sex":1,]),
(["id":"thill","title":"�����ڲ�����������","name":"������ ",]),
(["id":"dido","title":"��Ӱ���ťҥ���","name":"������ ",]),
(["id":"cold","title":"�����﷢��һ����","name":"���� ",]),
(["id":"scan","title":"����ͷ�ŵ���","name":"��Ӣ���� ",]),
(["id":"lubinh","title":"һ����ǰ��û���㣬Ҳû����","name":"С���� ",]),
(["id":"lightning","title":"�����ɵ���ʮ�������","name":"���� ",]),
(["id":"xiaomei","title":"�䵱�ɵڶ�������","name":"С��","sex":1,]),
(["id":"dldi","title":"�������������佫","name":"�����幤 ",]),
(["id":"mafan","title":"��ң�ɻ���ʹ��","name":"�鷳 ",]),
(["id":"hailoo","title":"ȫ��̵ڶ�������","name":"��������","sex":1,]),
(["id":"bingxueer","title":"�����Ľ��е���","name":"��ѩ��","sex":1,]),
(["id":"caree","title":"�����ŵ���������","name":"��������","sex":1,]),
(["id":"damenl","title":"����ͷ","name":"��Ǯ�뷢�� ",]),
(["id":"xiaotian","title":"ͨ������±�Х��͵�������","name":"Х�� ",]),
(["id":"waaas","title":"������һ������","name":"�ض�","sex":1,]),
(["id":"dbabla","title":"�嶾����","name":"��а ",]),
(["id":"lyf","title":"������·�㲻��ѽ","name":"������","sex":1,]),
(["id":"loveyqh","title":"��ɽ�ɵ�ʮ�Ĵ�����","name":"ˮ�� ",]),
(["id":"lovefox","title":"���ϸ�","name":"����","sex":1,]),
(["id":"linda","title":"���ã������Լ���ͦ����...","name":"�׾���","sex":1,]),
(["id":"lindy","title":"��֮��","name":"Ľ����","sex":1,]),
(["id":"lexy","title":"��ɽ�ɵ�ʮ�Ĵ�����","name":"����ң ",]),
(["id":"laiyinhate","title":"��Ӱ�����ų�","name":"������� ",]),
(["id":"yzx","title":"��һ���ķ���","name":"�������� ",]),
(["id":"xnh","title":"ѩɽ�����Ŵ����","name":"���� ",]),
(["id":"xjhjin","title":"��ң�ɵ���","name":"����","sex":1,]),
(["id":"xiaoxuan","title":"��ġ�sk�������ˣ�","name":"������ ",]),
(["id":"xdb","title":"��ɽ����","name":"ѩ���� ",]),
(["id":"wumi","title":"Ư���Ļ�����","name":"���� ",]),
(["id":"wukong","title":"����Ľ��","name":"�����ʥ ",]),
(["id":"wishluck","title":"�л�ʥ���⽻����","name":"С����","sex":1,]),
(["id":"winco","title":"������������֪�����������һ�","name":"�Ʒ� ",]),
(["id":"wanxia","title":"������±��޼۽�ˮԶɽ������","name":"��ϼ","sex":1,]),
(["id":"wanghu","title":"���м��˹�����һ�轣�����ķ�","name":"������� ",]),
(["id":"waaa","title":"��������Ϊ����","name":"���� ",]),
(["id":"myth","title":"����Ľ�ݵڶ�������","name":"Ľ�ݲ� ",]),
(["id":"vov","title":"õ����ʹ^_^","name":"���� ",]),
(["id":"tyywl","title":"����ɽ�ɵڶ�������","name":"��ҰԴ���� ",]),
(["id":"ttss","title":"�����޵��Ʋ���","name":"������","sex":1,]),
(["id":"tianjun","title":"���ϸ�ɽ������Ϫ��","name":"���� ",]),
(["id":"tcl","title":"ѩɽ���׼ҵ���","name":"���� ",]),
(["id":"taotao","title":"����ɽ�ɵڶ�������","name":"OhMyGod ",]),
(["id":"sug","title":"��ȹ����˭��Ů","name":"�����","sex":1,]),
(["id":"sprite","title":"��Ĺ�ɵ��Ĵ�����","name":"С���� ",]),
(["id":"sony","title":"�䵱�ɵڶ�������","name":"Ե�� ",]),
(["id":"snq","title":"�����ǳ���","name":"СС ",]),
(["id":"snow","title":"����Ϊ��","name":"������ѩ","sex":1,]),
(["id":"smj","title":"Ҫ exp","name":"������ ",]),
(["id":"smile","title":"������","name":"���� ",]),
(["id":"sjmoxj","title":"���","name":"����ʫ�� ",]),
(["id":"siren","title":"�������","name":"��� ",]),
(["id":"shuanger","title":"����С��Ů","name":"����˪","sex":1,]),
(["id":"shanc","title":"���չ��ڶ�������","name":"����","sex":1,]),
(["id":"sgy","title":"����","name":"С�� ",]),
(["id":"scare","title":"�Ұ� �³�","name":"Ц���� ",]),
(["id":"rui","title":"Amy�ľ��� ������","name":"��ѩƮ��","sex":1,]),
(["id":"quanjia","title":"������ˮ","name":"Ȫ��","sex":1,]),
(["id":"qkry","title":"��������ν����״�����","name":"Ǭ������ ",]),
(["id":"qiuqiu","title":"ؤ���ʮ�Ŵ�����","name":"���� ",]),
(["id":"qazqaz","title":"��������е���","name":"������ ",]),
(["id":"pxf","title":"~_______~","name":"ľ�� ",]),
(["id":"pcgame","title":"��ң�ɻ���ʹ��","name":"���� ",]),
(["id":"papaya","title":"�����԰����� ","name":"���� ",]),
(["id":"orange","title":"��ʦ��","name":"����","sex":1,]),
(["id":"ooo","title":"����HY��å�ϴ�","name":"���֮�� ",]),
(["id":"only","title":"����Թ�","name":"�����о� ",]),
(["id":"nvnv","title":"��һ��·ä","name":"���� ",]),
(["id":"npc","title":"ȫ��̵ڶ�������","name":"С����","sex":1,]),
(["id":"name","title":"��Ʒ����","name":"ֱ���� ",]),
(["id":"mzlm","title":"�������ֺ�","name":"���� ",]),
(["id":"marine","title":"��Ӱ���š����","name":"����Ź� ",]),
(["id":"means","title":"���ư��Ϲٰ�������","name":"��˼ ",]),
(["id":"miean","title":"���ε���û��Ϊ�����ؿ���Ǯ","name":"���� ",]),
(["id":"mingyang","title":"�һ��콣","name":"���� ",]),
(["id":"mini","title":"����μҵ�ʮ�ߴ�����","name":"���� ",]),
(["id":"mmm","title":"���������벻Ҫ��me˵��","name":"�Ž�һ�� ",]),
(["id":"mrf","title":"����Ľ�ݵ���������","name":"Ľ�ݷ� ",]),
(["id":"mryh","title":"���","name":"�ƻ� ",]),
(["id":"myboy","title":"���ա��ˡ隸��Ǯ","name":"������� ",]),
(["id":"mygirl","title":"С�¹���","name":"����","sex":1,]),
(["id":"lang","title":"�ԾƵ��裬��������","name":"�˷��� ",]),
(["id":"langer","title":"����������������","name":"���� ",]),
(["id":"legs","title":"ѡ������ ������ѡ","name":"��������","sex":1,]),
(["id":"lbxx","title":"ѩɽ���׼ҵ���","name":"����С�� ",]),
(["id":"lengxin","title":"��������ʦ","name":"���� ",]),
(["id":"ling","title":"ȫ��̵ڶ�������","name":"���","sex":1,]),
(["id":"ljgbook","title":" �������ʵ���������Ϊʲô������","name":"����","sex":1,]),
(["id":"lkdd","title":"������������������������ޱ�","name":"�ٱ��Ǿ� ",]),
(["id":"kara","title":"�����¸ɱ�","name":"����","sex":1,]),
(["id":"keeny","title":"����������Ҫ��������Ҳ������","name":"���� ",]),
(["id":"keyboard","title":"������ˡ���С�","name":"���� ",]),
(["id":"kgb","title":"��Զ��(ͨ����)","name":"����С�� ",]),
(["id":"killman","title":"�ɻ�С��","name":"�����Ǯ�� ",]),
(["id":"jad","title":"������ȸ¥֮�󵱼�","name":"���� ",]),
(["id":"jianxin","title":"��̫�ĵ���","name":"��̫ ",]),
(["id":"jxy","title":"��ɽ�ɵ�ʮ��������","name":"Ф�� ",]),
(["id":"icefox","title":"�þ�û����","name":"���� ",]),
(["id":"hadis","title":"���ư��ʮ�������","name":"����˹ ",]),
(["id":"hechuan","title":"ؤ��Ŵ�����","name":"��Ӣ�� ",]),
(["id":"hehaia","title":"����ʹ��","name":"�κ��� ",]),
(["id":"himura","title":"����μҵ�ʮ�ߴ�����","name":"���� ",]),
(["id":"honda","title":"��ӭ����www.fivekids.com","name":"���� ",]),
(["id":"huakai","title":"�����ǵ��ߴ�����","name":"���仨�� ",]),
(["id":"hylijun","title":"��ɽ�ɵ�ʮ��������","name":"����è ",]),
(["id":"hxt","title":"ʥ�����վ","name":"��ֽһ�� ",]),
(["id":"huihui","title":"�����ɵ���ʮ������","name":"��Ľ ",]),
(["id":"gameking","title":"�����ɾ����ڶ�������","name":"��Ϸ֮�� ",]),
(["id":"gaoc","title":"�߲��Թ�����","name":"�߲� ",]),
(["id":"gmxy","title":"����","name":"���� ",]),
(["id":"grape","title":"�մ�һ��¹����","name":"�̶��� ",]),
(["id":"green","title":"�����Թſ����","name":"��Ҷ�� ",]),
(["id":"fadai","title":"һ���˵�׷��","name":"���� ",]),
(["id":"fall","title":"�մ�һ��¹����","name":"������","sex":1,]),
(["id":"fff","title":"�����ĺ���","name":"���� ",]),
(["id":"ffs","title":"����","name":"��а ",]),
(["id":"fgy","title":"���ǽ�","name":"������ ",]),
(["id":"flower","title":"��������������ū","name":"������","sex":1,]),
(["id":"foryou","title":"Ϊ������","name":"��ʫ","sex":1,]),
(["id":"foxzzz","title":"�մ�һ��¹����","name":"ѩ��","sex":1,]),
(["id":"frfr","title":"ؤ��Ŵ�����","name":"���� ",]),
(["id":"ftoiloveyou","title":"wait me xue yitiantulong","name":"ѩ����ʥ ",]),
(["id":"fury","title":"һ�������������ҵ���ͷ��","name":"��ƽ�� ",]),
(["id":"fusheng","title":"����ɳ����ǧ����һЦ������","name":"��.���� ",]),
(["id":"eddie","title":"Amy�Ĵ��׾��������ų�","name":"������","sex":1,]),
(["id":"ehuan","title":"���� no look","name":"����","sex":1,]),
(["id":"enjoy","title":"ɫ��","name":"���� ",]),
(["id":"eric","title":"��ң�ɵ��Ĵ�����","name":"���� ",]),
(["id":"dairun","title":"�մ�һ��¹����","name":"���� ",]),
(["id":"dali","title":"�ܲ������","name":"���� ",]),
(["id":"datank","title":"�����ɵ���������","name":"��̹�� ",]),
(["id":"dhxy","title":"���ϴ����򡿱��Ϲ�Ѳ��ɱ��","name":"������ ",]),
(["id":"digu","title":"���ڹ��Ϻ����ӣ����Ͽ����","name":"ͯ��ϱ ",]),
(["id":"dldi","title":"�������������佫","name":"�����幤 ",]),
(["id":"dodo","title":"�»�Ұ��","name":"ûƷ���� ",]),
(["id":"donkey","title":"���ŵ��ߴ�����","name":"¿�� ",]),
(["id":"duly","title":"�ɻ�С��","name":"���� ",]),
(["id":"caiyi","title":"��ң�ɻ���ʹ��","name":"����","sex":1,]),
(["id":"camin","title":"�ɻ�С��","name":"Ц�� ",]),
(["id":"chaosheng","title":"Diablo12 www.love214.com","name":"���� ",]),
(["id":"cloud","title":"��ɽ�ɵ�ʮ��������","name":"���� ",]),
(["id":"com","title":"ǧ��˼��Ī����","name":"��� ",]),
(["id":"cutlove","title":"����ɽ�ɵڶ�������","name":"�ᵶ ",]),
(["id":"baggio","title":"����Ǳ��","name":"��ԯ�� ",]),
(["id":"baishi","title":"mely��רְ����","name":"������","sex":1,]),
(["id":"banana","title":"�����ɵ���������","name":"�㽶 ",]),
(["id":"baoer","title":"��ɽ�ɵ�ʮ��������","name":"�ֱ��� ",]),
(["id":"battlee","title":"����Ż���������ʦ��","name":"Ѧ��","sex":1,]),
(["id":"bear","title":"�ҹһ�������","name":"Ц�� ",]),
(["id":"bee","title":"��Ϸ����","name":"Ů����","sex":1,]),
(["id":"bihu","title":"С����","name":"�ڻ� ",]),
(["id":"biluo","title":"��ة��","name":"����������","sex":1,]),
(["id":"bird","title":"����ʹ��","name":"����","sex":1,]),
(["id":"bingxueer","title":"�����Ľ��е���","name":"��ѩ��","sex":1,]),
(["id":"bmr","title":"����","name":"ѩ��","sex":1,]),
(["id":"budai","title":"����Ľ�ݵ��Ĵ�����","name":"������ȥ ",]),
(["id":"bullet","title":"��Ҫ! ��Ҫ�� ��������","name":"С�� ",]),
(["id":"admire","title":"����������Ѱ����","name":"���� ",]),
(["id":"aka","title":"��������","name":"���� ",]),
(["id":"akan","title":"С����","name":"Ī������ ",]),
(["id":"amejio","title":"�һ����ڶ�������","name":"���","sex":1,]),
(["id":"amy","title":"�������µ�һ","name":"����","sex":1,]),
(["id":"ant","title":"��˭�ڶ���˵����������","name":"����","sex":1,]),
(["id":"anran","title":"��Ĺ֮����է��","name":"������Ȼ ",]),
(["id":"aoe","title":"�������� ���سɷ�","name":"�ɰ� ",]),
(["id":"axax","title":"Ը�������̳�� ��������ɨ�仨","name":"����",]),
(["id":"skbh","title":"��ͨ����","name":"���ڰ׻�","sex":0,]),
(["id":"capsyb","title":"�������������Ů","name":"Ģ������","sex":1,]),
(["id":"zhm","title":"�������������Ҷ�","name":"�ƹ���","sex":0,]),
(["id":"drip","title":"����μҵ�ʮ�ߴ�����","name":"����","sex":0,]),
(["id":"xxxxa","title":"Ů���΢Ц","name":"����","sex":0,]),
(["id":"poseidon","title":"����Ľ�ݵ��Ĵ�����","name":"������","sex":0,]),
(["id":"zeus","title":"����Ľ�ݵ��Ĵ�����","name":"��˹","sex":0,]),
(["id":"hera","title":"����Ľ�ݵ��Ĵ�����","name":"����","sex":1,]),
(["id":"avatar","title":"����Ľ�ݵ��Ĵ�����","name":"������","sex":0,]),
(["id":"xianodc","title":"����Ľ�ݵ��Ĵ�����","name":"ŶŶ","sex":0,]),
(["id":"shinsoo","title":"��ɽ�ɵ�ʮ�Ĵ�����","name":"������","sex":0,]),
(["id":"adj","title":"�һ����ڶ�������","name":"�ΰ���","sex":0,]),
(["id":"wansom","title":"ȫ��̵ڶ�������","name":"��������","sex":0,]),
(["id":"mimi","title":"ȫ��̵ڶ�������","name":"С��","sex":0,]),
(["id":"replacement","title":"ȫ��̵ڶ�������","name":"���������","sex":0,]),
(["id":"thill","title":"��ɽ�ɵ�ʮ�Ĵ�����","name":"ǧɽĺѩ","sex":1,]),
(["id":"kaillera","title":"�ɹ�����","name":"¬��","sex":1,]),
(["id":"nos","title":"��ɽ�ɵ�ʮ�������� ","name":"��٤��","sex":0,]),
(["id":"kenwaj","title":"��ɽ�ɵ�ʮ�������� ","name":"����","sex":0,]),
(["id":"koma","title":"�����ɵڶ�������","name":"����","sex":0,]),
(["id":"woshiwang","title":"�㵴�ɵڶ�������","name":"������","sex":1,]),
(["id":"wutong","title":"��ͨ����","name":"��Ͳ","sex":0,]),
(["id":"slyaxu","title":"��ɽ�ɵ�ʮ�Ĵ�����","name":"����վ","sex":0,]),
(["id":"yesno","title":"�һ����ڶ�������","name":"�Ƿ�","sex":0,]),
(["id":"blyaxu","title":"��ң�ɵ��Ĵ�����","name":"����վ","sex":0,]),
(["id":"guhui","title":"����","name":"�ǻ�","sex":0,]),
(["id":"shakb","title":"�����ŵڶ�������","name":"��ͷ��","sex":0,]),
(["id":"luxifa","title":"���չ��ڶ�������","name":"·����","sex":1,]),
(["id":"oldgui","title":"��ң�ɻ���ʹ��","name":"�ǹ�","sex":1,]),
(["id":"lyaxu","title":"�������ɵ�ʮ�˴�����","name":"����վ","sex":0,]),
(["id":"sim","title":"������","name":"��ë","sex":0,]),
(["id":"zmkk","title":"�����ǳ���","name":"������","sex":1,]),
(["id":"duanzihen","title":"С�㣬�����ɵ�������","name":"���Ӻ�","sex":0,]),
(["id":"xianodd","title":"ؤ���ʮ�˴�����","name":"������","sex":0,]),
(["id":"protoss","title":"ؤ���ʮһ������","name":"С��","sex":0,]),
(["id":"guaf","title":"�����̵ڶ�������","name":"�η�","sex":0,]),
(["id":"xianoda","title":"ؤ���ʮ�˴�����","name":"�ž�","sex":1,]),
(["id":"huaxinfeng","title":"������̵ڶ�������","name":"�����","sex":0,]),
(["id":"shaka","title":"�վ�һ����ÿ��˵һ��","name":"ɳ��","sex":0,]),
(["id":"fcl","title":"÷ׯ�ڶ�������","name":"�����","sex":1,]),
(["id":"zhaisi","title":"�����ɵ���ʮ�������","name":"����","sex":0,]),
(["id":"been","title":"�䵱�ɵ��Ĵ�����","name":"������","sex":0,]),
(["id":"huajian","title":"���չ��ڶ�������","name":"����","sex":1,]),
(["id":"flysnow","title":"ؤ���ʮ�˴�����","name":"��ѩ","sex":1,]),
(["id":"aka","title":"ؤ���ʮ�˴�����","name":"����","sex":0,]),
(["id":"wutiao","title":"��ͨ����","name":"����","sex":0,]),
(["id":"zorromar","title":"�㵴�ɵ���������","name":"Ľ����","sex":1,]),
(["id":"xianodb","title":"ؤ���ʮ�˴�����","name":"ʷ�ٷ�","sex":0,]),
(["id":"numen","title":"�һ�������������","name":"����","sex":1,]),
(["id":"kick","title":"��ͨ����","name":"���","sex":0,]),
(["id":"abc","title":"��ͨ����","name":"ũҵ����","sex":0,]),
(["id":"xmtl","title":"������̵ڶ�������","name":"Ϯ������","sex":0,]),
(["id":"renzha","title":"ؤ��ڶ�ʮ������","name":"����","sex":0,]),
(["id":"phoenix","title":"���ŵھŴ�����","name":"������","sex":1,]),
(["id":"sanba","title":"�嶾�̳���","name":"����","sex":1,]),
(["id":"dtyk","title":"���ư��ʮ�������","name":"����","sex":0,]),
(["id":"waseem","title":"��ͨ����","name":"������","sex":1,]),
(["id":"zmkk","title":"�����ǳ���","name":"������","sex":1,]),
(["id":"yoshare","title":"���ŵ��ߴ�����","name":"������","sex":1,]),
(["id":"spray","title":"��ң�ɵ���������","name":"�Ʊ���","sex":1,]),
(["id":"mist","title":"����Ľ�ݵ���������","name":"��˪��","sex":0,]),
(["id":"rains","title":"����μҵ�ʮ�Ŵ�����","name":"������","sex":0,]),
(["id":"zhma","title":"�һ����ڶ�������","name":"���º�","sex":1,])


});

mixed get_auto_actions(string action);
void change_combat_mode(object me, int mode);
int ask_job();
int ask_job2();
void create()
{
	mapping npc,mp,j;
	mapping hp_status, skill_status, map_status, prepare_status;
mapping my;
string *sname, *mname, *pname;
	string sex;
	object ob, weapon;
	int i,k,a,b,c,d,e,f,temp;

ob=this_object();
	k=random(29);
	//k=11;
	npc=data[random(sizeof(data))];
	sex=npc["sex"];
	set_name(npc["name"]+NOR,({ npc["id"] }));
	set("title",(order[random(13)])+(npc["title"])+NOR);

set("vendetta/authority",1);
	set("age",20+random(30));
        set("per",20+random(30));
if (sex)
set("gender", "Ů��" );
else set("gender", "����" );
	set("combat_exp",2000000+random(28000000));
set("skill_public",1);
set("pubmaster",1);
	set("taskid", 1);
	set_temp("apply/attack",50);
	set_temp("apply/defense",200);
	set_temp("apply/armor",650);
	set_temp("apply/damage",650);
	set("max_force",2000);
	set_skill("unarmed",200);
	set_skill("sword",200);
	set_skill("club",200);
	set("isteamjob",1);
	set_skill("whip",200);
	set_skill("throwing",200);
	set_skill("parry",200);
	set_skill("dodge",200);
        set("tasknpc",1);
        set("dex",200);
        set("no_get",1);
        set("szj/passed",1);
        set("double_attack",1);
        set("breakup", 1);
        set("szj/over200", 1);
        set("jiuyin/full", 1);
        set("jiuyin/shang", 1);
        set("jiuyin/xia", 1);
b=8000+random(18000);
a=8000+random(18000);
d=20+random(60);
set("str",d);
set("dex",100);
set("int",d);
set("con",d);
set("per",d);
set("kar",d);
        set("jing",b);
        set("max_jing",b);
set("eff_jing",b);

        set("qi",a);
        set("max_qi",a);
set("eff_qi",a);
        set("neili",a);
        set("max_neili",a);
        i=220+random(800);
        e=220+random(800);



        
f=1+random(8);        
	setup();
	        set("check_time", time());
set_heart_beat(1);
      
        set("chat_chance", 30);
        set("chat_msg", ({
                (: do_walk :),
                (: random_move :),
        }) );

        set("inquiry", ([
   	    "�ܼ�"  : (: ask_job :),
	    "task"  : (: ask_job :),
            ]));
      
//initlvl(200+random(188));
	
	add_money("silver",50+random(50));
}
       



void init()
{
        remove_call_out("leave");
        call_out("leave",480);
}
void leave()
{
        object ob = this_object();
        if (!ob->is_fighting()) {
                message_vision(this_object()->query("name") + "���·�ߵ��Ӳݣ������ˡ�\n" NOR,this_object());
                destruct(this_object());
                }
        else call_out("leave",30);
}



int do_walk()
{
        string start_room;
 string name,weapon;
        object room;
        object ob;
        mapping obmap;
        int n;
        int i;
	object *inv;
        if (! environment())
                return 0;
        name = color_title[random(sizeof(color_title))]+first_name[random(sizeof(first_name))];
        name += name_words[random(sizeof(name_words))]; 
//1800
//        if (time() - query("check_time") > 3600)
      if (time() - query("check_time") > 600 || !query_heart_beat(this_object()))
        {

       set("gender", "����");
       set("title", color_title[random(sizeof(color_title))]);
        n = 0;
	inv = all_inventory(this_object());



                        
                        destruct(this_object());
                        return 0;
        }

        n = 0;
        foreach (ob in all_inventory(environment()))
        {
                if (!ob)  continue;
                if (!ob->query("dynamic_quest"))
                        continue;
        command ("get all");
                n++;
        }

                        
        random_move();
        return 1;
}

int accept_fight(object ob)
{
				command("say " + RANK_D->query_self(this_object())
					+ "��ô������" + RANK_D->query_respect(ob)
					+ "�Ķ��֣�\n");
		  return 0;
}

int kill_ob(object ob)
{
        string start_room;
 string name,weapon;
        object room;
        mapping obmap;
        int n;
        int i;
	object *inv;
        name = color_title[random(sizeof(color_title))]+first_name[random(sizeof(first_name))];
        name += name_words[random(sizeof(name_words))]; 
		  //command("fear");
		  command("say ���ã��ұ�ʶ����!!");
if (random(5)==1)
{
command("say �Ӱ�!!");
if (random(3)==1)
{
command("go south");
command("go south");
command("go south");
command("go west");
command("go west");
command("go northup");
command("go southup");
command("go eastup");
command("go westup");
command("go northdown");
command("go southdown");
command("go eastdown");
command("go westdown");
command("go northeast");
command("go northwest");
command("go southeast");
command("go southwest");
command("go north");
command("go east");
}
else
{
command("go north");
command("go north");
command("go north");
command("go east");
command("go east");
command("go north");
command("go northup");
command("go southup");
command("go eastup");
command("go westup");
command("go northdown");
command("go southdown");
command("go eastdown");
command("go westdown");
command("go northeast");
command("go northwest");
command("go southeast");
command("go southwest");
command("go south");
command("go west");

}
}




}



string ask_job()
{     object guo,ob,obn;
      object *team;
	  int i=0,count=0,minexp,maxexp;
      string where;
	  guo =this_object();
	  ob=this_player();
 if (!environment(guo)->query("no_fight"))
return  "������ʲô��?";
 if (environment(guo)->query("no_fight"))
{
command("say �Ӱ�!!");
if (random(2)==1)
{
random_move();
        set("chat_chance", 90);
        set("chat_msg", ({
                (: do_walk :),
                (: random_move :),
        }) );

}
else
{

random_move();
        set("chat_chance", 90);
        set("chat_msg", ({
                (: do_walk :),
                (: random_move :),
        }) );

}
}
return  "�����˶࣬����ȫ������!";
}



int random_move()
{
        mapping exits;
        string *dirs;
        object me = this_object();

//        if (!query_heart_beat(me)) return 0;
	if( !environment(me) ) return 0;
        if( me->query_temp("is_unconcious") ) return 0;

	if( !living(me)) return 0;

	if( !mapp(exits = environment()->query("exits")) ) return 0;
        if( !environment() 
        || !mapp(exits = environment()->query("exits")) 
        || me->is_busy())
// || me->is_fighting()
        return 0;                 
//        if( !mapp(exits = environment()->query("exits")) 
//        || me->is_busy()) return 0;
        dirs = keys(exits);
        if (!dirs)  return 0;
        if (sizeof(dirs) < 1) return 0;
        command("go " + dirs[random(sizeof(dirs))]);
}

