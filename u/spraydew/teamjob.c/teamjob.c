int time_period(int timep,object me);
string  zuji(string str);
int ckiller=4;
#include <ansi.h>

mapping *lquest1 = ({
        ([      "quest_name":   "马超兴",  "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"扬州" ]),    	
        ([      "quest_name":   "武将",    "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"扬州" ]),    	
        ([      "quest_name":   "官兵",    "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"扬州" ]),    	
        ([      "quest_name":   "郭靖",    "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"襄阳" ]),    	
        ([      "quest_name":   "店小二",  "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"扬州" ]),    	
        ([      "quest_name":   "冼老板",  "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"扬州" ]),    	
        ([      "quest_name":   "王五",    "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"扬州" ]),    	
        ([      "quest_name":   "钱眼开",  "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"扬州" ]),    	
        ([      "quest_name":   "马夫",    "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"扬州" ]),    	
        ([      "quest_name":   "流氓",    "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"扬州" ]),    	
        ([      "quest_name":   "流氓头",  "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"扬州" ]),    	
        ([      "quest_name":   "朱熹",    "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"扬州" ]),    	
        ([      "quest_name":   "杨永福",  "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"扬州" ]),    	
        ([      "quest_name":   "曾柔",    "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"扬州" ]),    	
        ([      "quest_name":   "平一指",  "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"扬州" ]),    	
        ([      "quest_name":   "药铺伙计","exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"扬州" ]),    	
        ([      "quest_name":   "铁匠",    "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"扬州" ]),    	
        ([      "quest_name":   "挑夫",    "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"扬州" ]),    	
        ([      "quest_name":   "趟子手",  "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"北京" ]),    	
        ([      "quest_name":   "海公公",  "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"扬州" ]),    	
        ([      "quest_name":   "小桂子",  "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"扬州" ]),    	
        ([      "quest_name":   "程玉环",  "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"扬州" ]),    	
        ([      "quest_name":   "谭友纪",  "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"扬州" ]),    	
        ([      "quest_name":   "程药发",  "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"扬州" ]),    	
        ([      "quest_name":   "衙役",    "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"扬州" ]),    	
        ([      "quest_name":   "史青山",  "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"扬州" ]),    	
        ([      "quest_name":   "游方道人","exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"扬州" ]),    	
        ([      "quest_name":   "陈有德",  "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"扬州" ]),    	
        ([      "quest_name":   "家丁",    "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"扬州" ]),    	
        ([      "quest_name":   "管家",    "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"扬州" ]),    	
        ([      "quest_name":   "崔员外",  "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"扬州" ]),    	
        ([      "quest_name":   "崔莺莺",  "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"扬州" ]),    	
        ([      "quest_name":   "红娘",    "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"杭州" ]),    	
        ([      "quest_name":   "封弓影",  "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"扬州" ]),    	
        ([      "quest_name":   "慕容巡捕",    "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"扬州" ]),    	
        ([      "quest_name":   "桃花村长","exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"扬州" ]),    	
        ([      "quest_name":   "桃花童",  "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"扬州" ]),    	
        ([      "quest_name":   "男孩",    "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"扬州" ]),    	
        ([      "quest_name":   "赵敏",    "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"洛阳" ]),    	
        ([      "quest_name":   "孙三毁",  "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"洛阳" ]),    	
        ([      "quest_name":   "赵一伤",  "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"洛阳" ]),    	
        ([      "quest_name":   "钱二败",  "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"洛阳" ]),    	
        ([      "quest_name":   "李四摧",  "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"洛阳" ]),    	
        ([      "quest_name":   "吴六破",  "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"洛阳" ]),    	
        ([      "quest_name":   "周五输",  "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"洛阳" ]),    	
        ([      "quest_name":   "王八衰",  "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"洛阳" ]),    	
        ([      "quest_name":   "郑七灭",  "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"洛阳" ]),    	
        ([      "quest_name":   "史松",    "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"扬州" ]),    	
        ([      "quest_name":   "空空儿",  "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"扬州" ]),    	
        ([      "quest_name":   "韦小宝",  "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"扬州" ]),    	
        ([      "quest_name":   "唐楠",    "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"扬州" ]),    	
        ([      "quest_name":   "香菱",    "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"扬州" ]),    	
        ([      "quest_name":   "小混混",  "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"扬州" ]),    	
        ([      "quest_name":   "哈巴狗",  "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"扬州" ]),    	
        ([      "quest_name":   "胖头陀",  "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"扬州" ]),    	
        ([      "quest_name":   "段誉",    "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"扬州" ]),    	
        ([      "quest_name":   "阿庆嫂",  "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"扬州" ]),    	
        ([      "quest_name":   "韦春芳",  "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"扬州" ]),    	
        ([      "quest_name":   "龟公",    "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"扬州" ]),    	
        ([      "quest_name":   "茅十八",  "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"扬州" ]),    	
        ([      "quest_name":   "欧阳克",  "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"扬州" ]),    	
				([      "quest_name":  "何员外",  	"exp_bonus":random(10)+30,"pot_bonus": random(8)+10  ,"quest_city":"扬州" ]),    	
				([      "quest_name":  "阿珂",  		"exp_bonus":random(10)+30,"pot_bonus": random(8)+10  ,"quest_city":"扬州" ]),    	
				([      "quest_name":  "冷郁然", 	 	"exp_bonus":random(10)+30,"pot_bonus": random(8)+10  ,"quest_city":"扬州" ]),    	
				([      "quest_name":  "杨磊石",  	"exp_bonus":random(10)+30,"pot_bonus": random(8)+10  ,"quest_city":"扬州" ]),    	
				([      "quest_name":  "仇星星",    "exp_bonus":random(10)+30,"pot_bonus": random(8)+10  ,"quest_city":"扬州" ]),    	
				([      "quest_name":  "吴古贤",    "exp_bonus":random(10)+30,"pot_bonus": random(8)+10  ,"quest_city":"扬州" ]),    	
				([      "quest_name":  "顾月儿",		"exp_bonus":random(10)+30,"pot_bonus": random(8)+10  ,"quest_city":"扬州" ]),    	
				([      "quest_name":  "老婆婆",  	"exp_bonus":random(10)+30,"pot_bonus": random(8)+10  ,"quest_city":"扬州" ]),    	
				([      "quest_name":  "张不四",  	"exp_bonus":random(10)+30,"pot_bonus": random(8)+10  ,"quest_city":"扬州" ]),    	
				([      "quest_name":   "辛友清",  "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"扬州" ]),    	
			  ([			"quest_name":  "王家驹",   "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"洛阳" ]),    	
			  ([			"quest_name":  "易师爷",   "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"洛阳" ]),    	
			  ([			"quest_name":  "王仲强",  	"exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"洛阳" ]),    	
			  ([			"quest_name":  "拓跋玉",   "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"定襄" ]),    	
		 	  ([			"quest_name":  "墩欲谷",  	"exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"定襄" ]),    	
		 		([			"quest_name":  "周大夫",  	"exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"定襄" ]),    	
		 		([			"quest_name":  "吴老板",   	"exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"定襄" ]),    	
        ([      "quest_name":   "欧阳巡捕",    "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"扬州" ]),    	
        ([      "quest_name":   "公孙巡捕",    "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"扬州" ]),    	
        ([      "quest_name":   "紫云巡捕",    "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"扬州" ]),    	
        ([      "quest_name":   "玉虚子",    "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"关中" ]),    	
        ([      "quest_name":   "云清子",    "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"关中" ]),    	
        ([      "quest_name":   "张言成",    "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"关中" ]),    	
        ([      "quest_name":   "胡大掌柜",    "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"西藏" ]),    	
        ([      "quest_name":   "护寺藏尼",    "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"西藏" ]),    	
        ([      "quest_name":   "护寺喇嘛",    "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"西藏" ]),    	
        ([      "quest_name":   "城卫",    "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"西藏" ]),    	
        ([      "quest_name":   "裘逸",    "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"金陵" ]),    	
        ([      "quest_name":   "王乞儿",    "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"金陵" ]),    	
        ([      "quest_name":   "萧之羽",    "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"金陵" ]),    	
        ([      "quest_name":                "文泰来",           "exp_bonus":random(10)+30,"pot_bonus": random(8)+10 ,"quest_city":"杭州" ]),    	
        ([      "quest_name":                "阿拉木罕",         "exp_bonus":random(10)+30,"pot_bonus": random(8)+10 ,"quest_city":"天山" ]),    	
        ([      "quest_name":                "买卖提",           "exp_bonus":random(10)+30,"pot_bonus": random(8)+10 ,"quest_city":"天山" ]),    	
        ([      "quest_name":                "阿凡提",           "exp_bonus":random(10)+30,"pot_bonus": random(8)+10 ,"quest_city":"天山" ]),    	
        ([      "quest_name":                "巴依",             "exp_bonus":random(10)+30,"pot_bonus": random(8)+10 ,"quest_city":"天山" ]),    	
        ([      "quest_name":                "侯员外",           "exp_bonus":random(10)+30,"pot_bonus": random(8)+10 ,"quest_city":"武功镇" ]),    	
        ([      "quest_name":                "刘菁",             "exp_bonus":random(10)+30,"pot_bonus": random(8)+10 ,"quest_city":"衡阳" ]),    	
        ([      "quest_name":                "刘芹",             "exp_bonus":random(10)+30,"pot_bonus": random(8)+10 ,"quest_city":"衡阳" ]),    	
        ([      "quest_name":                "刘夫人",           "exp_bonus":random(10)+30,"pot_bonus": random(8)+10 ,"quest_city":"衡阳" ]),    	
        ([      "quest_name":                "刘正风",           "exp_bonus":random(10)+30,"pot_bonus": random(8)+10 ,"quest_city":"衡阳" ]),    	
        ([      "quest_name":                "曲非烟",           "exp_bonus":random(10)+30,"pot_bonus": random(8)+10 ,"quest_city":"衡阳" ]),    	
        ([      "quest_name":                "曲洋",             "exp_bonus":random(10)+30,"pot_bonus": random(8)+10 ,"quest_city":"衡阳" ]),    	
        ([      "quest_name":                "舞蛇人", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"北京" ]),    	
        ([      "quest_name":                "刀客",  "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"北京" ]),    	
        ([      "quest_name":                "剑客",   "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"北京" ]),    	
        ([      "quest_name":                "关安基",  "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"北京" ]),    	
        ([      "quest_name":                "李力世",     "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"北京" ]),    	
        ([      "quest_name":                "屠宰场伙计",   "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"北京" ]),    	
        ([      "quest_name":                "小贩",       "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"北京" ]),    	
        ([      "quest_name":                "贾老六",     "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"北京" ]),    	
        ([      "quest_name":                "游客",      "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"北京" ]),    	
        ([      "quest_name":                "游方和尚",   "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"北京" ]),    	
        ([      "quest_name":                "胡掌柜",     "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"北京" ]),    	
        ([      "quest_name":                "江湖豪客",   "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"北京" ]),    	
        ([      "quest_name":                "高彦超",      "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"北京" ]),    	
        ([      "quest_name":                "小流氓",      "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"北京" ]),    	
        ([      "quest_name":                "地痞",        "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"北京" ]),    	
        ([      "quest_name":                "掌柜",        "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"北京" ]),    	
        ([      "quest_name":                "客店伙计",    "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"北京" ]),    	
        ([      "quest_name":                "吴六奇",      "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"北京" ]),    	
        ([      "quest_name":                "瘦头陀",      "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"北京" ]),    	
        ([      "quest_name":                "书生",        "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"北京" ]),    	
        ([      "quest_name":                "顾炎武",      "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"北京" ]),    	
        ([      "quest_name":                "李可秀",           "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"杭州" ]),    	
        ([      "quest_name":                "胡庆余",           "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"杭州" ]),    	
        ([      "quest_name":                "张召重",           "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"杭州" ]),    	
        ([      "quest_name":                "耶律齐",           "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"襄阳" ]),    	
        ([      "quest_name":                "黄蓉",             "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"襄阳" ]),    	
        ([      "quest_name":                "武三通",           "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"襄阳" ]),    	
        ([      "quest_name":                "武修文",           "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"襄阳" ]),    	
        ([      "quest_name":                "朱子柳",           "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"襄阳" ]),    	
});

mapping *lquest2 = ({
        ([      "quest_name":                "舞蛇人", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"北京" ]),    	
        ([      "quest_name":                "刀客",  "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"北京" ]),    	
        ([      "quest_name":                "剑客",   "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"北京" ]),    	
        ([      "quest_name":                "关安基",  "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"北京" ]),    	
        ([      "quest_name":                "李力世",     "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"北京" ]),    	
        ([      "quest_name":                "屠宰场伙计",   "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"北京" ]),    	
        ([      "quest_name":                "小贩",       "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"北京" ]),    	
        ([      "quest_name":                "贾老六",     "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"北京" ]),    	
        ([      "quest_name":                "游客",      "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"北京" ]),    	
        ([      "quest_name":                "游方和尚",   "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"北京" ]),    	
        ([      "quest_name":                "胡掌柜",     "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"北京" ]),    	
        ([      "quest_name":                "江湖豪客",   "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"北京" ]),    	
        ([      "quest_name":                "高彦超",      "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"北京" ]),    	
        ([      "quest_name":                "小流氓",      "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"北京" ]),    	
        ([      "quest_name":                "地痞",        "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"北京" ]),    	
        ([      "quest_name":                "掌柜",        "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"北京" ]),    	
        ([      "quest_name":                "客店伙计",    "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"北京" ]),    	
        ([      "quest_name":                "吴六奇",      "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"北京" ]),    	
        ([      "quest_name":                "瘦头陀",      "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"北京" ]),    	
        ([      "quest_name":                "书生",        "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"北京" ]),    	
        ([      "quest_name":                "顾炎武",      "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"北京" ]),    	
        ([      "quest_name":                "萧远山",      "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"关外" ]),    	
        ([      "quest_name":                "冯锡范",      "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"北京" ]),    	
        ([      "quest_name":                "太监",        "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"北京" ]),    	
        ([      "quest_name":                "卖花姑娘",    "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"北京" ]),    	
        ([      "quest_name":                "侍卫",        "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"北京" ]),    	
        ([      "quest_name":                "白龟寿",      "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"王盘山岛" ]),    	
        ([      "quest_name":                "钱老本",       "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"北京" ]),    	
        ([      "quest_name":                "土匪",        "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"北京" ]),    	
        ([      "quest_name":                "挑夫",        "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"北京" ]),    	
        ([      "quest_name":                "贡唐仓国师",  "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"北京" ]),    	
        ([      "quest_name":                "徐天川",      "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"北京" ]),    	
        ([      "quest_name":                "桑三娘",      "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"黑木崖" ]),    	
        ([      "quest_name":                "沈青刚",      "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"黄河九曲" ]),    	
        ([      "quest_name":                "马青雄",      "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"黄河九曲" ]),    	
        ([      "quest_name":                "吴青烈",      "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"黄河九曲" ]),    	
        ([      "quest_name":                "薛慕华",      "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"逍遥" ]),    	
        ([      "quest_name":                "康广陵",      "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"逍遥" ]),    	
        ([      "quest_name":                "蒙面人",      "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"逍遥" ]),    	
        ([      "quest_name":                "苏星河",      "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"逍遥" ]),    	
        ([      "quest_name":                "苟读",        "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"逍遥" ]),    	
        ([      "quest_name":                "钱青健",      "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"黄河九曲" ]),    	
        ([      "quest_name":                "彭连虎",      "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"黄河九曲" ]),    	
        ([      "quest_name":                "陆冠英",      "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"归云庄" ]),    	
        ([      "quest_name":                "裘千丈",      "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"铁掌帮" ]),    	
        ([      "quest_name":                "翠花",        "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"武功镇" ]),    	
        ([      "quest_name":                "地保",        "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"武功镇" ]),    	
        ([      "quest_name":                "李四",        "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"武功镇" ]),    	
        ([      "quest_name":                "沙通天",      "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"黄河九曲" ]),    	
        ([      "quest_name":                "梁子翁",      "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"黄河九曲" ]),    	
        ([      "quest_name":                "侯通海",      "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"黄河九曲" ]),    	
        ([      "quest_name":                "大汉",       "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"黄河九曲" ]),    	
        ([      "quest_name":                "老者",        "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"黑木崖" ]),    	
        ([      "quest_name":                "老鸨婆",      "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"北京" ]),    	
        ([      "quest_name":                "老和尚",      "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"北京" ]),    	
        ([      "quest_name":                "程老板",      "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"北京" ]),    	
        ([      "quest_name":                "乐厚",        "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"嵩山" ]),    	
        ([      "quest_name":                "天松道人",    "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"泰山" ]),    	
        ([      "quest_name":                "天柏道人",    "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"泰山" ]),    	
        ([      "quest_name":                "祖千秋",      "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"黄河九曲" ]),    	
        ([      "quest_name":                "单正",        "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"黄河九曲" ]),    	
        ([      "quest_name":                "天乙道人",    "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"泰山" ]),    	
        ([      "quest_name":                "小孩",        "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"扬州" ]),    	
        ([      "quest_name":                "虚通",        "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"少林" ]),    	
        ([      "quest_name":                "虚明",        "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"少林" ]),    	
        ([      "quest_name":                "李莫愁",      "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"嘉兴" ]),    	
        ([      "quest_name":                "定静师太",    "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"恒山" ]),    	
        ([      "quest_name":                "仪文",        "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"恒山" ]),    	
        ([      "quest_name":                "冯铁匠",      "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"华山村" ]),    	
        ([      "quest_name":                "老船夫",      "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"北京" ]),    	
		 (["quest_name":  "王家驹",  "exp_bonus":random(15)+30,"pot_bonus": random(8)+10  ,"quest_city":"洛阳" ]),    	
		 (["quest_name":  "易师爷",  "exp_bonus":random(15)+30,"pot_bonus": random(8)+10  ,"quest_city":"洛阳" ]),    	
		 (["quest_name":  "王仲强",  "exp_bonus":random(15)+30,"pot_bonus": random(8)+10  ,"quest_city":"洛阳" ]),    	
		 (["quest_name":  "拓跋玉",  "exp_bonus":random(15)+30,"pot_bonus": random(8)+10  ,"quest_city":"定襄" ]),    	
		 (["quest_name":  "墩欲谷",  "exp_bonus":random(15)+30,"pot_bonus": random(8)+10  ,"quest_city":"定襄" ]),    	
		 (["quest_name":  "结社率",  "exp_bonus":random(15)+30,"pot_bonus": random(8)+10  ,"quest_city":"定襄" ]),    	
		 (["quest_name":  "毕玄",  "exp_bonus":random(15)+30,"pot_bonus": random(8)+10  ,"quest_city":"定襄" ]),    	
		 (["quest_name":  "王药师",  "exp_bonus":random(15)+30,"pot_bonus": random(8)+10  ,"quest_city":"碎叶" ]),    	
		 (["quest_name":  "孟老板",  "exp_bonus":random(15)+30,"pot_bonus": random(8)+10  ,"quest_city":"碎叶" ]),    	
		 (["quest_name":  "秦掌柜",  "exp_bonus":random(15)+30,"pot_bonus": random(8)+10  ,"quest_city":"碎叶" ]),    	
		 (["quest_name":  "周逸风",  "exp_bonus":random(15)+30,"pot_bonus": random(8)+10  ,"quest_city":"碎叶" ]),    	
		 (["quest_name":  "校尉",  "exp_bonus":random(15)+30,"pot_bonus": random(8)+10  ,"quest_city":"关中" ]),    	
		 (["quest_name":  "福建客商",  "exp_bonus":random(15)+30,"pot_bonus": random(8)+10  ,"quest_city":"关中" ]),    	
		 (["quest_name":  "鱼贩子",  "exp_bonus":random(15)+30,"pot_bonus": random(8)+10  ,"quest_city":"关中" ]),    	
		 (["quest_name":  "莫飞云",  "exp_bonus":random(15)+30,"pot_bonus": random(8)+10  ,"quest_city":"关中" ]),    	
		 (["quest_name":  "张天有",  "exp_bonus":random(15)+30,"pot_bonus": random(8)+10  ,"quest_city":"大同" ]),    	
		 (["quest_name":  "巧手妹妹",  "exp_bonus":random(15)+30,"pot_bonus": random(8)+10  ,"quest_city":"大同" ]),    	
		 (["quest_name":  "胡迈",  "exp_bonus":random(15)+30,"pot_bonus": random(8)+10  ,"quest_city":"大同" ]),    	
		 (["quest_name":  "任一力",  "exp_bonus":random(15)+30,"pot_bonus": random(8)+10  ,"quest_city":"大同" ]),    	
		 (["quest_name":  "刘铁",  "exp_bonus":random(15)+30,"pot_bonus": random(8)+10  ,"quest_city":"大同" ]),    	
		 (["quest_name":  "黄富贵",  "exp_bonus":random(15)+30,"pot_bonus": random(8)+10  ,"quest_city":"大同" ]),    	
		 (["quest_name":  "谢琳",  "exp_bonus":random(15)+30,"pot_bonus": random(8)+10  ,"quest_city":"雁荡" ]),    	
		 (["quest_name":  "落雁老人",  "exp_bonus":random(15)+30,"pot_bonus": random(8)+10  ,"quest_city":"雁荡" ]),    	
		 (["quest_name":  "铁桥三",  "exp_bonus":random(15)+30,"pot_bonus": random(8)+10  ,"quest_city":"雁荡" ]),    	
		 (["quest_name":  "猿长老",  "exp_bonus":random(15)+30,"pot_bonus": random(8)+10  ,"quest_city":"雁荡" ]),    	
		 (["quest_name":  "李老板",  "exp_bonus":random(15)+30,"pot_bonus": random(8)+10  ,"quest_city":"太原" ]),    	
		 (["quest_name":  "李店主",  "exp_bonus":random(15)+30,"pot_bonus": random(8)+10  ,"quest_city":"太原" ]),    	
		 (["quest_name":  "民工",  "exp_bonus":random(15)+30,"pot_bonus": random(8)+10  ,"quest_city":"太原" ]),    	
		 (["quest_name":  "断肠人",  "exp_bonus":random(15)+30,"pot_bonus": random(8)+10  ,"quest_city":"济南" ]),    	
		 (["quest_name":  "殷羡",  "exp_bonus":random(15)+30,"pot_bonus": random(8)+10  ,"quest_city":"济南" ]),    	
		 (["quest_name":  "苏蓉蓉",  "exp_bonus":random(15)+30,"pot_bonus": random(8)+10  ,"quest_city":"济南" ]),    	
});

mapping *lquest3 = ({
        ([      "quest_name":                "甄有庆",     "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"苏州" ]),    	
        ([      "quest_name":                "史镖头",     "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"福州" ]),    	
        ([      "quest_name":                "陈阿婆",     "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"福州" ]),    	
        ([      "quest_name":                "老朝奉",     "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"佛山" ]),    	
        ([      "quest_name":                "小贼",         "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"成都" ]),    	
        ([      "quest_name":                "鲁连荣",     "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"衡山" ]),    	
        ([      "quest_name":                "牙将",             "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"襄阳" ]),    	
        ([      "quest_name":                "黄真",             "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"襄阳" ]),    	
        ([      "quest_name":                "文泰来",           "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"杭州" ]),    	
        ([      "quest_name":                "阿拉木罕",         "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"天山" ]),    	
        ([      "quest_name":                "买卖提",           "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"天山" ]),    	
        ([      "quest_name":                "阿凡提",           "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"天山" ]),    	
        ([      "quest_name":                "巴依",             "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"天山" ]),    	
        ([      "quest_name":                "侯员外",           "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"武功镇" ]),    	
        ([      "quest_name":                "刘菁",             "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"衡阳" ]),    	
        ([      "quest_name":                "刘芹",             "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"衡阳" ]),    	
        ([      "quest_name":                "刘夫人",           "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"衡阳" ]),    	
        ([      "quest_name":                "刘正风",           "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"衡阳" ]),    	
        ([      "quest_name":                "曲非烟",           "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"衡阳" ]),    	
        ([      "quest_name":                "曲洋",             "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"衡阳" ]),    	
        ([      "quest_name":                "骆冰",             "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"杭州" ]),    	
        ([      "quest_name":                "米为义",           "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"衡阳" ]),    	
        ([      "quest_name":                "向大年",           "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"衡阳" ]),    	
        ([      "quest_name":                "田伯光",           "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"衡阳" ]),    	
        ([      "quest_name":                "仪琳",             "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"衡阳" ]),    	
        ([      "quest_name":                "茶博士",           "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"衡阳" ]),    	
        ([      "quest_name":                "西夏兵",     "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"黄河九曲" ]),    	
        ([      "quest_name":                "李可秀",           "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"杭州" ]),    	
        ([      "quest_name":                "胡庆余",           "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"杭州" ]),    	
        ([      "quest_name":                "张召重",           "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"杭州" ]),    	
        ([      "quest_name":                "耶律齐",           "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"襄阳" ]),    	
        ([      "quest_name":                "黄蓉",             "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"襄阳" ]),    	
        ([      "quest_name":                "武三通",           "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"襄阳" ]),    	
        ([      "quest_name":                "武修文",           "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"襄阳" ]),    	
        ([      "quest_name":                "朱子柳",           "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"襄阳" ]),    	
        ([      "quest_name":                "郭芙",             "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"襄阳" ]),    	
        ([      "quest_name":                "木匠",             "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"襄阳" ]),    	
        ([      "quest_name":                "偏将",             "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"襄阳" ]),    	
        ([      "quest_name":                "佐将",             "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"襄阳" ]),    	
        ([      "quest_name":                "宋兵",             "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"襄阳" ]),    	
        ([      "quest_name":                "高丽商",           "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"襄阳" ]),    	
        ([      "quest_name":                "书店老板",         "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"襄阳" ]),    	
        ([      "quest_name":                "申人俊",           "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"襄阳" ]),    	
        ([      "quest_name":                "武敦儒",           "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"襄阳" ]),    	
        ([      "quest_name":                "吉人通",           "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"襄阳" ]),    	
        ([      "quest_name":                "唐槐",             "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"成都" ]),    	
        ([      "quest_name":                "刘虹瑛",           "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"成都" ]),    	
        ([      "quest_name":                "萧飞",             "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"成都" ]),    	
        ([      "quest_name":                "陈浒",             "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"成都" ]),    	
        ([      "quest_name":                "龙铨",             "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"成都" ]),    	
        ([      "quest_name":                "马五德",           "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"成都" ]),    	
        ([      "quest_name":                "账房老夫子",       "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"成都" ]),    	
        ([      "quest_name":                "本参",         "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"天龙寺" ]),    	
        ([      "quest_name":                "本相",         "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"天龙寺" ]),    	
        ([      "quest_name":                "本尘",         "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"天龙寺" ]),    	
        ([      "quest_name":                "本观",         "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"天龙寺" ]),    	
        ([      "quest_name":                "枯荣大师",     "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"天龙寺" ]),    	
        ([      "quest_name":                "本因",         "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"天龙寺" ]),    	
        ([      "quest_name":                "猎人",         "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"大理" ]),    	
        ([      "quest_name":                "陪从",         "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"大理" ]),    	
        ([      "quest_name":                "高升泰",       "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"大理" ]),    	
        ([      "quest_name":                "素衣卫士",     "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"大理" ]),    	
        ([      "quest_name":                "采笋人",       "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"大理" ]),    	
        ([      "quest_name":                "士兵",         "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"大理" ]),    	
        ([      "quest_name":                "族头人",       "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"大理" ]),    	
        ([      "quest_name":                "侍从",         "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"大理" ]),    	
        ([      "quest_name":                "大土司",       "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"大理" ]),    	
        ([      "quest_name":                "歌女",         "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"大理" ]),    	
        ([      "quest_name":                "何红药",       "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"大理" ]),    	
        ([      "quest_name":                "薛老板",       "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"大理" ]),    	
        ([      "quest_name":                "石匠",         "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"大理" ]),    	
        ([      "quest_name":                "黄衣卫士",     "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"大理" ]),    	
        ([      "quest_name":                "褚万里",       "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"大理" ]),    	
        ([      "quest_name":                "傅思归",       "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"大理" ]),    	
        ([      "quest_name":                "锦衣卫士",     "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"大理" ]),    	
        ([      "quest_name":                "太监",       "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"大理" ]),    	
        ([      "quest_name":                "宫女",       "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"大理" ]),    	
        ([      "quest_name":                "神农帮弟子",   "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"大理" ]),    	
        ([      "quest_name":                "无量剑弟子",   "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"大理" ]),    	
        ([      "quest_name":                "凤一鸣",     "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"佛山" ]),    	
        ([      "quest_name":                "黄衣使者",   "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"佛山" ]),    	
        ([      "quest_name":                "渔夫",       "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"佛山" ]),    	
        ([      "quest_name":                "瘦商人",     "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"佛山" ]),    	
        ([      "quest_name":                "胖商人",     "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"佛山" ]),    	
        ([      "quest_name":                "凤七",       "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"佛山" ]),    	
        ([      "quest_name":                "张朝唐",     "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"佛山" ]),    	
        ([      "quest_name":                "张康",       "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"佛山" ]),    	
        ([      "quest_name":                "常金鹏",     "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"泉州" ]),    	
        ([      "quest_name":                "游讯",       "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"泉州" ]),    	
        ([      "quest_name":                "卜沉",       "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"嵩山" ]),    	
        ([      "quest_name":                "沙天江",     "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"嵩山" ]),    	
        ([      "quest_name":                "戈什哈",     "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"福州" ]),    	
        ([      "quest_name":                "老和尚",     "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"杭州" ]),    	
        ([      "quest_name":                "林震南",     "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"福州" ]),    	
        ([      "quest_name":                "余人彦",     "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"青城山" ]),    	
        ([      "quest_name":                "贾人达",     "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"青城山" ]),    	
        ([      "quest_name":                "崔镖头",     "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"福州" ]),    	
        ([      "quest_name":                "阿碧",       "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"慕容山庄" ]),    	
        ([      "quest_name":                "冯正东",     "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"苏州" ]),    	
        ([      "quest_name":                "阿朱",       "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"慕容山庄" ]),    	
		 (["quest_name":  "风波恶",  "exp_bonus":random(20)+30,"pot_bonus": random(10)+10  ,"quest_city":"燕子坞" ]),    	
		 (["quest_name":  "包不同",  "exp_bonus":random(20)+30,"pot_bonus": random(10)+10  ,"quest_city":"燕子坞" ]),    	
		 (["quest_name":  "王夫人",  "exp_bonus":random(20)+30,"pot_bonus": random(10)+10  ,"quest_city":"燕子坞" ]),    	
		 (["quest_name":  "王语嫣",  "exp_bonus":random(20)+30,"pot_bonus": random(10)+10  ,"quest_city":"燕子坞" ]),    	
		 (["quest_name":  "邓百川",  "exp_bonus":random(20)+30,"pot_bonus": random(10)+10  ,"quest_city":"燕子坞" ]),    	
	 (["quest_name":  "边军官兵",  "exp_bonus":random(20)+30,"pot_bonus": random(10)+10  ,"quest_city":"定襄" ]),    	
	 (["quest_name":  "边军武将",  "exp_bonus":random(20)+30,"pot_bonus": random(10)+10  ,"quest_city":"定襄" ]),    	    	
		 (["quest_name":  "马大嫂",  "exp_bonus":random(20)+30,"pot_bonus": random(10)+10  ,"quest_city":"盛京" ]),    	
		 (["quest_name":  "范文程",  "exp_bonus":random(20)+30,"pot_bonus": random(10)+10  ,"quest_city":"盛京" ]),    	
		 (["quest_name":  "李大姐",  "exp_bonus":random(20)+30,"pot_bonus": random(10)+10  ,"quest_city":"盛京" ]),    	
		 (["quest_name":  "多尔衮",  "exp_bonus":random(20)+30,"pot_bonus": random(10)+10  ,"quest_city":"盛京" ]),    	
		 (["quest_name":  "海兰珠",  "exp_bonus":random(20)+30,"pot_bonus": random(10)+10  ,"quest_city":"盛京" ]),    	
		 (["quest_name":  "王家驹",  "exp_bonus":random(20)+30,"pot_bonus": random(10)+10  ,"quest_city":"洛阳" ]),    	
		 (["quest_name":  "易师爷",  "exp_bonus":random(20)+30,"pot_bonus": random(10)+10  ,"quest_city":"洛阳" ]),    	
		 (["quest_name":  "王仲强",  "exp_bonus":random(20)+30,"pot_bonus": random(10)+10  ,"quest_city":"洛阳" ]),    	
		 (["quest_name":  "方穷",  "exp_bonus":random(20)+30,"pot_bonus": random(10)+10  ,"quest_city":"南少林" ]),    	
		 (["quest_name":  "元悲",  "exp_bonus":random(20)+30,"pot_bonus": random(10)+10  ,"quest_city":"南少林" ]),    	
		 (["quest_name":  "方戒",  "exp_bonus":random(20)+30,"pot_bonus": random(10)+10  ,"quest_city":"南少林" ]),    	
		 (["quest_name":  "大痍大师",  "exp_bonus":random(20)+30,"pot_bonus": random(10)+10  ,"quest_city":"南少林" ]),    	
		 (["quest_name":  "大痕大师",  "exp_bonus":random(20)+30,"pot_bonus": random(10)+10  ,"quest_city":"南少林" ]),    	
		 (["quest_name":  "元忍",  "exp_bonus":random(20)+30,"pot_bonus": random(10)+10  ,"quest_city":"南少林" ]),    	
		 (["quest_name":  "元惑",  "exp_bonus":random(20)+30,"pot_bonus": random(10)+10  ,"quest_city":"南少林" ]),    	
		 (["quest_name":  "元恙",  "exp_bonus":random(20)+30,"pot_bonus": random(10)+10  ,"quest_city":"南少林" ]),    	
		 (["quest_name":  "大苦大师",  "exp_bonus":random(20)+30,"pot_bonus": random(10)+10  ,"quest_city":"南少林" ]),    	
		 (["quest_name":  "醉汉",  "exp_bonus":random(20)+30,"pot_bonus": random(10)+10  ,"quest_city":"长沙" ]),    	
		 (["quest_name":  "乔老板",  "exp_bonus":random(20)+30,"pot_bonus": random(10)+10  ,"quest_city":"长沙" ]),    	
		 (["quest_name":  "宋大夫",  "exp_bonus":random(20)+30,"pot_bonus": random(10)+10  ,"quest_city":"长沙" ]),    	
		 (["quest_name":  "妙龄少女",  "exp_bonus":random(20)+30,"pot_bonus": random(10)+10  ,"quest_city":"长沙" ]),    	
		 (["quest_name":  "屠小娇",  "exp_bonus":random(20)+30,"pot_bonus": random(10)+10  ,"quest_city":"恶人谷" ]),    	
		 (["quest_name":  "胡药师",  "exp_bonus":random(20)+30,"pot_bonus": random(10)+10  ,"quest_city":"恶人谷" ]),    	
		 (["quest_name":  "铁萍姑",  "exp_bonus":random(20)+30,"pot_bonus": random(10)+10  ,"quest_city":"恶人谷" ]),    	
		 (["quest_name":  "王小路",  "exp_bonus":random(20)+30,"pot_bonus": random(10)+10  ,"quest_city":"恶人谷" ]),    	
});

mapping *lquest4 = ({
        ([      "quest_name":                "忽伦大虎",        "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"关外" ]),    	
       ([      "quest_name":                "忽伦二虎",        "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"关外" ]),    	
       ([      "quest_name":                "忽伦三虎",        "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"关外" ]),    	
       ([      "quest_name":                "忽伦四虎",        "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"关外" ]),    	
       ([      "quest_name":                "红毛鬼",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"台湾" ]),    	
       ([      "quest_name":                "刘国轩",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"台湾" ]),    	
       ([      "quest_name":                "莫大",            "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"衡山" ]),    	
       ([      "quest_name":                "纪晓芙",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"峨嵋" ]),    	
        ([      "quest_name":                "静玄师太",      "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"峨嵋" ]),    	
        ([      "quest_name":                "静和师太",      "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"峨嵋" ]),    	
        ([      "quest_name":                "文晖小师太",    "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"峨嵋" ]),    	
        ([      "quest_name":                "文清小师太",    "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"峨嵋" ]),    	
        ([      "quest_name":                "静心师太",      "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"峨嵋" ]),    	
        ([      "quest_name":                "贝锦仪",        "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"峨嵋" ]),    	
        ([      "quest_name":                "静玄师太",      "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"峨嵋" ]),    	
        ([      "quest_name":                "静迦师太",      "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"峨嵋" ]),    	
        ([      "quest_name":                "赵灵珠",        "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"峨嵋" ]),    	
        ([      "quest_name":                "李明霞",        "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"峨嵋" ]),    	
        ([      "quest_name":                "静慧师太",        "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"峨嵋" ]),    	
        ([      "quest_name":                "静闲师太",        "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"峨嵋" ]),    	
        ([      "quest_name":                "静照师太",        "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"峨嵋" ]),    	
        ([      "quest_name":                "静真师太",        "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"峨嵋" ]),    	
        ([      "quest_name":                "方碧琳",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"峨嵋" ]),    	
        ([      "quest_name":                "张松溪",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"武当" ]),    	
        ([      "quest_name":                "殷梨亭",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"武当" ]),    	
        ([      "quest_name":                "宋远桥",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"武当" ]),    	
        ([      "quest_name":                "俞莲舟",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"武当" ]),    	
        ([      "quest_name":                "谷虚道长",        "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"武当" ]),    	
        ([      "quest_name":                "张三丰",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"武当" ]),    	
        ([      "quest_name":                "清虚道长",        "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"武当" ]),    	
        ([      "quest_name":                "莫声谷",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"武当" ]),    	
       ([      "quest_name":                "钟万仇",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"万劫谷" ]),    	
       ([      "quest_name":                "甘宝宝",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"万劫谷" ]),    	
       ([      "quest_name":                "钟灵",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"万劫谷" ]),    	
       ([      "quest_name":                "陆乘风",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"归云庄" ]),    	
       ([      "quest_name":                "韩宝驹",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"归云庄" ]),    	
       ([      "quest_name":                "韩小莹",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"归云庄" ]),    	
       ([      "quest_name":                "柯镇恶",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"归云庄" ]),    	
       ([      "quest_name":                "全金发",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"归云庄" ]),    	
       ([      "quest_name":                "张阿生",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"归云庄" ]),    	
       ([      "quest_name":                "南希仁",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"归云庄" ]),    	
       ([      "quest_name":                "朱聪",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"归云庄" ]),    	
       ([      "quest_name":                "黄药师",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"桃花岛" ]),    	
       ([      "quest_name":                "余沧海",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"青城山" ]),    	
       ([      "quest_name":                "侯人英",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"青城山" ]),    	
       ([      "quest_name":                "洪人雄",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"青城山" ]),    	
       ([      "quest_name":                "张无忌",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"明教" ]),    	
       ([      "quest_name":                "殷野王",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"明教" ]),    	
       ([      "quest_name":                "拓跋",            "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"明教" ]),    	
       ([      "quest_name":                "辛然",            "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"明教" ]),    	
       ([      "quest_name":                "胡青牛",            "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"明教" ]),    	
       ([      "quest_name":                "颜垣",            "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"明教" ]),    	
       ([      "quest_name":                "唐洋",            "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"明教" ]),    	
       ([      "quest_name":                "庄铮",            "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"明教" ]),    	
       ([      "quest_name":                "接引使",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"明教" ]),    	
       ([      "quest_name":                "高山王",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"明教" ]),    	
       ([      "quest_name":                "巫士",            "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"明教" ]),    	
       ([      "quest_name":                "赵志敬",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"全真" ]),    	
       ([      "quest_name":                "尹志平",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"全真" ]),    	
       ([      "quest_name":                "小龙女",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"古墓" ]),    	
       ([      "quest_name":                "孙婆婆",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"古墓" ]),    	
       ([      "quest_name":                "林朝英",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"古墓" ]),    	
       ([      "quest_name":                "皮清玄",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"全真" ]),    	
       ([      "quest_name":                "姬清虚",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"全真" ]),    	
       ([      "quest_name":                "陈志益",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"全真" ]),    	
       ([      "quest_name":                "宝象",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"血刀门" ]),    	
       ([      "quest_name":                "血刀老祖",      "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"血刀门" ]),    	
       ([      "quest_name":                "胜谛",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"血刀门" ]),    	
       ([      "quest_name":                "央宗",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"血刀门" ]),    	
       ([      "quest_name":                "卓玛",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"血刀门" ]),    	
       ([      "quest_name":                "萨木活佛",      "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"雪山寺" ]),    	
       ([      "quest_name":                "嘉木活佛",      "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"雪山寺" ]),    	
       ([      "quest_name":                "拉章活佛",      "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"雪山寺" ]),    	
       ([      "quest_name":                "葛伦布",        "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"雪山寺" ]),    	
       ([      "quest_name":                "侍锤",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"雪山" ]),    	
       ([      "quest_name":                "善勇",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"血刀门" ]),    	
       ([      "quest_name":                "花铁干",        "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"血刀门" ]),    	
       ([      "quest_name":                "刘承风",        "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"血刀门" ]),    	
       ([      "quest_name":                "水岱",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"血刀门" ]),    	
       ([      "quest_name":                "陆天抒",        "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"血刀门" ]),    	
       ([      "quest_name":                "山贼头",        "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"白驼" ]),    	
       ([      "quest_name":                "花花公子",        "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"白驼" ]),    	
       ([      "quest_name":                "欧阳锋",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"白驼" ]),    	
       ([      "quest_name":                "小青",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"白驼" ]),    	
       ([      "quest_name":                "教练",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"白驼" ]),    	
       ([      "quest_name":                "李教头",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"白驼" ]),    	
       ([      "quest_name":                "管家",            "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"白驼" ]),    	
       ([      "quest_name":                "老材",            "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"白驼" ]),    	
       ([      "quest_name":                "白衣少女",        "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"白驼" ]),    	
       ([      "quest_name":                "张妈",            "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"白驼" ]),    	
       ([      "quest_name":                "白兔",            "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"白驼" ]),    	
       ([      "quest_name":                "门卫",            "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"白驼" ]),    	
       ([      "quest_name":                "兰剑",            "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"灵鹫宫" ]),    	
       ([      "quest_name":                "梅剑",            "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"灵鹫宫" ]),    	
       ([      "quest_name":                "余婆婆",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"灵鹫宫" ]),    	
       ([      "quest_name":                "九翼道人",        "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"灵鹫宫" ]),    	
       ([      "quest_name":                "出尘子",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"星宿海" ]),    	
       ([      "quest_name":                "采花子",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"星宿海" ]),    	
       ([      "quest_name":                "丁春秋",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"星宿海" ]),    	
       ([      "quest_name":                "阿紫",            "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"星宿海" ]),    	
       ([      "quest_name":                "摘星子",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"星宿海" ]),    	
       ([      "quest_name":                "狮吼子",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"星宿海" ]),    	
       ([      "quest_name":                "建除道人",        "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"泰山" ]),    	
       ([      "quest_name":                "玉磬子",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"泰山" ]),    	
       ([      "quest_name":                "玉音子",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"泰山" ]),    	
       ([      "quest_name":                "玉玑子",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"泰山" ]),    	
       ([      "quest_name":                "江百胜",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"泰山" ]),    	
       ([      "quest_name":                "天门道人",        "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"泰山" ]),    	
       ([      "quest_name":                "岳夫人",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"华山" ]),    	
       ([      "quest_name":                "施戴子",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"华山" ]),    	
       ([      "quest_name":                "岳不群",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"华山" ]),    	
       ([      "quest_name":                "岳灵珊",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"华山" ]),    	
       ([      "quest_name":                "高根明",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"华山" ]),    	
       ([      "quest_name":                "梁发",            "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"华山" ]),    	
       ([      "quest_name":                "公平子",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"华山" ]),    	
       ([      "quest_name":                "劳德诺",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"华山" ]),    	
       ([      "quest_name":                "令狐冲",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"华山" ]),    	
       ([      "quest_name":                "叶二娘",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"灵州" ]),    	
       ([      "quest_name":                "南海鳄神",        "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"灵州" ]),    	
       ([      "quest_name":                "石人武士",        "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"灵州" ]),    	
       ([      "quest_name":                "皇宫卫士",        "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"灵州" ]),    	
       ([      "quest_name":                "黄伯流",        "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"黑木崖" ]),    	
       ([      "quest_name":                "一品堂武士",    "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"灵州" ]),    	
       ([      "quest_name":                "范松",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"黑木崖" ]),    	
       ([      "quest_name":                "赵鹤",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"黑木崖" ]),    	
       ([      "quest_name":                "张乘云",        "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"黑木崖" ]),    	
       ([      "quest_name":                "张乘风",        "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"黑木崖" ]),    	
       ([      "quest_name":                "贾布",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"黑木崖" ]),    	
       ([      "quest_name":                "日月神教教徒",  "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"黑木崖" ]),    	
       ([      "quest_name":                "王诚",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"黑木崖" ]),    	
       ([      "quest_name":                "玄苦大师",      "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"少林" ]),    	
       ([      "quest_name":                "澄志",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"少林" ]),    	
       ([      "quest_name":                "扫地僧",        "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"天龙寺" ]),    	
       ([      "quest_name":                "慧空尊者",        "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"少林" ]),    	
       ([      "quest_name":                "道觉禅师",        "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"少林" ]),    	
       ([      "quest_name":                "玄慈大师",        "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"少林" ]),    	
       ([      "quest_name":                "清善比丘",        "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"少林" ]),    	
       ([      "quest_name":                "道果禅师",        "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"少林" ]),    	
       ([      "quest_name":                "清无比丘",        "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"少林" ]),    	
       ([      "quest_name":                "清为比丘",        "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"少林" ]),    	
       ([      "quest_name":                "清法比丘",        "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"少林" ]),    	
       ([      "quest_name":                "史登达",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"嵩山" ]),    	
       ([      "quest_name":                "左冷禅",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"嵩山" ]),    	
       ([      "quest_name":                "狄修",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"嵩山" ]),    	
       ([      "quest_name":                "汤英鹄",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"嵩山" ]),    	
       ([      "quest_name":                "万大平",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"嵩山" ]),    	
       ([      "quest_name":                "陆柏",            "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"嵩山" ]),    	
       ([      "quest_name":                "费彬",            "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"嵩山" ]),    	
       ([      "quest_name":                "钟镇",            "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"嵩山" ]),    	
       ([      "quest_name":                "高克新",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"嵩山" ]),    	
       ([      "quest_name":                "邓八年",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"嵩山" ]),    	
       ([      "quest_name":                "丁勉",            "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"嵩山" ]),    	
       ([      "quest_name":                "郑萼",            "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"恒山" ]),    	
       ([      "quest_name":                "秦绢",            "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"恒山" ]),    	
       ([      "quest_name":                "定闲师太",        "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"恒山" ]),    	
       ([      "quest_name":                "定逸师太",        "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"恒山" ]),    	
       ([      "quest_name":                "仪清",            "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"恒山" ]),    	
       ([      "quest_name":                "仪和",            "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"恒山" ]),    	
       ([      "quest_name":                "仪质",            "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"恒山" ]),    	
       ([      "quest_name":                "哑妇",            "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"恒山" ]),    	
       ([      "quest_name":                "胡斐",            "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"关外" ]),    	
       ([      "quest_name":                "阎基",            "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"关外" ]),    	
       ([      "quest_name":                "焦文期",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"关外" ]),    	
       ([      "quest_name":                "赫尔苏",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"关外" ]),    	
       ([      "quest_name":                "滕一雷",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"关外" ]),    	
       ([      "quest_name":                "玉真子",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"关外" ]),    	
		 (["quest_name":  "殷老板",  "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"塘沽" ]),    	
		 (["quest_name":  "龙三爷",  "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"塘沽" ]),    	
		 (["quest_name":  "朱富",  "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"塘沽" ]),    	
		 (["quest_name":  "影云",  "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"塘沽" ]),    	
 (["quest_name":  "唐方",  "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"唐门" ]),    	
 (["quest_name":  "唐老太太",  "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"唐门" ]),    	
 (["quest_name":  "唐猛",  "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"唐门" ]),    	
 (["quest_name":  "豹组武士",  "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"唐门" ]),    	
 (["quest_name":  "唐无情",  "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"唐门" ]),    	
 (["quest_name":  "唐亮",  "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"唐门" ]),    	
 (["quest_name":  "萧秋水",  "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"唐门" ]),    	
 (["quest_name":  "龙组武士",  "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"唐门" ]),    	
 (["quest_name":  "宗维侠",  "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"崆峒山" ]),    	
 (["quest_name":  "杨举鹏",  "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"崆峒山" ]),    	
 (["quest_name":  "陈汉京",  "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"崆峒山" ]),    	
 (["quest_name":  "木灵子",  "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"崆峒山" ]),    	
 (["quest_name":  "周真人",  "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"崆峒山" ]),    	
});
	
mapping *lquest = ({
        ([      "quest_name":                "忽伦大虎",        "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"关外" ]),    	
       ([      "quest_name":                "忽伦二虎",        "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"关外" ]),    	
       ([      "quest_name":                "忽伦三虎",        "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"关外" ]),    	
       ([      "quest_name":                "忽伦四虎",        "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"关外" ]),    	
       ([      "quest_name":                "红毛鬼",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"台湾" ]),    	
       ([      "quest_name":                "刘国轩",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"台湾" ]),    	
       ([      "quest_name":                "莫大",            "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"衡山" ]),    	
       ([      "quest_name":                "纪晓芙",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"峨嵋" ]),    	
        ([      "quest_name":                "静玄师太",      "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"峨嵋" ]),    	
        ([      "quest_name":                "静和师太",      "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"峨嵋" ]),    	
        ([      "quest_name":                "文晖小师太",    "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"峨嵋" ]),    	
        ([      "quest_name":                "文清小师太",    "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"峨嵋" ]),    	
        ([      "quest_name":                "静心师太",      "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"峨嵋" ]),    	
        ([      "quest_name":                "贝锦仪",        "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"峨嵋" ]),    	
        ([      "quest_name":                "静玄师太",      "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"峨嵋" ]),    	
        ([      "quest_name":                "静迦师太",      "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"峨嵋" ]),    	
        ([      "quest_name":                "赵灵珠",        "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"峨嵋" ]),    	
        ([      "quest_name":                "李明霞",        "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"峨嵋" ]),    	
        ([      "quest_name":                "静慧师太",        "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"峨嵋" ]),    	
        ([      "quest_name":                "静闲师太",        "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"峨嵋" ]),    	
        ([      "quest_name":                "静照师太",        "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"峨嵋" ]),    	
        ([      "quest_name":                "静真师太",        "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"峨嵋" ]),    	
        ([      "quest_name":                "方碧琳",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"峨嵋" ]),    	
        ([      "quest_name":                "张松溪",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"武当" ]),    	
        ([      "quest_name":                "殷梨亭",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"武当" ]),    	
        ([      "quest_name":                "宋远桥",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"武当" ]),    	
        ([      "quest_name":                "俞莲舟",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"武当" ]),    	
        ([      "quest_name":                "谷虚道长",        "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"武当" ]),    	
        ([      "quest_name":                "张三丰",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"武当" ]),    	
        ([      "quest_name":                "清虚道长",        "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"武当" ]),    	
        ([      "quest_name":                "莫声谷",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"武当" ]),    	
       ([      "quest_name":                "钟万仇",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"万劫谷" ]),    	
       ([      "quest_name":                "甘宝宝",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"万劫谷" ]),    	
       ([      "quest_name":                "钟灵",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"万劫谷" ]),    	
       ([      "quest_name":                "陆乘风",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"归云庄" ]),    	
       ([      "quest_name":                "韩宝驹",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"归云庄" ]),    	
       ([      "quest_name":                "韩小莹",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"归云庄" ]),    	
       ([      "quest_name":                "柯镇恶",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"归云庄" ]),    	
       ([      "quest_name":                "全金发",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"归云庄" ]),    	
       ([      "quest_name":                "张阿生",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"归云庄" ]),    	
       ([      "quest_name":                "南希仁",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"归云庄" ]),    	
       ([      "quest_name":                "朱聪",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"归云庄" ]),    	
       ([      "quest_name":                "黄药师",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"桃花岛" ]),    	
       ([      "quest_name":                "余沧海",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"青城山" ]),    	
       ([      "quest_name":                "侯人英",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"青城山" ]),    	
       ([      "quest_name":                "洪人雄",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"青城山" ]),    	
       ([      "quest_name":                "张无忌",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"明教" ]),    	
       ([      "quest_name":                "殷野王",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"明教" ]),    	
       ([      "quest_name":                "拓跋",            "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"明教" ]),    	
       ([      "quest_name":                "辛然",            "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"明教" ]),    	
       ([      "quest_name":                "胡青牛",            "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"明教" ]),    	
       ([      "quest_name":                "颜垣",            "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"明教" ]),    	
       ([      "quest_name":                "唐洋",            "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"明教" ]),    	
       ([      "quest_name":                "庄铮",            "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"明教" ]),    	
       ([      "quest_name":                "接引使",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"明教" ]),    	
       ([      "quest_name":                "高山王",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"明教" ]),    	
       ([      "quest_name":                "巫士",            "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"明教" ]),    	
       ([      "quest_name":                "赵志敬",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"全真" ]),    	
       ([      "quest_name":                "尹志平",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"全真" ]),    	
       ([      "quest_name":                "小龙女",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"古墓" ]),    	
       ([      "quest_name":                "孙婆婆",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"古墓" ]),    	
       ([      "quest_name":                "林朝英",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"古墓" ]),    	
       ([      "quest_name":                "皮清玄",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"全真" ]),    	
       ([      "quest_name":                "姬清虚",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"全真" ]),    	
       ([      "quest_name":                "陈志益",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"全真" ]),    	
       ([      "quest_name":                "宝象",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"血刀门" ]),    	
       ([      "quest_name":                "血刀老祖",      "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"血刀门" ]),    	
       ([      "quest_name":                "胜谛",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"血刀门" ]),    	
       ([      "quest_name":                "央宗",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"血刀门" ]),    	
       ([      "quest_name":                "卓玛",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"血刀门" ]),    	
       ([      "quest_name":                "萨木活佛",      "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"雪山寺" ]),    	
       ([      "quest_name":                "嘉木活佛",      "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"雪山寺" ]),    	
       ([      "quest_name":                "拉章活佛",      "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"雪山寺" ]),    	
       ([      "quest_name":                "葛伦布",        "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"雪山寺" ]),    	
       ([      "quest_name":                "侍锤",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"雪山" ]),    	
       ([      "quest_name":                "善勇",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"血刀门" ]),    	
       ([      "quest_name":                "花铁干",        "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"血刀门" ]),    	
       ([      "quest_name":                "刘承风",        "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"血刀门" ]),    	
       ([      "quest_name":                "水岱",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"血刀门" ]),    	
       ([      "quest_name":                "陆天抒",        "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"血刀门" ]),    	
       ([      "quest_name":                "山贼头",        "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"白驼" ]),    	
       ([      "quest_name":                "花花公子",        "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"白驼" ]),    	
       ([      "quest_name":                "欧阳锋",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"白驼" ]),    	
       ([      "quest_name":                "小青",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"白驼" ]),    	
       ([      "quest_name":                "教练",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"白驼" ]),    	
       ([      "quest_name":                "李教头",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"白驼" ]),    	
       ([      "quest_name":                "管家",            "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"白驼" ]),    	
       ([      "quest_name":                "老材",            "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"白驼" ]),    	
       ([      "quest_name":                "白衣少女",        "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"白驼" ]),    	
       ([      "quest_name":                "张妈",            "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"白驼" ]),    	
       ([      "quest_name":                "白兔",            "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"白驼" ]),    	
       ([      "quest_name":                "门卫",            "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"白驼" ]),    	
       ([      "quest_name":                "兰剑",            "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"灵鹫宫" ]),    	
       ([      "quest_name":                "梅剑",            "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"灵鹫宫" ]),    	
       ([      "quest_name":                "余婆婆",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"灵鹫宫" ]),    	
       ([      "quest_name":                "九翼道人",        "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"灵鹫宫" ]),    	
       ([      "quest_name":                "出尘子",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"星宿海" ]),    	
       ([      "quest_name":                "采花子",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"星宿海" ]),    	
       ([      "quest_name":                "丁春秋",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"星宿海" ]),    	
       ([      "quest_name":                "阿紫",            "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"星宿海" ]),    	
       ([      "quest_name":                "摘星子",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"星宿海" ]),    	
       ([      "quest_name":                "狮吼子",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"星宿海" ]),    	
       ([      "quest_name":                "建除道人",        "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"泰山" ]),    	
       ([      "quest_name":                "玉磬子",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"泰山" ]),    	
       ([      "quest_name":                "玉音子",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"泰山" ]),    	
       ([      "quest_name":                "玉玑子",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"泰山" ]),    	
       ([      "quest_name":                "江百胜",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"泰山" ]),    	
       ([      "quest_name":                "天门道人",        "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"泰山" ]),    	
       ([      "quest_name":                "岳夫人",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"华山" ]),    	
       ([      "quest_name":                "施戴子",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"华山" ]),    	
       ([      "quest_name":                "岳不群",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"华山" ]),    	
       ([      "quest_name":                "岳灵珊",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"华山" ]),    	
       ([      "quest_name":                "高根明",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"华山" ]),    	
       ([      "quest_name":                "梁发",            "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"华山" ]),    	
       ([      "quest_name":                "公平子",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"华山" ]),    	
       ([      "quest_name":                "劳德诺",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"华山" ]),    	
       ([      "quest_name":                "令狐冲",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"华山" ]),    	
       ([      "quest_name":                "叶二娘",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"灵州" ]),    	
       ([      "quest_name":                "南海鳄神",        "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"灵州" ]),    	
       ([      "quest_name":                "石人武士",        "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"灵州" ]),    	
       ([      "quest_name":                "皇宫卫士",        "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"灵州" ]),    	
       ([      "quest_name":                "黄伯流",        "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"黑木崖" ]),    	
       ([      "quest_name":                "一品堂武士",    "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"灵州" ]),    	
       ([      "quest_name":                "范松",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"黑木崖" ]),    	
       ([      "quest_name":                "赵鹤",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"黑木崖" ]),    	
       ([      "quest_name":                "张乘云",        "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"黑木崖" ]),    	
       ([      "quest_name":                "张乘风",        "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"黑木崖" ]),    	
       ([      "quest_name":                "贾布",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"黑木崖" ]),    	
       ([      "quest_name":                "日月神教教徒",  "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"黑木崖" ]),    	
       ([      "quest_name":                "王诚",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"黑木崖" ]),    	
       ([      "quest_name":                "玄苦大师",      "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"少林" ]),    	
       ([      "quest_name":                "澄志",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"少林" ]),    	
       ([      "quest_name":                "扫地僧",        "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"天龙寺" ]),    	
       ([      "quest_name":                "慧空尊者",        "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"少林" ]),    	
       ([      "quest_name":                "道觉禅师",        "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"少林" ]),    	
       ([      "quest_name":                "玄慈大师",        "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"少林" ]),    	
       ([      "quest_name":                "清善比丘",        "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"少林" ]),    	
       ([      "quest_name":                "道果禅师",        "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"少林" ]),    	
       ([      "quest_name":                "清无比丘",        "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"少林" ]),    	
       ([      "quest_name":                "清为比丘",        "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"少林" ]),    	
       ([      "quest_name":                "清法比丘",        "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"少林" ]),    	
       ([      "quest_name":                "史登达",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"嵩山" ]),    	
       ([      "quest_name":                "左冷禅",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"嵩山" ]),    	
       ([      "quest_name":                "狄修",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"嵩山" ]),    	
       ([      "quest_name":                "汤英鹄",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"嵩山" ]),    	
       ([      "quest_name":                "万大平",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"嵩山" ]),    	
       ([      "quest_name":                "陆柏",            "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"嵩山" ]),    	
       ([      "quest_name":                "费彬",            "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"嵩山" ]),    	
       ([      "quest_name":                "钟镇",            "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"嵩山" ]),    	
       ([      "quest_name":                "高克新",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"嵩山" ]),    	
       ([      "quest_name":                "邓八年",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"嵩山" ]),    	
       ([      "quest_name":                "丁勉",            "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"嵩山" ]),    	
       ([      "quest_name":                "郑萼",            "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"恒山" ]),    	
       ([      "quest_name":                "秦绢",            "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"恒山" ]),    	
       ([      "quest_name":                "定闲师太",        "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"恒山" ]),    	
       ([      "quest_name":                "定逸师太",        "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"恒山" ]),    	
       ([      "quest_name":                "仪清",            "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"恒山" ]),    	
       ([      "quest_name":                "仪和",            "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"恒山" ]),    	
       ([      "quest_name":                "仪质",            "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"恒山" ]),    	
       ([      "quest_name":                "哑妇",            "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"恒山" ]),    	
       ([      "quest_name":                "胡斐",            "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"关外" ]),    	
       ([      "quest_name":                "阎基",            "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"关外" ]),    	
       ([      "quest_name":                "焦文期",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"关外" ]),    	
       ([      "quest_name":                "赫尔苏",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"关外" ]),    	
       ([      "quest_name":                "滕一雷",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"关外" ]),    	
       ([      "quest_name":                "玉真子",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"关外" ]),    	
		 (["quest_name":  "殷老板",  "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"沧州" ]),    	
		 (["quest_name":  "龙三爷",  "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"沧州" ]),    	
		 (["quest_name":  "朱富",  "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"沧州" ]),    	
		 (["quest_name":  "影云",  "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"沧州" ]),    	
 (["quest_name":  "唐方",  "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"唐门" ]),    	
 (["quest_name":  "唐老太太",  "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"唐门" ]),    	
 (["quest_name":  "唐猛",  "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"唐门" ]),    	
 (["quest_name":  "豹组武士",  "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"唐门" ]),    	
 (["quest_name":  "唐无情",  "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"唐门" ]),    	
 (["quest_name":  "唐亮",  "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"唐门" ]),    	
 (["quest_name":  "萧秋水",  "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"唐门" ]),    	
 (["quest_name":  "龙组武士",  "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"唐门" ]),    	
 (["quest_name":  "宗维侠",  "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"崆峒山" ]),    	
 (["quest_name":  "杨举鹏",  "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"崆峒山" ]),    	
 (["quest_name":  "陈汉京",  "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"崆峒山" ]),    	
 (["quest_name":  "木灵子",  "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"崆峒山" ]),    	
 (["quest_name":  "周真人",  "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"崆峒山" ]),   	
		 (["quest_name":  "梅世杰",  "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"侯集镇" ]),    	
		 (["quest_name":  "张济世",  "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"侯集镇" ]),    	
		 (["quest_name":  "赵虎",  "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"开封" ]),    	
		 (["quest_name":  "张龙",  "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"开封" ]),    	
		 (["quest_name":  "张济世",  "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"侯集镇" ]),    	
		  (["quest_name":  "霍桑",  "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"高昌城" ]),    	
		 (["quest_name":  "买买提",  "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"高昌城" ]),    	
		 (["quest_name":  "驿长",  "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"高昌城" ]),    	
		 (["quest_name":  "张百万",  "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"绮云镇" ]),    	
		 (["quest_name":  "铁豹",  "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"绮云镇" ]),    	
		 (["quest_name":  "茶工",  "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"绮云镇" ]),    	
		 (["quest_name":  "魏无极",  "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"雪亭镇" ]),    	
		 (["quest_name":  "张铁匠",  "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"雪亭镇" ]),    	
		 (["quest_name":  "柳生一郎",  "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"雪亭镇" ]),    	
		 (["quest_name":  "拉姆",  "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"八一镇" ]),    	
		 (["quest_name":  "霍英",  "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"黄山" ]),    	
		 (["quest_name":  "杜吟",  "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"黄山" ]),    	
		 (["quest_name":  "王莹",  "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"黄山" ]),    	
		 (["quest_name":  "王震湘",  "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"黄山" ]),    	
		 (["quest_name":  "空光",  "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"黄山" ]),    	
		 (["quest_name":  "白荭",  "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"黄山" ]),    	
		 (["quest_name":  "白环",  "exp_bonus":random(25)+30,"pot_bonus": random(12)+10  ,"quest_city":"黄山" ]),    	    
        ([      "quest_name":   "马超兴",  "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"扬州" ]),    	
        ([      "quest_name":   "武将",    "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"扬州" ]),    	
        ([      "quest_name":   "官兵",    "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"扬州" ]),    	
        ([      "quest_name":   "郭靖",    "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"襄阳" ]),    	
        ([      "quest_name":   "店小二",  "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"扬州" ]),    	
        ([      "quest_name":   "冼老板",  "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"扬州" ]),    	
        ([      "quest_name":   "王五",    "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"扬州" ]),    	
        ([      "quest_name":   "钱眼开",  "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"扬州" ]),    	
        ([      "quest_name":   "马夫",    "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"扬州" ]),    	
        ([      "quest_name":   "流氓",    "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"扬州" ]),    	
        ([      "quest_name":   "流氓头",  "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"扬州" ]),    	
        ([      "quest_name":   "朱熹",    "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"扬州" ]),    	
        ([      "quest_name":   "杨永福",  "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"扬州" ]),    	
        ([      "quest_name":   "曾柔",    "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"扬州" ]),    	
        ([      "quest_name":   "平一指",  "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"扬州" ]),    	
        ([      "quest_name":   "药铺伙计","exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"扬州" ]),    	
        ([      "quest_name":   "铁匠",    "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"扬州" ]),    	
        ([      "quest_name":   "挑夫",    "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"扬州" ]),    	
        ([      "quest_name":   "趟子手",  "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"北京" ]),    	
        ([      "quest_name":   "海公公",  "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"扬州" ]),    	
        ([      "quest_name":   "小桂子",  "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"扬州" ]),    	
        ([      "quest_name":   "程玉环",  "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"扬州" ]),    	
        ([      "quest_name":   "谭友纪",  "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"扬州" ]),    	
        ([      "quest_name":   "程药发",  "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"扬州" ]),    	
        ([      "quest_name":   "衙役",    "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"扬州" ]),    	
        ([      "quest_name":   "史青山",  "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"扬州" ]),    	
        ([      "quest_name":   "游方道人","exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"扬州" ]),    	
        ([      "quest_name":   "陈有德",  "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"扬州" ]),    	
        ([      "quest_name":   "家丁",    "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"扬州" ]),    	
        ([      "quest_name":   "管家",    "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"扬州" ]),    	
        ([      "quest_name":   "崔员外",  "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"扬州" ]),    	
        ([      "quest_name":   "崔莺莺",  "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"扬州" ]),    	
        ([      "quest_name":   "红娘",    "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"杭州" ]),    	
        ([      "quest_name":   "封弓影",  "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"扬州" ]),    	
        ([      "quest_name":   "慕容巡捕",    "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"扬州" ]),    	
        ([      "quest_name":   "桃花村长","exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"扬州" ]),    	
        ([      "quest_name":   "桃花童",  "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"扬州" ]),    	
        ([      "quest_name":   "男孩",    "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"扬州" ]),    	
        ([      "quest_name":   "赵敏",    "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"洛阳" ]),    	
        ([      "quest_name":   "孙三毁",  "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"洛阳" ]),    	
        ([      "quest_name":   "赵一伤",  "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"洛阳" ]),    	
        ([      "quest_name":   "钱二败",  "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"洛阳" ]),    	
        ([      "quest_name":   "李四摧",  "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"洛阳" ]),    	
        ([      "quest_name":   "吴六破",  "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"洛阳" ]),    	
        ([      "quest_name":   "周五输",  "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"洛阳" ]),    	
        ([      "quest_name":   "王八衰",  "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"洛阳" ]),    	
        ([      "quest_name":   "郑七灭",  "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"洛阳" ]),    	
        ([      "quest_name":   "史松",    "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"扬州" ]),    	
        ([      "quest_name":   "空空儿",  "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"扬州" ]),    	
        ([      "quest_name":   "韦小宝",  "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"扬州" ]),    	
        ([      "quest_name":   "唐楠",    "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"扬州" ]),    	
        ([      "quest_name":   "香菱",    "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"扬州" ]),    	
        ([      "quest_name":   "小混混",  "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"扬州" ]),    	
        ([      "quest_name":   "哈巴狗",  "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"扬州" ]),    	
        ([      "quest_name":   "胖头陀",  "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"扬州" ]),    	
        ([      "quest_name":   "段誉",    "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"扬州" ]),    	
        ([      "quest_name":   "阿庆嫂",  "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"扬州" ]),    	
        ([      "quest_name":   "韦春芳",  "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"扬州" ]),    	
        ([      "quest_name":   "龟公",    "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"扬州" ]),    	
        ([      "quest_name":   "茅十八",  "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"扬州" ]),    	
        ([      "quest_name":   "欧阳克",  "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"扬州" ]),    	
		([      "quest_name":  "何员外",  "exp_bonus":random(10)+30,"pot_bonus": random(8)+10  ,"quest_city":"扬州" ]),    	
		([      "quest_name":  "阿珂",  "exp_bonus":random(10)+30,"pot_bonus": random(8)+10  ,"quest_city":"扬州" ]),    	
		([      "quest_name":  "冷郁然",  "exp_bonus":random(10)+30,"pot_bonus": random(8)+10  ,"quest_city":"扬州" ]),    	
		([      "quest_name":  "杨磊石",  "exp_bonus":random(10)+30,"pot_bonus": random(8)+10  ,"quest_city":"扬州" ]),    	
		([      "quest_name":  "仇星星",    "exp_bonus":random(10)+30,"pot_bonus": random(8)+10  ,"quest_city":"扬州" ]),    	
		([      "quest_name":  "吴古贤",    "exp_bonus":random(10)+30,"pot_bonus": random(8)+10  ,"quest_city":"扬州" ]),    	
		([      "quest_name":  "顾月儿","exp_bonus":random(10)+30,"pot_bonus": random(8)+10  ,"quest_city":"扬州" ]),    	
		([      "quest_name":  "老婆婆",  "exp_bonus":random(10)+30,"pot_bonus": random(8)+10  ,"quest_city":"扬州" ]),    	
		([     "quest_name":  "张不四",  "exp_bonus":random(10)+30,"pot_bonus": random(8)+10  ,"quest_city":"扬州" ]),    	
		([      "quest_name":   "辛友清",  "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"扬州" ]),    		
		 		([			"quest_name":  "周大夫",  	"exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"定襄" ]),    	
		 		([			"quest_name":  "吴老板",   	"exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"定襄" ]),    	
        ([      "quest_name":   "欧阳巡捕",    "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"扬州" ]),    	
        ([      "quest_name":   "公孙巡捕",    "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"扬州" ]),    	
        ([      "quest_name":   "紫云巡捕",    "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"扬州" ]),    	
        ([      "quest_name":   "玉虚子",    "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"关中" ]),    	
        ([      "quest_name":   "云清子",    "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"关中" ]),    	
        ([      "quest_name":   "张言成",    "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"关中" ]),    	
        ([      "quest_name":   "胡大掌柜",    "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"西藏" ]),    	
        ([      "quest_name":   "护寺藏尼",    "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"西藏" ]),    	
        ([      "quest_name":   "护寺喇嘛",    "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"西藏" ]),    	
        ([      "quest_name":   "城卫",    "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"西藏" ]),    	
        ([      "quest_name":   "裘逸",    "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"金陵" ]),    	
        ([      "quest_name":   "王乞儿",    "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"金陵" ]),    	
        ([      "quest_name":   "萧之羽",    "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"金陵" ]),    	
        ([      "quest_name":                "舞蛇人", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"北京" ]),    	
        ([      "quest_name":                "刀客",  "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"北京" ]),    	
        ([      "quest_name":                "剑客",   "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"北京" ]),    	
        ([      "quest_name":                "关安基",  "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"北京" ]),    	
        ([      "quest_name":                "李力世",     "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"北京" ]),    	
        ([      "quest_name":                "屠宰场伙计",   "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"北京" ]),    	
        ([      "quest_name":                "小贩",       "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"北京" ]),    	
        ([      "quest_name":                "贾老六",     "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"北京" ]),    	
        ([      "quest_name":                "游客",      "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"北京" ]),    	
        ([      "quest_name":                "游方和尚",   "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"北京" ]),    	
        ([      "quest_name":                "胡掌柜",     "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"北京" ]),    	
        ([      "quest_name":                "江湖豪客",   "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"北京" ]),    	
        ([      "quest_name":                "高彦超",      "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"北京" ]),    	
        ([      "quest_name":                "小流氓",      "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"北京" ]),    	
        ([      "quest_name":                "地痞",        "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"北京" ]),    	
        ([      "quest_name":                "掌柜",        "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"北京" ]),    	
        ([      "quest_name":                "客店伙计",    "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"北京" ]),    	
        ([      "quest_name":                "吴六奇",      "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"北京" ]),    	
        ([      "quest_name":                "瘦头陀",      "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"北京" ]),    	
        ([      "quest_name":                "书生",        "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"北京" ]),    	
        ([      "quest_name":                "顾炎武",      "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"北京" ]),    	
        ([      "quest_name":                "萧远山",      "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"关外" ]),    	
        ([      "quest_name":                "冯锡范",      "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"北京" ]),    	
        ([      "quest_name":                "太监",        "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"北京" ]),    	
        ([      "quest_name":                "卖花姑娘",    "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"北京" ]),    	
        ([      "quest_name":                "侍卫",        "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"北京" ]),    	
        ([      "quest_name":                "白龟寿",      "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"王盘山岛" ]),    	
        ([      "quest_name":                "钱老本",       "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"北京" ]),    	
        ([      "quest_name":                "土匪",        "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"北京" ]),    	
        ([      "quest_name":                "挑夫",        "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"北京" ]),    	
        ([      "quest_name":                "贡唐仓国师",  "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"北京" ]),    	
        ([      "quest_name":                "徐天川",      "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"北京" ]),    	
        ([      "quest_name":                "桑三娘",      "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"黑木崖" ]),    	
        ([      "quest_name":                "沈青刚",      "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"黄河九曲" ]),    	
        ([      "quest_name":                "马青雄",      "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"黄河九曲" ]),    	
        ([      "quest_name":                "吴青烈",      "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"黄河九曲" ]),    	
        ([      "quest_name":                "薛慕华",      "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"逍遥" ]),    	
        ([      "quest_name":                "康广陵",      "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"逍遥" ]),    	
        ([      "quest_name":                "蒙面人",      "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"逍遥" ]),    	
        ([      "quest_name":                "苏星河",      "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"逍遥" ]),    	
        ([      "quest_name":                "苟读",        "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"逍遥" ]),    	
        ([      "quest_name":                "钱青健",      "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"黄河九曲" ]),    	
        ([      "quest_name":                "彭连虎",      "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"黄河九曲" ]),    	
        ([      "quest_name":                "陆冠英",      "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"归云庄" ]),    	
        ([      "quest_name":                "裘千丈",      "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"铁掌帮" ]),    	
        ([      "quest_name":                "翠花",        "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"武功镇" ]),    	
        ([      "quest_name":                "地保",        "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"武功镇" ]),    	
        ([      "quest_name":                "李四",        "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"武功镇" ]),    	
        ([      "quest_name":                "沙通天",      "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"黄河九曲" ]),    	
        ([      "quest_name":                "梁子翁",      "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"黄河九曲" ]),    	
        ([      "quest_name":                "侯通海",      "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"黄河九曲" ]),    	
        ([      "quest_name":                "大汉",       "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"黄河九曲" ]),    	
        ([      "quest_name":                "老者",        "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"黑木崖" ]),    	
        ([      "quest_name":                "老鸨婆",      "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"北京" ]),    	
        ([      "quest_name":                "老和尚",      "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"北京" ]),    	
        ([      "quest_name":                "程老板",      "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"北京" ]),    	
        ([      "quest_name":                "乐厚",        "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"嵩山" ]),    	
        ([      "quest_name":                "天松道人",    "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"泰山" ]),    	
        ([      "quest_name":                "天柏道人",    "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"泰山" ]),    	
        ([      "quest_name":                "祖千秋",      "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"黄河九曲" ]),    	
        ([      "quest_name":                "单正",        "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"黄河九曲" ]),    	
        ([      "quest_name":                "天乙道人",    "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"泰山" ]),    	
        ([      "quest_name":                "小孩",        "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"扬州" ]),    	
        ([      "quest_name":                "虚通",        "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"少林" ]),    	
        ([      "quest_name":                "虚明",        "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"少林" ]),    	
        ([      "quest_name":                "李莫愁",      "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"嘉兴" ]),    	
        ([      "quest_name":                "定静师太",    "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"恒山" ]),    	
        ([      "quest_name":                "仪文",        "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"恒山" ]),    	
        ([      "quest_name":                "冯铁匠",      "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"华山村" ]),    	
        ([      "quest_name":                "老船夫",      "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"北京" ]),    	
		 (["quest_name":  "王家驹",  "exp_bonus":random(15)+30,"pot_bonus": random(8)+10  ,"quest_city":"洛阳" ]),    	
		 (["quest_name":  "易师爷",  "exp_bonus":random(15)+30,"pot_bonus": random(8)+10  ,"quest_city":"洛阳" ]),    	
		 (["quest_name":  "王仲强",  "exp_bonus":random(15)+30,"pot_bonus": random(8)+10  ,"quest_city":"洛阳" ]),    	
		 (["quest_name":  "拓跋玉",  "exp_bonus":random(15)+30,"pot_bonus": random(8)+10  ,"quest_city":"定襄" ]),    	
		 (["quest_name":  "墩欲谷",  "exp_bonus":random(15)+30,"pot_bonus": random(8)+10  ,"quest_city":"定襄" ]),    	
		 (["quest_name":  "结社率",  "exp_bonus":random(15)+30,"pot_bonus": random(8)+10  ,"quest_city":"定襄" ]),    	
		 (["quest_name":  "毕玄",  "exp_bonus":random(15)+30,"pot_bonus": random(8)+10  ,"quest_city":"定襄" ]),    	
		 (["quest_name":  "王药师",  "exp_bonus":random(15)+30,"pot_bonus": random(8)+10  ,"quest_city":"定襄" ]),    	
		 (["quest_name":  "孟老板",  "exp_bonus":random(15)+30,"pot_bonus": random(8)+10  ,"quest_city":"定襄" ]),    	
		 (["quest_name":  "秦掌柜",  "exp_bonus":random(15)+30,"pot_bonus": random(8)+10  ,"quest_city":"定襄" ]),    	
		 (["quest_name":  "周逸风",  "exp_bonus":random(15)+30,"pot_bonus": random(8)+10  ,"quest_city":"定襄" ]),    	
		 (["quest_name":  "校尉",  "exp_bonus":random(15)+30,"pot_bonus": random(8)+10  ,"quest_city":"关中" ]),    	
		 (["quest_name":  "福建客商",  "exp_bonus":random(15)+30,"pot_bonus": random(8)+10  ,"quest_city":"关中" ]),    	
		 (["quest_name":  "鱼贩子",  "exp_bonus":random(15)+30,"pot_bonus": random(8)+10  ,"quest_city":"关中" ]),    	
		 (["quest_name":  "莫飞云",  "exp_bonus":random(15)+30,"pot_bonus": random(8)+10  ,"quest_city":"关中" ]),    	
		 (["quest_name":  "张天有",  "exp_bonus":random(15)+30,"pot_bonus": random(8)+10  ,"quest_city":"大同" ]),    	
		 (["quest_name":  "巧手妹妹",  "exp_bonus":random(15)+30,"pot_bonus": random(8)+10  ,"quest_city":"大同" ]),    	
		 (["quest_name":  "胡迈",  "exp_bonus":random(15)+30,"pot_bonus": random(8)+10  ,"quest_city":"大同" ]),    	
		 (["quest_name":  "任一力",  "exp_bonus":random(15)+30,"pot_bonus": random(8)+10  ,"quest_city":"大同" ]),    	
		 (["quest_name":  "刘铁",  "exp_bonus":random(15)+30,"pot_bonus": random(8)+10  ,"quest_city":"大同" ]),    	
		 (["quest_name":  "黄富贵",  "exp_bonus":random(15)+30,"pot_bonus": random(8)+10  ,"quest_city":"大同" ]),    		
		(["quest_name":  "诸葛武",  "exp_bonus":random(15)+30,"pot_bonus": random(8)+10  ,"quest_city":"大同" ]),    	
		(["quest_name":  "手编老人",  "exp_bonus":random(15)+30,"pot_bonus": random(8)+10  ,"quest_city":"大同" ]),    	
		(["quest_name":  "钟济世",  "exp_bonus":random(15)+30,"pot_bonus": random(8)+10  ,"quest_city":"大同" ]),    	
		(["quest_name":  "李大爷",  "exp_bonus":random(15)+30,"pot_bonus": random(8)+10  ,"quest_city":"大同" ]),    	
		(["quest_name":  "刘福",  "exp_bonus":random(15)+30,"pot_bonus": random(8)+10  ,"quest_city":"大同" ]),    	
		(["quest_name":  "雷开远",  "exp_bonus":random(15)+30,"pot_bonus": random(8)+10  ,"quest_city":"天水" ]),    		     
		 (["quest_name":  "谢琳",  "exp_bonus":random(15)+30,"pot_bonus": random(8)+10  ,"quest_city":"雁荡" ]),    	
		 (["quest_name":  "落雁老人",  "exp_bonus":random(15)+30,"pot_bonus": random(8)+10  ,"quest_city":"雁荡" ]),    	
		 (["quest_name":  "铁桥三",  "exp_bonus":random(15)+30,"pot_bonus": random(8)+10  ,"quest_city":"雁荡" ]),    	
		 (["quest_name":  "猿长老",  "exp_bonus":random(15)+30,"pot_bonus": random(8)+10  ,"quest_city":"雁荡" ]),    	
		 (["quest_name":  "李老板",  "exp_bonus":random(15)+30,"pot_bonus": random(8)+10  ,"quest_city":"太原" ]),    	
		 (["quest_name":  "李店主",  "exp_bonus":random(15)+30,"pot_bonus": random(8)+10  ,"quest_city":"太原" ]),    	
		 (["quest_name":  "民工",  "exp_bonus":random(15)+30,"pot_bonus": random(8)+10  ,"quest_city":"太原" ]),    	
		 (["quest_name":  "断肠人",  "exp_bonus":random(15)+30,"pot_bonus": random(8)+10  ,"quest_city":"济南" ]),    	
		 (["quest_name":  "殷羡",  "exp_bonus":random(15)+30,"pot_bonus": random(8)+10  ,"quest_city":"济南" ]),    	
		 (["quest_name":  "苏蓉蓉",  "exp_bonus":random(15)+30,"pot_bonus": random(8)+10  ,"quest_city":"济南" ]),    	
        ([      "quest_name":                "甄有庆",     "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"苏州" ]),    	
        ([      "quest_name":                "史镖头",     "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"福州" ]),    	
        ([      "quest_name":                "陈阿婆",     "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"福州" ]),    	
        ([      "quest_name":                "老朝奉",     "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"佛山" ]),    	
        ([      "quest_name":                "小贼",         "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"成都" ]),    	
        ([      "quest_name":                "鲁连荣",     "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"衡山" ]),    	
        ([      "quest_name":                "牙将",             "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"襄阳" ]),    	
        ([      "quest_name":                "黄真",             "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"襄阳" ]),    	
        ([      "quest_name":                "文泰来",           "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"杭州" ]),    	
        ([      "quest_name":                "阿拉木罕",         "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"天山" ]),    	
        ([      "quest_name":                "买卖提",           "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"天山" ]),    	
        ([      "quest_name":                "阿凡提",           "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"天山" ]),    	
        ([      "quest_name":                "巴依",             "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"天山" ]),    	
        ([      "quest_name":                "侯员外",           "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"武功镇" ]),    	
        ([      "quest_name":                "刘菁",             "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"衡阳" ]),    	
        ([      "quest_name":                "刘芹",             "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"衡阳" ]),    	
        ([      "quest_name":                "刘夫人",           "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"衡阳" ]),    	
        ([      "quest_name":                "刘正风",           "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"衡阳" ]),    	
        ([      "quest_name":                "曲非烟",           "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"衡阳" ]),    	
        ([      "quest_name":                "曲洋",             "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"衡阳" ]),    	
        ([      "quest_name":                "骆冰",             "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"杭州" ]),    	
        ([      "quest_name":                "米为义",           "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"衡阳" ]),    	
        ([      "quest_name":                "向大年",           "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"衡阳" ]),    	
        ([      "quest_name":                "田伯光",           "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"衡阳" ]),    	
        ([      "quest_name":                "仪琳",             "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"衡阳" ]),    	
        ([      "quest_name":                "茶博士",           "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"衡阳" ]),    	
        ([      "quest_name":                "西夏兵",     "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"黄河九曲" ]),    	
        ([      "quest_name":                "李可秀",           "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"杭州" ]),    	
        ([      "quest_name":                "胡庆余",           "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"杭州" ]),    	
        ([      "quest_name":                "张召重",           "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"杭州" ]),    	
        ([      "quest_name":                "耶律齐",           "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"襄阳" ]),    	
        ([      "quest_name":                "黄蓉",             "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"襄阳" ]),    	
        ([      "quest_name":                "武三通",           "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"襄阳" ]),    	
        ([      "quest_name":                "武修文",           "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"襄阳" ]),    	
        ([      "quest_name":                "朱子柳",           "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"襄阳" ]),    	
        ([      "quest_name":                "郭芙",             "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"襄阳" ]),    	
        ([      "quest_name":                "木匠",             "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"襄阳" ]),    	
        ([      "quest_name":                "偏将",             "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"襄阳" ]),    	
        ([      "quest_name":                "佐将",             "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"襄阳" ]),    	
        ([      "quest_name":                "宋兵",             "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"襄阳" ]),    	
        ([      "quest_name":                "高丽商",           "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"襄阳" ]),    	
        ([      "quest_name":                "书店老板",         "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"襄阳" ]),    	
        ([      "quest_name":                "申人俊",           "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"襄阳" ]),    	
        ([      "quest_name":                "武敦儒",           "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"襄阳" ]),    	
        ([      "quest_name":                "吉人通",           "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"襄阳" ]),    	
        ([      "quest_name":                "唐槐",             "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"成都" ]),    	
        ([      "quest_name":                "刘虹瑛",           "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"成都" ]),    	
        ([      "quest_name":                "萧飞",             "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"成都" ]),    	
        ([      "quest_name":                "陈浒",             "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"成都" ]),    	
        ([      "quest_name":                "龙铨",             "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"成都" ]),    	
        ([      "quest_name":                "马五德",           "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"成都" ]),    	
        ([      "quest_name":                "账房老夫子",       "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"成都" ]),    	
        ([      "quest_name":                "本参",         "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"天龙寺" ]),    	
        ([      "quest_name":                "本相",         "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"天龙寺" ]),    	
        ([      "quest_name":                "本尘",         "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"天龙寺" ]),    	
        ([      "quest_name":                "本观",         "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"天龙寺" ]),    	
        ([      "quest_name":                "枯荣大师",     "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"天龙寺" ]),    	
        ([      "quest_name":                "本因",         "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"天龙寺" ]),    	
        ([      "quest_name":                "猎人",         "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"大理" ]),    	
        ([      "quest_name":                "陪从",         "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"大理" ]),    	
        ([      "quest_name":                "高升泰",       "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"大理" ]),    	
        ([      "quest_name":                "素衣卫士",     "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"大理" ]),    	
        ([      "quest_name":                "采笋人",       "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"大理" ]),    	
        ([      "quest_name":                "士兵",         "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"大理" ]),    	
        ([      "quest_name":                "族头人",       "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"大理" ]),    	
        ([      "quest_name":                "侍从",         "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"大理" ]),    	
        ([      "quest_name":                "大土司",       "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"大理" ]),    	
        ([      "quest_name":                "歌女",         "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"大理" ]),    	
        ([      "quest_name":                "何红药",       "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"大理" ]),    	
        ([      "quest_name":                "薛老板",       "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"大理" ]),    	
        ([      "quest_name":                "石匠",         "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"大理" ]),    	
        ([      "quest_name":                "黄衣卫士",     "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"大理" ]),    	
        ([      "quest_name":                "褚万里",       "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"大理" ]),    	
        ([      "quest_name":                "傅思归",       "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"大理" ]),    	
        ([      "quest_name":                "锦衣卫士",     "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"大理" ]),    	
        ([      "quest_name":                "太监",       "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"大理" ]),    	
        ([      "quest_name":                "宫女",       "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"大理" ]),    	
        ([      "quest_name":                "神农帮弟子",   "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"大理" ]),    	
        ([      "quest_name":                "无量剑弟子",   "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"大理" ]),    	
        ([      "quest_name":                "凤一鸣",     "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"佛山" ]),    	
        ([      "quest_name":                "黄衣使者",   "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"佛山" ]),    	
        ([      "quest_name":                "渔夫",       "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"佛山" ]),    	
        ([      "quest_name":                "瘦商人",     "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"佛山" ]),    	
        ([      "quest_name":                "胖商人",     "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"佛山" ]),    	
        ([      "quest_name":                "凤七",       "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"佛山" ]),    	
        ([      "quest_name":                "张朝唐",     "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"佛山" ]),    	
        ([      "quest_name":                "张康",       "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"佛山" ]),    	
        ([      "quest_name":                "常金鹏",     "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"泉州" ]),    	
        ([      "quest_name":                "游讯",       "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"泉州" ]),    	
        ([      "quest_name":                "卜沉",       "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"嵩山" ]),    	
        ([      "quest_name":                "沙天江",     "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"嵩山" ]),    	
        ([      "quest_name":                "戈什哈",     "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"福州" ]),    	
        ([      "quest_name":                "老和尚",     "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"杭州" ]),    	
        ([      "quest_name":                "林震南",     "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"福州" ]),    	
        ([      "quest_name":                "余人彦",     "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"青城山" ]),    	
        ([      "quest_name":                "贾人达",     "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"青城山" ]),    	
        ([      "quest_name":                "崔镖头",     "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"福州" ]),    	
        ([      "quest_name":                "阿碧",       "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"慕容山庄" ]),    	
        ([      "quest_name":                "冯正东",     "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"苏州" ]),    	
        ([      "quest_name":                "阿朱",       "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"慕容山庄" ]),    	
		 (["quest_name":  "风波恶",  "exp_bonus":random(20)+30,"pot_bonus": random(10)+10  ,"quest_city":"燕子坞" ]),    	
		 (["quest_name":  "包不同",  "exp_bonus":random(20)+30,"pot_bonus": random(10)+10  ,"quest_city":"燕子坞" ]),    	
		 (["quest_name":  "王夫人",  "exp_bonus":random(20)+30,"pot_bonus": random(10)+10  ,"quest_city":"燕子坞" ]),    	
		 (["quest_name":  "王语嫣",  "exp_bonus":random(20)+30,"pot_bonus": random(10)+10  ,"quest_city":"燕子坞" ]),    	
		 (["quest_name":  "邓百川",  "exp_bonus":random(20)+30,"pot_bonus": random(10)+10  ,"quest_city":"燕子坞" ]),    	
	 (["quest_name":  "边军官兵",  "exp_bonus":random(20)+30,"pot_bonus": random(10)+10  ,"quest_city":"定襄" ]),    	
	 (["quest_name":  "边军武将",  "exp_bonus":random(20)+30,"pot_bonus": random(10)+10  ,"quest_city":"定襄" ]),    	    	
		 (["quest_name":  "马大嫂",  "exp_bonus":random(20)+30,"pot_bonus": random(10)+10  ,"quest_city":"盛京" ]),    	
		 (["quest_name":  "范文程",  "exp_bonus":random(20)+30,"pot_bonus": random(10)+10  ,"quest_city":"盛京" ]),    	
		 (["quest_name":  "李大姐",  "exp_bonus":random(20)+30,"pot_bonus": random(10)+10  ,"quest_city":"盛京" ]),    	
		 (["quest_name":  "多尔衮",  "exp_bonus":random(20)+30,"pot_bonus": random(10)+10  ,"quest_city":"盛京" ]),    	
		 (["quest_name":  "海兰珠",  "exp_bonus":random(20)+30,"pot_bonus": random(10)+10  ,"quest_city":"盛京" ]),    	
		 (["quest_name":  "王家驹",  "exp_bonus":random(20)+30,"pot_bonus": random(10)+10  ,"quest_city":"洛阳" ]),    	
		 (["quest_name":  "易师爷",  "exp_bonus":random(20)+30,"pot_bonus": random(10)+10  ,"quest_city":"洛阳" ]),    	
		 (["quest_name":  "王仲强",  "exp_bonus":random(20)+30,"pot_bonus": random(10)+10  ,"quest_city":"洛阳" ]),    	
		 (["quest_name":  "方穷",  "exp_bonus":random(20)+30,"pot_bonus": random(10)+10  ,"quest_city":"南少林" ]),    	
		 (["quest_name":  "元悲",  "exp_bonus":random(20)+30,"pot_bonus": random(10)+10  ,"quest_city":"南少林" ]),    	
		 (["quest_name":  "方戒",  "exp_bonus":random(20)+30,"pot_bonus": random(10)+10  ,"quest_city":"南少林" ]),    	
		 (["quest_name":  "大痍大师",  "exp_bonus":random(20)+30,"pot_bonus": random(10)+10  ,"quest_city":"南少林" ]),    	
		 (["quest_name":  "大痕大师",  "exp_bonus":random(20)+30,"pot_bonus": random(10)+10  ,"quest_city":"南少林" ]),    	
		 (["quest_name":  "元忍",  "exp_bonus":random(20)+30,"pot_bonus": random(10)+10  ,"quest_city":"南少林" ]),    	
		 (["quest_name":  "元惑",  "exp_bonus":random(20)+30,"pot_bonus": random(10)+10  ,"quest_city":"南少林" ]),    	
		 (["quest_name":  "元恙",  "exp_bonus":random(20)+30,"pot_bonus": random(10)+10  ,"quest_city":"南少林" ]),    	
		 (["quest_name":  "大苦大师",  "exp_bonus":random(20)+30,"pot_bonus": random(10)+10  ,"quest_city":"南少林" ]),    		 
		 (["quest_name":  "醉汉",  "exp_bonus":random(20)+30,"pot_bonus": random(10)+10  ,"quest_city":"长沙" ]),    	
		 (["quest_name":  "乔老板",  "exp_bonus":random(20)+30,"pot_bonus": random(10)+10  ,"quest_city":"长沙" ]),    	
		 (["quest_name":  "宋大夫",  "exp_bonus":random(20)+30,"pot_bonus": random(10)+10  ,"quest_city":"长沙" ]),    	
		 (["quest_name":  "妙龄少女",  "exp_bonus":random(20)+30,"pot_bonus": random(10)+10  ,"quest_city":"长沙" ]),    	
		 (["quest_name":  "屠小娇",  "exp_bonus":random(20)+30,"pot_bonus": random(10)+10  ,"quest_city":"恶人谷" ]),    	
		 (["quest_name":  "胡药师",  "exp_bonus":random(20)+30,"pot_bonus": random(10)+10  ,"quest_city":"恶人谷" ]),    	
		 (["quest_name":  "铁萍姑",  "exp_bonus":random(20)+30,"pot_bonus": random(10)+10  ,"quest_city":"恶人谷" ]),    	
		 (["quest_name":  "王小路",  "exp_bonus":random(20)+30,"pot_bonus": random(10)+10  ,"quest_city":"恶人谷" ]),    	
		(["quest_name":  "端木良庸",  "exp_bonus":random(20)+30,"pot_bonus": random(10)+10  ,"quest_city":"景德镇" ]),    	
		(["quest_name":  "叶天士",  "exp_bonus":random(20)+30,"pot_bonus": random(10)+10  ,"quest_city":"景德镇" ]),    	
		(["quest_name":  "温方海",  "exp_bonus":random(20)+30,"pot_bonus": random(10)+10  ,"quest_city":"景德镇" ]),    	
		(["quest_name":  "温方达",  "exp_bonus":random(20)+30,"pot_bonus": random(10)+10  ,"quest_city":"温家堡" ]),    	
		(["quest_name":  "温方南",  "exp_bonus":random(20)+30,"pot_bonus": random(10)+10  ,"quest_city":"温家堡" ]),    	
		(["quest_name":  "温仪",  "exp_bonus":random(20)+30,"pot_bonus": random(10)+10  ,"quest_city":"温家堡" ]),    	
		(["quest_name":  "镇关西",  "exp_bonus":random(20)+30,"pot_bonus": random(10)+10  ,"quest_city":"宁远" ]),    	
		(["quest_name":  "彝南柯",  "exp_bonus":random(20)+30,"pot_bonus": random(10)+10  ,"quest_city":"宁远" ]),    	
		(["quest_name":  "袁崇焕",  "exp_bonus":random(20)+30,"pot_bonus": random(10)+10  ,"quest_city":"宁远" ]),    	
		(["quest_name":  "祖大寿",  "exp_bonus":random(20)+30,"pot_bonus": random(10)+10  ,"quest_city":"宁远" ]),    	
		(["quest_name":  "边军官兵",  "exp_bonus":random(20)+30,"pot_bonus": random(10)+10  ,"quest_city":"宁远" ]),    	
		(["quest_name":  "边军武将",  "exp_bonus":random(20)+30,"pot_bonus": random(10)+10  ,"quest_city":"宁远" ]),    	    	
		(["quest_name":  "吕通",  "exp_bonus":random(20)+30,"pot_bonus": random(10)+10  ,"quest_city":"江陵" ]),    	
		(["quest_name":  "鲁坤",  "exp_bonus":random(20)+30,"pot_bonus": random(10)+10  ,"quest_city":"江陵" ]),    	
		(["quest_name":  "贺文宝",  "exp_bonus":random(20)+30,"pot_bonus": random(10)+10  ,"quest_city":"江陵" ]),    	
		(["quest_name":  "丁典",  "exp_bonus":random(20)+30,"pot_bonus": random(10)+10  ,"quest_city":"江陵" ]),    	
		(["quest_name":  "言达平",  "exp_bonus":random(20)+30,"pot_bonus": random(10)+10  ,"quest_city":"江陵" ]),    	 	
		(["quest_name":  "苗若兰",  "exp_bonus":random(20)+30,"pot_bonus": random(10)+10  ,"quest_city":"沧州" ]),    	
		(["quest_name":  "蒋调侯",  "exp_bonus":random(20)+30,"pot_bonus": random(10)+10  ,"quest_city":"沧州" ]),    	
		(["quest_name":  "王大米",  "exp_bonus":random(20)+30,"pot_bonus": random(10)+10  ,"quest_city":"沧州" ]),    	
		(["quest_name":  "黄老板",  "exp_bonus":random(20)+30,"pot_bonus": random(10)+10  ,"quest_city":"沧州" ]),    	
});

mixed rooms = ({
        ({
        "少林广场","王府路","华藏庵","有所不为轩","紫霄宫大门",
        "天微堂","日月坪","大雪山山谷","六和塔","全真教大门", 
        "墓门","桃花山庄正厅","居庸关","独尊厅","星宿海", 
        "雪山寺山门","一品堂大院","昆仑派山门","参合居","五指堂", 
        "朱雀外门","青龙外门","白虎外门","玄武外门","天安门",
        "扬州武馆","福威镖局","玄妙观","灵隐寺","泉州南门",
        "灵州南门","诸葛亮殿","烟雨楼","南阳城","佛山南门",                
        "蛇骨塔","长安乐坊","衡阳西街","喜州城","葛鲁城", 
        "伊犁","山海关","老龙头","白头山天池","天山脚下",
        "丽春院","涌泉寺","听雨轩","五老峰","紫金城",
        "松风观","终南山脚","抱子岩","白马潭","升仙坊",                
        "嘉应门","玄妙观","峻极禅院","侠义厅","萧家桥", 
        "凌霄内门","凌霄殿","桃花江东岸","五毒教大门","天心岩",
        "嘉峪关","丝绸之路","白头山天池","黑风口","龙门峰",
        "南城","土窑馆","萧然居","铁木真部落","铁木真营帐",
        "蒙古草原","回族部落","小溪流","碎叶广场","王府井大街",
        "塘沽口","汝州城","永定门","山贼窝","草莓地",
        "长安乐坊","十字街头","长安城西门","乐府诗社","浣花溪",
        "银杏酒楼","金牛武馆","锦城驿","南诏德化碑","剑川镇",
        "玉虚观","星云湖畔","鲁望镇","喜州城","太和街口",
        "葛鲁城","圣湖","忘忧谷","大雪山北麓","华严顶",
        "凌云梯","十二盘","佛山镇街","英雄会馆","北帝庙",
        "福威镖局","南浔镇","向阳巷老宅","终南山主峰","寒水潭",
        "太湖","南浔镇","净慈寺","胡庆余堂","保淑塔",
        "风雷堂","圣姑堂","青龙堂大厅","哈萨克帐篷","平定州",
        "见性峰","大字岭","悬空寺","衡阳西街","刘府大院",
        "玄坛庙","打谷场","群仙观","莲花峰","莎萝坪",
        "五佛寺","古浪","黄河帮寨门","黄土高原","青城",
        "悦来客栈","归来客栈","碧桐园茶馆","定襄广场","养心殿",
        "天师洞","松风观","泉州南门","居庸关","峻极禅院",
        "嵩岳寺塔","万景山庄","沧浪亭","紫金庵","寒山寺",
        "玉皇顶","岱宗坊","黄山山门","般若台","清都瑶池",
        "澜沧江畔","吕祖庵","遇真宫","紫霄宫大门","朝天宫",
        "观景楼","青藏高原","安抚使衙门","玄武门外门","朱雀门外门",
        "日月洞","逍遥洞","雪山寺山门","雪山寺山门","观星台",
        "参合居","贵阳十字街头","扬州武馆","丽春院","草堂寺",
        "终南山脚","普光寺","重阳宫大门","祝融殿","福严寺",
        "缥缈峰山脚","独尊厅","高山湖泊","昆仑山门","迎风酒店",
        "五指堂","中指峰","无名峰","拇指峰","太白酒楼",
        "盛京城门","赵王府","马邑城中心","灵獒宫","巴颜喀拉山",
        "断肠崖","居庸关","星星峡","暖阁","皇宫正门",
        "潇湘馆","喜福堂","迎宾楼","囚室","净慈寺",
        "永安寺","坟墓内部","喜福堂","迎宾楼","回族部落",
        "马邑城中心","合肥广场","九江广场","巴陵广场","徐州东门",
        "济南衙门","雨花台","延福门","武昌码头","近日古楼",
        "岳阳西门","八角街","乌拉泊北城门","独柱寺","高丽赌场",
        "长沙广场","南昌广场","贵阳十字街头","碧鸡枋","滕王阁",
        }),
        });

mixed names = ({
        ({
        "少林广场","王府路","华藏庵","有所不为轩","紫霄宫大门",
        "天微堂","日月坪","大雪山山谷","六和塔","全真教大门", 
        "墓门","桃花山庄正厅","居庸关","独尊厅","星宿海", 
        "雪山寺山门","一品堂大院","昆仑派山门","五指堂", "玄妙观",
        "朱雀外门","青龙外门","白虎外门","玄武外门","天安门",
        "陈家铺子","福威镖局","玄妙观","灵隐寺","泉州南门",
        "灵州南门","诸葛亮殿","烟雨楼","南阳城","佛山南门",                
        "蛇骨塔","长安乐坊","衡阳西街","喜州城","葛鲁城", 
        "伊犁","山海关","老龙头","天山脚下","竹林小舍",
        "丽春院","涌泉寺","听雨轩","五老峰","紫金城",
        "松风观","终南山脚","抱子岩","白马潭","升仙坊",                
        "嘉应门","玄妙观","峻极禅院","侠义厅","萧家桥", 
        "凌霄内门","凌霄殿","峨嵋寝宫","渔家","天心岩",
        "嘉峪关","丝绸之路","黑风口","龙门峰","琼崖下",
        "南城","萧然居","铁木真部落","铁木真营帐","黑风口",
        "蒙古草原","回族部落","小溪流","碎叶广场","王府井大街",
        "塘沽口","汝州城","永定门","草莓地","大渡河边",
        "长安乐坊","十字街头","长安城西门","乐府诗社","浣花溪",
        "金牛武馆","锦城驿","南诏德化碑","剑川镇","江畔",
        "玉虚观","星云湖畔","鲁望镇","喜州城","太和街口",
        "葛鲁城","圣湖","忘忧谷","大雪山北麓","华严顶",
        "凌云梯","十二盘","佛山镇街","英雄会馆","北帝庙",
        "福威镖局","南浔镇","向阳巷老宅","终南山主峰","寒水潭",
        "太湖","南浔镇","净慈寺","胡庆余堂","保淑塔",
        "风雷堂","圣姑堂","青龙堂大厅","哈萨克帐篷","平定州",
        "大字岭","悬空寺","衡阳西街","刘府大院","茶亭",
        "玄坛庙","打谷场","群仙观","莲花峰","莎萝坪",
        "五佛寺","古浪","黄河帮寨门","黄土高原","青城",
        "漪澜堂","归来客栈","碧桐园茶馆","定襄广场","养心殿",
        "天师洞","松风观","泉州南门","居庸关","峻极禅院",
        "嵩岳寺塔","万景山庄","沧浪亭","紫金庵","寒山寺",
        "玉皇顶","岱宗坊","黄山山门","般若台","九龙壁",
        "澜沧江畔","玄岳门","遇真宫","紫霄宫大门","朝天宫",
        "观景楼","青藏高原","安抚使衙门","玄武门外门","朱雀门外门",
        "日月洞","逍遥洞","雪山寺山门","雪山寺山门","观星台",
        "梨香苑","贵阳十字街头","扬州武馆","丽春院","草堂寺",
        "终南山脚","普光寺","全真教大门","祝融殿","福严寺",
        "缥缈峰山脚","独尊厅","昆仑派山门","迎风酒店","惊神峰",
        "五指堂","中指峰","无名峰","拇指峰","太白酒楼",
        "盛京城门","赵王府","灵獒宫","巴颜喀拉山","星星峡",
        "居庸关","星星峡","暖阁","皇宫正门","惊神峰",
        "潇湘馆","喜福堂","迎宾楼","囚室","净慈寺",
        "永安寺","坟墓内部","喜福堂","迎宾楼","回族部落",
        "马邑城中心","合肥广场","九江广场","巴陵广场","徐州东门",
        "济南衙门","雨花台","延福门","武昌码头","近日古楼",
        "岳阳西门","八角街","乌拉泊北城门","独柱寺","高丽赌场",
        "长沙广场","南昌广场","贵阳十字街头","碧鸡枋","滕王阁",
        }),
        });
void init()
{
        add_action("give_quest", "quest");
        add_action("give_job", "job");
}


int give_job()
{      
        mapping changxi,changxiwhere;
        object me,ob;
        me = this_player(); 
        
    if( me->query_temp("obj/liangong")>0)
    {
                tell_object(me,"快去互相对练(duilian)吧。把武功练好,光大本门。\n");
                return 1;
    } 

        if( me->query("family/family_name")  !=  this_object()->query("mp"))
           {
                      message_vision("$N对着$n大喝一声："+this_object()->query("mp")+"的弟子才能做任务。你是哪来的奸细？????\n", this_object(), me);
                      return 1;
            }

message_vision("$N对着$n说道：你去找一个"+this_object()->query("mp")+"的弟子互相对练(duilian)一下吧。\n", this_object(), me);
        me->set_temp("obj/liangong", 8);
        //me->set_temp("obj/menpai",changxiwhere);
        return 1;   
}


int give_quest()
{
        object letter,ob,room2;
        mapping quest,item,npc,quests;
        object me;
        int j, combatexp, timep,factor,num,k,k1;
        string room;
string file;
string *roomlines;
string location,local,fname;
string *dir2;

        string tag = "2000000";
        string *levels = ({
                        "10000",
                        "15000",
                        "20000",
                        "30000",
                        "50000",
                        "80000",
                        "100000",
                        "130000",
                        "170000",
                        "220000",
                        "300000",
                        "450000",
                        "600000",
                        "800000",
                        "1000000",
                        "2000000"
        });


        me = this_player();
        combatexp = (int) (me->query("combat_exp"));



        
                if(me->query_temp("jobitem"))
        {
tell_object(me,"\n任务使笑着说到，你先把刚才让你找的东西找到给人家吧....”\n");
             return 1;
        }
                if(me->query_temp("roomjob"))
        {
tell_object(me,"\n任务使笑着说到，你先把刺探任务做好吧....”\n");
             return 1;
        }


if (me->is_busy() || this_object()->is_busy())
        {
tell_object(me,"\n任务使笑着说到，正忙着呢....”\n");
             return 1;
        }


        //if ((int)me->query_condition("roomjob")){message_vision("$N对着$n摇了摇头说：你刚接过刺探任务!等会再来!\n", this_object(), me);return 1;}

        if( me->query("family/family_name")  !=  this_object()->query("mp"))
           {
                      message_vision("$N对着$n大喝一声："+this_object()->query("mp")+"的弟子才能做任务。你是哪来的奸细？????\n", this_object(), me);
                      return 1;
            }

        if ((int)me->query_condition("menpai_busy"))  
            {
                      message_vision("$N对着$n摇了摇头说：你办事不利,等会再来!\n", this_object(), me);
                      return 1;
            }
        if(combatexp<10000)
        {
tell_object(me,"\n任务使笑着说到，你的武功还不行....”\n");
             return 1;

        }


        if((quest =  me->query("quest")))
        {
             if( ((int) me->query("task_time")) >  time() )
             {
tell_object(me,"任务使瞪了你一眼说道，我刚才要你做的事情呢？\n");
                  // me->set_temp("menpaijob",0);
                  // me->delete_temp("menpaijob");
                   return 0;
             }
             else
             {
             	  	message_vision("$N对着$n摇了摇头说：你办事不利,等会再来!\n", this_object(), me);
                 	
                 	me->apply_condition("menpai_busy",2+random(3));
                 	me->set_temp("menpaijob",0);
                   	me->delete_temp("menpaijob");
                   	me->set("quest",0);
                   	return 0;

             }
             
             
        }

 this_object()->start_busy(2);
        for(j= sizeof(levels) - 1 ; j>=0; j--)
        {
             combatexp=combatexp/3;
             if( atoi(levels[j])  <= combatexp )
             {
                   num=j;
                   factor=10;
                   break;
             }
        }
        if (num>0)
        {
             if (random(50)>45)
             {
                   num=num-1;
             }
        } 
        else
        {
             if ((num<sizeof(levels)-1)&&(random(100)>95))
             {
                   num=num+1;
                   factor=15;
             }
        }
        tag=levels[num];

 tag=levels[num];


me->set_temp("menpaikill",1);

//送信任务开始
 k=2;
 if (me->query_temp("menpaijob") >= 6 && me->query("combat_exp",1) < 2000000)
 {
k=6;
}

k1=3;
 if (me->query_temp("menpaijob") >= 10 && me->query("combat_exp",1) < 5000000)
 {
k1=6;
}
me->set("quest",0);
me->delete("quest");
        if (random(5) == 0 || (me->query("combat_exp") < 2000000 && random(k)==0))
        {
        //quest = lquest[random(sizeof(lquest))];
if (me->query("combat_exp",1) <=2000000)
quest = lquest1[random(sizeof(lquest1))];
else if (me->query("combat_exp",1) <=4000000)
quest = lquest2[random(sizeof(lquest2))];
else if (me->query("combat_exp",1) <=6000000)
quest = lquest3[random(sizeof(lquest3))];
else if (me->query("combat_exp",1) <=8000000)
quest = lquest4[random(sizeof(lquest4))];
else if (me->query("combat_exp",1) > 8000000)
quest = lquest[random(sizeof(lquest))];

//quest = lquest1[random(sizeof(lquest1))];
        timep = random(100) + 380;
        time_period(timep, me);
        tell_object(me, "到『" + quest["quest_city"] + "』附近,把信送给『" + quest["quest_name"] + "』你的任务就完成了。\n" NOR);
        message_vision("$N给了$n一封信。\n",this_object(),me);
        if (ob = present("xin", this_player()))
         {
             message_vision("任务使将以前的信收了回去！\n",me);
             me->delete_temp("menpaijob");
             destruct(ob);
             letter = new("/quest/menpai/letter");
                letter->set("long", "这是一封写给" + quest["quest_city"] + "附近的" +quest["quest_name"] + 
                                    "的亲笔信函。你可以用songxin <id>来送给别人。\n"); 
             letter->move(me);
             quest["quest_type"] = "把信送给";
             quest["exp_bonus"] = quest["exp_bonus"];
             quest["pot_bonus"] = quest["pot_bonus"];
             quest["score"] = 0;
             me->set("quest", quest);
             me->set("songxin",1);
             me->set("task_time", (int)time() + timep);
             me->set("quest_factor", factor);
             me->set("last_task_time", time());
             return 1;     
         }
         else
         {
            letter = new("/quest/menpai/letter");
                letter->set("long", "这是一封写给" + quest["quest_city"] + "附近的" + quest["quest_name"] + 
                                    "的亲笔信函。你可以用songxin <id>来送给别人。\n"); 
            letter->move(me);
            quest["quest_type"] = "把信送给";
            quest["exp_bonus"] = quest["exp_bonus"];
            quest["pot_bonus"] = quest["pot_bonus"];
            quest["score"] = 0;
            me->set("quest", quest);
            me->set("songxin",1);
            me->set("task_time", (int)time() + timep);
            me->set("quest_factor", factor);
            me->set("last_task_time", time());
if (me->query_temp("menpaijob") <= 0)
me->delete_temp("menpaijob");


if ((int)me->query_temp("menpaijob") >= 30 && random(3)==0)
{
me->add("mpgx",1);
tell_object(me,"你做的不错！你的门派贡献度增加了!\n" NOR);
tell_object(me,"目前为止,你的门派贡献度为『"HIC+chinese_number(me->query("mpgx"))+NOR"』。\n" NOR);
}

if (me->query_temp("menpaijob") > 1)
tell_object(me,"你已经连续为本门做了『"HIC+chinese_number(me->query_temp("menpaijob"))+NOR"』个任务了。\n" NOR);
         }
return 1;
}
else        if (random(5) == 0 || (me->query("combat_exp") < 5000000 && random(k1)==0))
{
	  //room=rooms[0][random(sizeof(rooms[0]))];
	file = read_file("/clone/medicine/dynamic_location");
	if (me->query("combat_exp",1)<=2000000)
	file = read_file("/clone/medicine/dynamic_location1");
	else if (me->query("combat_exp",1)<=4000000)
	file = read_file("/clone/medicine/dynamic_location2");
	else if (me->query("combat_exp",1)<=6000000)
	file = read_file("/clone/medicine/dynamic_location3");
else if (me->query("combat_exp",1)<=8000000)
	file = read_file("/clone/medicine/dynamic_location4");
else if (me->query("combat_exp",1)>8000000)
	file = read_file("/clone/medicine/dynamic_location5");

if (!file)
	file = read_file("/clone/medicine/dynamic_location");
	
	roomlines = explode(file,"\n");		
location = roomlines[random(sizeof(roomlines))];
room2=load_object(location);
if (!room2)
{
	file = read_file("/clone/medicine/dynamic_location");
	roomlines = explode(file,"\n");		
location = roomlines[random(sizeof(roomlines))];
room2=load_object(location);
}
local=room2->query("short");
if (!local)
{
	file = read_file("/clone/medicine/dynamic_location");
	roomlines = explode(file,"\n");		
location = roomlines[random(sizeof(roomlines))];
room2=load_object(location);
}
local=room2->query("short");
dir2=explode(base_name(room2),"/");
fname=base_name(room2);
zuji(dir2[1]);
room=zuji(dir2[1])+local;

         me->apply_condition("roomjob",10);
	         me->set_temp("roomjob",local);
        quest = lquest[random(sizeof(lquest))];
        //timep = 300+random(300)+10;
        //time_period(timep, me);
             quest["quest_type"] = "刺探";
             quest["quest"]=local;
             quest["exp_bonus"] = 30;
             quest["pot_bonus"] = 30;
             quest["time"]=600;
             quest["score"] = 10;
            me->set("quest", quest);
            me->set("task_time", (int)time() + 600);
            me->set("quest_factor", 15);
            me->set("last_task_time", time());
	  
	  tell_object(me,HIC"任务使说:我听说在『"HIR+room+HIC"』，发生了一些江湖事件。"+
           "你赶快去『"HIR+local+HIC"』刺探(citan)一下吧。\n"NOR);
if (wizardp(me))
	  tell_object(me,GRN"WIZ信息:刺探位置『"YEL+fname+GRN"』。\n"NOR);

if (me->query_temp("menpaijob") <= 0)
me->delete_temp("menpaijob");

if (me->query_temp("menpaijob") > 1)
tell_object(me,"你已经连续为本门做了『"HIC+chinese_number(me->query_temp("menpaijob"))+NOR"』个任务了。\n" NOR);
if ((int)me->query_temp("menpaijob") >= 8 && random(6)==0)
{
me->add("mpgx",1);
tell_object(me,"你做的不错！你的门派贡献度增加了!\n" NOR);
tell_object(me,"目前为止,你的门派贡献度为『"HIC+chinese_number(me->query("mpgx"))+NOR"』。\n" NOR);
}
return 1;
}
else


        if (random(5) == 0 )
        {
     quest = QUESTS_D(tag)->query_quest();
	}
       else
        if (random(5) == 1 )
        {
     quest = QUESTH_D(tag)->query_quest();
	}
       else
        if (random(5) == 2 )
        {
     quest = QUESTW_D(tag)->query_quest();
	}
       else if (random(16)==0 )
{
item  = QUESTW_D(tag)->query_quest();
npc = QUESTS_D(tag)->query_quest();
if (random(2)==1)
npc = QUESTH_D(tag)->query_quest();
 quest = lquest[random(sizeof(lquest))];
 if (me->query("combat_exp",1) <=2000000)
quest = lquest1[random(sizeof(lquest1))];
else if (me->query("combat_exp",1) <=4000000)
quest = lquest2[random(sizeof(lquest2))];
else if (me->query("combat_exp",1) <=6000000)
quest = lquest3[random(sizeof(lquest3))];
else if (me->query("combat_exp",1) <=8000000)
quest = lquest4[random(sizeof(lquest4))];
else if (me->query("combat_exp",1) > 8000000)
quest = lquest[random(sizeof(lquest))];

             quest["quest_type"] = "到"+item["quest_city"]+"找到"+item["quest"]+"然后到"+npc["quest_city"]+"给";
             quest["quest"]=npc["quest"];
             quest["exp_bonus"] = 30;
             quest["pot_bonus"] = 30;
             quest["time"]=800;
             quest["score"] = 10;
            me->set("quest", quest);
            me->set("task_time", (int)time() + 800);
            me->set("quest_factor", 15);
            me->set("last_task_time", time());
me->set_temp("jobitem",item["quest"]);
me->set_temp("jobnpc",npc["quest"]);
me->apply_condition("roomjob",8);
tell_object(me,HIC"任务使说道：请帮我到"+item["quest_city"]+"把『"HIG+item["quest"]+HIC"』找到，并到"+npc["quest_city"]+"交给『"HIG+npc["quest"]+HIC"』。\n" NOR);
if (me->query_temp("menpaijob") <= 0)
me->delete_temp("menpaijob");
//me->add_temp("menpaijob",1);
if (me->query_temp("menpaijob") > 1)
tell_object(me,"你已经连续为本门做了『"HIC+chinese_number(me->query_temp("menpaijob"))+NOR"』个任务了。\n" NOR);
if ((int)me->query_temp("menpaijob") >= 3 && random(5)==0)
{
me->add("mpgx",1);
tell_object(me,"你做的不错！你的门派贡献度增加了!\n" NOR);
tell_object(me,"目前为止,你的门派贡献度为『"HIC+chinese_number(me->query("mpgx"))+NOR"』。\n" NOR);
}

return 1;
}
else
	{
quest = QUESTW_D(tag)->query_quest();
}
//tell_object(me,tag);
//if (!quest) quest = QUESTW_D(tag)->query_quest();

//tell_object(me,quest["quest_type"]);
//tell_object(me,quest["quest"]);
        timep = quest["time"];
        if (!quest["time"]) timep=600;
        timep = timep+360;
        time_period(timep, me);
        if(quest["quest_type"]=="杀")
             tell_object(me,"到"+quest["quest_city"]+"把『"HIR+quest["quest"]+HIC"』杀了，他对本派不利。\n" NOR);
        else
             tell_object(me,"到"+quest["quest_city"]+"附近 找回『"HIG+quest["quest"]+HIC"』此物对本派有用。\n" NOR);
if (me->query_temp("menpaijob") <= 0)
me->delete_temp("menpaijob");

if (me->query_temp("menpaijob") > 1)
tell_object(me,"你已经连续为本门做了『"HIC+chinese_number(me->query_temp("menpaijob"))+NOR"』个任务了。\n" NOR);

if ((int)me->query_temp("menpaijob") >= 3 && random(4)==1)
{
me->add("mpgx",1);
tell_object(me,"你做的不错！你的门派贡献度增加了!\n" NOR);
tell_object(me,"目前为止,你的门派贡献度为『"HIC+chinese_number(me->query("mpgx"))+NOR"』。\n" NOR);
}

             quest["time"]=300;
             quest["exp_bonus"]=260+(int)me->query_temp("menpaijob");
             quest["pot_bonus"]=180+me->query_temp("menpaijob")/2;
             quest["score"]=50;
        me->set("quest", quest);
        me->set("task_time", (int) time()+(int) quest["time"]+180);
       
        return 1;
}

int time_period(int timep, object me)
{
        int t, d, h, m, s;
        string time;
        t = timep;
        s = t % 60;             t /= 60;
        m = t % 60;             t /= 60;
        h = t % 24;             t /= 24;
        d = t;

        if(d) time = chinese_number(d) + "天";
        else time = "";

        if(h) time += chinese_number(h) + "小时";
        if(m) time += chinese_number(m) + "分";
        time += chinese_number(s) + "秒";

        tell_object(me,HIC "任务使说道：请帮我在" + time + "内");
        return 1;
}

int accept_object(object who, object ob)
{
        int bonus, exp, pot, score,a;
        string test;
        mapping quest;
        object ob1;
        if (ob->query("money_id"))
        {
        	
             if(!who->query("quest") && !who->query_temp("jobitem") && !who->query_temp("roomjob"))
             {
                  tell_object(who,"没找到？你真差劲，看来还是请别的弟子帮忙算了！\n");
                   return 1;
             }
       if ( ob->value() < 2000)
             {
tell_object(who,"任务使看了看$P交上来的钱说道，太少了，这么点你也好意思拿出手！\n");
                   return 1;
             }
             else
             {

tell_object(who,"任务使说道，好吧，这次就算了，下不为例。\n");
                   who->set_temp("menpaijob",0);
                   who->set_temp("menpaijob",0);
                   who->delete_temp("menpaijob");
                who->delete_temp("jobitem");
                who->delete_temp("roomjob");
                   who->apply_condition("menpai_busy",8+random(8));who->delete_temp("menpaijob");
                   who->delete_temp("menpaijob");
                   who->set("quest",0);
                   who->delete("songxin");

         return 1;
        }
        }
        if(!(quest = who->query("quest")))
        {
             tell_object(who,"任务使说道：你秀逗了，我要的不是这个。\n");
             return 0;
        }

        if( ob->query("name") != quest["quest"])
        {
        tell_object(who,"任务使火冒三丈：这是什么？想鱼目浑珠呀，真是气死老夫了！\n");
        return 0;
        }

        if ((int) who->query("task_time") < time() )
        {
             tell_object(who,"任务使说道：对不起，时间过了，别的弟子刚把货物接走了！\n");
             destruct(ob);
             return 0;
        }
        else
        {
             tell_object(who,"任务使高兴地说道：太好了！我就是要这个，你真有本事！\n");
             exp = 150 + random(100)+(int)who->query_temp("menpaijob")/2;
             pot = 120 + random(30)+(int)who->query_temp("menpaijob")/3;
             score = 12 + random(5);

             bonus = (int) who->query("combat_exp");
             bonus += exp;
             who->set("combat_exp", bonus);
             bonus = (int) who->query("potential");
             bonus = bonus - (int) who->query("learned_points");
             bonus = bonus + pot;
             bonus += (int) who->query("learned_points");
             who->set("potential", bonus );
             bonus = (int) who->query("score");
             bonus += score;
             who->set("score", bonus);
             tell_object(who,HIW"恭喜你又完成一个任务！\n"NOR);
             tell_object(who,HIW"你被奖励了：" + chinese_number(exp)
               + "点实战经验，\n"+ chinese_number(pot) + "点潜能，\n"
               + chinese_number(score)+"点江湖阅历。\n"NOR);
             who->set("quest", 0 );
who->add_temp("menpaijob",1);
who->delete_temp("menpaikill");
a=FAMILY_D->query_family_fame(who->query("family/family_name"));

if (a> 10 && random(10)==0) 
{	
exp=(int)a/10+10;
pot=(int)exp*2/3+10;
	who->add("combat_exp",exp);
	who->add("potential",pot);

        tell_object(who, who->query("family/family_name")+"在江湖上的威望是" + chinese_number(a) + "。\n" NOR);
        tell_object(who,  "你的经验增长了" + chinese_number(exp) + "。潜能增长了"+chinese_number(pot) +
                         "。\n" NOR);

}
call_out("destroying", 1, ob, this_object(), who); 
//destruct(ob);
             return 1;
}
//destruct(ob);
        return 1;
}

void destroying(object obj, object ob, object me)
{   
   
   destruct(obj);
   return;      
}        
        
string ask_jianxi()
{     object guo,ob;
      object *team;
	  int i=0,count=0,minexp,maxexp;
int ckiller;
      string where;
	  guo =this_object();
	  ob=this_player();
	  if ((int)ob->query_temp("menpaijob")<1)
	  return "恩，现有有几件门派任务(quest)你先完成了再说吧。";
	  	
	  destruct(present("mi jian",ob));if (ob->query_condition("mjb2_busy")) return "我没有收到任何消息。";
	  
      if( ob->query("family/family_name") !=  this_object()->query("mp"))
      return  "只有"+this_object()->query("mp")+"的弟子才能做此任务!";
      //too low exp


      if(ob->query("combat_exp")<1500000)
      return  "你的功夫太差了。不要自寻死路!";//too low exp
      team=ob->query_team();
      count=sizeof(team);
	 // write("\n"+sprintf("%d",count));
	  if(count<=1 && !wizardp(ob))
      return "就你一个人?"; //too few people
      if(count>=5 && !wizardp(ob))
	  return "此事不宜张扬。"; //too many people
	  minexp=ob->query("combat_exp");
	  maxexp=minexp;destruct(present("mi jian",ob));if (ob->query_condition("mjb2_busy")) return "我没有收到任何消息。";
      
	  for(i=1;i<count;i++)
      { if(team[i]!=0)
	  { if(team[i]->query("combat_exp")<minexp)
	    minexp=team[i]->query("combat_exp");
		if(team[i]->query("combat_exp")>maxexp)
        maxexp=team[i]->query("combat_exp");
	  team[i]->apply_condition("mjb2_busy",38);
	  }
	  }
	  if ((maxexp-minexp)>3000000)
      return "你们的武功相差太悬殊。";//exp too far

	  where=names[0][random(sizeof(names[0]))];
	  guo->apply_condition("mjb_busy",30);
	  ob->set_temp("team_count",count);ob->set_temp("tjob",where);
	  ob->apply_condition("mjb_busy",60);
	  ob->apply_condition("mjb2_busy",38);
	  for(i=0;i<count;i++)
	  team[i]->apply_condition("mjb_busy",60);
ckiller=4;
	  for(i=100;i*i*i/10<=maxexp;i++);
         ob->apply_condition("mptjob",23);
ob->add_temp("menpaijob",-1);
	  return    "我刚得到消息，有一伙别派弟子与我派作对。派奸细偷去了我派的机要文件\n"+
		        "你们赶快去"+where+"设防阻截，把他们全部消灭。抢到文件后就地销毁(xiaohui)。\n"+
			    "肯定会有不少别派弟子接应他，多加小心。"; 
}

void unconcious()
{
	this_object()->reincarnate();
	this_object()->set("eff_qi", this_object()->query("max_qi"));
	this_object()->set("qi", this_object()->query("max_qi"));
	this_object()->set("eff_jing", this_object()->query("max_jing"));
	this_object()->set("jing", this_object()->query("max_jing"));
	this_object()->set("jingli", this_object()->query("eff_jingli"));
	this_object()->say( "任务使狞笑着说：我是无敌不死版！\n");
	this_object()->command("hehe");
}

void die()
{
	this_object()->unconcious();
}        


string ask_gift()
{     object who,ob,me;
      object *team;
	  int i=0,count=0,minexp,maxexp,a,exp,pot;
int ckiller,rn;
      string where;
string file;
string *roomlines;
string location;
int mi,yi,yai,lv,lb,money;
    string *ob_list = ({
                "/clone/family/jinkuai",
                "/clone/family/jintiao",
                "/clone/family/xiaoyuanbao",
                "/clone/family/dayuanbao",
                "/clone/family/jinding",
        });
	  who =this_player();
	  me=this_object();
        if( who->query("family/family_name")  !=  this_object()->query("mp"))
 return    "你是哪里的人啊?"; 	  


if ((int)who->query("mpgx") < 10)
	  return    "你的门派贡献度不够，现在贡献度为:"+chinese_number(who->query("mpgx"))+"。"; 	  


if (me->is_busy() || who->is_busy())
	  return    "正忙着呢。"; 	  

//me->start_busy(3);
a=FAMILY_D->query_family_fame(who->query("family/family_name"));

if (a> 10) 
{	
exp=(int)a/10+10;
pot=(int)exp*2/3+10;
	who->add("combat_exp",exp);
	who->add("potential",pot);
       message_vision("$n对$N微微一笑，道：干得不赖，我指点你二手武功吧。\n",
                       who, me);
        tell_object(who, who->query("family/family_name")+"在江湖上的威望是" + chinese_number(a) + "。\n" NOR);
        tell_object(who,  "你的经验增长了" + chinese_number(exp) + "。潜能增长了"+chinese_number(pot) +
                         "。\n" NOR);

}
        message_vision("$n对$N微微一笑，道：干得不赖，辛苦"
                       "了，行走江湖，总有各类开支应酬，这里有些金子，你就拿去吧。\n",
                       who, me);

                ob = new(ob_list[random(sizeof(ob_list))]);
        who->add("mpgx",-10);
        ob->move(who,1);
        tell_object(who, HIM "你获得了一" + ob->query("unit") + ob->name() +
                        HIM "。\n" NOR);
                ob = new("/clone/money/gold");
        money=88+random(188);
        if (who->query("combat_exp",1) < 1000000) money=10+random(50);
        if (who->query("combat_exp",1) < 2000000) money=30+random(30);
        if (who->query("combat_exp",1) < 3000000) money=60+random(60);
        if (who->query("combat_exp",1) < 4000000) money=80+random(80);
        tell_object(who, HIY "你获得了" + money +
                        HIY "两黄金。\n" NOR);

        ob->set_amount(money);
        ob->move(who,1);



if ( (random(8)==0 && (int)who->query("combat_exp",1) > 3000000))
{
lv=0;
lb=random(28)+1;
if (random(2)==0 && lb <=12 ) lb= 12+random(17);
if (random(3)==0 && lb <=12 ) lb= 12+random(17);


if (random(4)==0) lv=100;
if (random(16)==0) lv=200;
if (random(32)==0) lv=300;
if (random(64)==0) lv=400;
if (random(128)==0) lv=500;	
if (random(256)==0) lv=600;
if (random(512)==0) lv=700;
if (random(1024)==0) lv=800;


if (random(2)==0 && lv >=300 ) lv= 300;
if (random(3)==0 && lv >=400 ) lv= 400;

if ((int)who->query("combat_exp",1) < 5000000)
{
	if (lv> 500) lv=500;
}

if ((int)who->query("combat_exp",1) < 10000000)
{
	if (lv> 600) lv=600;
}

if ((int)who->query("combat_exp",1) < 15000000)
{
	if (lv> 700) lv=700;
}

lb=lb+lv;


        message_vision("$n对$N微微一笑，道：干得好，辛苦"
                       "了，行走江湖，总要有件趁手的武器，这里有些升级装备的宝石，你就拿去吧。\n",
                       who, me);
           ob = new("/p/newweapon/weaponobj/jade"+lb);
           ob->move(who);
        tell_object(who, HIM "你获得了一" + ob->query("unit") + ob->name() +
                        HIM "。\n" NOR);
//return    "你现在的等级为:"+lb+"。"; 
}

if (random(5)==0)
{
file = read_file("/clone/medicine/ycgift");
roomlines = explode(file,"\n");	
location = roomlines[random(sizeof(roomlines))];
        message_vision("$n对$N微微一笑，道：干得不赖，辛苦"
                       "了，行走江湖，总有各种危险，这里有些伤药，你就拿去吧。\n",
                       who, me);
           ob = new(location);
if (ob)
{
           ob->move(who);
        tell_object(who, HIM "你获得了一" + ob->query("unit") + ob->name() +
                        HIM "。\n" NOR);
}
}
rn=8;
if ((int)who->query("combat_exp",1) < 2000000)
{
rn=16;
}






if (random(rn)==0)
{
	file = read_file("/clone/medicine/wgift");
roomlines = explode(file,"\n");	
location = roomlines[random(sizeof(roomlines))];
        message_vision("$n对$N微微一笑，道：干得不赖，辛苦"
                       "了，行走江湖，总要用各种装备，这里有些装备，你就拿去吧。\n",
                       who, me);
           ob = new(location);
if (ob)
{
           ob->move(who);
        tell_object(who, HIM "你获得了一" + ob->query("unit") + ob->name() +
                        HIM "。\n" NOR);
}


}
mi=1;
if (random(4)==0) mi=2;
if (random(8)==0) mi=3;
if (random(16)==0) mi=4;
if (random(32)==0) mi=5;
if (random(64)==0) mi=6;	
if (random(128)==0) mi=7;
if (random(256)==0) mi=8;
if (random(512)==0) mi=9;
if (random(1024)==0) mi=10;				

yi=1;
if (random(8)==0) yi=2;
if (random(16)==0) yi=3;
if (random(32)==0) yi=4;
if (random(64)==0) yi=5;
if (random(128)==0) yi=6;	

yai=7;
if (random(8)==0) yai=8;
if (random(16)==0) yai=9;
if (random(32)==0) yai=10;
if (random(64)==0) yai=11;
if (random(128)==0) yai=12;	


if ((int)who->query("combat_exp",1) < 10000000)
{
	if (mi> 6) mi=6;
	if (yi> 4) yi=4;
	if (yai> 10) yai=10;
}

if ((int)who->query("combat_exp",1) < 5000000)
{
	if (mi> 5) mi=5;
	if (yi> 3) yi=3;
	if (yai> 9) yai=9;
}


if ((int)who->query("combat_exp",1) < 2000000)
{
	if (mi> 3) mi=3;
	if (yi> 2) yi=2;
	if (yai> 8) yai=8;
}





if (random(3)==0)
{
        message_vision("$n对$N微微一笑，道：干得不赖，辛苦"
                       "了，行走江湖，总要有打造些东西，这里有些打造道具的矿石，你就拿去吧。\n",
                       who, me);
           ob = new("/p/newweapon/weaponobj/kuangshi"+mi);
           ob->move(who);
        tell_object(who, HIM "你获得了一" + ob->query("unit") + ob->name() +
                        HIM "。\n" NOR);
}

if (random(3)==0)
{
        message_vision("$n对$N微微一笑，道：干得不赖，辛苦"
                       "了，行走江湖，总要有打造些防具，这里有些打造武器的布料，你就拿去吧。\n",
                       who, me);
           ob = new("/p/newweapon/weaponobj/buliao"+mi);
           ob->move(who);
        tell_object(who, HIM "你获得了一" + ob->query("unit") + ob->name() +
                        HIM "。\n" NOR);
}

if (random(8)==0)
{
        message_vision("$n对$N微微一笑，道：干得不赖，辛苦"
                       "了，行走江湖，总要有打造些武器，这里有些打造武器的玉石，你就拿去吧。\n",
                       who, me);
           ob = new("/p/newweapon/weaponobj/material"+yi);
           ob->move(who);
        tell_object(who, HIM "你获得了一" + ob->query("unit") + ob->name() +
                        HIM "。\n" NOR);
}

if (random(8)==0)
{
        message_vision("$n对$N微微一笑，道：干得不赖，辛苦"
                       "了，行走江湖，总要有打造些防具，这里有些打造防具的玉石，你就拿去吧。\n",
                       who, me);
           ob = new("/p/newweapon/weaponobj/material"+yai);
           ob->move(who);
        tell_object(who, HIM "你获得了一" + ob->query("unit") + ob->name() +
                        HIM "。\n" NOR);
}

if (random(9)==0 && (int)who->query("combat_exp",1) > 1000000)
{
        message_vision("$n对$N微微一笑，道：干得不赖，辛苦"
                       "了，行走江湖，总要有自造武器，这里有些造武器的宝石，你就拿去吧。\n",
                       who, me);
           ob = new("/clone/gem/gem");
           ob->move(who);
        tell_object(who, HIM "你获得了一" + ob->query("unit") + ob->name() +
                        HIM "。\n" NOR);
}
        who->save();
	  

	  return    "你现在的师门贡献度为:"+chinese_number(who->query("mpgx"))+"。"; 
}


string  zuji(string str)
{   
string output;
      	if (str=="baituo")  

	output="白驼山的";

if (str=="binghuodao")  

	output="冰火岛的";

if (str=="city")  

	output="扬州的";

if (str=="city2" || str=="beijing"  || str=="huanggon"  || str=="huanggong" || str=="beihai")  

	output="北京城的";

if (str=="city4" || str=="changan")   

	output="长安城的";

if (str=="dali")  

	output="大理的";

if (str=="emei")  

	output="娥眉山的";

if (str=="foshan")  

	output="佛山的";

if (str=="gaibang")  

	output="丐帮的";

if (str=="gaochang")  

	output="高昌迷宫的";

if (str=="guanwai")  

	output="关外的";

if (str=="guiyun")  

	output="归云庄的";

if (str=="gumu")  

	output="古墓派的";

if (str=="hangzhou")  

	output="杭州的";

if (str=="heimuya")  

	output="黑木崖的";

if (str=="hengshan")  

	output="恒山的";

if (str=="henshan")  

	output="衡山的";

if (str=="huanghe")  

	output="黄河九曲的";

if (str=="huashan")  

	output="华山的";

if (str=="jinshe")  

	output="金蛇山洞的";

if (str=="lingjiu")  

	output="灵鹫宫的";

if (str=="lingzhou")  

	output="灵州的";

if (str=="meizhuang")  

	output="梅庄的";

if (str=="mingjiao")  

	output="明教的";

if (str=="qingcheng")  

	output="青城山的";

if (str=="quanzhen")  

	output="全真派的";

if (str=="quanzhou")  

	output="泉州的";

if (str=="shaolin")  

	output="少林寺的";

if (str=="shenlong")  

	output="神龙岛的";

if (str=="songshan")  

	output="嵩山的";

if (str=="suzhou")  

	output="苏州的";

if (str=="taishan")  

	output="泰山的";

if (str=="taohua")  

	output="桃花岛的";

if (str=="tianlongsi")  

	output="天龙寺的";

if (str=="wanjiegu")  

	output="万劫谷的";

if (str=="wudang")  

	output="武当山的";

if (str=="xiakedao")  

	output="侠客岛的";

if (str=="xiangyang")  

	output="襄阳城的";

if (str=="xiaoyao")  

	output="逍遥林的";

if (str=="xingxiu")  

	output="星宿海的";

if (str=="xueshan")  

	output="雪山寺的";

if (str=="xuedao")  

	output="大雪山的";

if (str=="mr")  

	output="慕容世家的";

if (str=="kunlun")  

	output="昆仑山的";

if (str=="tiezhang")  

	output="铁掌门的";

if (str=="huizhu")  

	output="回族部落的";

if (str=="yinju")  

	output="一灯大师居的";

if (str=="menggu")  

	output="蒙古草原的";

if (str=="qianjin")  

	output="北京千金楼的";

if (str=="lingshedao")  

	output="灵蛇岛的";

if (str=="ruzhou")  

	output="汝州城的";

if (str=="kunming")  

	output="昆明的";

if (str=="jingzhou")  

	output="荆州的";

if (str=="yanjing")  

	output="燕京的";

if (str=="lanzhou" || str=="lanzhouchen")  

	output="兰州的";

if (str=="jyguan")  

	output="兰州以北嘉峪关的";

if (str=="changcheng")  

	output="北京以北长城的";

if (str=="fairyland")  

	output="昆仑的红梅山庄";

if (str=="sdxl")  

	output="剑魔独孤求败墓";

if (str=="jqg")  

	output="绝情谷";

if (str=="nio")  

	output="牛家村的";

if (str=="feihu")  

	output="闯王宝藏的";

if (str=="wuguan")  

	output="襄阳武馆的";

if (str=="village")  

	output="华山村的";

if (str=="taohuacun")  

	output="桃花村的";

if (str=="pingan")  

	output="平安城的";

if (str=="lingxiao")  

	output="凌霄城的";

if (str=="wudujiao")  

	output="五毒教的";

if (str=="hj")  

	output="天山。草原的";
if (str=="dali/yuxu")  

	output="大理玉虚观的";
if (str=="dali/wuliang")  

	output="大理无量山的";
if (str=="huanghe/yyd")  

	output="黄河萧府的";
if (str=="kaifeng")  

	output="开封城的";
if (str=="feitian")  

	output="飞天御剑流的";
if (str=="japan")  

	output="日本神户的";
if (str=="tangmen")  

	output="唐门的";
if (str=="luoyang")  

	output="洛阳城的";

if (str=="chengdu" || str=="city3")  

	output="成都的";

if (str=="baihuagu")  

	output="百花谷的";

if (str=="heizhao")  

	output="百花谷。黑沼的";

if (str=="jiaxing")  

	output="嘉兴的";

if (str=="shiliang")  

	output="温家庄的";

if (str=="wuyi")  

	output="武夷山区的";

if (str=="yanping")  

	output="延平城的";
	

if (str=="jiangling")  
{
	output="江陵城的";
}

if (str=="yueyang")  
{
	output="岳阳城的";	
}

if (str=="qilian")  
{
	output="祁连山的";	
}

if (str=="shouxihu")  
{
	output="瘦西湖的";	
}

if (str=="wuxi")  
{
	output="无锡城的";	
}

if (str=="yixing")  
{
	output="宜兴城的";	
}
if (str=="taiwan")  
{
	output="台湾地区的";	
}
if (str=="nanyang")  
{
	output="南阳地区的";	
}
if (str=="nanshaolin")  
{
	output="南少林地区的";	
}

if (str=="cangzhou")  
{
	output="沧州地区的";	
}

if (str=="tanggu")  
{
	output="塘沽城地区的";	
}

if (str=="yunhe")  
{
	output="京杭大运河的";	
}

if (str=="hainan")  
{
	output="海南岛的";	
}

if (str=="jindezheng")  
{
	output="景德镇的";	
}

if (str=="yandang")  
{
	output="雁荡山的";	
}

if (str=="jinling")  
{
	output="金陵城的";	
}

if (str=="sandboy")  
{
	output="江南农村的";	
}

if (str=="huangshan")  
{
	output="黄山的";	
}

if (str=="yubifeng")  
{
	output="玉笔峰的";	
}

if (str=="quanzhouchen")  
{
	output="泉州城内的";	
}

if (str=="qingzh")  
{
	output="青藏高原";	
}

if (str=="changbaishan" || str=="gaoli")  
{
	output="高丽 长白山的";	
}

if (str=="annan")  
{
	output="安南附近的";	
}

if (str=="taiyuan")  
{
	output="太原附近的";	
}

if (str=="hefei")  
{
	output="合肥附近的";	
}

if (str=="jiujiang")  
{
	output="九江附近的";	
}

if (str=="baling")  
{
	output="巴陵附近的";	
}

if (str=="xinjiang")  
{
	output="新疆附近的";	
}
if (str=="dingxiang")  
{
	output="定襄附近的";	
}
if (str=="suiye")  
{
	output="碎叶附近的";	
}


if (str=="mayi")  
{
	output="马邑边疆附近的";	
}
if (str=="xuzhou")  
{
	output="徐州城附近的";	
}
if (str=="jinan")  
{
	output="济南城附近的";	
}
if (str=="guizhou")  
{
	output="贵阳城附近的";	
}

if (str=="nanchang")  
{
	output="南昌城附近的";	
}


if (str=="changsha")  
{
	output="长沙城附近的";	
}


if (str=="zhongzhou")  
{
	output="中州城附近的";	
}

if (str=="xizang" || str=="zangbei")  
{
	output="西藏或藏北附近的";	
}

return output;
}