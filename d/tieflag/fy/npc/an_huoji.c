#include <ansi.h>
inherit NPC; 
void create()
{
    set_name("��������", ({"huo ji"}) );
    set("gender", "����" );
    set("long", "�����������Ļ�ƣ�æʱ�����ϰ��к����ˣ�û�¾����Ű��ٸ��޲���ľ��\n");
    set("attitude", "friendly");
    set("age", 25);
    set("cor", 25);
    set("cps", 25);
    set("combat_exp", 380000);
    
    set("force_factor", 30+random(30));
    set("neili",100);
    set("max_neili",100);
    
    set_skill("axe",100);
    set_skill("unarmed", 100);
    set_skill("parry", 100);
    set_skill("dodge", 100);
    set_skill("move", 100);
    set_skill("xuanyuan-axe",60);
    set_skill("wuxing-dun",100);
    
    map_skill("dodge","wuxing-dun");
    map_skill("axe","xuanyuan-axe");
    map_skill("parry","xuanyuan-axe");
    setup();
    carry_object(__DIR__"obj/heicloth")->wear();
    carry_object(__DIR__"obj/paoaxe")->wield();
}   
