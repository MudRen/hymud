#include <ansi.h>
inherit BOSS;
int big_blowing();
#include "/quest/menpai/romnpc.c"

mapping *data=({
(["id":"boss killer","title":"��·��","name":"ʩ����",]),
(["id":"boss killer","title":"�컨���ϴ��ܶ���","name":"����ͤ",]),
(["id":"boss killer","title":"�����","name":"���µ���",]),
(["id":"boss killer","title":"��ع���","name":"Ԭʿ��",]),
(["id":"boss killer","title":"������","name":"½����","sex":1,]),
(["id":"boss killer","title":"�����Ÿ���ħצ��","name":"������",]),
(["id":"boss killer","title":"������ǰ����һέ�ɽ�","name":"��Բ",]),
(["id":"boss killer","title":"�ھ�����ͷ�����˷","name":"��ά��",]),
(["id":"boss killer","title":"���������ŵ�һ����","name":"����Ӣ","sex":1,]),
(["id":"boss killer","title":"��ɽ˫ӥͺ��","name":"������",]),
(["id":"boss killer","title":"��ɽ˫ӥѩ��","name":"����÷",]),
(["id":"boss killer","title":"�ض���ħ��ħ","name":"������",]),
(["id":"boss killer","title":"�ض���ħ��ħ","name":"������",]),
(["id":"boss killer","title":"�����������й�","name":"������",]),
(["id":"boss killer","title":"�������˵������޺�","name":"����",]),
(["id":"boss killer","title":"���޵�","name":"��Ԫ��",]),
(["id":"boss killer","title":"������","name":"����ɽ",]),
(["id":"boss killer","title":"½������","name":"�Դ�ƽ",]),
(["id":"boss killer","title":"̫��ɽկ��","name":"��ͨ",]),
(["id":"boss killer","title":"Ѫ������ɮ֮��","name":"����",]),
(["id":"boss killer","title":"����ī��","name":"÷����",]),
(["id":"boss killer","title":"�����Ὥ","name":"�ݳ���",]),
(["id":"boss killer","title":"���̽���","name":"������",]),
(["id":"boss killer","title":"¹�ȿʹ����","name":"��������",]),
(["id":"boss killer","title":"��������","name":"������","sex":1,]),
(["id":"boss killer","title":"Ǭ��һ��","name":"��ɽ��",]),
(["id":"boss killer","title":"Ħ���ʿ","name":"л�̿�",]),
(["id":"boss killer","title":"����ׯׯ������","name":"����Ӣ","sex":1,]),
(["id":"boss killer","title":"����̫����ǧ������","name":"�԰�ɽ",]),
(["id":"boss killer","title":"��ƽ̫��������","name":"��շ�",]),
(["id":"boss killer","title":"������ȭ��","name":"������",]),
(["id":"boss killer","title":"������ȭ��","name":"","name":"����",]),
(["id":"boss killer","title":"̫���ܹ�","name":"����",]),
(["id":"boss killer","title":"��������","name":"�����",]),
(["id":"boss killer","title":"ҡͷʨ��","name":"������",]),
(["id":"boss killer","title":"����һƷ������","name":"������",]),
(["id":"boss killer","title":"�׶��ھ���֮��","name":"�������",]),
(["id":"boss killer","title":"�黨��ס��","name":"��üɮ",]),
(["id":"boss killer","title":"��˹�ܽ̽���ɽ������","name":"��ɽ",]),
(["id":"boss killer","title":"����۹���","name":"�������",]),
(["id":"boss killer","title":"����ׯׯ���ڰ�˫��","name":"ʯ��",]),
(["id":"boss killer","title":"����ׯׯ�����˺ڰ�˫��","name":"����","sex":1,]),
(["id":"boss killer","title":"����˫��","name":"������",]),
(["id":"boss killer","title":"����˫��","name":"������",]),
(["id":"boss killer","title":"��צ����","name":"˾ͽ��",]),
(["id":"boss killer","title":"���ֻش�","name":"����ʯ",]),
(["id":"boss killer","title":"��������","name":"������",]),
(["id":"boss killer","title":"ݪ���ٸ�","name":"ʯ��¶","sex":1,]),
(["id":"boss killer","title":"����","name":"׿����",]),
(["id":"boss killer","title":"����˫��","name":"����",]),
(["id":"boss killer","title":"����˫��","name":"�ξ�",]),
(["id":"boss killer","title":"�ؼ�կ��ɽկ��","name":"�ع���",]),
(["id":"boss killer","title":"�����ɵ��ߴ�������","name":"������",]),
(["id":"boss killer","title":"�����ɵڰ˴�������","name":"������",]),
(["id":"boss killer","title":"��ţ������","name":"�°���",]),
(["id":"boss killer","title":"�°�������׷���","name":"����֮",]),
(["id":"boss killer","title":"������","name":"�ް�Ȫ",]),
(["id":"boss killer","title":"�Ĺȿ����޵�","name":"�غ���",]),
(["id":"boss killer","title":"��ũ�����","name":"˾����",]),
(["id":"boss killer","title":"ӥצ����������","name":"������",]),
(["id":"boss killer","title":"�����ű���������","name":"���ũ",]),
(["id":"boss killer","title":"������������������������","name":"��",]),
(["id":"boss killer","title":"�����ź���","name":"������",]),
(["id":"boss killer","title":"�������ƽ�˫��������","name":"������",]),
(["id":"boss killer","title":"�������ƽ�˫��������","name":"������",]),
(["id":"boss killer","title":"�������ڵ�һ����������","name":"��ʿ��",]),
(["id":"boss killer","title":"����ҩ��","name":"����",]),
(["id":"boss killer","title":"��������","name":"ʯ����",]),
(["id":"boss killer","title":"���Ž������˸��ػ���ʡ����","name":"����",]),
(["id":"boss killer","title":"������������","name":"������",]),
(["id":"boss killer","title":"��������","name":"������",]),
(["id":"boss killer","title":"��������","name":"����Ӣ",]),
(["id":"boss killer","title":"��������","name":"������",]),
(["id":"boss killer","title":"���ɽ�������","name":"����",]),
(["id":"boss killer","title":"�廢���������ϰ���","name":"������",]),
(["id":"boss killer","title":"Τ��˫��","name":"�����",]),
(["id":"boss killer","title":"Τ��˫��","name":"������",]),
(["id":"boss killer","title":"�����ھ�����ͷ��ʤ��ȭ","name":"���п�",]),
(["id":"boss killer","title":"�彣˫��","name":"��Х��",]),
(["id":"boss killer","title":"�������","name":"������",]),
(["id":"boss killer","title":"�������","name":"��ά��",]),
(["id":"boss killer","title":"�������һȭ����","name":"����֮",]),
(["id":"boss killer","title":"�������","name":"����",]),
(["id":"boss killer","title":"ʥ��٤��","name":"��Զ",]),
(["id":"boss killer","title":"����Գ","name":"������",]),
(["id":"boss killer","title":"��ȭ�޵�","name":"������",]),
(["id":"boss killer","title":"������ӷ������","name":"��ϣ��",]),
(["id":"boss killer","title":"�������������嶡��","name":"������",]),
(["id":"boss killer","title":"����������ӷ���ħŮ","name":"���پ�","sex":1,]),
(["id":"boss killer","title":"�����������ûӰ��","name":"÷����",]),
(["id":"boss killer","title":"ǧ�����","name":"ľɣ����",]),
(["id":"boss killer","title":"�ɶ��ɵ�ʮ��������ʦ","name":"��̶����",]),
(["id":"boss killer","title":"�ɶ��ɵ�ʮ��������","name":"��ľ����",]),
(["id":"boss killer","title":"�ɶ��ɵ�ʮ��������","name":"ˮ�Ƶ���",]),
(["id":"boss killer","title":"�ɶ��ɵ�ʮ��������","name":"���ӻ�",]),
(["id":"boss killer","title":"�ɶ��ɵ�ʮ��������","name":"��������",]),
(["id":"boss killer","title":"ʯ������","name":"�·���",]),
(["id":"boss killer","title":"���ϳ�","name":"�ϲ���",]),
(["id":"boss killer","title":"�˼�ȭ���Ű˱���߸","name":"����֮",]),
(["id":"boss killer","title":"��Ͽ����������һ","name":"������",]),
});
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

