#include <net/daemons.h>

inherit F_CLEAN_UP;
string  zuji(string str);
mapping *dddata=({
(["name":"����ѩɽ",	"long":"ѩɽɽ���������ƣ�Զ����һ������ɫ�ľ�������˵�����","tname":"migong0","ttg":"/d/kunming/dxiaolu","npc":"npc1","boss":"boss1","lv":"100",]),
(["name":"����ɽ",	"long":"����ɽλ�ڼ��꽭����Ͽ�ϣ�������ɽ����ľ���죬������֣��������ġ�","tname":"migong1","ttg":"/d/baling/edao5","npc":"npc2","boss":"boss2","lv":"110",]),
(["name":"��ɽ",	"long":"��Ȼɽˮ����ʤ�ż������������Ժ�������ֹ��ơ�","tname":"migong2","ttg":"/d/tanggu/gangkou","npc":"npc3","boss":"boss3","lv":"120",]),
(["name":"��̨ɽ",	"long":"��̨ɽ���Ĵ�����ɽ�����վŻ�ɽ���㽭����ɽ�����й�����Ĵ���ɽ��","tname":"migong3","ttg":"/d/taiyuan/road1","npc":"npc4","boss":"boss4","lv":"130",]),
(["name":"����ɽˮ",	"long":"����ɽˮһ����ɽ�ࡢˮ�㡢���桢ʯ��������ɽˮ�����µ�����","tname":"migong4","ttg":"/d/yanping/fuqiao1","npc":"npc5","boss":"boss5","lv":"140",]),
(["name":"��������",	"long":"����֮����ں���ɽ�У�ɽ�����⣬����ɽ������á�","tname":"migong5","ttg":"/d/hangzhou/baiti","npc":"npc6","boss":"boss6","lv":"150",]),
(["name":"����ɽ",	"long":"����ɽ����������������ũ����������������Ժ��������ӣ���������","tname":"migong6","ttg":"/d/tiezhang/road-3","npc":"npc7","boss":"boss1","lv":"160",]),
(["name":"��կ��",	"long":"��կ����ˮ�����ΰ׺ӵ�֧�������оŸ������կ������","tname":"migong7","ttg":"/d/qingzh/road8","npc":"npc8","boss":"boss8","lv":"170",]),
(["name":"������Ͽ ",	"long":"��������Ͽ����Ͽ��ȣ�����������ս����������Ӣ�ۺ�������֮�ء�","tname":"migong8","ttg":"/d/baling/edao10","npc":"npc9","boss":"boss9","lv":"180",]),
(["name":"��˫����",	"long":"��˫���ɣ��Ŵ�����Ϊ�°�����������˼���������������� ","tname":"migong9","ttg":"/d/kunming/nanmen","npc":"npc10","boss":"boss10","lv":"190",]),
(["name":"�ƹ�����",	"long":" �ƹ����ٲ�λ�ڹ��ݵİ�ˮ���ϡ���Χ���ܹ㲼���ӿ�ˮ����","tname":"migong10","ttg":"/d/kunming/pubu","npc":"npc11","boss":"boss11","lv":"200",]),
(["name":"����̶",	"long":"����̶����һС��Զ��������ˮ���ϵ�һ�����ӣ��������졣 ","tname":"migong11","ttg":"/d/taiwan/riyuetan","npc":"npc12","boss":"boss12","lv":"210",]),
(["name":"����ʯ��",	"long":"�����Ϻ������޿���ļ��紺���������µ�һ���ʯ�ֲ���ݵ�����","tname":"migong12","ttg":"/d/kunming/shilin2","npc":"npc13","boss":"boss13","lv":"220",]),
(["name":"����԰��",	"long":"����������ɽˮ������԰�ֵ��Ŷ��������£��н���԰�ּ����£�����԰�ּ׽��ϵ����ơ�","tname":"migong13","ttg":"/d/suzhou/yanyutang","npc":"npc14","boss":"boss14","lv":"230",]),
(["name":"��ɽ���",	"long":"��ɽ����������ƴ�𣬵ش��й��Ĵ�ʡ��ɽ�У�ẽ������½��ʹ�ɺ�������������","tname":"migong14","ttg":"/d/xinan/leshan","npc":"npc15","boss":"boss15","lv":"240",]),
(["name":"��������",	"long":"����ʥ�ǡ�ǧ�����ֹ鶫³������¹ڰ���������֮���������л���������ӵ����ֽ��������ġ� ","tname":"migong15","ttg":"/d/jinan/road2","npc":"npc16","boss":"boss16","lv":"250",]),
(["name":"��ʼ�ʱ���ٸ",	"long":"����ٸ������ǧ����ִ��������ʿ������ƥҷ����ս��һ���С�һ���У����ɹ�ģ��ΰ�����ư�������ݡ�","tname":"migong16","ttg":"/d/city4/apanggong","npc":"npc17","boss":"boss17","lv":"260",]),
(["name":"�е±���ɽׯ",	"long":"����ɽׯ�����ص��ŵ�ɽ��ҰȤΪ�����ȡ��Ȼɽˮ֮��ɫ�����ս�������  ����ɽׯ֮���","tname":"migong17","ttg":"/d/changcheng/nroad1","npc":"npc18","boss":"boss18","lv":"270",]),
(["name":"�ػ�Ī�߿�",	"long":"���˶��ߵ����ܺͿ߶������������ŷ��񡢷��졢���֡���Ů������Ů�˵ȡ�","tname":"migong18","ttg":"/d/qilian/yumenguan","npc":"npc19","boss":"boss19","lv":"280",]),
(["name":"��������",	"long":"��������޸ɲ�ΪӭȢ�ĳɹ������˽��ġ�����������������Ĳ�ʽ�����ɽ������������ΰ��","tname":"migong19","ttg":"/d/xizang/birdroad2","npc":"npc20","boss":"boss20","lv":"290",]),
(["name":"��������",	"long":"���������´����ڶ�����ƽʮһ��68�꣬Ϊ�й���һ��ɲ����������٤�����Ƿ�̴����й����˽��ĵ�һ����Ժ��","tname":"migong20","ttg":"/d/kaifeng/wroad3","npc":"npc21","boss":"boss21","lv":"300",]),
(["name":"����",	"long":"���������ڶպ���գ�������ǧ�����ƾ���ʷ����������֮�磬˿��֮��֮�ơ�","tname":"migong21","ttg":"/d/hangzhou/road4","npc":"npc22","boss":"boss22","lv":"310",]),
(["name":"��ׯ",	"long":"������ׯʼ����1086�꣬�������ܵϹ����������ȫ���¶�������","tname":"migong22","ttg":"/d/hangzhou/suti7","npc":"npc23","boss":"boss23","lv":"320",]),
(["name":"��������",	"long":"���ݴ������ڻ�ɽ��´�������һ�Դ���˼�֮�ơ�","tname":"migong23","ttg":"/d/huangshan/taoyuan","npc":"npc24","boss":"boss24","lv":"330",]),
(["name":"���Ϻ��",	"long":"������۴��αȵĲ�¥��Ժ���컵ĺ���ɽɫ�����ӳ���������ˣ������̽壬�����Ǿ��������뻭","tname":"migong34","ttg":"/d/huangshan/lianhua","npc":"npc25","boss":"boss25","lv":"340",]),
(["name":"̩������",	"long":"̩�����к��ƹ�����������֮�ƣ�������ʯ��ʱ���������������ﷱ����Ϣ��","tname":"migong25","ttg":"/d/fuzhou/shulin","npc":"npc26","boss":"boss26","lv":"350",]),
(["name":"ɽ���ű�",	"long":"ɽ���ű���ξ�ٹ�����������������ս�ؽ���ʱ��Ϊ���������Ǳ������ڵص�ʱ�����","tname":"migong26","ttg":"/d/taiyuan/sroad6","npc":"npc27","boss":"boss27","lv":"360",]),
(["name":"��ׯ",	"long":"��ׯ�������������˻���������ĸ�׺ӡ����������ϰ���������ɽ��ɽ��������ɽ��ˮ���羰���ˡ�","tname":"migong27","ttg":"/d/hangzhou/shiwudong","npc":"npc28","boss":"boss28","lv":"370",]),
(["name":"�����",	"long":"���������ʷ�ƾõ��Ļ����������������֮�硢˿��֮��֮����������ʱ���������̼��Ƽ������÷���","tname":"migong28","ttg":"/d/hangzhou/shuiledong","npc":"npc29","boss":"boss29","lv":"380",]),
(["name":"ͬ����",	"long":"ͬ��ɳƸ������Ƴ���Ϊͭ���ʱ����������Ϊͬ�ͬ��羰�������������滷ˮ��","tname":"migong29","ttg":"/d/hangzhou/shanlu4","npc":"npc30","boss":"boss30","lv":"390",]),
(["name":"��˳��",	"long":"��˳������������գ�������һ��С���ƴ������������˳����ȡʿ����˳֮�⣬�Ż�Ϊ��˳�硣","tname":"migong31","ttg":"/d/kunming/qingshilu2","npc":"npc31","boss":"boss31","lv":"400",]),
(["name":"������",	"long":"�����Ҿ�����ɢ���ڹ������������ҡ��˶��������������ɣ���ɽ��ˮ�㡢��ɽ��ӳ����Ѩ�����ʤ����","tname":"migong32","ttg":"/d/henshan/hsroad9","npc":"npc32","boss":"boss32","lv":"410",]),
(["name":"�����ٲ�",	"long":"�����ٲ����й��ƺ��ϵ������ٲ����䱼����ӿ���������л����徫���������","tname":"migong33","ttg":"/d/city4/road4","npc":"npc33","boss":"boss33","lv":"420",]),
(["name":"ƽң��",	"long":"ƽң�ɳƹ��գ��������꣬Ϊ�����������ţ�ʼ����ǽ���������깫Ԫ1370���ھ�ǽԫ�������������ޣ���ȫ���ש��","tname":"migong34","ttg":"/d/taiyuan/road4","npc":"npc34","boss":"boss34","lv":"430",]),
(["name":"�Ƹ�ʯ��",	"long":"�Ƹ�ʯ��λ������ɽ��´����ɽ���䣬��������Լһ������ƻֺ룬���ݷḻ��","tname":"migong35","ttg":"/d/taiyuan/road5","npc":"npc35","boss":"boss35","lv":"440",]),
(["name":"��˷��",	"long":"��˷��һ����ʷ�ƾõĹųǣ���ʫ��һ��˵�úã��ǹ����޶�����˼Ҷ�����ɽ�С�","tname":"migong36","ttg":"/d/yanping/road1","npc":"npc36","boss":"boss36","lv":"450",]),
(["name":"������",	"long":"�����޲�����Ϊ����İ��ӣ������޵��˽���ʱ�ڣ���������̺죬�����ι�״���ޡ�","tname":"migong37","ttg":"/d/xinan/shanlu09","npc":"npc37","boss":"boss37","lv":"460",]),
(["name":"��ʤ��",	"long":"��ʤ��λ�ں鶴�سǶ����Ļ�ɽ��´����Ȫ�෢Դ�ڴ˵أ������ŰزԴ䣬ɽ��ˮ�㡣","tname":"migong38","ttg":"/d/taiyuan/nroad1","npc":"npc38","boss":"boss38","lv":"470",]),
(["name":"��ĿϪ",	"long":"��ĿϪ�Ǹ������ϵ�һ��֧����ˮ���峺��ҡҷ��ˮ�ݣ���̬��һ�Ķ���ʯ�������ס�","tname":"migong39","ttg":"/d/hangzhou/hupaoquan","npc":"npc39","boss":"boss39","lv":"480",]),
(["name":"������",	"long":"������Ϊ���ʥ�أ�ӵ��������߷�������������Ĳ���ָ����������Ϊ�ٹ������ķ��ʥ�ء�","tname":"migong40","ttg":"/d/lanzhou/caroad8","npc":"npc40","boss":"boss40","lv":"490",]),
(["name":"��ľ��",	"long":"��ľ��(��Ů��)λ���Ĵ������ཻ��ش����Թ��������Ǵ����ʡ���������ڳ��ݺڻ�Ů���ʥ�ء�","tname":"migong41","ttg":"/d/xingxiu/xxroad1","npc":"npc41","boss":"boss41","lv":"500",]),
(["name":"������",	"long":"��������̫껹����׳�����������Ժ���������ף��Ľ���Ժ���������","tname":"migong42","ttg":"/d/lanzhouchen/road3","npc":"npc42","boss":"boss42","lv":"510",]),
(["name":"���ɽʯ��",	"long":"���ɽ�ߣ�������μ���������룬����һ��ʯ���߰���Ѱ����֮���ţ���ũ�һ���֮״�����д�����","tname":"migong43","ttg":"/d/lanzhou/caroad2","npc":"npc43","boss":"boss43","lv":"520",]),
(["name":"������",	"long":"������λ�ھ�������ɽ��´���Ŵ�����ī�ͽ�������佡�ά������ˣ�������������գ���Ϊ�¹������������","tname":"migong44","ttg":"/d/xinjiang/aiding","npc":"npc44","boss":"boss44","lv":"530",]),
(["name":"̫����",	"long":"̫����Ϊʯ�����ܶ�����5��4������϶����¶���ˮ����������ɡ�","tname":"migong45","ttg":"/d/huangshan/mroad2","npc":"npc45","boss":"boss45","lv":"540",]),
(["name":"������",	"long":"�����������Ϸ���һ��ʯ��ÿ���ǳ�ˮӿ���˻���ʯ�������޹ģ����ǳƹ���ʯ����������˶�������","tname":"migong46","ttg":"/d/fuzhou/yushan","npc":"npc46","boss":"boss46","lv":"550",]),
(["name":"����Դ",	"long":"����Դ���������أ�������Ȼ������Ȼ�����ӳ��Ȥ�ģ��Ǵ��ӵ���԰��⡣","tname":"migong47","ttg":"/d/changsha/road1","npc":"npc47","boss":"boss47","lv":"560",]),
(["name":"��´ɽ",	"long":"��´ɽ����������Ļ��ľ�������ʤ�ż��ڶ࣬�����͵�Ϊһ�壬��ʷʥ���鲼��ֲ����Դ�ḻ��","tname":"migong48","ttg":"/d/changsha/eroad3","npc":"npc48","boss":"boss48","lv":"570",]),
(["name":"��ϼɽ",	"long":"��ϼɽ����Ϊ���㡣��ʼ���ڱ��εĽ�ʯ��ʯ���¡��ξ��ء�ͨ�춴������Ͽ������͵ĳ�ڵ��¡�","tname":"migong49","ttg":"/d/fuzhou/fzroad4","npc":"npc49","boss":"boss49","lv":"580",]),
(["name":"ܽ�ؽ�",	"long":"ܽ�ؽ���ɫ������ɽ�ࡢˮ�㡢���ۡ����桢Ͽ�ġ����̲�ա��������ٷɡ�Ȫӿ���������ȣ�����ʤ�ա�","tname":"migong50","ttg":"/d/guizhou/dadao2","npc":"npc50","boss":"boss50","lv":"590",]),
(["name":"������",	"long":"������޵�ܴ�������ľ���㣬��ˮ��Ȫ����̨��к���γ�ǧ�ٿ��ػ����ۡ����Ƕ���Ĳʳء�","tname":"migong51","ttg":"/d/resort/smallroad","npc":"npc51","boss":"boss51","lv":"600",]),
(["name":"����ɽ",	"long":"����ɽ�������������Ĵ�߶ȼ���ɽ����Ƕ��Ѷ�ԶԶ������������塣","tname":"migong52","ttg":"/d/xinan/shanlu07","npc":"npc52","boss":"boss52","lv":"610",]),
(["name":"������",	"long":"�ഫ�����������ڵ�����ɽԭ��Ů����ﲹ��ʱ����ĳ�ʯ�� ","tname":"migong53","ttg":"/d/xuedao/sroad2","npc":"npc53","boss":"boss53","lv":"620",]),
(["name":"����ɽ",	"long":"����ɽ��һ��������������Ȼɽˮ�����θ��ӣ����͵��֣����ֿ�������Ѩ���","tname":"migong54","ttg":"/d/xinan/shanlu11","npc":"npc54","boss":"boss54","lv":"630",]),
(["name":"���ȶ���ɽ",	"long":"����ɽɽ���ֵ���ˮ��ӯ�����д�СϪ��100���������в�԰�Ӽ��Ƚ��Ӳ����޴����ʯ����������Զ�ŵĴ�����","tname":"migong55","ttg":"/d/guizhou/tulu2","npc":"npc55","boss":"boss55","lv":"640",]),
(["name":"������",	"long":"�������ش���ţɽ��´���������룬�����ܶ�ɽ����������������ʼ�����������������","tname":"migong56","ttg":"/d/guizhou/beimen","npc":"npc56","boss":"boss56","lv":"650",]),
(["name":"�Ƶ���",	"long":"�Ƶ��꣬���л�����ʼ��Ƶ۵���Ĺ���ഫ�Ƶ۵õ����죬�ʴ���ĹΪ�¹�ڣ��","tname":"migong57","ttg":"/d/city4/road5","npc":"npc57","boss":"boss57","lv":"660",]),
(["name":"���ɽ",	"long":"��ˮ�ж��Ϸ�50�������������ɽ���ϲ࣬��������ɽ��С¤ɽ�е�һ���·塣","tname":"migong58","ttg":"/d/tianshui/yidao5","npc":"npc58","boss":"boss58","lv":"670",]),
(["name":"��˹�ں�",	"long":"�ҹ�������½��ˮ���� ����ʱ�������ϣ�����׺�,�羲ʱ�������٣���ˮ���졣","tname":"migong59","ttg":"/d/xinjiang/chairong","npc":"npc59","boss":"boss59","lv":"680",]),
(["name":"�ڳ��ȵ�",	"long":"�ڳ��������ɽ�Ⱥ���ǧ��ŵ��߹أ���������̳�,��99����ɽ�ۚl��񷡢88����Ȫ���齦��","tname":"migong60","ttg":"/d/kunming/qingshilu","npc":"npc60","boss":"boss60","lv":"690",]),
(["name":"��ʯ��",	"long":"��̩ɽ�ı��棬�˴�Σ���ͱڣ���ʯͻ�������Բ��ɴ�أ��ľ�СϪ�������Ⱦ߱�Ȥ����","tname":"migong61","ttg":"/d/taishan/baozang","npc":"npc61","boss":"boss61","lv":"700",]),
(["name":"ң��ͤ",	"long":"�ɳƲݲ�ͤ��Ϊ���ǰͤ�����˼�̩ɽ�������˼򵥲ΰݣ�����������롣��Ժ�ھٰ���̩������ ��","tname":"migong62","ttg":"/d/taishan/yaocan","npc":"npc62","boss":"boss62","lv":"710",]),
(["name":"����Ժ",	"long":"����Ժλ����������Ŷ�����Ժ���йŰ������������","tname":"migong63","ttg":"/d/taishan/daimiao","npc":"npc63","boss":"boss63","lv":"720",]),
(["name":"������",	"long":"̩ɽ�շ���ϣ����ʱ�������ڴ�Ϊ��ĸ��Ͷ�����������������Ϊ�����¡���","tname":"migong64","ttg":"/d/taishan/aishen","npc":"npc64","boss":"boss64","lv":"730",]),
(["name":"��ɽ�ɹ�",	"long":"һ·ǧ�徺�㣬�������棬��ʯ��̶��Ϊ����ر���ɽ�����ܣ��������£����ν���������硣","tname":"migong65","ttg":"/d/huangshan/feicui","npc":"npc65","boss":"boss65","lv":"740",]),
(["name":"��ţ����Ϫ",	"long":"��ţ����Ϫλ���ţ��ɽ���£�Ⱥɽ�����������˼ң�����������ӣ�����������Դ�����԰��� ","tname":"migong66","ttg":"/d/huangshan/mingxuan","npc":"npc66","boss":"boss66","lv":"750",]),
(["name":"�ų���",	"long":"�ų��ң����������������򶫲࣬���ǵ͵͵�һ��ɽ�ͣ�ȴ���ڶ�Ĺż���ַ��","tname":"migong67","ttg":"/d/huangshan/chayuan","npc":"npc67","boss":"boss67","lv":"760",]),
(["name":"������",	"long":"����ʥ��ʥ���������ӹھ��С���������������徻�أ����ܵ��ҷ��ӹ���ظ���Ȼ�����롣","tname":"migong68","ttg":"/d/songshan/tianzhongge","npc":"npc68","boss":"boss68","lv":"770",]),
(["name":"����̨ ",	"long":"����̨��̨����ʯ�硢�����ɡ�̨����С�´����Ƹ�����̨��ʷ��Ρ�","tname":"migong69","ttg":"/d/songshan/chaotian","npc":"npc69","boss":"boss69","lv":"780",]),
(["name":"������Ժ",	"long":"������Ժ����ɽ�뻷������ң��Ϫˮ����������������Ϫˮ���������������峺��Ϫˮ����������Ժǰ���ϡ�","tname":"migong70","ttg":"/d/songshan/shuyuan","npc":"npc70","boss":"boss70","lv":"790",]),
(["name":"��ɽ����",	"long":"��ɽ���壬��λ�þӶ��������嶥��һƽ̨���Ӹ����գ���Ұ�������������Ĺ��ճ��ĵط����˳Ƴ���̨������Ҳ��֮����Ϊ�����塣","tname":"migong71","ttg":"/d/huashan/chaoyang","npc":"npc71","boss":"boss71","lv":"800",]),
(["name":"��ɽ�Ϸ�",	"long":"��ɽ���壬Ҳ����������߷壬����������ǻ�ɽԪ�ס������Ϸ�������ٸ������ߣ��Ƕ���ժ��","tname":"migong72","ttg":"/d/huashan/sheshen","npc":"npc72","boss":"boss72","lv":"810",]),
(["name":"��ɽ����",	"long":"��ɽ���壬��λ�þ���������������� �о�ʯ��״���������꣬�Ŵ����˶����Ϊ�����塢ܽ�ط塣","tname":"migong73","ttg":"/d/huashan/lianhua","npc":"npc73","boss":"boss73","lv":"820",]),
(["name":"��ɽ����",	"long":"��ɽ���壬��λ�þӱ����������������������Ϲھ��ƣ���ͨ������ΡȻ���㣬������̨�����������̨�塣","tname":"migong74","ttg":"/d/huashan/yuntai","npc":"npc74","boss":"boss74","lv":"830",]),
(["name":"��ɽ�з�",	"long":"��ɽ���塣�Ӷ����������������룬������ľ���ף��������ģ��滨��ݶ಻֪������ͷ�е�������Ů������˷��ֱ���Ϊ��Ů�塣","tname":"migong75","ttg":"/d/huashan/yunu","npc":"npc75","boss":"boss75","lv":"840",]),
(["name":"ףʥ��",	"long":"ףʥ�¾���������ܽ�������ٲ����˷��º�ΰ׳�ۣ��������롣","tname":"migong76","ttg":"/d/henshan/zhurongfeng","npc":"npc76","boss":"boss76","lv":"850",]),
(["name":"��̨��",	"long":"��̨��������Ӧ���µ����������棬�ų����·�Դ���ϳ��������䴴�������챦��������������ϣǨ���н�������Ϊ��̨�¡�","tname":"migong77","ttg":"/d/henshan/wangyuetai","npc":"npc77","boss":"boss77","lv":"860",]),
(["name":"�Ϸ���",	"long":"�Ϸ����ڸ�̨���Ϸ�����������ʮ�������������Ĺ�ɲ֮һ���峯��ǰ�й���ۣ���������Ϊ�ڶ�ʮ�����ء������Ǻ������Ϸ��¡�","tname":"migong78","ttg":"/d/henshan/wangritai","npc":"npc78","boss":"boss78","lv":"870",]),
(["name":"�����",	"long":"�������һ�����·ת�Ķ���·�ڣ�������������绢Х���ɴ˵�����","tname":"migong79","ttg":"/d/hengshan/hufengkou","npc":"npc79","boss":"boss79","lv":"880",]),
(["name":"Ϧ����",	"long":"�����շ�ֱ��������ÿ��Ϧ�����£���Է��������뻭��","tname":"migong80","ttg":"/d/hengshan/xuangengsong","npc":"npc80","boss":"boss80","lv":"890",]),
(["name":"������",	"long":"���������й�����ص㿪����Ժ֮һ��Ϊ�����ټ��������������Ժ��ʼ�������ʱ�ڣ��������1000������ʷ��","tname":"migong81","ttg":"/d/changsha/yanzixiang","npc":"npc81","boss":"boss81","lv":"900",]),
(["name":"������",	"long":"ԭΪ����ƽ����¡���һ�������ѣ��ݵط�־����Ϊ���ʱ�ڳ�������������Ĺ�أ����������ѡ�","tname":"migong82","ttg":"/d/changsha/eroad2","npc":"npc82","boss":"boss82","lv":"910",]),
(["name":"���ĸ�",	"long":"���ĸ��ڳ�ɳ�����ĵ������Ͻ��ϣ��ǳ�ɳ�ųǵ�һ����¥��Ϊ��ɳ��Ҫ��ʤ��Ҳ�ǳ�ɳ����ĹųǱ�־��","tname":"migong83","ttg":"/d/changsha/dongmen","npc":"npc83","boss":"boss83","lv":"920",]),
(["name":"������",	"long":"�Թ����С����µ�ʮ�˸��ء���������ʤ�ء������ơ����������������桢�����Ĵ�˵�����������⡣","tname":"migong84","ttg":"/d/henshan/hsroad8","npc":"npc84","boss":"boss84","lv":"930",]),
(["name":"�ƺ�¥",	"long":"�ഫҲʼ������������ʱ����ʼʢ������Ҫ��֮��ʫ�˴�������ѳ˻ƺ�ȥ���˵ؿ���ƺ�¥ʫ��","tname":"migong85","ttg":"/d/jiangling/huanghelou","npc":"npc85","boss":"boss85","lv":"940",]),
(["name":"����Ͽ",	"long":"����Ͽ��̲��ˮ�����ơ���������̲������̲������Ӿ�������Ͽ�ڡ�","tname":"migong86","ttg":"/d/jingzhou/sanxia1","npc":"npc86","boss":"boss86","lv":"950",]),
(["name":"��ũ��",	"long":"�Ϲ�ʱ������ũ����������鳢�ٲ�Ϊ������������¸߱ڶ�����ϡҩ�ݲ��ײɵ�����ũ�Ͼͷ�ľ��ܶ��ϣ���˺��˳�����Ϊ����ũ�ܡ���","tname":"migong87","ttg":"/d/jiangling/shennongjia","npc":"npc87","boss":"boss87","lv":"960",]),
(["name":"��Ͽ",	"long":"��Ͽ��������������ʱ�̣�Ͽ��ʪ��������ɢ�����׳�����������ǧ����̬��","tname":"migong88","ttg":"/d/jingzhou/sanxia2","npc":"npc88","boss":"boss88","lv":"970",]),
(["name":"���ĺ���",	"long":"����ɳ̲�ϴ�С�ٿ�ʯ�����������ġ��������ǡ��͡�����һ������ʯͻأ��䣬�������⣬���׳��","tname":"migong89","ttg":"/d/hainan/underhill2","npc":"npc89","boss":"boss89","lv":"980",]),
(["name":"��ָɽ",	"long":"��ָɽ����ΧȺɽ������ɭ��ï�ܣ��������ġ����ɽ�ǡ������Ժ��ϵ������ɽ����ָɽ���������","tname":"migong90","ttg":"/d/hainan/road4","npc":"npc90","boss":"boss90","lv":"990",]),
(["name":"��Ȫ��",	"long":"�غ��������͵��ȴ����־��ۺ��ɶ��칤�ĵ�ò������̾Ϊ��ֹ����Ȫ����̬�����������ȴ�����������Ϊ�й��ġ�����ѷ�ӡ���","tname":"migong91","ttg":"/d/hainan/pubu","npc":"npc91","boss":"boss91","lv":"1000",]),
(["name":"����",	"long":"��������Ī�嶼�����ض���D��������ˡ���D���ǲ�������ľ��񣬲���������Ӧ���ǡ���D������","tname":"migong92","ttg":"/d/hainan/underhill3","npc":"npc92","boss":"boss92","lv":"1010",]),
(["name":"ħ���",	"long":"ħ����ֳ��ڶ��̷�ǡ��������˳�Ϊ��ɳ��̹�˶���������Ϊħ���","tname":"migong93","ttg":"/d/xinjiang/emin","npc":"npc93","boss":"boss93","lv":"1020",]),
(["name":"����Ĺ",	"long":"����������Ļ��Ӻ����У���һ��������������Ů�ӣ���Ǭ¡�ʵ۵İ�����","tname":"migong94","ttg":"/d/xinjiang/tulu3","npc":"npc94","boss":"boss94","lv":"1030",]),
(["name":"���ӹʳ�",	"long":"���ӹʳ� ��������ս�𣬽��ӳ���˥�䡣","tname":"migong95","ttg":"/d/xinjiang/sichou3","npc":"npc95","boss":"boss95","lv":"1040",]),
(["name":"����˹��",	"long":"������˹���ɹ����Ϊ���������ġ�����Ī�⡱���ߡ�Ͽ���еĺ�����","tname":"migong96","ttg":"/d/xinjiang/goudi","npc":"npc96","boss":"boss96","lv":"1050",]),
(["name":"�Ÿ�ʳ�",	"long":"Ρ��ĹŸ�ʳ������ڰ�����������������������������������Ȫ���ϰ���Ϊ����ӵ�а���֮�ڵĽ���������ެ���Һ���������","tname":"migong97","ttg":"/d/xizang/deadneck","npc":"npc97","boss":"boss97","lv":"1060",]),
(["name":"������",	"long":"�������������ش��£���ʷ�ƾã��ڵ�������ʢ����ÿ�궼�а�����������  ���������ؼ������Ჴ������ͽǰ�����ݡ�","tname":"migong98","ttg":"/d/zangbei/mount2","npc":"npc98","boss":"boss98","lv":"1070",]),
(["name":"��ë��",	"long":"��ë����̨��ԫ��ë�������ڵ�ˮ��β���������򣬸߾ᵭˮ�ӳ����ڵ�ɽ�ۡ�","tname":"migong99","ttg":"/d/taiwan/hongmaocheng","npc":"npc99","boss":"boss99","lv":"1080",]),
(["name":"��ɽ��",	"long":"¹����ɽ�¹�ģ��ΰ������Ϊ�����������ʮ�ַ�����ɽ��Ϊ�������Ⱦſ�������ʽ������","tname":"migong100","ttg":"/d/taiwan/lugang","npc":"npc100","boss":"boss100","lv":"1090",]),
});


