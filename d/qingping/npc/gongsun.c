 // XXder@fy3
#include <ansi.h>
inherit NPC;
void create()
{
        set_name("���ﲻ��" , ({ "buzhi", "gongsun buzhi", "gongsun" }) );
        set("long", "����������С�������ڹ��ļơ�\n");
        set("attitude", "friendly");
/*      set("max_gin", 500);
        set("max_kee", 500);
        set("max_sen", 500);  */
        set("age", 30);
        set("gender", "����" );
/*      set("str", 35);
        set("cor", 30);
        set("cps", 25); */
        create_family("��ƽɽׯ", 1, "������");
        set("combat_exp", 20000+random(50000));
        set_skill("dodge", 50+random(50));
        set_skill("unarmed", 80);
        set_skill("sword", 365);

        set_skill("force", 60);

        setup();
        carry_object(__DIR__"obj/cloth")->wear();
        carry_object("/clone/weapon/gangjian")->wield();
}  
