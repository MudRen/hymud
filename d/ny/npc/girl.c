
// girl.c

inherit NPC;

void create()
{
        set_name("������", ({ "liuh wheixin", "liuh", "wheixin" }) );
        set("gender", "Ů��" );
          set("shen_type",1);
        set("age", 15);
        set("str", 16);
        set("cor", 24);
        set("cps", 11);
        set("per", 27);
        set("int", 27);

        set("attitude", "friendly");

        set("max_force", 200);
        set("force", 200);
        set("force_factor", 2);

        set("long",     "�������Ǵ�����ݹ���������Ķ���Ů��\n");

        create_family("��ɽ��", 14, "����");

        set("combat_exp", 100000);

        set("chat_chance_combat", 25);
        set("chat_msg_combat", ({
                (: perform_action, "sword.counterattack" :),
                
"��������ü΢����˵����ι��������������ˣ�������������ƴ��ƴ�\n",
                "�����Ĳ�ס���������⣺�㻹�ǿ��߰ɣ���û������������\n",
        }) );

        set_skill("unarmed", 20);
        set_skill("parry", 40);
        set_skill("dodge", 50);
        set_skill("sword", 30);
        set_skill("force", 30);
        set_skill("literate", 70);


        setup();

        carry_object(__DIR__"obj/thin_sword")->wield();
        carry_object(__DIR__"obj/pink_cloth")->wear();
        carry_object(__DIR__"obj/shoe")->wear();
}

int accept_fight(object me)
{
        if( (string)me->query("family/family_name")=="��ɽ����" ) {
                if( (string)me->query("gender")=="Ů��" ) {
                        command("say 
ʦ�㣡�������������������ȥ��԰ժ�������");
                        return 0;
                } else {
                        command("say �ҲŲ�Ҫ������ȥ�����ͷ���ɣ�");
                        return 0;
                }
        }
        command("say ����˵�������ܸ�������Щ�������������С�");
        return 0;
}
 
