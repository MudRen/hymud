// qslist8000.c

inherit SKILL;
#include <ansi.h>;
mapping *quest = ({
([ "quest":  "肥肥", "quest_type":"杀", "time":   380, "exp_bonus":76, "pot_bonus":50, "score" : 20,"quest_city":"白驼附近" ]),
([ "quest":  "管家", "quest_type":"杀", "time":   280, "exp_bonus":76, "pot_bonus":50, "score" : 20,"quest_city":"白驼附近" ]),
([ "quest":  "李教头", "quest_type":"杀", "time":   480, "exp_bonus":76, "pot_bonus":50, "score" : 20,"quest_city":"白驼附近" ]),
([ "quest":  "花花公子", "quest_type":"杀", "time":   380, "exp_bonus":76, "pot_bonus":50, "score" : 20,"quest_city":"白驼附近" ]),
([ "quest":  "小山贼", "quest_type":"杀", "time":   380, "exp_bonus":76, "pot_bonus":50, "score" : 20,"quest_city":"白驼附近" ]),
([ "quest":  "山贼", "quest_type":"杀", "time":   380, "exp_bonus":76, "pot_bonus":50, "score" : 20,"quest_city":"白驼附近" ]),
([ "quest":  "舞蛇人", "quest_type":"杀", "time":   380, "exp_bonus":76, "pot_bonus":50, "score" : 20,"quest_city":"白驼附近" ]),
([ "quest":  "管家", "quest_type":"杀", "time":   380, "exp_bonus":76, "pot_bonus":50, "score" : 20,"quest_city":"白驼附近" ]),
	
([ "quest":  "崔员外", "quest_type":"杀", "time":   380, "exp_bonus":76, "pot_bonus":50, "score" : 20,"quest_city":"扬州附近" ]),
([ "quest":  "流氓", "quest_type":"杀", "time":   280, "exp_bonus":76, "pot_bonus":50, "score" : 20,"quest_city":"扬州附近" ]),
([ "quest":  "流氓头", "quest_type":"杀", "time":   380, "exp_bonus":76, "pot_bonus":50, "score" : 20,"quest_city":"扬州附近" ]),
([ "quest":  "冼老板", "quest_type":"杀", "time":   580, "exp_bonus":76, "pot_bonus":50, "score" : 20,"quest_city":"扬州附近" ]),
([ "quest":  "小桂子", "quest_type":"杀", "time":   380, "exp_bonus":76, "pot_bonus":50, "score" : 20,"quest_city":"扬州附近" ]),
([ "quest":  "王五", "quest_type":"杀", "time":   200, "exp_bonus":76, "pot_bonus":50, "score" : 20,"quest_city":"扬州附近" ]),
([ "quest":  "海公公", "quest_type":"杀", "time":   400, "exp_bonus":76, "pot_bonus":50, "score" : 20,"quest_city":"扬州附近" ]),
	
([ "quest":  "小流氓", "quest_type":"杀", "time":   280, "exp_bonus":76, "pot_bonus":50, "score" : 20,"quest_city":"北京附近" ]),
([ "quest":  "地痞", "quest_type":"杀", "time":   380, "exp_bonus":76, "pot_bonus":50, "score" : 20,"quest_city":"北京附近" ]),

([ "quest":  "「平通镖局」镖头", "quest_type":"杀", "time":   380, "exp_bonus":76, "pot_bonus":50, "score" : 20,"quest_city":"大理附近" ]),
([ "quest":  "恶奴", "quest_type":"杀", "time":   480, "exp_bonus":76, "pot_bonus":50, "score" : 20,"quest_city":"大理附近" ]),
([ "quest":  "贵公子", "quest_type":"杀", "time":   480, "exp_bonus":76, "pot_bonus":50, "score" : 20,"quest_city":"大理附近" ]),
([ "quest":  "何红药", "quest_type":"杀", "time":   680, "exp_bonus":76, "pot_bonus":50, "score" : 20,"quest_city":"大理附近" ]),
([ "quest":  "祭司", "quest_type":"杀", "time":   380, "exp_bonus":76, "pot_bonus":50, "score" : 20,"quest_city":"大理附近" ]),
([ "quest":  "段无畏", "quest_type":"杀", "time":   500, "exp_bonus":76, "pot_bonus":50, "score" : 20,"quest_city":"大理附近" ]),
([ "quest":  "老祭司", "quest_type":"杀", "time":   500, "exp_bonus":76, "pot_bonus":50, "score" : 20,"quest_city":"大理附近" ]),
([ "quest":  "乌夷老祭司", "quest_type":"杀", "time":   500, "exp_bonus":76, "pot_bonus":50, "score" : 20,"quest_city":"大理附近" ]),
([ "quest":  "族头人", "quest_type":"杀", "time":   500, "exp_bonus":76, "pot_bonus":50, "score" : 20,"quest_city":"大理附近" ]),
([ "quest":  "族长", "quest_type":"杀", "time":   500, "exp_bonus":76, "pot_bonus":50, "score" : 20,"quest_city":"大理附近" ]),
	
([ "quest":  "神农帮弟子", "quest_type":"杀", "time":   300, "exp_bonus":76, "pot_bonus":50, "score" : 20,"quest_city":"无量山附近" ]),
([ "quest":  "无量剑弟子", "quest_type":"杀", "time":   300, "exp_bonus":76, "pot_bonus":50, "score" : 20,"quest_city":"无量山附近" ]),

([ "quest":  "段天德", "quest_type":"杀", "time":   400, "exp_bonus":76, "pot_bonus":50, "score" : 20,"quest_city":"归云庄附近" ]),
([ "quest":  "大金兵", "quest_type":"杀", "time":   380, "exp_bonus":76, "pot_bonus":50, "score" : 20,"quest_city":"归云庄附近" ]),

([ "quest":  "刀客", "quest_type":"杀", "time":   380, "exp_bonus":76, "pot_bonus":50, "score" : 20,"quest_city":"明教附近" ]),
([ "quest":  "剑客", "quest_type":"杀", "time":   500, "exp_bonus":76, "pot_bonus":50, "score" : 20,"quest_city":"明教附近" ]),
([ "quest":  "高山王", "quest_type":"杀", "time":   400, "exp_bonus":76, "pot_bonus":50, "score" : 20,"quest_city":"明教附近" ]),

([ "quest":  "日月神教教徒", "quest_type":"杀", "time":   380, "exp_bonus":76, "pot_bonus":50, "score" : 20,"quest_city":"黑木崖附近" ]),

([ "quest":  "蒙面人", "quest_type":"杀", "time":   500, "exp_bonus":76, "pot_bonus":50, "score" : 20,"quest_city":"黄河九曲附近" ]),
([ "quest":  "马青雄", "quest_type":"杀", "time":   500, "exp_bonus":76, "pot_bonus":50, "score" : 20,"quest_city":"黄河九曲附近" ]),
([ "quest":  "马贼", "quest_type":"杀", "time":   380, "exp_bonus":76, "pot_bonus":50, "score" : 20,"quest_city":"黄河九曲附近" ]),
([ "quest":  "钱青健", "quest_type":"杀", "time":   500, "exp_bonus":76, "pot_bonus":50, "score" : 20,"quest_city":"黄河九曲附近" ]),
([ "quest":  "沈青刚", "quest_type":"杀", "time":   500, "exp_bonus":76, "pot_bonus":50, "score" : 20,"quest_city":"黄河九曲附近" ]),
([ "quest":  "吴青烈", "quest_type":"杀", "time":   500, "exp_bonus":76, "pot_bonus":50, "score" : 20,"quest_city":"黄河九曲附近" ]),
([ "quest":  "西夏兵", "quest_type":"杀", "time":   380, "exp_bonus":76, "pot_bonus":50, "score" : 20,"quest_city":"黄河九曲附近" ]),

([ "quest":  "李铁嘴", "quest_type":"杀", "time":   380, "exp_bonus":76, "pot_bonus":50, "score" : 20,"quest_city":"华山村附近" ]),

([ "quest":  "校尉", "quest_type":"杀", "time":   500, "exp_bonus":76, "pot_bonus":50, "score" : 20,"quest_city":"灵州附近" ]),
([ "quest":  "一品堂武士", "quest_type":"杀", "time":   600, "exp_bonus":76, "pot_bonus":50, "score" : 20,"quest_city":"灵州附近" ]),
([ "quest":  "石人武士", "quest_type":"杀", "time":   600, "exp_bonus":76, "pot_bonus":50, "score" : 20 ,"quest_city":"灵州附近"]),
([ "quest":  "校尉", "quest_type":"杀", "time":   600, "exp_bonus":76, "pot_bonus":50, "score" : 20,"quest_city":"灵州附近" ]),

([ "quest":  "年轻女弟子", "quest_type":"杀", "time":   400, "exp_bonus":76, "pot_bonus":50, "score" : 20,"quest_city":"神龙岛附近" ]),
([ "quest":  "老者", "quest_type":"杀", "time":   400, "exp_bonus":76, "pot_bonus":50, "score" : 20,"quest_city":"神龙岛附近" ]),

([ "quest":  "章老三", "quest_type":"杀", "time":   400, "exp_bonus":76, "pot_bonus":50, "score" : 20 ,"quest_city":"北京附近"]),

([ "quest":  "进喜儿", "quest_type":"杀", "time":   500, "exp_bonus":76, "pot_bonus":50, "score" : 20,"quest_city":"万劫谷附近" ]),

([ "quest":  "土匪", "quest_type":"杀", "time":   400, "exp_bonus":76, "pot_bonus":50, "score" : 20,"quest_city":"武当山附近" ]),
([ "quest":  "土匪头", "quest_type":"杀", "time":   600, "exp_bonus":76, "pot_bonus":50, "score" : 20,"quest_city":"武当山附近" ]),
([ "quest":  "小土匪", "quest_type":"杀", "time":   300, "exp_bonus":76, "pot_bonus":50, "score" : 20,"quest_city":"武当山附近" ]),

([ "quest":  "巴依", "quest_type":"杀", "time":   300, "exp_bonus":76, "pot_bonus":50, "score" : 20,"quest_city":"天山附近" ]),

([ "quest":  "星宿派钹手", "quest_type":"杀", "time":   380, "exp_bonus":76, "pot_bonus":50, "score" : 20,"quest_city":"星宿海附近" ]),
([ "quest":  "采花子", "quest_type":"杀", "time":   380, "exp_bonus":76, "pot_bonus":50, "score" : 20,"quest_city":"星宿海附近" ]),
([ "quest":  "星宿派鼓手", "quest_type":"杀", "time":   380, "exp_bonus":76, "pot_bonus":50, "score" : 20,"quest_city":"星宿海附近" ]),
([ "quest":  "星宿派号手", "quest_type":"杀", "time":   380, "exp_bonus":76, "pot_bonus":50, "score" : 20,"quest_city":"星宿海附近" ]),
([ "quest":  "阿紫", "quest_type":"杀", "time":   400, "exp_bonus":76, "pot_bonus":50, "score" : 20,"quest_city":"星宿海附近" ]),
	
([ "quest":  "守寺僧兵", "quest_type":"杀", "time":   400, "exp_bonus":76, "pot_bonus":50, "score" : 20,"quest_city":"雪山寺附近" ]),
([ "quest":  "小喇嘛", "quest_type":"杀", "time":   400, "exp_bonus":76, "pot_bonus":50, "score" : 20,"quest_city":"雪山寺附近" ]),

([ "quest":  "劳德诺", "quest_type":"杀", "time":   300, "exp_bonus":76, "pot_bonus":50, "score" : 20 ,"quest_city":"华山附近"]),
([ "quest":  "林平之", "quest_type":"杀", "time":   200, "exp_bonus":76, "pot_bonus":50, "score" : 20,"quest_city":"华山附近" ]),

([ "quest":  "忽伦大虎", "quest_type":"杀", "time":   400, "exp_bonus":76, "pot_bonus":50, "score" : 20 ,"quest_city":"关外附近"]),
([ "quest":  "忽伦二虎", "quest_type":"杀", "time":   400, "exp_bonus":76, "pot_bonus":50, "score" : 20 ,"quest_city":"关外附近"]),
([ "quest":  "忽伦三虎", "quest_type":"杀", "time":   400, "exp_bonus":76, "pot_bonus":50, "score" : 20,"quest_city":"关外附近" ]),
([ "quest":  "忽伦四虎", "quest_type":"杀", "time":   400, "exp_bonus":76, "pot_bonus":50, "score" : 20,"quest_city":"关外附近" ]),
([ "quest":  "阎基", "quest_type":"杀", "time":   400, "exp_bonus":76, "pot_bonus":50, "score" : 20 ,"quest_city":"关外附近"]),
	
([ "quest":  "段天德", "quest_type":"杀", "time":   400, "exp_bonus":76, "pot_bonus":50, "score" : 20,"quest_city":"归云庄附近" ]),
([ "quest":  "大金兵", "quest_type":"杀", "time":   400, "exp_bonus":76, "pot_bonus":50, "score" : 20 ,"quest_city":"归云庄附近"]),

([ "quest":  "完颜洪烈", "quest_type":"杀", "time":   400, "exp_bonus":76, "pot_bonus":50, "score" : 20,"quest_city":"燕京附近" ]),
([ "quest":  "完颜康", "quest_type":"杀", "time":   400, "exp_bonus":76, "pot_bonus":50, "score" : 20,"quest_city":"燕京附近" ]),

([ "quest":  "褚圆", "quest_type":"杀", "time":   400, "exp_bonus":76, "pot_bonus":50, "score" : 20 ,"quest_city":"杭州附近"]),
([ "quest":  "李可秀", "quest_type":"杀", "time":   400, "exp_bonus":76, "pot_bonus":50, "score" : 20 ,"quest_city":"杭州附近"]),
([ "quest":  "龙骏", "quest_type":"杀", "time":   400, "exp_bonus":76, "pot_bonus":50, "score" : 20,"quest_city":"杭州附近" ]),

([ "quest":  "方人智", "quest_type":"杀", "time":   500, "exp_bonus":76, "pot_bonus":50, "score" : 20 ,"quest_city":"青城山附近"]),
([ "quest":  "洪人雄", "quest_type":"杀", "time":   500, "exp_bonus":76, "pot_bonus":50, "score" : 20,"quest_city":"青城山附近" ]),
([ "quest":  "侯人英", "quest_type":"杀", "time":   500, "exp_bonus":76, "pot_bonus":50, "score" : 20 ,"quest_city":"青城山附近"]),
([ "quest":  "吉人通", "quest_type":"杀", "time":   500, "exp_bonus":76, "pot_bonus":50, "score" : 20,"quest_city":"青城山附近" ]),
([ "quest":  "贾人达", "quest_type":"杀", "time":   500, "exp_bonus":76, "pot_bonus":50, "score" : 20,"quest_city":"青城山附近" ]),
([ "quest":  "罗人杰", "quest_type":"杀", "time":   500, "exp_bonus":76, "pot_bonus":50, "score" : 20,"quest_city":"青城山附近" ]),
([ "quest":  "申人俊", "quest_type":"杀", "time":   500, "exp_bonus":76, "pot_bonus":50, "score" : 20,"quest_city":"青城山附近" ]),
([ "quest":  "于人豪", "quest_type":"杀", "time":   500, "exp_bonus":76, "pot_bonus":50, "score" : 20,"quest_city":"青城山附近" ]),
([ "quest":  "余人彦", "quest_type":"杀", "time":   500, "exp_bonus":76, "pot_bonus":50, "score" : 20,"quest_city":"青城山附近" ]),
	
([ "quest":  "红毛鬼", "quest_type":"杀", "time":   400, "exp_bonus":76, "pot_bonus":50, "score" : 20 ,"quest_city":"台湾附近"]),
([ "quest":  "倭寇", "quest_type":"杀", "time":   400, "exp_bonus":76, "pot_bonus":50, "score" : 20,"quest_city":"台湾附近" ]),

([ "quest":  "李莫愁", "quest_type":"杀", "time":   400, "exp_bonus":76, "pot_bonus":50, "score" : 20,"quest_city":"嘉兴附近" ]),

([ "quest":  "游讯", "quest_type":"杀", "time":   400, "exp_bonus":76, "pot_bonus":50, "score" : 20,"quest_city":"泉州附近" ]),

([ "quest":  "高克新", "quest_type":"杀", "time":   400, "exp_bonus":76, "pot_bonus":50, "score" : 20 ,"quest_city":"嵩山附近"]),
([ "quest":  "陆柏", "quest_type":"杀", "time":   400, "exp_bonus":76, "pot_bonus":50, "score" : 20,"quest_city":"嵩山附近" ]),
([ "quest":  "沙天江", "quest_type":"杀", "time":   400, "exp_bonus":76, "pot_bonus":50, "score" : 20,"quest_city":"嵩山附近" ]),
([ "quest":  "史登达", "quest_type":"杀", "time":   400, "exp_bonus":76, "pot_bonus":50, "score" : 20,"quest_city":"嵩山附近" ]),
([ "quest":  "汤英鹄", "quest_type":"杀", "time":   400, "exp_bonus":76, "pot_bonus":50, "score" : 20,"quest_city":"嵩山附近" ]),
([ "quest":  "万大平", "quest_type":"杀", "time":   400, "exp_bonus":76, "pot_bonus":50, "score" : 20 ,"quest_city":"嵩山附近"]),
([ "quest":  "乐厚", "quest_type":"杀", "time":   400, "exp_bonus":76, "pot_bonus":50, "score" : 20,"quest_city":"嵩山附近" ]),
	
(["quest":  "霍桑",  "quest_type":"杀", "time":   400, "exp_bonus":76, "pot_bonus":50, "score" : 20,"quest_city":"高昌城附近" ]),
(["quest":  "买买提",  "quest_type":"杀", "time":   400, "exp_bonus":76, "pot_bonus":50, "score" : 20,"quest_city":"高昌城附近" ]),
(["quest":  "驿长",  "quest_type":"杀", "time":   400, "exp_bonus":76, "pot_bonus":50, "score" : 20,"quest_city":"高昌城附近" ]),

(["quest":  "张百万",  "quest_type":"杀", "time":   400, "exp_bonus":76, "pot_bonus":50, "score" : 20,"quest_city":"绮云镇附近" ]),
(["quest":  "铁豹",  "quest_type":"杀", "time":   400, "exp_bonus":76, "pot_bonus":50, "score" : 20,"quest_city":"绮云镇附近" ]),
(["quest":  "茶工",  "quest_type":"杀", "time":   400, "exp_bonus":76, "pot_bonus":50, "score" : 20,"quest_city":"绮云镇附近" ]),

(["quest":  "魏无极",  "quest_type":"杀", "time":   400, "exp_bonus":76, "pot_bonus":50, "score" : 20,"quest_city":"雪亭镇附近" ]),
(["quest":  "张铁匠",  "quest_type":"杀", "time":   400, "exp_bonus":76, "pot_bonus":50, "score" : 20,"quest_city":"雪亭镇附近" ]),
(["quest":  "柳生一郎",  "quest_type":"杀", "time":   400, "exp_bonus":76, "pot_bonus":50, "score" : 20,"quest_city":"雪亭镇附近" ]),

(["quest":  "拉姆",  "quest_type":"杀", "time":   400, "exp_bonus":76, "pot_bonus":50, "score" : 20,"quest_city":"八一镇附近" ]),

(["quest":  "霍英",  "quest_type":"杀", "time":   400, "exp_bonus":76, "pot_bonus":50, "score" : 20,"quest_city":"黄山附近" ]),
(["quest":  "杜吟",  "quest_type":"杀", "time":   400, "exp_bonus":76, "pot_bonus":50, "score" : 20,"quest_city":"黄山附近" ]),
(["quest":  "王莹",  "quest_type":"杀", "time":   400, "exp_bonus":76, "pot_bonus":50, "score" : 20,"quest_city":"黄山附近" ]),
(["quest":  "空光",  "quest_type":"杀", "time":   400, "exp_bonus":76, "pot_bonus":50, "score" : 20,"quest_city":"黄山附近" ]),
(["quest":  "白荭",  "quest_type":"杀", "time":   400, "exp_bonus":76, "pot_bonus":50, "score" : 20,"quest_city":"黄山附近" ]),
(["quest":  "白环",  "quest_type":"杀", "time":   400, "exp_bonus":76, "pot_bonus":50, "score" : 20,"quest_city":"黄山附近" ]),    

(["quest":  "马大嫂", "quest_type":"杀", "time":   400, "exp_bonus":76, "pot_bonus":50, "score" : 20,"quest_city":"盛京附近" ]),    	
(["quest":  "范文程", "quest_type":"杀", "time":   400, "exp_bonus":76, "pot_bonus":50, "score" : 20,"quest_city":"盛京附近" ]),    	
(["quest":  "李大姐", "quest_type":"杀", "time":   400, "exp_bonus":76, "pot_bonus":50, "score" : 20,"quest_city":"盛京附近" ]),    	
});

mapping query_quest()
{
   return quest[random(sizeof(quest))];
}

