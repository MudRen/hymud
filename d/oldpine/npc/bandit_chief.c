 // bandit_chief.c
inherit NPC; 
void create()
{
        set_name("�����ϴ�", ({ "bandit chief", "chief" }) );
        set("gender", "����");
        set("age", 39);
        set("long",
                "��һ������׶�һ˫���������������������Ĳ��ӡ�\n");
        set("combat_exp", 6000);
        set("score", 700);
        set("attitude", "aggressive");
        set("chat_chance", 10);
        set("chat_msg_combat", ({
                "\n�����ϴ���������˵�����ԹԵ����°ɣ�\n",
                "\n�����ϴ󻢺�һ����������ǰ��\n"
        }) );
 set("combat_exp", 400000+random(900000));
        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: perform_action, "blade.leitingpili" :),
                (: perform_action, "blade.kuang" :),
        }) );


	set("max_qi", 3000);
	set("max_jing", 3000);
	set("neili", 3000);
	set("max_neili", 3000);
        set_skill("unarmed", 80+random(180));
        set_skill("blade", 80+random(180));
        set_skill("parry", 80+random(180));
        set_skill("dodge", 180+random(180));
        set_skill("kuang-blade", 80+random(380));
        
        map_skill("blade", "kuang-blade");
        map_skill("parry", "kuang-blade");
        set_temp("apply/attack", 20);
        set_temp("apply/defense",50);
        set_temp("apply/armor", 50);
        set_temp("apply/damage", 20);
        setup();
        carry_object(__DIR__"obj/blade")->wield();
        carry_object(__DIR__"obj/leather")->wear();
        add_money("silver", 30);
} 
void start_help()
{
        say("һ����Ӱ�����ּ�Ծ�������ֽý��������书\������\n");
        command("say ������... ���⼸��С��ɫҲ�򷢲��ˣ�վ��һ�㣡\n");
}   
