 inherit NPC;
#include <ansi.h>
void create()
{
        set_name("��С��", ({ "xiaoyun" }) );
        set("gender", "����" );
        set("title", HIR "�캢��"NOR);
        set("age", 14);
        set("long",
                "һ��������а��δ�����µ�С���ӣ������ٱ�����ˣ�����\n");
        set("combat_exp", 5);
        set("attitude", "aggrensive");
        set("per",30);
        set_skill("unarmed",5);
        set_skill("dodge",5);
        setup();
        carry_object("/clone/misc/cloth")->wear();
} 
void init()
{       
        object ob; 
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
} 
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(10) ) {
                case 0:
message_vision("$N���������ҵ�С��ɵ����Ϲٽ��һ�����Ӧ����Ϊͽ�ģ�\n",this_object(),ob);
                        break;
                case 1:
                        command("grin");
                        break;
        }
}
