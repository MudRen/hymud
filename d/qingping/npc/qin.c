 // thousand_hand.c
#include <ansi.h> 
inherit NPC;
void create()
{
        set_name("�ٶ�" , ({ "qiner", "qin er", "girl" }) );
        set("long", "һλʮ�������СѾͷ��\n");
        set("attitude", "friendly");
/*      set("max_gin", 500);
        set("max_kee", 500);
        set("max_sen", 500); */
        set("age", 13);
        set("gender", "Ů��" );
        set("inquiry", ([
        ]) );
/*      set("str", 35);
        set("cor", 30);
        set("cps", 25); */ 
        set("combat_exp", 5000);
        set_skill("dodge", 50+random(50));
        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/d/tieflag/chuenyu/obj/yellow_flower")->wear();
} 
