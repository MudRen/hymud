#include <ansi.h>
inherit NPC; 
void create()
{
    set_name("ţ����", ({ "niuroutang" }) );
    set("title", HIB "�Ϻ�һ֦��"NOR);
        set("gender", "Ů��" );
    set("age", 16);
    set("per", 23);
        set("long", @LONG
һ���ظ��ܸߣ���֫��ϸ�����ȴ��С��Ů���ӣ��۾�����������飬
��˵���С��ȴ���Ϻ�С�����ˣ������е����͵Ĵ��ϴ��޲��Ժ���
���ȴ���(enjoy)Ϊ�١�
LONG
);
    set("combat_exp", 50000);
   set("attitude", "friendly"); 
   setup();
    carry_object("/clone/misc/cloth")->wear();
} 
int accept_fight(object me)
{
        command("say СŮ�����������Ķ��֣�");
        return 0;
}
int accept_object(object me, object obj)
{
        command("smile");
        command("say ��л��λ" + RANK_D->query_respect(me) +
"�����Ϻ�С�۵�Զ��ϡ��������ţ��������\nȴ��ǧ��¥��Щӹ֬�׷ۡ�����\n");
    if((int)obj->value() >= 50000) me->add_temp("marks/niuroutang",1);
        return 1;
} 
void init()
{
        add_action("do_enjoy","enjoy");
} 
int do_enjoy()
{
object me;
object wo;
object *inv;
int maxgin,maxkee, maxsen;
int i;
        me = this_player();
    if((int)me->query_temp("marks/niuroutang") <=0)
        {
        command("say ��Ӵ��������λ" + RANK_D->query_respect(me) +
    "������û������ô�ܺ����أ����ġ���");
        return 1;
        }
    me->add_temp("marks/niuroutang",-1);
message_vision(HIB"$N������Ц�ų�$n�߹�����ˮ�߰����֫Ť���Ų�����������\n"NOR,this_object(),me);
        me->unconcious();
                inv = all_inventory(me);
                for(i=0; i<sizeof(inv); i++)
                {
                if (inv[i]->query("no_drop") || inv[i]->query("owner")) continue;
                        destruct(inv[i]);
                }
        maxgin = (int)me->query("max_jing");
        maxkee = (int)me->query("max_qi");
        maxsen = (int)me->query("max_jing");
        me->set("eff_jing", maxgin);
        me->set("jing", maxgin);
        me->set("eff_qi", maxkee);
        me->set("qi", maxkee);
        me->set("eff_jing", maxsen);
        me->set("jing", maxsen);
        wo = new(__DIR__"obj/flower");
        wo->move(me);
        return 1;
}   
