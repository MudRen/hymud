#include <ansi.h>
inherit BOSS;
int big_blowing();
#include "/d/migong/romnpc2.c"

mapping *data=({
(["id":"boss","title":"��·��","name":"ʩ����",]),
(["id":"boss","title":"�컨���ϴ��ܶ���","name":"����ͤ",]),
(["id":"boss","title":"�����","name":"���µ���",]),
(["id":"boss","title":"��ع���","name":"Ԭʿ��",]),
(["id":"boss","title":"������","name":"½����","sex":1,]),
(["id":"boss","title":"�����Ÿ���ħצ��","name":"������",]),
(["id":"boss","title":"������ǰ����һέ�ɽ�","name":"��Բ",]),
(["id":"boss","title":"�ھ�����ͷ�����˷","name":"��ά��",]),
(["id":"boss","title":"���������ŵ�һ����","name":"����Ӣ","sex":1,]),
(["id":"boss","title":"��ɽ˫ӥͺ��","name":"������",]),
(["id":"boss","title":"��ɽ˫ӥѩ��","name":"����÷",]),
(["id":"boss","title":"�ض���ħ��ħ","name":"������",]),
(["id":"boss","title":"�ض���ħ��ħ","name":"������",]),
(["id":"boss","title":"�����������й�","name":"������",]),
(["id":"boss","title":"�������˵������޺�","name":"����",]),
(["id":"boss","title":"���޵�","name":"��Ԫ��",]),
(["id":"boss","title":"������","name":"����ɽ",]),
(["id":"boss","title":"½������","name":"�Դ�ƽ",]),
(["id":"boss","title":"̫��ɽկ��","name":"��ͨ",]),
(["id":"boss","title":"Ѫ������ɮ֮��","name":"����",]),
(["id":"boss","title":"����ī��","name":"÷����",]),
(["id":"boss","title":"�����Ὥ","name":"�ݳ���",]),
(["id":"boss","title":"���̽���","name":"������",]),
(["id":"boss","title":"¹�ȿʹ����","name":"��������",]),
(["id":"boss","title":"��������","name":"������","sex":1,]),
(["id":"boss","title":"Ǭ��һ��","name":"��ɽ��",]),
(["id":"boss","title":"Ħ���ʿ","name":"л�̿�",]),
(["id":"boss","title":"����ׯׯ������","name":"����Ӣ","sex":1,]),
(["id":"boss","title":"����̫����ǧ������","name":"�԰�ɽ",]),
(["id":"boss","title":"��ƽ̫��������","name":"��շ�",]),
(["id":"boss","title":"������ȭ��","name":"������",]),
(["id":"boss","title":"������ȭ��","name":"","name":"����",]),
(["id":"boss","title":"̫���ܹ�","name":"����",]),
(["id":"boss","title":"��������","name":"�����",]),
(["id":"boss","title":"ҡͷʨ��","name":"������",]),
(["id":"boss","title":"����һƷ������","name":"������",]),
(["id":"boss","title":"�׶��ھ���֮��","name":"�������",]),
(["id":"boss","title":"�黨��ס��","name":"��üɮ",]),
(["id":"boss","title":"��˹�ܽ̽���ɽ������","name":"��ɽ",]),
(["id":"boss","title":"����۹���","name":"�������",]),
(["id":"boss","title":"����ׯׯ���ڰ�˫��","name":"ʯ��",]),
(["id":"boss","title":"����ׯׯ�����˺ڰ�˫��","name":"����","sex":1,]),
(["id":"boss","title":"����˫��","name":"������",]),
(["id":"boss","title":"����˫��","name":"������",]),
(["id":"boss","title":"��צ����","name":"˾ͽ��",]),
(["id":"boss","title":"���ֻش�","name":"����ʯ",]),
(["id":"boss","title":"��������","name":"������",]),
(["id":"boss","title":"ݪ���ٸ�","name":"ʯ��¶","sex":1,]),
(["id":"boss","title":"����","name":"׿����",]),
(["id":"boss","title":"����˫��","name":"����",]),
(["id":"boss","title":"����˫��","name":"�ξ�",]),
(["id":"boss","title":"�ؼ�կ��ɽկ��","name":"�ع���",]),
(["id":"boss","title":"�����ɵ��ߴ�������","name":"������",]),
(["id":"boss","title":"�����ɵڰ˴�������","name":"������",]),
(["id":"boss","title":"��ţ������","name":"�°���",]),
(["id":"boss","title":"�°�������׷���","name":"����֮",]),
(["id":"boss","title":"������","name":"�ް�Ȫ",]),
(["id":"boss","title":"�Ĺȿ����޵�","name":"�غ���",]),
(["id":"boss","title":"��ũ�����","name":"˾����",]),
(["id":"boss","title":"ӥצ����������","name":"������",]),
(["id":"boss","title":"�����ű���������","name":"���ũ",]),
(["id":"boss","title":"������������������������","name":"��",]),
(["id":"boss","title":"�����ź���","name":"������",]),
(["id":"boss","title":"�������ƽ�˫��������","name":"������",]),
(["id":"boss","title":"�������ƽ�˫��������","name":"������",]),
(["id":"boss","title":"�������ڵ�һ����������","name":"��ʿ��",]),
(["id":"boss","title":"����ҩ��","name":"����",]),
(["id":"boss","title":"��������","name":"ʯ����",]),
(["id":"boss","title":"���Ž������˸��ػ���ʡ����","name":"����",]),
(["id":"boss","title":"������������","name":"������",]),
(["id":"boss","title":"��������","name":"������",]),
(["id":"boss","title":"��������","name":"����Ӣ",]),
(["id":"boss","title":"��������","name":"������",]),
(["id":"boss","title":"���ɽ�������","name":"����",]),
(["id":"boss","title":"�廢���������ϰ���","name":"������",]),
(["id":"boss","title":"Τ��˫��","name":"�����",]),
(["id":"boss","title":"Τ��˫��","name":"������",]),
(["id":"boss","title":"�����ھ�����ͷ��ʤ��ȭ","name":"���п�",]),
(["id":"boss","title":"�彣˫��","name":"��Х��",]),
(["id":"boss","title":"�������","name":"������",]),
(["id":"boss","title":"�������","name":"��ά��",]),
(["id":"boss","title":"�������һȭ����","name":"����֮",]),
(["id":"boss","title":"�������","name":"����",]),
(["id":"boss","title":"ʥ��٤��","name":"��Զ",]),
(["id":"boss","title":"����Գ","name":"������",]),
(["id":"boss","title":"��ȭ�޵�","name":"������",]),
(["id":"boss","title":"������ӷ������","name":"��ϣ��",]),
(["id":"boss","title":"�������������嶡��","name":"������",]),
(["id":"boss","title":"����������ӷ���ħŮ","name":"���پ�","sex":1,]),
(["id":"boss","title":"�����������ûӰ��","name":"÷����",]),
(["id":"boss","title":"ǧ�����","name":"ľɣ����",]),
(["id":"boss","title":"�ɶ��ɵ�ʮ��������ʦ","name":"��̶����",]),
(["id":"boss","title":"�ɶ��ɵ�ʮ��������","name":"��ľ����",]),
(["id":"boss","title":"�ɶ��ɵ�ʮ��������","name":"ˮ�Ƶ���",]),
(["id":"boss","title":"�ɶ��ɵ�ʮ��������","name":"���ӻ�",]),
(["id":"boss","title":"�ɶ��ɵ�ʮ��������","name":"��������",]),
(["id":"boss","title":"ʯ������","name":"�·���",]),
(["id":"boss","title":"���ϳ�","name":"�ϲ���",]),
(["id":"boss","title":"�˼�ȭ���Ű˱���߸","name":"����֮",]),
(["id":"boss","title":"��Ͽ����������һ","name":"������",]),
});
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

