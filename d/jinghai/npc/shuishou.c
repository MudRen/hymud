inherit NPC;
 
void create()
{
        set_name("���ᴬ��", ({"shui shou",}));
        set("long", "һλ��ɫ��ڵ���������,����ͦ�أ�һ������ν�ܵ����ӡ�\n");
        set("gender","����");
        set("title","�����ɵ���");
	set("chat_chance",1);
        set("chat_msg",({
        "������۸ߺ���һ������һ������\n"
}));

        set("age",25);
        set("con",30);
        set("str",30);
        set("max_qi",1200);
        set("max_jing",1200);
        set("max_sen",1200);

        set_skill("dodge",100);
        set_skill("demon-blade",100);
        set_skill("parry",100);
        set_skill("unarmed",100);
        set_skill("chilian-shenzhang",200);
        set_skill("doomsword",200);
create_family("������", 3, "ˮ��");
        set("combat_exp",250000);
 
        setup();
        carry_object("/clone/misc/cloth")->wear();
}

