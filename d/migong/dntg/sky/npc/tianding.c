// tian-ding1.c
// created 4-8-97 pickle
#include <ansi.h>
inherit NPC;
#include "action.h"
#include "party.h"


varargs void drool(string msg, string who);

void create()
{
  string name, id;

       int rd;
 

	mapping npc,mp,j;
	mapping hp_status, skill_status, map_status, prepare_status;
mapping my;
string *sname, *mname, *pname;
	string sex;
	object ob, weapon;
	int i,k,a,b,c,d,e,f,temp;

        int gd,sk;
	mp=menpai[random(sizeof(menpai))];
	j=ps[random(sizeof(ps))];
ob=this_object();
	k=random(17);
        gd=random(2);
        sk=random(10);        
                rd=random(4);
  set_name("�춡", ({ "tian ding", "tian", "ding" }) );
  set("gender", "����" );
  set("long", "

�����������°˴�����֮һ������������ϸ��Ѱ��
ÿһ���������ˡ�
");
  set("title", "�����춡");
  set("age", 35+random(10));
  set("attitude", "peaceful");
  set("str", 27);
  set("int", 25);
  set("combat_exp",400000);
  set("neili",500);
  set("max_neili",500);
  set("force_factor", 20);
  set("max_qi", 900);
  set("max_jing", 600);
  set("max_mana", 400);
  set("mana", 400);
  set("mana_factor", 20);
 	set("combat_exp",13000000+random(20000000));
	set_temp("apply/attack",30);
	set_temp("apply/defense",30);
	set_temp("apply/armor",250);
	set_temp("apply/damage",250);
	set("max_force",2000);
	set_skill("unarmed",200);
	set_skill("sword",200);
	set_skill("club",200);
	set_skill("whip",200);
	set_skill("throwing",200);
	set_skill("parry",200);
	set_skill("dodge",200);
        set("szj/passed",1);
        set("double_attack",1);
        set("breakup", 1);
        set("szj/over200", 1);
        set("jiuyin/full", 1);
        set("jiuyin/shang", 1);
        set("jiuyin/xia", 1);
b=14000+random(4000);
a=16000+random(9000);
d=60+random(60);
set("str",d);
set("dex",d);
set("int",d);
set("con",d);
set("per",d);
set("kar",d);
        set("jing",b);
        set("max_jing",b);
set("eff_jing",b);
        set("neili",a);
        set("max_neili",a);
	this_object()->set("party",ps[k]["party"]);
	this_object()->set_skills(ps[k]["skills"]);
	this_object()->set_skill_map(ps[k]["skill_map"]);
	this_object()->set_skill_prepare(ps[k]["skill_prepare"]);
        i=800+random(500);
        e=800+random(500);
	for (k = 0; k < sizeof(ns); k++)
		this_object()->set_skill(ns[k], i);

		this_object()->set_skill("literate",i);
        this_object()->set_skill("shenzhao-jing",e);
if (mapp(skill_status = this_object()->query_skills()))//�ж��Լ��Ƿ��й������н����������ȫ��ɾ��
{
skill_status = this_object()->query_skills();
sname = keys(skill_status);//���������Լ��Ĺ�������

temp = sizeof(skill_status);
for (i = 0; i < temp; i++)
this_object()->set_skill(sname[i],e);//ɾ���Լ����й���
}
        this_object()->change_combat_mode();
set("chat_chance_combat", 100);
set("chat_msg_combat", get_auto_actions("perform"));
change_combat_mode(ob, 1);
        
f=1+random(8);        
	setup();

	if (ob->query("gender")=="Ů��")
	{
	carry_object("/clone/cloth/female"+f+"-cloth")->wear();
	carry_object("/clone/cloth/female-shoe")->wear();
	}
else {
	carry_object("/clone/cloth/male"+f+"-cloth")->wear();
	carry_object("/clone/cloth/male-shoe")->wear();
}        
        if (stringp(ob->query_skill_mapped("sword"))) 
	carry_object(__DIR__"weapon/sword")->wield();
	if (stringp(ob->query_skill_mapped("blade"))) 
	carry_object(__DIR__"weapon/dao")->wield();
	if (stringp(ob->query_skill_mapped("whip"))) 
	carry_object(__DIR__"weapon/bian")->wield();
	if (stringp(ob->query_skill_mapped("hammer"))) 
	carry_object(__DIR__"weapon/hammer")->wield();
	if (stringp(ob->query_skill_mapped("staff"))) 
	carry_object(__DIR__"weapon/ban")->wield();
	if (stringp(ob->query_skill_mapped("axe"))) 
	carry_object(__DIR__"weapon/axe")->wield();

	add_money("silver",50+random(50));
}
void init( )

{
	object ob;	
        remove_call_out("hunting");
	if( interactive(ob = this_player())  ) {
ob->start_busy(1);
        call_out("hunting",0);
        }
	if(!environment()->query("no_fight") )
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
if(wizardp(ob[i])) continue;
         if(!userp(ob[i])) continue;
                kill_ob(ob[i]);
                ob[i]->fight(this_object());
        call_out("check",0);
        }
}