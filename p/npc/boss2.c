#include <ansi.h>
int do_walk();
inherit NPC;
#include "/quest/menpai/romnpc.c"
#include "/quest/menpai/givegift.c"
string  ask_job();
string *first_name = ({ "赵","钱","孙","李","周","吴","郑","王","张","陈","柳","风","刘","林", }); 
string *name_words = ({ "一","二","三","四","五","六","七","八","九","十", });
string *color_title = ({"[天杀门]杀手","[地煞门]杀手",});
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});
mapping *data=({
(["name":"官兵",	"id":"guan bing",	"mw":-1,"weapon":"gangdao",]),
(["name":"渔夫",	"id":"yu fu",	"mw":-1,]),
(["name":"男孩",	"id":"boy",	"mw":-1,]),
(["name":"女孩",	"id":"girl",	"mw":1,]),
(["name":"店小二",	"id":"xiao er",	"mw":-1,]),
(["name":"员外",	"id":"yuanwai",	"mw":-1,]),
(["name":"歌妓",	"id":"ge ji",	"mw":1,]),					
(["name":"管家",	"id":"guan jia",	"mw":-1,]),
(["name":"龟公",	"id":"gui gong",	"mw":-1,]),
(["name":"红娘",	"id":"hong niang",	"mw":1,]),
(["name":"小混混",	"id":"xiao hunhun",	"mw":-1,]),
(["name":"火工僧",	"id":"huogong seng",	"mw":-1,]),
(["name":"伙计",	"id":"huoji",	"mw":-1,]),
(["name":"看门僧",	"id":"kanmen seng",	"mw":-1,]),
(["name":"扬州女孩",	"id":"girl",	"mw":1,]),
(["name":"踏青少女",	"id":"girl",	"mw":1,]),
(["name":"江南女孩",	"id":"girl",	"mw":1,]),
(["name":"小丫头",	"id":"littlegirl",	"mw":1,]),											
(["name":"麻童",	"id":"ma tong",	"mw":-1,]),
(["name":"白髯老头",	"id":"lao tou",	"mw":-1,]),		
(["name":"老婆婆",	"id":"lao popo",	"mw":1,]),		
(["name":"签客",	"id":"qian ke",	"mw":-1,]),		
(["name":"卖糖小贩",	"id":"tang fan",	"mw":-1,]),				
(["name":"衙差",	"id":"ya chai",	"mw":-1,]),		
(["name":"山贼",	"id":"shan zei",	"mw":-1,]),		
(["name":"厨师",	"id":"chu shi",	"mw":-1,]),		
(["name":"贵夫人",	"id":"fu ren",	"mw":1,]),		
(["name":"女贵家",	"id":"guan jia",	"mw":1,]),				
(["name":"喇嘛",	"id":"lama",	"mw":-1,]),		
(["name":"大喇嘛",	"id":"lama",	"mw":-1,]),		
(["name":"仆役",	"id":"pu yi",	"mw":-1,]),		
(["name":"御前侍卫",	"id":"shi wei",	"mw":-1,	"weapon":"gangdao",]),		
(["name":"骁骑营侍卫",	"id":"shi wei",	"mw":-1,	"weapon":"gangdao",]),				
(["name":"铁匠",	"id":"tiejiang",	"mw":-1,]),		
(["name":"乞丐",	"id":"qi gai",	"mw":-1,]),			
(["name":"女乞丐",	"id":"nvqi gai",	"mw":1,]),			
(["name":"道士",	"id":"dao shi",	"mw":-1,]),			
(["name":"女道士",	"id":"nv daoshi",	"mw":1,]),
(["name":"戏子",	"id":"xi zi",	"mw":1,]),		
(["name":"丫环",	"id":"ya huan",	"mw":1,]),	
(["name":"园丁",	"id":"yuan ding",	"mw":-1,]),	
(["name":"掌柜",	"id":"zhanggui",	"mw":-1,]),	
(["name":"采茶女",	"id":"cha girl",	"mw":-1,]),	
(["name":"老禅师",	"id":"old chanshi",	"mw":-1,]),	
(["name":"刀客",	"id":"dao ke",	"mw":-1,]),	
(["name":"进香客",	"id":"jinxiang ke",	"mw":-1,]),	
(["name":"红花会众",	"id":"hong hua",	"mw":-1,]),	
(["name":"剑客",	"id":"jian ke",	"mw":-1,]),	
(["name":"马夫",	"id":"ma fu",	"mw":-1,]),	
(["name":"媒婆",	"id":"mei po",	"mw":-1,]),		
(["name":"蒙面人",	"id":"mengmianren",	"mw":-1,]),			
(["name":"穷汉",	"id":"poor man",	"mw":-1,]),				
(["name":"书生",	"id":"shu sheng",	"mw":-1,]),				
(["name":"老和尚",	"id":"lao heshang",	"mw":-1,]),				
(["name":"小沙弥",	"id":"xiao shami",	"mw":-1,]),				
(["name":"挑夫",	"id":"tiao fu",	"mw":-1,]),							
(["name":"游客",	"id":"youke",	"mw":-1,]),				
(["name":"公子哥",	"id":"gongzi",	"mw":-1,]),				
(["name":"婢女",	"id":"bi nu",	"mw":1,]),				
(["name":"尼姑",	"id":"ni gu",	"mw":1,]),							
(["name":"小贩",	"id":"xiao fan",	"mw":-1,]),			
(["name":"妓女",	"id":"ji nv",	"mw":1,]),	
(["name":"老父子",	"id":"fu zi",	"mw":1,]),	
(["name":"捕头",	"id":"bu tou",	"mw":-1,	]),
(["name":"快捕",	"id":"kuai bu",	"mw":-1,	]),
(["name":"铁捕",	"id":"tie bu",	"mw":-1,	]),
(["name":"衙役",	"id":"ya yi",	"mw":-1,	]),
(["name":"公公",	"id":"gong gong",	"mw":-1,	]),
(["name":"跑堂",	"id":"pao tang",	"mw":-1,	]),
(["name":"脚夫",	"id":"jiao fu",	"mw":-1,	]),
(["name":"裁缝",	"id":"cai feng",	"mw":-1,	]),
(["name":"药师",	"id":"yao shi",	"mw":-1,	]),
(["name":"官差",	"id":"guan cha",	"mw":-1,	]),
(["name":"武将",	"id":"wu jiang",	"mw":-1,	]),
(["name":"山贼头",	"id":"shan zeitou",	"mw":-1,	]),
(["name":"客店伙计",	"id":"huo ji",	"mw":-1,	"weapon":"gangdao",	]),
(["name":"仕卫",	"id":"shi wei",	"mw":-1,	"weapon":"changqiang",	]),
(["name":"铁匠",	"id":"tie jiang",	"mw":-1,	"weapon":"gangdao",	]),
(["name":"流氓头",	"id":"liumang tou",	"mw":-1,	"weapon":"gangjian",	]),
(["name":"贵公子",	"id":"gui gongzi",		"mw":-1,	"weapon":"gangjian",	]),
(["name":"行者",	"id":"xing ze",	"mw":-1,	"weapon":"gangdao",]),
(["name":"土匪头",	"id":"tufei tou",	"mw":-1,	"weapon":"changbian",	]),
(["name":"戏子",		"id":"xi zi",	"mw":-1,	"weapon":"lianzi",]),
(["name":"台夷商贩",	"id":"shang fan",		"mw":-1,	"weapon":"hammer",	]),
(["name":"江湖艺人",	"id":"yi ren",	"mw":-1,	"weapon":"gangjian",]),
(["name":"砍竹人",	"id":"kanzu ren",	"mw":-1,	"weapon":"changbian",	]),
(["name":"猎人",		"id":"lie ren",	"mw":-1,	"weapon":"lianzi",]),
(["name":"台夷猎人",	"id":"old lieren",		"mw":-1,	"weapon":"hammer",	]),
(["name":"牧羊人",	"id":"muyang ren",	"mw":-1,	"weapon":"gangjian",]),
(["name":"农夫",	"id":"nong fu",	"mw":-1,	"weapon":"gangjian",]),
(["name":"皮货商",	"id":"pihuo sang",	"mw":-1,	"weapon":"changbian",	]),
(["name":"石匠",		"id":"shi jiang",	"mw":-1,	"weapon":"lianzi",]),
(["name":"道人",	"id":"dao ren",		"mw":-1,	"weapon":"hammer",	]),
(["name":"游客",	"id":"you ke",	"mw":-1,	"weapon":"gangjian",]),
(["name":"书童",	"id":"shu tong",	"mw":1,	"weapon":"gangjian",]),
(["name":"绿营会众",	"id":"guan bing",	"mw":-1,	"weapon":"changbian",	]),
(["name":"员外",		"id":"yuan wai",	"mw":-1,	"weapon":"lianzi",]),
(["name":"比丘",	"id":"bi qiu",		"mw":-1,	"weapon":"hammer",	]),
(["name":"流氓",	"id":"liu mang",	"mw":-1,	"weapon":"gangjian",]),
});



