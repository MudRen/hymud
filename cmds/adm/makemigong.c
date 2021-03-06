#include <net/daemons.h>

inherit F_CLEAN_UP;
string  zuji(string str);
mapping *dddata=({
(["name":"玉龙雪山",	"long":"雪山山腰云腾雾绕，远望像一条银白色的巨龙，因此得名。","tname":"migong0","ttg":"/d/kunming/dxiaolu","npc":"npc1","boss":"boss1","lv":"100",]),
(["name":"缙云山",	"long":"缙云山位于嘉陵江温塘峡畔，古名巴山。古木参天，翠竹成林，环境清幽。","tname":"migong1","ttg":"/d/baling/edao5","npc":"npc2","boss":"boss2","lv":"110",]),
(["name":"盘山",	"long":"自然山水与名胜古迹并著，佛家寺院与后家轩林共称。","tname":"migong2","ttg":"/d/tanggu/gangkou","npc":"npc3","boss":"boss3","lv":"120",]),
(["name":"五台山",	"long":"五台山与四川峨嵋山、安徽九华山、浙江普陀山共称中国佛教四大名山。","tname":"migong3","ttg":"/d/taiyuan/road1","npc":"npc4","boss":"boss4","lv":"130",]),
(["name":"桂林山水",	"long":"桂林山水一向以山青、水秀、洞奇、石美而享有山水甲天下的美誉","tname":"migong4","ttg":"/d/yanping/fuqiao1","npc":"npc5","boss":"boss5","lv":"140",]),
(["name":"杭州西湖",	"long":"西湖之妙，在于湖裹山中，山屏湖外，湖和山相得益彰。","tname":"migong5","ttg":"/d/hangzhou/baiti","npc":"npc6","boss":"boss6","lv":"150",]),
(["name":"天子山",	"long":"天子山因明初土家族领袖农民起义领袖向大坤自号向王天子，而得名。","tname":"migong6","ttg":"/d/tiezhang/road-3","npc":"npc7","boss":"boss1","lv":"160",]),
(["name":"九寨沟",	"long":"九寨沟白水沟上游白河的支沟，以有九个藏族村寨而得名","tname":"migong7","ttg":"/d/qingzh/road8","npc":"npc8","boss":"boss8","lv":"170",]),
(["name":"长江三峡 ",	"long":"　长江三峡，大峡深谷，曾是三国古战场，是无数英雄豪杰用武之地。","tname":"migong8","ttg":"/d/baling/edao10","npc":"npc9","boss":"boss9","lv":"180",]),
(["name":"西双版纳",	"long":"西双版纳，古代傣语为勐巴拉那西，意思是理想而神奇的乐土 ","tname":"migong9","ttg":"/d/kunming/nanmen","npc":"npc10","boss":"boss10","lv":"190",]),
(["name":"黄果树瀑",	"long":" 黄果树瀑布位于贵州的白水河上。周围岩溶广布，河宽水急。","tname":"migong10","ttg":"/d/kunming/pubu","npc":"npc11","boss":"boss11","lv":"200",]),
(["name":"日月潭",	"long":"日月潭中有一小岛远望好像浮在水面上的一颗珠子，名珠子屿。 ","tname":"migong11","ttg":"/d/taiwan/riyuetan","npc":"npc12","boss":"boss12","lv":"210",]),
(["name":"云南石林",	"long":"冬无严寒、夏无酷暑、四季如春，素有天下第一奇观石林博物馆的美誉","tname":"migong12","ttg":"/d/kunming/shilin2","npc":"npc13","boss":"boss13","lv":"220",]),
(["name":"苏州园林",	"long":"这里素来以山水秀丽，园林典雅而闻名天下，有江南园林甲天下，苏州园林甲江南的美称。","tname":"migong13","ttg":"/d/suzhou/yanyutang","npc":"npc14","boss":"boss14","lv":"230",]),
(["name":"乐山大佛",	"long":"乐山大佛，又名凌云大佛，地处中国四川省乐山市，岷江、青衣江和大渡河三江汇流处。","tname":"migong14","ttg":"/d/xinan/leshan","npc":"npc15","boss":"boss15","lv":"240",]),
(["name":"曲阜三孔",	"long":"东方圣城。千年礼乐归东鲁，万古衣冠拜素王曲阜之所以享誉中华，是与孔子的名字紧密相连的。 ","tname":"migong15","ttg":"/d/jinan/road2","npc":"npc16","boss":"boss16","lv":"250",]),
(["name":"秦始皇兵马俑",	"long":"兵马俑中那数千名手执兵器的武士，数百匹曳车的战马，一列列、一行行，构成规模宏伟、气势磅礴的阵容。","tname":"migong16","ttg":"/d/city4/apanggong","npc":"npc17","boss":"boss17","lv":"260",]),
(["name":"承德避暑山庄",	"long":"避暑山庄以朴素淡雅的山村野趣为格调，取自然山水之本色，吸收江南塞北  避暑山庄之风光","tname":"migong17","ttg":"/d/changcheng/nroad1","npc":"npc18","boss":"boss18","lv":"270",]),
(["name":"敦煌莫高窟",	"long":"环顾洞窟的四周和窟顶，到处都画着佛像、飞天、伎乐、仙女·赤身女人等。","tname":"migong18","ttg":"/d/qilian/yumenguan","npc":"npc19","boss":"boss19","lv":"280",]),
(["name":"布达拉宫",	"long":"最初是松赞干布为迎娶文成公主而兴建的。整座宫殿具有鲜明的藏式风格，依山而建，气势雄伟。","tname":"migong19","ttg":"/d/xizang/birdroad2","npc":"npc20","boss":"boss20","lv":"290",]),
(["name":"洛阳白马",	"long":"洛阳白马寺创建于东汉永平十一年68年，为中国第一古刹，世界著名伽蓝，是佛教传入中国后兴建的第一座寺院。","tname":"migong20","ttg":"/d/kaifeng/wroad3","npc":"npc21","boss":"boss21","lv":"300",]),
(["name":"乌镇",	"long":"乌镇曾名乌墩和青墩，具有六千余年悠久历史。素有鱼米之乡，丝绸之府之称。","tname":"migong21","ttg":"/d/hangzhou/road4","npc":"npc22","boss":"boss22","lv":"310",]),
(["name":"周庄",	"long":"古镇周庄始建于1086年，因邑人周迪功先生捐地修全福寺而得名。","tname":"migong22","ttg":"/d/hangzhou/suti7","npc":"npc23","boss":"boss23","lv":"320",]),
(["name":"皖南西递",	"long":"西递村坐落于黄山南麓，素有桃花源里人家之称。","tname":"migong23","ttg":"/d/huangshan/taoyuan","npc":"npc24","boss":"boss24","lv":"330",]),
(["name":"皖南宏村",	"long":"宏村内鳞次栉比的层楼叠院与旖旎的湖光山色交相辉映，动静相宜，空灵蕴藉，处处是景，步步入画","tname":"migong34","ttg":"/d/huangshan/lianhua","npc":"npc25","boss":"boss25","lv":"340",]),
(["name":"泰宁古镇",	"long":"泰宁曾有汉唐古镇，两宋名城之称，早在新石器时代就有人类在这里繁衍生息。","tname":"migong25","ttg":"/d/fuzhou/shulin","npc":"npc26","boss":"boss26","lv":"350",]),
(["name":"山西张壁",	"long":"山西张壁是尉迟恭帮刘武周与李世民交战守介休时所为，是明筑城堡、暗挖地道时的遗物。","tname":"migong26","ttg":"/d/taiyuan/sroad6","npc":"npc27","boss":"boss27","lv":"360",]),
(["name":"李庄",	"long":"李庄，坐落在孕育了华夏文明的母亲河——长江的南岸，与大桂轮山隔山相望，依山傍水，风景宜人。","tname":"migong27","ttg":"/d/hangzhou/shiwudong","npc":"npc28","boss":"boss28","lv":"370",]),
(["name":"南浔镇",	"long":"南浔镇是历史悠久的文化重镇。南浔素有鱼米之乡、丝绸之府之美誉。南宋时起，南浔镇就商贾云集，经济繁荣","tname":"migong28","ttg":"/d/hangzhou/shuiledong","npc":"npc29","boss":"boss29","lv":"380",]),
(["name":"同里镇",	"long":"同里旧称富土。唐初改为铜里。宋时将旧名拆字为同里。同里风景优美，镇外四面环水。","tname":"migong29","ttg":"/d/hangzhou/shanlu4","npc":"npc30","boss":"boss30","lv":"390",]),
(["name":"和顺镇",	"long":"和顺古镇古名阳温暾，因境内有一条小河绕村而过，更名河顺，后取士和民顺之意，雅化为和顺乡。","tname":"migong31","ttg":"/d/kunming/qingshilu2","npc":"npc31","boss":"boss31","lv":"400",]),
(["name":"七星岩",	"long":"七星岩景区由散落在广阔湖区的七岩、八洞、五湖、六岗组成，以山奇水秀、湖山相映、洞穴幽奇见胜。。","tname":"migong32","ttg":"/d/henshan/hsroad9","npc":"npc32","boss":"boss32","lv":"410",]),
(["name":"壶口瀑布",	"long":"壶口瀑布是中国黄河上的著名瀑布，其奔腾汹涌的气势是中华民族精神的象征。","tname":"migong33","ttg":"/d/city4/road4","npc":"npc33","boss":"boss33","lv":"420",]),
(["name":"平遥城",	"long":"平遥旧称古陶，明朝初年，为防御外族南扰，始建城墙，洪武三年公元1370年在旧墙垣基础上重筑扩修，并全面包砖。","tname":"migong34","ttg":"/d/taiyuan/road4","npc":"npc34","boss":"boss34","lv":"430",]),
(["name":"云冈石窟",	"long":"云冈石窟位于武周山南麓，依山而凿，东西绵延约一公里，气势恢弘，内容丰富。","tname":"migong35","ttg":"/d/taiyuan/road5","npc":"npc35","boss":"boss35","lv":"440",]),
(["name":"阳朔城",	"long":"阳朔是一个历史悠久的古城，唐诗中一句说得好：城郭并无二里大，人家都在万山中。","tname":"migong36","ttg":"/d/yanping/road1","npc":"npc36","boss":"boss36","lv":"450",]),
(["name":"米亚罗",	"long":"米亚罗藏语译为好玩的坝子，米亚罗到了金秋时节，万树姹紫嫣红，争奇形怪状斗艳。","tname":"migong37","ttg":"/d/xinan/shanlu09","npc":"npc37","boss":"boss37","lv":"460",]),
(["name":"广胜寺",	"long":"广胜寺位于洪洞县城东北的霍山南麓，霍泉亦发源于此地，寺区古柏苍翠，山清水秀。","tname":"migong38","ttg":"/d/taiyuan/nroad1","npc":"npc38","boss":"boss38","lv":"470",]),
(["name":"天目溪",	"long":"天目溪是富春江上的一条支流，水质清澈，摇曳的水草，形态不一的鹅卵石清晰见底。","tname":"migong39","ttg":"/d/hangzhou/hupaoquan","npc":"npc39","boss":"boss39","lv":"480",]),
(["name":"法门寺",	"long":"法门寺为佛骨圣地，拥有世界最高佛塔。因安置释迦牟尼佛指骨舍利而成为举国仰望的佛教圣地。","tname":"migong40","ttg":"/d/lanzhou/caroad8","npc":"npc40","boss":"boss40","lv":"490",]),
(["name":"郎木寺",	"long":"郎木寺(虎女寺)位于四川、甘肃交界地带，自古以来就是川、甘、青各族民众朝拜黑虎女神的圣地。","tname":"migong41","ttg":"/d/xingxiu/xxroad1","npc":"npc41","boss":"boss41","lv":"500",]),
(["name":"伏羲庙",	"long":"伏羲庙本名太昊宫，俗称人宗庙，庙内院落重重相套，四进四院，宏阔幽深。","tname":"migong42","ttg":"/d/lanzhouchen/road3","npc":"npc42","boss":"boss42","lv":"510",]),
(["name":"麦积山石窟",	"long":"麦积山者，北跨清渭，麦积处其半，崛起一块石，高百万寻，望之团团，如农家积麦之状，故有此名。","tname":"migong43","ttg":"/d/lanzhou/caroad2","npc":"npc43","boss":"boss43","lv":"520",]),
(["name":"艾丁湖",	"long":"艾丁湖位于觉洛塔格山北麓，古代文人墨客叫它觉洛浣。维吾尔族人，则叫它艾丁库勒，意为月光湖、月亮湖。","tname":"migong44","ttg":"/d/xinjiang/aiding","npc":"npc44","boss":"boss44","lv":"530",]),
(["name":"太极洞",	"long":"太极洞为石灰岩溶洞，长5．4公里，由上洞、下洞、水洞、旱洞组成。","tname":"migong45","ttg":"/d/huangshan/mroad2","npc":"npc45","boss":"boss45","lv":"540",]),
(["name":"鼓浪屿",	"long":"鼓浪屿因岛西南方有一礁石，每当涨潮水涌，浪击礁石，声似擂鼓，人们称鼓浪石，鼓浪屿因此而得名。","tname":"migong46","ttg":"/d/fuzhou/yushan","npc":"npc46","boss":"boss46","lv":"550",]),
(["name":"武陵源",	"long":"武陵源，美在神秘，美在天然。与自然风光相映成趣的，是纯朴的田园风光。","tname":"migong47","ttg":"/d/changsha/road1","npc":"npc47","boss":"boss47","lv":"560",]),
(["name":"岳麓山",	"long":"岳麓山荟萃了湘楚文化的精华，名胜古迹众多，集儒释道为一体，历史圣迹遍布且植物资源丰富。","tname":"migong48","ttg":"/d/changsha/eroad3","npc":"npc48","boss":"boss48","lv":"570",]),
(["name":"丹霞山",	"long":"丹霞山分数为数层。有始建于北宋的锦石岩石窟寺、梦觉关、通天洞、百丈峡及最典型的赤壁丹崖。","tname":"migong49","ttg":"/d/fuzhou/fzroad4","npc":"npc49","boss":"boss49","lv":"580",]),
(["name":"芙蓉江",	"long":"芙蓉江景色秀丽，山青、水秀、崖雄、峰奇、峡幽、涧深、滩险、流急、瀑飞、泉涌，天作画廊，美不胜收。","tname":"migong50","ttg":"/d/guizhou/dadao2","npc":"npc50","boss":"boss50","lv":"590",]),
(["name":"黄龙寺",	"long":"黄龙寺薜萝丛生，花木竞秀，碧水清泉，漫台滚泻，形成千百块迂回周折、层层嵌砌的彩池。","tname":"migong51","ttg":"/d/resort/smallroad","npc":"npc51","boss":"boss51","lv":"600",]),
(["name":"贡嘎山",	"long":"贡嘎山是最难以征服的大尺度极高山，其登顶难度远远大于珠穆朗玛峰。","tname":"migong52","ttg":"/d/xinan/shanlu07","npc":"npc52","boss":"boss52","lv":"610",]),
(["name":"蜀南竹海",	"long":"相传，蜀南竹海所在的万岭山原是女娲娘娘补天时遗落的赤石。 ","tname":"migong53","ttg":"/d/xuedao/sroad2","npc":"npc53","boss":"boss53","lv":"620",]),
(["name":"光雾山",	"long":"光雾山是一方神奇秀丽的自然山水，地形复杂，峰峦迭嶂，峰林俊美，洞穴幽深。","tname":"migong54","ttg":"/d/xinan/shanlu11","npc":"npc54","boss":"boss54","lv":"630",]),
(["name":"都匀斗篷山",	"long":"斗篷山山间林地蓄水丰盈，共有大小溪流100余条。其中茶园河及谷江河布满巨大的卵石，有如来自远古的船舶。","tname":"migong55","ttg":"/d/guizhou/tulu2","npc":"npc55","boss":"boss55","lv":"640",]),
(["name":"九龙洞",	"long":"九龙洞地处伏牛山南麓，西接秦岭，东与熊耳山主峰毗连，南与玉皇尖相望，属长江流域。","tname":"migong56","ttg":"/d/guizhou/beimen","npc":"npc56","boss":"boss56","lv":"650",]),
(["name":"黄帝陵",	"long":"黄帝陵，是中华民族始祖黄帝的陵墓，相传黄帝得道升天，故此陵墓为衣冠冢。","tname":"migong57","ttg":"/d/city4/road5","npc":"npc57","boss":"boss57","lv":"660",]),
(["name":"麦积山",	"long":"天水市东南方50公里的麦积区麦积山乡南侧，是西秦岭山脉小陇山中的一座孤峰。","tname":"migong58","ttg":"/d/tianshui/yidao5","npc":"npc58","boss":"boss58","lv":"670",]),
(["name":"博斯腾湖",	"long":"我国最大的内陆淡水湖。 风起时波浪滔滔，宛如沧海,风静时波光潋滟，湖水连天。","tname":"migong59","ttg":"/d/xinjiang/chairong","npc":"npc59","boss":"boss59","lv":"680",]),
(["name":"腾冲热地",	"long":"腾冲有万年火山热海，千年古道边关，百年翡翠商城,有99座火山雄歭苍穹、88处温泉喷珠溅玉。","tname":"migong60","ttg":"/d/kunming/qingshilu","npc":"npc60","boss":"boss60","lv":"690",]),
(["name":"后石坞",	"long":"在泰山的背面，此处危岩峭壁，怪石突立，饰以苍松翠柏，幽径小溪，景致尤具别趣。。","tname":"migong61","ttg":"/d/taishan/baozang","npc":"npc61","boss":"boss61","lv":"700",]),
(["name":"遥参亭",	"long":"旧称草参亭，为岱庙前亭。古人祭泰山必先至此简单参拜，尔后入庙祭祀。今院内举办了泰安民俗 。","tname":"migong62","ttg":"/d/taishan/yaocan","npc":"npc62","boss":"boss62","lv":"710",]),
(["name":"汉柏院",	"long":"汉柏院位于岱庙配天门东，因院内有古柏五株而得名。","tname":"migong63","ttg":"/d/taishan/daimiao","npc":"npc63","boss":"boss63","lv":"720",]),
(["name":"舍身崖",	"long":"泰山日凤峰南，因旧时常有人于此为父母求福投崖舍身而得名。易名为舍身崖。。","tname":"migong64","ttg":"/d/taishan/aishen","npc":"npc64","boss":"boss64","lv":"730",]),
(["name":"黄山松谷",	"long":"一路千峰竞秀，万壑争奇，巧石名潭尤为佳妙。特别是山高林密，空气清新，真可谓是清凉世界。","tname":"migong65","ttg":"/d/huangshan/feicui","npc":"npc65","boss":"boss65","lv":"740",]),
(["name":"牯牛降历溪",	"long":"牯牛降历溪位於牯牛降山脚下，群山环抱。村中人家，世代聚族而居，过著世外桃源般的田园生活。 ","tname":"migong66","ttg":"/d/huangshan/mingxuan","npc":"npc66","boss":"boss66","lv":"750",]),
(["name":"古城岩",	"long":"古城岩，座落在休宁县万安镇东侧，虽是低低的一面山峦，却以众多的古迹遗址。","tname":"migong67","ttg":"/d/huangshan/chayuan","npc":"npc67","boss":"boss67","lv":"760",]),
(["name":"中岳庙",	"long":"道教圣地圣景，五岳居冠居中。慢慢游览这块三清净地，感受道家反朴归真回复自然的理想。","tname":"migong68","ttg":"/d/songshan/tianzhongge","npc":"npc68","boss":"boss68","lv":"770",]),
(["name":"观星台 ",	"long":"观星台由台身由石圭、表槽组成。台身上小下大，形似覆斗。台面呈方形。","tname":"migong69","ttg":"/d/songshan/chaotian","npc":"npc69","boss":"boss69","lv":"780",]),
(["name":"嵩阳书院",	"long":"嵩阳书院东西山岭环抱，逍遥谷溪水缓缓南流，嵩岳寺溪水汩汩西来，两道清澈的溪水，在嵩阳书院前面汇合。","tname":"migong70","ttg":"/d/songshan/shuyuan","npc":"npc70","boss":"boss70","lv":"790",]),
(["name":"华山东峰",	"long":"华山主峰，因位置居东得名。峰顶有一平台，居高临险，视野开阔，是著名的观日出的地方，人称朝阳台，东峰也因之被称为朝阳峰。","tname":"migong71","ttg":"/d/huashan/chaoyang","npc":"npc71","boss":"boss71","lv":"800",]),
(["name":"华山南峰",	"long":"华山主峰，也是五岳的最高峰，古人尊称它是华山元首。登上南峰绝顶，顿感天近咫尺，星斗可摘。","tname":"migong72","ttg":"/d/huashan/sheshen","npc":"npc72","boss":"boss72","lv":"810",]),
(["name":"华山西峰",	"long":"华山主峰，因位置居西得名。又因峰巅 有巨石形状好似莲花瓣，古代文人多称其为莲花峰、芙蓉峰。","tname":"migong73","ttg":"/d/huashan/lianhua","npc":"npc73","boss":"boss73","lv":"820",]),
(["name":"华山北峰",	"long":"华山主峰，因位置居北得名。北峰四面悬绝，上冠景云，下通地脉，巍然独秀，有若云台，因此又名云台峰。","tname":"migong74","ttg":"/d/huashan/yuntai","npc":"npc74","boss":"boss74","lv":"830",]),
(["name":"华山中峰",	"long":"华山主峰。居东、西、南三峰中央，峰上林木葱茏，环境清幽，奇花异草多不知名，峰头有道舍名玉女祠，因此峰又被称为玉女峰。","tname":"migong75","ttg":"/d/huashan/yunu","npc":"npc75","boss":"boss75","lv":"840",]),
(["name":"祝圣寺",	"long":"祝圣寺距南岳大庙很近，不足百步。此佛寺宏伟壮观，殿宇整齐。","tname":"migong76","ttg":"/d/henshan/zhurongfeng","npc":"npc76","boss":"boss76","lv":"850",]),
(["name":"南台寺",	"long":"南台寺在于瑞应峰下的三生塔南面，号称天下法源，南朝梁天监年间创建，唐天宝年间禅宗七祖弟子希迁和尚将它定名为南台寺。","tname":"migong77","ttg":"/d/henshan/wangyuetai","npc":"npc77","boss":"boss77","lv":"860",]),
(["name":"上封寺",	"long":"上封寺在高台寺上方，距南岳庙十公里，是南岳最早的古刹之一。隋朝以前叫光天观，被道教尊为第二十二福地。它就是后来的上封寺。","tname":"migong78","ttg":"/d/henshan/wangritai","npc":"npc78","boss":"boss78","lv":"870",]),
(["name":"虎风口",	"long":"虎风口是一个峰回路转的陡峭路口，刮起风来，声如虎啸，由此得名。","tname":"migong79","ttg":"/d/hengshan/hufengkou","npc":"npc79","boss":"boss79","lv":"880",]),
(["name":"夕阳岩",	"long":"万仞险峰直达云霄，每当夕阳西下，余辉反照满峪入画。","tname":"migong80","ttg":"/d/hengshan/xuangengsong","npc":"npc80","boss":"boss80","lv":"890",]),
(["name":"开福寺",	"long":"开福寺是中国佛教重点开放寺院之一，为禅宗临济宗杨岐派著名寺院，始建于五代时期，距今已有1000多年历史。","tname":"migong81","ttg":"/d/changsha/yanzixiang","npc":"npc81","boss":"boss81","lv":"900",]),
(["name":"马王堆",	"long":"原为河湾平地中隆起的一个大土堆，据地方志记载为五代时期楚王马殷及其家族的墓地，故名马王堆。","tname":"migong82","ttg":"/d/changsha/eroad2","npc":"npc82","boss":"boss82","lv":"910",]),
(["name":"天心阁",	"long":"天心阁在长沙市中心地区东南角上，是长沙古城的一座城楼。为长沙重要名胜，也是长沙仅存的古城标志。","tname":"migong83","ttg":"/d/changsha/dongmen","npc":"npc83","boss":"boss83","lv":"920",]),
(["name":"苏仙岭",	"long":"自古享有“天下第十八福地”、“湘南胜地”的美称。苏仙岭因苏仙神奇、美丽的传说而驰名海内外。","tname":"migong84","ttg":"/d/henshan/hsroad8","npc":"npc84","boss":"boss84","lv":"930",]),
(["name":"黄鹤楼",	"long":"相传也始建于三国，唐时名声始盛，这主要得之于诗人崔颢昔人已乘黄鹤去，此地空余黄鹤楼诗句","tname":"migong85","ttg":"/d/jiangling/huanghelou","npc":"npc85","boss":"boss85","lv":"940",]),
(["name":"西陵峡",	"long":"西陵峡以滩多水急著称。著名的新滩、崆岭滩和腰叉河均在西陵峡内。","tname":"migong86","ttg":"/d/jingzhou/sanxia1","npc":"npc86","boss":"boss86","lv":"950",]),
(["name":"神农架",	"long":"上古时代的神农氏曾在这里遍尝百草为民除病，由于崖高壁陡，珍稀药草不易采到，神农氏就伐木搭架而上，因此后人称这里为“神农架”。","tname":"migong87","ttg":"/d/jiangling/shennongjia","npc":"npc87","boss":"boss87","lv":"960",]),
(["name":"巫峡",	"long":"巫峡谷深狭长，日照时短，峡中湿气蒸郁不散，容易成云致雾，云雾千姿万态。","tname":"migong88","ttg":"/d/jingzhou/sanxia2","npc":"npc88","boss":"boss88","lv":"970",]),
(["name":"天涯海角",	"long":"海湾沙滩上大小百块石耸立，“天涯”、“海角”和“南天一柱”巨石突兀其间，昂首天外，峥嵘壮观","tname":"migong89","ttg":"/d/hainan/underhill2","npc":"npc89","boss":"boss89","lv":"980",]),
(["name":"五指山",	"long":"五指山市周围群山环抱，森林茂密，是有名的“翡翠山城”。它以海南岛上最高山峰五指山因而得名。","tname":"migong90","ttg":"/d/hainan/road4","npc":"npc90","boss":"boss90","lv":"990",]),
(["name":"万泉河",	"long":"沿河两岸典型的热带雨林景观和巧夺天工的地貌，令人叹为观止。万泉河生态环境优美的热带河流，被誉为中国的“亚马逊河”。","tname":"migong91","ttg":"/d/hainan/pubu","npc":"npc91","boss":"boss91","lv":"1000",]),
(["name":"博鳌",	"long":"“博鳌浦莫村都（在县东民疍）”。因此“民疍”是博鳌最早的居民，博鳌的名称应该是“民疍”所起。","tname":"migong92","ttg":"/d/hainan/underhill3","npc":"npc92","boss":"boss92","lv":"1010",]),
(["name":"魔鬼城",	"long":"魔鬼城又称乌尔禾风城。哈萨克人称为“沙依坦克尔西”，意为魔鬼城","tname":"migong93","ttg":"/d/xinjiang/emin","npc":"npc93","boss":"boss93","lv":"1020",]),
(["name":"香妃墓",	"long":"埋葬在这里的霍加后裔中，有一个叫伊帕尔汗的女子，是乾隆皇帝的爱妃。","tname":"migong94","ttg":"/d/xinjiang/tulu3","npc":"npc94","boss":"boss94","lv":"1030",]),
(["name":"交河故城",	"long":"交河故城 由于连年战火，交河城逐渐衰落。","tname":"migong95","ttg":"/d/xinjiang/sichou3","npc":"npc95","boss":"boss95","lv":"1040",]),
(["name":"喀纳斯湖",	"long":"　喀纳斯是蒙古语，意为“美丽富饶、神秘莫测”或者“峡谷中的湖”。","tname":"migong96","ttg":"/d/xinjiang/goudi","npc":"npc96","boss":"boss96","lv":"1050",]),
(["name":"古格故城",	"long":"巍峨的古格故城坐落于阿里扎达县扎布让区境内托林镇西北的象泉河南岸。为曾经拥有百万之众的金戈铁马的吐蕃王室后裔所建。","tname":"migong97","ttg":"/d/xizang/deadneck","npc":"npc97","boss":"boss97","lv":"1060",]),
(["name":"科迦寺",	"long":"科迦寺是普兰县大寺，历史悠久，在当地享有盛名，每年都有阿里地区札达、噶  建筑尔等县及境外尼泊尔的信徒前来朝拜。","tname":"migong98","ttg":"/d/zangbei/mount2","npc":"npc98","boss":"boss98","lv":"1070",]),
(["name":"红毛城",	"long":"红毛城炮台城垣红毛城伫立在淡水街尾往淡海方向，高踞淡水河出海口的山巅。","tname":"migong99","ttg":"/d/taiwan/hongmaocheng","npc":"npc99","boss":"boss99","lv":"1080",]),
(["name":"龙山寺",	"long":"鹿港龙山寺规模宏伟，坐向为东朝西，格局十分方正，山门为三进两廊九开间纵深式建筑。","tname":"migong100","ttg":"/d/taiwan/lugang","npc":"npc100","boss":"boss100","lv":"1090",]),
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
		return notify_fail("只有 (arch) 以上的巫师才能使用!\n");


lb=0;
tp=8;

lv=1;

//生成NPC
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


//生成BOSS
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
//生成迷宫
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
//write("名称:"+dddata[i]["name"]+" 等级:"+dddata[i]["lv"]+" 位置:"+envn+"\n");
write_file("/p/migong/migong/"+dddata[i]["tname"]+".c",my_file,1);
}
					}

					


					
	return 1;
}


