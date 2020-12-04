#include <ansi.h>
inherit BOSS;
int big_blowing();
#include "/quest/menpai/romnpc4.c"

mapping *data=({
(["id":"boss killer","title":"五路神","name":"施令威","tname":"bnpc1","tname":"bnpc1",]),
(["id":"boss killer","title":"红花会上代总舵主","name":"于万亭","tname":"bnpc2",]),
(["id":"boss killer","title":"青城派","name":"慧侣道人","tname":"bnpc3",]),
(["id":"boss killer","title":"天池怪侠","name":"袁士霄","tname":"bnpc4",]),
(["id":"boss killer","title":"绵里针","name":"陆菲青","sex":1,"tname":"bnpc5",]),
(["id":"boss killer","title":"六扇门高手魔爪孙","name":"万庆澜","tname":"bnpc6",]),
(["id":"boss killer","title":"大内御前侍卫一苇渡江","name":"褚圆","tname":"bnpc7",]),
(["id":"boss killer","title":"镖局总镖头威震河朔","name":"王维扬","tname":"bnpc8",]),
(["id":"boss killer","title":"当世八卦门第一高手","name":"王剑英","sex":1,"tname":"bnpc9",]),
(["id":"boss killer","title":"天山双鹰秃鹫","name":"陈正德","tname":"bnpc10",]),
(["id":"boss killer","title":"天山双鹰雪雕","name":"关明梅","tname":"bnpc11",]),
(["id":"boss killer","title":"关东六魔五魔","name":"阎世魁","tname":"bnpc12",]),
(["id":"boss killer","title":"关东六魔六魔","name":"阎世章","tname":"bnpc13",]),
(["id":"boss killer","title":"两湖豪杰玉判官","name":"贝人龙","tname":"bnpc14",]),
(["id":"boss killer","title":"焦文期盟弟铁臂罗汉","name":"罗信","tname":"bnpc15",]),
(["id":"boss killer","title":"金刀无敌","name":"王元霸","tname":"bnpc16",]),
(["id":"boss killer","title":"五云手","name":"万震山","tname":"bnpc17",]),
(["id":"boss killer","title":"陆地神龙","name":"言达平","tname":"bnpc18",]),
(["id":"boss killer","title":"太行山寨主","name":"吕通","tname":"bnpc19",]),
(["id":"boss killer","title":"血刀门五僧之首","name":"宝象","tname":"bnpc20",]),
(["id":"boss killer","title":"铁骨墨萼","name":"梅念笙","tname":"bnpc21",]),
(["id":"boss killer","title":"铁索横江","name":"戚长发","tname":"bnpc22",]),
(["id":"boss killer","title":"明教教主","name":"阳顶天","tname":"bnpc23",]),
(["id":"boss killer","title":"鹿杖客大弟子","name":"乌旺阿普","tname":"bnpc24",]),
(["id":"boss killer","title":"闪电娘娘","name":"卫四娘","sex":1,"tname":"bnpc25",]),
(["id":"boss killer","title":"乾坤一剑","name":"震山子","tname":"bnpc26",]),
(["id":"boss killer","title":"摩天居士","name":"谢烟客","tname":"bnpc27",]),
(["id":"boss killer","title":"铁胆庄庄主铁胆","name":"周仲英","sex":1,"tname":"bnpc28",]),
(["id":"boss killer","title":"温州太极门千手如来","name":"赵半山","tname":"bnpc29",]),
(["id":"boss killer","title":"广平太极门掌门","name":"孙刚峰","tname":"bnpc30",]),
(["id":"boss killer","title":"西岳华拳门","name":"姬老三","tname":"bnpc31",]),
(["id":"boss killer","title":"西岳华拳门","name":"","name":"蔡威","tname":"bnpc32",]),
(["id":"boss killer","title":"太监总管","name":"海大富","tname":"bnpc33",]),
(["id":"boss killer","title":"铁背苍龙","name":"柳大洪","tname":"bnpc34",]),
(["id":"boss killer","title":"摇头狮子","name":"吴立身","tname":"bnpc34",]),
(["id":"boss killer","title":"西夏一品堂堂主","name":"李延年","tname":"bnpc36",]),
(["id":"boss killer","title":"雷动于九天之上","name":"九翼道人","tname":"bnpc37",]),
(["id":"boss killer","title":"拈花寺住持","name":"黄眉僧","tname":"bnpc38",]),
(["id":"boss killer","title":"波斯总教教主山中老人","name":"霍山","tname":"bnpc39",]),
(["id":"boss killer","title":"上清观观主","name":"冲虚道长","tname":"bnpc40",]),
(["id":"boss killer","title":"玄素庄庄主黑白双剑","name":"石清","tname":"bnpc41",]),
(["id":"boss killer","title":"玄素庄庄主夫人黑白双剑","name":"闵柔","sex":1,"tname":"bnpc42",]),
(["id":"boss killer","title":"丁氏双雄","name":"丁不三","tname":"bnpc43",]),
(["id":"boss killer","title":"丁氏双雄","name":"丁不四","tname":"bnpc44",]),
(["id":"boss killer","title":"八爪金龙","name":"司徒横","tname":"bnpc45",]),
(["id":"boss killer","title":"着手回春","name":"贝海石","tname":"bnpc46",]),
(["id":"boss killer","title":"铁背金獒","name":"焦公礼","tname":"bnpc47",]),
(["id":"boss killer","title":"莳花少妇","name":"石清露","sex":1,"tname":"bnpc48",]),
(["id":"boss killer","title":"剑神","name":"卓不凡","tname":"bnpc49",]),
(["id":"boss killer","title":"游氏双雄","name":"游骥","tname":"bnpc50",]),
(["id":"boss killer","title":"游氏双雄","name":"游驹","tname":"bnpc51",]),
(["id":"boss killer","title":"秦家寨开山寨主","name":"秦公望","tname":"bnpc52",]),
(["id":"boss killer","title":"蓬莱派第七代掌门人","name":"海风子","tname":"bnpc53",]),
(["id":"boss killer","title":"蓬莱派第八代掌门人","name":"都灵子","tname":"bnpc54",]),
(["id":"boss killer","title":"伏牛派掌门","name":"柯百岁","tname":"bnpc55",]),
(["id":"boss killer","title":"柯百岁大弟子追魂鞭","name":"过彦之","tname":"bnpc56",]),
(["id":"boss killer","title":"金算盘","name":"崔百泉","tname":"bnpc5",]),
(["id":"boss killer","title":"幽谷客修罗刀","name":"秦红棉","tname":"bnpc58",]),
(["id":"boss killer","title":"神农帮帮主","name":"司空玄","tname":"bnpc59",]),
(["id":"boss killer","title":"鹰爪雁行门掌门","name":"汪铁鹗","tname":"bnpc60",]),
(["id":"boss killer","title":"天龙门北宗掌门人","name":"田归农","tname":"bnpc61",]),
(["id":"boss killer","title":"天龙门南宗掌门人威震天南","name":"殷吉","tname":"bnpc62",]),
(["id":"boss killer","title":"天龙门好手","name":"殷仲翔","tname":"bnpc63",]),
(["id":"boss killer","title":"天龙门掌剑双绝腾龙剑","name":"曹云奇","tname":"bnpc64",]),
(["id":"boss killer","title":"天龙门掌剑双绝回龙剑","name":"周云阳","tname":"bnpc65",]),
(["id":"boss killer","title":"天龙北宗第一高手七星手","name":"阮士中","tname":"bnpc66",]),
(["id":"boss killer","title":"毒手药王","name":"无嗔","tname":"bnpc67",]),
(["id":"boss killer","title":"毒手神枭","name":"石万嗔","tname":"bnpc68",]),
(["id":"boss killer","title":"三才剑掌门人甘霖惠七省大侠","name":"汤沛","tname":"bnpc69",]),
(["id":"boss killer","title":"黑龙门掌门人","name":"海兰弼","tname":"bnpc70",]),
(["id":"boss killer","title":"锺氏三雄","name":"锺兆文","tname":"bnpc71",]),
(["id":"boss killer","title":"锺氏三雄","name":"锺兆英","tname":"bnpc72",]),
(["id":"boss killer","title":"锺氏三雄","name":"锺兆能","tname":"bnpc73",]),
(["id":"boss killer","title":"八仙剑掌门人","name":"蓝秦","tname":"bnpc74",]),
(["id":"boss killer","title":"五虎门掌门人南霸天","name":"凤天南","tname":"bnpc75",]),
(["id":"boss killer","title":"韦陀双鹤","name":"万鹤声","tname":"bnpc76",]),
(["id":"boss killer","title":"韦陀双鹤","name":"刘鹤真","tname":"bnpc77",]),
(["id":"boss killer","title":"飞马镖局总镖头百胜神拳","name":"马行空","tname":"bnpc78",]),
(["id":"boss killer","title":"铃剑双侠","name":"汪啸风","tname":"bnpc79",]),
(["id":"boss killer","title":"崆峒五老","name":"唐文亮","tname":"bnpc80",]),
(["id":"boss killer","title":"崆峒五老","name":"宗维侠","tname":"bnpc81",]),
(["id":"boss killer","title":"崆峒五老一拳断岳","name":"常敬之","tname":"bnpc82",]),
(["id":"boss killer","title":"崆峒五老","name":"关能","tname":"bnpc83",]),
(["id":"boss killer","title":"圣手伽蓝","name":"捷远","tname":"bnpc84",]),
(["id":"boss killer","title":"神剑仙猿","name":"穆人清","tname":"bnpc85",]),
(["id":"boss killer","title":"神拳无敌","name":"归辛树","tname":"bnpc86",]),
(["id":"boss killer","title":"黄真弟子伏虎金刚","name":"崔希敏","tname":"bnpc87",]),
(["id":"boss killer","title":"归辛树三弟子五丁手","name":"刘培生","tname":"bnpc88",]),
(["id":"boss killer","title":"归辛树五弟子飞天魔女","name":"孙仲君","sex":1,"tname":"bnpc89",]),
(["id":"boss killer","title":"归辛树大弟子没影子","name":"梅剑和","tname":"bnpc90",]),
(["id":"boss killer","title":"千变万劫","name":"木桑道人","tname":"bnpc91",]),
(["id":"boss killer","title":"仙都派第十代掌门祖师","name":"菊潭道长","tname":"bnpc92",]),
(["id":"boss killer","title":"仙都派第十二代掌门","name":"黄木道人","tname":"bnpc93",]),
(["id":"boss killer","title":"仙都派第十三代掌门","name":"水云道人","tname":"bnpc94",]),
(["id":"boss killer","title":"仙都派第十三代弟子","name":"闵子华","tname":"bnpc95",]),
(["id":"boss killer","title":"仙都派第十三代弟子","name":"洞玄道人","tname":"bnpc96",]),
(["id":"boss killer","title":"石梁五祖","name":"温方达","tname":"bnpc97",]),
(["id":"boss killer","title":"盖孟尝","name":"孟伯飞","tname":"bnpc98",]),
(["id":"boss killer","title":"八极拳掌门八臂哪吒","name":"秦耐之","tname":"bnpc99",]),
(["id":"boss killer","title":"三峡以西剑法第一","name":"长青子","tname":"bnpc100",]),
});
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});
int lv=100+random(10);
void create()
{
	mapping npc,mp,j;
	int i,k,a,b,c,d,e,f,temp;
	string sex,tname;
	npc=data[20];
	sex=npc["sex"];
	tname=npc["tname"];
	set_name(npc["name"]+NOR,({ npc["id"] }));
	set("title",(order[random(13)])+(npc["title"])+NOR);

if (sex)
set("gender", "女性" );
else set("gender", "男性" );
set("pubmaster",1);
        set("isboss",1);
        set("age", 32);
        set("str", 30);
        set("cor", 30);
        set("tname",tname);
        set("cps", 30);
        set("int", 30);
	set("per", 30);
        set("agi",25);
        set("dex",30);
        set("con",30);
       set("str" ,30);
       set("dex",30);
       set("int",30);
       set("per",30);
       set("kar",30);       
     set("age", 22+random(40));

	set("attitude","friendly");
set("isteamjob",1);
 
 set("mgnpc",1);
        set_skill("parry", 120);
        set_skill("dodge", 120);
        set_skill("force", 120);
        set_skill("literate", 120);
	set_skill("sword", 120);
	set_skill("unarmed",120);
	set("combat_exp",26730899);
	set("magicset",1);
        set("zhuanbest",1);
        set("no_get",1);
        //set("vendetta/authority",1);
        if (random(2)==0)
        {
        set_temp("apply/attack", 100);
        set_temp("apply/defense", 100);
        set_temp("apply/armor", 800);
        set_temp("apply/damage", 800);
}
        set("killer_reward", ([
                "FI&/clone/box/gbox"   :   6000,
                "TW&480"   :  100+(41*6),
                "TA&480"   :  100+(41*6),
                "RI&40"   :   100+(41*6),
                "GE&3"   :  100+(41*6),
                "JD&3"   :  100+(41*6),
                "YC&3"   :  100+(41*6),
                "WG&3"   :  100+(41*6),
                "KS&3"   :   100+(41*6),
                "BL&3"   :  100+(41*6),
                "YW&3"   :  100+(41*6),
                "YA&3"   :  100+(41*6),
        ]));
	set("bonus", 5888+random(3888)+(41*100));


if (query("str",1) < 100)
set("str",100);
if (query("dex",1) < 100)
set("dex",100);


if (query("max_qi",1) < (lv*300))
set("max_qi",lv*300);

if (query("max_jing",1) < (lv*300))
set("max_jing",lv*300);

if (query("max_neili",1) < (lv*380))
set("max_neili",lv*380);

set("neili",query("max_neili"));
set("eff_qi",query("max_qi"));
set("eff_jing",query("max_jing"));
set("qi",query("max_qi"));
set("jing",query("max_jing"));
        setup();
 	 initlvl(280+random(50),20+random(2));
}

void unconcious()
{
    die();
}
void die()
{
int i,pot,exp;
	object killer;
	exp= random(60)+30;
	pot= exp*2/3;
 if(!objectp(killer = query_temp("last_damage_from")))
	return;
	
	if(objectp(killer = query_temp("last_damage_from")))
{
        killer->add_temp(this_object()->query("tname"),1);
        killer->delete_temp("migongxh");	
        tell_object(killer,"你战败了高强的敌人"+killer->query_temp(this_object()->query("tname"))+"！。\n");
       killer->add("mpgx",1);	
       //killer->add_temp("mpjobn8",1);
}
	::die();

return ;
}

void init()
{
        remove_call_out("leave");
        call_out("leave",66);
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