// qhlist100000.c

inherit SKILL;
#include <ansi.h>;
mapping *quest = ({
 
(["quest_city":"白驼附近", "quest": "村姑",  "quest_type": "杀",  "time":  200,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"白驼附近", "quest": "寡妇",  "quest_type": "杀",  "time":  200,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"白驼附近", "quest": "金花",  "quest_type": "杀",  "time":  200,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"白驼附近", "quest": "老材",  "quest_type": "杀",  "time":  200,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"白驼附近", "quest": "农民",  "quest_type": "杀",  "time":  200,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"白驼附近", "quest": "樵夫",  "quest_type": "杀",  "time":  200,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"白驼附近", "quest": "铁匠",  "quest_type": "杀",  "time":  200,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"白驼附近", "quest": "陪练童子",  "quest_type": "杀",  "time":  200,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"白驼附近", "quest": "白衣少女",  "quest_type": "杀",  "time":  200,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"白驼附近", "quest": "农家妇女",  "quest_type": "杀",  "time":  200,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"白驼附近", "quest": "丫环",  "quest_type": "杀",  "time":  200,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"白驼附近", "quest": "张妈",  "quest_type": "杀",  "time":  200,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 

(["quest_city":"嘉兴附近", "quest": "老船夫",  "quest_type": "杀",  "time":  200,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 

(["quest_city":"扬州附近", "quest": "史青山",  "quest_type": "杀",  "time":  300,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"扬州附近", "quest": "崔莺莺",  "quest_type": "杀",  "time":  300,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 

(["quest_city":"北京附近", "quest": "卖花姑娘",  "quest_type": "杀",  "time":  300,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"北京附近", "quest": "庄夫人",  "quest_type": "杀",  "time":  300,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"北京附近", "quest": "高彦超",  "quest_type": "杀",  "time":  300,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"北京附近", "quest": "关安基",  "quest_type": "杀",  "time":  300,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"北京附近", "quest": "胡掌柜",  "quest_type": "杀",  "time":  300,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"北京附近", "quest": "客店伙计",  "quest_type": "杀",  "time":  300,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"北京附近", "quest": "屠宰场伙计",  "quest_type": "杀",  "time":  300,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"北京附近", "quest": "药铺伙计",  "quest_type": "杀",  "time":  300,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"北京附近", "quest": "李力世",  "quest_type": "杀",  "time":  300,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"北京附近", "quest": "铁匠",  "quest_type": "杀",  "time":  300,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"北京附近", "quest": "戏子",  "quest_type": "杀",  "time":  300,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 

(["quest_city":"长安附近", "quest": "酸秀才",  "quest_type": "杀",  "time":  300,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 

(["quest_city":"大理附近", "quest": "士兵",  "quest_type": "杀",  "time":  300,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"大理附近", "quest": "台夷商贩",  "quest_type": "杀",  "time":  300,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"大理附近", "quest": "采桑女",  "quest_type": "杀",  "time":  300,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"大理附近", "quest": "采笋人",  "quest_type": "杀",  "time":  300,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"大理附近", "quest": "村妇",  "quest_type": "杀",  "time":  300,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"大理附近", "quest": "纺纱女",  "quest_type": "杀",  "time":  300,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"大理附近", "quest": "台夷妇女",  "quest_type": "杀",  "time":  300,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"大理附近", "quest": "歌女",  "quest_type": "杀",  "time":  300,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"大理附近", "quest": "摆夷女子",  "quest_type": "杀",  "time":  300,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"大理附近", "quest": "南国姑娘",  "quest_type": "杀",  "time":  300,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"大理附近", "quest": "宫女",  "quest_type": "杀",  "time":  300,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"大理附近", "quest": "管家",  "quest_type": "杀",  "time":  300,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"大理附近", "quest": "台夷姑娘",  "quest_type": "杀",  "time":  300,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"大理附近", "quest": "养花女",  "quest_type": "杀",  "time":  300,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"大理附近", "quest": "霍先生",  "quest_type": "杀",  "time":  300,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"大理附近", "quest": "江湖艺人",  "quest_type": "杀",  "time":  300,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"大理附近", "quest": "砍竹人",  "quest_type": "杀",  "time":  400,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"大理附近", "quest": "盛皮罗客商",  "quest_type": "杀",  "time":  400,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"大理附近", "quest": "摆夷小孩",  "quest_type": "杀",  "time":  400,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"大理附近", "quest": "猎人",  "quest_type": "杀",  "time":  400,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"大理附近", "quest": "台夷猎人",  "quest_type": "杀",  "time":  400,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"大理附近", "quest": "牧羊女",  "quest_type": "杀",  "time":  400,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"大理附近", "quest": "牧羊人",  "quest_type": "杀",  "time":  400,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"大理附近", "quest": "农夫",  "quest_type": "杀",  "time":  400,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"大理附近", "quest": "台夷农妇",  "quest_type": "杀",  "time":  400,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"大理附近", "quest": "农夫",  "quest_type": "杀",  "time":  400,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"大理附近", "quest": "摆夷老叟",  "quest_type": "杀",  "time":  400,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"大理附近", "quest": "皮货商",  "quest_type": "杀",  "time":  400,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"大理附近", "quest": "破嗔",  "quest_type": "杀",  "time":  400,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"大理附近", "quest": "破疑",  "quest_type": "杀",  "time":  400,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"大理附近", "quest": "少女",  "quest_type": "杀",  "time":  400,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"大理附近", "quest": "石匠",  "quest_type": "杀",  "time":  400,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"大理附近", "quest": "台夷商贩",  "quest_type": "杀",  "time":  400,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"大理附近", "quest": "素衣卫士",  "quest_type": "杀",  "time":  400,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"大理附近", "quest": "黄衣卫士",  "quest_type": "杀",  "time":  400,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"大理附近", "quest": "锦衣卫士",  "quest_type": "杀",  "time":  400,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"大理附近", "quest": "乌夷商贩",  "quest_type": "杀",  "time":  400,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"大理附近", "quest": "小道姑",  "quest_type": "杀",  "time":  400,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"大理附近", "quest": "薛老板",  "quest_type": "杀",  "time":  400,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"大理附近", "quest": "养蚕女",  "quest_type": "杀",  "time":  400,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"大理附近", "quest": "游客",  "quest_type": "杀",  "time":  400,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"大理附近", "quest": "渔夫",  "quest_type": "杀",  "time":  400,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 

(["quest_city":"佛山附近", "quest": "张朝唐",  "quest_type": "杀",  "time":  400,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"佛山附近", "quest": "张康",  "quest_type": "杀",  "time":  400,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"佛山附近", "quest": "钟四嫂",  "quest_type": "杀",  "time":  400,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"佛山附近", "quest": "钟小二",  "quest_type": "杀",  "time":  400,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 

(["quest_city":"福州附近", "quest": "白二",  "quest_type": "杀",  "time":  400,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"福州附近", "quest": "陈七",  "quest_type": "杀",  "time":  400,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"福州附近", "quest": "崔镖头",  "quest_type": "杀",  "time":  400,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"福州附近", "quest": "史镖头",  "quest_type": "杀",  "time":  400,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"福州附近", "quest": "王夫人",  "quest_type": "杀",  "time":  400,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"福州附近", "quest": "郑镖头",  "quest_type": "杀",  "time":  400,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 

(["quest_city":"归云庄附近", "quest": "书童",  "quest_type": "杀",  "time":  400,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"归云庄附近", "quest": "小菊",  "quest_type": "杀",  "time":  400,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"归云庄附近", "quest": "小兰",  "quest_type": "杀",  "time":  400,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 

(["quest_city":"古墓附近", "quest": "孙婆婆",  "quest_type": "杀",  "time":  400,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 

(["quest_city":"杭州附近", "quest": "红花会众",  "quest_type": "杀",  "time":  500,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"杭州附近", "quest": "绿营会众",  "quest_type": "杀",  "time":  500,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"杭州附近", "quest": "李沅芷",  "quest_type": "杀",  "time":  500,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"杭州附近", "quest": "庄允城",  "quest_type": "杀",  "time":  300,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 

(["quest_city":"恒山附近", "quest": "哑妇",  "quest_type": "杀",  "time":  500,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 

(["quest_city":"衡阳附近", "quest": "刘菁",  "quest_type": "杀",  "time":  500,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"衡阳附近", "quest": "刘芹",  "quest_type": "杀",  "time":  500,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"衡阳附近", "quest": "曲非烟",  "quest_type": "杀",  "time":  500,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"衡阳附近", "quest": "茶博士",  "quest_type": "杀",  "time":  300,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 

(["quest_city":"黄河附近", "quest": "老秀才",  "quest_type": "杀",  "time":  500,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 

(["quest_city":"华山附近", "quest": "小猴",  "quest_type": "杀",  "time":  350,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"华山附近", "quest": "翠花",  "quest_type": "杀",  "time":  350,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 

(["quest_city":"天龙寺附近", "quest": "扫地僧",  "quest_type": "杀",  "time":  350,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"天龙寺附近", "quest": "小沙弥",  "quest_type": "杀",  "time":  350,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"天龙寺附近", "quest": "护塔僧",  "quest_type": "杀",  "time":  350,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"天龙寺附近", "quest": "老年僧人",  "quest_type": "杀",  "time":  350,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"天龙寺附近", "quest": "扫地僧",  "quest_type": "杀",  "time":  350,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 

(["quest_city":"苏州附近", "quest": "小孩",  "quest_type": "杀",  "time":  350,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"苏州附近", "quest": "苏州女孩",  "quest_type": "杀",  "time":  350,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"苏州附近", "quest": "苏州少女",  "quest_type": "杀",  "time":  350,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"苏州附近", "quest": "游方和尚",  "quest_type": "杀",  "time":  350,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 

(["quest_city":"伊犁附近", "quest": "阿拉木罕",  "quest_type": "杀",  "time":  350,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"伊犁附近", "quest": "阿凡提",  "quest_type": "杀",  "time":  350,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"伊犁附近", "quest": "买卖提",  "quest_type": "杀",  "time":  350,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"伊犁附近", "quest": "波斯商人",  "quest_type": "杀",  "time":  350,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 

(["quest_city":"雪山寺附近", "quest": "央宗",  "quest_type": "杀",  "time":  350,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"雪山寺附近", "quest": "卓玛",  "quest_type": "杀",  "time":  350,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 

(["quest_city":"燕子坞附近", "quest": "阿朱",  "quest_type": "杀",  "time":  350,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 

(["quest_city":"峨嵋山附近", "quest": "道明小师父",  "quest_type": "杀",  "time":  350,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"峨嵋山附近", "quest": "文方小师太",  "quest_type": "杀",  "time":  350,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"峨嵋山附近", "quest": "文晖小师太",  "quest_type": "杀",  "time":  350,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"峨嵋山附近", "quest": "文清小师太",  "quest_type": "杀",  "time":  350,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"峨嵋山附近", "quest": "文音小师太",  "quest_type": "杀",  "time":  350,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 

(["quest_city":"丐帮附近", "quest": "江上游",  "quest_type": "杀",  "time":  350,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"丐帮附近", "quest": "快活三",  "quest_type": "杀",  "time":  350,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"丐帮附近", "quest": "李斧头",  "quest_type": "杀",  "time":  350,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"丐帮附近", "quest": "莫不收",  "quest_type": "杀",  "time":  350,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"丐帮附近", "quest": "裘万家",  "quest_type": "杀",  "time":  350,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"丐帮附近", "quest": "赵狗儿",  "quest_type": "杀",  "time":  350,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 

(["quest_city":"武当山附近", "quest": "道童",  "quest_type": "杀",  "time":  450,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"武当山附近", "quest": "明月",  "quest_type": "杀",  "time":  450,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"武当山附近", "quest": "清风",  "quest_type": "杀",  "time":  450,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"武当山附近", "quest": "守园道长",  "quest_type": "杀",  "time":  450,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
});

mapping query_quest()
{
    return quest[random(sizeof(quest))];
}
