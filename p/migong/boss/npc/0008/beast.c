#include <ansi.h>
inherit BOSS;
string *first_name = ({ "��", "����"});
string *first_id = ({ "lei", "leiting"});
string *name_words = ({ "��", "��"});
string *id_words = ({ "yao", "guai"});
int combatpower();

void create()
{
        string name;
        int i,j,k,a,b,c,d,e,f,temp;
        
        i = random(sizeof(first_name));
        name = first_name[i];
        j = random(sizeof(name_words));
        name += name_words[j];

        set_name(name, ({ first_id[i]+" "+id_words[j] }) );
        //random_name_color(this_object());
        
        set("age", 20);
        set("vrm_guard", 1);
	set("attitude", "aggressive");

	set("chat_chance_combat", 10);
	set("chat_msg_combat", ({
		(: combatpower :),
	}) );
   set("combat_exp", 85000000);
        set("level", 35);
        set("qi", 80000);
        set("max_qi", 80000);
        set("jing", 85000);
        set("max_jing", 85000);
        set("neili", 170000);
        set("max_neili", 170000);
        set("jiali", 1000);

        set_skill("unarmed", 3500); 
        set_skill("dodge", 3500); 
        set_skill("parry", 3500); 
        set_skill("force", 3500); 
	

        set_temp("apply/attack", 100);
        set_temp("apply/damage", 600);
        set_temp("apply/armor", 600);
        set_temp("apply/defence",100);  

set_skill("unarmed",300);
	set_skill("hammer",780);
	set_skill("tiexue-hammer",720);
	set_skill("force", 260);
	set_skill("guiyuan-tunafa", 720);
	set_skill("dodge", 260);
	set_skill("shuishangpiao", 720);
	set_skill("strike", 280);
	set_skill("tiezhang-zhangfa", 750);
	set_skill("parry", 180);
	set_skill("literate", 100);
	set_skill("axe", 780);
	set_skill("duanyun-fu", 750);
	map_skill("hammer", "tiexue-hammer");
	set_skill("duanyun-fu", 750);
	set_skill("tongbi-zhang", 750);
	map_skill("force", "guiyuan-tunafa");
	map_skill("dodge", "shuishangpiao");
	map_skill("unarmed", "tiezhang-zhangfa");
	map_skill("strike", "tongbi-zhang");
	map_skill("parry", "tiezhang-zhangfa");
	prepare_skill("strike", "tiezhang-zhangfa");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "strike.chu" :),
                (: perform_action, "strike.juesha" :),
                (: perform_action, "strike.tui" :),
                (: perform_action, "strike.zhui" :),
                (: perform_action, "hammer.fanzhuan" :),
                (: perform_action, "unarmed.dao" :),
                (: perform_action, "unarmed.ying" :),
                (: perform_action, "unarmed.yin" :),
                (: perform_action, "unarmed.tianlei" :),
                (: perform_action, "unarmed.tiezhangxianglong" :),
                  (: perform_action, "unarmed.zhangdao" :),
		(: command("unwield bighammer") :),
		(: command("wield bighammer") :),
        }) );
if (random(18)==0)
{
set("nickname",HIY"�书�߳�"NOR);
        set_skill("spells",1000+random(1000));
        set_skill("force",1000+random(1000));
	set_skill("unarmed",1000+random(1000));
	set_skill("sword",1000+random(1000));
	set_skill("club",1000+random(1000));
	set_skill("whip",1000+random(1000));
	set_skill("throwing",1000+random(1000));
	set_skill("parry",1000+random(1000));
}
else
if (random(18)==0)
{
set("nickname",MAG"ħ��ǿ��"NOR);
      set_skill("magic-unarmed", 850+random(1300));
      set_skill("magic-sword", 850+random(1300));
      set_skill("magic-ice", 850+random(1200));
      set_skill("magic-water", 850+random(1200));
      set_skill("magic-fire", 850+random(1200));
      set_skill("magic-earth", 850+random(1200));
      set_skill("magic-light", 850+random(1200));
      set_skill("magic-dark", 850+random(1200));
}
else
if (random(18)==0)
{
set("nickname",HIB"����ḻ"NOR);
set("combat_exp",150000000+random(58000000));
}
else
if (random(18)==0)
{
set("nickname",HIR"ǿ����"NOR);
set("dex",300);
        set("jing",900000);
        set("max_jing",900000);
        set("eff_jing",900000);
        set("qi",900000);
        set("max_qi",900000);
        set("eff_qi",900000);
        set("neili",900000);
        set("max_neili",900000);
}
else
if (random(18)==0)
{
set("nickname",HIC"������ǿ"NOR);
d=188+random(188);
set("str",d);
set("dex",30+d);
set("int",d);
set("con",d);
set("per",d);
set("kar",d);
}
else
if (random(18)==0)
{
set("dex",300);
        set("jing",800000);
        set("max_jing",800000);
        set("eff_jing",800000);
        set("qi",800000);
        set("max_qi",800000);
        set("eff_qi",800000);
        set("neili",800000);
        set("max_neili",800000);
      set_skill("magic-unarmed", 850+random(800));
      set_skill("magic-sword", 850+random(800));
      set_skill("magic-ice", 850+random(800));
      set_skill("magic-water", 850+random(800));
      set_skill("magic-fire", 850+random(800));
      set_skill("magic-earth", 850+random(800));
      set_skill("magic-light", 850+random(800));
      set_skill("magic-dark", 850+random(800));
        set_skill("spells",850+random(800));
        set_skill("force",850+random(800));
	set_skill("unarmed",850+random(800));
	set_skill("sword",850+random(800));
	set_skill("club",850+random(800));
	set_skill("whip",850+random(800));
	set_skill("throwing",850+random(800));
	set_skill("parry",850+random(800));
set("nickname",HIC"�����޵�"NOR);
d=188+random(188);
set("str",d);
set("dex",30+d);
set("int",d);
set("con",d);
set("per",d);
set("kar",d);
}

		set("bonus", 750);
        set("killer_reward", ([
                "FI&/clone/box/gbox"   :   600,
                "TW&480"   :  390,
                "TA&480"   :  390,
        ]));

	set_weight(500000);
        setup();
carry_object("/d/tiezhang/npc/obj/hammer")->wield();        
        // init_npc(this_object(), 10, 6, 6, 100);
// �Զ�����NPC���Ժͼ��ܣ���һ���������롣
// ��һ������ΪNPC��OB
// �ڶ�������ΪNPC�����ɣ�0����1�ظ�2����3�¹�4ѩɽ5��ׯ6����7�޵׶�����Ϊ������������Ϊ�������
// ����������ΪNPC�ļ��ܣ���NPC�ĵȼ�����(1:50)��ȱʡ��0Ϊ������
// ���ĸ�����ΪNPC�����Ժ�״̬�ȼ�����NPC�ĵȼ����ã�ȱʡ��0Ϊ������
// ���������ΪNPC��ǿ�ȣ�ȱʡΪ100
}
void init()
{
        object me, ob;

        ::init();
        if (! interactive(me = this_player()))
                return;
        
        if( !me->is_character() || me==this_object() || !me) return;
        if(me->query("vendetta/authority")) return;
        if(!userp(me)) return;
        
        remove_call_out("kill_ob");
        call_out("kill_ob", 0, me);
}