void create()
{
	mapping npc,mp,j;
	int i,k,a,b,c,d,e,f,temp;
	string sex;
	npc=data[random(sizeof(data))];
	sex=npc["sex"];
	set_name(npc["name"]+NOR,({ npc["id"] }));
	set("title",(order[random(13)])+(npc["title"])+NOR);

if (sex)
set("gender", "Ů��" );
else set("gender", "����" );
set("pubmaster",1);
        set("age", 32);
        set("str", 30);
        set("cor", 30);
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
set("taskid", 1);
	set("attitude","friendly");
set("isteamjob",1);
        set("max_neili", 1145000);
        set("neili", 1145000);
        set("jing",118000+random(10000));
        set("max_jing",118000+random(10000));
set("eff_jing",118000+random(10000));
        set("qi",118000+random(10000));
        set("max_qi",118000+random(10000));
set("eff_qi",118000+random(10000));
 
        set_skill("parry", 420);
        set_skill("dodge", 420);
        set_skill("force", 420);
        set_skill("literate", 420);
	set_skill("sword", 420);
	set_skill("unarmed",420);
	set("combat_exp",1000000+random(2000000));
	set("magicset",1);
        set("zhuanbest",1);
        set("no_get",1);
        //set("vendetta/authority",1);
        if (random(2)==0)
        {
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 2800);
        set_temp("apply/damage", 2800);
}
        set("killer_reward", ([
                "FI&/clone/box/gbox"   :   6000,
                "TW&480"   :  600,
                "TA&480"   :  600,
                "RI&40"   :   500,
                "GE&5"   :  300,
                "JD&5"   :  300,
                "YC&3"   :  300,
                "WG&3"   :  500,
                "KS&5"   :   500,
                "BL&4"   :  500,
                "YW&4"   :  300,
                "YA&4"   :  300,
        ]));
	set("bonus", 8888+random(8888));

a=280000+random(90000);
b=280000+random(90000);
c=50000;
d=35+random(35);
set("str",d);
set("dex",20+d);
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

        set("neili",c);
        set("max_neili",c);
        
        setup();
 	 initlvl(550+random(100));
}

void init()
{
        remove_call_out("leave");
        call_out("leave",300);
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
int do_back(object me)
{                       
        me = this_object();
  tell_room(environment(me), me->query("name")+"�Ҵ�ææ���뿪�ˡ�\n", ({me}));	
  destruct(me); 
  return 1;
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
        	tell_object(killer,"��ս���˸�ǿ�ĵ��ˣ���\n");
       killer->clear_condition("taskjob_busy");
       killer->add("mpgx",1);	
       killer->add_temp("mpjobn8",1);
}
	::die();

return ;
}