#include <ansi.h>
inherit NPC;
inherit F_VENDOR; 
void create()
{
        set_name("���Ϲ�", ({ "mai laoguang", "mai" }) );
        set("nickname","��Ѽ��");
        set("long",
"���Ϲ��Ǽ�����Ĵ�������û�����˼��������Ŀ�Ѽ������ˮ�ģ�
���Լ�ʹ���������ͣ��ͺ���������Ͷ���������Ҳû���ں���\n");
        set("chat_chance",2);
        set("chat_msg", ({
                        "���Ϲ�������ҵ��ص�����ϵ��������ϵ����úݣ���Ǯϵ���¶࣬Խ���Խϵ�á���\n",
                        "���ϏV����Ц���s��������������ϵ�ͩo����ϵ���ȥ�ġ���\n",  
                                })  ); 
        set("age", 50);
        set("combat_exp", 1000000);
        set("max_jing",1000);
        set("max_qi",1000);
        set("max_jing",6000);
        set_temp("apply/attack",50);
        set_temp("apply/damage",50);
        set_temp("apply/armor",150);
        set("max_neili",1500);
        set("force",2500);
        set("force_factor",30);
        set("no_arrest",1);
        set_skill("unarmed",150);
        set_skill("dodge",150);
        set_skill("parry",150);
        set_skill("changquan",150);
        map_skill("unarmed", "changquan");
	set("vendor_goods", ({
                __DIR__"obj/kaoya",
                __DIR__"obj/sausage",
                __DIR__"obj/tongue",
	}));
        setup();
        carry_object("/clone/misc/cloth")->wear();
} 
void init()
{
        ::init();
	add_action("do_buy", "buy");
	add_action("do_list", "list");
} 
void die()
{
        object ob;
        object feng;
        object *enemy;
        feng = this_object();
        ob = query_temp("last_damage_from");
        if(!ob)
        { 
                enemy = this_object()->query_enemy();
                ob=enemy[0];
        }
        if(userp(ob)) {
                if(feng->query("name") == "������") {
                        ob->set_temp("marks/fugui_killed_feng",1);
                }
                else {
                        ob->set_temp("marks/fugui_killed_mai",1);
                }
        }
        ::die();
} 
