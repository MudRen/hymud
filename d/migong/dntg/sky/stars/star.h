//Cracked by Roath

//�����ǹ�
inherit NPC;
#include "action.h"
#include "party.h"

mapping *menpai=({
(["mp":"wudang",]),
(["mp":"lingjiu",]),
(["mp":"taohua",]),
(["mp":"tiandihui",]),
(["mp":"mingjiao",]),
(["mp":"gumu",]),
(["mp":"huashan",]),
(["mp":"gaibang",]),
(["mp":"quanzhen",]),
(["mp":"dali",]),
(["mp":"tiezhang",]),
(["mp":"murong",]),
(["mp":"kunlun",]),
(["mp":"lingxiao",]),
(["mp":"wdjiao",]),
(["mp":"jiuyin",]),
(["mp":"noname",])
});
string *ns = ({	"force",
		"dodge",
		"parry",
		"unarmed",
		"strike",
		"cuff",
		"finger",
		"claw",
		"hand",
		"leg",
		"sword",
		"blade",
		"whip",
		"hammer",
		"staff",
		"axe",
		"literate",
		"shenzhao-jing",
});

mixed get_auto_actions(string action);
void change_combat_mode(object me, int mode);

string *title=({"�����Ǿ�",
		"��ľ�Ǿ�",
		"Ů���Ǿ�",
		"ţ���Ǿ�",
		"��ˮ�Ǿ�",
		"�һ��Ǿ�",
		"Σ���Ǿ�",
		"�����Ǿ�",
		"��ľ�Ǿ�",
		"θ���Ǿ�",
		"¦���Ǿ�",
		"��ˮ�Ǿ�",
		"�����Ǿ�",
		"�����Ǿ�",
		"�����Ǿ�",
		"��ľ�Ǿ�",
		"�����Ǿ�",
		"�����Ǿ�",
		"��ˮ�Ǿ�",
		"�����Ǿ�",
		"�����Ǿ�",
		"�����Ǿ�",
		"��ľ�Ǿ�",
		"ص���Ǿ�",
		"�����Ǿ�",
		"��ˮ�Ǿ�",
		"β���Ǿ�",
		"�����Ǿ�",
});

string *long=({
"������������䣬�෢�𾦶��绢\n���绽�겻Ѱ����ն����Ϊ������\n", 
"����ɴ��ͷ�ϸǣ����������ޱ���\n����������ƽ����ն����Ϊ��ľ��\n",
"�绢��ɽ�ۺ�¹����а׽�������\nֻ���޸����ɼң�ն����ΪŮ����\n",
"������ɽ�����Σ������ε�������\n����¯�ڽ𵤹���ն����Ϊţ��ţ\n",
"����������ȫ�⣬�Ͼ��������ɷ�\n����������컯��ն����Ϊ��ˮ��\n",
"�ؽ̴���ת���࣬���������ù���\n��ɰ������������ն����Ϊ�һ���\n",
"������ɰ���Ƶ壬�������½����\n������������ԣ�ն����ΪΣ����\n",
"�������������룬�������ֿ����\nֻ���޸�Ϊ���£�ն����Ϊ���ռ�\n",
"��������һ�߳��������������Ϸ�\n�����ɵ���������ն����Ϊ��ľ��\n",
"���������������������������\n�޷���Ե��������ն����Ϊθ����\n",
"����������ƥ���������񵤳ɲ���\n��Ե������������ն����Ϊ¦��\n",
"����������ԣ����޿��������\n��ɽ���������⣬ն����Ϊ��ˮԳ\n",
"��������ֹ���ޣ���������������\n��Ϊ���ص�ɰ����ն����Ϊ�����\n",
"������������ޣ����������ձ���\n�������̰���٣�ն����Ϊ������\n",
"�޳ɴ��������������������\n���ܳ���ȴ������ն����Ϊ������\n",
"�޳ɵ�����������޿�����췢��\n���ι�����������ն����Ϊ��ľ��\n",
"�����������췽������׫�����л�\n������̹�ؽ̣�ն����Ϊ�����\n",
"���������˷����������������\nֻ��ɱ�����Ӷ㣬ն����Ϊ������\n",
"��ڵ����Դ��������Ͱ���������\nֻ���޸��˳�����ն����Ϊ��ˮ�\n",
"���ڿھ�����а���������������\n�����۶��ѳɾͣ�ն����Ϊ������\n",
"���������޶�������������������\n˭֪����δ��Ԫ��ն����Ϊ����¹\n",
"����������¶��ϼ��ǰ�����ٲ�\n�������ڳ�Ӣ�ۣ�ն����Ϊ������\n",
"һ����ɴ�Ժ�Ʈ������ˮ����˿��\nԭ��һ�������ն����Ϊ��ľ��\n",
"�෢������������ξ���ɽ������\n����������ͽ�ͣ�ն����Ϊ������\n",
"�������ѷ���������������ͨ\nδ����ʬ��������ն����Ϊ������\n",
"�Դ�����������������¹���ھ\nͨ���������ʦ��ն����Ϊ��ˮ��\n",
"����ϼ�����ݹţ�˫���ư���ز�\n���ķõ�ѧ������ն����Ϊβ��\n",
"�����������������������������\n���������ֿ�磬ն����Ϊ���º�\n",
});