// shutdown.c



int main(object me, string arg)
{
	string wiz_status,mname;
	object *user, link_ob;
	int i,tp,lv,lb,j,k,nn,mpn,mexp,mlv,mjl;
	string this_file;
	string my_file;
	string name;
	string err,file;
	object env;
	        
        string *dir2,envn;
	if( me != this_player(1) ) return 0;
	
	wiz_status = SECURITY_D->get_status(me);
	if( wiz_status != "(admin)" && wiz_status != "(arch)" )
		return notify_fail("ֻ�� (arch) ���ϵ���ʦ����ʹ��!\n");


lb=0;
tp=8;

lv=1;

//����NPC
j=sizeof(dddata);	
j=1;	
		mpn=0;
		nn=0;
		mjl=0;
				for(i = 0; i<sizeof(dddata); i++) {
					my_file = read_file("/p/migong/migong/npc.o");
write("tname"+dddata[i]["npc"]+"\n");
if (dddata[i]["tname"])
	{
		

if (nn>0) nn=nn+1;
mlv=100+(10*i)-1;
mexp=mlv*mlv*mlv;
mjl=i*3+1;
my_file= replace_string(my_file,"RPNAME",nn+"+random(2)");
my_file= replace_string(my_file,"RPEXP",""+mexp);
my_file= replace_string(my_file,"RPJL",""+mjl);
my_file= replace_string(my_file,"RPLV",""+(100+(9*i)));
my_file= replace_string(my_file,"RPMP",mpn+"+random(2)");

mpn=mpn+1;
nn=nn+1;
if (mpn>62) mpn=0;
//write("ttg"+dddata[i]["ttg"]+"\n");
//write("npc"+dddata[i]["npc"]+"\n");
//write("boss"+dddata[i]["boss"]+"\n");
//write("lv"+dddata[i]["lv"]+"\n");



write_file("/p/migong/migong/npc/"+dddata[i]["npc"]+".c",my_file,1);
}
					}


//����BOSS
j=sizeof(dddata);	
j=1;	
		mpn=0;
		nn=0;
		mjl=0;
				for(i = 0; i<sizeof(dddata); i++) {
					my_file = read_file("/p/migong/migong/boss.o");
write("tname"+dddata[i]["boss"]+"\n");
if (dddata[i]["tname"])
	{
		

if (nn>0) nn=nn+1;
mlv=100+(10*i)-1;
mexp=mlv*mlv*mlv;
mjl=i*2+1;
my_file= replace_string(my_file,"RPNAME",""+i);
my_file= replace_string(my_file,"RPEXP",""+mexp);
my_file= replace_string(my_file,"RPJL",""+mjl);
my_file= replace_string(my_file,"RPLV",""+(100+(9*i)));
my_file= replace_string(my_file,"RPMP",mpn+"+random(2)");

mpn=mpn+1;
nn=nn+1;
if (mpn>62) mpn=0;
//write("ttg"+dddata[i]["ttg"]+"\n");
//write("npc"+dddata[i]["npc"]+"\n");
//write("boss"+dddata[i]["boss"]+"\n");
//write("lv"+dddata[i]["lv"]+"\n");

write_file("/p/migong/migong/npc/"+dddata[i]["boss"]+".c",my_file,1);
}
					}

//return 1;
//�����Թ�
j=sizeof(dddata);	
j=1;	
				for(i = 0; i<sizeof(dddata); i++) {
					my_file = read_file("/p/migong/migong/migong.o");
//write("name"+dddata[i]["name"]+"\n");
//write("long"+dddata[i]["long"]+"\n");
//write("tname"+dddata[i]["tname"]+"\n");
if (dddata[i]["tname"])
	{
my_file= replace_string(my_file,"RPNAME",dddata[i]["name"]);
my_file= replace_string(my_file,"RPLONG",dddata[i]["long"]);
my_file= replace_string(my_file,"RPTNAME",dddata[i]["tname"]);
my_file= replace_string(my_file,"RPTTG",dddata[i]["ttg"]);
my_file= replace_string(my_file,"RPNPC",dddata[i]["npc"]);
my_file= replace_string(my_file,"RPBOSS",dddata[i]["boss"]);
my_file= replace_string(my_file,"RPLV",dddata[i]["lv"]);
//write("ttg"+dddata[i]["ttg"]+"\n");
//write("npc"+dddata[i]["npc"]+"\n");
//write("boss"+dddata[i]["boss"]+"\n");
//write("lv"+dddata[i]["lv"]+"\n");

env = load_object(dddata[i]["ttg"]);
dir2=explode(base_name(env),"/");
envn=zuji(dir2[1])+"-"+env->query("short");

write("'"+dddata[i]["ttg"]+"': '"+dddata[i]["tname"]+"',\n");
//write("����:"+dddata[i]["name"]+" �ȼ�:"+dddata[i]["lv"]+" λ��:"+envn+"\n");
write_file("/p/migong/migong/"+dddata[i]["tname"]+".c",my_file,1);
}
					}

					


					
	return 1;
}


