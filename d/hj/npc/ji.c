// Jay 3/17/96
#include <ansi.h>;
inherit NPC;
string ask_ma();
string ask_li();
void create()
{
        set_name("������", ({ "ji laoren", "ji"}));
        set("gender", "����");
        set("age", 83);
        set("long", "��ͷ�׷�������һ���Ǻڵģ�������Ǹߴ�
ֻ�ǹ�������������ȫ�����ƣ�˥���Ѽ���\n");
        set("attitude", "friendly");

        set("shen", 4800);
      set("str", 60);
        set("int", 69);
        set("con", 60);
        set("dex", 68);

        set("qi", 53900);
        set("max_qi", 53900);
        set("jing", 53900);
        set("max_jing", 53900);
        set("neili", 61500);
        set("max_neili", 61500);
        set("jiali", 50);

        set("combat_exp", 9500000);
        set("score", 200000);
        set_skill("force", 370);
        set_skill("unarmed", 300);
        set_skill("dodge", 350);
        set_skill("parry", 350);
        set_skill("hand",370);
        set_skill("staff", 370);
        set_skill("taixuan-gong", 550);

set_skill("huanhe-dao", 580);
set_skill("sata-shenfa", 350);
set_skill("sumi-jian", 350);
set_skill("wuyu-quan", 350);
set_skill("xiuli-qiankun", 350);
set_skill("strike", 250);
set_skill("cuff", 250);
set_skill("unarmed", 250);
set_skill("blade", 550);
set_skill("sword", 350);
set_skill("club", 380);
set_skill("bawang-qiang", 580);
//map_skill("sword", "sumi-jian");
map_skill("blade", "huanhe-dao");
map_skill("strike", "xiuli-qiankun");
map_skill("cuff", "wuyu-quan");
      map_skill("force", "taixuan-gong");
        map_skill("dodge", "sata-shenfa");
        map_skill("parry", "taixuan-gong");
        map_skill("unarmed", "taixuan-gong");
    	prepare_skill("strike", "xiuli-qiankun");
	prepare_skill("cuff", "wuyu-quan");

        
	set("chat_chance_combat", 90);
       set("chat_msg_combat", ({
                (: perform_action, "blade.huan" :),
                	(: perform_action, "blade.kuang" :),
                		(: perform_action, "blade.leitingpili" :),
                			(: perform_action, "blade.shiwanshenmo" :),
                				(: perform_action, "blade.tiandirenmo" :),
                					(: perform_action, "blade.xueyu" :),
                						(: perform_action, "blade.baoxue" :),
                						(: perform_action, "blade.baoxue" :),                							
                (: perform_action, "parry.po" :),
                (: perform_action, "parry.jing" :),
                (: perform_action, "parry.xuan" :),
                (: perform_action, "parry.po" :),
                (: perform_action, "parry.taixuan" :),
                
        }) );
	set_temp("apply/attack", 200);
	set_temp("apply/defense", 200);
	set_temp("apply/armor", 1000);
	set_temp("apply/damage", 1600);
        set("inquiry", ([
            "��ҿ�" : (: ask_ma :),
            "������" : (: ask_li :),
            "��������" : "������������������ҵ����ơ�\n",
            "����" : "˭���Ҳ�֪������ˡ�\n",
        ]) );
        setup();
        carry_object(__DIR__"obj/bishou")->wield();
        carry_object(__DIR__"obj/yangao")->wear();
      if (clonep(this_object())) 
        carry_object("/d/hj/obj/rousisuo");
}

string ask_li()
{
    object me, ob, where;
    me=this_player();
    ob = find_living("li wenxiu");
    if (!ob) return "�⺢�ӣ���֪��������ȥ�ˣ���������\n";
    where = environment(ob);
       if (!where) return "�⺢�ӣ���֪��������ȥ�ˣ���������\n";
    return "Ŷ���⺢�Ӻ����ܵ�"+where->query("short")+"��ȥ�ˡ�";        
}

string ask_ma()
{
	mapping fam; 
    object me, ob, where;
    me=this_player();
	
	if ((int)me->query("jinyong/book6") !=4 )
		return "��˵����˭�����������ף�";

	me->set_temp("marks/killji", 1);
	this_object()->set("qi",this_object()->query("max_qi"));
	this_object()->set("jing",this_object()->query("max_jing"));
	this_object()->set("neili",this_object()->query("max_neili"));
	this_object()->kill_ob(me);
	me->kill_ob(this_object());
	return "��Ȼ��ʶ�����ң����ȥ����!";
}

void unconcious()
{
    die();
}
void die()
{
        int i;
        object ob, me, corpse,who;
        
        ob = this_object();
        me = query_temp("last_damage_from");
if (!me) return;
              //me->add("score",1);        

who=me;        
       if(who->query("jinyong/book6")==4 && who->query_temp("marks/killji")) {
        message_vision(RED"$N��˵������Ӧ,��Ӧ.....������Ѫֱ����������ȥ!\n"NOR,ob,me);
		i = 500+random(3000);
		who->set("jinyong/book6",5);
		who->add("combat_exp",i+20000);
		who->add("potential",i*15);
		who->add("mpgx",10);
		who->add("expmax",2);
		//command("chat "+this_player()->query("name")+"��ɫ���ˣ������Ƕ�ԡ�");
		tell_object (who,"��Ӯ����"+chinese_number(i+20000)+"�㾭��"+
		           chinese_number(i*15)+"��Ǳ��"+"ʮ�����ɹ��� ����ɳ����ޣ���\n");
		message("channel:chat", HIB"������III����˵"+who->name() + "����˰���Х�������������!"NOR"\n", users());
		who->save();
        }




              ::die();
        return;
}