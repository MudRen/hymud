#include <ansi.h>
inherit BOSS;
int big_blowing();
#include "/quest/menpai/romnpc4.c"

mapping *data=({
(["id":"boss killer","title":"��·��","name":"ʩ����","tname":"bnpc1","tname":"bnpc1",]),
(["id":"boss killer","title":"�컨���ϴ��ܶ���","name":"����ͤ","tname":"bnpc2",]),
(["id":"boss killer","title":"�����","name":"���µ���","tname":"bnpc3",]),
(["id":"boss killer","title":"��ع���","name":"Ԭʿ��","tname":"bnpc4",]),
(["id":"boss killer","title":"������","name":"½����","sex":1,"tname":"bnpc5",]),
(["id":"boss killer","title":"�����Ÿ���ħצ��","name":"������","tname":"bnpc6",]),
(["id":"boss killer","title":"������ǰ����һέ�ɽ�","name":"��Բ","tname":"bnpc7",]),
(["id":"boss killer","title":"�ھ�����ͷ�����˷","name":"��ά��","tname":"bnpc8",]),
(["id":"boss killer","title":"���������ŵ�һ����","name":"����Ӣ","sex":1,"tname":"bnpc9",]),
(["id":"boss killer","title":"��ɽ˫ӥͺ��","name":"������","tname":"bnpc10",]),
(["id":"boss killer","title":"��ɽ˫ӥѩ��","name":"����÷","tname":"bnpc11",]),
(["id":"boss killer","title":"�ض���ħ��ħ","name":"������","tname":"bnpc12",]),
(["id":"boss killer","title":"�ض���ħ��ħ","name":"������","tname":"bnpc13",]),
(["id":"boss killer","title":"�����������й�","name":"������","tname":"bnpc14",]),
(["id":"boss killer","title":"�������˵������޺�","name":"����","tname":"bnpc15",]),
(["id":"boss killer","title":"���޵�","name":"��Ԫ��","tname":"bnpc16",]),
(["id":"boss killer","title":"������","name":"����ɽ","tname":"bnpc17",]),
(["id":"boss killer","title":"½������","name":"�Դ�ƽ","tname":"bnpc18",]),
(["id":"boss killer","title":"̫��ɽկ��","name":"��ͨ","tname":"bnpc19",]),
(["id":"boss killer","title":"Ѫ������ɮ֮��","name":"����","tname":"bnpc20",]),
(["id":"boss killer","title":"����ī��","name":"÷����","tname":"bnpc21",]),
(["id":"boss killer","title":"�����Ὥ","name":"�ݳ���","tname":"bnpc22",]),
(["id":"boss killer","title":"���̽���","name":"������","tname":"bnpc23",]),
(["id":"boss killer","title":"¹�ȿʹ����","name":"��������","tname":"bnpc24",]),
(["id":"boss killer","title":"��������","name":"������","sex":1,"tname":"bnpc25",]),
(["id":"boss killer","title":"Ǭ��һ��","name":"��ɽ��","tname":"bnpc26",]),
(["id":"boss killer","title":"Ħ���ʿ","name":"л�̿�","tname":"bnpc27",]),
(["id":"boss killer","title":"����ׯׯ������","name":"����Ӣ","sex":1,"tname":"bnpc28",]),
(["id":"boss killer","title":"����̫����ǧ������","name":"�԰�ɽ","tname":"bnpc29",]),
(["id":"boss killer","title":"��ƽ̫��������","name":"��շ�","tname":"bnpc30",]),
(["id":"boss killer","title":"������ȭ��","name":"������","tname":"bnpc31",]),
(["id":"boss killer","title":"������ȭ��","name":"","name":"����","tname":"bnpc32",]),
(["id":"boss killer","title":"̫���ܹ�","name":"����","tname":"bnpc33",]),
(["id":"boss killer","title":"��������","name":"�����","tname":"bnpc34",]),
(["id":"boss killer","title":"ҡͷʨ��","name":"������","tname":"bnpc34",]),
(["id":"boss killer","title":"����һƷ������","name":"������","tname":"bnpc36",]),
(["id":"boss killer","title":"�׶��ھ���֮��","name":"�������","tname":"bnpc37",]),
(["id":"boss killer","title":"�黨��ס��","name":"��üɮ","tname":"bnpc38",]),
(["id":"boss killer","title":"��˹�ܽ̽���ɽ������","name":"��ɽ","tname":"bnpc39",]),
(["id":"boss killer","title":"����۹���","name":"�������","tname":"bnpc40",]),
(["id":"boss killer","title":"����ׯׯ���ڰ�˫��","name":"ʯ��","tname":"bnpc41",]),
(["id":"boss killer","title":"����ׯׯ�����˺ڰ�˫��","name":"����","sex":1,"tname":"bnpc42",]),
(["id":"boss killer","title":"����˫��","name":"������","tname":"bnpc43",]),
(["id":"boss killer","title":"����˫��","name":"������","tname":"bnpc44",]),
(["id":"boss killer","title":"��צ����","name":"˾ͽ��","tname":"bnpc45",]),
(["id":"boss killer","title":"���ֻش�","name":"����ʯ","tname":"bnpc46",]),
(["id":"boss killer","title":"��������","name":"������","tname":"bnpc47",]),
(["id":"boss killer","title":"ݪ���ٸ�","name":"ʯ��¶","sex":1,"tname":"bnpc48",]),
(["id":"boss killer","title":"����","name":"׿����","tname":"bnpc49",]),
(["id":"boss killer","title":"����˫��","name":"����","tname":"bnpc50",]),
(["id":"boss killer","title":"����˫��","name":"�ξ�","tname":"bnpc51",]),
(["id":"boss killer","title":"�ؼ�կ��ɽկ��","name":"�ع���","tname":"bnpc52",]),
(["id":"boss killer","title":"�����ɵ��ߴ�������","name":"������","tname":"bnpc53",]),
(["id":"boss killer","title":"�����ɵڰ˴�������","name":"������","tname":"bnpc54",]),
(["id":"boss killer","title":"��ţ������","name":"�°���","tname":"bnpc55",]),
(["id":"boss killer","title":"�°�������׷���","name":"����֮","tname":"bnpc56",]),
(["id":"boss killer","title":"������","name":"�ް�Ȫ","tname":"bnpc5",]),
(["id":"boss killer","title":"�Ĺȿ����޵�","name":"�غ���","tname":"bnpc58",]),
(["id":"boss killer","title":"��ũ�����","name":"˾����","tname":"bnpc59",]),
(["id":"boss killer","title":"ӥצ����������","name":"������","tname":"bnpc60",]),
(["id":"boss killer","title":"�����ű���������","name":"���ũ","tname":"bnpc61",]),
(["id":"boss killer","title":"������������������������","name":"��","tname":"bnpc62",]),
(["id":"boss killer","title":"�����ź���","name":"������","tname":"bnpc63",]),
(["id":"boss killer","title":"�������ƽ�˫��������","name":"������","tname":"bnpc64",]),
(["id":"boss killer","title":"�������ƽ�˫��������","name":"������","tname":"bnpc65",]),
(["id":"boss killer","title":"�������ڵ�һ����������","name":"��ʿ��","tname":"bnpc66",]),
(["id":"boss killer","title":"����ҩ��","name":"����","tname":"bnpc67",]),
(["id":"boss killer","title":"��������","name":"ʯ����","tname":"bnpc68",]),
(["id":"boss killer","title":"���Ž������˸��ػ���ʡ����","name":"����","tname":"bnpc69",]),
(["id":"boss killer","title":"������������","name":"������","tname":"bnpc70",]),
(["id":"boss killer","title":"��������","name":"������","tname":"bnpc71",]),
(["id":"boss killer","title":"��������","name":"����Ӣ","tname":"bnpc72",]),
(["id":"boss killer","title":"��������","name":"������","tname":"bnpc73",]),
(["id":"boss killer","title":"���ɽ�������","name":"����","tname":"bnpc74",]),
(["id":"boss killer","title":"�廢���������ϰ���","name":"������","tname":"bnpc75",]),
(["id":"boss killer","title":"Τ��˫��","name":"�����","tname":"bnpc76",]),
(["id":"boss killer","title":"Τ��˫��","name":"������","tname":"bnpc77",]),
(["id":"boss killer","title":"�����ھ�����ͷ��ʤ��ȭ","name":"���п�","tname":"bnpc78",]),
(["id":"boss killer","title":"�彣˫��","name":"��Х��","tname":"bnpc79",]),
(["id":"boss killer","title":"�������","name":"������","tname":"bnpc80",]),
(["id":"boss killer","title":"�������","name":"��ά��","tname":"bnpc81",]),
(["id":"boss killer","title":"�������һȭ����","name":"����֮","tname":"bnpc82",]),
(["id":"boss killer","title":"�������","name":"����","tname":"bnpc83",]),
(["id":"boss killer","title":"ʥ��٤��","name":"��Զ","tname":"bnpc84",]),
(["id":"boss killer","title":"����Գ","name":"������","tname":"bnpc85",]),
(["id":"boss killer","title":"��ȭ�޵�","name":"������","tname":"bnpc86",]),
(["id":"boss killer","title":"������ӷ������","name":"��ϣ��","tname":"bnpc87",]),
(["id":"boss killer","title":"�������������嶡��","name":"������","tname":"bnpc88",]),
(["id":"boss killer","title":"����������ӷ���ħŮ","name":"���پ�","sex":1,"tname":"bnpc89",]),
(["id":"boss killer","title":"�����������ûӰ��","name":"÷����","tname":"bnpc90",]),
(["id":"boss killer","title":"ǧ�����","name":"ľɣ����","tname":"bnpc91",]),
(["id":"boss killer","title":"�ɶ��ɵ�ʮ��������ʦ","name":"��̶����","tname":"bnpc92",]),
(["id":"boss killer","title":"�ɶ��ɵ�ʮ��������","name":"��ľ����","tname":"bnpc93",]),
(["id":"boss killer","title":"�ɶ��ɵ�ʮ��������","name":"ˮ�Ƶ���","tname":"bnpc94",]),
(["id":"boss killer","title":"�ɶ��ɵ�ʮ��������","name":"���ӻ�","tname":"bnpc95",]),
(["id":"boss killer","title":"�ɶ��ɵ�ʮ��������","name":"��������","tname":"bnpc96",]),
(["id":"boss killer","title":"ʯ������","name":"�·���","tname":"bnpc97",]),
(["id":"boss killer","title":"���ϳ�","name":"�ϲ���","tname":"bnpc98",]),
(["id":"boss killer","title":"�˼�ȭ���Ű˱���߸","name":"����֮","tname":"bnpc99",]),
(["id":"boss killer","title":"��Ͽ����������һ","name":"������","tname":"bnpc100",]),
});
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});
int lv=100+random(10);
void create()
{
	mapping npc,mp,j;
	int i,k,a,b,c,d,e,f,temp;
	string sex,tname;
	npc=data[3];
	sex=npc["sex"];
	tname=npc["tname"];
	set_name(npc["name"]+NOR,({ npc["id"] }));
	set("title",(order[random(13)])+(npc["title"])+NOR);

if (sex)
set("gender", "Ů��" );
else set("gender", "����" );
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
	set("combat_exp",2146689);
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
                "TW&480"   :  100+(7*6),
                "TA&480"   :  100+(7*6),
                "RI&40"   :   100+(7*6),
                "GE&3"   :  100+(7*6),
                "JD&3"   :  100+(7*6),
                "YC&3"   :  100+(7*6),
                "WG&3"   :  100+(7*6),
                "KS&3"   :   100+(7*6),
                "BL&3"   :  100+(7*6),
                "YW&3"   :  100+(7*6),
                "YA&3"   :  100+(7*6),
        ]));
	set("bonus", 5888+random(3888)+(7*100));


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
 	 initlvl(127+random(50),3+random(2));
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
        tell_object(killer,"��ս���˸�ǿ�ĵ���"+killer->query_temp(this_object()->query("tname"))+"����\n");
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
                message_vision(this_object()->query("name") + "���·�ߵ��Ӳݣ������ˡ�\n" NOR,this_object());
                destruct(this_object());
                }
        else call_out("leave",30);
}