void create()
{
	mapping npc,mp,j;
	int i,k,a,b,c,d,e,f,temp;
	string sex;
	npc=data[random(8)+56];
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

	set("attitude","friendly");

        set("max_neili", 1145000);
        set("neili", 1145000);
        set("jing",118000+random(10000));
        set("max_jing",118000+random(10000));
set("eff_jing",118000+random(10000));
        set("qi",118000+random(10000));
        set("max_qi",118000+random(10000));
set("eff_qi",118000+random(10000));
 
        set_skill("parry", 490);
        set_skill("dodge", 490);
        set_skill("force", 490);
        set_skill("literate", 490);
	set_skill("sword", 490);
	set_skill("unarmed",490);
	set("combat_exp",40000000+random(5000000));
	set("magicset",1);
        set("zhuanbest",1);
        set("no_get",1);
        set("vendetta/authority",1);
        set_temp("apply/attack", 140);
        set_temp("apply/defense", 140);
        set_temp("apply/armor", 2800);
        set_temp("apply/damage", 2800);
        set("killer_reward", ([
                "FI&/clone/box/gbox"   :   8000,
                "TW&480"   :  500,
                "TA&480"   :  500,
                "RI&40"   :   500,
                "GE&4"   :  500,
                "JD&5"   :  500,
                "YC&3"   :  500,
                "WG&3"   :  500,
                "KS&5"   :   500,
                "BL&5"   :  500,
                "YW&4"   :  500,
                "YA&4"   :  500,
        ]));
	set("bonus", 8888+random(8888));

a=270000+random(80000);
b=270000+random(80000);
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
 	 initlvl(550+random(100),random(40));
}

void init( )

{
	object ob;	
        remove_call_out("hunting");
	if( interactive(ob = this_player())  ) {
ob->start_busy(1);
        call_out("hunting",0);
        }
	if(!environment()->query("no_fight"))
        call_out("hunting",0);
}

void hunting()
{
	int i;
        object *ob;
        ob = all_inventory(environment());
        for(i=sizeof(ob)-1; i>=0; i--) {
        if( !ob[i]->is_character() || ob[i]==this_object() || !living(ob[i])) continue;
        if(ob[i]->query("vendetta/authority")) continue;
                kill_ob(ob[i]);
                ob[i]->fight(this_object());
        }
}

int hit_ob(object me, object ob, int damage)
{
	if (me->is_busy()) me->start_busy(1);
me->clear_condition();	

  if ( random(me->query("combat_exp"))>(int)ob->query("combat_exp")/3)
{
if (random(10)==0)
{
ob->apply_condition("new_poison1", 5); 
}
else if (random(9)==0)
{
ob->apply_condition("new_poison2", 5); 
}
else if (random(8)==0)
{
ob->apply_condition("new_poison3", 5); 
}
else if (random(7)==0)
{
ob->apply_condition("new_poison4", 5); 
}
else if (random(6)==0)
{
ob->apply_condition("new_poison5", 5); 
}
else if (random(5)==0)
{
ob->apply_condition("new_poison6", 5); 
}
        tell_object(ob, HIG "����ñ����еĵط�����һ��⻪��\n" NOR );
}
}
int big_blowing()
{
if (this_object()->is_busy()) this_object()->start_busy(1);
	this_object()->clear_condition();
        return 1;
}