string  zuji(string str)
{   
string output;
      	if (str=="baituo")  

	output="白驼山";

if (str=="binghuodao")  

	output="冰火岛";

if (str=="city")  

	output="扬州";

if (str=="city2" || str=="beijing"  || str=="huanggon"  || str=="huanggong" || str=="beihai")  

	output="北京城";

if (str=="city4" || str=="changan")   

	output="长安城";

if (str=="dali")  

	output="大理";

if (str=="emei")  

	output="娥眉山";

if (str=="foshan")  

	output="佛山";

if (str=="gaibang")  

	output="丐帮";

if (str=="gaochang")  

	output="高昌迷宫";

if (str=="guanwai")  

	output="关外";

if (str=="guiyun")  

	output="归云庄";

if (str=="gumu")  

	output="古墓派";

if (str=="hangzhou")  

	output="杭州";

if (str=="heimuya")  

	output="黑木崖";

if (str=="hengshan")  

	output="恒山";

if (str=="henshan")  

	output="衡山";

if (str=="huanghe")  

	output="黄河九曲";

if (str=="huashan")  

	output="华山";

if (str=="jinshe")  

	output="金蛇山洞";

if (str=="lingjiu")  

	output="灵鹫宫";

if (str=="lingzhou")  

	output="灵州";

if (str=="meizhuang")  

	output="梅庄";

if (str=="mingjiao")  

	output="明教";

if (str=="qingcheng")  

	output="青城山";

if (str=="quanzhen")  

	output="全真派";

if (str=="quanzhou")  

	output="泉州";

if (str=="shaolin")  

	output="少林寺";

if (str=="shenlong")  

	output="神龙岛";

if (str=="songshan")  

	output="嵩山";

if (str=="suzhou")  

	output="苏州";

if (str=="taishan")  

	output="泰山";

if (str=="taohua")  

	output="桃花岛";

if (str=="tianlongsi")  

	output="天龙寺";

if (str=="wanjiegu")  

	output="万劫谷";

if (str=="wudang")  

	output="武当山";

if (str=="xiakedao")  

	output="侠客岛";

if (str=="xiangyang")  

	output="襄阳城";

if (str=="xiaoyao")  

	output="逍遥林";

if (str=="xingxiu")  

	output="星宿海";

if (str=="xueshan")  

	output="雪山寺";

if (str=="xuedao")  

	output="大雪山";

if (str=="mr")  

	output="慕容世家";

if (str=="kunlun")  

	output="昆仑山";

if (str=="tiezhang")  

	output="铁掌门";

if (str=="huizhu")  

	output="回族部落";

if (str=="yinju")  

	output="一灯大师居";

if (str=="menggu")  

	output="蒙古草原";

if (str=="qianjin")  

	output="北京千金楼";

if (str=="lingshedao")  

	output="灵蛇岛";

if (str=="ruzhou")  

	output="汝州城";

if (str=="kunming")  

	output="昆明";

if (str=="jingzhou")  

	output="荆州";

if (str=="yanjing")  

	output="盛京";

if (str=="lanzhou" || str=="lanzhouchen")  

	output="兰州";

if (str=="jyguan")  

	output="嘉峪关";

if (str=="changcheng")  

	output="长城";

if (str=="fairyland")  

	output="红梅山庄";

if (str=="sdxl")  

	output="剑魔独孤求败墓";

if (str=="jqg")  

	output="绝情谷";

if (str=="nio")  

	output="牛家村";

if (str=="feihu")  

	output="闯王宝藏";

if (str=="wuguan")  

	output="襄阳武馆";

if (str=="village")  

	output="华山村";

if (str=="taohuacun")  

	output="桃花村";

if (str=="pingan")  

	output="平安城";

if (str=="lingxiao")  

	output="凌霄城";

if (str=="wudujiao")  

	output="五毒教";

if (str=="hj")  

	output="天山草原";
if (str=="dali/yuxu")  

	output="大理玉虚观";
if (str=="dali/wuliang")  

	output="大理无量山";
if (str=="huanghe/yyd")  

	output="黄河萧府";
if (str=="kaifeng")  

	output="开封城";
if (str=="feitian")  

	output="飞天御剑流";
if (str=="japan")  

	output="日本神户";
if (str=="tangmen")  

	output="唐门";
if (str=="luoyang")  

	output="洛阳城";

if (str=="chengdu" || str=="city3")  

	output="成都";

if (str=="baihuagu")  

	output="百花谷";

if (str=="heizhao")  

	output="百花谷黑沼";

if (str=="jiaxing")  

	output="嘉兴";

if (str=="shiliang")  

	output="温家庄";

if (str=="wuyi")  

	output="武夷山区";

if (str=="yanping")  

	output="延平城";
	

if (str=="jiangling")  
{
	output="江陵城";
}

if (str=="yueyang")  
{
	output="岳阳城";	
}

if (str=="qilian")  
{
	output="祁连山";	
}

if (str=="shouxihu")  
{
	output="瘦西湖";	
}

if (str=="wuxi")  
{
	output="无锡城";	
}

if (str=="yixing")  
{
	output="宜兴城";	
}
if (str=="taiwan")  
{
	output="台湾";	
}
if (str=="nanyang")  
{
	output="南阳";	
}
if (str=="nanshaolin")  
{
	output="南少林";	
}

if (str=="cangzhou")  
{
	output="沧州";	
}

if (str=="tanggu")  
{
	output="塘沽城";	
}

if (str=="yunhe")  
{
	output="京杭运河";	
}

if (str=="hainan")  
{
	output="海南岛";	
}

if (str=="jindezheng")  
{
	output="景德镇";	
}

if (str=="yandang")  
{
	output="雁荡山";	
}

if (str=="jinling")  
{
	output="金陵城";	
}

if (str=="sandboy")  
{
	output="江南农村";	
}

if (str=="huangshan")  
{
	output="黄山";	
}

if (str=="yubifeng")  
{
	output="玉笔峰";	
}

if (str=="quanzhouchen")  
{
	output="泉州城内";	
}

if (str=="qingzh")  
{
	output="青藏高原";	
}

if (str=="changbaishan" || str=="gaoli")  
{
	output="高丽长白山";	
}

if (str=="annan")  
{
	output="安南";	
}

if (str=="taiyuan")  
{
	output="太原";	
}

if (str=="hefei")  
{
	output="合肥";	
}

if (str=="jiujiang")  
{
	output="九江";	
}

if (str=="baling")  
{
	output="巴陵";	
}

if (str=="xinjiang")  
{
	output="新疆";	
}
if (str=="dingxiang")  
{
	output="定襄";	
}
if (str=="suiye")  
{
	output="碎叶";	
}


if (str=="mayi")  
{
	output="马邑边疆";	
}
if (str=="xuzhou")  
{
	output="徐州城";	
}
if (str=="jinan")  
{
	output="济南城";	
}
if (str=="guizhou")  
{
	output="贵阳城";	
}

if (str=="nanchang")  
{
	output="南昌城";	
}


if (str=="changsha")  
{
	output="长沙城";	
}


if (str=="zhongzhou")  
{
	output="中州城";	
}

if (str=="xizang" || str=="zangbei")  
{
	output="西藏或藏北";	
}

if (str=="tianshui")  
{
	output="天水城";	
}

if (str=="datong")  
{
	output="大同府";	
}
if (str=="ny")  
{
	output="宁远城";	
}
if (str=="fengtian")  
{
	output="盛京城";	
}

if (str=="yanmen")  
{
	output="燕门关";	
}
if (str=="cloud")  
{
	output="绮云镇";	
}
if (str=="xueting")  
{
	output="雪亭镇";	
}
if (str=="fuzhou")  
{
	output="福州";	
}
if (str=="welcome")  
{
	output="古村";	
}
if (!output)  
{
	output="未知区域";	
}

if (output=="")  
{
	output="未知区域";	
}


return output;
}

int help (object me)
{
        write(@HELP
指令格式: shutdown
 
生成迷宫文件100个
 
HELP
);
        return 1;
}
 
