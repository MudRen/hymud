#include <ansi.h>
inherit NPC; 
void create()
{
    set_name("������", ({"liu jinlian","liu"}) );
        set("gender", "Ů��" );
        set("nickname", HIM "ĸɫ��"NOR);
        set("long", "��Ů�˵�һ˫�ż�ֱ��������С����Ѫ�����ƺ���ʱ׼������һ�ڸ�����ȥ��\n");
        set("attitude", "friendly");
        set("max_jing", 3000);
        set("max_qi", 3000);
        set("max_jing", 3000);
        set("age", 36);
        set("str", 25);
        set("cor", 30);
        set("cps", 30);
        set("combat_exp", 1000000);
        set_skill("blade", 100);
        set_skill("parry", 100);
        set_skill("dodge", 100);
        set_skill("move", 100);
        set("chat_chance", 10);
        set("chat_msg", ({
        "���������Ŵ������ݹ�Ц����Щ���˶��ǹ������ҵ��������������\n",
        (: random_move :),

        }) );
        setup();
        carry_object(__DIR__"obj/redskirt")->wear();
} 
void init()
{
        object ob; 
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) 
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
} 
void greeting(object ob)
{   
   if (ob->query("gender") == "����" && ob->query("combat_exp") > 1000000 )
        {
                message_vision("$N������ͻȻ��$n���˹�ȥ�������Ϲ����ˣ�������������ɡ���\n", this_object(),ob );
                this_object()->kill_ob(ob);
        }
        return;
}     
