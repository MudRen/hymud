// shinv.c from mool

inherit NPC;
 
void create()
{
        set_name("��Ů", ({"shi nv",}));
        set("long", "����һλ�������ش��˼ҵ�Ѿ�ߡ�\n");
        set("gender","Ů��");
        set("title","�һ�ɽׯ");

        set("chat_chance",5);
        set("chat_msg",({
        "��Ů����Թ�����������:�ҵ���������ԭ,��!����ȥ������ᰡ��\n"
}));
        set("age",19);
        set("con",30);
        set("str",20);
        set("max_qi",500);
        set("max_jing",400);
        set("max_sen",500);

        set_skill("dodge",100);
        set_skill("parry",100);
        set_skill("unarmed",100);
        set_skill("literate",10);

        set("combat_exp",20000+random(20000));

        setup();
        carry_object("/d/jinghai/npc/obj/saozhu")->wield();
        carry_object("/clone/misc/cloth")->wear();
}