void create()
{
	mapping npc,mp,j;
	mapping hp_status, skill_status, map_status, prepare_status;
mapping my;
string *sname, *mname, *pname;
	string sex;
	object ob, weapon;
	int i,k,a,b,c,d,e,f,temp;
  int gd,sk;
        	string tt, ll;
	mp=menpai[random(sizeof(menpai))];
	j=ps[random(sizeof(ps))];
ob=this_object();
	k=random(17);
        gd=random(2);
        sk=random(10);

//	int ID=random(26);
	tt = title[ID];
	ll = long[ID];

        set_name("�Ǿ�", ({"xing jun", "star"}));
	set("title", tt);
	set("long", ll);
	set("gender", "����");
	set("class", "xian");
	set("age", 20);
	set("per", 30);
	set("no_check", 1);	
	set("combat_exp", 1000000);
	set("daoxing", 1000000);

	set("combat_exp",3000000+random(20000000));
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
b=4000+random(4000);
a=6000+random(9000);
d=30+random(60);
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
        i=200+random(500);
        e=200+random(500);
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
       

mixed get_auto_actions(string action)
{
	int i, flag = 0;

	for (i = 0; i < sizeof(pfm); i++)
		if (pfm[i]["party"] == query("party")) {
			flag = 1;
			break;
		}
	if (!flag)
		return ({ });
	if (arrayp(pfm[i][action]))
		return pfm[i][action];
	else
		return ({ });
}

void change_combat_mode(object me, int mode)
{
	switch (mode) {
	case 0:
		delete("chat_chance_combat");
		delete("chat_msg_combat");
		set("jiali", 1);
		break;
	case 1:
		set("chat_chance_combat", 100);
		set("chat_msg_combat", get_auto_actions("perform"));
		set("jiali", 50);
		break;
	case 2:
		set("chat_chance_combat", 100);
		set("chat_msg_combat", get_auto_actions("perform1"));
		set("jiali", (int)query_skill("force") / 2);
		break;
	case 3:
		set("chat_chance_combat", 100);
		set("chat_msg_combat", get_auto_actions("perform2"));
		set("jiali", 1);
		break;
	default:
		set("chat_chance_combat", 80);
		set("chat_msg_combat", get_auto_actions("perform"));
		set("jiali", 50);
		return;
	}
	set("combat_mode", mode);
//	me->set("guard/status/combat_mode", mode);
}

void random_chat()
{
  string *e,str="";
   int i;
   object npc,*inv;
if (!environment(this_object()))
   return;
   inv=all_inventory(environment(this_object()));
	if(!sizeof(inv))	return;
 
   e = sort_array(EMOTE_D->query_all_emote(), 1);
   str=e[random(sizeof(e))];
   command(str+" "+inv[random(sizeof(inv))]->query("id"));
   set("answer",str);  
   return;
}

int chat()
{
	int i, ratio, chance, rnd, flag = 0;
	string *msg, *emotes, cmd;
	object *inv, *killer;

	if (!is_busy() 
	&& living(this_object())
	&& environment(this_object()) )
	{
		if (arrayp(msg = get_auto_actions("powerup")))
			for (i = 0; i < sizeof(msg); i++)
				if (functionp(msg[i]))
					evaluate(msg[i]);
	}


	if (query("neili") > 100 && query("max_neili") > 200 && !is_busy()
	&& living(this_object())
	&& environment(this_object()) 
	) {
		if (query("eff_jing") && query("jing") * 100 / query("eff_jing") <= 80)
			command("exert regenerate");

		if (query("eff_qi") && query("qi") >= 0 && query("qi") * 100 / query("eff_qi") <= 80)
			command("exert recover");

		if (query("eff_qi") && query("qi") >= 0
		&& query("max_qi") && !is_fighting() && !query("mute")
		&& query_skill_mapped("force")
		&& query("eff_qi") < query("max_qi")
		&& query("eff_qi") >= query("max_qi") / 3)
			command("exert heal");

		if (query("max_neili")
		&& query("neili") * 100 / query("max_neili") <= 80
		&& !is_fighting()
		&& query_skill_mapped("force")) {
			i = 1 + (int)query_skill("force") / 15 * (1 + (int)query_skill("force") / 100);
			command(sprintf("dazuo %d", i));
		}

	}

	if( !chance = (int)query(is_fighting()? "chat_chance_combat": "chat_chance") )
		return 0;

	if( arrayp(msg = query(is_fighting()? "chat_msg_combat": "chat_msg"))) {
		if( query_temp("is_unconcious") ) return 0;
		if(!living(this_object()) ) return 0;
		if(!environment(this_object())  ) return 0;

		if( random(100) < chance ) {
			rnd = random(sizeof(msg));
			if( stringp(msg[rnd]) )
				say(msg[rnd]);
			else if( functionp(msg[rnd]) )
				return evaluate(msg[rnd]);
		}
		return 1;
	}

	return 1;
}


void init()
{
	object ob;
	ob=this_player();
	::init();
	
	if( wizardp(ob) && !this_object()->query("have_name") ){
		tell_object(ob,"������Ǿ���δ����������(setname ����)��\n");
	}
	add_action("setname", "setname");
	return;
}

int setname(string arg)
{
	object ob;
	ob=this_player();

	if(!wizardp(ob))
		return notify_fail("ʲô��\n");

	if(!arg)
		return notify_fail("����(setname ����)��\n");

	tell_object(ob, "�����Ķ��ɹ���\n");
	this_object()->set("have_name", 1);
	this_object()->set("name", arg);
	//this_object()->save();
	return 1;
}