string  zuji(string str)
{   
string output;
      	if (str=="baituo")  

	output="����ɽ";

if (str=="binghuodao")  

	output="����";

if (str=="city")  

	output="����";

if (str=="city2" || str=="beijing"  || str=="huanggon"  || str=="huanggong" || str=="beihai")  

	output="������";

if (str=="city4" || str=="changan")   

	output="������";

if (str=="dali")  

	output="����";

if (str=="emei")  

	output="��üɽ";

if (str=="foshan")  

	output="��ɽ";

if (str=="gaibang")  

	output="ؤ��";

if (str=="gaochang")  

	output="�߲��Թ�";

if (str=="guanwai")  

	output="����";

if (str=="guiyun")  

	output="����ׯ";

if (str=="gumu")  

	output="��Ĺ��";

if (str=="hangzhou")  

	output="����";

if (str=="heimuya")  

	output="��ľ��";

if (str=="hengshan")  

	output="��ɽ";

if (str=="henshan")  

	output="��ɽ";

if (str=="huanghe")  

	output="�ƺӾ���";

if (str=="huashan")  

	output="��ɽ";

if (str=="jinshe")  

	output="����ɽ��";

if (str=="lingjiu")  

	output="���չ�";

if (str=="lingzhou")  

	output="����";

if (str=="meizhuang")  

	output="÷ׯ";

if (str=="mingjiao")  

	output="����";

if (str=="qingcheng")  

	output="���ɽ";

if (str=="quanzhen")  

	output="ȫ����";

if (str=="quanzhou")  

	output="Ȫ��";

if (str=="shaolin")  

	output="������";

if (str=="shenlong")  

	output="������";

if (str=="songshan")  

	output="��ɽ";

if (str=="suzhou")  

	output="����";

if (str=="taishan")  

	output="̩ɽ";

if (str=="taohua")  

	output="�һ���";

if (str=="tianlongsi")  

	output="������";

if (str=="wanjiegu")  

	output="��ٹ�";

if (str=="wudang")  

	output="�䵱ɽ";

if (str=="xiakedao")  

	output="���͵�";

if (str=="xiangyang")  

	output="������";

if (str=="xiaoyao")  

	output="��ң��";

if (str=="xingxiu")  

	output="���޺�";

if (str=="xueshan")  

	output="ѩɽ��";

if (str=="xuedao")  

	output="��ѩɽ";

if (str=="mr")  

	output="Ľ������";

if (str=="kunlun")  

	output="����ɽ";

if (str=="tiezhang")  

	output="������";

if (str=="huizhu")  

	output="���岿��";

if (str=="yinju")  

	output="һ�ƴ�ʦ��";

if (str=="menggu")  

	output="�ɹŲ�ԭ";

if (str=="qianjin")  

	output="����ǧ��¥";

if (str=="lingshedao")  

	output="���ߵ�";

if (str=="ruzhou")  

	output="���ݳ�";

if (str=="kunming")  

	output="����";

if (str=="jingzhou")  

	output="����";

if (str=="yanjing")  

	output="ʢ��";

if (str=="lanzhou" || str=="lanzhouchen")  

	output="����";

if (str=="jyguan")  

	output="������";

if (str=="changcheng")  

	output="����";

if (str=="fairyland")  

	output="��÷ɽׯ";

if (str=="sdxl")  

	output="��ħ�������Ĺ";

if (str=="jqg")  

	output="�����";

if (str=="nio")  

	output="ţ�Ҵ�";

if (str=="feihu")  

	output="��������";

if (str=="wuguan")  

	output="�������";

if (str=="village")  

	output="��ɽ��";

if (str=="taohuacun")  

	output="�һ���";

if (str=="pingan")  

	output="ƽ����";

if (str=="lingxiao")  

	output="������";

if (str=="wudujiao")  

	output="�嶾��";

if (str=="hj")  

	output="��ɽ��ԭ";
if (str=="dali/yuxu")  

	output="���������";
if (str=="dali/wuliang")  

	output="��������ɽ";
if (str=="huanghe/yyd")  

	output="�ƺ�����";
if (str=="kaifeng")  

	output="�����";
if (str=="feitian")  

	output="����������";
if (str=="japan")  

	output="�ձ���";
if (str=="tangmen")  

	output="����";
if (str=="luoyang")  

	output="������";

if (str=="chengdu" || str=="city3")  

	output="�ɶ�";

if (str=="baihuagu")  

	output="�ٻ���";

if (str=="heizhao")  

	output="�ٻ��Ⱥ���";

if (str=="jiaxing")  

	output="����";

if (str=="shiliang")  

	output="�¼�ׯ";

if (str=="wuyi")  

	output="����ɽ��";

if (str=="yanping")  

	output="��ƽ��";
	

if (str=="jiangling")  
{
	output="�����";
}

if (str=="yueyang")  
{
	output="������";	
}

if (str=="qilian")  
{
	output="����ɽ";	
}

if (str=="shouxihu")  
{
	output="������";	
}

if (str=="wuxi")  
{
	output="������";	
}

if (str=="yixing")  
{
	output="���˳�";	
}
if (str=="taiwan")  
{
	output="̨��";	
}
if (str=="nanyang")  
{
	output="����";	
}
if (str=="nanshaolin")  
{
	output="������";	
}

if (str=="cangzhou")  
{
	output="����";	
}

if (str=="tanggu")  
{
	output="������";	
}

if (str=="yunhe")  
{
	output="�����˺�";	
}

if (str=="hainan")  
{
	output="���ϵ�";	
}

if (str=="jindezheng")  
{
	output="������";	
}

if (str=="yandang")  
{
	output="�㵴ɽ";	
}

if (str=="jinling")  
{
	output="�����";	
}

if (str=="sandboy")  
{
	output="����ũ��";	
}

if (str=="huangshan")  
{
	output="��ɽ";	
}

if (str=="yubifeng")  
{
	output="��ʷ�";	
}

if (str=="quanzhouchen")  
{
	output="Ȫ�ݳ���";	
}

if (str=="qingzh")  
{
	output="��ظ�ԭ";	
}

if (str=="changbaishan" || str=="gaoli")  
{
	output="��������ɽ";	
}

if (str=="annan")  
{
	output="����";	
}

if (str=="taiyuan")  
{
	output="̫ԭ";	
}

if (str=="hefei")  
{
	output="�Ϸ�";	
}

if (str=="jiujiang")  
{
	output="�Ž�";	
}

if (str=="baling")  
{
	output="����";	
}

if (str=="xinjiang")  
{
	output="�½�";	
}
if (str=="dingxiang")  
{
	output="����";	
}
if (str=="suiye")  
{
	output="��Ҷ";	
}


if (str=="mayi")  
{
	output="���ر߽�";	
}
if (str=="xuzhou")  
{
	output="���ݳ�";	
}
if (str=="jinan")  
{
	output="���ϳ�";	
}
if (str=="guizhou")  
{
	output="������";	
}

if (str=="nanchang")  
{
	output="�ϲ���";	
}


if (str=="changsha")  
{
	output="��ɳ��";	
}


if (str=="zhongzhou")  
{
	output="���ݳ�";	
}

if (str=="xizang" || str=="zangbei")  
{
	output="���ػ�ر�";	
}

if (str=="tianshui")  
{
	output="��ˮ��";	
}

if (str=="datong")  
{
	output="��ͬ��";	
}
if (str=="ny")  
{
	output="��Զ��";	
}
if (str=="fengtian")  
{
	output="ʢ����";	
}

if (str=="yanmen")  
{
	output="���Ź�";	
}
if (str=="cloud")  
{
	output="�����";	
}
if (str=="xueting")  
{
	output="ѩͤ��";	
}
if (str=="fuzhou")  
{
	output="����";	
}
if (str=="welcome")  
{
	output="�Ŵ�";	
}
if (!output)  
{
	output="δ֪����";	
}

if (output=="")  
{
	output="δ֪����";	
}


return output;
}

int help (object me)
{
        write(@HELP
ָ���ʽ: shutdown
 
�����Թ��ļ�100��
 
HELP
);
        return 1;
}
 
