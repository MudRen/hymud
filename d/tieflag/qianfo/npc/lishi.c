 inherit NPC;
void create()
{
        set_name("��ʿ", ({ "lishi","��ʿ" }) );
        set("gender", "����" );
        set("class", "bonze");
        set("str", 26);
        set("long", "��ò��ΰ������ŭ�࣬�ϰ�����㣬�����ſ����ʽ���״��\n");
        set("combat_exp", 6000);
        set("attitude", "friendly");
        set("max_neili", 500);
        set("neili", 500);
        set("max_sen",1);
        set("jing",1);
        set("force_factor", 5);
        set("no_shown",1);
        set_skill("force", 60);
        set_skill("unarmed", 500);
        set_skill("dodge", 60);
        setup();
        carry_object(__DIR__"obj/hat");
        carry_object(__DIR__"obj/staff");
} 
int accept_fight(object me)
{
        return 0;
}
void init()
{
add_action("do_look","look");
} 
int do_look(string arg)
{ 
if (arg == "lishi" || arg == "��ʿ")
{
write("��ò��ΰ������ŭ�࣬�ϰ�����㣬�����ſ����ʽ���״��\n");
return 1;
}
return 0;
} 
