//Cracked by Roath

//Ansi 99.12
inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("�����", ({ "zhao linger", "linger"}));
        set("title","");
        set("long", 
"�������Ů��֮�󣬵�Ȼ�ǰ����ߡ�\n");
        set("gender", "Ů��");
        set("age", 15);
        set("attitude", "peaceful");
        set("str", 30);
        set("int", 40);
        set("spi", 50);
        set("per", 40);
        set("class","xian");
        
        set("kee", 2000);
        set("max_kee", 2000);
        set("sen", 3000);
        set("max_sen", 3000);
        set("force", 4000);
        set("max_force", 2000);
        set("mana", 6000);
        set("max_mana", 3000);
        set("force_factor", 60);
        set("mana_factor", 100);

        set("combat_exp", 1500000);
        set("daoxing", 2000000);

        set_skill("unarmed", 100);
        set_skill("dodge", 100);
        set_skill("parry", 100);
        set_skill("spells",150);
        set("inquiry", ([
                "����ң" : "���ܴ���ȥ����ң����𣿣�\n",
        ]));
        setup();

        carry_object("/clone/misc/cloth")->wear();

}