string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});
mapping *data=({
(["id":"zuizui","title":"丐帮九袋长老","name":"缀缀 ",]),
(["id":"zhword","title":"三大门派掌门","name":"新星 ",]),
(["id":"danyingzi","title":"大理BUG","name":"丹辰子 ",]),
(["id":"fox","title":"老银狐","name":"狐狸 ",]),
(["id":"cash","title":"海洋最初第一","name":"银票 ",]),
(["id":"fen","title":"海洋黑暗左使","name":"凌云 ",]),
(["id":"lting","title":"翠蕊梨花阁梨花仙子","name":"風動梨花","sex":1,]),
(["id":"shazi","title":"风哥是我老大","name":"轻狂 ",]),
(["id":"hotwing","title":"大理镇南王府武将","name":"灼热天使 ",]),
(["id":"lavender","title":"都是真的","name":"薰衣草","sex":1,]),
(["id":"bakangel","title":"唐门第七代弟子","name":"黑天使","sex":1,]),
(["id":"rains","title":"华山派第十三代弟子","name":"小小勇士 ",]),
(["id":"guipu","title":"我是流氓我怕谁！！！","name":"鬼仆 ",]),
(["id":"flyt","title":"别欺负我老公啊","name":"安妮","sex":1,]),
(["id":"qing","title":"终南第一女侠","name":"秋意浓","sex":1,]),
(["id":"sos","title":"海洋总统","name":"飞飞飞飞机 ",]),
(["id":"dings","title":"只发呆不做事","name":"鸭蛋 ",]),
(["id":"damenly","title":"我就是最近杀飞机的一毛不拔","name":"缺德居士 ",]),
(["id":"Qlbl","title":"五毒教长老","name":"纨绔公子 ",]),
(["id":"xbd","title":"海洋第一","name":"小不懂 ",]),
(["id":"game","title":"莫思身外无穷事且尽生前有限杯","name":"游戏 ",]),
(["id":"amei","title":"五毒教长老","name":"千山暮雪","sex":1,]),
(["id":"zbabla","title":"我爱虫宝宝","name":"逍遥快乐 ",]),
(["id":"lunar","title":"桃花岛第二代弟子","name":"雪梅","sex":1,]),
(["id":"yoyo","title":"桃花岛第二代弟子","name":"悠游 ",]),
(["id":"snowfly","title":"我要我们在一起","name":"雪花飘","sex":1,]),
(["id":"wto","title":"铁掌帮第十五代弟子","name":"大伯流体欧 ",]),
(["id":"hadis","title":"铁掌帮第十五代弟子","name":"哈迪斯 ",]),
(["id":"angel","title":"【飞天御剑流】第三十七代掌门人","name":"绯村刀心 ",]),
(["id":"zohu","title":"听说雷骆被雷打中了","name":"雷骆 ",]),
(["id":"dfei","title":"逍遥派护法使者","name":"大飞 ",]),
(["id":"bakangel","title":"唐门第七代弟子","name":"黑天使","sex":1,]),
(["id":"woodtian","title":"我的帅惊动了十六大和党中央","name":"我爱你美女 ",]),
(["id":"kjhojin","title":"唐门第七代弟子","name":"水灵儿","sex":1,]),
(["id":"thill","title":"念密宗不动明王真言","name":"西门子 ",]),
(["id":"dido","title":"幻影旅团ヒソカ","name":"横喇嘛 ",]),
(["id":"cold","title":"宝箱里发出一阵金光","name":"无情 ",]),
(["id":"scan","title":"海洋头号丹神","name":"精英六号 ",]),
(["id":"lubinh","title":"一百年前，没有你，也没有我","name":"小白兔 ",]),
(["id":"lightning","title":"少林派第三十五代弟子","name":"渡闪 ",]),
(["id":"xiaomei","title":"武当派第二代弟子","name":"小美","sex":1,]),
(["id":"dldi","title":"大理镇南王府武将","name":"大理义工 ",]),
(["id":"mafan","title":"逍遥派护法使者","name":"麻烦 ",]),
(["id":"hailoo","title":"全真教第二代弟子","name":"蝶舞翩翩","sex":1,]),
(["id":"bingxueer","title":"将无聊进行到底","name":"冰雪儿","sex":1,]),
(["id":"caree","title":"云龙门第三代弟子","name":"心语妹妹","sex":1,]),
(["id":"damenl","title":"这年头","name":"想钱想发疯 ",]),
(["id":"xiaotian","title":"通缉犯许郝被啸天就地正法了","name":"啸天 ",]),
(["id":"waaas","title":"海洋新一代丹神","name":"蓉儿","sex":1,]),
(["id":"dbabla","title":"五毒老妖","name":"地邪 ",]),
(["id":"lyf","title":"天堂有路你不走呀","name":"龙吟凤","sex":1,]),
(["id":"loveyqh","title":"华山派第十四代弟子","name":"水手 ",]),
(["id":"lovefox","title":"轻紫阁","name":"怜星","sex":1,]),
(["id":"linda","title":"穿好，觉得自己还挺美的...","name":"白晶晶","sex":1,]),
(["id":"lindy","title":"天之羽","name":"慕容资","sex":1,]),
(["id":"lexy","title":"华山派第十四代弟子","name":"乐逍遥 ",]),
(["id":"laiyinhate","title":"幻影旅团团长","name":"莱因哈特 ",]),
(["id":"yzx","title":"那一剑的风情","name":"星月浪子 ",]),
(["id":"xnh","title":"雪山寺掌门大弟子","name":"阿虎 ",]),
(["id":"xjhjin","title":"逍遥派弟子","name":"茜茜","sex":1,]),
(["id":"xiaoxuan","title":"你的「sk」进步了！","name":"花泽泪 ",]),
(["id":"xdb","title":"华山弟子","name":"雪代巴 ",]),
(["id":"wumi","title":"漂亮的回旋踢","name":"呜咪 ",]),
(["id":"wukong","title":"姑苏慕容","name":"齐天大圣 ",]),
(["id":"wishluck","title":"中华圣朝外交部长","name":"小赵敏","sex":1,]),
(["id":"winco","title":"花开花落两不知箫声袅袅绕桃花","name":"云峰 ",]),
(["id":"wanxia","title":"清风明月本无价近水远山皆有情","name":"晚霞","sex":1,]),
(["id":"wanghu","title":"今有佳人公孙氏一舞剑器动四方","name":"公孙大狼 ",]),
(["id":"waaa","title":"问世间情为何物","name":"忘命 ",]),
(["id":"myth","title":"姑苏慕容第二代弟子","name":"慕容布 ",]),
(["id":"vov","title":"玫瑰天使^_^","name":"棒棒 ",]),
(["id":"tyywl","title":"白驼山派第二代弟子","name":"天野源五郎 ",]),
(["id":"ttss","title":"正牌无敌唐伯虎","name":"冷清秋","sex":1,]),
(["id":"tianjun","title":"不上高山不临深溪！","name":"流云 ",]),
(["id":"tcl","title":"雪山派俗家弟子","name":"王牌 ",]),
(["id":"taotao","title":"白驼山派第二代弟子","name":"OhMyGod ",]),
(["id":"sug","title":"青裙缟袂谁家女","name":"冷袖风","sex":1,]),
(["id":"sprite","title":"古墓派第四代弟子","name":"小精灵 ",]),
(["id":"sony","title":"武当派第二代弟子","name":"缘来 ",]),
(["id":"snq","title":"凌霄城城主","name":"小小 ",]),
(["id":"snow","title":"乞讨为生","name":"天下有雪","sex":1,]),
(["id":"smj","title":"要 exp","name":"阎罗猪 ",]),
(["id":"smile","title":"饿了我","name":"繁星 ",]),
(["id":"sjmoxj","title":"活佛","name":"吟游诗人 ",]),
(["id":"siren","title":"正大光明","name":"贵鬼 ",]),
(["id":"shuanger","title":"飞天小龙女","name":"独孤霜","sex":1,]),
(["id":"shanc","title":"灵鹫宫第二代弟子","name":"衫菜","sex":1,]),
(["id":"sgy","title":"法王","name":"小铁 ",]),
(["id":"scare","title":"我爱 陈超","name":"笑二郎 ",]),
(["id":"rui","title":"Amy的军团 －将军","name":"白雪飘零","sex":1,]),
(["id":"quanjia","title":"橘子香水","name":"泉笳","sex":1,]),
(["id":"qkry","title":"日月神教任教主亲传弟子","name":"乾坤日月 ",]),
(["id":"qiuqiu","title":"丐帮第十九代弟子","name":"球球 ",]),
(["id":"qazqaz","title":"将堕落进行到底","name":"王怜花 ",]),
(["id":"pxf","title":"~_______~","name":"木风 ",]),
(["id":"pcgame","title":"逍遥派护法使者","name":"风针 ",]),
(["id":"papaya","title":"海洋菜园帮帮主 ","name":"阿瓜 ",]),
(["id":"orange","title":"判师了","name":"桔子","sex":1,]),
(["id":"ooo","title":"现任HY流氓老大","name":"倾城之恋 ",]),
(["id":"only","title":"虫儿乖乖","name":"情瘤感菌 ",]),
(["id":"nvnv","title":"新一代路盲","name":"冬冬 ",]),
(["id":"npc","title":"全真教第二代弟子","name":"小美人","sex":1,]),
(["id":"name","title":"极品丑男","name":"直升机 ",]),
(["id":"mzlm","title":"嘛弥嘛弥哄","name":"啦啦 ",]),
(["id":"marine","title":"幻影旅团☆シズク","name":"刁钻古怪 ",]),
(["id":"means","title":"铁掌帮上官帮主弟子","name":"意思 ",]),
(["id":"miean","title":"无奈的我没有为海洋重开出钱","name":"灭黯 ",]),
(["id":"mingyang","title":"桃花快剑","name":"名扬 ",]),
(["id":"mini","title":"大理段家第十七代弟子","name":"本妮 ",]),
(["id":"mmm","title":"机器人中请不要和me说话","name":"九剑一痴 ",]),
(["id":"mrf","title":"姑苏慕容第三代弟子","name":"慕容峰 ",]),
(["id":"mryh","title":"活佛","name":"移花 ",]),
(["id":"myboy","title":"★烧★☆菜★Ω收钱","name":"晴天的雨 ",]),
(["id":"mygirl","title":"小月姑娘","name":"邵四","sex":1,]),
(["id":"lang","title":"对酒当歌，人生几何","name":"浪翻云 ",]),
(["id":"langer","title":"大理镇南王府皇卿","name":"本浪 ",]),
(["id":"legs","title":"选你所爱 爱你所选","name":"碧玉纤足","sex":1,]),
(["id":"lbxx","title":"雪山派俗家弟子","name":"蜡笔小新 ",]),
(["id":"lengxin","title":"五行引导师","name":"冷心 ",]),
(["id":"ling","title":"全真教第二代弟子","name":"灵儿","sex":1,]),
(["id":"ljgbook","title":" 你伤心问道：「这是为什么啊？」","name":"灵鹫","sex":1,]),
(["id":"lkdd","title":"你生得呲牙咧嘴黑如锅底奇丑无比","name":"百变星君 ",]),
(["id":"kara","title":"与往事干杯","name":"卡拉","sex":1,]),
(["id":"keeny","title":"慢慢来，不要急！练了也白练！","name":"秋政 ",]),
(["id":"keyboard","title":"★机器人★★中★","name":"本键 ",]),
(["id":"kgb","title":"永远的(通缉犯)","name":"江湖小二 ",]),
(["id":"killman","title":"采花小贼","name":"难免的钱袋 ",]),
(["id":"jad","title":"海洋麻雀楼之大当家","name":"江东 ",]),
(["id":"jianxin","title":"心太的道馆","name":"心太 ",]),
(["id":"jxy","title":"华山派第十三代弟子","name":"肖岳 ",]),
(["id":"icefox","title":"好久没上了","name":"冰狐 ",]),
(["id":"hadis","title":"铁掌帮第十五代弟子","name":"哈迪斯 ",]),
(["id":"hechuan","title":"丐帮九袋长老","name":"华英雄 ",]),
(["id":"hehaia","title":"明教使者","name":"任横行 ",]),
(["id":"himura","title":"大理段家第十七代弟子","name":"脉剑 ",]),
(["id":"honda","title":"欢迎光临www.fivekids.com","name":"本田 ",]),
(["id":"huakai","title":"凌霄城第七代弟子","name":"花落花开 ",]),
(["id":"hylijun","title":"华山派第十三代弟子","name":"机器猫 ",]),
(["id":"hxt","title":"圣火加油站","name":"草纸一疤 ",]),
(["id":"huihui","title":"少林派第三十六代弟","name":"玄慕 ",]),
(["id":"gameking","title":"无忧仙境　第二代弟子","name":"游戏之王 ",]),
(["id":"gaoc","title":"高昌迷宫主人","name":"高昌 ",]),
(["id":"gmxy","title":"法王","name":"消魂 ",]),
(["id":"grape","title":"钦赐一等鹿鼎公","name":"绿豆汤 ",]),
(["id":"green","title":"多情自古空余恨","name":"红叶风 ",]),
(["id":"fadai","title":"一个人的追逐","name":"发呆 ",]),
(["id":"fall","title":"钦赐一等鹿鼎公","name":"冷清秋","sex":1,]),
(["id":"fff","title":"苦命的孩子","name":"飞龙 ",]),
(["id":"ffs","title":"法王","name":"地邪 ",]),
(["id":"fgy","title":"连城剑","name":"方歌吟 ",]),
(["id":"flower","title":"大理镇南王府家奴","name":"蝶恋花","sex":1,]),
(["id":"foryou","title":"为君而狂","name":"如诗","sex":1,]),
(["id":"foxzzz","title":"钦赐一等鹿鼎公","name":"雪雁","sex":1,]),
(["id":"frfr","title":"丐帮九袋长老","name":"呼噜 ",]),
(["id":"ftoiloveyou","title":"wait me xue yitiantulong","name":"雪中情圣 ",]),
(["id":"fury","title":"一道闪电从天而降砸到你头上","name":"清平乐 ",]),
(["id":"fusheng","title":"看黄沙卷起千层浪一笑不能忘","name":"本.拉登 ",]),
(["id":"eddie","title":"Amy的大米军团三团团长","name":"珞珈混混","sex":1,]),
(["id":"ehuan","title":"负神 no look","name":"静环","sex":1,]),
(["id":"enjoy","title":"色佛","name":"休闲 ",]),
(["id":"eric","title":"逍遥派第四代弟子","name":"岳超 ",]),
(["id":"dairun","title":"钦赐一等鹿鼎公","name":"代天 ",]),
(["id":"dali","title":"萝卜青菜猪","name":"难免 ",]),
(["id":"datank","title":"昆仑派第六代弟子","name":"大坦克 ",]),
(["id":"dhxy","title":"【上次死因】被上官巡捕杀死","name":"大话西游 ",]),
(["id":"digu","title":"终于过上好日子，用上宽带了","name":"童养媳 ",]),
(["id":"dldi","title":"大理镇南王府武将","name":"大理义工 ",]),
(["id":"dodo","title":"孤魂野鬼","name":"没品上人 ",]),
(["id":"donkey","title":"唐门第七代弟子","name":"驴子 ",]),
(["id":"duly","title":"采花小贼","name":"净阿 ",]),
(["id":"caiyi","title":"逍遥派护法使者","name":"彩衣","sex":1,]),
(["id":"camin","title":"采花小贼","name":"笑天 ",]),
(["id":"chaosheng","title":"Diablo12 www.love214.com","name":"潮生 ",]),
(["id":"cloud","title":"华山派第十三代弟子","name":"云起 ",]),
(["id":"com","title":"千里思君莫相忘","name":"虫虫 ",]),
(["id":"cutlove","title":"白驼山派第二代弟子","name":"横刀 ",]),
(["id":"baggio","title":"百里潜龙","name":"轩辕剑 ",]),
(["id":"baishi","title":"mely的专职秘书","name":"冬月辛","sex":1,]),
(["id":"banana","title":"星宿派第三代弟子","name":"香蕉 ",]),
(["id":"baoer","title":"华山派第十三代弟子","name":"贾宝玉 ",]),
(["id":"battlee","title":"【神古活心流】代师傅","name":"薛婷","sex":1,]),
(["id":"bear","title":"挂挂机聊聊天","name":"笑狂 ",]),
(["id":"bee","title":"游戏人生","name":"女王蜂","sex":1,]),
(["id":"bihu","title":"小恐龙","name":"壁虎 ",]),
(["id":"biluo","title":"右丞相","name":"爱尔兰咖啡","sex":1,]),
(["id":"bird","title":"明教使者","name":"蓝鸟","sex":1,]),
(["id":"bingxueer","title":"将无聊进行到底","name":"冰雪儿","sex":1,]),
(["id":"bmr","title":"姑苏","name":"雪儿","sex":1,]),
(["id":"budai","title":"姑苏慕容第四代弟子","name":"有来有去 ",]),
(["id":"bullet","title":"我要! 我要嘛 ～～～～","name":"小鱼 ",]),
(["id":"admire","title":"雾中云中难寻我踪","name":"雾云 ",]),
(["id":"aka","title":"九阴狂中","name":"阿卡 ",]),
(["id":"akan","title":"小善人","name":"莫柯无量 ",]),
(["id":"amejio","title":"桃花岛第二代弟子","name":"娟娟","sex":1,]),
(["id":"amy","title":"幼年天下第一","name":"阿宝","sex":1,]),
(["id":"ant","title":"是谁在耳边说爱你永不变","name":"不悔","sex":1,]),
(["id":"anran","title":"古墓之风云乍起","name":"我心黯然 ",]),
(["id":"aoe","title":"放下屠刀 立地成佛","name":"渡奥 ",]),
(["id":"axax","title":"愿随夫子天坛上 闲与仙人扫落花","name":"白玉京",])
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
set("gender", "女性" );
else set("gender", "男性" );
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
      
        set("chat_chance", 50);
        set("chat_msg", ({
                (: do_walk :),
                (: random_move :),
        }) );

        set("inquiry", ([
   	    "密件"  : (: ask_job :),
	    "task"  : (: ask_job :),
            ]));
      
//initlvl(200+random(188));
	
	add_money("silver",50+random(50));
}
       



void init()
{
        remove_call_out("leave");
        call_out("leave",600);
}
void leave()
{
        object ob = this_object();
        if (!ob->is_fighting()) {
                message_vision(this_object()->query("name") + "钻进路边的杂草，不见了。\n" NOR,this_object());
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

       set("gender", "男性");
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
					+ "怎么可能是" + RANK_D->query_respect(ob)
					+ "的对手？\n");
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
		  command("say 不好，我被识破了!!");
if (random(5)==1)
{
command("say 逃啊!!");
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
return  "你想做什么呢?";
 if (environment(guo)->query("no_fight"))
{
command("say 逃啊!!");
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
return  "这里人多，不安全，快走!";
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

void die()
{
	object killer;
 object ob,me;
int exp,pot,base_exp;
	int i;
	object fang,who,where;
        int count,add_exp;
        object *team,boss;

	ob=this_object();
	if (!objectp(killer = query_temp("last_damage_from")))
	return;	
me=killer;
	where = environment(me);
who=me;
if (killer->query("quest/location1") && killer->query("id")==ob->query("killbyn"))
{
	
        	tell_object(killer,"突然,"+ob->query("name")+"朝"
		+killer->query("quest/location1n")+"的方向逃走了!\n");

ob->move(killer->query("quest/location1"));
  ob->revive();
  ob->reincarnate();
ob->set("neili",ob->query("max_neili")*2);
ob->set("qi",ob->query("max_qi")*2);
ob->set("eff_qi",ob->query("max_qi")*2);
ob->set("jing",ob->query("max_jing")*2);
if (wizardp(me))
tell_object(me,"位置:"+killer->query("quest/location1")+"。\n" NOR);
	killer->delete("quest/location1");
	killer->delete("quest/locationn");
return ;
}	
		
	if(objectp(killer = query_temp("last_damage_from"))  && killer->query("id")==ob->query("killbyn"))
{
 count=me->query_temp("team_count");
		if (count<2) count=2;	
               
		team=me->query_team();
		count=sizeof(team);
		//write("\n"+sprintf("%d",count));
if (!count)
{
		     exp=random(1188)+888;
		     pot=exp*2/3+random(200);

me->clear_condition("mjb2_busy");		
me->clear_condition("mp2_kill");
me->delete("quest");
me->delete("task_time");
me->delete("mjb2job");
me->delete_temp("team_count");	
addnl(me,"exp",exp);
if (random(3)==0) addnl(me,"mpgx",1);
}	

		for(i=0;i<count;i++)
		{ if(team[i]!=0)
		{
			if (team[i]->query_condition("mjb2_busy"))
			{ 
			 add_exp=100;
		     exp=random(1188)+888;
		     pot=exp*2/3+random(200);
		     team[i]->delete_temp("team_count");
             if (environment(me)==environment(team[i])) addnl(team[i],"exp",exp);


team[i]->clear_condition("mjb2_busy");		
team[i]->clear_condition("mp2_kill");
team[i]->delete("quest");
team[i]->delete("task_time");
team[i]->delete("mjb2job");
team[i]->delete_temp("team_count");
			}
			} 
		}

}
	::die();

return ;
}