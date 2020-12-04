// boy4.c
#include <ansi.h>

inherit NPC;

void create()
{
	set_name("年轻弟子", ({"young boy","boy","young"}));
	set("title",HIY"神龙教"HIG"青龙使"NOR"座下弟子");
	set("long",
	"这是一个神龙教弟子，一袭青衣，混身透着一股邪气。\n"
	);

	set("gender", "男性");
	set("attitude", "peaceful");

	set("age", 10+random(10));
	set("shen_type", -1);
	set("str", 25+random(10));
	set("dex", 25+random(10));
	set("max_qi", 200);
	set("max_jing", 150);
	set("neili", 200);
	set("max_neili", 200);
	set("jiaji", 5+random(5));
	set("combat_exp", 20000+random(10000));

	set_skill("force", 40);
	set_skill("dodge", 40);
	set_skill("unarmed", 40);
	set_skill("parry", 40);
	set_skill("sword", 60);
	create_family("神龙教",3,"弟子");
	set_skill("shedao-qigong", 30);
	map_skill("sword","shedao-qigong");
	set("chat_chance", 3);
        set("chat_msg", ({
"年轻弟子说道：洪教主身通护佑，众弟子勇气百倍，以一当百，以百当万。\n",
"年轻弟子说道：洪教主神目如电，烛照四方。\n",
"年轻弟子说道：我弟子杀敌护教，洪教主亲加提拔，升任圣职。\n",
"年轻弟子说道：我教弟子护教而死，同升天堂。\n",
"年轻弟子忽然高声叫道:教主宝训,时刻在心,建功克敌,无事不成!\n",
"年轻弟子忽然齐声叫道:众志齐心可成城,威震天下无比伦!\n",
"年轻弟子忽然齐声叫道:神龙飞天齐仰望,教主声威盖八方!\n",
"年轻弟子忽然齐声叫道:乘风破浪逞英豪,教主如同日月光!\n",
"年轻弟子齐声叫道:教主永享仙福,寿与天齐!\n",
        }) );

	setup();
	carry_object("/d/shenlong/obj/xionghuang")->wield();
	carry_object("/d/city/obj/duanjian")->wield();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	object ob;

	::init();

	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 10, ob);
	}
}

void greeting(object ob)
{
if(ob)
{
	object obj;
	if (obj = present("usedgao", ob))          
		unconcious();
}
	return;

}
