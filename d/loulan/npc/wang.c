#include <ansi.h>
inherit NPC; 
void create()
{
        object armor;
        set_name("������", ({ "wang lianhua","wang" }) );
        set("gender", "����" );
        set("title", "ǧ�湫��" );
        set("nickname", HIM"���ž���������"NOR );
        set("long",
                "һ�����û����������ꡣ����ݰף���ü��Ŀ����ɫ����͸�죬������������\n"
                );
        set("attitude", "peaceful");
        set("chat_chance_combat",50);
        set("chat_msg_combat",({
                      (:perform_action,"blade.shiwanshenmo":),
                      (:perform_action,"dodge.huanyingqianchong":),
        }));
        set("age", 25);
        set("cps", 40);
        set("int", 50);
        set("per", 40);
        set("cor", 40);
        set("agi", 30); 
        set("combat_exp", 3500000);
        set("neili", 50000);
        set("max_neili", 50000);
	set("max_qi",19999);
        set("max_jing",19999);
	set("eff_qi",19999);
	set("qi",19999);
	set("eff_jing",19999);
	set("jing",19999);
        set("force_factor", 30);  
        set("chat_chance", 1);
        set("chat_msg", ({
                "��������Ц�����������ۣ�ҲҪ�����˼���ⳡ��Ϸ�� \n",
                "��������Ц�������ˡ������ˡ������˿��������Ͱ׷ɷɡ�����  \n",
                }) ); 
        set_skill("unarmed", 540);
        set_skill("blade", 500);
        set_skill("bat-blade", 550);
        set_skill("dodge", 580);
        set_skill("parry", 580);
        set_skill("move", 500);
        set_skill("meng-steps", 540);
        set_skill("nine-moon-claw", 540);
        
        map_skill("move","meng-steps");
        map_skill("dodge", "meng-steps");
        map_skill("unarmed", "nine-moon-claw");
        map_skill("blade", "bat-blade");
        map_skill("parry", "bat-blade");
                       set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 600);
        setup();
        carry_object(__DIR__"obj/sword2")->wield();
        armor=new("/clone/misc/cloth");
        armor->set_name("��Ƥ����",({"coat"}) );
        armor->move(this_object());
        armor->wear();
}
