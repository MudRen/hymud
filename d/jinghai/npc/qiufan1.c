inherit NPC;
 
void create()
{
        set_name("������", ({"zhang tufu","tufu"}));
        set("long", "����һ��������������꺺�ӡ�\n");
        set("gender","����");
        set("title","��������ͽ[����]");

        set("age",39);
        set("con",30);
        set("str",50);
        set("max_qi",2500);
        set("max_jing",2500);
        set("max_sen",2500);
        set("attitude", "aggressive");


        set("chat_chance",5);
        set("chat_msg",({
        "������̾����:������ԩ���ã���ԩ������ԩ������\n"
}));

        set_skill("dodge",250);
        set_skill("demon-blade",250);
        set_skill("parry",250);
        set_skill("unarmed",250);
        set_skill("force",250);
        set_skill("jingyiforce",280);
        set_skill("blade",250);
 
        map_skill("force","jingyiforce");
        map_skill("blade","longjiao-blade");
        map_skill("parry","longjiao-blade");
        map_skill("unarmed","changquan");
        map_skill("dodge","fengyu-piaoxiang");
        set("combat_exp",2000000+random(700000));

        setup();
        carry_object(__DIR__"obj/qiuyi")->wear();
        carry_object(__DIR__"obj/kao")->wear();
}

