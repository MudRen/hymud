 inherit NPC;
void create()
{
        set_name("��������", ({ "tianwang","����","��������" }) );
        set("gender", "����" );
        set("combat_exp", 500000);
        set("attitude", "friendly");
        set("max_neili", 500);
        set("neili", 500);
        set("force_factor", 5);
        set("no_shown",1);
        set_skill("force", 60);
        set_skill("whip", 300);
        set_skill("dodge", 100);
        setup();
        carry_object(__DIR__"obj/godwhip")->wield();
}
int is_ghost() { return 1; } 
void init()
{
add_action("do_kill","kill");
}
int getme(object me)
{
this_object()->kill_ob(me);
return 1;
} 
int do_kill(string arg)
{
        object me;
        me = this_player();
        if(arg == "master can" || arg == "master" || arg == "can")
        {
        message_vision("�λ���ʦ˵���������ӷ����Ϳ̼���飬�÷������ͷ�$N�ɣ���\n",me);
        call_out("getme",1,me);
        return 1;
        }
        return 0;
}    