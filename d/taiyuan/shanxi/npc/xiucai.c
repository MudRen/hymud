// hu.c
inherit NPC;
#include <ansi.h>
//int wieldblade();
 
void create()
{
        set_name("���", ({ "mr jian", "jian er" }) );
        set("gender", "����" );
        set("age", 52);
        set("str", 30);
        set("str", 99);
        set("cor", 40);
        set("cps", 1);
        set("no_busy", 99);
                 set("reward_npc", 1);
        set("difficulty", 10);

        set("class","huashan");
            set("resistance/kee",99);
    set("resistance/sen",99);
    set("resistance/gin",99);

    set("long",
"һ����������������ţ�������˫�֣�ʩʩȻ�ض��Ų��� \n"
    );
        set("force_factor", 100);
        set("combat_exp", 7000000+random(3000000));
        set("attitude", "friendly");
        set_skill("move",100);
        set_skill("force",100);
        set_skill("unarmed",999);
        set_skill("dodge",99);
        set_skill("throwing",999);
        set_skill("ill-quan",999);
        set_skill("tanzhi-shentong",999);
        
        
        //set_skill("tangforce",100);
        //set_skill("blade",180);
        //set_skill("tang-blade",180);        

        //set("skill_public",1);

        map_skill("unarmed", "ill-quan");
        map_skill("parry", "tanzhi-shentong");
        //map_skill("force", "tangforce");
        set("chat_chance", 1);
        set("chat_msg", ({
                "�������������������ǳ����ҹ��Ϊ˭��¶���д�����\n",
                //"��������Ȼ��Ц������һ�Ӱ��£�����Ͳ����ˡ���\n",  
                //"�����˺�Ȼ�����������ֲ��壬���ƿ�̾����������ǣ�Ҳ����һ���壮����ֺα�̫�����أ���\n",
        }));
        //set("skill_public", 1);
        set("chat_chance_combat", 99);
        /*set("chat_msg_combat", ({
                (: wieldblade  :),
        }) );*/
        setup();
           carry_object("/clone/misc/cloth")->wear();

        //carry_object("/d/huashan/npc/obj/chickbone")->wield();
        
} 
/*
int wieldblade()
{
command("wield piece");
perform_action("throwing.tanzhijinghun");
command("unwield piece");
return 1;
}*/
